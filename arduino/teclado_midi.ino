#include "MIDI.h"
#include "ShiftInController.h"
#include "MIDIController.h"

unsigned long val_shiftin=0;

bool action[32]={false};

ShiftInController shiftincon(4,2,3);

void setup()
{
	shiftincon.setPins();
	MIDI.begin();
}

void loop()
{
	shiftincon.doLatch();
	val_shiftin=shiftincon.getShiftIn();
	MIDIController::process(val_shiftin, action);
}
