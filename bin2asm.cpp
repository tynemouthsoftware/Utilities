#include <stdio.h>
#include <assert.h>

// Dave Curran 2023-12-11
// gcc bin2asm.cpp -o bin2asm

int main(int argc, char** argv) 
{
	assert(argc == 2);
	char* fn = argv[1];
	FILE* f = fopen(fn, "rb");
	unsigned int n = 0x4000;
	int c;

	printf("; %s\n", fn);
	printf("\n\t.BYTE\t");
	while(1)
	{
		c = fgetc(f);
		if (c == EOF) break;
		printf("$%.2X", c);
		++n;		
		if(n % 16 == 0)
		{
			printf("\t; $%.4X - $%.4X\n", n-0x10, n-1);
			printf("\t.BYTE\t");
		}
		else
		{
			printf(", ");
		}			
	};

	if(n % 16 == 0)
	{
		printf("\n");
	}
	else
	{
		printf("\t; $%.4X - $%.4X\n", n&0xFFF0, n-1);
	}

	fclose(f);
	printf("\n");
}