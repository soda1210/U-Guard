#include <Arduino.h>

#include "../watchBattery/WatchBattery_25.h"
#include "../watchBattery/WatchBattery_50.h"
#include "../watchBattery/WatchBattery_75.h"
#include "../watchBattery/WatchBattery_100.h"

const unsigned char watch_battery[4][200] PROGMEM = {
    (const unsigned char)WatchBattery_25,
    (const unsigned char)WatchBattery_50,
    (const unsigned char)WatchBattery_75,
    (const unsigned char)WatchBattery_100
};