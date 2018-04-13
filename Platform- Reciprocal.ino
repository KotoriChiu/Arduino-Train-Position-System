#include <SoftwareSerial.h>
SoftwareSerial BTSerial(10, 11);

int infrared_re[10]={22,23,24,25,26,27,28,29,30,31};
int infrared_em = 32;

//七段顯示器

int sign_light = 2;

void setup(){
    for(int i = 22;i < 32;i++)pinMode(i,INPUT);
    pinMode(infrared_em,OUTPUT);
    pinMode(sign_light,INPUT);
    Serial.begin(9600);
}

void loop(){
    //
}