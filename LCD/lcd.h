#include <LPC21xx.H>
void wait()
{
int i;
for(i=0;i<5000;i++);
}	  
void delay()
{	 int i;
for(i=0;i<500;i++);
}
void lcd_cmd(char value)
{ 
 IOSET1=value<<16;	    //sending data to lcd which will be stored in LCD RAM
 IOCLR1=~(value<<16);	 //data sent.
 IOCLR0=0x01<<3;  //clear rs
 IOCLR0=0x02<<3;   //clear rw
 IOSET0=0x04<<3;	//set enable
 delay();
 IOCLR0=0x04<<3;   //clear enable
 }
 void lcd_data(char value)
 {
 IOSET1=value<<16;			  //sending data to lcd which will be stored in LCD RAM
 IOCLR1=~(value<<16);		  //data sent.
 IOSET0=0x01<<3;  //clear rs
 IOCLR0=0x02<<3;   //clear rw
 IOSET0=0x04<<3;	//set enable
 delay();
 IOCLR0=0x04<<3;   //clear enable
 }
 lcd_init()
 {
 lcd_cmd(0x38);
 lcd_cmd(0x80);
 lcd_cmd(0x0E);
 lcd_cmd(0x01);
 }
 void lcd_str(char *p)
 {
 int count=0;
 while(*p!='\0')
    {
	lcd_data(*p);
	p++;
    count++;
	if(count>15)
	{
	count=0;
	lcd_cmd(0xC0);
	}
	}
 }
 void lcd_int(int a)
 {
 int i=0,j,arr[32];
 while(a!=0)
  {
  j=a%10;
  a=a/10;
  arr[i]=j;
  i++;  
  }
  i=i-1;
  while(i>=0)
  {
  lcd_data(arr[i]+48);
  i--;
  }
 }

