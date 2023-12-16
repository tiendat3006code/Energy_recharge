#include "../include/lcd.h"

lcd::lcd() : m_lcd(LCD_ADDRESS, 16, 2) {}

lcd::~lcd() {}

void lcd::lcd_init() {
   m_lcd.init();
   m_lcd.backlight();
   m_lcd.setCursor(3, 0);
   m_lcd.print("KHOI DONG");
}

void lcd::lcd_display_string(char* str, int x, int y) {
   m_lcd.setCursor(x - 1, y - 1);
   m_lcd.print(str);
}

void lcd::lcd_display_number(float value, int x, int y) {
   m_lcd.setCursor(x - 1, y + 1);
   m_lcd.print(value);
}

void lcd::lcd_display_clear(int start, int end, int x, int y) {
   m_lcd.setCursor(x - 1, y - 1);
   char str[end - start];
   for (int i = 0; i < (end - start); i++) {
      str[i] = ' ';
   }
   m_lcd.print(str);
}

void lcd::lcd_display_clear_all() {
   m_lcd.clear();
}