#ifndef _EPAPER_TOOLS_H
#define _EPAPER_TOOLS_H

#include <Arduino.h>
#include <SPI.h>

#include "imagesRouter.h"
#include "pinSetting.h"

// EPD
void Epaper_READBUSY(void);
void SPI_Write(unsigned char TxData);
void Epaper_Write_Command(unsigned char cmd);
void Epaper_Write_Data(unsigned char data);

// Electronic paper initialization
void EPD_HW_Init(void);
void EPD_Part_Update(void);
void EPD_Update(void);

void EPD_WhiteScreen_Black(void);
void EPD_WhiteScreen_White(void);
void EPD_DeepSleep(void);

// Display
void EPD_WhiteScreen_ALL(const unsigned char *datas);
void EPD_SetRAMValue_BaseMap(const unsigned char *datas);

void EPD_Dis_Part(unsigned int x_start, unsigned int y_start, const unsigned char *datas, unsigned int PART_COLUMN, unsigned int PART_LINE);

// SPI

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

// EPD settings Functions
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
// All screen update
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
// Part update
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

// Single display

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

#endif // _EPAPER_TOOLS_H