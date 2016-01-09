#include <LPC21xx.H>
#include <stdlib.h>
#include <lpc21xx.h>
void delay()
{
int i;
for(i=0;i<10000;i++);
}
void interrupt_function(void) __irq
{
   IOPIN1=~IOPIN1;
   delay();
   EXTINT=0x01;
}
int main()
{
  IODIR0=0x00000000;
  IODIR1=0xffffffff;
  //PINSEL0=(1<<29);
  PINSEL1=(1<<0);//|(1<<8)|(1<<9)|(1<<29);
  EXTINT=0x01;	 //To select EINT0 pin.Upto 2 external input is available for EIN0(P0.1 and P0.16 in this case)
  //EXTWAKE=0x01;  //To wakeup the processor from Power Down mode
  //EXTMODE=0x00;  //EDGE select mode for EINT0 (0 for LEVEL sensetive)
  //EXTPOLAR=0x00;  //Rising Edge	Sensetive
  VICIntEnable=(1<<14); //Table given page page 103
  VICVectCntl0=0x2E; //0:4-pin14 for EINT0 // 5- 1 for IRQ-mode 
  VICVectAddr0=(unsigned)interrupt_function;
  IOPIN1=0xffffffff;
  while(1);     
} 