#include "ApplicationLogic.h"

static boolean LedState=FALSE;

void AppDriversInit(void)
{
	Port_Init(&Port_config);
	
	Gpt_Init(&GptConfigArr);
	Gpt_EnableNotification(GPT_TIMER_A_0_16_32_BIT);
	Gpt_StartTimer(GPT_TIMER_A_0_16_32_BIT,62500);
	NVIC_init();
}

void Interrupted(void)
{
	LocSeconds++;
}

void AppLogic(void)
{
	if(LedState)
	{
		if(LocSeconds>=APPLICATION_LOGIC_CFG_ON_TIME)
		{
			LED_OFF(LED_RED);
			LocSeconds=0;
			LedState=FALSE;
		}
	}
	else
	{
		if(LocSeconds>=APPLICATION_LOGIC_CFG_OFF_TIME)
		{
			LED_ON(LED_RED);
			LocSeconds=0;
			LedState=TRUE;
		}
	}
	
}