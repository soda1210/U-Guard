#include <Arduino.h>

#include "watchBattery/WatchBattery_25.h"
#include "watchBattery/WatchBattery_50.h"
#include "watchBattery/WatchBattery_75.h"
#include "watchBattery/WatchBattery_100.h"

const unsigned char* image_watch_battery[4] PROGMEM = {
    WatchBattery_25,
    WatchBattery_50,
    WatchBattery_75,
    WatchBattery_100
};