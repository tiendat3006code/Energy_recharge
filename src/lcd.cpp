#include "../include/lcd.h"

lcd::lcd() {}

lcd::~lcd() {}

void lcd::lcd_init() {
   m_lcd.begin(16, 2);
   m_lcd.setRGB(COLOR_R, COLOR_G, COLOR_B);
   m_lcd.setCursor(3, 0);
   m_lcd.print("KHOI DONG");
}

void lcd::lcd_display_string(char* str, int x, int y) {
   m_lcd.setCursor(x - 1, y - 1);
   m_lcd.print(str);
}

void lcd::lcd_display_number(float value_1, float value_2, int posX_1, int posY_1, int posX_2, int posY_2) {
   lcd_display_clear(1, 4, posX_1, posY_1);
   lcd_display_clear(1, 5, posX_2, posY_2);
   m_lcd.setCursor(posX_1 - 1, posY_1 - 1);
   m_lcd.print(value_1);
   m_lcd.setCursor(posX_2 - 1, posY_2 - 1);
   m_lcd.print(value_2);
}

void lcd::lcd_display_clear(int start, int end, int x, int y) {
   char str[end - start];
   for (int i = 0; i < (end - start); i++) {
      str[i] = ' ';
   }
   m_lcd.setCursor(x - 1, y - 1);
   m_lcd.print(str);
}

void lcd::lcd_display_clear_all() {
   m_lcd.clear();
}