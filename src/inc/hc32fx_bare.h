#ifndef _HC32Fx_BARE_H_
#define _HC32Fx_BARE_H_


#include <stdint.h>

#define _MEM_(mem_addr)      (*(volatile uint32_t *)(mem_addr))
#define _SFR_(mem_addr)      (*(volatile uint32_t *)((mem_addr)))
#define _SFR16_(mem_addr)    (*(volatile uint16_t *)((mem_addr)))

#define BIT(x)               (1UL << (x))


/* CLOCK */
#define CLOCK_BASE_ADDRESS      0x40002000UL
#define CLOCK_PERI_CLKEN        _SFR_(CLOCK_BASE_ADDRESS+0x20)

#define CLKEN_PERI_GPIO         28


/* GPIO */
#define GPIO_BASE_ADDRESS       0x40020C00UL

/* PORT 0 */
#define P0_BASE_ADDRESS         (GPIO_BASE_ADDRESS+0x100)
#define P0_DIR                  _SFR_(P0_BASE_ADDRESS + 0x00)
#define P0_IN                   _SFR_(P0_BASE_ADDRESS + 0x04)
#define P0_OUT                  _SFR_(P0_BASE_ADDRESS + 0x08)
#define P0_ADS                  _SFR_(P0_BASE_ADDRESS + 0x0C)
#define P0_DR                   _SFR_(P0_BASE_ADDRESS + 0x1C)
#define P0_PU                   _SFR_(P0_BASE_ADDRESS + 0x20)
#define P0_PD                   _SFR_(P0_BASE_ADDRESS + 0x24)
#define P0_OD                   _SFR_(P0_BASE_ADDRESS + 0x2C)
#define P0_HIE                  _SFR_(P0_BASE_ADDRESS + 0x30)
#define P0_LIE                  _SFR_(P0_BASE_ADDRESS + 0x34)
#define P0_RIE                  _SFR_(P0_BASE_ADDRESS + 0x38)
#define P0_FIE                  _SFR_(P0_BASE_ADDRESS + 0x3C)
/* PORT 1 */
#define P1_BASE_ADDRESS         (GPIO_BASE_ADDRESS+0x140)
#define P1_DIR                  _SFR_(P1_BASE_ADDRESS + 0x00)
#define P1_IN                   _SFR_(P1_BASE_ADDRESS + 0x04)
#define P1_OUT                  _SFR_(P1_BASE_ADDRESS + 0x08)
#define P1_ADS                  _SFR_(P1_BASE_ADDRESS + 0x0C)
#define P1_DR                   _SFR_(P1_BASE_ADDRESS + 0x1C)
#define P1_PU                   _SFR_(P1_BASE_ADDRESS + 0x20)
#define P1_PD                   _SFR_(P1_BASE_ADDRESS + 0x24)
#define P1_OD                   _SFR_(P1_BASE_ADDRESS + 0x2C)
#define P1_HIE                  _SFR_(P1_BASE_ADDRESS + 0x30)
#define P1_LIE                  _SFR_(P1_BASE_ADDRESS + 0x34)
#define P1_RIE                  _SFR_(P1_BASE_ADDRESS + 0x38)
#define P1_FIE                  _SFR_(P1_BASE_ADDRESS + 0x3C)
/* PORT 2 */
#define P2_BASE_ADDRESS         (GPIO_BASE_ADDRESS+0x180)
#define P2_DIR                  _SFR_(P2_BASE_ADDRESS + 0x00)
#define P2_IN                   _SFR_(P2_BASE_ADDRESS + 0x04)
#define P2_OUT                  _SFR_(P2_BASE_ADDRESS + 0x08)
#define P2_ADS                  _SFR_(P2_BASE_ADDRESS + 0x0C)
#define P2_DR                   _SFR_(P2_BASE_ADDRESS + 0x1C)
#define P2_PU                   _SFR_(P2_BASE_ADDRESS + 0x20)
#define P2_PD                   _SFR_(P2_BASE_ADDRESS + 0x24)
#define P2_OD                   _SFR_(P2_BASE_ADDRESS + 0x2C)
#define P2_HIE                  _SFR_(P2_BASE_ADDRESS + 0x30)
#define P2_LIE                  _SFR_(P2_BASE_ADDRESS + 0x34)
#define P2_RIE                  _SFR_(P2_BASE_ADDRESS + 0x38)
#define P2_FIE                  _SFR_(P2_BASE_ADDRESS + 0x3C)
/* PORT 3 */
#define P3_BASE_ADDRESS         (GPIO_BASE_ADDRESS+0x1C0)
#define P3_DIR                  _SFR_(P3_BASE_ADDRESS + 0x00)
#define P3_IN                   _SFR_(P3_BASE_ADDRESS + 0x04)
#define P3_OUT                  _SFR_(P3_BASE_ADDRESS + 0x08)
#define P3_ADS                  _SFR_(P3_BASE_ADDRESS + 0x0C)
#define P3_DR                   _SFR_(P3_BASE_ADDRESS + 0x1C)
#define P3_PU                   _SFR_(P3_BASE_ADDRESS + 0x20)
#define P3_PD                   _SFR_(P3_BASE_ADDRESS + 0x24)
#define P3_OD                   _SFR_(P3_BASE_ADDRESS + 0x2C)
#define P3_HIE                  _SFR_(P3_BASE_ADDRESS + 0x30)
#define P3_LIE                  _SFR_(P3_BASE_ADDRESS + 0x34)
#define P3_RIE                  _SFR_(P3_BASE_ADDRESS + 0x38)
#define P3_FIE                  _SFR_(P3_BASE_ADDRESS + 0x3C)


#endif /* _HC32Fx_BARE_H_ */
