#include <Arduino.h>

#include "display.h"

Bike bike;
BikeMode bikeMode;

void testDisplay(){
  for (int testValue = 0; testValue < 100; testValue++){
    bike.speed = testValue;
    reflashing_screen(&bike);
    delay(1000);
  }
}

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
  testDisplay();
}