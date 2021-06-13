#include <stdint.h>
#include "hc32fx.h"


volatile uint32_t systick = 0;
volatile uint32_t core_clock_hz = 4000000; /* 4MHz */

int main (void) {
    SysTick_Config( core_clock_hz / 1000 );
    while(1);
    return 0;
}


void SysTick_IRQn_handler(void) {
  ++systick;
}
