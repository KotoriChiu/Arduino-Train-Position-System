#include <SoftwareSerial.h>   // 引用程式庫
// 定義連接藍牙模組的序列埠
SoftwareSerial BT(2,3); // 接收腳, 傳送腳

void setup() {
  Serial.begin(9600);   // 與電腦序列埠連線
  BT.begin(9600);
}
 
void loop() {
  char a= 'a';
  BT.print(a); //傳送a
 delay(1000);
 
}