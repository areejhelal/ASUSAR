/* This file is Auto-Generated to configure the AUTOSAR OS */



/************************** GENERAL CONFIGURATION ***************************/

#define CPU_CLOCK_HZ					16000000
#define OSTICKDURATION					1000        /*MicroSeconds*/
#define NUMBER_OF_EXTENDEDTASK			2
#define NUMBER_OF_BASICTASK				2
#define NUMBER_OF_PRIORITES				1
#define NUMBER_OF_EVENTS				6
#define NUMBER_OF_RESOURCES				0
#define NUMBER_OF_COUNTER				1
#define NUMBER_OF_ALARM					6
#define NUMBER_OF_ISR					0
#define NUMBER_OF_CALLBACK_FUNCTION		0

#define ALARM_CALLBACK					0
#define IDLETASK_STACK_SIZE				128
/**************************** TASK CONFIGURATION ****************************/
/************************** Task 1 *****************************************/
#define OS_TASK_NAME_1					T1
#define OS_TASK_PRIORITY_1				3
#define OS_TASK_SCHEDULE_1				full
#define OS_TASK_ACTIVATION_1			100
#define OS_TASK_AUTOSTART_1				FALSE
#define OS_TASK_TYPE_1					basic
#define OS_TASK_SIZE_1					128
#define TASK_1_NUMBER_OF_EVENT_IN_TASK	6
#define TASK_1_NUMBER_OF_RES_IN_TASK	2
#define TASK_1_EVENT_1					RTE_Event_SeatHeaterEvent
#define TASK_1_EVENT_2					RTE_Event_SeatSensorLeftUpdateTimer
#define TASK_1_EVENT_3					RTE_Event_SeatSensorRightUpdateTimer
#define TASK_1_EVENT_4					BSW_Event_Com_MainFunctionRx
#define TASK_1_EVENT_5					BSW_Event_Com_MainFunctionTx
#define TASK_1_EVENT_6					BSW_Event_CanTp_MainFunction
#define TASK_1_RESOURCE_1				Res1
#define TASK_1_RESOURCE_2				Res2
/************************** Task 2 *****************************************/
#define OS_TASK_NAME_2                  T2
#define OS_TASK_PRIORITY_2              3
#define OS_TASK_SCHEDULE_2              full
#define OS_TASK_ACTIVATION_2            90
#define OS_TASK_AUTOSTART_2             FALSE
#define OS_TASK_TYPE_2                  basic
#define OS_TASK_SIZE_2                  128
#define TASK_2_NUMBER_OF_EVENT_IN_TASK  6
#define TASK_2_NUMBER_OF_RES_IN_TASK    2
#define TASK_2_EVENT_1                  RTE_Event_SeatHeaterEvent
#define TASK_2_EVENT_2                  RTE_Event_SeatSensorLeftUpdateTimer
#define TASK_2_EVENT_3                  RTE_Event_SeatSensorRightUpdateTimer
#define TASK_2_EVENT_4                  BSW_Event_Com_MainFunctionRx
#define TASK_2_EVENT_5                  BSW_Event_Com_MainFunctionTx
#define TASK_2_EVENT_6                  BSW_Event_CanTp_MainFunction
#define TASK_2_RESOURCE_1               Res1
#define TASK_2_RESOURCE_2               Res2
/************************** Task 3 *****************************************/
#define OS_TASK_NAME_3                  T3
#define OS_TASK_PRIORITY_3              4
#define OS_TASK_SCHEDULE_3              full
#define OS_TASK_ACTIVATION_3            80
#define OS_TASK_AUTOSTART_3             FALSE
#define OS_TASK_TYPE_3                  extended
#define OS_TASK_SIZE_3                  128
#define TASK_3_NUMBER_OF_EVENT_IN_TASK  6
#define TASK_3_NUMBER_OF_RES_IN_TASK    2
#define TASK_3_EVENT_1                  RTE_Event_SeatHeaterEvent
#define TASK_3_EVENT_2                  RTE_Event_SeatSensorLeftUpdateTimer
#define TASK_3_EVENT_3                  RTE_Event_SeatSensorRightUpdateTimer
#define TASK_3_EVENT_4                  BSW_Event_Com_MainFunctionRx
#define TASK_3_EVENT_5                  BSW_Event_Com_MainFunctionTx
#define TASK_3_EVENT_6                  BSW_Event_CanTp_MainFunction
#define TASK_3_RESOURCE_1               Res1
#define TASK_3_RESOURCE_2               Res2
/************************** Task 4 *****************************************/
#define OS_TASK_NAME_4                  T4
#define OS_TASK_PRIORITY_4              3
#define OS_TASK_SCHEDULE_4              full
#define OS_TASK_ACTIVATION_4            70
#define OS_TASK_AUTOSTART_4             TRUE
#define OS_TASK_TYPE_4                  extended
#define OS_TASK_SIZE_4                  128
#define TASK_4_NUMBER_OF_EVENT_IN_TASK  6
#define TASK_4_NUMBER_OF_RES_IN_TASK    2
#define TASK_4_EVENT_1                  RTE_Event_SeatHeaterEvent
#define TASK_4_EVENT_2                  RTE_Event_SeatSensorLeftUpdateTimer
#define TASK_4_EVENT_3                  RTE_Event_SeatSensorRightUpdateTimer
#define TASK_4_EVENT_4                  BSW_Event_Com_MainFunctionRx
#define TASK_4_EVENT_5                  BSW_Event_Com_MainFunctionTx
#define TASK_4_EVENT_6                  BSW_Event_CanTp_MainFunction
#define TASK_4_RESOURCE_1               Res1
#define TASK_4_RESOURCE_2               Res2
/*************************** ALARM CONFIGURATION ****************************/

