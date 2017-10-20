/* Fibonacci Sequence 
   by RafiX	 20-10-2017 */
#include <stdio.h>
#include <stdlib.h>

int a;

int fib(int n)
{
	if(n==0)
	{
		return 0;
	}
	if(n==1)
	{
		return 1;
	}
	return fib(n-1) + fib(n-2);
}

int main(int argc, char* argv[])
{
	if(argc<=1)
	{
		printf("Usage: %s <number>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	a = atoi(argv[1]);
	printf("fib(%d) = %d\n", a, fib(a));
	return EXIT_SUCCESS;
}
