 #include<stdio.h>
 #include<ez8.h>

 void main (void)
 {
 	long int delay;
 	unsigned char val;
 	unsinged char count = 0;

 	PEADDR = 0X02;          	//alt func
 	PECTL = 0X00;	           //disable alt func
 	PEADDR = 0X01;	          //data address
 	PECTL = 0X00;	           //set to output
 	PEADDR = 0X03;	          //controll function (output)
 	PECTL = 0X00;	           //set pushpull
 	PEADDR = 0X00;	          //prevents changes to sub-register

 	PDADDR = 0X02;	          //alt func
 	PDCTL = 0X00;	           //disable alt func
 	PDADDR = 0X01;          	//data address
 	PDCTL = 0XFF;	           //set to input
 	PDADDR = 0X00;	          //preven changes to sub-registers

 	while(1)
 	{
 		if ((val == 's') && (count > 0x14))
 		{
 			 PEOUT = 's';
 		}
 		else
 		{
 			 PEOUT = count;
 			 for(delay = 375000; delay > 0; delay--);
 			 count++;
 		}
 }
}