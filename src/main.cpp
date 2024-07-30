#include <Arduino.h>

#include "display.h"
#include "ePaperTools.h"

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
  // Bike {speed, torque, cadence, distance, errorCode, battery, assist, mode}
  bike = {true, false, true, 0, 0, 0, 0, 88, 0, 0, bikeMode};
  Serial.println("Start!");
  init_screen();
  delay(2000);
}

void loop()
{
  testDisplay();
}