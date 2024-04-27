/*
 * button.c
 *
 * Created: 19/09/2023 12:18:41 AM
 *  Author: MAI
 */ 
#include "button.h"
#if BUTTON_CFG 
std_ReturnType_t BUTTON_INIT(uint8_t pinNum,uint8_t port){
	if(DIO_DIRECTION_INIT(pinNum,port,DIO_INPUT)){return E_OK;}
	else{return E_NOT_OK;}
}
std_ReturnType_t BUTTON_READ(uint8_t pinNum,uint8_t port,btn_logic logic_t,btn_state *state){
	
	BUTTON_INIT(pinNum,port);
	uint8_t button_value=DIO_READ(pinNum,port,&state);
	if((logic_t==B_LOW && button_value==DIO_LOW)||(logic_t==B_HIGH && button_value==DIO_HIGH)){
		*state=BTN_PREASED;
		return E_OK;
		}
	else{
	*state=BTN_RELEASED;
	return E_NOT_OK;}
	
	}
#endif