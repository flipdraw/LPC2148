#include"lcd.h"
int i;

void start(unsigned char x)
{
I2CONSET=x;				//10 0000 START
while((I2CONSET&0X08)==0X00);
}

void data(unsigned char x)
{
I2DAT=x;	   			//	   SLAVE ADD & data.
I2CONCLR=0X08;
while((I2CONSET&0X08)==0X00);
}

void stop(unsigned char x)
{
I2CONSET=x;			  	//STOP
I2CONCLR=0X08;
for(i=0;i<210;i++);
}

void main()
{
char X[]={"sumit"},b;
IODIR1=0XFFFFFFFf;
PINSEL0=0X50;			 //PIN SET
I2CONSET=0x44;						//SCL Duty Cycle Register Low Half Word
I2ADR=0X02;							 // slave add.
lcd_ini();
while(1)
{
//lcd_cmd(0x01);
while((I2CONSET&0X08)==0X00); 		//ADD. POLLING
for(b=0;b<5;b++)
{
I2DAT=X[b];
I2CONCLR=0X08;	   			//	   SLAVE ADD & data.
while((I2CONSET&0X08)==0X00);					  //DATA POLLING
}

lcd_str("123");

}

}