#define OS_ALARM_NAME_1					RTE_Alarm_alarm1
#define AUTOSTART_1						FALSE
#define ALARM_TIME_1					NULL
#define CYCLE_TIME_1					300
#define OS_ALARM_COUNTER_REF_1			0
#define OS_ALARM_ACTION_1				ACTIVATETASK
#define OS_ALARM_ACTION_TASK_REF_1		T4
#define OS_ALARM_ACTION_EVENT_REF_1		RTE_Event_SeatHeaterEvent

#define OS_ALARM_NAME_2					RTE_Alarm_alarm2
#define AUTOSTART_2						TRUE
#define ALARM_TIME_2					NULL
#define CYCLE_TIME_2					100
#define OS_ALARM_COUNTER_REF_2			0
#define OS_ALARM_ACTION_2				SETEVENT
#define OS_ALARM_ACTION_TASK_REF_2		T1
#define OS_ALARM_ACTION_EVENT_REF_2		RTE_Event_SeatSensorLeftUpdateTimer

#define OS_ALARM_NAME_3					RTE_Alarm_alarm3
#define AUTOSTART_3						TRUE
#define ALARM_TIME_3					NULL
#define CYCLE_TIME_3					100
#define OS_ALARM_COUNTER_REF_3			0
#define OS_ALARM_ACTION_3				SETEVENT
#define OS_ALARM_ACTION_TASK_REF_3		T1
#define OS_ALARM_ACTION_EVENT_REF_3		RTE_Event_SeatSensorRightUpdateTimer

#define OS_ALARM_NAME_4					BSW_Alarm_alarm4
#define AUTOSTART_4						TRUE
#define ALARM_TIME_4					NULL
#define CYCLE_TIME_4					100
#define OS_ALARM_COUNTER_REF_4			0
#define OS_ALARM_ACTION_4				SETEVENT
#define OS_ALARM_ACTION_TASK_REF_4		T1
#define OS_ALARM_ACTION_EVENT_REF_4		BSW_Event_Com_MainFunctionRx

#define OS_ALARM_NAME_5					BSW_Alarm_alarm5
#define AUTOSTART_5						TRUE
#define ALARM_TIME_5					NULL
#define CYCLE_TIME_5					200
#define OS_ALARM_COUNTER_REF_5			0
#define OS_ALARM_ACTION_5				SETEVENT
#define OS_ALARM_ACTION_TASK_REF_5		T1
#define OS_ALARM_ACTION_EVENT_REF_5		BSW_Event_Com_MainFunctionTx

#define OS_ALARM_NAME_6					BSW_Alarm_alarm6
#define AUTOSTART_6						TRUE
#define ALARM_TIME_6					NULL
#define CYCLE_TIME_6					100
#define OS_ALARM_COUNTER_REF_6			0
#define OS_ALARM_ACTION_6				SETEVENT
#define OS_ALARM_ACTION_TASK_REF_6		T1
#define OS_ALARM_ACTION_EVENT_REF_6		BSW_Event_CanTp_MainFunction
/************************* COUNTER CONFIGURATION ****************************/

#define OS_COUNTER_Name_1					0
#define OS_COUNTER_TYPE_1					HARDWARE
#define OS_SECONDS_PER_TICK_1				1e-09
#define OS_COUNTER_MAX_ALLOWED_VALUE_1		65535
#define OS_COUNTER_TICKS_PER_BASE_1			1
#define OS_COUNTER_MIN_CYCLE_1				0
/*************************** EVENT CONFIGURATION ****************************/

#define OS_EVENT_NAME_1					RTE_Event_SeatHeaterEvent
#define OS_EVENT_MASK_1					300

#define OS_EVENT_NAME_2					RTE_Event_SeatSensorLeftUpdateTimer
#define OS_EVENT_MASK_2					300

#define OS_EVENT_NAME_3					RTE_Event_SeatSensorRightUpdateTimer
#define OS_EVENT_MASK_3					300

#define OS_EVENT_NAME_4					BSW_Event_Com_MainFunctionRx
#define OS_EVENT_MASK_4					300

#define OS_EVENT_NAME_5					BSW_Event_Com_MainFunctionTx
#define OS_EVENT_MASK_5					300

#define OS_EVENT_NAME_6					BSW_Event_CanTp_MainFunction
#define OS_EVENT_MASK_6					300
/************************ RESOURCE CONFIGURATION ****************************/
