#include "Arduino.h"
#include "ShiftInController.h"

ShiftInController::ShiftInController(int latch_pin, int data_pin, int clock_pin)
{
	_latch_pin = latch_pin;
	_data_pin = data_pin;
	_clock_pin = clock_pin;
}

void ShiftInController::setPins()
{
	pinMode(_latch_pin, OUTPUT);
	pinMode(_clock_pin, OUTPUT);
	pinMode(_data_pin, INPUT);
}

void ShiftInController::doLatch()
{
	digitalWrite(_latch_pin, HIGH);
	delayMicroseconds(20);
	digitalWrite(_latch_pin, LOW);
}

unsigned long ShiftInController::getShiftIn()
{
	unsigned long tmp_shiftin=0;
	unsigned long val_shiftin=0;

	for (int i=0; i < 4; i++){
		tmp_shiftin = shiftIn(_data_pin, _clock_pin, LSBFIRST);
		tmp_shiftin=tmp_shiftin<<(8*i);
		val_shiftin+=tmp_shiftin;
	}
	return val_shiftin;
}
