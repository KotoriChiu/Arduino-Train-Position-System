#include <TimedAction.h>
int button = 2;     //微動開關
int rled = 8;       //號誌燈紅色
int oled = 9;       //號誌燈橘色
int gled = 10;      //號誌燈綠色
int emission = 11;  //發射給2560指令的port
long interval = 1000;
int light_value = 0;
int led_value;
int value = 10;

TimedAction blinkAction = TimedAction(interval,brink);

void setup(){
    for(int i = 8;i < 12;i++)pinMode(i,OUTPUT);

    pinMode(button,INPUT);
}

void loop(){
    if(digitalRead(button) == HIGH && led_value == 2){ //遇到險阻
        digitalWrite(emission,HIGH);
        digitalWrite(emission,LOW);
    }else if(digitalRead(button) == HIGH && led_value == 1 || led_value == 3){
        red_light();
        light_value = 1;
    }
    if(light_value) blinkAction.check();
}

void green_light(){
    digitalWrite(gled,HIGH);
    digitalWrite(oled,LOW);
    digitalWrite(rled,LOW);
    led_value = 1;
}

void red_light(){
    digitalWrite(gled,LOW);
    digitalWrite(oled,LOW);
    digitalWrite(rled,HIGH);
    led_value = 2;
}

void oled_light(){
    digitalWrite(gled,LOW);
    digitalWrite(oled,HIGH);
    digitalWrite(rled,LOW);
    led_value = 3;
}

void blink(){
    if(value == 5)oled_light();
    if(value == 0){
        green_light();
        value = 10;
        light_value = 0;
    }
    value--;
}