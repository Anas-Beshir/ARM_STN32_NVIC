#include	"STD_Types.h"
#include	"BIT_Math.h"

#include	"RCC_interface.h"
#include	"DIO_interface.h"
#include	"NVIC_interface.h"


void	_delay_ms(u32 Ticks)
{
	for(u32 i = 0; i < (ms * 500) ; i++)
	{
		asm("NOP");
	}
}

void	EXTI0_IRQHandler(void);

int	main(void)
{
	/*	Initialization Part		*/
	
	/*	System Clk init			*/
	MRCC_voidSysClkInit();
	
	/*	Toggle Led C13	GPIOC	*/
	/*	1- Enable Per Clk "RCC" Port C		*/
	MRCC_voidEnablePerClk(RCC_APB2,4);
	
	/*	Direction for C13 is output Push Pull */
	MDIO_voidSetPinDirection(PORTC, PIN13, OUT_2MHZ_PP);
	
	/*	NVIC Initialization		*/
	NVIC_voidInit();
	
	/*	EXTI0 NVIC interrupt Enable 			*/
	NVIC_voidEnableInt(6);
	
	/*	EXTI0 Set the pending flag	 			*/
	NVIC_voidSetPendingFlag(6);
	
	while(1)
	{

	}
	return 0;
}

//External Peripherals
void	EXTI0_IRQHandler(void)
{
		/*	Toggle led */
		MDIO_voidSetPinValue(PORTC, PIN13, DIO_LOW);
		_delay_ms();
		MDIO_voidSetPinValue(PORTC, PIN13, DIO_HIGH);
		_delay_ms();	
}
//Core Peripheral
void	SysTick_Handler(void)
{
	
}