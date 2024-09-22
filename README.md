HƯỚNG DẪN THỰC HIỆN MẠCH ĐIỀU KHIỂN LED RGB BẰNG ARDUINO NANO

I. THÀNH PHẦN

  1 X Arduino Nano
  
  1 x LED RGB 8 chân
  
  4 x triết áp 10k
  
  1 x màn hình OLED 0.96 inch

II. Sơ đồ lắp mạch

Link sơ đồ mạch điện: https://www.circuito.io/app?components=514,9590,9591,9594,9939,9939,9939,9939,11022,11372,466193 

III. Lưu ý

1. LED RGB

  Loại led: RGBW
  
  Số chân: 8 chân
  
  Kiểu đấu: song song, mỗi màu led có 2 cực riêng
  
  Dây kết nối trong chip led bằng đồng
  
  Tấm acrylic che led trong suốt chịu được nhiệt độ cao
  
  Tuổi thọ: có thể sử dụng 24h, tuổi thọ lý thuyết là 50.000 giờ
  
  Công suất: một màu ~ 3w, 4 màu sáng cùng lúc lên tới 12w
  
  Điện áp: mỗi cực led có một điện áp khác nhau vui lòng xem ảnh thông số kỹ thuật
  
    Đỏ (R): 2.0-3.6VDC
    
    Xanh lá (G): 3.0-3.6VDC
    
    Xanh dương (B): 3.2-3.4VDC
    
    Trắng (W): 3.2-3.4VDC
    
  Dòng tiêu thụ tối đa: ~ 3A
  
    Đỏ (R): ~700mA
    
    Xanh lá (G): ~700mA
    
    Xanh dương (B): ~700mA
    
    Trắng (W): ~700mA
    

3. Arduino Nano

   Cực dương các LED phải cắm vào các chân phát PWM của Nano, cụ thể là các chân: 3,5,6,9.



