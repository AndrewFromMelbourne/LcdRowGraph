#include "LcdRowGraph.h"

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

LcdRowGraph:: LcdRowGraph(
	LiquidCrystal& lcd,
	int32_t min,
	int32_t max,
	uint8_t row,
	uint8_t firstColumn,
	uint8_t lastColumn)
:
	_lcd(lcd),
	_min(min),
	_max(max),
	_row(row),
	_firstColumn(firstColumn),
	_columns(lastColumn - firstColumn + 1),
	_lastBlock(0),
	_setup(false)
{
}


//-------------------------------------------------------------------------

void
LcdRowGraph:: setup()
{
	for (uint8_t letter = 0 ; letter < 5 ; ++letter)
	{
		byte pixelRow = 0;

		for (int16_t bit = 5 ; bit > 4 - letter ; --bit)
		{
			bitSet(pixelRow, bit-1);
		}

		byte pixels[8];

		for (uint8_t i = 0 ; i < 8 ; ++i)
		{
			pixels[i] = pixelRow;
		}

		_lcd.createChar(letter, pixels);
	}

	_setup = true;
}

//-------------------------------------------------------------------------

void
LcdRowGraph:: unscaled(
	uint8_t value)
{
	if (not _setup)
	{
		setup();
	}

	uint8_t letters = value / 5;
	uint8_t bar = value % 5;
	uint8_t letter = min(letters, _lastBlock);

	_lcd.setCursor(letter + _firstColumn, _row);

	for ( ; letter < letters ; ++letter)
	{
		_lcd.write((uint8_t)4);
	}

	_lastBlock = letter;

    if (bar)
	{
	    ++letter;
		_lcd.write(bar-1);
	}

	for ( ; letter < _columns ; ++letter)
	{
		_lcd.print(" ");
	}
}
