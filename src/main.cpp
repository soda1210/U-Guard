
// FIXME: This include after the defines
#include <Arduino.h>
#include <SPI.h>
#include <display.h>
#include <ePaperTools.h>
#include <example.h>


#define EPD_W21_CS_0 digitalWrite(CS_Pin, LOW)
#define EPD_W21_CS_1 digitalWrite(CS_Pin, HIGH)
#define EPD_W21_DC_0 digitalWrite(DC_Pin, LOW)
#define EPD_W21_DC_1 digitalWrite(DC_Pin, HIGH)
#define EPD_W21_RST_0 digitalWrite(RES_Pin, LOW)
#define EPD_W21_RST_1 digitalWrite(RES_Pin, HIGH)
#define isEPD_W21_BUSY digitalRead(BUSY_Pin)

// IO setting
//  int BUSY_Pin = 33;
//  int RES_Pin = 32;
//  int DC_Pin = 27;
//  int CS_Pin = 14;
//  SCLK--GPIO23
//  MOSI---GPIO18

Bike bike;
BikeMode bikeMode;

void setup()
{
  Serial.begin(9600);
  pinMode(BUSY_Pin, INPUT);
  pinMode(RES_Pin, OUTPUT);
  pinMode(DC_Pin, OUTPUT);
  pinMode(CS_Pin, OUTPUT);
  // SPI
  SPI.beginTransaction(SPISettings(10000000, MSBFIRST, SPI_MODE0));
  SPI.begin();
  // Display
  bikeMode = MODE_BIKE;
  bike = {0, 0, 0, 0, 0, 0, bikeMode};
  Serial.println("Start!");
  init_screen();
  delay(2000);
}

void loop()
{
  unsigned char fen_L, fen_H, miao_L, miao_H;
  for (miao_H = 0; miao_H < 10; miao_H++)
  {
    for (miao_L = 0; miao_L < 10; miao_L++)
    {
      bike.speed = 10 * miao_H + miao_L;
      reflashing_screen(&bike);
      delay(100);
      // displayNumber(64, 122, number[miao_L],
      //               96, 122, number[miao_H], 64, 32);
    }
  }
}