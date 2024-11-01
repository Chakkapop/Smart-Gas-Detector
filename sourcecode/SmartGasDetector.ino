#include <Wire.h>                           
#include <Adafruit_GFX.h>                    
#include <Adafruit_SSD1306.h>                 
#include <WiFiMulti.h>
#include <ArtronShop_LineNotify.h>

#define WIFI_SSID "--------" // WiFi Name
#define WIFI_PASSWORD "--------" // WiFi Password

#define LINE_TOKEN "--------------------------" // LINE Token

WiFiMulti wifiMulti;

unsigned long lastSendTime = 0;   // เวลาสุดท้ายที่ส่งไปยัง Line Notify
const unsigned long sendInterval = 30000; // ส่งข้อมูลทุกๆ 30 วินาที

#define sensor 34                        
#define buzzer 4                      
#define led 2                       
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET   -1                  

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {  
  pinMode(buzzer,OUTPUT);                 
  pinMode(led,OUTPUT);                       
  Serial.begin(115200);

  Serial.println();
  Serial.println();
  Serial.println();

  WiFi.mode(WIFI_STA);
  wifiMulti.addAP(WIFI_SSID, WIFI_PASSWORD);

  // wait for WiFi connection
  Serial.print("Waiting for WiFi to connect...");
  while ((wifiMulti.run() != WL_CONNECTED)) {
    Serial.print(".");
  }
  Serial.println(" connected");

  LINE.begin(LINE_TOKEN);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // 
  }
  display.display();                          
  display.clearDisplay();                   
  
}


void loop() {
  
  int values;                                                             
  int grafX = 0;                                
  display.clearDisplay();                    
  values = analogRead(sensor);
  values = map(values, 0, 4095, 0, 20);
  grafX = map(values, 0, 20, 0, 127);          // map ค่ากับความกว้างของจอ
  display.fillRect(0, 0, grafX, 16, WHITE);  // print กราฟค่า
  
  display.setTextSize(2);                     // ตั้งขนาดตัวอักษร
  display.setTextColor(WHITE);                // ตั้งสีตัวอักษร
  display.setCursor(5, 33);                     // ตั้งตำแหน่ง cursor
  display.println("LOW");
  display.setCursor(46, 33); 
  display.println("BUTANE"); 
  
  display.setTextSize(2);                     
  display.setTextColor(WHITE);                
  display.setCursor(28, 50);
  display.print("LEVELS");  // print ระดับแก๊ส
  
  display.setTextSize(1); 
  display.setCursor(48, 20); 
  display.print(values); // print ค่าแก๊ส
  display.print(" V");
  grafX = map(values, 0, 100, 0, 127);          
  display.fillRect(0, 0, grafX, 16, WHITE);  
  
  if (values >= 6) {
    unsigned long currentTime = millis(); 
    
    if (currentTime - lastSendTime > sendInterval) {
      sendtoLine();                             // ส่งข้อความไปที่ Line Notify
      lastSendTime = currentTime;               // อัพเดตเวลาสุดท้ายที่ส่ง
    }
    
    digitalWrite(led, HIGH); // เปิดไฟ LED
    digitalWrite(buzzer, HIGH); // เปิด buzzer 
    
    display.fillRect(0, 17, 128, 64, SSD1306_WHITE);
    display.setTextColor(BLACK);                
    display.setTextSize(2);
    display.setCursor(5, 23);
    display.print("BUTANE");
    display.setTextSize(1);
    display.setCursor(83, 28);
    display.setTextSize(2);
    display.setCursor(19, 45);
    display.print("LEVELS!!");
    
    display.setTextColor(BLACK);                
    display.setTextSize(2);
    display.setCursor(39, 2);
    display.print("HIGH");
    
  } else {                                       
    digitalWrite(led, LOW);  // ปิดไฟ LED
    digitalWrite(buzzer, LOW);  // ปิด buzzer
  }
  Serial.print(values);
  Serial.println(" V");
  display.display();  // อัพเดตจอแสดงผล
  delay(500);
}

void sendtoLine() {
  LINE.send("ตรวจพบแก๊สเกินกำหนด!!");
}