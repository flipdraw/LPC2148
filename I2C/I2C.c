#include <LPC21xx.H>
int i;
void led()
{
int i;
IOSET1=0xffffffff;
for(i=0;i<50000;i++);
IOCLR1=0xffffffff;
for(i=0;i<50000;i++);
}
void start()
 {
 /*BEFORE ENTERING MASTER TRANSMITTER MODE*/
   //I2CONSET must be initialized
   //I2EN=1 TO ENABLE I2C
   //STA,STO,SI must 0
   //SI bit is cleared by writing SIC=1
    I2CONSET=1<<5;
   	//I2SCLL=26;
    //I2SCLH=24;
  //  I2CONCLR=1<<3;
  // while(I2CONSET&0x08==0x00);
 }
void stop()
 {
 I2CONSET=1<<5;	 //ErROR
 I2CONCLR=1<<3;
 while(I2CONSET&0x08==0x00);
 }
void MTX(int x,int addr)	//Master as Transmitter(to transmit 8 bit data x)
  {
    start();
   /*ENTERING MASTER TRANSMITTER MODE*/
   //STA=1 SI=1 send I2DAT then SIC=1(to clear SI)
	I2DAT=(addr<<1);//	led();
	I2CONCLR=1<<3;
	while(I2CONSET&0x08==0x00);
	I2CONCLR=1<<3;
	while(I2CONSET&0x08==0x00);
   //first byte transmitted contains slave address(Receiving Device)+DDB[0 for writing](Data Direction Bit)
   //After each byte(8bit) data	transmission ACKNOWLEDGE bit is received
   I2DAT=x;	//transmitted or received data bits
   I2CONCLR=1<<3;
   while(I2CONSET&0x08==0x00);
   stop();
   for(i=0;i<10000;i++);
  }
void MRX()	//Master as Receiver
  {
  }
int main()
 {
 IODIR1=0xffffffff;
 VPBDIV=1;
 PINSEL0=1<<4|1<<6;
 PINSEL1=0;
    I2CONSET=1<<6;
   	I2SCLL=4;
    I2SCLH=8;
  MTX(28,0x20);
   while(1); 
 }