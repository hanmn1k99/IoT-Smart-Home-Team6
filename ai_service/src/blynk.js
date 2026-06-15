require('dotenv').config({ path: '../.env' });
const axios = require('axios');

const BLYNK_AUTH_TOKEN = process.env.BLYNK_AUTH_TOKEN;

/**
 * Gửi lệnh bật tắt đèn qua Blynk (Pin V0)
 * @param {boolean} turnOn 
 */
async function controlLight(turnOn) {
    const value = turnOn ? 1 : 0;
    const url = `https://blynk.cloud/external/api/update?token=${BLYNK_AUTH_TOKEN}&v0=${value}`;
    try {
        await axios.get(url);
        console.log(`✅ Đã gửi lệnh điều khiển đèn: ${turnOn ? 'BẬT' : 'TẮT'}`);
    } catch (error) {
        console.error('❌ Lỗi khi điều khiển Blynk:', error.message);
    }
}

module.exports = {
    controlLight
};
