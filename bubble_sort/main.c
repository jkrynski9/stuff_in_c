#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int array_size,array[1000],i,j,a,tmp;

int main(int argc, char* argv[])
{
	if (argc == 1)
	{
		printf("Usage: %s <size of array>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	srand(time(NULL));
	array_size = atoi(argv[1]);
	if(array_size > 1000)
	{
		printf("Error: array size can't be greater than 1000");
		exit(EXIT_FAILURE);
	}
	for(i=0;i<array_size;i++)
		array[i]=1 + rand() % 50;
	printf("Before sorting:\n");
	for(i=0;i<array_size;i++)
	{
		for(j=0;j<array[i];j++)
		{
			if(j==array[i]-1)
				printf("%i",array[i]);
			else
				printf(" ");
		}
		printf("\n");
	}
	printf("Press any key to continue.");
	getchar();
	j=array_size-1;
	while(j>0)
	{
		for(i=0;i<j;i++)
		{
			if(array[i]>array[i+1])
			{
				tmp = array[i];
				array[i] = array[i+1];
				array[i+1] = tmp;
			}
		}
		j--;
		printf("\e[1;1H\e[2J");
		usleep(15000);
		for(i=0;i<array_size;i++)
		{
			for(a=0;a<array[i];a++)
			{
				if(a==array[i]-1)
					printf("%i",array[i]);
				else
					printf(" ");
			}
			printf("\n");
		}
	}
	exit(EXIT_SUCCESS);
}
