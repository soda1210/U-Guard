#ifndef EPAPER_TOOLS_H
#define EPAPER_TOOLS_H

#include <Arduino.h>
#include <SPI.h>
#include <display.h>
#include <image.h>
#include <number.h>

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

#include <SPI.h>
////////FUNCTION//////
void SPI_Write(unsigned char value);
void Epaper_Write_Command(unsigned char command);
void Epaper_Write_Data(unsigned char command);
// EPD
void Epaper_READBUSY(void);
void SPI_Write(unsigned char TxData);
void Epaper_Write_Command(unsigned char cmd);
void Epaper_Write_Data(unsigned char data);

void EPD_HW_Init(void); // Electronic paper initialization
void EPD_Part_Update(void);
void EPD_Update(void);

void EPD_WhiteScreen_Black(void);
void EPD_WhiteScreen_White(void);
void EPD_DeepSleep(void);
// Display
void EPD_WhiteScreen_ALL(const unsigned char *datas);
void EPD_SetRAMValue_BaseMap(const unsigned char *datas);

void EPD_Dis_Part(unsigned int x_start, unsigned int y_start, const unsigned char *datas, unsigned int PART_COLUMN, unsigned int PART_LINE);

void EPD_Dis_Part_myself(unsigned int x_startA, unsigned int y_startA, const unsigned char *datasA,
                         unsigned int x_startB, unsigned int y_startB, const unsigned char *datasB,
                         unsigned int x_startC, unsigned int y_startC, const unsigned char *datasC,
                         unsigned int x_startD, unsigned int y_startD, const unsigned char *datasD,
                         unsigned int x_startE, unsigned int y_startE, const unsigned char *datasE,
                         unsigned int PART_COLUMN, unsigned int PART_LINE);
                         
void displayNumber(unsigned int x_startA, unsigned int y_startA, const unsigned char *datasA,
                   unsigned int x_startB, unsigned int y_startB, const unsigned char *datasB,
                   unsigned int PART_COLUMN, unsigned int PART_LINE);

void writeBlack(unsigned int x_start, unsigned int x_end,
                unsigned int y_start1, unsigned int y_end1,
                unsigned int y_start2, unsigned int y_end2,
          const unsigned char *datas, unsigned int PART_COLUMN,unsigned int PART_LINE);

void writeImage(int x, int y, unsigned int column, unsigned int line, const unsigned char *image);
// TODO: add function to display image

void writeNumber(unsigned int x_start, unsigned int x_end, unsigned int number);

struct Coordinates {
    unsigned int x_start;
    unsigned int x_end;
    unsigned int y_start1;
    unsigned int y_start2;
    unsigned int y_end1;
    unsigned int y_end2;
};

Coordinates transformXY(unsigned int x_start, unsigned int x_end,
                unsigned int y_start1, unsigned int y_end1,
                unsigned int y_start2, unsigned int y_end2,
                unsigned int PART_COLUMN,unsigned int PART_LINE);

void displayWatchMode(unsigned int inputNumber);


void displayBikeMode(unsigned int inputNumber);

Coordinates transformXY(unsigned int x_start, unsigned int y_start,
                unsigned int PART_COLUMN,unsigned int PART_LINE){
  Coordinates result;
  unsigned int x_end, y_start1, y_start2, y_end1, y_end2;
  result.x_start = x_start / 8; // Convert to byte
  result.x_end = result.x_start + PART_LINE / 8 - 1;

  result.y_start1 = 0;
  result.y_start2 = y_start - 1;
  if (y_start >= 256)
  {
      result.y_start1 = result.y_start2 / 256;
      result.y_start2 = result.y_start2 % 256;
  }
  result.y_end1 = 0;
  result.y_end2 = y_start + PART_COLUMN - 1;
  if (result.y_end2 >= 256)
  {
      result.y_end1 = result.y_end2 / 256;
      result.y_end2 = result.y_end2 % 256;
  }

  return result;
}

