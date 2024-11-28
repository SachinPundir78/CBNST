#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define f(x) 1 / (1 + pow(x, 2))
int main()
{
	printf("***********************************************************");
	printf("\n");
	printf("***********************************************************");
	printf("\n");
	printf("*              		 Trapezoidal                          *");
	printf("\n");
	printf("***********************************************************");
	printf("\n");
	printf("***********************************************************");
	printf("\n");
	float lower, upper, integration = 0.0, size, temp;

	int interval;

	printf("Enter the lower integration: ");
	scanf("%f", &lower);

	printf("Enter the upper integration: ");
	scanf("%f", &upper);

	printf("Enter the interval: ");
	scanf("%d", &interval);

	size = (upper - lower) / interval;

	integration = f(lower) + f(upper);

	for (int i = 1; i <= interval - 1; ++i)
	{
		temp = lower + i * size;
		integration += 2 * f(temp);
	}
	integration *= size / 2;

	printf("Value Required is: %.3f", integration);
}