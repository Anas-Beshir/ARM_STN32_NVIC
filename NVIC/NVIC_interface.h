#ifndef		NVIC_INTERFACE_H
#define		NVIC_INTERFACE_H

void	NVIC_voidInit(void);


void	NVIC_voidEnableInt(u8 IntNum);
void	NVIC_voidDisableInt(u8 IntNum);

void	NVIC_voidSetPendingFlag(u8 IntNum);
void	NVIC_voidClrPendingFlag(u8 IntNum);

u8	NVIC_u8GetActiveFlag(u8 IntNum);
void	NVIC_voidSetPriority(u8 IntNum,u8 Priority);

#endif