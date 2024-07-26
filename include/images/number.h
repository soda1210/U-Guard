#include <Arduino.h>

#include "numberFont/number_0.h"
#include "numberFont/number_1.h"
#include "numberFont/number_2.h"
#include "numberFont/number_3.h"
#include "numberFont/number_4.h"
#include "numberFont/number_5.h"
#include "numberFont/number_6.h"
#include "numberFont/number_7.h"
#include "numberFont/number_8.h"
#include "numberFont/number_9.h"

const unsigned char* number[10]PROGMEM = {
    number_0,
    number_1,
    number_2,
    number_3,
    number_4,
    number_5,
    number_6,
    number_7,
    number_8,
    number_9
};