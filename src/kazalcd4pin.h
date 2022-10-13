#ifndef KAZALCD4PIN_H
#define KAZALCD4PIN_H
#include<Arduino.h>
class kazalcd{
  public:

    unsigned char rs;
    unsigned char rw;
    unsigned char e;
    int db[4];

    void init();
    void setPin(unsigned char rsPin,unsigned char rwPin,unsigned char ePin);
    void setDataPin(int db7,int db6,int db5,int db4);
    void orderReady();
    void dataReady();
    void send();
    void writeCom(int value);
    void writeData(int value);
    unsigned char busy();

    void setArea(unsigned char line,unsigned char col);
    void printStr(unsigned char line,unsigned char col,unsigned char key[]);
    int Pow(int x,int y);
    void showNum(unsigned char x,unsigned char y,int key,unsigned char len);
    void creatIcon(int pos,unsigned char icon[]);
    void showIcon(unsigned char line,unsigned char col,int pos);
    
  private:
    
};

#endif