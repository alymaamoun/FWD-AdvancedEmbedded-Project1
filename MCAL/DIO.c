/**********************************************************************************************************
*
*	File name: 		DIO.c
*
*	Author: 			Aly Mohamed Maamoun
*	
*	Date:		  		17/7/2022
*	
*	Description:	Source file for DIO module	
*
***********************************************************************************************************/

#include "DIO.h"

	int Port;
	int Pin;

void PinPortGetter(Dio_ChannelType ChannelId, int* Port ,  int* Pin)
{
	if(ChannelId<0x08)
	{
		*Port=DIO_def_PORTA;
		*Pin=ChannelId;
	}
	else if(ChannelId>=0x08 && ChannelId<0x10)
	{
		*Port=DIO_def_PORTB;
		*Pin=ChannelId-8;
	}
	else if(ChannelId>=0x10 && ChannelId<0x18)
	{
		*Port=DIO_def_PORTC;
		*Pin=ChannelId-2*8;
	}
	else if(ChannelId>=0x18 && ChannelId<0x20)
	{
		*Port=DIO_def_PORTD;
		*Pin=ChannelId-3*8;
	}
	else if(ChannelId>=0x20 && ChannelId<0x26)
	{
		*Port=DIO_def_PORTE;
		*Pin=ChannelId-4*8;
	}
	else if(ChannelId>=0x26 && ChannelId<=0x2A)
	{
		*Port=DIO_def_PORTF;
		*Pin=ChannelId-4*8-6;
	}
}

Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{
	PinPortGetter(ChannelId,&Port,&Pin);
	
	switch(Port)
	{
		case DIO_def_PORTA:
			if(BIT_IS_SET(GPIO_PORTA_DATA_REG,Pin))
			{
				return HIGH;
			}
			else
			{
				return LOW;
			}
		case DIO_def_PORTB:
			if(BIT_IS_SET(GPIO_PORTB_DATA_REG,Pin))
			{
				return HIGH;
			}
			else
			{
				return LOW;
			}
		case DIO_def_PORTC:
			if(BIT_IS_SET(GPIO_PORTC_DATA_REG,Pin))
			{
				return HIGH;
			}
			else
			{
				return LOW;
			}
		case DIO_def_PORTD:
			if(BIT_IS_SET(GPIO_PORTD_DATA_REG,Pin))
			{
				return HIGH;
			}
			else
			{
				return LOW;
			}
		case DIO_def_PORTE:
			if(BIT_IS_SET(GPIO_PORTE_DATA_REG,Pin))
			{
				return HIGH;
			}
			else
			{
				return LOW;
			}
		case DIO_def_PORTF:
			if(BIT_IS_SET(GPIO_PORTF_DATA_REG,Pin))
			{
				return HIGH;
			}
			else
			{
				return LOW;
			}

	}
	return LOW;
}



