#include <Wire.h>
#include <SoftwareSerial.h>

int moto1 = 2;       //馬達定義
int moto1_speed = 3; //
int moto2 = 4;       //
int moto2_speed = 5  //
int speed = 0;

int value = 0;

int headlights = 6;  //車燈
int rearlights = 7;  //

int irled = 8;       //紅外線發射
int irReceiver = 9;  //紅外線接收
SoftwareSerial BTSerial(10, 11);
unsigned int frequency = 38000; //發射頻率

void setup(){
    for(int i = 2;i<9;i++)pinMode(i,OUTPUT);
    pinMode(irReceiver,INPUT);

    Serial.begin(9600);
    digitalWrite(headlights,HIGH);
    digitalWrite(rearlights,HIGH);
}

void loop(){
    char receive;
    if(BTSerial.available()>0)receive = BTSerial.read();
    switch(receive){ 
        case 'a':
            speed = 100
        break;
        case 'b':
            if(value < 4){
                speed = 130;
                value++;
            }
        break;
        case 'c':
            if(value < 4){
                speed = 160;
                value++;
            }
        break;
        case 'd':
            if(value < 4){
                speed = 190;
                value++;
            }
        break;
        case 'e':
            if(value < 4){
                speed = 220;
                value++;
            }
        break;
        case 'f':
            speed = 200;
            value = 0;
        break;
        case 'g':
            speed = 180
        break;
        case 'h':
            speed = 120;
        break;
        case 'i':
            speed = 60;
        break
        case 'j':
            speed = 20;
        break;
        case 'k':
            if(digitalRead(irReceiver)==0)speed = 0;
        break;
    }
    digitalWrite(moto1,HIGH);
    digitalWrite(moto2,HIGH);
    analogWrite(moto1_speed,speed);
    analogWrite(moto2_speed,speed);
}
