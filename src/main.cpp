#include <Arduino.h>
#include"kazalcd4pin.h"
#include"./icon/icon.h"
#include"./icon/wea.h"

kazalcd lcd;

void creat8icon(int fps){
  int i;
  for(i=0;i<8;i++){
      lcd.writeCom(0x40 + i);
      lcd.writeData(pic[fps][i]);
  }
  for(i=0;i<8;i++){
      lcd.writeCom(0x60 + i);
      lcd.writeData(pic[fps][i+8]);
  }
  for(i=0;i<8;i++){
      lcd.writeCom(0x48 + i);
      lcd.writeData(pic[fps][i+16]);
  }
  for(i=0;i<8;i++){
      lcd.writeCom(0x68 + i);
      lcd.writeData(pic[fps][i+24]);
  }
  for(i=0;i<8;i++){
      lcd.writeCom(0x50 + i);
      lcd.writeData(pic[fps][i+32]);
  }
  for(i=0;i<8;i++){
      lcd.writeCom(0x70 + i);
      lcd.writeData(pic[fps][i+40]);
  }
  for(i=0;i<8;i++){
      lcd.writeCom(0x58 + i);
      lcd.writeData(pic[fps][i+48]);
  }
  for(i=0;i<8;i++){
      lcd.writeCom(0x78 + i);
      lcd.writeData(pic[fps][i+56]);
  }
  
}


void show8icon(){
  lcd.showIcon(0,0,1);
  lcd.showIcon(0,1,2);
  lcd.showIcon(0,2,3);
  lcd.showIcon(0,3,4);
  lcd.showIcon(1,0,5);
  lcd.showIcon(1,1,6);
  lcd.showIcon(1,2,7);
  lcd.showIcon(1,3,8);  
}



void setup() {
  Serial.begin(9600);
  delay(200);
  lcd.setPin(A3,A4,A5);
  lcd.setDataPin(10,9,8,7);
  lcd.init();

  
  
}

void loop() {
  lcd.printStr(0,5,(unsigned char*)"this is ani");
  for(int i=0;i<7;i++){
    creat8icon(i);
    show8icon();
    delay(50);
    if(i >17){
      i=0;
    }
  }

  


}