#include "STD_TYPES.h"
#include "RCC_interface.h"

Error_Status RCC_EnablePort(u8 Port){
	Error_Status err=STD_ERR_OK;
	if(Port!=RCC_PORTA && Port!=RCC_PORTB && Port!=RCC_PORTC && Port!=RCC_PORTD && Port!=RCC_PORTE && Port!=RCC_PORTF)
		err=STD_ERR_NOT_OK;
	else
		RCC_RCGC2|=Port;
	return err;
}
