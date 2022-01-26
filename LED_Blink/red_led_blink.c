/*==========================================
 Title:  LED Blink Program for TM4C123G
 Author: Amith G Nair
 Date:   7 Jan 2021
========================================== */
#include <stdint.h>
// Header file is included in TivaWare for C Series Software  : Downoad from https://www.ti.com/tool/SW-TM4C 
#include "C:\ti\TivaWare_C_Series-2.1.4.178\inc\tm4c123gh6pm.h"

void delayMs(int n);
int main(void)
{
    /* enable clock to GPIOF at clock gating control register */
    SYSCTL_RCGCGPIO_R |= 0x20;
    /* enable the GPIO pins for the LED (PF1) as output */
	/* replace 0x02 with 0x04 for PF2( Blue led) */
	/* replace 0x02 with 0x08 for PF3( Green  led) */
    GPIO_PORTF_DIR_R =  0x02;
    /* enable the GPIO pin PF1 for digital function  by DEN register and with 0x02*/
	/* replace 0x02 with 0x04 for PF2( Blue led) */
	/* replace 0x02 with 0x08 for PF3( Green  led) */
    GPIO_PORTF_DEN_R =  0x02;

    while(1)
    {
        GPIO_PORTF_DATA_R = 0x02;   /* turn on red LEDs */
        delayMs(500);

        GPIO_PORTF_DATA_R = 0;      /* turn off red LEDs */
        delayMs(500);
    }
}
/* delay n milliseconds (16 MHz CPU clock) */
void delayMs(int n)
{
    int i, j;
    for(i = 0 ; i < n; i++)
        for(j = 0; j < 3180; j++)
        {}  /* do nothing for 1 ms */
}

/* This function is called by the startup assembly code to perform system specific initialization tasks. */

void SystemInit(void)
{
    /* Grant coprocessor access */
    /* This is required since TM4C123G has a floating point coprocessor. */
    NVIC_CPAC_R |= 0x00F00000;
}
