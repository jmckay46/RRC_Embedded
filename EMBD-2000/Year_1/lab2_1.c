#include <ez8.h>


 void main(void)
 {
	unsigned char leds = 0x05;					//store 0000|0110 into leds

	/* Port A Configuration*/
	 //disable alternative functon
	 PAADDR = 0x02;								// write cycle into PAADDR (0x0FDO)
	 PACTL = 0x00;								// disable alternative functions

	 //data directions
	 PAADDR = 0x01;								//write cycle into PAADDR (0x0FDO)
	 PACTL = 0xF8;								//set pins 2 to 0 outputs, 7 to 3 inputs

	 //output controll
	 PAADDR = 0x03;								//write cycle into PAADDR (0x0FDO)
	 PACTL = 0x00;								//make all outputs push-pull

	 //preventative-care
	 PAADDR = 0x00;								//prevents any changes to sub-registers

	 //assign 'leds' to PAOUT
	 PAOUT = leds;								//write cycle to PAOUT (0x0FD3)

 }//end main
