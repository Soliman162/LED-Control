#include "std_types.h"

#include "INT_Ctrl_interface.h"
#include "SYS_Ctrl_interface.h"
#include "DIO_interface.h"
#include "GPT_interface.h"

static u32 ON_u32Tick_Time = 0;
static u32 OFF_u32Tick_Time = 0;

static GPT_CONFIG_TYPE TIMER_0 = {GPT_32BIT_TIMER,CHANNEL_ID_0,GPT_MODE_PERIODIC};
static GPT_CONFIG_TYPE TIMER_1 = {GPT_32BIT_TIMER,CHANNEL_ID_1,GPT_MODE_PERIODIC};

static PORT_CONFIG_TYPE LED_0  = {PIN_F1,GPIO_OUTPUT,PULL_UP,OUT_PUT_CURRENT_STREGNTH_8MA};

void Led_voidCtrl(u16 ON_u16Time, u16 OFF_u16Time);

void Timeer0_ISR(void);
void Timeer1_ISR(void);

int main(void)
{
	/*
	
	SYS_Ctrl:-
		0x400FE000, 0x400FEA5C
	
	GPT:-
		 16/32-bit Timer 0: 0x40030000,	0x40030FC0	
		 16/32-bit Timer 1: 0x40031000,	0x40031FC0
		 16/32-bit Timer 2: 0x40032000,	0x40032FC0
		 16/32-bit Timer 3: 0x40033000,	0x40033FC0
		 16/32-bit Timer 4: 0x40034000,	0x40034FC0
		 16/32-bit Timer 5: 0x40035000,	0x40035FC0
	
	GPIO:-
		0x40000000, 0x4000FFFF
	
	*/
	Init_voidIntCtrl();
	Init_voidSYS_Ctrl_Clock();

	SYS_Ctrl_voidEnable_Clock_Run_Mode( GENERAL_PURPOUSE_INPUT_OUTPUT,  MODULE_5);
	SYS_Ctrl_voidEnable_Clock_Run_Mode( GENERAL_PURPOUSE_TIMER_16_32,  MODULE_0);
	SYS_Ctrl_voidEnable_Clock_Run_Mode( GENERAL_PURPOUSE_TIMER_16_32,  MODULE_1);
	
    DIO_voidInit_Pin(&LED_0);
	
    Init_voidGPT(&TIMER_0);
	Init_voidGPT(&TIMER_1);

	Led_voidCtrl( 3 , 1  );
		
    while (1)
    {

    }
		
		return 0;
}

void Timeer0_ISR(void)
{
	GPT_voidStop_Timer(&TIMER_0);
	CLR_voidInterrupt_Flag(&TIMER_0);
	
	DIO_voidWriteChannel(LED_0.Pin_Number,DIO_LOW);
	GPT_voidStart_Timer(&TIMER_1,OFF_u32Tick_Time );
}
void Timeer1_ISR(void)
{
	GPT_voidStop_Timer(&TIMER_1);
	CLR_voidInterrupt_Flag(&TIMER_1);
	
    DIO_voidWriteChannel(LED_0.Pin_Number,DIO_HIGH);
    GPT_voidStart_Timer(&TIMER_0,ON_u32Tick_Time);
}
void Led_voidCtrl(u16 Copy_u16ONTime, u16 Copy_u16OFFTime)
{
	GPT_voidEnableInterrupt(&TIMER_0,&Timeer0_ISR);
	GPT_voidEnableInterrupt(&TIMER_1,&Timeer1_ISR);
	
    OFF_u32Tick_Time = Copy_u16OFFTime*10000;
    ON_u32Tick_Time = Copy_u16ONTime*10000 ;
	
	DIO_voidWriteChannel(LED_0.Pin_Number,DIO_HIGH);
	GPT_voidStart_Timer(&TIMER_0,ON_u32Tick_Time);
}

