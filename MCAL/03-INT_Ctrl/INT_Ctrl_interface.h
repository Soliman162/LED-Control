#ifndef INT_CTRL_INTERAFCE_H
#define INT_CTRL_INTERAFCE_H

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef enum
{
    GPIO_Port_A=0,
    GPIO_Port_B,
    GPIO_Port_C,
    GPIO_Port_D,
    GPIO_Port_E,
    UART0,
    UART1,
    SSI0,
    I2C0,
    PWM0_Fault,
    PWM0_Generator_1, 
    PWM0_Generator_2,
    PWM0_Generator_3,
    QEI0,
    ADC0_Sequence_0,
    ADC0_Sequence_1,
    ADC0_Sequence_2,
    ADC0_Sequence_3,
    Watchdog_Timers_0_and_1,
    Bit_Timer_16_32_0A,
    Bit_Timer_16_32_0B,
    Bit_Timer_16_32_1A,
    Bit_Timer_16_32_1B,
    Bit_Timer_16_32_2A,
    Bit_Timer_16_32_2B,
    Analog_Comparator_0,
    Analog_Comparator_1,
    System_Control=28,
    Flash_Memory_Control_EEPROM_Control,
    GPIO_Port_F,
    UART2=33,
    SSI1    ,
    Bit_Timer_3A,
    Bit_Timer_3B ,
    I2C1,
    QEI1,
    CAN0,
    CAN1,
    Hibernation_Module=43,
    USB,
    PWM_Generator_3,
    μDMA_Software,
    μDMA_Error,
    ADC1_Sequence_0,
    ADC1_Sequence_1,
    ADC1_Sequence_2,
    ADC1_Sequence_3,
    SSI2=57,
    SSI3,
    UART3,
    UART4,
    UART5,
    UART6,
    UART7,
    I2C2=68,
    I2C3,
    Timer_16_32_4A,
    Timer_16_32_4B,
    Timer_16_32_5A=92,
    Timer_16_32_5B,
    Timer_32_64_0A, 
    Timer_32_64_0B ,
    Timer_32_64_1A,
    Timer_32_64_1B,
    Timer_32_64_2A,
    Timer_32_64_2B,
    Timer_32_64_3A,
    Timer_32_64_3B,
    Timer_32_64_4A,
    Timer_32_64_4B,
    Timer_32_64_5A,
    Timer_32_64_5B,
    System_Exception, 
    PWM1_Generator_0=134, 
    PWM1_Generator_1 ,
    PWM1_Generator_2 ,
    PWM1_Generator_3 ,
    PWM1_Fault
    
}INTRRUPTS_Types;


typedef enum{

    GROUP_PRIORITY_8_SUBPRIORITY_1 = 0x0,
    GROUP_PRIORITY_4_SUBPRIORITY_2 = 0x5,
    GROUP_PRIORITY_2_SUBPRIORITY_4 = 0x6,
    GROUP_PRIORITY_1_SUBPRIORITY_8 = 0x7

}PRIORYTY_SECTION_TYPE;

typedef enum{

    /*GROUP_PRIORITY_8_SUBPRIORITY_1*/

    GROUP_PRIORITY_0_SUBPRIORITY_0=0,
    GROUP_PRIORITY_1_SUBPRIORITY_0,
    GROUP_PRIORITY_2_SUBPRIORITY_0,
    GROUP_PRIORITY_3_SUBPRIORITY_0,
    GROUP_PRIORITY_4_SUBPRIORITY_0,
    GROUP_PRIORITY_5_SUBPRIORITY_0,
    GROUP_PRIORITY_6_SUBPRIORITY_0,
    GROUP_PRIORITY_7_SUBPRIORITY_0,

    /*GROUP_PRIORITY_4_SUBPRIORITY_2*/

    GROUP_PRIORITY_1_SUBPRIORITY_0_XXY=0b010,
    GROUP_PRIORITY_2_SUBPRIORITY_0_XXY=0b100,
    GROUP_PRIORITY_3_SUBPRIORITY_0_XXY=0b110,

    GROUP_PRIORITY_1_SUBPRIORITY_1_XXY=0b011,
    GROUP_PRIORITY_2_SUBPRIORITY_1_XXY=0b101,
    GROUP_PRIORITY_3_SUBPRIORITY_1_XXY=0b111,

    /*GROUP_PRIORITY_2_SUBPRIORITY_4*/

    GROUP_PRIORITY_1_SUBPRIORITY_0_XYY=0b100,
    GROUP_PRIORITY_1_SUBPRIORITY_1_XYY=0b101,
    GROUP_PRIORITY_1_SUBPRIORITY_2_XYY=0b110,
    GROUP_PRIORITY_1_SUBPRIORITY_3_XYY=0b111,
    
    /*GROUP_PRIORITY_1_SUBPRIORITY_8*/

    GROUP_PRIORITY_0_SUBPRIORITY_1=1,
    GROUP_PRIORITY_0_SUBPRIORITY_2,
    GROUP_PRIORITY_0_SUBPRIORITY_3,
    GROUP_PRIORITY_0_SUBPRIORITY_4,
    GROUP_PRIORITY_0_SUBPRIORITY_5,
    GROUP_PRIORITY_0_SUBPRIORITY_6,
    GROUP_PRIORITY_0_SUBPRIORITY_7

}PRIORITY_LEVEL;
 

void Init_voidIntCtrl(void);

#endif