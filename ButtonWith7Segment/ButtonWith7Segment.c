/*
 * File:   ButtonBulb.c
 * Author: VISHAL
 *
 * Created on April 19, 2025, 11:46 AM
 */


/*
 * File:   ButtonBulb.c
 * Author: VISHAL
 *
 * Created on April 19, 2025
 */

#include <xc.h>
#define _XTAL_FREQ 6000000

// 7-segment digit patterns for 0?9
char arr[10] = {0x3f, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};

void segmentPut(unsigned char i)
{
    PORTB = arr[i];
    __delay_ms(1000);
}

void main(void)
{
    TRISD = 0xFF;     // RD0 as input
    PORTD = 0x00;

    TRISB = 0x00;   // PORTB as output (not used here, but safe to init)
    PORTB = 0xFF;

    unsigned char i = 0;
    segmentPut(i);

    while (1)
    {
        if (RD0 == 1) // Button pressed (HIGH due to external pull-down logic)
        {
            __delay_ms(50); 
            if (RD0 == 1)
            {
                i++;
                if (i == 10)
                    i = 0;
                segmentPut(i);

                // Wait for button release
                while (RD0 == 1);
                __delay_ms(50);
            }
        }
    }
}