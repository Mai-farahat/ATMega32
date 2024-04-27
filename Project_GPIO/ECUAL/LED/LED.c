/*
 * LED.c
 *
 * Created: 18/09/2023 11:12:37 PM
 *  Author: MAI
 */ 
#include "LED.h"
#if LED_CFG
std_ReturnType_t LED_INIT(uint8_t pinNum,uint8_t port){
	if(DIO_DIRECTION_INIT(pinNum,port,DIO_OUTPUT)){return E_OK;}
	else{return E_NOT_OK;}
	}
std_ReturnType_t LED_ON(uint8_t pinNum,uint8_t port){
	LED_INIT(pinNum,port);
	if(DIO_WRITE(pinNum,port,DIO_HIGH)){return E_OK;}
	else{return E_NOT_OK;}
	}
std_ReturnType_t LED_OFF(uint8_t pinNum,uint8_t port){
	LED_INIT(pinNum,port);
	if(DIO_WRITE(pinNum,port,DIO_LOW)){return E_OK;}
	else{return E_NOT_OK;}
}
std_ReturnType_t LED_TOGGLE(uint8_t pinNum,uint8_t port){
	LED_INIT(pinNum,port);
	if(DIO_TOGGLE(pinNum,port)){return E_OK;}
	else{return E_NOT_OK;}
}
#endif