void writeBlack(unsigned int x_start, unsigned int x_end,
          unsigned int y_start1, unsigned int y_end1,
          unsigned int y_start2, unsigned int y_end2,
          const unsigned char *datas, unsigned int PART_COLUMN,unsigned int PART_LINE)
{
  Epaper_Write_Command(0x44);  // set RAM x address start/end, in page 35
  Epaper_Write_Data(x_start); // RAM x address start at 00h;
  Epaper_Write_Data(x_end);    // RAM x address end at 0fh(15+1)*8->128
  Epaper_Write_Command(0x45);  // set RAM y address start/end, in page 35
  Epaper_Write_Data(y_start2); // RAM y address start at 0127h;
  Epaper_Write_Data(y_start1); // RAM y address start at 0127h;
  Epaper_Write_Data(y_end2);   // RAM y address end at 00h;
  Epaper_Write_Data(y_end1);

  Epaper_Write_Command(0x4E); // set RAM x address count to 0;
  Epaper_Write_Data(x_start);
  Epaper_Write_Command(0x4F); // set RAM y address count to 0X127;
  Epaper_Write_Data(y_start2);
  Epaper_Write_Data(y_start1);

  Epaper_Write_Command(0x24); // Write Black and White image to RAM
  for (int i = 0; i < PART_COLUMN * PART_LINE / 8; i++)
  {
    Epaper_Write_Data(pgm_read_byte(&datas[i]));
  }
}


void writeImage(int x, int y, unsigned int column, unsigned int line, const unsigned char *image)
{
  Coordinates tramXY = transformXY(x, y, column, line);
  writeBlack(tramXY.x_start, tramXY.x_end, tramXY.y_start1, tramXY.y_end1,
              tramXY.y_start2, tramXY.y_end2, image, column, line);
}

void displayNumber(unsigned int x_startA, unsigned int y_startA, const unsigned char *datasA,
                   unsigned int x_startB, unsigned int y_startB, const unsigned char *datasB,
                   unsigned int PART_COLUMN, unsigned int PART_LINE)
{
  // Reset
  EPD_W21_RST_0; // Module reset
  delay(10);     // At least 10ms delay
  EPD_W21_RST_1;
  delay(10); // At least 10ms delay

  Epaper_Write_Command(0x3C); // BorderWavefrom
  Epaper_Write_Data(0x80);

  // 個位數
  Coordinates tramXY = transformXY(x_startA, y_startA, PART_COLUMN, PART_LINE);
  writeBlack(tramXY.x_start, tramXY.x_end, tramXY.y_start1, tramXY.y_end1, tramXY.y_start2, tramXY.y_end2, datasA, PART_COLUMN, PART_LINE);
  // 十位數
  tramXY = transformXY(x_startB, y_startB, PART_COLUMN, PART_LINE);
  writeBlack(tramXY.x_start, tramXY.x_end, tramXY.y_start1, tramXY.y_end1, tramXY.y_start2, tramXY.y_end2, datasB, PART_COLUMN, PART_LINE);
  EPD_Part_Update();
}

void writeNumber(unsigned int x_start, unsigned int y_start, unsigned int inputNumber)
{
  Coordinates tramXY;
  unsigned int tens = inputNumber / 10;
  unsigned int ones = inputNumber % 10;  
  // 個位數
  tramXY = transformXY(x_start, y_start, 64, 32);
  writeBlack(tramXY.x_start, tramXY.x_end, tramXY.y_start1, tramXY.y_end1, tramXY.y_start2, tramXY.y_end2, number[ones], 64, 32);
  // 十位數
  tramXY = transformXY(x_start+32, y_start, 64, 32);
  writeBlack(tramXY.x_start, tramXY.x_end, tramXY.y_start1, tramXY.y_end1, tramXY.y_start2, tramXY.y_end2, number[tens], 64, 32);

}

void displayWatchMode(unsigned int inputNumber){
  Coordinates tramXY;
  unsigned int column, line; 

  // Reset
  EPD_W21_RST_0; // Module reset
  delay(10);     // At least 10ms delay
  EPD_W21_RST_1;
  delay(10); // At least 10ms delay

  Epaper_Write_Command(0x3C); // BorderWavefrom
  Epaper_Write_Data(0x80);

  // TODO: import image change to prompt
  
  // 電池
  writeImage(6, 200, 40, 40, watch_battery[0]);
  // 左上角鎖
  writeImage(160, 200, 40, 40, lock);
  // 腳踏車 Bibi
  writeImage(48, 136, 104, 104, big_bike);
  // 右訊號
  writeImage(25, 150, 48, 48, right_single);
  // 左訊號
  writeImage(135, 150, 48, 48, left_single);
  // 數值顯示
  writeNumber(68, 52, inputNumber);

  // 更新畫面
  EPD_Part_Update();
}

