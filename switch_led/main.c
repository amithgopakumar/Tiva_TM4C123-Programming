/*==========================================
Title:  LED Blink Program for TM4C123G
Author: Amith G Nair
 Date:   18 Jan 2021
==========================================*/
#include <stdint.h>
// Header file is included in TivaWare for C Series Software  : Download from https://www.ti.com/tool/SW-TM4C
#include "inc\tm4c123gh6pm.h"

int main(void)
{
    unsigned int value;
    SYSCTL_RCGCGPIO_R |= 0x20;        // enable the clock for port F
    GPIO_PORTF_DIR_R =  0x02;        // set PF1 as output pin  and PF4 as input
    GPIO_PORTF_DEN_R =   0x12;       // set PF1 and PF4 as Digital pins
    GPIO_PORTF_PUR_R=  0x10;        //enable the pull-up for PF4 pin

    while(1){
        value=GPIO_PORTF_DATA_R;   // READ THE gpiovalue and store in a varible value
        value=~value;              // switch is high so when press it becomes low ,
        value=value>>3;            //right shift the value to 3 make red led on
        GPIO_PORTF_DATA_R=value;   // write the value to led pin
       }
}
void SystemInit(void)
{
    /* Grant co-processor access */
    /* This is required since TM4C123G has a floating point co-processor. */
    NVIC_CPAC_R |= 0x00F00000;
}
