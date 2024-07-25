// 車錶 速度圖示
#include <Arduino.h>

const unsigned char speed_icon[5][800] PROGMEM = {
    // 1
    {
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XC0,0X00,0X00,0X3F,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X80,0X00,0X00,0X1F,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X00,0X00,0X00,0X07,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFE,0X00,0X00,0X00,0X03,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFE,0X00,0X00,0X00,0X03,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFE,0X00,0X00,0X00,0X03,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFE,0X00,0X00,0X00,0X03,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFE,0X00,0X00,0X00,0X03,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFE,0X00,0X00,0X00,0X03,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFE,0X00,0X00,0X00,0X07,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X00,0X00,0X00,0X07,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XC0,0X00,0X00,0X1F,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XE0,0X00,0X00,0X3F,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
    },
    // 2
    {
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XC0,0X00,0X00,0X3F,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X80,0X00,0X00,0X1F,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X00,0X00,0X00,0X07,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFE,0X00,0X00,0X00,0X03,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFE,0X00,0X00,0X00,0X03,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFE,0X00,0X00,0X00,0X03,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFE,0X00,0X00,0X00,0X03,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFE,0X00,0X00,0X00,0X03,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFE,0X00,0X00,0X00,0X03,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFE,0X00,0X00,0X00,0X07,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X00,0X00,0X00,0X07,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XC0,0X00,0X00,0X1F,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XE0,0X00,0X00,0X3F,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFC,0X00,0X00,0X00,0X3F,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XF8,0X00,0X00,0X00,0X1F,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XE0,0X00,0X00,0X00,0X07,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XE0,0X00,0X00,0X00,0X07,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XE0,0X00,0X00,0X00,0X03,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XE0,0X00,0X00,0X00,0X03,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XE0,0X00,0X00,0X00,0X03,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XE0,0X00,0X00,0X00,0X07,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XE0,0X00,0X00,0X00,0X07,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XF0,0X00,0X00,0X00,0X0F,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XF8,0X00,0X00,0X00,0X1F,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFC,0X00,0X00,0X00,0X3F,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
    },
    // 3
    {
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XC0,0X00,0X00,0X3F,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X80,0X00,0X00,0X1F,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFE,0X00,0X00,0X00,0X0F,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFE,0X00,0X00,0X00,0X07,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFC,0X00,0X00,0X00,0X07,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFC,0X00,0X00,0X00,0X07,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFC,0X00,0X00,0X00,0X07,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFC,0X00,0X00,0X00,0X07,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFC,0X00,0X00,0X00,0X07,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFE,0X00,0X00,0X00,0X07,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFE,0X00,0X00,0X00,0X0F,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X80,0X00,0X00,0X3F,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XC0,0X00,0X00,0X7F,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFC,0X00,0X00,0X00,0X7F,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XF0,0X00,0X00,0X00,0X0F,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XF0,0X00,0X00,0X00,0X07,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XE0,0X00,0X00,0X00,0X07,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XE0,0X00,0X00,0X00,0X07,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XE0,0X00,0X00,0X00,0X07,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XE0,0X00,0X00,0X00,0X07,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XE0,0X00,0X00,0X00,0X07,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XE0,0X00,0X00,0X00,0X07,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XF0,0X00,0X00,0X00,0X0F,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XF0,0X00,0X00,0X00,0X1F,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XF8,0X00,0X00,0X00,0X3F,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XF8,0X00,0X00,0X00,0X01,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XF0,0X00,0X00,0X00,0X00,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XF0,0X00,0X00,0X00,0X00,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XE0,0X00,0X00,0X00,0X00,0X7F,
        0XFF,0XFF,0XFF,0XFF,0XE0,0X00,0X00,0X00,0X00,0X7F,
        0XFF,0XFF,0XFF,0XFF,0XE0,0X00,0X00,0X00,0X00,0X7F,
        0XFF,0XFF,0XFF,0XFF,0XE0,0X00,0X00,0X00,0X00,0X7F,
        0XFF,0XFF,0XFF,0XFF,0XF0,0X00,0X00,0X00,0X00,0X7F,
        0XFF,0XFF,0XFF,0XFF,0XF0,0X00,0X00,0X00,0X00,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XF0,0X00,0X00,0X00,0X00,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFC,0X00,0X00,0X00,0X03,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
    },
    // 4
    {
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XC0,0X00,0X00,0X3F,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X80,0X00,0X00,0X1F,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X00,0X00,0X00,0X07,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFE,0X00,0X00,0X00,0X03,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFE,0X00,0X00,0X00,0X03,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFE,0X00,0X00,0X00,0X03,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFE,0X00,0X00,0X00,0X03,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFE,0X00,0X00,0X00,0X03,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFE,0X00,0X00,0X00,0X03,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFE,0X00,0X00,0X00,0X07,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X00,0X00,0X00,0X07,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XC0,0X00,0X00,0X1F,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XE0,0X00,0X00,0X3F,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFC,0X00,0X00,0X00,0X3F,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XF8,0X00,0X00,0X00,0X1F,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XE0,0X00,0X00,0X00,0X07,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XE0,0X00,0X00,0X00,0X07,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XE0,0X00,0X00,0X00,0X03,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XE0,0X00,0X00,0X00,0X03,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XE0,0X00,0X00,0X00,0X03,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XE0,0X00,0X00,0X00,0X07,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XE0,0X00,0X00,0X00,0X07,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XF0,0X00,0X00,0X00,0X0F,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XF8,0X00,0X00,0X00,0X1F,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFC,0X00,0X00,0X00,0X3F,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFC,0X00,0X00,0X00,0X01,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XF8,0X00,0X00,0X00,0X00,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XF0,0X00,0X00,0X00,0X00,0X7F,
        0XFF,0XFF,0XFF,0XFF,0XE0,0X00,0X00,0X00,0X00,0X7F,
        0XFF,0XFF,0XFF,0XFF,0XE0,0X00,0X00,0X00,0X00,0X7F,
        0XFF,0XFF,0XFF,0XFF,0XE0,0X00,0X00,0X00,0X00,0X7F,
        0XFF,0XFF,0XFF,0XFF,0XE0,0X00,0X00,0X00,0X00,0X7F,
        0XFF,0XFF,0XFF,0XFF,0XE0,0X00,0X00,0X00,0X00,0X7F,
        0XFF,0XFF,0XFF,0XFF,0XE0,0X00,0X00,0X00,0X00,0X7F,
        0XFF,0XFF,0XFF,0XFF,0XF8,0X00,0X00,0X00,0X00,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFC,0X00,0X00,0X00,0X01,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0X00,0X00,0X00,0X00,0X00,0X3F,0XFF,
        0XFF,0XFF,0XFE,0X00,0X00,0X00,0X00,0X00,0X1F,0XFF,
        0XFF,0XFF,0XFC,0X00,0X00,0X00,0X00,0X00,0X1F,0XFF,
        0XFF,0XFF,0XFC,0X00,0X00,0X00,0X00,0X00,0X0F,0XFF,
        0XFF,0XFF,0XFC,0X00,0X00,0X00,0X00,0X00,0X07,0XFF,
        0XFF,0XFF,0XFC,0X00,0X00,0X00,0X00,0X00,0X07,0XFF,
        0XFF,0XFF,0XFC,0X00,0X00,0X00,0X00,0X00,0X07,0XFF,
        0XFF,0XFF,0XFC,0X00,0X00,0X00,0X00,0X00,0X07,0XFF,
        0XFF,0XFF,0XFC,0X00,0X00,0X00,0X00,0X00,0X07,0XFF,
        0XFF,0XFF,0XFE,0X00,0X00,0X00,0X00,0X00,0X0F,0XFF,
        0XFF,0XFF,0XFF,0X00,0X00,0X00,0X00,0X00,0X1F,0XFF,
        0XFF,0XFF,0XFF,0X80,0X00,0X00,0X00,0X00,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
    },
    // 5
    {
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XC0,0X00,0X00,0X3F,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X80,0X00,0X00,0X1F,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFE,0X00,0X00,0X00,0X0F,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFE,0X00,0X00,0X00,0X07,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFC,0X00,0X00,0X00,0X07,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFC,0X00,0X00,0X00,0X07,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFC,0X00,0X00,0X00,0X07,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFC,0X00,0X00,0X00,0X07,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFC,0X00,0X00,0X00,0X07,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFE,0X00,0X00,0X00,0X07,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFE,0X00,0X00,0X00,0X0F,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X00,0X00,0X00,0X1F,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XC0,0X00,0X00,0X3F,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFC,0X00,0X00,0X00,0X7F,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XF0,0X00,0X00,0X00,0X1F,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XF0,0X00,0X00,0X00,0X1F,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XE0,0X00,0X00,0X00,0X0F,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XE0,0X00,0X00,0X00,0X07,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XE0,0X00,0X00,0X00,0X07,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XE0,0X00,0X00,0X00,0X07,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XE0,0X00,0X00,0X00,0X07,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XE0,0X00,0X00,0X00,0X07,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XF0,0X00,0X00,0X00,0X1F,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XF0,0X00,0X00,0X00,0X1F,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XF8,0X00,0X00,0X00,0X3F,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XF8,0X00,0X00,0X00,0X01,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XF0,0X00,0X00,0X00,0X00,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XF0,0X00,0X00,0X00,0X00,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XF0,0X00,0X00,0X00,0X00,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XE0,0X00,0X00,0X00,0X00,0X7F,
        0XFF,0XFF,0XFF,0XFF,0XE0,0X00,0X00,0X00,0X00,0X7F,
        0XFF,0XFF,0XFF,0XFF,0XF0,0X00,0X00,0X00,0X00,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XF0,0X00,0X00,0X00,0X00,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XF0,0X00,0X00,0X00,0X00,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XF8,0X00,0X00,0X00,0X00,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XF8,0X00,0X00,0X00,0X01,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0X00,0X00,0X00,0X00,0X00,0X7F,0XFF,
        0XFF,0XFF,0XFE,0X00,0X00,0X00,0X00,0X00,0X3F,0XFF,
        0XFF,0XFF,0XFE,0X00,0X00,0X00,0X00,0X00,0X1F,0XFF,
        0XFF,0XFF,0XFE,0X00,0X00,0X00,0X00,0X00,0X0F,0XFF,
        0XFF,0XFF,0XFC,0X00,0X00,0X00,0X00,0X00,0X0F,0XFF,
        0XFF,0XFF,0XF8,0X00,0X00,0X00,0X00,0X00,0X0F,0XFF,
        0XFF,0XFF,0XF8,0X00,0X00,0X00,0X00,0X00,0X0F,0XFF,
        0XFF,0XFF,0XFC,0X00,0X00,0X00,0X00,0X00,0X0F,0XFF,
        0XFF,0XFF,0XFE,0X00,0X00,0X00,0X00,0X00,0X0F,0XFF,
        0XFF,0XFF,0XFE,0X00,0X00,0X00,0X00,0X00,0X0F,0XFF,
        0XFF,0XFF,0XFF,0X00,0X00,0X00,0X00,0X00,0X1F,0XFF,
        0XFF,0XFF,0XFF,0X80,0X00,0X00,0X00,0X00,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XC0,0X00,0X00,0X00,0X00,0X00,0X00,0XFF,0XFF,0XFF,
        0X80,0X00,0X00,0X00,0X00,0X00,0X00,0XFF,0XFF,0XFF,
        0X00,0X00,0X00,0X00,0X00,0X00,0X00,0XFF,0XFF,0XFF,
        0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X7F,0XFF,0XFF,
        0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X7F,0XFF,0XFF,
        0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X7F,0XFF,0XFF,
        0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X7F,0XFF,0XFF,
        0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X7F,0XFF,0XFF,
        0X80,0X00,0X00,0X00,0X00,0X00,0X00,0XFF,0XFF,0XFF,
        0XC0,0X00,0X00,0X00,0X00,0X00,0X00,0XFF,0XFF,0XFF,
        0XE0,0X00,0X00,0X00,0X00,0X00,0X01,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
    }
};