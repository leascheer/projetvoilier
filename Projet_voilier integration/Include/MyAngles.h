/* ************************************
Driver pour comptage et transformation des angles � partir des donn�es de la girouette
Andrea P�rez
***************************************** */

#ifndef ANGLES
#define ANGLES

#include "stm32f10x.h"
#include "MyGPIO.h"
#include "MyTimer.h"

//Configuration des 3 pins
void Configuration(MyTimer_Struct_TypeDef * timer_in);

//Association des pointeurs des fonctions aux routines correspondantes
void EXTI15_10_IRQHandler(void);

//Activation de l'interruption pour mettre � zero la girouette sur le pin A10
void Active_IT_Zero(void(*IT_function )(void));
	
//Calibration renvoi 1 quand elle a �t� r�ussi 0 si non
int Calibration(MyTimer_Struct_TypeDef*timer);  

//A partir de l'angle du vend rend l'angle � prendre par le servo moteur (en ratio de 1)
//A REVISER!!
float ratio_moteur(int angle_vent);

//Fonction de retard de 20ms
void delay_us(uint32_t delay_us);

#endif
