#ifndef INT_CTRL_CONFIG_H
#define INT_CTRL_CONFIG_H

/*
    Options:-

        GROUP_PRIORITY_8_SUBPRIORITY_1 
        GROUP_PRIORITY_4_SUBPRIORITY_2 
        GROUP_PRIORITY_2_SUBPRIORITY_4 
        GROUP_PRIORITY_1_SUBPRIORITY_8 
*/
#define GROUP_PRIORITY_X_SUBPRIORITY_X      GROUP_PRIORITY_1_SUBPRIORITY_8
/**********************************************************************************************************************/
#define MAX_INTRRUPT_NUMBER     2  

u8 Intrrupt_u8SET[MAX_INTRRUPT_NUMBER][2] = {{Bit_Timer_16_32_0A,GROUP_PRIORITY_0_SUBPRIORITY_0},
											{Bit_Timer_16_32_1A,GROUP_PRIORITY_0_SUBPRIORITY_1}};
/**********************************************************************************************************************/

/*
    Options:-

        -STACK_4_BYTE_ALIGNED
        -STACK_8_BYTE_ALIGNED
*/

#define STACK_ALIGNMENT_ON_EXCEPTION_ENTRY      STACK_8_BYTE_ALIGNED
/**********************************************************************************************************************/
/*
    Options:-

    -DISABLED
    -ENABLE
*/  
#define TRAP_DIV_BY_0                           DISABLED

#define WAKE_UP_ON_PENDING                      DISABLED

#define SLEEP_ONISR_EXIT                        DISABLED

#define TRAP_ON_UNALIGNED_ACCESS                DISABLED 

#define SW_UNPREVILLEDGE_ACCESS                   ENABLE
/**********************************************************************************************************************/



/**********************************************************************************************************************/

#endif