void displayBikeMode(unsigned int inputNumber){
  ;
}
//////////////////////SPI///////////////////////////////////

void SPI_Write(unsigned char value)
{
  SPI.transfer(value);
}

void Epaper_Write_Command(unsigned char command)
{
  EPD_W21_CS_0;
  EPD_W21_DC_0; // command write
  SPI_Write(command);
  EPD_W21_CS_1;
}
void Epaper_Write_Data(unsigned char command)
{
  EPD_W21_CS_0;
  EPD_W21_DC_1; // command write
  SPI_Write(command);
  EPD_W21_CS_1;
}

/////////////////EPD settings Functions/////////////////////
void EPD_HW_Init(void)
{
  EPD_W21_RST_0; // Module reset
  delay(10);     // At least 10ms delay
  EPD_W21_RST_1;
  delay(10); // At least 10ms delay

  Epaper_READBUSY();
  Epaper_Write_Command(0x12); // SWRESET
  Epaper_READBUSY();

  Epaper_Write_Command(0x01); // Driver output control
  Epaper_Write_Data(0xC7);
  Epaper_Write_Data(0x00);
  Epaper_Write_Data(0x00);

  Epaper_Write_Command(0x11); // data entry mode
  Epaper_Write_Data(0x01);

  Epaper_Write_Command(0x44); // set Ram-X address start/end position
  Epaper_Write_Data(0x00);
  Epaper_Write_Data(0x18); // 0x0C-->(18+1)*8=200

  Epaper_Write_Command(0x45); // set Ram-Y address start/end position
  Epaper_Write_Data(0xC7);    // 0xC7-->(199+1)=200
  Epaper_Write_Data(0x00);
  Epaper_Write_Data(0x00);
  Epaper_Write_Data(0x00);

  Epaper_Write_Command(0x3C); // BorderWavefrom
  Epaper_Write_Data(0x05);

  Epaper_Write_Command(0x18); // Reading temperature sensor
  Epaper_Write_Data(0x80);

  Epaper_Write_Command(0x4E); // set RAM x address count to 0;
  Epaper_Write_Data(0x00);
  Epaper_Write_Command(0x4F); // set RAM y address count to 0X199;
  Epaper_Write_Data(0xC7);
  Epaper_Write_Data(0x00);
  Epaper_READBUSY();
}
//////////////////////////////All screen update////////////////////////////////////////////
void EPD_WhiteScreen_ALL(const unsigned char *datas)
{
  unsigned int i;
  Epaper_Write_Command(0x24); // write RAM for black(0)/white (1)
  for (i = 0; i < 5000; i++)
  {
    Epaper_Write_Data(pgm_read_byte(&datas[i]));
  }
  EPD_Update();
}

/////////////////////////////////////////////////////////////////////////////////////////
void EPD_Update(void)
{
  Epaper_Write_Command(0x22); // Display Update Control
  Epaper_Write_Data(0xF7);
  Epaper_Write_Command(0x20); // Activate Display Update Sequence
  Epaper_READBUSY();
}
void EPD_Part_Update(void)
{
  Epaper_Write_Command(0x22); // Display Update Control
  Epaper_Write_Data(0xFF);
  Epaper_Write_Command(0x20); // Activate Display Update Sequence
  Epaper_READBUSY();
}
void EPD_DeepSleep(void)
{
  Epaper_Write_Command(0x10); // enter deep sleep
  Epaper_Write_Data(0x01);
  delay(100);
}
void Epaper_READBUSY(void)
{
  while (1)
  { //=1 BUSY
    if (isEPD_W21_BUSY == 0)
      break;
  }
}
///////////////////////////Part update//////////////////////////////////////////////
void EPD_SetRAMValue_BaseMap(const unsigned char *datas)
{
  unsigned int i;
  const unsigned char *datas_flag;
  datas_flag = datas;
  Epaper_Write_Command(0x24); // Write Black and White image to RAM
  for (i = 0; i < 5000; i++)
  {
    Epaper_Write_Data(pgm_read_byte(&datas[i]));
  }
  datas = datas_flag;
  Epaper_Write_Command(0x26); // Write Black and White image to RAM
  for (i = 0; i < 5000; i++)
  {
    Epaper_Write_Data(pgm_read_byte(&datas[i]));
  }
  EPD_Update();
}

