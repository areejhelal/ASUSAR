/*
 * main.c
 */
#pragma diag_push
#pragma CHECK_MISRA("none")

#include <stdbool.h>
#include <stdint.h>
#include "driverlib/interrupt.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "inc/hw_memmap.h"
#include "driverlib/uart.h"
#include "OS/include/task.h"
#include "OS/include/event.h"
#include "utils/uartstdio.h"
#include "OS/include/InitConsole.h"
#include <PORTF.h>
#include "include/Com.h"
#include "include/CanTp_Cfg.h"
#include "include/CanTp.h"
#include "include/CanIf.h"
#include "include/Can.h"
#include "Rte/Rte.h"
#include "Dio.h"
#include "GPIO_interface.h"
#include "RCC_interface.h"

extern const Can_ConfigType CanContainer;
extern const CanTp_ConfigType CanTp_Config ;
extern const ComConfig_type ComConfiguration ;
extern const CanIf_ConfigType CanIf_configTypeInstance;

//DeclareTask(T1);
//
//DeclareEvent(RTE_Event_HeatRegulatorEvent);
//DeclareEvent(RTE_Event_HeatingControllerEvent);
//DeclareEvent(BSW_Event_Com_MainFunctionRx);
//DeclareEvent(BSW_Event_Com_MainFunctionTx);
//DeclareEvent(BSW_Event_CanTp_MainFunction);

DeclareTask(T1);
DeclareTask(T2);
DeclareTask(T3);
DeclareTask(T4);

DeclareEvent(RTE_Event_SeatHeaterEvent);
DeclareEvent(RTE_Event_SeatSensorLeftUpdateTimer);
DeclareEvent(RTE_Event_SeatSensorRightUpdateTimer);
DeclareEvent(BSW_Event_Com_MainFunctionRx);
DeclareEvent(BSW_Event_Com_MainFunctionTx);
DeclareEvent(BSW_Event_CanTp_MainFunction);

DeclareAlarm(RTE_Alarm_alarm1);

//DeclareAlarm(alar1);

//#pragma RESET_MISRA("all")


int flag = 0;


int main(void)
{
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    RCC_EnablePort(RCC_PORTA);

    GPIO_Init(GPIO_PORTA, GPIO_PIN4, MODE_OUTPUT);
    GPIO_Init(GPIO_PORTF, GPIO_PIN2, MODE_OUTPUT);

    GPIO_WritePin(GPIO_PORTA, GPIO_PIN4, LOW);
    GPIO_WritePin(GPIO_PORTA, GPIO_PIN2, HIGH);

    StartOS(OSDEFAULTAPPMODE);
    while (1)
    {

    }
    return 0;
}

//TASK(T1)
//{
//    EventMaskType NewEvent;
//    while(true)
//    {
//        WaitEvent(BSW_Event_Com_MainFunctionTx );
//        GetEvent(T1, &NewEvent);
//        ClearEvent(NewEvent);
//        if(NewEvent & BSW_Event_Com_MainFunctionTx)
//        {
//            SeatSensorRunnableRight();
//            SeatSensorRunnableLeft();
//            SeatHeaterRunnable();
//            Com_MainFunctionRx();
//            Com_MainFunctionTx();
//        }
//
//        TerminateTask();
//    }
//}

TASK(T1)
{

    while (true)
    {
        GPIO_WritePin(GPIO_PORTA, GPIO_PIN4, HIGH);
       /* ActivateTask(T2);
        TerminateTask();*/
        ChainTask(T2);
    }
}

TASK(T2)
{
    while (true)
    {
        GPIO_WritePin(GPIO_PORTA, GPIO_PIN4, LOW);
        /*ActivateTask(T1);
        TerminateTask();*/
        ChainTask(T1);
    }
}


TASK(T3)
{
    EventMaskType Current_eventMask;
    while (true)
    {
        GPIO_WritePin(GPIO_PORTA, GPIO_PIN4, HIGH);
        WaitEvent(RTE_Event_SeatHeaterEvent);
        GetEvent(T3, &Current_eventMask);
        ClearEvent(Current_eventMask);
        GPIO_WritePin(GPIO_PORTA, GPIO_PIN4, LOW);
        GPIO_WritePin(GPIO_PORTA, GPIO_PIN4, HIGH);
        GPIO_WritePin(GPIO_PORTA, GPIO_PIN4, HIGH);
    }
}

TASK(T4)
{
    static flag=0;
    while (true)
    {
        if(flag == 0)
        {
            GPIO_WritePin(GPIO_PORTA, GPIO_PIN4, HIGH);
            flag =1;
        }
        else if(flag == 1)
        {
            GPIO_WritePin(GPIO_PORTA, GPIO_PIN4, LOW);
            flag=0;
        }

        SetAbsAlarm(RTE_Alarm_alarm1, 2000, 0);


        TerminateTask();
        //SetEvent(T3, RTE_Event_SeatHeaterEvent);
        //GPIO_WritePin(GPIO_PORTA, GPIO_PIN4, HIGH);
    }
}
