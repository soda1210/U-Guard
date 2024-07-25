#include <Arduino.h>

#include "../numberFont/number_0.h"
#include "../numberFont/number_1.h"
#include "../numberFont/number_2.h"
#include "../numberFont/number_3.h"
#include "../numberFont/number_4.h"
#include "../numberFont/number_5.h"
#include "../numberFont/number_6.h"
#include "../numberFont/number_7.h"
#include "../numberFont/number_8.h"
#include "../numberFont/number_9.h"

const unsigned char number[10][256]PROGMEM = {
    (const unsigned char)number_0,
    (const unsigned char)number_1,
    (const unsigned char)number_2,
    (const unsigned char)number_3,
    (const unsigned char)number_4,
    (const unsigned char)number_5,
    (const unsigned char)number_6,
    (const unsigned char)number_7,
    (const unsigned char)number_8,
    (const unsigned char)number_9
};