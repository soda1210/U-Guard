#include <Arduino.h>

#include "display.h"

Bike bike;
BikeMode bikeMode;

void testDisplay()
{
  for (int testValue = 0; testValue < 10; testValue++)
  {
    bike.speed = testValue;
    bike.battery = testValue * 10;
    reflashing_screen(&bike);
    delay(500);
  }
  bike.mode = MODE_KEY;
  init_screen();
  delay(200);
  for (int testValue = 0; testValue < 10; testValue++)
  {
    bike.speed = testValue;
    bike.battery = testValue * 10;
    reflashing_screen(&bike);
    delay(500);
  }
  bike.mode = MODE_BIKE;
  init_screen();
  delay(200);
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
  bike = {.isLock = true,
        .buzzer = false,
        .assistMode = true,
        .speed = 0.0,
        .torque = 0.0,
        .cadence = 0,
        .errorCode = 0,
        .distance = 88,
        .battery = 0,
        .assist = 0,
        .mode = bikeMode};
  Serial.println("Start!");
  init_screen();
  delay(2000);
}

void loop()
{
  testDisplay();
}