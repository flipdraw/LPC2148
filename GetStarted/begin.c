/*#include <LPC21xx.H>
#include <math.h>
int main()
{
	unsigned int i,j;
	PINSEL0=0x00000000;
	PINSEL1=0x00000000;	
	IODIR0=0xffffffff;
	IODIR1=0xffffffff;
	while(1)
	{
	for(j=0;j<32;j++)
	{
		IOSET0|=(1<<j);
		for(i=0;i<50000;i++);
		IOPIN0=0x000fffff;
		for(i=0;i<50000;i++);
		while(j>=31)
		{
		  IOSET1|=(1<<(j-16));
		for(i=0;i<50000;i++);
		IOCLR1=0xffffffff;
		for(i=0;i<50000;i++);
		j++;
		}
		if(j>=48)j=0;
    }
	return 0;

	}
}
 */
 /*LED_TOGGLE*/
 /*
#include <LPC21xx.H>
#include <math.h>
int main()
{
	PINSEL0=0x00000000;
	PINSEL1=0x00000000;	
	IODIR0=0x0000ffff;
	IODIR1=0xffffffff;
	while(1)
	{
		 if(IOPIN0&(1<<21))IOSET0=0x0000ffff;
		 else IOCLR0=0x0000ffff;
    }
	return 0;	
}
*/
#include <LPC21xx.H>
#include <math.h>
void delay()
{  int i;
for(i=0;i<50000;i++);
}

int main()
{
	PINSEL0=0x00000000;
	PINSEL1=0x00000000;	
	IODIR0=0xffff0000;
	IODIR1=0xffffffff;
	while(1)
	{
		 if(IOPIN0&(1<<0))
		 {
		 IOSET0|=(1<<16)|(1<<18);	   delay();
		 }
		 if(IOPIN0&(1<<1))
		 {
		 IOSET0=(1<<17)|(1<<19);	 delay();
		 }
		 if(IOPIN0&(1<<2))
		 {
		 IOSET0=(1<<17)|(1<<18);    delay();
		 }
		 if(IOPIN0&(1<<3))
		 {
		 IOSET0=(1<<16)|(1<<19);	  delay();
		 }
		 else IOCLR0=0xffff0000;
    	 delay();
	}
	return 0;	
}