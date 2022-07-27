#include "Leds.h"

void LED_ON(LedID ID)
{
	switch(ID)
	{
		case LED_RED	: Dio_WriteChannel(DIO_def_PortF_Pin1_Index,LOGIC_HIGH); break;
		case LED_BLUE	: Dio_WriteChannel(DIO_def_PortF_Pin2_Index,LOGIC_HIGH); break;
		case LED_GREEN: Dio_WriteChannel(DIO_def_PortF_Pin3_Index,LOGIC_HIGH); break;
	}
	
}
void LED_OFF	(LedID ID)
{
		switch(ID)
	{
		case LED_RED	: Dio_WriteChannel(DIO_def_PortF_Pin1_Index,LOGIC_LOW); break;
		case LED_BLUE	: Dio_WriteChannel(DIO_def_PortF_Pin2_Index,LOGIC_LOW); break;
		case LED_GREEN: Dio_WriteChannel(DIO_def_PortF_Pin3_Index,LOGIC_LOW); break;
	}
	
}
