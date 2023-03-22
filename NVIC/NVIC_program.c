#include	"STD_Types.h"
#include	"BIT_Math.h"

#include	"NVIC_interface.h"
#include	"NVIC_private.h"
#include	"NVIC_config.h"

void	NVIC_voidInit(void)
{
	#ifndef		SCB_AIRCR	 
	#define		SCB_AIRCR	 *((volatile u32 *)(0xE000ED00+0x0C))
	#endif
	SCB_AIRCR	=	NVIC_GRB_SUB_NUM;
}


void	NVIC_voidEnableInt(u8 IntNum)
{
	if(IntNum<32)
	{
		NVIC_ISER0 = (1<<IntNum) ;
	}
	else if(IntNum<64)
	{
		IntNum -= 32 ;
		NVIC_ISER1 = (1<<IntNum) ;
	}
}


void	NVIC_voidDisableInt(u8 IntNum)
{
	if(IntNum<32)
	{
		NVIC_ICER0 = (1<<IntNum) ;
	}
	else if(IntNum<64)
	{
		IntNum -= 32 ;
		NVIC_ICER1 = (1<<IntNum) ;
	}
}

void	NVIC_voidSetPendingFlag(u8 IntNum)
{
	if(IntNum<32)
	{
		NVIC_ISPR0 = (1<<IntNum) ;
	}
	else if(IntNum<64)
	{
		IntNum -= 32 ;
		NVIC_ISPR1 = (1<<IntNum) ;
	}
}


void	NVIC_voidClrPendingFlag(u8 IntNum)
{
	if(IntNum<32)
	{
		NVIC_ICPR0 = (1<<IntNum) ;
	}
	else if(IntNum<64)
	{
		IntNum -= 32 ;
		NVIC_ICPR1 = (1<<IntNum) ;
	}
}


u8	NVIC_u8GetActiveFlag(u8 IntNum)
{
	u8 Local_Active = 0x22;
	if(IntNum<32)
	{
		Local_Active	=	GIT_BIT(NVIC_IABR0,(1<<IntNum));
	}
	else if(IntNum<64)
	{
		IntNum -= 32 ;
		Local_Active	=	GIT_BIT(NVIC_IABR1,(1<<IntNum));
	}
	return Local_Active;
}

//NVIC_voidSetPriority(0,0b0111) /*Group 1 Sub 3*/
void	NVIC_voidSetPriority(u8 IntNum,u8 Priority)
{
	NVIC_IPR[IntNum] = (Priority<<4);
}