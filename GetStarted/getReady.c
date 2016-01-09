#include <LPC214X.H>
int main()
{
int i;
IODIR0=0xff;
while(1)
   {
   IOSET0=0xff;
   for(i=0;i<1000000;i++);
   IOCLR0=0xff;
   for(i=0;i<1000000;i++);
   }
}