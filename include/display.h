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
    bool isLock;
    bool buzzer;
    bool assistMode;
    float speed;
    float torque;
    uint16_t cadence;
    uint16_t errorCode;
    uint8_t distance;
    uint8_t battery;
    uint8_t assist;
    BikeMode mode;
} Bike;

// 初始化顯示屏幕
void init_screen();
// 更新畫面
void reflashing_screen(Bike *bike);

void init_screen()
{
    EPD_HW_Init();
    EPD_SetRAMValue_BaseMap(image_white);
}

void reflashing_screen(Bike *bike)
{
    bool isLock = bike->isLock;
    bool buzzer = bike->buzzer;
    unsigned int speed = (int)bike->speed;
    uint8_t battery = bike->battery;

    bool assistMode = bike->assistMode;
    uint8_t assist = bike->assist;

    if (bike->mode == MODE_BIKE)
    {
        displayBikeMode(assistMode, buzzer, speed, battery, assist);
    }
    else if (bike->mode == MODE_KEY)
    {
        displayWatchMode(isLock, buzzer, speed, battery);
    }
    else
    {
        bike->errorCode = 1;
    }
}

#endif // DISPLAY_H
