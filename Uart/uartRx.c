#include <LPC21xx.H>
#include "lcd.h"
int main()
 {
  IODIR0=(1<<0)|(0<<1)|(1<<3)|(1<<4)|(1<<5);
  IODIR1=0xffffffff;
 PINSEL0=0x05;
 VPBDIV=1;  //EXT. Clock=Processor clock
 U0LCR=(1<<7)|(1<<0)|(1<<1);
 U0DLL=65;
 U0DLM=0;
 U0FCR=(1<<0)|(1<<2);	  //FIFO Enabled//Rx data Reset
 U0LCR&=~(1<<7);
 lcd_init();
 while(1)
   {
   // lcd_int(3);
  	while(U0LSR&(1<<0)==(0<<0)); //if there is no data we'll stay here
	lcd_data(U0RBR); //Yeah!!!, We got the data
	  }
 }