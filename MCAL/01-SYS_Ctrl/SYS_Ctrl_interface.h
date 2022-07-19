#ifndef SYS_CTRL_INTERFACE_H
#define SYS_CTRL_INTERFACE_H


typedef enum{

    WATCH_DOG_TIMER = 0,//0
    GENERAL_PURPOUSE_TIMER_16_32=1,//1
    GENERAL_PURPOUSE_INPUT_OUTPUT=2,//2
    MICRO_DIRECT_MEMORY_ACCESS=3,//3
    HIB=5,//5
    UART=6,//6
    SSI=7,//7
    I2C=8,//8
    USB_SCB=10,//10
    CAN=13,//13
    ADC=14,//14
    ACMP=15,//15
    PWM=16,//16
    QEI=17,//17
    EEPROM=22,//22
    WTIMER_32_64=23//23

}MODULES_NAME;

typedef enum{

    MODULE_0,
    MODULE_1,
    MODULE_2,
    MODULE_3,
    MODULE_4,
    MODULE_5,
    MODULE_6,
    MODULE_7

}MODULE_INDEX;


void Init_voidSYS_Ctrl_Clock(void);

void SYS_Ctrl_voidReset(MODULES_NAME Copy_enumModuleName, MODULE_INDEX Copy_enumModuleIndex);

void SYS_Ctrl_voidEnable_Clock_Run_Mode(MODULES_NAME Copy_enumModuleName, MODULE_INDEX Copy_enumModuleIndex);



#endif