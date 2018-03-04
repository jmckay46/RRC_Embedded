
 #include <ez8.h>

/*-- 				PROTOTYPES					--*/
 void init_ports(void);		// port initialization
 void sdelay(unsigned int);	// call delay function
 void motor (void);			// call motor function


/*-- 			START MAIN FUNCTION 			--*/
 void main(void)
 {
	init_ports();			// initialize ports (function call)
	motor();				// run motor (function call)
 }



/*-- 			PORT FUNCTION				--*/
 void init_ports(void)
 {
	/*-- Initialize Port A --*/
	PDADDR= 0x02; 			// alt function
	PDCTL= 0x00; 			// no alt function
	PDADDR= 0x01; 			// data dir
	PDCTL= 0xFF; 			// all 8 bits I/P
	PDADDR= 0x03; 			// output ctrl
	PDCTL= 0x00; 			// pushpull only
	PDADDR= 0x00; 			// prevents inadvert changes to the sub registers

	/*-- Initialize Port G --*/
	PGADDR= 0x02; 			// alt function
	PGCTL= 0x00; 			// no alt function
	PGADDR= 0x01; 			// data dir
	PGCTL= 0x00; 			// all 8 bits O/P you only care about PG0
	PGADDR= 0x03; 			// output ctrl
	PGCTL= 0x00; 			// pushpull only
	PGADDR= 0x00; 			// prevents inadvert changes to the sub registers
 }
/*-- 			END PORT FUNCTION				--*/

/*-- 			DELAY FUNCTION				--*/
 void sdelay(unsigned int time)
 {
	for(;time>0;time--) 	// any condition, greater than 0, decrement
		;					// destroy all humans
 }
/*-- 			END DELAY FUNCTION				--*/

/*-- 			START MOTOR FUNCTION				--*/
 void motor (void)
 {
	unsigned int hi_time[4]= {300, 500, 800, 150};			 // arrays to subtract
	unsigned int choice;									// makes unsigned int
	unsigned int dcycle;									// initializes duty cycle
	int period= 1000;										// max delay period

	while (1)
	{

		choice = PDIN& 0x07;		// loops users choice

		switch (choice)				// switch case choice
		{
			case (0x01):			// case 1
				dcycle= hi_time[0]; // call 1st array in high_time
				break;
			case (0x03):			// case 2
				dcycle= hi_time[1];	// calls 2nd array in high_time
				break;
			case(0x07):				// case 3
				dcycle= hi_time[2];	// calls 3rd array in high_time
				break;
			default:				// default case
				dcycle= hi_time[3];	// calls 4rth array in high_time
		}

	 PGOUT= 0x01;					// designates 0x01 to PGOUT
	 sdelay(dcycle);				// calls dcycle from chosen case
	 PGOUT= 0x00;					// designates 0x00 to PGOUT
	 sdelay(period - dcycle);		// subtract period from duty cycle
	}