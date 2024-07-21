#ifndef DISPLAY_H
#define DISPLAY_H

#include <ePaperTools.h>
#include <image.h>
#include <number.h>

typedef unsigned char uint8_t;
typedef unsigned short int uint16_t;

// Mode of the bike
typedef enum
{
    MODE_BIKE,
    MODE_KEY
} BikeMode;

// 定義Display結構體
typedef struct
{
    float speed;
    float torque;
    uint16_t cadence;
    uint16_t errorCode;
    uint8_t battery;
    uint8_t assist;
    BikeMode mode;
} Bike;

// 初始化顯示屏幕
void init_screen();
// 更新畫面
void reflashing_screen(Bike *bike);

void init_screen(){
  EPD_HW_Init();
  EPD_SetRAMValue_BaseMap(image_CHC);
}


void reflashing_screen(Bike *bike){
    // TODO: Get the info from the bike
    int speed_int = (int)bike->speed; // 取整數部分
    int tens = (speed_int / 10) % 10; // 取十位數
    int ones = speed_int % 10;        // 取個位數
    displayNumber(64, 122, number[ones],
                    96, 122, number[tens], 64, 32);
}

#endif // DISPLAY_H
