// bin2forth
// Dave Curran
// 2022-08-18

// usage
// ./bin2forth x.bin > x.fs

#include <stdio.h>
#include <assert.h>

int main(int argc, char** argv)
{
	assert(argc == 2);
	char* fn = argv[1];
	FILE* f = fopen(fn, "rb");
	unsigned int n = 0;
	int c;

	printf("CODE %s\n", fn);

	while(1)
	{
		c = fgetc(f);
		if (c == EOF)
		{
			break;
		}

		if (c < 10)
		{
			printf("  ");
		}
		else if (c < 100)
		{
			printf(" ");
		}
		printf(" %i c,", c);

		++n;
		if(n % 8 == 0)
		{
			printf("\n");
			if(n % 256 == 0)
			{
				printf("\n");   
			}
		}
	};

	printf("\n\n");
	fclose(f);
}

