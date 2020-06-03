#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H 


/*GPIO Registers*/
#define GPIOA_DATA       	(*((u32 volatile*)(0x400043FC)))
#define GPIOA_DIRECTION  	(*((u32 volatile*)(0x40004400)))
#define GPIOA_DEN        	(*((u32 volatile*)(0x4000451C)))
#define GPIOA_CR          	(*((u32 volatile*)(0x40004524)))
#define GPIOA_LOCK         	(*((u32 volatile*)(0x40004520)))
#define GPIOA_PUR        	(*((u32 volatile*)(0x40004510)))

/* GPIO ports */
#define GPIO_PORTA 0x1
#define GPIO_PORTB 0x2
#define GPIO_PORTC 0x4
#define GPIO_PORTD 0x8
#define GPIO_PORTE 0x10
#define GPIO_PORTF 0x20

/* GPIO pins */
#define GPIO_PIN0 0x1
#define GPIO_PIN1 0x2
#define GPIO_PIN2 0x4
#define GPIO_PIN3 0x8
#define GPIO_PIN4 0x10
#define GPIO_PIN5 0x20
#define GPIO_PIN6 0x40
#define GPIO_PIN7 0x80

/* GPIO signals */
#define MODE_OUTPUT HIGH
#define MODE_INPUT LOW

#define u8 char
#define Error_Status u8

/************************************************************************
 * Function name: GPIO_Init
 *
 * parameters:  Input:
 *                 Port
 *                     type: u8
                        Description: GPIO port number (PORTA,PORTB,PORTC,PORTD)
 *                 Pin
 *                     type: u8
 *                     Description: GPIO pin number (PIN0 .. PIN7)
 *                 Direction
 *                     type: u8
 *                     Description: GPIO pin Direction (INPUT,OUTPUT)
 *
 *              Output: NA
 *              In/out: NA
 * return: E_OK, E_NOK
 * Description: a function to initialize all the GPIO Groups in the configurations
 ***************************************************************************/
Error_Status GPIO_Init(u8 Port,u8 Pin,u8 Direction);


/************************************************************************
 * function name: GPIO_WritePin
 *
 * parameters:  Input:
 *                Port
 *                     type: u8
                        Description: GPIO port number (PORTA,PORTB,PORTC,PORTD)
 *                 Pin
 *                     type: u8
 *                     Description: GPIO pin number (PIN0 .. PIN7)
 *                     type: u8
 *                 Value
 *                     type: u8
 *                     Description: Value which to be written on specified pin
 *
 *              Output: NA
 *              In/out: NA
 *
 * return: E_OK, E_NOK
 * Description: a function to write data to a specific port and pin
***************************************************************************/
Error_Status GPIO_WritePin(u8 Port,u8 Pin,u8 Value);

/************************************************************************
 * function name: GPIO_ReadPin
 *
 * parameters:  Input:
 *                Port
 *                     type: u8
                        Description: GPIO port number (PORTA,PORTB,PORTC,PORTD)
 *                 Pin  
 *                     type: u8
 *                     Description: GPIO pin number (PIN0 .. PIN7)
 *
 *
 *              Output: NA
 *              In/out: Value
 *                     type: pointer to u8
 *                     Description: data which to be read from specified pin
 *
 * return: E_OK, E_NOK
 * Description: a function to Digital read data from a specific port and pin
***************************************************************************/
Error_Status GPIO_ReadPin(u8 Port,u8 Pin,u8 *Value);


#endif
