#include <LPC21xx.H>
void delay()
	{
	int i;
	for(i=0;i<50000;i++);
	}
int main()
{
	PINSEL0=0x00000000;
	PINSEL1=0x00000000;	
	IODIR0=0xffffffff;
	while(1)
	{		 
		IOSET0=(1<<1)|(1<<2); delay();	IOCLR0=(1<<1)|(1<<2);
		IOSET0=(1<<0)|(1<<1)|(1<<3)|(1<<4)|(1<<6);	  delay();	 IOCLR0=(1<<0)|(1<<1)|(1<<3)|(1<<4)|(1<<6);
		IOSET0=(1<<0)|(1<<1)|(1<<6)|(1<<2)|(1<<3);		delay();	 	IOCLR0=(1<<0)|(1<<1)|(1<<6)|(1<<2)|(1<<3);
		IOSET0=(1<<5)|(1<<6)|(1<<1)|(1<<2);			  delay();			 	IOCLR0=(1<<5)|(1<<6)|(1<<1)|(1<<2);
		IOSET0=(1<<1)|(1<<5)|(1<<6)|(1<<2)|(1<<3);	 delay();					IOCLR0=(1<<1)|(1<<5)|(1<<6)|(1<<2)|(1<<3);
		IOSET0=~(1<<1);							   delay();		   	IOCLR0=~(1<<1);			
		IOSET0=(1<<0)|(1<<1)|(1<<2);			  delay();		   	IOCLR0=(1<<0)|(1<<1)|(1<<2);
		IOSET0=0xff;							delay();		IOCLR0=0xff;
		IOSET0=~(1<<4);							delay();		 IOCLR0=~(1<<4);
		IOSET0=0xffffffff;
		delay();
		IOCLR0=0xffffffff;	
		delay();	
	}
}
