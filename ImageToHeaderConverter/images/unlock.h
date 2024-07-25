#include <Arduino.h>

const unsigned char unlock[200] PROGMEM = {
    0XFF,0XE0,0X00,0X00,0X03,
    0XFF,0XC0,0X00,0X00,0X01,
    0XFF,0XC0,0X00,0X00,0X00,
    0XFF,0XC0,0X00,0X00,0X00,
    0XFF,0XC0,0X00,0X00,0X00,
    0XFF,0XC0,0X00,0XC0,0X00,
    0XFF,0XC0,0X00,0XC0,0X00,
    0XFF,0XC0,0X00,0XC0,0X00,
    0XFF,0XC0,0X00,0XC0,0X00,
    0XFF,0XC0,0X01,0XC0,0X00,
    0XFF,0XC0,0X03,0XE0,0X00,
    0XFF,0XC0,0X03,0XF0,0X00,
    0XFF,0XC0,0X07,0XF0,0X00,
    0XFF,0XC0,0X07,0XF0,0X00,
    0X3F,0XC0,0X03,0XF0,0X00,
    0X0F,0XC0,0X03,0XE0,0X00,
    0X83,0XC0,0X00,0X00,0X00,
    0XE1,0XC0,0X00,0X00,0X00,
    0XF9,0XC0,0X00,0X00,0X00,
    0XFF,0XC0,0X00,0X00,0X01,
    0XFF,0XE0,0X00,0X00,0X03,
    0X81,0XFF,0XFF,0XFE,0X03,
    0X01,0XFF,0XFF,0XFE,0X03,
    0XFF,0XFF,0XFF,0XFE,0X03,
    0XFF,0XF0,0X1F,0XFE,0X03,
    0XFF,0XF0,0X1F,0XFE,0X03,
    0XF1,0XF0,0X1F,0XFE,0X03,
    0XC1,0XF0,0X1F,0XFE,0X03,
    0X83,0XF0,0X1F,0XFC,0X03,
    0X0F,0XF0,0X1F,0XFC,0X07,
    0XFF,0XF0,0X0F,0XFC,0X07,
    0XFF,0XF8,0X07,0XF8,0X07,
    0XFF,0XF8,0X01,0XE0,0X0F,
    0XFF,0XFC,0X00,0X00,0X0F,
    0XFF,0XFC,0X00,0X00,0X1F,
    0XFF,0XFE,0X00,0X00,0X1F,
    0XFF,0XFF,0X00,0X00,0X3F,
    0XFF,0XFF,0X80,0X00,0XFF,
    0XFF,0XFF,0XE0,0X01,0XFF,
    0XFF,0XFF,0XF8,0X0F,0XFF,
};