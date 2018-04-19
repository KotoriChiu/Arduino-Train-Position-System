#include <SoftwareSerial.h>
SoftwareSerial BT(2,3); // 接收腳, 傳送腳
void setup() {
  Serial.begin(9600); 
  BT.begin(9600);
}

void loop() {
 if (BT.available()) {
  char a= BT.read(); //接收Mmaster端的資料
  Serial.println(a); //印出值
 }
}