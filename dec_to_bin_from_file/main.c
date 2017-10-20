/* Decimal to binary converter from file
   by RafiX	20-10-2017		 */


#include <stdio.h>
#include <stdlib.h>

FILE * file;
char line[256];
int dec,bin[256],i,a;

int main(int argc, char* argv[])
{
	if(argc<=1)
	{
		printf("Usage: %s <file>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1],"r");
	while(!feof(file))
	{
		fgets(line, 256, file);
		dec = atoi(line);
		i=0;
		printf("%d(10) = ", dec);
		while(dec>0)
		{
			bin[i] = dec % 2;
			dec /= 2;
			i++;
		}
		for(a=i-1;a>=0;a--)
		{
			printf("%d", bin[a]);
		}
		printf("(2)\n");
	}
	fclose(file);
	return EXIT_SUCCESS;
}
