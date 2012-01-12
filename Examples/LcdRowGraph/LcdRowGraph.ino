#include <LcdRowGraph.h>
#include <LiquidCrystal.h>

//-------------------------------------------------------------------------
// Copyright (C) 2012 Andrew Duncan.
//
// This software may be distributed and modified under the terms of the GNU
// General Public License version 2 (GPL2) as published by the Free Software
// Foundation and appearing in the file GPL2.TXT included in the packaging
// of this file. Please note that GPL2 Section 2[b] requires that all works
// based on this software must also be made publicly available under the
// terms of the GPL2 ("Copyleft").
//
//-------------------------------------------------------------------------

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

