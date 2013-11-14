#ifndef BUTTON_h
#define BUTTON_h

#include <Bounce.h>

#define DEBOUNCE_MS 10

#define DOWN 0
#define UP 1

class Button
{
    public:
        int pin;
        int finger;
        int state;
        Bounce bnc;
		Button();
        Button(int,int);
		void init(int,int);
        bool update();
        int read();
        void write(int);
        unsigned long duration();
};

#endif
