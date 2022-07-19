#include "std_types.h"
#include "BIT_MATH.h"
#include "TM4C123GH6PM.h"

#include "INT_Ctrl_interface.h"
#include "INT_Ctrl_private.h"
#include "INT_Ctrl_config.h"


void Init_voidIntCtrl(void)
{
    u8 LOC_i_u8;
    u8 LOC_j_u8;
    u8 LOC_N_u8;

    /* set group_priorty / subgroub priority APINT in SCB*/
    SCB_REGs->APINT = (APINT_REG_KEY|(GROUP_PRIORITY_X_SUBPRIORITY_X<<8));

    /* set group_priorty / subgroub priority in NVIC */
    for(LOC_i_u8=0;LOC_i_u8<MAX_INTRRUPT_NUMBER;LOC_i_u8++)
    {
        LOC_N_u8 = (Intrrupt_u8SET[LOC_i_u8][0])/4;
        LOC_j_u8 = (Intrrupt_u8SET[LOC_i_u8][0]) - 4*LOC_N_u8;

        NVIC_REGS->PRI[LOC_N_u8] |= (Intrrupt_u8SET[LOC_i_u8][1]<<(LOC_j_u8*8+5)) ;
    }
    
    /* Enable/disable IRQ */
    for(LOC_i_u8=0;LOC_i_u8<MAX_INTRRUPT_NUMBER;LOC_i_u8++)
    {
        LOC_N_u8 = Intrrupt_u8SET[LOC_i_u8][0]/32;
        LOC_j_u8 = (Intrrupt_u8SET[LOC_i_u8][0])%32;
        NVIC_REGS->EN[LOC_N_u8] = 1<<( LOC_j_u8 ) ;

    }

        //SCB_REGs->APINT |= APINT_REG_KEY;
    #if WAKE_UP_ON_PENDING == ENABLE
        SCB_REGs->SYSCTRL |= 16;
    #endif

    #if SLEEP_ONISR_EXIT == ENABLE
        SCB_REGs->SYSCTRL |= 2;
    #endif
    #if STACK_ALIGNMENT_ON_EXCEPTION_ENTRY == STACK_8_BYTE_ALIGNED
        SCB_REGs->CFGCTRL |= 1<<9;
    #endif
    #if TRAP_DIV_BY_0 == ENABLE
        SCB_REGs->CFGCTRL |= 1<<4;
    #endif

    #if TRAP_ON_UNALIGNED_ACCESS == ENABLE
        SCB_REGs->CFGCTRL |= 1<<3 ;
    #endif
    #if SW_UNPREVILLEDGE_ACCESS == ENABLE
        SCB_REGs->CFGCTRL |= 1<<1;
    #endif
}