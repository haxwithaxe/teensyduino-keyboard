#include "keypress.h"

KeyPress::Keypress()
{
	init(0, {0}, 0);
}
KeyPress::KeyPress(int hsh, int cds[6], int mds)
{
	init(hsh, cds, mds);
}
void KeyPress::init(int hsh, int cds[6], int mds)
{
	hash = hsh;
	codes = cds;
	mods = mds;
}
