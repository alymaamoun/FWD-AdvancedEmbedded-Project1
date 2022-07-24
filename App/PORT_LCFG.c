#include "PORT.h"



const Port_ConfigType Port_config[PORT_CONFIGURED_CHANNELS] ={
	PORT_def_PORTF,	PORT_def_Pin0,INPUT		,	Port_def_Mode_DIO		,	OFF	,	_4MA,LOW	,
	PORT_def_PORTF,	PORT_def_Pin1,OUTPUT	,	Port_def_Mode_DIO		,	OFF	,	_4MA,LOW	,
	PORT_def_PORTF,	PORT_def_Pin2,OUTPUT	,	Port_def_Mode_DIO		,	OFF	,	_4MA,LOW	,
	PORT_def_PORTF,	PORT_def_Pin3,OUTPUT	,	Port_def_Mode_CAN		,	OFF	,	_4MA,HIGH	,
	PORT_def_PORTF,	PORT_def_Pin4,INPUT		,	Port_def_Mode_ADC		,	OFF	,	_4MA,LOW	,
	PORT_def_PORTB,	PORT_def_Pin6,OUTPUT	, Port_def_Mode_TIMER	,	OFF	,	_4MA,LOW	,

};