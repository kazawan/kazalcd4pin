#include <Arduino.h>
unsigned char pic[7][64]={
  {
0x1F,0x1F,0x1F,0x1F,0x00,0x1F,0x1F,0x1F,
0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,
0x1F,0x17,0x13,0x19,0x00,0x19,0x13,0x17,
0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,
0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,
0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,
0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,
0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,/*"未命名文件",0*/
},
{
0x1F,0x1F,0x1F,0x1F,0x18,0x1F,0x1F,0x1F,
0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,
0x1F,0x1B,0x19,0x1C,0x00,0x1C,0x19,0x1B,
0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,
0x1F,0x1F,0x1F,0x1F,0x0F,0x1F,0x1F,0x1F,
0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,
0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,
0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,/*"未命名文件",0*/
},
{
0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,
0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,
0x1F,0x1E,0x1F,0x1F,0x00,0x1F,0x1F,0x1E,
0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,
0x1F,0x1F,0x07,0x13,0x01,0x13,0x07,0x0F,
0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,
0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,
0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,/*"未命名文件",0*/
},
{
0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,
0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,
0x1F,0x1F,0x1F,0x1F,0x1C,0x1F,0x1F,0x1F,
0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,
0x1F,0x13,0x19,0x1C,0x00,0x1C,0x19,0x13,
0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,
0x1F,0x1F,0x1F,0x1F,0x0F,0x1F,0x1F,0x1F,
0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,/*"未命名文件",0*/
},
{
0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,
0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,
0x1F,0x1E,0x1F,0x1F,0x00,0x1F,0x1F,0x1E,
0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,
0x1F,0x1F,0x07,0x13,0x01,0x13,0x07,0x0F,
0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,
0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,
0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,/*"未命名文件",0*/
},
{
0x1F,0x1F,0x1F,0x1F,0x18,0x1F,0x1F,0x1F,
0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,
0x1F,0x1B,0x19,0x1C,0x00,0x1C,0x19,0x1B,
0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,
0x1F,0x1F,0x1F,0x1F,0x0F,0x1F,0x1F,0x1F,
0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,
0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,
0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,/*"未命名文件",0*/
},
{
0x1F,0x1F,0x1F,0x1F,0x00,0x1F,0x1F,0x1F,
0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,
0x1F,0x17,0x13,0x19,0x00,0x19,0x13,0x17,
0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,
0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,
0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,
0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,
0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,/*"未命名文件",0*/
}





};