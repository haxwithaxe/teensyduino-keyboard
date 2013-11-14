#ifndef KEYPRESS_h
#define KEYPRESS_h

class KeyPress
{
	KeyPress();
	KeyPress(int, int*, int);
	init(int, int*, int);
	int hash;
	int* codes;
	int mods;
};

#endif
