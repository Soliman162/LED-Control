/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Mcu_Hw.h
 *       Module:  Mcu_Hw
 *
 *  Description:  header file for Registers definition    
 *  
 *********************************************************************************************************************/
#ifndef MCU_HW_H
#define MCU_HW_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "std_types.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define CORTEX_M4_BASE_ADDRESS      0xE000E000
#define SCB_BASE_ADDRESS            0x400FE000

#define GPIO_PORT_A_APB_BASE_ADDRESS        0x40004000
#define GPIO_port_B_APB_BASE_ADDRESS        0x40005000
#define GPIO_port_C_APB_BASE_ADDRESS        0x40006000
#define GPIO_port_D_APB_BASE_ADDRESS        0x40007000
#define GPIO_port_E_APB_BASE_ADDRESS        0x40024000
#define GPIO_port_F_APB_BASE_ADDRESS        0x40025000


#define GPT_16_32_0_BASE_ADDRESS    0x40030000    
#define GPT_16_32_1_BASE_ADDRESS    0x40031000
#define GPT_16_32_2_BASE_ADDRESS    0x40032000
#define GPT_16_32_3_BASE_ADDRESS    0x40033000
#define GPT_16_32_4_BASE_ADDRESS    0x40034000
#define GPT_16_32_5_BASE_ADDRESS    0x40035000

#define GPT_32_64_WID_6_BASE_ADDRESS     0x40036000    
#define GPT_32_64_WID_7_BASE_ADDRESS     0x40037000
#define GPT_32_64_WID_8_BASE_ADDRESS     0x4004C000
#define GPT_32_64_WID_9_BASE_ADDRESS     0x4004D000
#define GPT_32_64_WID_10_BASE_ADDRESS    0x4004E000
#define GPT_32_64_WID_11_BASE_ADDRESS    0x4004F000


typedef struct{
    
        u32 MOSCDIS     :1;
        u32 reserved_1  :3;
        u32 OSCSRC      :2;
        u32 XTAL        :5;
        u32 BYPASS      :1;
        u32 reserved_2  :1;
        u32 PWRDN       :1;
        u32 reserved_3  :3;
        u32 PWMDIV      :3;
        u32 USEPWMDIV   :1;
        u32 reserved_4  :1;
        u32 USESYSDIV   :1;
        u32 SYSDIV      :4;
        u32 ACG         :1;
        u32 reserved_5  :4;

}RCC_BIT_FIELD;
typedef union
{
    u32 reg;
    RCC_BIT_FIELD bit;

}SYS_CTRL_RCC_config;

#define SYS_CTRL_RCC_REG                 ((volatile SYS_CTRL_RCC_config *)(SCB_BASE_ADDRESS+0x060))

#define SYS_CTRL_MOSCCTL_REG                *((volatile u32 *)(SCB_BASE_ADDRESS+0x07C))
#define SYS_CTRL_PLL_STAT                *((volatile u32 *)(SCB_BASE_ADDRESS+0x168)) 

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
/***************************************************NVIC**************************************************************/
typedef struct{

    volatile u32 EN[5];
    volatile u32 RESERVED_1[27];
    volatile u32 DIS[5];
    volatile u32 RESERVED_2[27];
    volatile u32 SET_PED[5];
    volatile u32 RESERVED_3[27];
    volatile u32 CLR_PED[5];
    volatile u32 RESERVED_4[27];
    volatile u32 ACT_INT[5];
    volatile u32 RESERVED_5[59];
    volatile u32 PRI[35];
    volatile u32 RESERVED_6[669];
    volatile u32 SWTRIG;

}NVIC_REGs_CONFIG;

#define NVIC_REGS        ((NVIC_REGs_CONFIG *)(CORTEX_M4_BASE_ADDRESS+0x100))
/****************************************************************************************************************/
/************************************************SYS_CTRL*******************************************************/
typedef struct{

    volatile u32 SYS_CTRL_RESET_REGs[24];
    u32 Reserved_0[40];
    volatile u32 SYS_CTRL_RUN_MODE_GC_REGs[24];
    u32 Reserved_1[40];
    volatile u32 SYS_CTRL_SLEEP_MODE_GC_REGs[24];
    u32 Reserved_2[40];
    volatile u32 SYS_CTRL_DEEP_SLEEP_MODE_GC_REGs[24];
    u32 Reserved_3[104];
    volatile u32 SYS_CTRL_PERIPHERAL_READY_REGs[24];

}SYS_CTRL_config_REGs;
 
 #define SYS_CTRL_REGs         ((SYS_CTRL_config_REGs *)(SCB_BASE_ADDRESS+0x500))
/****************************************************************************************************************/
/*********************************************SCB****************************************************************/
 typedef struct
 {
    volatile u32 INTCTRL;
    volatile u32 VTABLE;
    volatile u32 APINT;
    volatile u32 SYSCTRL;
    volatile u32 CFGCTRL;
    volatile u32 SYSPRI1;
    volatile u32 SYSPRI2;
    volatile u32 SYSPRI3;
    volatile u32 SYSHNDCTRL;
    volatile u32 FAULTSTAT;
    volatile u32 HFAULTSTAT;
    
 }SCB_config_REGs;

 #define SCB_REGs   ((SCB_config_REGs *)(CORTEX_M4_BASE_ADDRESS+0xD04))
