#ifndef _PAGES_H
#define _PAGES_H

#include "ePaperTools.h"
#include "imagesRouter.h"
#include "pinSetting.h"

struct Coordinates
{
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
                        unsigned int PART_COLUMN, unsigned int PART_LINE);

void writeReset();

void writeBlack(unsigned int x_start, unsigned int x_end,
                unsigned int y_start1, unsigned int y_end1,
                unsigned int y_start2, unsigned int y_end2,
                const unsigned char *datas, unsigned int PART_COLUMN, unsigned int PART_LINE);

void writeImage(int x, int y, unsigned int column, unsigned int line, const unsigned char *image);

void writeNumber(unsigned int x_start, unsigned int x_end, unsigned int number);

void displayNumber(unsigned int x_startA, unsigned int y_startA, const unsigned char *datasA,
                   unsigned int x_startB, unsigned int y_startB, const unsigned char *datasB,
                   unsigned int PART_COLUMN, unsigned int PART_LINE);

void displayWatchMode(unsigned int inputNumber);

void displayBikeMode(unsigned int inputNumber);

// Function

Coordinates transformXY(unsigned int x_start, unsigned int y_start,
                        unsigned int PART_COLUMN, unsigned int PART_LINE)
{
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

void writeReset()
{
  // Reset
  EPD_W21_RST_0; // Module reset
  delay(10);     // At least 10ms delay
  EPD_W21_RST_1;
  delay(10); // At least 10ms delay

  Epaper_Write_Command(0x3C); // BorderWavefrom
  Epaper_Write_Data(0x80);
}

void writeBlack(unsigned int x_start, unsigned int x_end,
                unsigned int y_start1, unsigned int y_end1,
                unsigned int y_start2, unsigned int y_end2,
                const unsigned char *datas, unsigned int PART_COLUMN, unsigned int PART_LINE)
{
  Epaper_Write_Command(0x44);  // set RAM x address start/end, in page 35
  Epaper_Write_Data(x_start);  // RAM x address start at 00h;
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

void writeImage(int x, int y, unsigned int height, unsigned int width, const unsigned char *image)
{
  Coordinates tramXY = transformXY(x, y, height, width);
  writeBlack(tramXY.x_start, tramXY.x_end, tramXY.y_start1, tramXY.y_end1,
             tramXY.y_start2, tramXY.y_end2, image, height, width);
}

void writeNumber(unsigned int x_start, unsigned int y_start, unsigned int inputNumber)
{
  Coordinates tramXY;
  unsigned int tens = inputNumber / 10;
  unsigned int ones = inputNumber % 10;
  // 個位數
  tramXY = transformXY(x_start + 32, y_start, 64, 32);
  writeBlack(tramXY.x_start, tramXY.x_end, tramXY.y_start1, tramXY.y_end1, tramXY.y_start2, tramXY.y_end2, number[ones], 64, 32);
  // 十位數
  tramXY = transformXY(x_start, y_start, 64, 32);
  writeBlack(tramXY.x_start, tramXY.x_end, tramXY.y_start1, tramXY.y_end1, tramXY.y_start2, tramXY.y_end2, number[tens], 64, 32);
}

void displayNumber(unsigned int x_startA, unsigned int y_startA, const unsigned char *datasA,
                   unsigned int x_startB, unsigned int y_startB, const unsigned char *datasB,
                   unsigned int PART_COLUMN, unsigned int PART_LINE)
{
  writeReset();
  // 個位數
  Coordinates tramXY = transformXY(x_startA, y_startA, PART_COLUMN, PART_LINE);
  writeBlack(tramXY.x_start, tramXY.x_end, tramXY.y_start1, tramXY.y_end1, tramXY.y_start2, tramXY.y_end2, datasA, PART_COLUMN, PART_LINE);
  // 十位數
  tramXY = transformXY(x_startB, y_startB, PART_COLUMN, PART_LINE);
  writeBlack(tramXY.x_start, tramXY.x_end, tramXY.y_start1, tramXY.y_end1, tramXY.y_start2, tramXY.y_end2, datasB, PART_COLUMN, PART_LINE);
  EPD_Part_Update();
}

void displayWatchMode(unsigned int inputNumber)
{
  writeReset();

  // 左上角鎖
  if (true)
  {
    writeImage(0, 40, 40, 40, lock);
  }
  else
  {
    writeImage(0, 40, 40, 40, unlock);
  }

  if (true)
  {
    // 電池
    writeImage(160, 40, 40, 40, watch_battery[0]);
    // 電力警告
    writeImage(136, 32, 24, 24, watch_battery_warning);
  }

  if (false)
  {
    // 腳踏車 Bibi
    writeImage(48, 176, 104, 104, big_bike);
    // 左訊號
    writeImage(135, 112, 48, 48, right_single);
    // 右訊號
    writeImage(25, 112, 48, 48, left_single);
  }

  if (true)
  {
    // 尋車
    writeImage(32, 151, 104, 136, distance);
    // 距離單位
    writeImage(135, 200, 40, 24, m);
    // 數值顯示
    writeNumber(60, 210, inputNumber);
  }
  else
  {
    // 無訊號
    writeImage(24, 191, 152, 152, no_signal);
  }

  // 更新畫面
  EPD_Part_Update();
}

void displayBikeMode(unsigned int inputNumber)
{
  writeReset();
  // 左上腳踏車
  writeImage(0, 40, 48, 48, small_bike);

  if (true)
  {
    // 電池
    writeImage(0, 200, 32, 152, bike_battery[0]);
    // 電力警告
    writeImage(160, 200, 32, 32, bike_battery_warning);
  }

  if (false)
  {
    // 自動輔助力模式
    writeImage(140, 100, 48, 48, assist_mode_auto);
  }
  else
  {
    // 正常輔助力模式
    writeImage(140, 100, 48, 48, assist_mode_normal);
  }

  if (true)
  {
    // 速度icon
    writeImage(12, 140, 80, 80, speed_icon[4]);
  }
  // 距離單位
  writeImage(130, 150, 24, 48, km_h);
  // 數值顯示
  writeNumber(65, 155, inputNumber);

  // 更新畫面
  EPD_Part_Update();
}


#endif // _PAGES_H