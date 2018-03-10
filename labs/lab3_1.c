#include <ez8.h>

 int main(void)
 {

	unsigned char leds = 0x02; 		//store 0x02 in char leds
	unsigned char push_button;		//declare character push_butto
	push_button = 0x00;				//store 0x00 in push_button

	/* Port A Configuration */
	 //alternate function
	 PAADDR = 0x02;					//write cycle into PAADDR
	 PACTL = 0x00;					//disable altfuctions

	 //data directions
	 PAADDR = 0x01;					//write cycle into PAADDR
	 PACTL = 0xF8;					//set pins 2-0 as outputs and 7-3 as inputs

	 //output control
	 PAADDR = 0x03;					//write cycle into PAADDR
	 PACTL = 0x00;					//all outputs set to push-pull

	 //preventative care
	 PAADDR = 0x00; 				//prevents any changes to the subregisters

	/* Port C Configuration */
	 //alternate function
	 PCADDR = 0x02;					//write cyle to port PCADDR
	 PCCTL = 0x00;					//disable alternative functions

	 //data directions
	 PCADDR = 0x01;										// write cyle to port PCADDR
	 PCCTL = 0x01; 										//set data output

	 //preventative care
	 PCADDR = 0x00;										//prevents changes in subregisters

	/* Push Button */
	 PAOUT = leds;
	 while (1)											//loop forever until power is off
	 {
		push_button = PCIN;								//write cycle: makes push_button have variables belonging to PCIN
		push_button = push_button & 0x01;				//mask PCIN with hex01
		if(push_button == 0x00)							//true if push_button is equal to 0x00
		{
			leds=leds^0x07;								// sets an exclusive or operator to switch Red & Green OR just Yellow
			PAOUT=leds;
		}
	 }

 return 0;
 }//end main