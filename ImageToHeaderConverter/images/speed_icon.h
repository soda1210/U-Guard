// 車錶 速度圖示
#include <Arduino.h>

#include "../speedIcon/speed_icon1.h"
#include "../speedIcon/speed_icon2.h"
#include "../speedIcon/speed_icon3.h"
#include "../speedIcon/speed_icon4.h"
#include "../speedIcon/speed_icon5.h"

const unsigned char image_speed_icon[5][800] PROGMEM = {
    (const unsigned char)speed_icon1,
    (const unsigned char)speed_icon2,
    (const unsigned char)speed_icon3,
    (const unsigned char)speed_icon4,
    (const unsigned char)speed_icon5
};