/*
 * EXT_I_CFG.h
 *
 * Created: 01/10/2023 12:33:59 AM
 *  Author: MAI
 */ 

#include "EXT_I.h"
#ifndef EXT_I_CFG_H_
#define EXT_I_CFG_H_

#define   EXTI_CFG_ENABLE			0x01
#define   EXTI_CFG_DISABLE			0x00

/*EXT INT0 MODE

EXTI_Low_Level                               
EXTI_Any_logical_change                      
EXTI_Falling_Edge                            
EXTI_Rising_Edge

*/
#define  EXTINT0_MODE     EXTI_Rising_Edge
/*EXT INT1 MODE

EXTI_Low_Level
EXTI_Any_logical_change
EXTI_Falling_Edge
EXTI_Rising_Edge

*/
#define  EXTINT1_MODE     EXTI_Low_Level
/*EXT INT2 MODE

EXTI_INT2_Falling_Edge
EXTI_INT2_Rising_Edge

*/
#define  EXTINT2_MODE     EXTI_INT2_Falling_Edge
/*EXT INT initial state

EXTI_Enable
EXTI_Disable

*/
#define  EXTINT0_INIT_STATE    EXTI_Disable
#define  EXTINT1_INIT_STATE    EXTI_Disable
#define  EXTINT2_INIT_STATE    EXTI_Disable

#endif /* EXT_I_CFG_H_ */