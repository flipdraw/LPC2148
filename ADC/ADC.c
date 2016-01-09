#include <LPC21xx.H>
//home work:-DISPLAY ADC VALUE ON LCD
/*
int main()
{
unsigned int x,i;
VPBDIV=0x01;
PINSEL0=0x800000;
IODIR1=0XFFFFFFFF;
ADCR=0x01200301;	   //0000 0001 0010 0000 0000 0011 0000 0001	//sir 01200401;
while((ADDR&0X80000000)==0x00);
x=((ADDR&0xffc0)>>6);
IOSET0=x;
for(i=0;i<10000;i++);
IOCLR0=x;
}
  */

void delay()
{
 int i;
 for(i=0;i<1000;i++);
}
int main()
 {
  long int x;
  IODIR0=0x0000ffff;
  PINSEL0=0;
  PINSEL1=(1<<22);
  while(1)
     {
	 ADCR=0x0301|(1<<21)|(1<<24);
	 while((ADDR&0x80000000)!=(0x80000000));
	 x=((ADDR>>6)&0x3ff); 
	 IOSET0=x;
	 delay();
	 IOCLR0=x;
	 }
 }
 
