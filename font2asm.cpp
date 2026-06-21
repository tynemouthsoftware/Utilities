#include <stdio.h>
#include <assert.h>

// Dave Curran 2026-06-18

// Build:
// gcc font2asm.cpp -o font2asm

// Usage:
// font2asm font.bin > font.asm

// Example output
// ; Character $1C
// 		.BYTE %00000000		; ........
// 		.BYTE %00111100		; ..OOOO..
// 		.BYTE %01000110		; .O...OO.
// 		.BYTE %01001010		; .O..O.O.
// 		.BYTE %01010010		; .O.O..O.
// 		.BYTE %01100010		; .OO...O.
// 		.BYTE %00111100		; ..OOOO..
// 		.BYTE %00000000		; ........

// Print an 8 bit binary representation of c using c0 for 0 bits and c1 for 1 bits
void printbin(unsigned char c, unsigned char c0, unsigned char c1)
{
	unsigned char mask = 0b10000000;
	while(mask)
	{
		printf("%c", c&mask ? c1 : c0);
		mask >>= 1;
	}
}

// Convert a binary font file with 8x8 bytes per character to an assembly source file with comments
int main(int argc, char** argv) 
{
	assert(argc == 2);
	char* fn = argv[1];
	FILE* f = fopen(fn, "rb");
	unsigned char n = 0x00;
	int c;

	printf("; %s\n", fn);
	while(1)
	{
		printf("\n; Character $%.2X\n", n);

		for (unsigned char line = 0; line < 8; line++)
		{
			c = fgetc(f);
			if (c == EOF) break;

			printf("\t.BYTE %c", '%');
			printbin(c, '0', '1');
			printf("\t\t\t; ");
			printbin(c, '.', 'O');
			printf("\n");
		}

		if (c == EOF) break;

		++n;		
	};

	fclose(f);
	printf("\n");
}