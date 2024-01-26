#include<reg51.h>
#define dat P1
sbit rs = P2^0;
sbit en = P2^1;
sbit SCL = P3^0;
sbit SDA = P3^1;
void delay(unsigned int time);
void lcdcmd(unsigned char ch);
void lcddata(unsigned char ch);
void lcdstr(unsigned char *ch);
void i2cdatawrite(unsigned char dat);  //write the data from master to slave
unsigned char i2cdataread(void);       //read the data from slave
void I2Cstart(void);
void I2Cstop(void);
void main()
{
	unsigned char x;
	lcdcmd(0x38);
	lcdcmd(0x0E);
	lcdcmd(0x80);
	lcdstr("welcome guys");
	lcdcmd(0xc0);
	lcdstr("on my project");
	lcdcmd(0x01);
	lcdcmd(0x80);
	lcdstr("I2C PROTOCOL RD/WR");
	lcdcmd(0x01);
	
	
	
	I2Cstart();
	i2cdatawrite(0xA0);  //SLAVE ADDRESS  1010 0000(LSB SHOULD BE ZERO FOR WRITING THE DATA SENDING BY MASTER
	i2cdatawrite(0x00); //REGISTER OR MEMORY ADRRESS

	i2cdatawrite('K');
	I2Cstop();
	
	I2Cstart();
  i2cdatawrite(0xA0);   //SLAVE ADDRESS  1010 0000(LSB SHOULD BE ZERO FOR WRITING THE DATA)
	i2cdatawrite(0x00);   // register address or memory address
	I2Cstart();
	i2cdatawrite(0xA1); // SLAVE ADDRESS 1010 0001(LSB SHOULD BE ONE FOR READING THE DATA) 
	x = i2cdataread();
	lcdcmd(0x80);
	lcddata(x); 
	
	I2Cstop();
	
	while(1);
}
void delay(unsigned int time)
{
	unsigned int i,j;
	for(i=0;i<time;i++)
	{
		for(j=0;j<500;j++)
		{
		}
	}
}
void lcdcmd(unsigned char ch)
{
	dat = ch;
	rs = 0;
	en = 1;
	delay(10);
	en = 0;
}
void lcddata(unsigned char ch)
{
	dat = ch;
	rs = 1;
	en = 1;
	delay(10);
	en = 0;
}
void lcdstr(unsigned char *str)
{
	unsigned loop =0;
	for(loop = 0; str[loop] != '\0'; loop++)
	{
		lcddata(str[loop]);
	}
}
void I2Cstart(void)
{
	SCL = 1;
	SDA = 1;
	delay(10);
	SDA = 0;
	delay(10);
	SCL = 0;
}
void I2Cstop(void)
{
	SCL = 0;
	SDA = 0;
	delay(5);
	SCL = 1;
	delay(5);
	SDA =1;
}

	// WRITE THE DATA FROM MASTER TO SALVE
void i2cdatawrite(unsigned char dat)
{
	unsigned char i;
	
	for(i = 0;i<8;i++)
	{
		SDA = (dat&0x80)? 1 : 0 ;
		SCL = 1 ;
		delay(5);
		SCL = 0;
		dat = dat<<1;
		
	}
	SDA = 1;   
	SCL = 1;
	while(SDA == 1);	// acknowledgement until SDA = 0,THIS SHOULD BE SET BY SLAVE
	SCL = 0;
	delay(5);

}
// READING THE DATA FROM SLAVE
unsigned char i2cdataread(void)
{
	bit readbit;
	unsigned int i;
	unsigned int dat = 0;
	for(i=0;i<8;i++)
	{
		delay(5);
		SCL = 1;
		delay(5);
		readbit = SDA;
		dat = dat<<1;
		dat = (dat | readbit);
		SCL = 0;
		
	}
	SDA = 1; // NEGATIVE ACKNOWLEGMENT BECAUSE WE ARE SENDING ONLY ONE CHAR
	SCL = 1;
	delay(5);
	SCL =0;
  return dat;
}


		
	
	
		
		
	
	
	

	