void EPD_Dis_Part(unsigned int x_start, unsigned int y_start, const unsigned char *datas, unsigned int PART_COLUMN, unsigned int PART_LINE)
{
  unsigned int i;
  unsigned int x_end, y_start1, y_start2, y_end1, y_end2;
  x_start = x_start / 8; //
  x_end = x_start + PART_LINE / 8 - 1;

  y_start1 = 0;
  y_start2 = y_start;
  if (y_start >= 256)
  {
    y_start1 = y_start2 / 256;
    y_start2 = y_start2 % 256;
  }
  y_end1 = 0;
  y_end2 = y_start + PART_COLUMN - 1;
  if (y_end2 >= 256)
  {
    y_end1 = y_end2 / 256;
    y_end2 = y_end2 % 256;
  }
  // Add hardware reset to prevent background color change
  EPD_W21_RST_0; // Module reset
  delay(10);     // At least 10ms delay
  EPD_W21_RST_1;
  delay(10); // At least 10ms delay

  // Lock the border to prevent flashing
  Epaper_Write_Command(0x3C); // BorderWavefrom,
  Epaper_Write_Data(0x80);
  //
  Epaper_Write_Command(0x44);  // set RAM x address start/end, in page 35
  Epaper_Write_Data(x_start);  // RAM x address start at 00h;
  Epaper_Write_Data(x_end);    // RAM x address end at 0fh(15+1)*8->128
  Epaper_Write_Command(0x45);  // set RAM y address start/end, in page 35
  Epaper_Write_Data(y_start2); // RAM y address start at 0127h;
  Epaper_Write_Data(y_start1); // RAM y address start at 0127h;
  Epaper_Write_Data(y_end2);   // RAM y address end at 00h;
  Epaper_Write_Data(y_end1);   // ????=0

  Epaper_Write_Command(0x4E); // set RAM x address count to 0;
  Epaper_Write_Data(x_start);
  Epaper_Write_Command(0x4F); // set RAM y address count to 0X127;
  Epaper_Write_Data(y_start2);
  Epaper_Write_Data(y_start1);

  Epaper_Write_Command(0x24); // Write Black and White image to RAM
  for (i = 0; i < PART_COLUMN * PART_LINE / 8; i++)
  {
    Epaper_Write_Data(pgm_read_byte(&datas[i]));
  }
  EPD_Part_Update();
}

