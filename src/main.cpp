
//IO setting
int BUSY_Pin = 33;
int RES_Pin = 32;
int DC_Pin = 27;
int CS_Pin = 14;
//SCLK--GPIO23
//MOSI---GPIO18

#define EPD_W21_CS_0 digitalWrite(CS_Pin, LOW)
#define EPD_W21_CS_1 digitalWrite(CS_Pin, HIGH)
#define EPD_W21_DC_0 digitalWrite(DC_Pin, LOW)
#define EPD_W21_DC_1 digitalWrite(DC_Pin, HIGH)
#define EPD_W21_RST_0 digitalWrite(RES_Pin, LOW)
#define EPD_W21_RST_1 digitalWrite(RES_Pin, HIGH)
#define isEPD_W21_BUSY digitalRead(BUSY_Pin)

// FIXME: This include after the defines
#include <Arduino.h>
#include <SPI.h>
#include "../ePaperDisplay/ePaperTools.h"
#include "../ePaperDisplay/example.h"
#include "../ePaperDisplay/number.h"

void setup() {
  Serial.begin(9600);
  pinMode(BUSY_Pin, INPUT);
  pinMode(RES_Pin, OUTPUT);
  pinMode(DC_Pin, OUTPUT);
  pinMode(CS_Pin, OUTPUT);
  //SPI
  SPI.beginTransaction(SPISettings(10000000, MSBFIRST, SPI_MODE0));
  SPI.begin();
}

void loop() {
  unsigned char fen_L, fen_H, miao_L, miao_H;

  // EPD_HW_Init();   //Electronic paper initialization
  // Serial.println("show gImage_1");
  // EPD_WhiteScreen_ALL(gImage_1);  //Refresh the picture in full screen
  // delay(2000);

  Serial.println("Start!");
  EPD_HW_Init();
  EPD_SetRAMValue_BaseMap(autoMode);  //Partial refresh background color,Brush map is a must, please do not delete
  delay(2000);
  
  for (miao_H = 0; miao_H < 10; miao_H++) {
    for (miao_L = 0; miao_L < 10; miao_L++) {
      displayNumber(64, 122, number[miao_L],           //x-A,y-A,DATA-A
                          96, 122, number[miao_H], 64, 32);  //x-B,y-B,DATA-B,Resolution 32*64

      // if ((fen_L == 0) && (miao_Hz == 0) && (miao_L == 5))
      //   goto Clear;
    }
  }
//   //Clean
// Clear:
//   delay(2000);              //2s
//   EPD_HW_Init();            //Electronic paper initialization
//   EPD_WhiteScreen_White();  //Show all white
//   EPD_DeepSleep();          //Enter deep sleep,Sleep instruction is necessary, please do not delete!!!
//   while (1)
//     ;
}