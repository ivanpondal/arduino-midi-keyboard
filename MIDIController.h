#include "Arduino.h"
#include "MIDI.h"
#include "Tools.h"

#ifndef MIDIController_h
#define MIDIController_h

class MIDIController
{
	public:
		static void process(unsigned long val_shiftin, bool* accion);
		static void doAction(int i, bool& action, bool on);
};

#endif
