/*
 * LED.h
 *
 * Created: 18/09/2023 11:12:14 PM
 *  Author: MAI
 */ 


#ifndef LED_H_
#define LED_H_
// Section :INCLUDES
#include "../../MCAL/DIO_DRIVER/DIO.h"
#include "LED_CFG.h"

// Section :Macro Declarations

#define LED_CFG  LED_ENABLE 

//Section :Macro Functions Declarations
//Section :Data type Declarations

//Section : Functions Declarations
#if LED_CFG
std_ReturnType_t LED_INIT(uint8_t pinNum,uint8_t port);
std_ReturnType_t LED_ON(uint8_t pinNum,uint8_t port);
std_ReturnType_t LED_OFF(uint8_t pinNum,uint8_t port);
std_ReturnType_t LED_TOGGLE(uint8_t pinNum,uint8_t port);
#endif
#endif /* LED_H_ */