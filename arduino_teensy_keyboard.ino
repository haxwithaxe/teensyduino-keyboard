/* Buttons to USB Keyboard Example

   You must select Keyboard from the "Tools > USB Type" menu
*/

#include "Button.h"
#include "fingers_and_pins.h"
#include "keymap.h"

Button buttons[BUTTON_COUNT];

int key_state[BUTTON_COUNT] = {0};

void setup() {
	/* Configure the pins for input mode with pullup resistors.
	 * The pushbuttons connect from each pin to ground.  When
	 * the button is pressed, the pin reads LOW because the button
	 * shorts it to ground.  When released, the pin reads HIGH
	 * because the pullup resistor connects to +5 volts inside
	 * the chip.  LOW for "on", and HIGH for "off" may seem
	 * backwards, 
	 */
	for(int i=0;i<BUTTON_COUNT;i++)
	{
		buttons[i] = Button(pins[i], fingers[i]);
		pinMode(pins[i], INPUT_PULLUP);
	}
}

void loop() {
	int key_state[BUTTON_COUNT] = {0};
	for(int i=0;i<BUTTON_COUNT;i++)
	{
		/* Update all the buttons.  There should not be any long
		 * delays in loop(), so this runs repetitively at a rate
		 * faster than the buttons could be pressed and released.
		 */
		if (buttons[i].update())
			key_state[buttons[i].finger] = buttons[i].state;
	}

	// handle key_state
	clear_keys();
	int key = keymap_index(key_state);
	if (key > 0) {
		int keycode = keymap_default[key];
		if (keycode > 0) {
			Keyboard.set_modifier(modifier);
			keyboard_keys = keycode;
		}
	}
}

int keymap_index(int keys[BUTTON_COUNT])
{
	int index = 255;
	for(int i=0;i<BUTTON_COUNT;i++)
    {
		 index = index & keys[i]<<i;
	}
	return index;
}

void clear_keys()
{
	Keyboard.set_modifier(0);
	keyboard_keys = {0};
}
