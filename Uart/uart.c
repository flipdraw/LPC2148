//Transmitter
#include <LPC21xx.H>
int main()
 {
      VPBDIV=1;  //Ext. Clock=Processor Clock	
	  PINSEL0=(1<<0)|(1<<2); //Port0.0 as UART0-TxD//pg127
      U0LCR=(1<<7)|(1<<0)|(1<<1);	  //DLAB must be 1.for deciding BaudRate
    //U0LCR decides format of the data
	//8bit Character Length
	//Parity Disable //1 Stop Bit
	U0DLL=11;//BaudRate=XTAL frequency/[16*(U0DLL+U0DLM)]
	U0DLM=0;//Baudrate=9600//U0DLL contains lower 8 bits of Divisor
	//U0DLM contains Higher 8 bits of Divisor
	//U0DLL contains lower 8 bits of Divisor
	U0LCR&=~(1<<7); //DLAB must be 0.For writing data in U0THR
  while(1)
   {
    //U0FCR=1<<0|1<<2;	//	FIFO enabled and Tx data is Reset
   	U0THR='r';		//Data to transmit
	while(U0LSR&(1<<5)!=(1<<5)); U0LSR&=~(1<<5);		 //provides Information of Transmission
   U0THR='a';		//Data to transmit
	while(U0LSR&(1<<5)!=(1<<5)); U0LSR&=~(1<<5);		 //provides Information of Transmission
  U0THR='g';		//Data to transmit
	while(U0LSR&(1<<5)!=(1<<5));  U0LSR&=~(1<<5);		 //provides Information of Transmission
  U0THR='h';		//Data to transmit
	while(U0LSR&(1<<5)!=(1<<5));	 U0LSR&=~(1<<5);	 //provides Information of Transmission
  U0THR='a';		//Data to transmit
	while(U0LSR&(1<<5)!=(1<<5));    U0LSR&=~(1<<5);		 //provides Information of Transmission
  U0THR='v';		//Data to transmit
	while(U0LSR&(1<<5)!=(1<<5));	 U0LSR&=~(1<<5);	 //provides Information of Transmission
 }
 }
	