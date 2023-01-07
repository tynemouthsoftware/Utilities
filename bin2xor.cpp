// bin2xor
// Dave Curran
// 2022-07-29

// usage
// ./bin2xor x.bin

#include <stdio.h>
#include <assert.h>

int main(int argc, char** argv)
{
	assert(argc == 2);
	char* fn = argv[1];
	FILE* f = fopen(fn, "rb");
	unsigned int n = 0;
	int c;

    unsigned char x = 0;

	while(1)
	{
		c = fgetc(f);
		if (c == EOF) break;
        x = x ^ c;
	};
	fclose(f);
	printf("%02x\n", x);
}

