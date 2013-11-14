#ifndef FINGERS_AND_PINS_h
#define FINGERS_AND_PINS_h

// BUTTON_COUNT == number of button pins == number of "fingers"
#define BUTTON_COUNT 7

// fingers/buttons (0-(BUTTON_COUNT-1))
#define THUMB_CENTER 0
#define THUMB_FORE 1
#define THUMB_AFT 2
#define INDEX 3 
#define MIDDLE 4
#define RING 5
#define PINKY 6

// pins
#define THUMB_CENTER_PIN 0
#define THUMB_FORE_PIN 1
#define THUMB_AFT_PIN 2
#define INDEX_PIN 3
#define MIDDLE_PIN 4
#define RING_PIN 5
#define PINKY_PIN 6

int pins[BUTTON_COUNT] = {THUMB_CENTER_PIN, THUMB_FORE_PIN, THUMB_AFT_PIN, INDEX_PIN, MIDDLE_PIN, RING_PIN, PINKY_PIN};
int fingers[BUTTON_COUNT] = {THUMB_CENTER, THUMB_FORE, THUMB_AFT, INDEX, MIDDLE, RING, PINKY};

//END #ifndef FINGERS_AND_PINS_h
#endif
