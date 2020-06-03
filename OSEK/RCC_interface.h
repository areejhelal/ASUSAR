#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

#define RCC_RCGC2           	(*((u32 volatile*)(0x400FE108)))

#define RCC_PORTA 0x1
#define RCC_PORTB 0x2
#define RCC_PORTC 0x4
#define RCC_PORTD 0x8
#define RCC_PORTE 0x10
#define RCC_PORTF 0x20

Error_Status RCC_EnablePort(u8 Port);

#endif
