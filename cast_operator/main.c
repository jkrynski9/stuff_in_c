/* Usage of cast operator example
   by RafiX	20-10-2017	  */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	float exact;
	int rough;
	exact = 3.14;
	rough = (int) exact;
	printf("Exact = %f \nRough = %d\n", exact, rough);
	return EXIT_SUCCESS;
}
