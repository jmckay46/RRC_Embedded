 //#include <stdio.h>					//<-- Standard Input and Output library for C
 #include <ez8.h>					//<-- library for int1erfacing with Z8
 //#include<myFunctions.h>				//<-- library for future subroutines and identifiers
/*-- 			END HEADER FILES 			--*/



/*-- 			START MAIN FUNCTION 			--*/
 int main(void)//!FLAG#1 - comment out if function does not require return 0;
 //void main(void) //!FLAG#1 - comment out if function requires return 0;
 {
	//variable declarations and assignments;
	unsigned char leds = 0x02; 		//<-- makes 0x02 = leds an unsigned char
	unsigned char push_button;		//<-- makes 0x00 = push_button an unsigned char
	push_button = 0x00;				//<-- makes push_button 0 | used as a var container

	/*- PORT A CONFIGURATION -*/
	 //alternate function
	 PAADDR = 0x02;					//<-- write cycle into PAADDR
	 PACTL = 0x00;					//<-- disable altfuctions

	 //data directions
	 PAADDR = 0x01;					//<-- write cycle into PAADDR
	 PACTL = 0xF8;					//<-- set pins 2-0 as outputs and 7-3 as inputs

	 //output controll
	 PAADDR = 0x03;					//<-- write cycle into PAADDR
	 PACTL = 0x00;					//<-- makes all outputs push-pull

	 //preventative care
	 PAADDR = 0x00; 				//<-- prevents any changes to the subregs

	/*- PORT C CONFIGURATION -*/
	 //alternate function
	 PCADDR = 0x02;					//<-- write cyle to port PCADDR
	 PCCTL = 0x00;					//<-- disable altfunctions

	 //data directions
	 PCADDR = 0x01;					//<-- write cyle to port PCADDR
	 PCCTL = 0x01; 					//<-- set data output

	 //preventative care
	 PCADDR = 0x00;					//<-- prevents and changes to the subregs

	/*-- PUSH BUTTON --*/
	 PAOUT = leds;
	 while (1)					//<-- loops forever till power is off
	 {
		push_button = PCIN;			//<-- write cycle: makes push_button have variables belonging to PCIN
		push_button = push_button & 0x01;	//<-- adds masking to new push_button var
		if(push_button == 0x00)			//<-- true if push_button is equal to 0x00
		{
			leds=leds^0x07;			//<-- sets an exclusive or operator to switch Red & Green OR just Yellow
			PAOUT=leds;
		}
	 }

 return 0;