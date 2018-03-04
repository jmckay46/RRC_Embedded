 //#include <stdio.h>			//<-- Standard Input and Output library for C
 #include <ez8.h>				//<-- library for interfacing with Z8




 //int main(void) //!FLAG#1 - comment out if function does not require return 0;
 void main(void)  //!FLAG#1 - comment out if function requires return 0;
 {

	//create local variable 'leds' to be data 0x05
	unsigned char leds = 0x05;	//<-- [Play with the hex value] Hint: h5=b101

	/*- PORT A CONFIGURATION -*/
	 //alternate function
	 PAADDR = 0x02;				//<-- write cycle into PAADDR (0x0FDO)
	 PACTL = 0x00;				//<-- disable dem' alternative functions bra'

	 //data directions
	 PAADDR = 0x01;				//<-- write cycle into PAADDR (0x0FDO)
	 PACTL = 0xF8;				//<-- set pins 2 to 0 outputs, 7 to 3 inputs

	 //output controll
	 PAADDR = 0x03;				//<-- write cycle into PAADDR (0x0FDO)
	 PACTL = 0x00;				//<-- makes all outputs push-pull

	 //preventative-care
	 PAADDR = 0x00;				//<-- prevents any changes to sub-regs

	 //assign local variable 'leds' to PAOUT constant
	 PAOUT = leds;				//<-- write cycle to PAOUT (0x0FD3)

 	 //return 0; //!FLAG#1 - comment out if int main(void) is not in use
 }
/*-- 			END MAIN FUNCTION 			--*/
