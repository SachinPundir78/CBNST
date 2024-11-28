#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define take(x, y) (y * y - x) / (y * y + x)

int main()
{
    printf("***********************************************************");
    printf("\n");
    printf("***********************************************************");
    printf("\n");
    printf("*              Runga Kutta Method                         *");
    printf("\n");
    printf("***********************************************************");
    printf("\n");
    printf("***********************************************************");
    printf("\n");
    int n;
    float x0, y0, xn, yn, res, k1, k2, k3, k4, stepSize;

    printf("Enter the initial conditions\n");

    printf("Enter x0: ");
    scanf("%f", &x0);

    printf("Enter y0: ");
    scanf("%f", &y0);

    printf("Enter the calculating point: ");
    scanf("%f", &xn);

    printf("Enter the steps: ");
    scanf("%d", &n);

    stepSize = (xn - x0) / n;

    for (int i = 0; i < n; ++i)
    {
        k1 = stepSize * (take(x0, y0));
        k2 = stepSize * (take((x0 + stepSize / 2), (y0 + k1 / 2)));
        k3 = stepSize * (take((x0 + stepSize / 2), (y0 + k2 / 2)));
        k4 = stepSize * (take((x0 + stepSize), (y0 + k3)));

        res = (k1 + 2 * k2 + 2 * k3 + k4) / 6;

        yn = res + y0;
        printf("%0.4f\t%0.4f\t%0.4f\n", x0, y0, yn);
        x0 += res;
        y0 = yn;
    }
    printf("\nValue of y at x = %0.2f is %0.3f", xn, yn);
}
// pd code