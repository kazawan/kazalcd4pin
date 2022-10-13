#include"kazalcd4pin.h"
#include<Arduino.h>

void kazalcd::setPin(unsigned char rsPin,unsigned char rwPin,unsigned char ePin){
    rs = rsPin;
    rw = rwPin;
    e = ePin;
    pinMode(rs, OUTPUT);
    pinMode(rw, OUTPUT);
    pinMode(e, OUTPUT);
}

void  kazalcd::setDataPin(int db7,int db6,int db5,int db4){
    db[0] = db7;
    db[1] = db6;
    db[2] = db5;
    db[3] = db4;

    int i;
    for(i=0;i<4;i++){
    pinMode(db[i], OUTPUT);
    }
}

void kazalcd::orderReady(){
    digitalWrite(rs,0);
    digitalWrite(rw,0);
    digitalWrite(e,0);
    delayMicroseconds(1);
}
void kazalcd::dataReady(){
    digitalWrite(rs,1);
    digitalWrite(rw,0);
    digitalWrite(e,0);
    delayMicroseconds(1);
}
void kazalcd::send(){
    digitalWrite(e,1);
    delayMicroseconds(1);
    digitalWrite(e,0);
    delayMicroseconds(1);
}

void kazalcd::writeCom(int value){
    while(busy());
    orderReady();
    int i;
    int j;
    int temp1;
    int temp2;
    
    temp1 = value & 0xf0;
    for(i=3;i>=0;i--){
        digitalWrite(db[3-i],temp1 & 0x80);
        temp1 <<= 1;
    }
    send();

    temp2 = value & 0x0f;
    for(j=3;j>=0;j--){
        digitalWrite(db[3-j],temp2 & 0x08);
        temp2 <<= 1;
    }
    send();
    // for(i=7;i>=0;i--){
    //     digitalWrite(db[7-i],value & 0x80);
    //     value <<= 1;
    // }
}

void kazalcd::writeData(int value){
    while(busy());
    dataReady();
    int i;
    int j;
    int temp1;
    int temp2;
    
    temp1 = value & 0xf0;
    for(i=3;i>=0;i--){
        digitalWrite(db[3-i],temp1 & 0x80);
        temp1 <<= 1;
    }
    send();
    temp2 = value & 0x0f;
    
    for(j=3;j>=0;j--){
        digitalWrite(db[3-j],temp2 & 0x08);
        temp2 <<= 1;
    }
    send();
}

unsigned char kazalcd::busy(){
    int res = 0;
    int temp ;
    int i;
    digitalWrite(rs,0);
    digitalWrite(rw,1);
    digitalWrite(e,1);
    for(i=3;i>=0;i--){
        temp = digitalRead(db[3-i]);
        temp <<=1;
    }
    for(i=3;i>=0;i--){
        temp = digitalRead(db[3-i]);
        temp <<=1;
    }
    if((temp & 0x80) == 0x80){
        res = 1;
    }else{
        res = 0 ;
    }
    return res;

}

void kazalcd::init(){
    //0x38= 0011 1000
    // 0010 1000 = 0x28

    writeCom(0x28);         
    delay(20);
    writeCom(0x28);         
    delay(20);
    writeCom(0x28);         
    delay(20);
    writeCom(0x28);         
    delay(20);
    writeCom(0x08);         
    delay(20);
    writeCom(0x01);         
    delay(20);
    writeCom(0x06);         
    delay(20);
    writeCom(0x0c);         
    delay(20);
    Serial.println("lcd ready");
}

void kazalcd::setArea(unsigned char line,unsigned char col){
    switch(line){
        case 0:
            writeCom(0x80+col);
            break;
        case 1:
            writeCom(0xc0+col);
            break;
        default:
            break;
    }
}

void kazalcd::printStr(unsigned char line,unsigned char col,unsigned char key[]){
    setArea(line,col);
    unsigned int i;
    for(i=0;i<strlen((char*)key);i++){
        writeData(key[i]);
    }
}

int kazalcd::Pow(int x,int y){
    unsigned char i;
    int result = 1;
    for(i = 0; i < y; i++)
    {
    result *= x;
    }
    return result;
}

void kazalcd::showNum(unsigned char line,unsigned char col,int key,unsigned char len){
    unsigned char i;
    unsigned char temp;
    setArea(line,col);
    for(i = len ;i > 0 ; i--){
    temp = key/Pow(10,i-1)%10+'0';
    writeData(temp);
    }
}

void kazalcd::creatIcon(int pos,unsigned char icon[]){
    int i;
    switch(pos){
        case 1:
            //0x40 写入地址
            for(i=0;i<8;i++){
                writeCom(0x40 + i);
                writeData(icon[i]);
            }
            //0x01写出地址
            
            break;
        case 2:
            //0x48
            for(i=0;i<8;i++){
                writeCom(0x48 + i);
                writeData(icon[i]);
            }
            //0x02写出地址
            break;
        case 3:
            //0x50
            for(i=0;i<8;i++){
                writeCom(0x50 + i);
                writeData(icon[i]);
            }
            break;
        case 4:
            //0x58
            for(i=0;i<8;i++){
                writeCom(0x58 + i);
                writeData(icon[i]);
            }
            //0x03写出地址
            break;
        case 5:
            //0x60
            for(i=0;i<8;i++){
                writeCom(0x60 + i);
                writeData(icon[i]);
            }
            break;
        case 6:
            //0x68
            for(i=0;i<8;i++){
                writeCom(0x68 + i);
                writeData(icon[i]);
            }
            break;
        case 7:
            //0x70
            for(i=0;i<8;i++){
                writeCom(0x70 + i);
                writeData(icon[i]);
            }
            break;
        case 8:
            //0x78
            for(i=0;i<8;i++){
                writeCom(0x78 + i);
                writeData(icon[i]);
            }
            break;
        default:
            break;
    }

}


void kazalcd::showIcon(unsigned char line,unsigned char col,int pos){
    setArea(line,col);
    switch (pos)
    {
    case 1:
        writeData(0x00);
        break;
    case 2:
        writeData(0x01);
        break;
    case 3:
        writeData(0x02);
        break;
    case 4:
        writeData(0x03);
        break;
    case 5:
        writeData(0x04);
        break;
    case 6:
        writeData(0x05);
        break;
    case 7:
        writeData(0x06);
        break;
    case 8:
        writeData(0x07);
        break;
    
    default:
        break;
    }
}



