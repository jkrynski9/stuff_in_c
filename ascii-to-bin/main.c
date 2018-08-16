#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	if(argc==1)
	{
		printf("Usage: %s <string>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	int i=0,y,a=0,b,tmp,bin[255];
	while(argv[1][i]!='\0')
	{
		tmp=argv[1][i];y=0;
		while(tmp>0)
		{
			bin[y]=tmp%2;
			tmp/=2;
			y++;
		}
		i++;
		for(b=0;b<8-y;b++) printf("0");
		for(a=y-1;a>=0;a--)
		{
			printf("%d", bin[a]);
		}
		printf(" ");
	}
	printf("\n");
	exit(EXIT_SUCCESS);
}
