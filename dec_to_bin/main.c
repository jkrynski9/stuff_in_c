/* Decimal to binary converter
   by RafiX	20-10-2017     */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int dec,bin[255],i,a;

int main(int argc, char* argv[])
{
	if (argc == 1)
	{
		printf("Usage: dectobin <number>\n");
		exit(EXIT_FAILURE);
	}
	dec = atoi(argv[1]),i=0;
	printf("%d in binary = ", dec);
	while (dec>0)
	{
		bin[i] = dec % 2;
		dec /= 2;
		i++;
	}
	for (a=i-1;a>=0;a--)
	{
		printf("%d", bin[a]);
	}
	printf("\n");
	return EXIT_SUCCESS;
}
