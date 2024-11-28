#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i;
    float x[20], y[20], sumx = 0, sumy = 0, sumx2 = 0, sumxy = 0, a, b;

    // Input number of data points
    printf("\nSimple Linear Regression (Y = a + bX)\n");
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    // Input x and y values
    printf("\nEnter the values of x:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%f", &x[i]);
    }

    printf("\nEnter the values of y:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%f", &y[i]);
    }

    // Display table header
    printf("\n----------------------------------------------------------\n");
    printf("|  x  |  y  |  x^2  |  xy  |\n");
    printf("----------------------------------------------------------\n");

    // Calculating necessary summations and displaying the table
    for (i = 0; i < n; i++)
    {
        float x2 = x[i] * x[i];
        float xy = x[i] * y[i];

        sumx += x[i];
        sumy += y[i];
        sumx2 += x2;
        sumxy += xy;

        // Print each row of the table
        printf("| %4.2f | %4.2f | %5.2f | %5.2f |\n", x[i], y[i], x2, xy);
    }

    // Display the summation results
    printf("----------------------------------------------------------\n");
    printf("Sum of x = %.2f\n", sumx);
    printf("Sum of y = %.2f\n", sumy);
    printf("Sum of x^2 = %.2f\n", sumx2);
    printf("Sum of xy = %.2f\n", sumxy);
    printf("----------------------------------------------------------\n");

    // Calculate the slope (b) and intercept (a)
    b = (n * sumxy - sumx * sumy) / (n * sumx2 - sumx * sumx);
    a = (sumy - b * sumx) / n;

    // Display the regression line equation
    printf("\nThe regression line is: Y = %.3f + %.3f X\n", a, b);

    return 0;
}
