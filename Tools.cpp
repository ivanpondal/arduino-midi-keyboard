#include "Arduino.h"
#include "Tools.h"

const int Tools::shiftin_brk[]={};

byte Tools::getNote(int i)
{
	byte note;
	switch(i)
	{
		case 0:
			note=22;
			break;
		case 1:
			note=26;
			break;
		case 2:
			note=25;
			break;
		case 3:
			note=24;
			break;
		case 4:
			note=20;
			break;
		case 5:
			note=23;
			break;
		case 6:
			note=0;
			break;
		case 7:
			note=0;
			break;
		case 8:
			note=19;
			break;
		case 9:
			note=0;
			break;
		case 10:
			note=26;
			break;
		case 11:
			note=18;
			break;
		case 12:
			note=0;
			break;
		case 13:
			note=17;
			break;
		case 14:
			note=16;
			break;
		case 15:
			note=13;
			break;
		case 16:
			note=14;
			break;
		case 17:
			note=15;
			break;
		case 18:
			note=10;
			break;
		case 19:
			note=12;
			break;
		case 20:
			note=9;
			break;
		case 21:
			note=11;
			break;
		case 22:
			note=8;
			break;
		case 23:
			note=1;
			break;
		case 24:
			note=6;
			break;
		case 25:
			note=5;
			break;
		case 26:
			note=7;
			break;
		case 27:
			note=0;
			break;
		case 28:
			note=2;
			break;
		case 29:
			note=4;
			break;
		case 30:
			note=3;
			break;
		case 31:
			note=0;
			break;
	}
	return note;
}

bool Tools::isBroken(int i)
{
	bool found=false;
	int n=0;
	int length=0;
	length=sizeof(shiftin_brk)/2;

	while(!found && n<length)
	{
		if(shiftin_brk[n]==i)
		{
			found=true;
		}
		n++;
	}
	return found;
}
