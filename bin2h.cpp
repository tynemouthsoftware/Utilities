// bin2h
// Dave Curran
// 2022-06-03

// usage
// ./bin2h x.bin > x.h

#include <stdio.h>
#include <assert.h>

int main(int argc, char** argv)
{
	assert(argc == 2);
	char* fn = argv[1];
	FILE* f = fopen(fn, "rb");
	unsigned int n = 0;
	int c;

	printf("// %s\n", fn);
	printf("const unsigned char data[] =\n{\n\t");
	while(1)
	{
		c = fgetc(f);
		if (c == EOF) break;
		printf("0x%.2X", c);
		++n;
		if(n % 8 == 0)
		{
			printf(",\n\t");
			if(n % 256 == 0) printf("\n\t");
		}
		else
		{
			printf(",");
		}
	};
	fclose(f);
	printf("\n};\n");
}

