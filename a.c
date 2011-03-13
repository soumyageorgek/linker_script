#include <io.h>

int i = 0x01;
int j = 0x00;

main()
{
	WDTCTL = WDTPW | WDTHOLD;

	P1DIR = 0x01;

	P1OUT = i;
	P1OUT = j;
}
