#include <ez8.h>
#include <stdio.h>

#define BUSY 1
#define READY 0
#define DATA_DIR 0x01
#define ALT_FUN 0x02
#define OUT_CTL 0x03

void init_ports();
void init_lcd();
void delay(unsigned int);
void soft_reset();
void cmd_write(unsigned char);
void data_write(unsigned char);
void lcd_ready();
unsigned char rd_busy();


void main()
{
    init_ports();
    init_lcd();
}

void init_ports()
{
    PEADDR = ALT_FUN;
    PECTL = 0x00;

    PEADDR = DATA_DIR;
    PECTL = 0x00;

    PEADDR = OUT_CTL;
    PECTL = 0x00;

    PEADDR = 0x00;
    return;
}

void delay(unsigned int t)
{
    unsigned int delay;

    while(t>0)
    {
        t--;
        delay = 0xA7;
        while(delay>0)
        {
            delay--;
        }
    }
}

void soft_reset()
{
    delay(15);
    PEOUT = 0x38;
    PEOUT = 0x30;

    delay(5);
    PEOUT = 0x38;
    PEOUT = 0x30;

    delay(1);
    PEOUT = 0x38;
    PEOUT = 0x30;
    PEOUT = 0x28;
    PEOUT = 0x20;
}

void init_lcd()
{
	soft_reset();

	cmd_write(0x28);

	cmd_write(0x0F);

	cmd_write(0x06);

	cmd_write(0x01);
}

void cmd_write(unsigned char val)
{
    unsigned char highnib;
	unsigned char lownib;

    highnib = val&0xF0;
    lownib = val<<4;

	lcd_ready();

    //PEOUT = 0x00;
    PEOUT = highnib | 0x08;
    PEOUT = highnib;

	//PEOUT = 0x00;
	PEOUT = lownib | 0x08;
	PEOUT = lownib;
}

void data_write(unsigned char data)
{
    unsigned char high_nib;
	unsigned char low_nib;

    high_nib = data & 0xF0;
    low_nib = data << 4;

	lcd_ready();

    PEOUT = high_nib | 0x0C;
    PEOUT = high_nib | 0x04;

    PEOUT = low_nib | 0x0C;
    PEOUT = low_nib | 0xF7;
}

void lcd_ready()
{
	while(rd_busy() == BUSY);
    init_ports();
}

unsigned char rd_busy()
{
    unsigned char status;
	PEADDR = DATA_DIR;
	PECTL = 0xF0;

    PEOUT = 0x02;
    PEOUT = 0x0A;

    status = PEIN;
	status = status & 0x80;

    PEOUT = 0x02;
    PEOUT = 0x0A;
    PEOUT = 0x02;

    if(status = 0x80)
    {
        status = READY;
    }
    else
    {
        status = BUSY;
    }

    return(status);
}






























