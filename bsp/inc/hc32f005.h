#ifndef __HC32F005_H__
#define __HC32F005_H__

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
* Configuration of the Cortex-M0P Processor and Core Peripherals
******************************************************************************/
#define __MPU_PRESENT           0 /* No MPU                                       */
#define __NVIC_PRIO_BITS        2 /* M0P uses 2 Bits for the Priority Levels      */
#define __Vendor_SysTickConfig  0 /* Set to 1 if different SysTick Config is used */

/******************************************************************************
* Interrupt Number Definition
******************************************************************************/
typedef enum IRQn
{
    NMI_IRQn            = -14, /*  2 Non Maskable                            */
    HardFault_IRQn      = -13, /*  3 Hard Fault                              */
    SVC_IRQn            = -5,  /* 11 SV Call                                 */
    PendSV_IRQn         = -2,  /* 14 Pend SV                                 */
    SysTick_IRQn        = -1,  /* 15 System Tick                             */
    
    PORT0_IRQn          = 0 ,
    PORT1_IRQn          = 1 ,
    PORT2_IRQn          = 2 ,
    PORT3_IRQn          = 3 ,
    UART0_IRQn          = 6 ,
    UART1_IRQn          = 7 ,
    SPI_IRQn            = 10,
    I2C_IRQn            = 12,
    TIM0_IRQn           = 14,
    TIM1_IRQn           = 15,
    TIM2_IRQn           = 16,
    TIM4_IRQn           = 18,
    TIM5_IRQn           = 19,
    TIM6_IRQn           = 20,
    PCA_IRQn            = 21,
    WDT_IRQn            = 22,
    ADC_IRQn            = 24,
    VC0_IRQn            = 26,
    VC1_IRQn            = 27,
    LVD_IRQn            = 28,
    FLASH_RAM_IRQn      = 30,
    CLK_TRIM_IRQn       = 31,
    
    
} IRQn_Type;


#include <stdint.h>

#define SUCCESS         (0)
#define ERROR           (-1)

#ifndef NULL
#define NULL            (0)
#endif


/******************************************************************************/
/*                Device Specific Peripheral Registers structures             */
/******************************************************************************/

#if defined ( __CC_ARM   )
#pragma anon_unions
#endif



#ifdef __cplusplus
}
#endif

#endif /* __HC32F005_H__ */

