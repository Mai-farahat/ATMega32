/*
 * button.h
 *
 * Created: 19/09/2023 12:18:59 AM
 *  Author: MAI
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_
// Section :INCLUDES
#include "../../MCAL/DIO_DRIVER/DIO.h"
#include "button_cfg.h"
// Section :Macro Declarations
#define BUTTON_CFG     BUTTON_ENABLE
//Section :Macro Functions Declarations
//Section :Data type Declarations
typedef enum{
	BTN_PREASED,
	BTN_RELEASED
	}btn_state;
	
typedef enum{
	B_LOW,
	B_HIGH
	}btn_logic;
//Section : Functions Declarations
#if BUTTON_CFG 
std_ReturnType_t BUTTON_INIT(uint8_t pinNum,uint8_t port);
std_ReturnType_t BUTTON_READ(uint8_t pinNum,uint8_t port,btn_logic logic_t,btn_state *state);

#endif
#endif /* BUTTON_H_ */