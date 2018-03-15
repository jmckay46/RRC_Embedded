#include <stdio.h>
#include <ez8.h>

 void main()
 {

	 int val;

	/*Initialize Port E*/
	 PEADDR = 0x02; 		//alt function
	 PECTL = 0x00; 			//no alt function
	 PEADDR = 0x01; 		//data dir
	 PECTL = 0x00; 			//set all 8 bits to O/P
	 PEADDR = 0x03; 		//O/P control function
	 PECTL = 0x00; 			//set to push pull rather than open drain
	 PEADDR = 0x00; 		//prevents inadvertent changes to sub registers

	/*Intializie Port D */
	 PDADDR = 0x02; 		//alt function
	 PDCTL = 0x00; 			//no alt function
	 PDADDR = 0x01; 		//data dir
	 PDCTL = 0xFF; 			//set all 8 bits to I/P
	 PDADDR = 0x00; 		//prevents inadvertent changes to sub registers

	while(1)
		{
		 val = PDIN;		//display I/P from port D on Port E
		 PEOUT = val; 		//display I/P from port D on Port E
		}
 return;
 }