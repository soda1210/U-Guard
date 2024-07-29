#ifndef _DISPLAY_H
#define _DISPLAY_H

#include "pages.h"

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
  EPD_SetRAMValue_BaseMap(white);
}

void reflashing_screen(Bike *bike){
    unsigned int speed_int = (int)bike->speed; // 取整數部分
    if (false){
        displayBikeMode(speed_int);
    }else{
        displayWatchMode(speed_int);
    }
}

#endif // DISPLAY_H
