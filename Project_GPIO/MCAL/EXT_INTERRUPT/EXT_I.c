/*
 * EXT_I.c
 *
 * Created: 01/10/2023 12:34:37 AM
 *  Author: MAI
 */ 
#include "EXT_I.h"
#if EXTI_Enable

void (*callbackptr)(void)=NULL;

void EXTI_INIT(void){
	/*CLEAR ALL MODES*/
	CLEAR_func(MCUCR,0);
	CLEAR_func(MCUCR,1);
	CLEAR_func(MCUCR,2);
	CLEAR_func(MCUCR,3);
	
	/* INITIALIZE INTERRUPT MODE*/
#if   EXTINT0_MODE	==	EXTI_Low_Level
	MCUCR|=EXTI_Low_Level;
#elif EXTINT0_MODE	==	EXTI_Any_logical_change
	MCUCR|=EXTI_Any_logical_change;
#elif EXTINT0_MODE	==	EXTI_Falling_Edge
	MCUCR|=EXTI_Falling_Edge;
#elif EXTINT0_MODE	==	EXTI_Rising_Edge
	MCUCR|=EXTI_Rising_Edge;
#endif

#if   EXTINT1_MODE	==	EXTI_Low_Level
	MCUCR |= (EXTI_Low_Level << 2);
#elif EXTINT1_MODE	==	EXTI_Any_logical_change
	MCUCR |=(EXTI_Any_logical_change << 2);
#elif EXTINT1_MODE	==	EXTI_Falling_Edge
	MCUCR |=(EXTI_Falling_Edge << 2);
#elif EXTINT1_MODE	==	EXTI_Rising_Edge
	MCUCR |=(EXTI_Rising_Edge << 2);


#if   EXTINT2_MODE	==	EXTI_INT2_Falling_Edge
	CLEAR_func(MCUCSR,6);
#elif EXTINT2_MODE	==	EXTI_INT2_Rising_Edge
	SET_func(MCUCSR,6);
#endif
		/* INITIALIZE INTERRUPT STATE*/
#if    EXTINT0_INIT_STATE	==	EXTI_Disable
CLEAR_func(GICR,6);
#elif  EXTINT0_INIT_STATE	==	EXTI_Enable
SET_func(GICR,6);
#endif

#if    EXTINT1_INIT_STATE	==	EXTI_Disable
CLEAR_func(GICR,7);
#elif  EXTINT1_INIT_STATE	==	EXTI_Enable
SET_func(GICR,7);
#endif

#if    EXTINT2_INIT_STATE	==	EXTI_Disable
CLEAR_func(GICR,5);
#elif  EXTINT2_INIT_STATE	==	EXTI_Enable
SET_func(GICR,5);
#endif

     /*CLEAR INT FLAG*/
SET_func(GIFR,5);
SET_func(GIFR,6);
SET_func(GIFR,7);
#endif
}

std_ReturnType_t EXTI_ENABLE_INT0(void){
	if(SET_func(GICR,6)) return E_OK;
	else return E_NOT_OK;
}

std_ReturnType_t EXTI_DISABLE_INT0(void){
	if(CLEAR_func(GICR,6))return E_OK;
	else return E_NOT_OK;
}
                           
std_ReturnType_t EXTI_ENABLE_Global_INT(void){
	if(SET_func(SREG,7)) return E_OK;
	else return E_NOT_OK;
}
                           
std_ReturnType_t EXTI_DISABLE_Global_INT(void){
	if(CLEAR_func(SREG,7))return E_OK;
	else return E_NOT_OK;
}


void EXTI_SetCallBack(void(*FuncPtr)(void)){
	callbackptr = FuncPtr;
}
void __vector_1(void)__attribute__((signal,used));
void __vector_1(void){
	if(callbackptr != NULL){
		callbackptr();
	}
}
#endif