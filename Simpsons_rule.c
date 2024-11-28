#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define f(x) (log(x))
int main()
{

    printf("***********************************************************");
    printf("\n");
    printf("***********************************************************");
    printf("\n");
    printf("*              		 Simpson 1/3                          *");
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
        if (i % 2 == 0)
        {
            integration += 2 * f(temp);
        }
        else
        {
            integration += 4 * f(temp);
        }
    }
    integration *= size / 3;
    printf("Value Required is: %.3f", integration);
}