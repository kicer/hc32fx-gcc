#include <stdint.h>
#include "hc32fx.h"
#include "hc32fx_bare.h"


volatile uint32_t systick = 0;
volatile uint32_t core_clock_hz = 4000000; /* 4MHz */

#define LED_PIN   5

int main (void) {
    SysTick_Config( core_clock_hz / 1000 );

    CLOCK_PERI_CLKEN |= BIT(CLKEN_PERI_GPIO);
    P1_ADS &= ~BIT(LED_PIN);
    P1_DIR &= ~BIT(LED_PIN);
    P1_OUT &= ~BIT(LED_PIN);

/* offical op code
    M0P_CLOCK->PERI_CLKEN_f.GPIO = 1;
    M0P_GPIO->P15_SEL = 0;
    M0P_GPIO->P1DIR_f.P15 = 0;
    M0P_GPIO->P1PU_f.P15 = 0;
    M0P_GPIO->P1OUT_f.P15 = 0;
*/

    while(1) {
        uint32_t next = systick + 1000;
        while(systick<next) {
            __asm__("WFI");
        }
        P1_OUT ^=  BIT(LED_PIN);
    }

    return 0;
}


void SysTick_IRQn_handler(void) {
  ++systick;
}
