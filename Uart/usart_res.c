#include<lpc21xx.h>
void main()
{
IODIR1=0XFF0000;
VPBDIV=0x01;   		//VPBCL 1 
PINSEL0=0X05;		  //PINSEL  1010
U0LCR=0X83;			 // DLAB  1
U0DLL=65;			//Divisor Latch LSB
U0DLM=0;
U0LCR=0X03;			// 0000 0011:,0000 Disable access to Divisor Latches,0011 8 bit character length

while((U0LSR&0x01)==0x00);
IOSET1=U0RBR<<16;			//DATA
//U0LCR=0X04;			//Stop Bit Select
while(1);
}