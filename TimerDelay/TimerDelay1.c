#include <LPC21xx.H>
int main()
 {
 IODIR0=0xff;
 T0TCR=0x01;
 T0PR=0;
 T0MCR=0x03; //flag of MR0(interrupt) should be called when Timer Counter reaches MR0 and MR0 should be reset after each loop
 T0MR0=1000000;
    while(1)
	{
	IOSET0=0xff;
	T0MCR=0x03; //flag of MR0(interrupt) should be called when Timer Counter reaches MR0 and MR0 should be reset after each loop
    while(~(T0IR&(1<<0x01))); //MR0 flag will be called when Timer Counter reaches MR0
	IOCLR0=0xff;
    T0MCR=0x03; //flag of MR0(interrupt) should be called when Timer Counter reaches MR0 and MR0 should be reset after each loop
    while(~(T0IR&(1<<0x01)));
	}
}
