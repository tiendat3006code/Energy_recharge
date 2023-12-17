#ifndef LCD_H
#define LCD_H

#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include "loadcell.h"
#include "config.h"

class lcd 
{
private:
    /* data */
    LiquidCrystal_I2C m_lcd;
public:
    lcd(/* args */);
    ~lcd();
    void lcd_init();
    void lcd_display_string(char* str, int x, int y);
    void lcd_display_number(float value_1, float value_2, int posX_1, int posY_1, int posX_2, int posY_2);
    void lcd_display_clear(int start, int end, int x, int y);
    void lcd_display_clear_all();
};

#endif //LCD_H