/******************************************************************************************************/
/*************************************GPIO*************************************************************/
typedef struct{

    volatile u32 GPIODATA[256];
    volatile u32 GPIODIR;
    volatile u32 GPIOIS;
    volatile u32 GPIOIBE;
    volatile u32 GPIOIEV;
    volatile u32 GPIOIM;
    volatile u32 GPIORIS;
    volatile u32 GPIOMIS;
    volatile u32 GPIOICR;
    volatile u32 GPIOAFSEL;

    u32 Reserved[55];

    volatile u32 GPIODR_2_4_8_R[3];

    volatile u32 GPIO_OD_PU_PD_SL_R[4];
    volatile u32 GPIODEN;
    volatile u32 GPIOLOCK;
    volatile u32 GPIOCR;
    volatile u32 GPIOAMSEL;
    volatile u32 GPIOPCTL;
    volatile u32 GPIOADCCTL;
    volatile u32 GPIODMACTL;

}GPIO_CONFIG_REGs;
 
#define GPIO_A_PRE   ((GPIO_CONFIG_REGs *)(GPIO_PORT_A_APB_BASE_ADDRESS))
#define GPIO_B_PRE   ((GPIO_CONFIG_REGs *)(GPIO_port_B_APB_BASE_ADDRESS))
#define GPIO_C_PRE   ((GPIO_CONFIG_REGs *)(GPIO_port_C_APB_BASE_ADDRESS))
#define GPIO_D_PRE   ((GPIO_CONFIG_REGs *)(GPIO_port_D_APB_BASE_ADDRESS))
#define GPIO_E_PRE   ((GPIO_CONFIG_REGs *)(GPIO_port_E_APB_BASE_ADDRESS))
#define GPIO_F_PRE   ((GPIO_CONFIG_REGs *)(GPIO_port_F_APB_BASE_ADDRESS))

/********************************************************************************************************************/
/*******************************************GPT**********************************************************************/

typedef struct{

    volatile u32 GPTMCFG;
    volatile u32 GPTMT_A_B_MR[2];
    volatile u32 GPTMCTL;
    volatile u32 GPTMSYNC;
    volatile u32 Reserved_1;
    volatile u32 GPTMIMR;
    volatile u32 GPTMRIS;
    volatile u32 GPTMMIS;
    volatile u32 GPTMICR;
    volatile u32 GPTMT_A_B_ILR[2];
    volatile u32 GPTMT_A_B_MATCHER[2];
    volatile u32 GPTMT_A_B_PR[2];
    volatile u32 GPTMT_A_B_PMR[2];
    volatile u32 GPTMT_A_B_R[2];
    volatile u32 GPTMT_A_B_V[2];

}GPT_REGs_CONFIG;

#define GPT0_16_32_BIT_REGs      ((GPT_REGs_CONFIG *)(GPT_16_32_0_BASE_ADDRESS))
#define GPT1_16_32_BIT_REGs      ((GPT_REGs_CONFIG *)(GPT_16_32_1_BASE_ADDRESS))
#define GPT2_16_32_BIT_REGs      ((GPT_REGs_CONFIG *)(GPT_16_32_2_BASE_ADDRESS))
#define GPT3_16_32_BIT_REGs      ((GPT_REGs_CONFIG *)(GPT_16_32_3_BASE_ADDRESS))
#define GPT4_16_32_BIT_REGs      ((GPT_REGs_CONFIG *)(GPT_16_32_4_BASE_ADDRESS))
#define GPT5_16_32_BIT_REGs      ((GPT_REGs_CONFIG *)(GPT_16_32_5_BASE_ADDRESS))

#define GPT0_32_64_WID_BIT_REGs      ((GPT_REGs_CONFIG *)(GPT_32_64_WID_6_BASE_ADDRESS ))
#define GPT1_32_64_WID_BIT_REGs      ((GPT_REGs_CONFIG *)(GPT_32_64_WID_7_BASE_ADDRESS ))
#define GPT2_32_64_WID_BIT_REGs      ((GPT_REGs_CONFIG *)(GPT_32_64_WID_8_BASE_ADDRESS ))
#define GPT3_32_64_WID_BIT_REGs      ((GPT_REGs_CONFIG *)(GPT_32_64_WID_9_BASE_ADDRESS ))
#define GPT4_32_64_WID_BIT_REGs      ((GPT_REGs_CONFIG *)(GPT_32_64_WID_10_BASE_ADDRESS))
#define GPT5_32_64_WID_BIT_REGs      ((GPT_REGs_CONFIG *)(GPT_32_64_WID_11_BASE_ADDRESS))



#endif  /* MCU_HW_H */

/**********************************************************************************************************************
 *  END OF FILE: Mcu_Hw.h
 *********************************************************************************************************************/