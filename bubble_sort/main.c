#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int array_size,array[255],i,j,tmp;

int main(int argc, char* argv[])
{
	if (argc == 1)
	{
		printf("Usage: %s <size of array>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	srand(time(NULL));
	array_size = atoi(argv[1]);
	if(array_size > 255)
	{
		printf("Error: array size can't be greater than 255");
		exit(EXIT_FAILURE);
	}
	for(i=0;i<array_size;i++)
		array[i]=rand() % 100;
	printf("Before sort:\n");
	for(i=0;i<array_size;i++)
		printf("%d ",array[i]);
	printf("\n");
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
	}
	printf("After sort:\n");
	for(i=0;i<array_size;i++)
		printf("%d ",array[i]);
	printf("\n");
	exit(EXIT_SUCCESS);
}
