#include <Arduino.h>

#include "bikeBattery/BikeBattery_20.h"
#include "bikeBattery/BikeBattery_40.h"
#include "bikeBattery/BikeBattery_60.h"
#include "bikeBattery/BikeBattery_80.h"
#include "bikeBattery/BikeBattery_100.h"

const unsigned char* bike_battery[5] PROGMEM = {
    BikeBattery_20,
    BikeBattery_40,
    BikeBattery_60,
    BikeBattery_80,
    BikeBattery_100
};