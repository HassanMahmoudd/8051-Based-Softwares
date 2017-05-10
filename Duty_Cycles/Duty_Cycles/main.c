//	Mahmoud Gamal	    2640
//	Hassan Mahmoud		2811
//	Ahmed Oraby				3121

#include <at89c51xd2.h>
#include <stdio.h>
#include <math.h>

sbit LED = P2^0;
sbit ERROR = P2^6;
sbit SW = P2^7;

void timer_delay(int t)
{  
		t = 65536 - t;
		TL0 = t & 0x00FF;
		TH0 = (t & 0xFF00) >> 8;
		TR0 = 1;
	  while(TF0 == 0);
		TR0 = 0;
		TF0 = 0;
}

int convert_BCD()
{		unsigned char number; 
		unsigned char nLow = 0;
		unsigned char nHigh = 0;
		nLow = (P1 & 0x0F);
		nHigh = (P1 & 0xF0) >> 4;
	if (nLow > 9 || nHigh > 9) 
		{
			ERROR = 0;
			return 0;
		}
		ERROR = 1;
		number = nHigh*10 + nLow;
		return number;
	
}

void main()
{
	 int cycleTime = 35;
	 int input;

	 P3 = 0x00;
	 SW = 1;
	 LED = 1;						// Turn off LED
	 P1 = 0xFF;					// Set Port 1 as Input
	 TMOD =	0x01;  			//setup Timer 0	Mode 1
	 while( 1 )
	 {
			while(SW == 0)
			{
				input = convert_BCD();
				if(input == 0)
				{LED=0;break;}
				LED = 1;
				timer_delay((input * cycleTime));
				LED = 0;
				timer_delay(((100 - input) * cycleTime));	
			}
					 
	}
}