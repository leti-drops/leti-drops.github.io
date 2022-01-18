#include <lcd_lib.h>

avrlib::LCD lcd(37, 35, AVR_PORTA);

void setup()
{
    lcd.begin();
}

void loop()
{
    lcd.print("Hello World!");
    lcd.setCursor(0, 0);
}
