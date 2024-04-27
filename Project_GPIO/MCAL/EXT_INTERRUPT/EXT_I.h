/*
 * EXT_I.h
 *
 * Created: 01/10/2023 12:33:26 AM
 *  Author: MAI
 */ 


#ifndef EXT_I_H_
#define EXT_I_H_
// Section :INCLUDES
#include "../../MCAL/DIO_DRIVER/DIO.h"
#include "EXT_I_CFG.h"
// Section :Macro Declarations
#define EXTI_Low_Level                               0
#define EXTI_Any_logical_change                      1
#define EXTI_Falling_Edge                            2
#define EXTI_Rising_Edge                             3

#define EXTI_INT2_Falling_Edge						 0
#define EXTI_INT2_Rising_Edge						 1

#define EXTI_Enable						EXTI_CFG_ENABLE
#define EXTI_Disable					EXTI_CFG_DISABLE                   

//Section :Macro Functions Declarations
//Section :Data type Declarations
//Section : Functions Declarations
#if EXTI_Enable
                           /*Function to initialize external interrupt*/
void EXTI_INIT(void);
                           /*Function to enable external  INT0 */
std_ReturnType_t EXTI_ENABLE_INT0(void);
                           /*Function to disable external  INT0 */
std_ReturnType_t EXTI_DISABLE_INT0(void);
                           /*Function to enable global  INT*/
std_ReturnType_t EXTI_ENABLE_Global_INT(void);
                           /*Function to disable global  INT */
std_ReturnType_t EXTI_DISABLE_Global_INT(void);
						  /*Call back function*/
void EXTI_SetCallBack(void(*FuncPtr)(void));	
void __vector_1(void);				  
#endif


#endif /* EXT_I_H_ */