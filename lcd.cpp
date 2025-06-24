#include "lcd.h"

#include <Wire.h>
#include "rgb_lcd.h"

#include "config.h"

rgb_lcd lcd;

void LCD::lcd_setup() {
    lcd.begin(LCD_ROWS, LCD_COLS);
}

void LCD::lcd_display(String to_display, int col) {
    // Add trailing spaces if the string is shorter than the LCD_COLS
    while (to_display.length() < LCD_ROWS) {
      to_display += " ";
    }

    lcd.setCursor(0, col);
    debug.println(to_display);
    lcd.print(to_display);
    lcd.display();
}
