#include<ez8.h>
#include<stdio.h>

#define DATA_DIR 0x01
#define ALT_FUN 0x02
#define OUT_CTL 0x03

void init_ports(void);                      //initializes port E as o/p - pushpull configuartion
void delay_ms(unsigned int);
void char rd_busy();

void main(void)
{
    init_ports();

    PEADDR = DATA_DIR;
    PECTL = 0xF0;                           //set 4 MSb's as inputs
    PEADDR = 0x00;

    while(rd_busy() == 1)
    {
        ;
    }

}

void init_ports(void)
{
    PEADDR = ALT_FUN;
    PECTL = 0x00;

    PEADDR = DATA_DIR;
    PECTL = 0x00;

    PEADDR = OUT_CTL;
    PECTL = 0x00;

    PEADDR = 0x00;
}//end init_ports


//void delay_ms is still in the works. Need to figure a bit of math out.

void delay_ms(unsigned int time_ms)
{
    delay = 1000 * time_ms;

    while(time_ms > 0)
    {
        while(delay >0)
        {
            delay --;
        }
        time_ms--;
    }
}

//this function returns the status of rd_busy as a char-> returns the busy_status

unsigned char rd_busy()
{
    unsigned char busy_flag = 0x00;
    unsigned char busy_status;

    PEOUT = 0x02;                           //Set LCD's R -> high for reading the LCD
    PEOUT = 0x0A;                           //Pulse the Enable while R is -> high

    busy_flag = PEIN;                       //store the contents of PE in busy_flag
    busy_flag &= 0x80;

    PEOUT = 0x02;                           //Set R high again, according to data sheet
    PEOUT = 0x0A;                           //Pulse the Enable while R is -> high
    PEOUT = 0x02;                           //Set R high

    if(busy_flag == 0x00)
    {
        busy_status = 0;
    }
    else
    {
        busy_status = 1;
    }

    return(busy_status);
}






