////////////////////////////////////TIME///////////////////////////////////////////////////
void EPD_Dis_Part_myself(unsigned int x_startA, unsigned int y_startA, const unsigned char *datasA,
                         unsigned int x_startB, unsigned int y_startB, const unsigned char *datasB,
                         unsigned int x_startC, unsigned int y_startC, const unsigned char *datasC,
                         unsigned int x_startD, unsigned int y_startD, const unsigned char *datasD,
                         unsigned int x_startE, unsigned int y_startE, const unsigned char *datasE,
                         unsigned int PART_COLUMN, unsigned int PART_LINE)
{
  unsigned int i;
  unsigned int x_end, y_start1, y_start2, y_end1, y_end2;

  // Data A////////////////////////////
  x_startA = x_startA / 8; // Convert to byte
  x_end = x_startA + PART_LINE / 8 - 1;

  y_start1 = 0;
  y_start2 = y_startA - 1;
  if (y_startA >= 256)
  {
    y_start1 = y_start2 / 256;
    y_start2 = y_start2 % 256;
  }
  y_end1 = 0;
  y_end2 = y_startA + PART_COLUMN - 1;
  if (y_end2 >= 256)
  {
    y_end1 = y_end2 / 256;
    y_end2 = y_end2 % 256;
  }
  // Reset
  EPD_W21_RST_0; // Module reset
  delay(10);     // At least 10ms delay
  EPD_W21_RST_1;
  delay(10); // At least 10ms delay

  Epaper_Write_Command(0x3C); // BorderWavefrom
  Epaper_Write_Data(0x80);
  //
  Epaper_Write_Command(0x44);  // set RAM x address start/end, in page 35
  Epaper_Write_Data(x_startA); // RAM x address start at 00h;
  Epaper_Write_Data(x_end);    // RAM x address end at 0fh(15+1)*8->128
  Epaper_Write_Command(0x45);  // set RAM y address start/end, in page 35
  Epaper_Write_Data(y_start2); // RAM y address start at 0127h;
  Epaper_Write_Data(y_start1); // RAM y address start at 0127h;
  Epaper_Write_Data(y_end2);   // RAM y address end at 00h;
  Epaper_Write_Data(y_end1);

  Epaper_Write_Command(0x4E); // set RAM x address count to 0;
  Epaper_Write_Data(x_startA);
  Epaper_Write_Command(0x4F); // set RAM y address count to 0X127;
  Epaper_Write_Data(y_start2);
  Epaper_Write_Data(y_start1);

  Epaper_Write_Command(0x24); // Write Black and White image to RAM
  for (i = 0; i < PART_COLUMN * PART_LINE / 8; i++)
  {
    Epaper_Write_Data(pgm_read_byte(&datasA[i]));
  }
  // Data B/////////////////////////////////////
  x_startB = x_startB / 8; // Convert to byte
  x_end = x_startB + PART_LINE / 8 - 1;

  y_start1 = 0;
  y_start2 = y_startB - 1;
  if (y_startB >= 256)
  {
    y_start1 = y_start2 / 256;
    y_start2 = y_start2 % 256;
  }
  y_end1 = 0;
  y_end2 = y_startB + PART_COLUMN - 1;
  if (y_end2 >= 256)
  {
    y_end1 = y_end2 / 256;
    y_end2 = y_end2 % 256;
  }

  Epaper_Write_Command(0x44);  // set RAM x address start/end, in page 35
  Epaper_Write_Data(x_startB); // RAM x address start at 00h;
  Epaper_Write_Data(x_end);    // RAM x address end at 0fh(15+1)*8->128
  Epaper_Write_Command(0x45);  // set RAM y address start/end, in page 35
  Epaper_Write_Data(y_start2); // RAM y address start at 0127h;
  Epaper_Write_Data(y_start1); // RAM y address start at 0127h;
  Epaper_Write_Data(y_end2);   // RAM y address end at 00h;
  Epaper_Write_Data(y_end1);

  Epaper_Write_Command(0x4E); // set RAM x address count to 0;
  Epaper_Write_Data(x_startB);
  Epaper_Write_Command(0x4F); // set RAM y address count to 0X127;
  Epaper_Write_Data(y_start2);
  Epaper_Write_Data(y_start1);

  Epaper_Write_Command(0x24); // Write Black and White image to RAM
  for (i = 0; i < PART_COLUMN * PART_LINE / 8; i++)
  {
    Epaper_Write_Data(pgm_read_byte(&datasB[i]));
  }

  // Data C//////////////////////////////////////
  x_startC = x_startC / 8; // Convert to byte
  x_end = x_startC + PART_LINE / 8 - 1;

  y_start1 = 0;
  y_start2 = y_startC - 1;
  if (y_startC >= 256)
  {
    y_start1 = y_start2 / 256;
    y_start2 = y_start2 % 256;
  }
  y_end1 = 0;
  y_end2 = y_startC + PART_COLUMN - 1;
  if (y_end2 >= 256)
  {
    y_end1 = y_end2 / 256;
    y_end2 = y_end2 % 256;
  }

  Epaper_Write_Command(0x44);  // set RAM x address start/end, in page 35
  Epaper_Write_Data(x_startC); // RAM x address start at 00h;
  Epaper_Write_Data(x_end);    // RAM x address end at 0fh(15+1)*8->128
  Epaper_Write_Command(0x45);  // set RAM y address start/end, in page 35
  Epaper_Write_Data(y_start2); // RAM y address start at 0127h;
  Epaper_Write_Data(y_start1); // RAM y address start at 0127h;
  Epaper_Write_Data(y_end2);   // RAM y address end at 00h;
  Epaper_Write_Data(y_end1);

  Epaper_Write_Command(0x4E); // set RAM x address count to 0;
  Epaper_Write_Data(x_startC);
  Epaper_Write_Command(0x4F); // set RAM y address count to 0X127;
  Epaper_Write_Data(y_start2);
  Epaper_Write_Data(y_start1);

  Epaper_Write_Command(0x24); // Write Black and White image to RAM
  for (i = 0; i < PART_COLUMN * PART_LINE / 8; i++)
  {
    Epaper_Write_Data(pgm_read_byte(&datasC[i]));
  }

  // Data D//////////////////////////////////////
  x_startD = x_startD / 8; // Convert to byte
  x_end = x_startD + PART_LINE / 8 - 1;

  y_start1 = 0;
  y_start2 = y_startD - 1;
  if (y_startD >= 256)
  {
    y_start1 = y_start2 / 256;
    y_start2 = y_start2 % 256;
  }
  y_end1 = 0;
  y_end2 = y_startD + PART_COLUMN - 1;
  if (y_end2 >= 256)
  {
    y_end1 = y_end2 / 256;
    y_end2 = y_end2 % 256;
  }

  Epaper_Write_Command(0x44);  // set RAM x address start/end, in page 35
  Epaper_Write_Data(x_startD); // RAM x address start at 00h;
  Epaper_Write_Data(x_end);    // RAM x address end at 0fh(15+1)*8->128
  Epaper_Write_Command(0x45);  // set RAM y address start/end, in page 35
  Epaper_Write_Data(y_start2); // RAM y address start at 0127h;
  Epaper_Write_Data(y_start1); // RAM y address start at 0127h;
  Epaper_Write_Data(y_end2);   // RAM y address end at 00h;
  Epaper_Write_Data(y_end1);

  Epaper_Write_Command(0x4E); // set RAM x address count to 0;
  Epaper_Write_Data(x_startD);
  Epaper_Write_Command(0x4F); // set RAM y address count to 0X127;
  Epaper_Write_Data(y_start2);
  Epaper_Write_Data(y_start1);

  Epaper_Write_Command(0x24); // Write Black and White image to RAM
  for (i = 0; i < PART_COLUMN * PART_LINE / 8; i++)
  {
    Epaper_Write_Data(pgm_read_byte(&datasD[i]));
  }
  // Data E//////////////////////////////////////
  x_startE = x_startE / 8; // Convert to byte
  x_end = x_startE + PART_LINE / 8 - 1;

  y_start1 = 0;
  y_start2 = y_startE - 1;
  if (y_startE >= 256)
  {
    y_start1 = y_start2 / 256;
    y_start2 = y_start2 % 256;
  }
  y_end1 = 0;
  y_end2 = y_startE + PART_COLUMN - 1;
  if (y_end2 >= 256)
  {
    y_end1 = y_end2 / 256;
    y_end2 = y_end2 % 256;
  }

  Epaper_Write_Command(0x44);  // set RAM x address start/end, in page 35
  Epaper_Write_Data(x_startE); // RAM x address start at 00h;
  Epaper_Write_Data(x_end);    // RAM x address end at 0fh(15+1)*8->128
  Epaper_Write_Command(0x45);  // set RAM y address start/end, in page 35
  Epaper_Write_Data(y_start2); // RAM y address start at 0127h;
  Epaper_Write_Data(y_start1); // RAM y address start at 0127h;
  Epaper_Write_Data(y_end2);   // RAM y address end at 00h;
  Epaper_Write_Data(y_end1);

  Epaper_Write_Command(0x4E); // set RAM x address count to 0;
  Epaper_Write_Data(x_startE);
  Epaper_Write_Command(0x4F); // set RAM y address count to 0X127;
  Epaper_Write_Data(y_start2);
  Epaper_Write_Data(y_start1);

  Epaper_Write_Command(0x24); // Write Black and White image to RAM
  for (i = 0; i < PART_COLUMN * PART_LINE / 8; i++)
  {
    Epaper_Write_Data(pgm_read_byte(&datasE[i]));
  }
  EPD_Part_Update();
}

/////////////////////////////////Single display////////////////////////////////////////////////

void EPD_WhiteScreen_Black(void)
{
  unsigned int i;
  Epaper_Write_Command(0x24); // write RAM for black(0)/white (1)
  for (i = 0; i < 5000; i++)
  {
    Epaper_Write_Data(0x00);
  }
  EPD_Update();
}

void EPD_WhiteScreen_White(void)
{
  unsigned int i;
  Epaper_Write_Command(0x24); // write RAM for black(0)/white (1)
  for (i = 0; i < 5000; i++)
  {
    Epaper_Write_Data(0xff);
  }
  EPD_Update();
}

#endif // EPAPER_TOOLS_H