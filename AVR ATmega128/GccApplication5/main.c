#define F_CPU 14745600UL
#define FND_SEL PORTB
#define FND_DB PORTE
#define dTime 1

#include <avr/io.h>
#include <util/delay.h>

//unsigned char DGT[6] = {0xfb, 0xf7};
unsigned char DGT[6] = {0xfe, 0xfd, 0xfb, 0xf7, 0xef, 0xdf};
//unsigned char FND[9][2] = { {0x01, 0x00}, {0x00, 0x01}, {0x00, 0x20}, {0x00, 0x10},
//{0x00, 0x08}, {0x08, 0x00}, {0x04, 0x00},{0x02, 0x00}, {0x01, 0x00}};
unsigned char FND[17][6] = {    {0x01,0x00,0x00,0x00,0x00,0x00}, {0x00,0x01,0x00,0x00,0x00,0x00},
								{0x00,0x00,0x01,0x00,0x00,0x00}, {0x00,0x00,0x00,0x01,0x00,0x00},
								{0x00,0x00,0x00,0x00,0x01,0x00}, {0x00,0x00,0x00,0x00,0x00,0x01},
								{0x00,0x00,0x00,0x00,0x00,0x20}, {0x00,0x00,0x00,0x00,0x00,0x10},
								{0x00,0x00,0x00,0x00,0x00,0x08}, {0x00,0x00,0x00,0x00,0x00,0x08},
								{0x00,0x00,0x00,0x00,0x08,0x00}, {0x00,0x00,0x00,0x08,0x00,0x00},
								{0x00,0x00,0x08,0x00,0x00,0x00}, {0x00,0x08,0x00,0x00,0x00,0x00},
								{0x08,0x00,0x00,0x00,0x00,0x00}, {0x04,0x00,0x00,0x00,0x00,0x00},
								{0x02,0x00,0x00,0x00,0x00,0x00}    };
	
void CPU_Setup() {
	DDRB=0xff;
	DDRE=0xff;
}

int main(void)
{
	CPU_Setup();
	
    while (1) 
    {
		for (unsigned char k=0; k<17; k++) {
			for (unsigned char h=0; h<10; h++) {
				for (unsigned char m=0; m<6; m++) {
					FND_SEL=DGT[m];
					FND_DB=FND[k][m];
					_delay_ms(dTime);
					}
				}
			}
			
		/*	
		for (unsigned char k=0; k<9; k++) {
			for (unsigned char h=0; h<10; h++) {
				for (unsigned char m=0; m<2; m++) {
					FND_SEL=DGT[m];
					FND_DB=FND[k][m];
					_delay_ms(dTime);
				}
			}
		}
		*/
	}
	
}

