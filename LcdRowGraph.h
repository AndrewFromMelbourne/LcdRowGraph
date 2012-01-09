#ifndef LCD_ROW_GRAPH_H
#define LCD_ROW_GRAPH_H

//-------------------------------------------------------------------------

#include <inttypes.h>

#if defined(ARDUINO) && ARDUINO >= 100
        #include "Arduino.h"
#else
        #include "WProgram.h"
#endif

#include "LiquidCrystal.h"



//-------------------------------------------------------------------------

class LcdRowGraph 
{
private: 

	LiquidCrystal& _lcd;
	int32_t _min;
	int32_t _max;
	uint8_t _row;
	uint8_t _firstColumn;
	uint8_t _columns;
	uint8_t _lastBlock;
	boolean _setup;

	void setup();

public:

	LcdRowGraph(
		LiquidCrystal& lcd,
		int32_t min,
		int32_t max,
		uint8_t row,
		uint8_t firstColumn = 0,
		uint8_t lastColumn = 15);

	void value(int32_t value)
	{
		unscaled(map(value, _min, _max, 0, _columns * 5));
	}

	void unscaled(uint8_t value);

	uint8_t getRow() const { return _row; }

	int32_t getMin() const { return _min; }
	int32_t getMax() const { return _max; }

	void setMinMax(int32_t min, int32_t max) { _min = min; _max = max; }

};

//-------------------------------------------------------------------------

#endif
