#include <at89c51xd2.h>

sbit LED = P2^0;
sbit ERROR = P2^1;

int count = 0;

unsigned char pass[4] = {3,9,0,5};
unsigned char result[4];

void delay(void)
{
	int i,j;
	for(i = 0; i < 1000; i++)
	{
		for(j = 0; j < 1000; j++) ;
	}
}

int checkPass(void)
{
	if(result[count - 1] == pass[count - 1])
		return 1;
	return 0;
}

void external_interrupt (void) interrupt 0
{
	unsigned char temp;
	
	temp = P1 & 0x0F;
	
	if(temp == 0x0A)
		temp = 0x00;
	
	result[count] = temp;
	
	if(result[count] != pass[count])
	{
		ERROR = 1;
		delay();
		ERROR = 0;
	}
	else
		count++;   
	
}

void main (void)
{
	int res;
	
	P1 = 0xFF;
	
	IT0 = 1;											
	EX0 = 1;                      
	EA = 1;                      
	
	LED = 0;
	ERROR = 0;
	
	while (1)
	{
			if(count == 4)
			{	
				res = checkPass();
				
				if(res)
					LED = 1;
				
				delay();
				LED = 0;
				count = 0;
			}
  }
}