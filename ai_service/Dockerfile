FROM node:18-alpine

WORKDIR /app

# Copy package files
COPY package*.json ./

# Cài đặt các thư viện production
RUN npm install --omit=dev

# Copy toàn bộ source code
COPY . .

# Khởi chạy ứng dụng
CMD ["npm", "start"]
