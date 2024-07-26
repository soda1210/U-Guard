#include <Arduino.h>

#include "../bikeBattery/BikeBattery_20.h"
#include "../bikeBattery/BikeBattery_40.h"
#include "../bikeBattery/BikeBattery_60.h"
#include "../bikeBattery/BikeBattery_80.h"
#include "../bikeBattery/BikeBattery_100.h"

const unsigned char bike_battery[5][608] PROGMEM = {
    (const unsigned char)BikeBattery_20,
    (const unsigned char)BikeBattery_40,
    (const unsigned char)BikeBattery_60,
    (const unsigned char)BikeBattery_80,
    (const unsigned char)BikeBattery_100
};