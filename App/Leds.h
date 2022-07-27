#ifndef LEDS_H
#define LEDS_H

#include "DIO.h"


#define LED_RED 	1
#define LED_BLUE	2
#define LED_GREEN	3

typedef uint8 LedID;

void LED_ON		(LedID ID);
void LED_OFF	(LedID ID);

#endif