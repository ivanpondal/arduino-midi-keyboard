#include "Arduino.h"

#ifndef ShiftInController_h
#define ShiftInController_h

class ShiftInController
{
	public:
		ShiftInController(int latch_pin, int data_pin, int clock_pin);
		void setPins();
		void doLatch();
		unsigned long getShiftIn();
	private:
		int _latch_pin, _data_pin, _clock_pin;
};

#endif
