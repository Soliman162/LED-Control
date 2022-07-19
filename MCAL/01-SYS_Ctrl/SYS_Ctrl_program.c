#include "std_types.h"
#include "BIT_MATH.h"
#include "TM4C123GH6PM.h"

#include "SYS_Ctrl_interface.h"
#include "SYS_Ctrl_private.h"
#include "SYS_Ctrl_config.h"

void Init_voidSYS_Ctrl_Clock(void)
{
    #if CLOCK_SOURCE == MOSC_MAIN_OSCILLATOR_16_MHZ
        /*enable main OSC*/
        SYS_CTRL_RCC_REG->bit.MOSCDIS = 0;
		SYS_CTRL_RCC_REG->reg = 0x000000000;
        /*select the input source for OSC*/
        SYS_CTRL_RCC_REG->bit.OSCSRC = 0;
        /* Select the crystal value */
        SYS_CTRL_RCC_REG->bit.XTAL = CRYSTAL_VALUE;
        /* MOSC monitor circuit enable */
        SYS_CTRL_MOSCCTL_REG |= 1;
        /* indecate a crystall connected to the OSC1_OSC2   */
        SYS_CTRL_MOSCCTL_REG &= ~(1<<2);
    #elif   CLOCK_SOURCE == PIOSC_PRECISION_INTERNAL_OSCILLATOR
        SYS_CTRL_RCC_REG->bit.OSCSRC = 1;
    #elif   CLOCK_SOURCE == PIOSC_4_PRECISION_INTERNALL_OSCILLATOR
        SYS_CTRL_RCC_REG->bit.OSCSRC = 2;
    #elif   CLOCK_SOURCE == LIFOSC_LOW_FREQ_INTERNAL_OSCILLATOR
        SYS_CTRL_RCC_REG->bit.OSCSRC = 3;
    #endif

    /*Enable/Disable PLL*/
    #if PLL_STATE == ENABLED
        SYS_CTRL_RCC_REG->bit.PWRDN = 0;
        SYS_CTRL_RCC_REG->bit.BYPASS = 0;
    #elif PLL_STATE == DISABLED
        SYS_CTRL_RCC_REG->bit.BYPASS = 1;
        SYS_CTRL_RCC_REG->bit.PWRDN = 1;
       // while(GET_BIT(SYS_CTRL_PLL_STAT,0)!=1);
    #endif
    /*disable / enable SYSDIV*/
    SYS_CTRL_RCC_REG->bit.USESYSDIV = DIVIDER_STATE;
    SYS_CTRL_RCC_REG->bit.SYSDIV = SSDIV_DIVISOR;
    /*choose sleep mode control*/
    SYS_CTRL_RCC_REG->bit.ACG = SLEEP_MODE_CONTROL;
}

void SYS_Ctrl_voidEnable_Clock_Run_Mode(MODULES_NAME Copy_enumModuleName, MODULE_INDEX Copy_enumModuleIndex)
{
    SYS_CTRL_REGs->SYS_CTRL_RUN_MODE_GC_REGs[Copy_enumModuleName] |= (1<<Copy_enumModuleIndex);
}
