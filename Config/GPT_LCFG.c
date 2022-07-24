#include "GPT.h"
#include "ApplicationLogic.h"


extern void Interrupted(void);




const Gpt_ConfigType GptConfigArr[GPT_CFG_CONFIGURED_CHANNELS]=
{
	{GPT_TIMER_A_0_16_32_BIT,16,50,GPT_PRIODIC_TIMER_MODE,Interrupted}
};