#ifndef LCD_H
#define LCD_H

#define DATA_DIR 0x01
#define ALT_FUN 0x02
#define OUT_CTL 0x03

void init_ports(void);                      
void delay_ms(unsigned int);
void cmd_write(unsigned char);
void data_write(unsigned char);
void soft_reset(void);
unsigned char rd_busy();
void lcd_ready();
void init_lcd();

void init_ports(void)
{
    PEADDR = ALT_FUN;
    PECTL = 0x00;

    PEADDR = DATA_DIR;
    PECTL = 0x00;

    PEADDR = OUT_CTL;
    PECTL = 0x00;

    PEADDR = 0x00;
	return;
	
}//end init_ports

void delay_ms(unsigned int time_ms)
{
   unsigned int delay;

    while(time_ms > 0)
    {
		time_ms --;
		delay = 0xA7;
		
        while(delay >0)
        {
            delay --;
        }
    }
}

void init_lcd()
{
	soft_reset();
	
	lcd_ready();
	cmd_write(0x28);		
	
	lcd_ready();					
	cmd_write(0x0F);			
	
	lcd_ready();
	cmd_write(0x06);
	
	lcd_ready();
	cmd_write(0x01);		
	
}

void soft_reset()
{
	delay_ms(16);
	PEOUT = 0x30;
	PEOUT = 0x38;
	delay_ms(1);
	PEOUT = 0x30;

	delay_ms(5);
	PEOUT = 0x30;
	PEOUT = 0x38;
	delay_ms(1);
	PEOUT = 0x30;

	delay_ms(1);
	PEOUT = 0x30;
	PEOUT = 0x38;
	delay_ms(1);
	PEOUT = 0x30;
	
	delay_ms(1);
	PEOUT = 0x20;
	PEOUT = 0x28;
	delay_ms(1);
	PEOUT = 0x20;
}

//this function returns the status of rd_busy as a char
unsigned char rd_busy()
{
    unsigned char busyflag = 0x00;
    unsigned char busy;

    PEOUT = 0x02;                           //Set LCD's R -> high for reading the LCD
    PEOUT = 0x0A;                           //Pulse the Enable while R is -> high

    busyflag = PEIN;                       //store the contents of PE in busy_flag
    busyflag = busyflag&0x80;

    PEOUT = 0x02;                           //Set R high again, according to data sheet
    PEOUT = 0x0A;                           //Pulse the Enable while R is -> high
    PEOUT = 0x02;                           //Set R high

    if(busyflag == 0x0)
    {
        busy=0;
    }
    else
    {
        busy=1;
    }

    return(busy);
}

void lcd_ready()
{
	PEADDR = DATA_DIR;
	PECTL = 0xF0;
	PEADDR = OUT_CTL;
	PEADDR = 0x00;
	
	PEADDR = 0x00;
	
	while(rd_busy()==1)
	{
		;
	}
	init_ports();
}

void cmd_write(unsigned char val)
{
	char high_nib;
	char low_nib;
	
	high_nib = val&0xF0;	
	
	//shift val 4 places to the left and assign it to low_nib
	low_nib = val<<4;
	
	lcd_ready();
	
	PEOUT = 0x00;
	
	PEOUT = high_nib;
	PEOUT = high_nib^0x08;
	delay_ms(1);
	PEOUT = high_nib;
	
	PEOUT = low_nib;
	PEOUT = low_nib^0x08;
	delay_ms(1);
	PEOUT = low_nib;
}

void data_write(unsigned char dataval)
{
	char highnib;
	char lownib;
	
	highnib = (dataval&0xF0)|0x04;
	lownib = (dataval<<4)|0x04;
	
	lcd_ready();
	
	PEOUT = 0x04;
	
	PEOUT = highnib;
	PEOUT = highnib^0x08;
	delay_ms(1);
	PEOUT = highnib;
	
	PEOUT = lownib;
	PEOUT = lownib^0x08;
	delay_ms(1);
	PEOUT = lownib;
}

#endif //LCD_H
