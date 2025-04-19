/*
 * File:   LED.c
 * Author: VISHAL
 *
 * Created on 18 April, 2025, 2:37 PM
 */

// LED.c
#pragma config FOSC = EXTRC     // Oscillator Selection bits (RC oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

#include <xc.h>
#define _XTAL_FREQ 6000000
#include "Seven_Segment.h"

char arr[9] = {0, 1, 2, 4, 8, 16, 32, 64, 128};

void run()
{
    for (int i = 0; i < 9; i++)
    {
        PORTB = arr[i];
        __delay_ms(500);
    }
}

void blink()
{
    PORTB = 0xff;
    __delay_ms(500);
}

void main(void)
{
    TRISB = 0x00;  // Set PORTB as output
    PORTB = 0x00;  // Set PORTB to 0 initially

    displayNumbers();  // Call the function to display numbers on the 7-segment display
}
