#include <LiquidCrystal_I2C.h>
#include <headers/lcd.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

// initialize LCD
void lcd_init() {
    lcd.init();
    lcd.begin(16, 2);
    lcd.backlight(); // Turn on backlight 
    lcd.print("Loading....");
}

// send data to LCD display
void sendToLCD(const char* v1, const char* v2) {
    lcd.clear(); // Clear the LCD before printing new values

    lcd.setCursor(0, 0);
    lcd.print(v1);

    lcd.setCursor(0, 1);
    lcd.print(v2);
}