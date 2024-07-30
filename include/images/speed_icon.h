// 車錶 速度圖示
#include <Arduino.h>

#include "speedIcon/speed_icon1.h"
#include "speedIcon/speed_icon2.h"
#include "speedIcon/speed_icon3.h"
#include "speedIcon/speed_icon4.h"
#include "speedIcon/speed_icon5.h"

const unsigned char* image_speed_icon[5] PROGMEM = {
    speed_icon1,
    speed_icon2,
    speed_icon3,
    speed_icon4,
    speed_icon5
};