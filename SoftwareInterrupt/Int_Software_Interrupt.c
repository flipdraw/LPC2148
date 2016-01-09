//Timer Interrupt(Software interrupt)
#include <LPC21xx.H>																																																																																  	  																																																																																														
void delay()
  {
  int i;
  for(i=0;i<10000;i++);
  }
void function()
  {
  int j;
   for(j=0;j<20;j++)
   {
    IOSET1=0xffffffff;
    delay();
    IOCLR0=0xffffffff;
   }
  }
int main()
{
  IODIR0=0xffffffff;
  IODIR1=0xffffffff;
  PINSEL0=;
  PINSEL1=;																																																																																																																																																																																																																																							 	
  VICIntSelect=	//which of the interrupt is contributing as FIQ or IRQ
  VICVectAddr0=(unsigned)function;
  VICVectCntl0=		  //page 103
  VICSoftInt=       //
  VICIntEnable=
  VICIntSelect=  //1=>FIQ //0=>IRQ																																																																																																																																						
}