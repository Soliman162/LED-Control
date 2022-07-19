#ifndef GPT_INTERFACE_H
#define GPT_INTERFACE_H

typedef enum {

    CHANNEL_ID_0=0,
    CHANNEL_ID_1,
    CHANNEL_ID_2,
    CHANNEL_ID_3,
    CHANNEL_ID_4,
    CHANNEL_ID_5,

    CHANNEL_ID_6,
    CHANNEL_ID_7,
    CHANNEL_ID_8,
    CHANNEL_ID_9,
    CHANNEL_ID_10,
    CHANNEL_ID_11

}CHANNEL_ID_CONFIG;

typedef enum{

    GPT_MODE_ONE_SHOT=1,
    GPT_MODE_PERIODIC,

}CHANNEL_MODE_CONFIG;

typedef enum {

    GPT_16BIT_TIMER=4,    
    GPT_24BIT_TIMER=4,
    GPT_32BIT_TIMER=0,

}GPT_BIT_NUM_TYPE_CONFIG;

typedef struct 
{
    GPT_BIT_NUM_TYPE_CONFIG Bit_Num;
    CHANNEL_ID_CONFIG Channel_ID;
    CHANNEL_MODE_CONFIG Channel_Mode;
   
}GPT_CONFIG_TYPE;


void Init_voidGPT(const GPT_CONFIG_TYPE *Copy_type);

void GPT_voidStart_Timer(const GPT_CONFIG_TYPE *Copy_type, u32 Copy_u32Start_Value);
void GPT_voidStop_Timer(const GPT_CONFIG_TYPE *Copy_type);

void GPT_voidEnableInterrupt(const GPT_CONFIG_TYPE *Copy_type,void (*ISR_ptrAddr)(void));

void CLR_voidInterrupt_Flag(const GPT_CONFIG_TYPE *Copy_type);




#endif