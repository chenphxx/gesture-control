#ifndef __USART1_H
#define	__USART1_H

#include "stm32f10x.h"

void Usart1_Config(void);
void Nvic_Usart1_Config(void);
void Usart1_Send(unsigned char *str);


#endif
