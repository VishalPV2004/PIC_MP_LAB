/*
 * File:   Seven_Segment.c
 * Author: VISHAL
 *
 * Created on 18 April, 2025, 5:58 PM
 */


// CONFIG
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
/*

  Digit | h g f e d c b a | Hex
  -----------------------------
    0   | 0 0 1 1 1 1 1 1 | 0x3F
    1   | 0 0 0 0 0 1 1 0 | 0x06
    2   | 0 1 0 1 1 0 1 1 | 0x5B
    3   | 0 1 0 0 1 1 1 1 | 0x4F
    4   | 0 1 1 0 0 1 1 0 | 0x66
    5   | 0 1 1 0 1 1 0 1 | 0x6D
    6   | 0 1 1 1 1 1 0 1 | 0x7D
    7   | 0 0 0 0 0 1 1 1 | 0x07
    8   | 0 1 1 1 1 1 1 1 | 0x7F
    9   | 0 1 1 0 1 1 1 1 | 0x6F

*/

char arr[10] = {0x3f, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};

void displayNumbers()
{
    PORTB = 0xff;
    
    for(int i = 0 ; i < 10 ; i++)
    {
        PORTB = arr[i];
        __delay_ms(250);
    }
}

