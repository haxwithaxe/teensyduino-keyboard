#include "Button.h"

#ifndef DEBOUNCE_MS
#define DEBOUNCE_MS 10
#endif

Button::Button()
{
	init(0,0);
}

void Button::Button(int pn, int fngr)
{
	init(pn, fngr);
}

/* Create Bounce objects for each button.  The Bounce object
 * automatically deals with contact chatter or "bounce", and
 * it makes detecting changes very simple.
 * 10 = 10 ms debounce time
 * which is appropriate for
 * most mechanical pushbuttons
 * if a button is too "sensitive"
 * to rapid touch, you can
 * increase this time.
 */
void Button::init(int pn, int fngr)
{
    pin = pn;
    finger = fngr;
    bnc = Bounce(pin, DEBOUNCE_MS);
}

bool Button::update()
{
	int changed = bnc.update();
	if (changed > 0)
		state = (state==UP)?DOWN:UP;
	return (changed > 0)
}

int Button::read()
{
	return bnc.read();
}

void Button::write(int val)
{
	bnc.write(val);
}

unsigned long Button::duration()
{
	return bnc.duration()
}

