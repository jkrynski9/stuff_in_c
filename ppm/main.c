#include <stdio.h>
#include <stdlib.h>
#include <time.h>

FILE *fp; int xi,yi,x,y,v;

int main(int argc, char *argv[])
{
	if(argc<3)
	{
		printf("Usage: %s <x> <y>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	xi = atoi(argv[1]);
	yi = atoi(argv[2]);
	fp=fopen("out.ppm","w");
	srand(time(NULL));
	fprintf(fp,"P3\n%i %i\n255\n", xi, yi);
	for(x=0;x<xi;x++)
	{
		for(y=0;y<(yi*3)-1;y++)
		{
			v=rand()%256;
			fprintf(fp,"%i ",v);
		}
		fprintf(fp,"\n");
	}
	fclose(fp);
	exit(EXIT_SUCCESS);
}