void Dio_WriteChannel(Dio_ChannelType ChannelId,Dio_LevelType level)
{
	PinPortGetter(ChannelId,&Port,&Pin);
	switch(Port)
	{
		case DIO_def_PORTA:
			if(level)
			{
				SET_BIT(GPIO_PORTA_DATA_REG,Pin)	;
			}
			else
			{
				CLEAR_BIT(GPIO_PORTA_DATA_REG,Pin);
			}
			break;
		case DIO_def_PORTB:
			if(level)
			{
				SET_BIT(GPIO_PORTB_DATA_REG,Pin)	;
			}
			else
			{
				CLEAR_BIT(GPIO_PORTB_DATA_REG,Pin);
			}
			break;
		case DIO_def_PORTC:
			if(level)
			{
				SET_BIT(GPIO_PORTC_DATA_REG,Pin)	;
			}
			else
			{
				CLEAR_BIT(GPIO_PORTC_DATA_REG,Pin);
			}
			break;	
		case DIO_def_PORTD:
			if(level)
			{
				SET_BIT(GPIO_PORTD_DATA_REG,Pin)	;
			}
			else
			{
				CLEAR_BIT(GPIO_PORTD_DATA_REG,Pin);
			}
			break;			
		case DIO_def_PORTE:
			if(level)
			{
				SET_BIT(GPIO_PORTE_DATA_REG,Pin)	;
			}
			else
			{
				CLEAR_BIT(GPIO_PORTE_DATA_REG,Pin);
			}
			break;
		case DIO_def_PORTF:
			if(level)
			{
				SET_BIT(GPIO_PORTF_DATA_REG,Pin)	;
			}
			else
			{
				CLEAR_BIT(GPIO_PORTF_DATA_REG,Pin);
			}
			break;
	}
	
}


Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId)
{
	uint8 Data=0;
	switch(PortId)
	{
		case DIO_def_PORTA:
			Data =(uint8)GPIO_PORTA_DATA_REG;
			break;
		case DIO_def_PORTB:
			Data =(uint8)GPIO_PORTB_DATA_REG;
			break;
		case DIO_def_PORTC:
			Data =(uint8)GPIO_PORTC_DATA_REG;
			break;
		case DIO_def_PORTD:
			Data =(uint8)GPIO_PORTD_DATA_REG;
			break;
		case DIO_def_PORTE:
			Data =(uint8)GPIO_PORTE_DATA_REG;
			break;
		case DIO_def_PORTF:
			Data =(uint8)GPIO_PORTF_DATA_REG;
			break;		
	}
	return Data;
	
	
}


void Dio_WritePort(Dio_PortType PortId,Dio_PortLevelType level)
{
		switch(PortId)
	{
		case DIO_def_PORTA:
			GPIO_PORTA_DATA_REG=level;
			break;
		case DIO_def_PORTB:
			GPIO_PORTB_DATA_REG=level;
			break;
		case DIO_def_PORTC:
			GPIO_PORTC_DATA_REG=level;
			break;
		case DIO_def_PORTD:
			GPIO_PORTD_DATA_REG=level;
			break;
		case DIO_def_PORTE:
			GPIO_PORTE_DATA_REG=level;
			break;
		case DIO_def_PORTF:
			GPIO_PORTF_DATA_REG=level;
			break;		
	}
}


Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId)
{
	PinPortGetter(ChannelId , &Port , &Pin);
	switch(Port)
	{
		case DIO_def_PORTA:
			TOGGLE_BIT(GPIO_PORTA_DATA_REG,Pin);
			if(BIT_IS_SET(GPIO_PORTA_DATA_REG,Pin))
			{
				return HIGH;
			}
			else
			{
				return LOW;
			}
		case DIO_def_PORTB:
			TOGGLE_BIT(GPIO_PORTB_DATA_REG,Pin);
			if(BIT_IS_SET(GPIO_PORTB_DATA_REG,Pin))
			{
				return HIGH;
			}
			else
			{
				return LOW;
			}
		case DIO_def_PORTC:
			TOGGLE_BIT(GPIO_PORTC_DATA_REG,Pin);
			if(BIT_IS_SET(GPIO_PORTC_DATA_REG,Pin))
			{
				return HIGH;
			}
			else
			{
				return LOW;
			}
		case DIO_def_PORTD:
			TOGGLE_BIT(GPIO_PORTD_DATA_REG,Pin);
			if(BIT_IS_SET(GPIO_PORTD_DATA_REG,Pin))
			{
				return HIGH;
			}
			else
			{
				return LOW;
			}
		case DIO_def_PORTE:
			TOGGLE_BIT(GPIO_PORTE_DATA_REG,Pin);
			if(BIT_IS_SET(GPIO_PORTE_DATA_REG,Pin))
			{
				return HIGH;
			}
			else
			{
				return LOW;
			}
		case DIO_def_PORTF:
			TOGGLE_BIT(GPIO_PORTF_DATA_REG,Pin);
			if(BIT_IS_SET(GPIO_PORTF_DATA_REG,Pin))
			{
				return HIGH;
			}
			else
			{
				return LOW;
			}

	}
	return LOW;
}	
	
