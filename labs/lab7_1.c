#include <stdio.h>
#include <ez8.h>


 void init_ports(void);				// declare port initialization function
 void sdelay(unsigned int);			// declare delay function
 void motor (void);					// declare call motor function

 void main(void)
 {
	init_ports();			// initialize ports (function call)
	motor();				// run motor (function call)
 }



 void init_ports(void)		//this function initializes Port D and Port A
 {
	//initialize port A
	PDADDR= 0x02; 			// alt function
	PDCTL= 0x00; 			// no alt function
	PDADDR= 0x01; 			// data dir
	PDCTL= 0xFF; 			// all 8 bits I/P
	PDADDR= 0x03; 			// output ctrl
	PDCTL= 0x00; 			// pushpull only
	PDADDR= 0x00; 			// prevents inadvert changes to the sub registers

	//initialize port G
	PGADDR= 0x02; 			// alt function
	PGCTL= 0x00; 			// no alt function
	PGADDR= 0x01; 			// data dir
	PGCTL= 0x00; 			// all 8 bits O/P you only care about PG0
	PGADDR= 0x03; 			// output ctrl
	PGCTL= 0x00; 			// pushpull only
	PGADDR= 0x00; 			// prevents inadvert changes to the sub registers

 }//end of port initialization


 void sdelay(unsigned int time)
 {
	for(;time>0;time--);						// any condition, greater than 0, decrement

 }//end sdelay

 void motor (void)
 {
	unsigned int hi_time[4]= {300, 500, 800, 150};		// arrays to subtract
	unsigned int choice;								// makes unsigned int
	unsigned int duty_cycle;							// initializes duty cycle
	int period= 1000;									// max delay period

	while (1)
	{

		choice = PDIN & 0x07;				// loops users choice

		switch (choice)						// switch case choice
		{
			case (0x01):					// case 1
				duty_cycle= hi_time[0]; 	// call 1st array in high_time
				break;
			case (0x03):					// case 2
				duty_cycle= hi_time[1];		// calls 2nd array in high_time
				break;
			case(0x07):						// case 3
				duty_cycle= hi_time[2];		// calls 3rd array in high_time
				break;
			default:						// default case
				duty_cycle= hi_time[3];		// calls 4rth array in high_time
		}

	 PGOUT= 0x01;							// designates 0x01 to PGOUT
	 sdelay(dcycle);						// calls dcycle from chosen case
	 PGOUT= 0x00;							// designates 0x00 to PGOUT
	 sdelay(period - dcycle);				// subtract period from duty cycle

	}//end motor function