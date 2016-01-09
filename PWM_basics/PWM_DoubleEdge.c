#include <LPC21xx.H>
int main()
{
 VPBDIV=1;	 //external clock=Processor clock
 IODIR0=0xffffffff;
  PINSEL0=(1<<1)|(1<<3)|(1<<15)|(1<<17);		 //Selected from PINSEL table
  PWMMCR=(1<<1);    //Match Control Register
  PWMMR0=100000;
  PWMMR1=50000;
   PWMMR2=30000;
   PWMMR3=60000;
    PWMPR=1; //Prescaler register	  //Division by (PWMPR+1)
  //PWMPC=1; //Prescaler counter 
 PWMPCR=(1<<2)|(1<<3)|(1<<9)|(1<<10)|(1<<11)|(1<<12);  //PWM control register//Mainly to select Singly or Doubly edge PWM
 PWMTCR=0x09;	//used to enable/disable timer/pwm
 // PWMTC=  //PWM timer counts
while(1);	
}