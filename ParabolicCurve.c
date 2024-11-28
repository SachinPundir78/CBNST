#include <stdio.h>
#include <math.h>

int main()
{
    float xy[20][20], matrix[3][4], ratio, a;
    float sum_x = 0, sum_y = 0, sum_x2 = 0, sum_x3 = 0, sum_x4 = 0, sum_xy = 0, sum_x2y = 0;
    int i, j, k, n;

    printf("***********************************************************\n");
    printf("          Parabolic Curve Fitting Program                 \n");
    printf("***********************************************************\n");

    // Input the number of data points
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    // Input the x and y values
    printf("Enter the values of x and y:\n");
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i == 0)
                printf("x[%d]: ", j + 1);
            else
                printf("y[%d]: ", j + 1);

            scanf("%f", &xy[i][j]);
        }
    }

    // Calculate summations
    for (i = 0; i < n; i++)
    {
        sum_x += xy[0][i];
        sum_y += xy[1][i];
        sum_x2 += pow(xy[0][i], 2);
        sum_x3 += pow(xy[0][i], 3);
        sum_x4 += pow(xy[0][i], 4);
        sum_xy += xy[0][i] * xy[1][i];
        sum_x2y += pow(xy[0][i], 2) * xy[1][i];
    }

    // Form the augmented matrix
    matrix[0][0] = n;
    matrix[0][1] = sum_x;
    matrix[0][2] = sum_x2;
    matrix[0][3] = sum_y;
    matrix[1][0] = sum_x;
    matrix[1][1] = sum_x2;
    matrix[1][2] = sum_x3;
    matrix[1][3] = sum_xy;
    matrix[2][0] = sum_x2;
    matrix[2][1] = sum_x3;
    matrix[2][2] = sum_x4;
    matrix[2][3] = sum_x2y;

    // Apply Gauss Elimination to solve for coefficients
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (i != j)
            {
                ratio = matrix[j][i] / matrix[i][i];
                for (k = 0; k < 4; k++)
                {
                    matrix[j][k] -= ratio * matrix[i][k];
                }
            }
        }
    }

    // Normalize the rows to find coefficients
    for (i = 0; i < 3; i++)
    {
        a = matrix[i][i];
        for (j = 0; j < 4; j++)
        {
            matrix[i][j] /= a;
        }
    }

    // Display the table of computations
    printf("\n-----------------------------------------------------------\n");
    printf("x\t y\t x^2\t x^3\t x^4\t x*y\t x^2*y\n");
    printf("-----------------------------------------------------------\n");
    for (i = 0; i < n; i++)
    {
        printf("%.2f\t %.2f\t %.2f\t %.2f\t %.2f\t %.2f\t %.2f\n",
               xy[0][i], xy[1][i],
               pow(xy[0][i], 2), pow(xy[0][i], 3), pow(xy[0][i], 4),
               xy[0][i] * xy[1][i], pow(xy[0][i], 2) * xy[1][i]);
    }
    printf("-----------------------------------------------------------\n");

    // Display the results
    printf("\nThe coefficients of the parabolic curve are:\n");
    printf("a = %.2f\n", matrix[0][3]);
    printf("b = %.2f\n", matrix[1][3]);
    printf("c = %.2f\n", matrix[2][3]);

    printf("\nThe equation of the parabolic curve is:\n");
    printf("y = %.2f + %.2f*x + %.2f*x^2\n",
           matrix[0][3], matrix[1][3], matrix[2][3]);

    return 0;
}
