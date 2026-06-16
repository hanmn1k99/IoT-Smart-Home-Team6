require('dotenv').config({ path: '../.env' });
const axios = require('axios');

const THINGSPEAK_READ_API_KEY = process.env.XNHCRLGIIOH6H3AP;
const THINGSPEAK_CHANNEL_ID = process.env.3408715;

/**
 * Đọc 5 kết quả gần nhất từ ThingSpeak
 */
async function getLatestData() {
    try {
        const url = `https://api.thingspeak.com/channels/${THINGSPEAK_CHANNEL_ID}/feeds.json?api_key=${THINGSPEAK_READ_API_KEY}&results=5`;
        const response = await axios.get(url);
        return response.data.feeds || [];
    } catch (error) {
        console.error('❌ Lỗi khi đọc ThingSpeak:', error.message);
        return [];
    }
}

module.exports = {
    getLatestData
};
