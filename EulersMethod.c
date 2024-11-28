#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float f(float x, float y)
{
    float temp;
    return temp = x + y;
}

int main()
{
    printf("***********************************************************");
    printf("\n");
    printf("***********************************************************");
    printf("\n");
    printf("*                   Euler Method                          *");
    printf("\n");
    printf("***********************************************************");
    printf("\n");
    printf("***********************************************************");
    printf("\n");
    float a, b, x, y, h, t, k;
    printf("Enter the x0: ");
    scanf("%f", &a);

    printf("Enter the y0: ");
    scanf("%f", &b);

    printf("Enter the h: ");
    scanf("%f", &h);

    printf("Enter the xn: ");
    scanf("%f", &t);

    x = a;
    y = b;

    while (x <= t)
    {
        k = h * f(x, y);
        x += h;
        y += k;

        printf("The Values are: %0.3f\t%0.3f\n ", x, y);
    }
}