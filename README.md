# Physical Computing Project 2024 - IT KMITL

รายงานฉบับนี้จัดทำขึ้นเพื่อเป็นส่วนหนึ่งของวิชา PHYSICAL COMPUTING รหัสวิชา 06016409 ชั้นปีที่ 2 สถาบันเทคโนโลยีพระจอมเกล้าเจ้าคุณทหารลาดกระบัง

## ที่มาและความคิดริเริ่มสร้างสรรค์

การใช้แก๊สเป็นเชื้อเพลิงและพลังงานในหลายด้านกลายเป็นเรื่องปกติและแพร่หลายในชีวิตประจำวัน ไม่ว่าจะเป็น
ครัวเรือน: ใช้สำหรับประกอบอาหาร
คมนาคม: ใช้เป็นเชื้อเพลิงสำหรับรถยนต์และยานพาหนะบางประเภท
อุตสาหกรรม: โรงงานต่าง ๆ ใช้แก๊สในกระบวนการผลิตสินค้า
สถานประกอบการ: ร้านอาหาร
สถานที่ที่ต้องการการควบคุมความปลอดภัยสูง: เช่น โรงพยาบาลและห้องปฏิบัติการต่าง ๆ
แก๊สเป็นสารไวไฟที่ต้องการการจัดการอย่างระมัดระวัง การป้องกันการรั่วไหลของแก๊สจึงเป็นสิ่งสำคัญเพื่อความปลอดภัยของผู้ใช้งานและป้องกันอันตรายที่อาจเกิดขึ้น

## จุดประสงค์ของโปรเจกต์ Smart Gas Detector

- เพิ่มความปลอดภัย: ตรวจจับและแจ้งเตือนการรั่วไหลของแก๊สอย่างรวดเร็ว เพื่อลดความเสี่ยงจากการระเบิด เพลิงไหม้ หรืออันตรายจากการสูดดมแก๊สพิษ
- เพื่อแจ้งเตือนการรั่วไหลของแก๊ส: ส่งการแจ้งเตือนถึงผู้ใช้งานผ่านอุปกรณ์ต่าง ๆ เช่น แอปมือถือ สัญญาณเสียง หรือไฟแจ้งเตือน เพื่อให้ผู้ใช้สามารถตอบสนองได้อย่างรวดเร็ว
- เพื่อเสริมประสิทธิภาพระบบรักษาความปลอดภัย: เชื่อมต่อกับระบบความปลอดภัยอื่น ๆ เช่น ระบบดับเพลิงหรือระบบระบายอากาศอัตโนมัติ
- เพื่อพัฒนาการในการประยุกต์ใช้ Microcontroller

## รายละเอียดของโปรเจกต์ Smart Gas Detector

โครงงานนี้เป็นการใช้ Microcontroller ในการตรวจสอบการรั่วไหลของแก๊สที่เป็นอันตรายต่อมนุษย์และแจ้งเตือนต่อผู้ใช้งานอย่างทันท่วงทีเพื่อป้องกันภัยที่เกิดขึ้น Microcontroller ที่ใช้คือ ESP32 
Sensorในการตรวจจับแก๊สคือ MQ-9 Sensor Gas และแสดงผลด้วยจอ 0.96 inch OLED และมีBuzzerกับLEDเพื่อส่งสัญญาณเมื่อแก๊สรั่วไหล 
เมื่อSensorตรวจจับแก๊สได้Microcontroller จะส่งNotifyไปที่LINEของผู้ใช้งานและจะส่งสัญญาณเสียงBuzzerและสัญญาณไฟLEDเพื่อแจ้งเตือนผู้คนที่อยู่รอบข้าง

## คลิปวิดีโอนำเสนอ

https://youtu.be/gUXTy4dL-Ww

## Website

https://chakkapop.github.io/Smart-Gas-Detector/

## สมาชิก
| ID       | Name                                  | Img                                                                             |
|----------|---------------------------------------|---------------------------------------------------------------------------------|
| 66070025 | นายจักรภพ บัวจันทร์ (ฟาฎิล)          |![12](https://github.com/user-attachments/assets/f13dc52d-7794-4abc-869a-b53557185ff5)|
| 66070034 | นายเจษฎาพร บัวศรี (โอ๊ค)            |![pak](https://github.com/user-attachments/assets/7ca991df-8da3-4649-a509-8d7eec083ff8)     |
| 66070046 | นายชัยธวัช ชมภูเพ็ชร (ซูเคอร์)          | ![cer](https://github.com/user-attachments/assets/6c7011cd-65d2-4129-bc22-c3ecf762ba84)    |
| 66070242 | นายกิตติภูมิ วงศ์ษา (ภูมิ)            | ![phum](https://github.com/user-attachments/assets/adbc50e6-176e-4b21-b81b-dc5a3af83651)     |

