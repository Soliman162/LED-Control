#include "std_types.h"
#include "BIT_MATH.h"
#include "TM4C123GH6PM.h"

#include "DIO_interface.h"

static GPIO_CONFIG_REGs *GPIO_ARR[6] = {GPIO_A_PRE,GPIO_B_PRE,GPIO_C_PRE,GPIO_D_PRE,GPIO_E_PRE,GPIO_F_PRE};


void DIO_voidInit_Pin(const PORT_CONFIG_TYPE * Copy_Pin)
{
    GPIO_ARR[Copy_Pin->Pin_Number/8]->GPIODIR |= (u32)Copy_Pin->Pin_Direction<<(Copy_Pin->Pin_Number%8);
    if(Copy_Pin->Pin_Direction != GPIO_INPUT )
    {
        GPIO_ARR[Copy_Pin->Pin_Number/8]->GPIODR_2_4_8_R[Copy_Pin->Pin_OutPut_Current] |= 1<<(Copy_Pin->Pin_Number%8);
    }
    if(Copy_Pin->Pin_InternalAttach != NOT_USED)
    {
        GPIO_ARR[Copy_Pin->Pin_Number/8]->GPIO_OD_PU_PD_SL_R[Copy_Pin->Pin_InternalAttach] |= 1<<(Copy_Pin->Pin_Number%8);
    }
    GPIO_ARR[Copy_Pin->Pin_Number/8]->GPIODEN |= 1<<(Copy_Pin->Pin_Number%8); 
}
void DIO_voidWriteChannel(DIO_CHANNEL_TYPE Copy_enumChannel, DIO_LEVEL_TYPE Copy_enumLevel_type)
{
    GPIO_ARR[Copy_enumChannel/8]->GPIODATA[1<<(Copy_enumChannel%8)] = (u32)(1<<(Copy_enumChannel%8));
	/*
    if(Copy_enumLevel_type == DIO_HIGH)
	{
		GPIO_ARR[Copy_enumChannel/8]->GPIODATA[255] |= (u32)(1<<(Copy_enumChannel%8));
	}else if( Copy_enumLevel_type == DIO_LOW)
	{
		GPIO_ARR[Copy_enumChannel/8]->GPIODATA[255] &= (u32)(~(1<<(Copy_enumChannel%8)));
	}
    */
}


