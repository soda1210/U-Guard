# ifndef _PIN_SETTING_H
# define _PIN_SETTING_H

// IO setting
int BUSY_Pin = 33;
int RES_Pin = 32;
int DC_Pin = 27;
int CS_Pin = 14;
// SCLK--GPIO23
// MOSI---GPIO18

#define EPD_W21_CS_0 digitalWrite(CS_Pin, LOW)
#define EPD_W21_CS_1 digitalWrite(CS_Pin, HIGH)
#define EPD_W21_DC_0 digitalWrite(DC_Pin, LOW)
#define EPD_W21_DC_1 digitalWrite(DC_Pin, HIGH)
#define EPD_W21_RST_0 digitalWrite(RES_Pin, LOW)
#define EPD_W21_RST_1 digitalWrite(RES_Pin, HIGH)
#define isEPD_W21_BUSY digitalRead(BUSY_Pin)

#endif // _PIN_SETTING_H