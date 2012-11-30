#include "Arduino.h"
#include "MIDI.h"
#include "Tools.h"
#include "MIDIController.h"

void MIDIController::process(unsigned long val_shiftin, bool* accion)
{
	byte note=0;
	unsigned long mask=00000000000000000000000000000001;
	for(int i=0;i<32;i++)
	{
		note=Tools::getNote(i);
		if(val_shiftin & mask)
		{
			MIDIController::doAction(note, accion[note], true);
		}
		else
		{
			MIDIController::doAction(note, accion[note], false);
		}
		mask<<=1;
	}
}

void MIDIController::doAction(int note, bool& action, bool on)
{
	byte vel=80;
	byte channel=1;
	byte offset=53;
	note+=offset;
	if(on)
	{
		if(!action)
		{
			MIDI.sendNoteOn(note, vel, channel);
			action=true;
		}
	}
	else
	{
		if(action)
		{
			MIDI.sendNoteOff(note, 0, channel);
			action=false;
		}
	}
}
