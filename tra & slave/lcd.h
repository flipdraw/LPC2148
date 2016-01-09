#include<lpc21xx.h>
void _delay_ms(unsigned char x)
{
int i,j;
for(i=0;i<x;i++);
for(j=0;j<250;j++);
}

void lcd_cmd(unsigned char cmd)
{
IOSET1=cmd<<16;
IOCLR1=~cmd<<16;
IOCLR1=0x1000000;
IOSET1=0x2000000;
_delay_ms(10);
IOCLR1=0x2000000;
}


void lcd_data(unsigned char dat)
{
IOSET1=dat<<16;
IOCLR1=~dat<<16;

IOSET1=0x1000000;

IOSET1=0x2000000;
_delay_ms(5);
IOCLR1=0x2000000;
}


void lcd_str(unsigned char *p)
{
while(*p!='\0')
{
lcd_data(*p);
p++;
}
}

void lcd_int(unsigned int y)
{
	unsigned char j=0, a[]={0,0};
	while(y)
	{
		a[j]=y%10;
		y=y/10;
		j++;
	}
	for(j=0;j<2;j++)
	lcd_data(a[1-j]+48);
						}
void lcd_ini()
{
lcd_cmd(0x01);
lcd_cmd(0x38);
lcd_cmd(0x0e);
lcd_cmd(0x80);
}
