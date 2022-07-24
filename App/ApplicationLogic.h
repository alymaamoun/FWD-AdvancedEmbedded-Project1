#ifndef APPLICATION_LOGIC_H
#define APPLICATION_LOGIC_H

#include "PORT.h"
#include "GPT.h"
#include "Leds.h"
#include "NVIC.h"
#include "ApplicationLogic_CFG.h"
static uint8 LocSeconds;

void AppDriversInit(void);
void AppLogic(void);
void Interrupted(void);


#endif