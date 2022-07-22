#include "std_types.h"
#include "BIT_MATH.h"
#include "TM4C123GH6PM.h"

#include "GPT_interface.h"
#include "GPT_private.h"

static GPT_REGs_CONFIG *GPT_ARR[12] = {  GPT0_16_32_BIT_REGs,GPT1_16_32_BIT_REGs,
                                        GPT2_16_32_BIT_REGs,GPT3_16_32_BIT_REGs
                                        ,GPT4_16_32_BIT_REGs,GPT5_16_32_BIT_REGs,
                                        GPT0_32_64_WID_BIT_REGs,GPT1_32_64_WID_BIT_REGs
                                        ,GPT2_32_64_WID_BIT_REGs,GPT3_32_64_WID_BIT_REGs
                                        ,GPT4_32_64_WID_BIT_REGs,GPT5_32_64_WID_BIT_REGs  
                                      };
static void (*GPT_ISR_Arr[12])(void) = {NULL};
  

void TIMER1A_Handler(void);
void TIMER2A_Handler(void);
void TIMER3A_Handler(void);
void TIMER4A_Handler(void);
void TIMER5A_Handler(void);
void WTIMER0A_Handler(void);
void WTIMER1A_Handler(void);
void WTIMER2A_Handler(void);
void WTIMER3A_Handler(void);
void WTIMER4A_Handler(void);
void WTIMER5A_Handler(void);

void TIMER0A_Handler(void)
{
	if(GPT_ISR_Arr[0] != NULL )
	{
		GPT_ISR_Arr[0]();
	}
}
void TIMER1A_Handler(void)
{
	if(GPT_ISR_Arr[1] != NULL )
	{
		GPT_ISR_Arr[1]();
	}
}
void TIMER2A_Handler(void)
{
	if(GPT_ISR_Arr[2] != NULL )
	{
		GPT_ISR_Arr[2]();
	}
}
void TIMER3A_Handler(void)
{
		if(GPT_ISR_Arr[3] != NULL )
	{
		GPT_ISR_Arr[3]();
	}
}
void TIMER4A_Handler(void)
{
	if(GPT_ISR_Arr[4] != NULL )
	{
		GPT_ISR_Arr[4]();
	}
}
void TIMER5A_Handler(void)
{
	if(GPT_ISR_Arr[5] != NULL )
	{
		GPT_ISR_Arr[5]();
	}
}
void WTIMER0A_Handler(void)
{
	if(GPT_ISR_Arr[6] != NULL )
	{
		GPT_ISR_Arr[6]();
	}
}
void WTIMER1A_Handler(void)
{
	if(GPT_ISR_Arr[7] != NULL )
	{
		GPT_ISR_Arr[7]();
	}
}
void WTIMER2A_Handler(void)
{
	if(GPT_ISR_Arr[8] != NULL )
	{
		GPT_ISR_Arr[8]();
	}
}
void WTIMER3A_Handler(void)
{
	if(GPT_ISR_Arr[9] != NULL )
	{
		GPT_ISR_Arr[9]();
	}
}
void WTIMER4A_Handler(void)
{
		if(GPT_ISR_Arr[10] != NULL )
	{
		GPT_ISR_Arr[10]();
	}
}
void WTIMER5A_Handler(void)
{
	if(GPT_ISR_Arr[11] != NULL )
	{
		GPT_ISR_Arr[11]();
	}
}
/************************************************************************************/

void Init_voidGPT(const GPT_CONFIG_TYPE *Copy_type)
{
    /*disable timer*/
    GPT_ARR[Copy_type->Channel_ID]->GPTMCTL &= ~(1<<TAEN_BIT);
    /*SET BIT NUM*/
    GPT_ARR[Copy_type->Channel_ID]->GPTMCFG = Copy_type->Bit_Num;
    /*periodic or oneshot*/
    GPT_ARR[Copy_type->Channel_ID]->GPTMT_A_B_MR[TIMER_A] |= Copy_type->Channel_Mode;   
}
void GPT_voidStart_Timer(const GPT_CONFIG_TYPE *Copy_type, u32 Copy_u32Start_Value)
{
    /*load start value*/
    GPT_ARR[Copy_type->Channel_ID]->GPTMT_A_B_ILR[TIMER_A] = Copy_u32Start_Value;
    /*enable timer*/
    GPT_ARR[Copy_type->Channel_ID]->GPTMCTL |= (1<<TAEN_BIT);
}
void GPT_voidStop_Timer(const GPT_CONFIG_TYPE *Copy_type)
{
    GPT_ARR[Copy_type->Channel_ID]->GPTMCTL &= ~(1<<TAEN_BIT);
}

void GPT_voidEnableInterrupt(const GPT_CONFIG_TYPE *Copy_type,void (*ISR_ptrAddr)(void))
{
	if(ISR_ptrAddr != NULL )
	{
		GPT_ISR_Arr[Copy_type->Channel_ID] = ISR_ptrAddr;
	}
   GPT_ARR[Copy_type->Channel_ID]->GPTMIMR |= 1;
}

void CLR_voidInterrupt_Flag(const GPT_CONFIG_TYPE *Copy_type)
{
    GPT_ARR[Copy_type->Channel_ID]->GPTMICR |= 1;
}

