#include <stdio.h>
#include <math.h>

int main()
{
    int n, i;
    int x[20], y[20];
    int sumx = 0, sumy = 0, sumxy = 0, sumx2 = 0;
    float a, b;

    // Input number of data points
    printf("\n   C program for Linear Curve Fitting \n");
    printf("Enter the number of terms n: ");
    scanf("%d", &n);

    // Input x and y values
    printf("\nEnter the values of x:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &x[i]);
    }

    printf("\nEnter the values of y:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &y[i]);
    }

    // Display the table
    printf("\n-------------------------------------------------------------\n");
    printf("  x   |  y   |  x^2  |  xy  \n");
    printf("-------------------------------------------------------------\n");
    for (i = 0; i < n; i++) {
        int x_squared = x[i] * x[i];
        int x_y = x[i] * y[i];
        printf(" %3d  | %3d  | %3d  | %3d \n", x[i], y[i], x_squared, x_y);
        
        // Calculating the summations needed for the coefficients
        sumx += x[i];
        sumy += y[i];
        sumxy += x_y;
        sumx2 += x_squared;
    }

    // Calculate the coefficients 'a' and 'b' for the line y = a + bx
    a = (float)((sumx2 * sumy - sumx * sumxy) * 1.0) / (n * sumx2 - sumx * sumx);
    b = (float)((n * sumxy - sumx * sumy) * 1.0) / (n * sumx2 - sumx * sumx);

    // Display the equation of the line
    printf("\nThe equation of the line is: Y = %.3f + %.3f X\n", a, b);

    return 0;
}
