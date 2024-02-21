#ifndef LCD_H
#define LCD_H

#include <LiquidCrystal_I2C.h>

void lcd_init();
void sendToLCD(const char* v1 = "", const char* v2 = "");

#endif