#include <LcdRowGraph.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
LcdRowGraph lcdRowGraph(lcd, 0, 80, 1);

void graph(int32_t min, int32_t max, int32_t step)
{
    lcd.clear();
    lcdRowGraph.setMinMax(min, max);
    
    for (int32_t value = min ; value != max ; value += step)
    {
        lcd.setCursor(0,0);
        lcd.print(value, DEC);
        lcd.print("/");
        lcd.print(max, DEC);
        lcdRowGraph.value(value);
        delay(50);
    }
}

void setup() 
{
    lcd.begin(16, 2);
}

void loop()
{
    graph(0, 16, 1);
    graph(0, 40, 1);
    graph(0, 80, 1);
    graph(0, 100, 1);
}

