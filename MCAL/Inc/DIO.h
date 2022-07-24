/**********************************************************************************************************
*
*	File name: 		DIO.h
*
*	Author: 			Aly Mohamed Maamoun
*	
*	Date:		  		15/7/2022
*	
*	Description:	Header file for DIO module	
*
***********************************************************************************************************/


#ifndef PORT_h
#define PORT_h

/*Includes*/

#include "Std_Types.h"
#include "tm4c123gh6pm_registers.h"
#include "Common_Macros.h"
#include "DIO_Def.h"





/**********************************************************************************************************
*								  													MODULE DATATYPES																							*
**********************************************************************************************************/
typedef uint8 Dio_ChannelType		;
typedef uint8 Dio_PortType			;
typedef uint8 Dio_PortLevelType	;

typedef enum
{
	LOW,HIGH
}Dio_LevelType;


/**********************************************************************************************************
*																						MODULE FUNCTIONS PROTOTYPE																		*
**********************************************************************************************************/

/************************************************************************************
* Service Name: Dio_ReadChannel
* Parameters (in): ChannelId - Channel number
* Parameters (inout): None
* Parameters (out): None
* Return value: Low or High
* Description: Read the value of specific pin
************************************************************************************/
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId);


/************************************************************************************
* Service Name: Dio_WriteChannel
* Parameters (in): ChannelId - Channel number , level- high or low
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Writing value on pin
************************************************************************************/
void Dio_WriteChannel(Dio_ChannelType ChannelId,Dio_LevelType level);


/************************************************************************************
* Service Name: Dio_ReadPort
* Parameters (in): PortId - port number
* Parameters (inout): None
* Parameters (out): None
* Return value: Dio_PortLevelType 0-255
* Description: Reading the value of specific port
************************************************************************************/
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId);


/************************************************************************************
* Service Name: Dio_WritePort
* Parameters (in): PortId - port number , level - 0->255
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Writing value on specific port
************************************************************************************/
void Dio_WritePort(Dio_PortType PortId,Dio_PortLevelType level);


/************************************************************************************
* Service Name: Dio_FlipChannel
* Parameters (in): ChannelId - Channel number
* Parameters (inout): None
* Parameters (out): None
* Return value: High or Low
* Description: flipping value of specific pin and returning the new value 
************************************************************************************/
Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId);



#endif 

