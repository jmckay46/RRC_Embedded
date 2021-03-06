#include<stdio.h>
#include<ez8.h>

#define DATA_DIR 0x01
#define ALT_FUN 0x02
#define OUT_CTL 0x03

void init_ports();
void delay(unsigned int);

void main()
{
    init_ports();
    PEOUT = 0xFF;                   //test init_ports
}

//Function initializes Ports E as push/pull-outputs

void init_ports()
{
    PEADDR = ALT_FUN;
    PECTL = 0x00;                   //disable alternatie functions

    PEADDR = DATA_DIR;              //select data direction sub register
    PECTL = 0x00;                   //enable push pull

    PEADDR = OUT_CTL;               //select output control sub register
    PECTL = 0x00;                   //set Port E as ouput

    PEADDR = 0x00;                  //prevent inadvertent change

    return;
}

//the function delays input is the time in msec.

void delay(unsigned int t)
{
    while (t > 0)
    {

    }
}