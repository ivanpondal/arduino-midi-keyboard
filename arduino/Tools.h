#ifndef Tools_h
#define Tools_h

#include "Arduino.h"

class Tools
{
	public:
		static const int shiftin_brk[];
		static byte getNote(int i);
		static bool isBroken(int i);
};

#endif
