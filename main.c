/*
 * main.c
 *
 *  Created on: Apr 17, 2023
 *      Author: Ahmed Osama
 */
#include<stdint.h>
#include<util/delay.h>
#define DDRA  *((uint8_t*) 0x3A)
#define PORTA *((uint8_t*) 0x3B)
#define PINA  *(( volatile uint8_t*) 0x39)
#define DDRB  *((uint8_t*) 0x37)
#define PORTB *((uint8_t*) 0x38)
#define PINB  *(( volatile uint8_t*) 0x36)
/*
 * Embedded c code to control a 7-segment using two push buttons.
Requirements:
• The two switches are connected to pin 0 & 1 in PORTA.
• If the switch1 is pressed just increase the number appeared
in the 7 segment display, and if the number reach the
maximum number (9) do nothing.
• If the switch2 is pressed just decrease the number appeared
in the 7 segment display, and if the number reach the
minimum number (0) do nothing.
*/
int main(void)
{
uint8_t CathodSeg[]={0x3F,0x06,0x5B,0x4F,
					 0x66,0x6D,0x7D,0x07,
					 0x7F,0x6F}, counter=0;
DDRA  =0x00;//0b0000 0000
PORTA =0x03;//0b0000 0011
DDRB  =0xff;//0b1111 1111
	while(1)
	{
		if(((PINA>>0)&1) ==0 )
			{
		while(((PINA>>0)&1) ==0);
			if(counter<=8)
				{
				counter++;
				PORTB=CathodSeg[counter];
				}else if(counter>=8)counter=8;
			_delay_ms(100);
			}
		if(((PINA>>1)&1) ==0 )
			{
		while(((PINA>>1)&1) ==0);
			if(counter>=1)
				{
				counter--;
				PORTB=CathodSeg[counter];
				}else if(counter<=1)counter=1;
			_delay_ms(100);
			}
	}
}
/*
 * Embedded C code to control a led using a push button.
Requirements:
•The Led 1 & 2 is connected to pin 0 & 1 in PORTA.
• The switch 1 , 2 , 3 is connected to pin 0 & 1 & 2 in PORTB.
• If switch 1 is pressed just turn on the first led1 only , if switch
2 is pressed just turn on led2 only , if switch 3 is pressed turn
on the 2 leds .
• In case no switches are pressed both leds are off.
*/

/*
int main(void)
{
	DDRA  =0x03;//0b0000 0011
	DDRB  =0x00;//0b0000 0000
	PORTB =0x07;//0b0000 0111
	while(1)
	{
		if(((PINB>>0)&1)==0)
			{
				PORTA|=(1<<0);
				while(((PINB>>0)&1)==0);
			}
		else if (((PINB>>0)&1)==1)			PORTA &=~(1<<0);

		if(((PINB>>1)&1)==0)
			{
				PORTA|=(1<<1);
				while(((PINB>>1)&1)==0);
			}
		else if (((PINB>>1)&1)==1)			PORTA &=~(1<<1);

		if(((PINB>>2)&1)==0)
			{
				PORTA|=(1<<0);
				PORTA|=(1<<1);
			while(((PINB>>2)&1)==0);
			}
		else if (((PINB>>2)&1)==1)
			{
				PORTA &=~(1<<1);
				PORTA &=~(1<<0);
			}

		_delay_ms(50);
	}
}
*/
