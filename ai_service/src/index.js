const dayjs = require('dayjs');
const utc = require('dayjs/plugin/utc');
const timezone = require('dayjs/plugin/timezone');
const { getLatestData } = require('./thingspeak');
const { controlLight } = require('./blynk');

dayjs.extend(utc);
dayjs.extend(timezone);

/**
 * Kiểm tra xem ngoài trời sáng hay tối dựa vào giờ VN (UTC+7)
 */
function checkOutsideLight() {
    // Lấy giờ Việt Nam
    const vnTime = dayjs().tz('Asia/Ho_Chi_Minh');
    const hour = vnTime.hour();
    
    // Giả sử trời tối từ 18:00 đến 06:00
    if (hour >= 18 || hour < 6) {
        return { status: 'Tối', vnTime };
    }
    return { status: 'Sáng', vnTime };
}

/**
 * Vòng lặp AI tự động dự đoán và điều khiển
 */
async function runAiLoop() {
    console.log('--- 🤖 Bắt đầu AI Service (Node.js) ---');
    
    setInterval(async () => {
        const { status, vnTime } = checkOutsideLight();
        const timeStr = vnTime.format('YYYY-MM-DD HH:mm:ss');
        
        console.log(`\n[${timeStr}] Trạng thái môi trường (theo giờ): ${status}`);

        const feeds = await getLatestData();
        if (feeds.length > 0) {
            const latest = feeds[feeds.length - 1];
            const ldrValue = parseInt(latest.field2 || 0, 10);
            console.log(`📊 Giá trị cảm biến ánh sáng hiện tại (LDR): ${ldrValue}`);

            // Logic AI (có thể thay thế bằng mô hình ML thực tế nếu cần)
            if (status === 'Tối' || ldrValue < 1000) {
                console.log('💡 Dự đoán: Cần BẬT đèn.');
                await controlLight(true);
            } else if (status === 'Sáng' && ldrValue > 2000) {
                console.log('🌑 Dự đoán: Cần TẮT đèn.');
                await controlLight(false);
            } else {
                console.log('➖ Không cần thay đổi trạng thái.');
            }
        } else {
            console.log('⚠️ Không có dữ liệu từ ThingSpeak.');
        }

    }, 30000); // Chạy mỗi 30 giây
}

runAiLoop();
