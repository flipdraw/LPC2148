#include <LPC21xx.H>
int main()
{
IODIR0=0xffffffff;
PINSEL0=0x00000000;
PINSEL1=0x00000000;
     T0TCR=0x01;   //T0 control register
	 T0PR=0; //Prescaler Register
	// T0TC=   //T0 counter
	// T0MCR
   while(1)
   {
   	   T0TC=0;
	   IOSET0=0xff;
	   while(T0TC<1000000);
	   IOCLR0=0xff;
	   T0TC=0;
	   while(T0TC<10000000);
   }
}
