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
 IOCLR0=0x01;  //clear rs
 IOCLR0=0x02;   //clear rw
 IOSET0=0x04;	//set enable
 delay();
 IOCLR0=0x04;   //clear enable
 }
 void lcd_data(char value)
 {
 IOSET1=value<<16;			  //sending data to lcd which will be stored in LCD RAM
 IOCLR1=~(value<<16);		  //data sent.
 IOSET0=0x01;  //clear rs
 IOCLR0=0x02;   //clear rw
 IOSET0=0x04;	//set enable
 delay();
 IOCLR0=0x04;   //clear enable
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

int main()
{
int x,y,z,w,val;
IODIR0=0x00000007;
IODIR1=0xffffffff;
PINSEL0=0x00000000;
PINSEL1=0x00000000;
lcd_init();
while(1)
     {
     lcd_cmd(0x01);  delay();//Clear Display Screen       
	/* lcd_cmd(0x02);	  delay();//Return Home
	 lcd_cmd(0x04);   delay();//decrement curser(shift to left)
	 lcd_cmd(0x06);   delay();//Increment curser(shift to right)
	 lcd_cmd(0x05);   delay();//Shift display right
	 lcd_cmd(0x07);	  delay();//shift display left
	 lcd_cmd(0x08);   delay();//Display Off,Cursor Off
	 lcd_cmd(0x0C);	  delay();//Display On,Cursor Off
	 lcd_cmd(0x0A);   delay();//Display Off,Cursor On
	 lcd_cmd(0x0E);   delay();//Display On,cursor No blink
	 lcd_cmd(0x0F);   delay();//Display On cursor blink
	 lcd_cmd(0x10);   delay();//Shift cursor to left
	 lcd_cmd(0x14);  delay(); //Shift cursor to right
	 lcd_cmd(0x18);   delay();//Shift entire display to left
	 lcd_cmd(0x1C);   delay();//Shift entire display to right
	 lcd_cmd(0x80);   delay();//Force Cursor to begining of First Line
	 lcd_cmd(0xC0);   delay();//Force Cursor to begining of Second Line
	 lcd_cmd(0x38);	  delay();//2lines and 5X7 matrix 
	 IODIR0=0x000000f7; //ABCD as output and 1234 as input
	 x=IOSET0=0x000000f0; //ABCD to high and 1234 to low;
	 while(IOPIN0==x);
     w=IOPIN0&0xff0;
	 w=w>>4;
	 lcd_int(w);
	 lcd_str(" ");
	 IOCLR0=0x000000f0;

	 IODIR0=0x00000f07; //ABCD as input and 1234 as output
	 y=IOSET0=0x00000f00; //ABCD to low and 1234 to high
	 while(IOPIN0==y);
	 z=IOPIN0&0xff0;
	 z=z>>4;
	 lcd_int(z);
	 lcd_str(" ");
	 IOCLR0=0x00000f00;

	 val=w&z;
	 //val=~val;
	 lcd_int(val); */
	 lcd_str("RAGHAV");
	  wait();
	  }
}
