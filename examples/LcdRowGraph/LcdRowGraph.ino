//-------------------------------------------------------------------------
//
// The MIT License (MIT)
//
// Copyright (c) 2014 Andrew Duncan
//
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the
// "Software"), to deal in the Software without restriction, including
// without limitation the rights to use, copy, modify, merge, publish,
// distribute, sublicense, and/or sell copies of the Software, and to
// permit persons to whom the Software is furnished to do so, subject to
// the following conditions:
//
// The above copyright notice and this permission notice shall be included
// in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
// OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
// IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
// CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
// TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
// SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//
//-------------------------------------------------------------------------

#include <LcdRowGraph.h>
#include <LiquidCrystal.h>

//-------------------------------------------------------------------------

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
LcdRowGraph<LiquidCrystal> lcdRowGraph(lcd, 0, 80, 1);

//-------------------------------------------------------------------------

//-------------------------------------------------------------------------

void graph(int32_t min, int32_t max, int32_t step)
{
    lcd.clear();
    lcdRowGraph.setMinMax(min, max);
    
    for (int32_t value = min ; value <= max ; value += step)
    {
        lcd.setCursor(0,0);
        lcd.print(value, DEC);
        lcd.print("/");
        lcd.print(max, DEC);
        lcdRowGraph.value(value);
        delay(50);
    }
}

//-------------------------------------------------------------------------

void setup() 
{
    lcd.begin(16, 2);
}

//-------------------------------------------------------------------------

void loop()
{
    graph(0, 16, 1);
    graph(0, 40, 1);
    graph(0, 80, 1);
    graph(0, 100, 1);
}

