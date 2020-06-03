#include "STD_TYPES.h"
#include "GPIO_interface.h"


Error_Status GPIO_Init(u8 Port,u8 Pin,u8 Direction){
	Error_Status err = STD_ERR_OK;
	switch(Port){
		case GPIO_PORTA:
			GPIOA_DEN|=Pin;
			if(Direction==HIGH){
				GPIOA_DIRECTION|=Pin;
			}
			else if(Direction==LOW){
				GPIOA_DIRECTION&=~Pin;
				GPIOA_PUR|=Pin;	
			}
			break;
		case GPIO_PORTB:
			break;
		case GPIO_PORTC:
			break;
		case GPIO_PORTD:
			break;
		case GPIO_PORTE:
			break;
		case GPIO_PORTF:
			break;
		default:
			err=STD_ERR_NOT_OK;
			break;
	}
	return err;
}
Error_Status GPIO_WritePin(u8 Port,u8 Pin,u8 Value){
	Error_Status err = STD_ERR_OK;
	switch(Port){
		case GPIO_PORTA:
			GPIOA_DEN|=Pin;
			if(Value==HIGH){
				GPIOA_DATA|=Pin;
			}
			else if(Value==LOW){
				GPIOA_DATA&=~Pin;
			}
			break;
		case GPIO_PORTB:
			break;
		case GPIO_PORTC:
			break;
		case GPIO_PORTD:
			break;
		case GPIO_PORTE:
			break;
		case GPIO_PORTF:
			break;
		default:
			err=STD_ERR_NOT_OK;
			break;
	}
	return err;
}
Error_Status GPIO_ReadPin(u8 Port,u8 Pin,u8 *Value){
	Error_Status err = STD_ERR_OK;
	switch(Port){
		case GPIO_PORTA:
			*Value=GPIOA_DATA&Pin;
			if(*Value>0)
				*Value=1;
			break;
		case GPIO_PORTB:
			break;
		case GPIO_PORTC:
			break;
		case GPIO_PORTD:
			break;
		case GPIO_PORTE:
			break;
		case GPIO_PORTF:
			break;
		default:
			err=STD_ERR_NOT_OK;
			break;
	}
	return err;
}
