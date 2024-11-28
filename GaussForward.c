#include <stdio.h>
#include <math.h>

void main() {
    int n, i, j;
    float ax[10], ay[10], x, nr, dr, y = 0, h, p, diff[20][20];
    float y1, y2, y3, y4;

    printf("\t\t !! GAUSS' FORWARD INTERPOLATION FORMULA !! ");
    
    // Input section (all inputs in one line)
    printf("\n\n Enter the number of terms (n): ");
    scanf("%d", &n);
    
    printf("Enter the X values separated by space: ");
    for (i = 0; i < n; i++) {
        scanf("%f", &ax[i]);
    }

    printf("Enter the Y values separated by space: ");
    for (i = 0; i < n; i++) {
        scanf("%f", &ay[i]);
    }

    printf("Enter the value of x for which you want to find y: ");
    scanf("%f", &x);

    // Calculation and processing section
    h = ax[1] - ax[0];

    // Constructing the difference table
    for (i = 0; i < n - 1; i++) {
        diff[i][1] = ay[i + 1] - ay[i];
    }

    for (j = 2; j <= 5; j++) {
        for (i = 0; i < n - j; i++) {
            diff[i][j] = diff[i + 1][j - 1] - diff[i][j - 1];
        }
    }

    // Printing the difference table with the required format
    printf("\nThe Difference Table is as follows:\n");
    printf("Index\t  X\t\tY\tY1\tY2\tY3\tY4\n");
    printf("---------------------------------------------------------------\n");
    
    for (i = 0; i < n; i++) {
        printf("%d\t  %.4f\t%.4f", i - 3, ax[i], ay[i]);
        for (j = 1; j < 5; j++) {
            printf("\t%.4f", diff[i][j]);
        }
        printf("\n");
    }

    // Find the appropriate 'i' where x falls
    i = 0;
    while (ax[i] < x) {
        i++;
    }
    i--;

    p = (x - ax[i]) / h;
    y1 = p * diff[i][1];
    y2 = p * (p - 1) * diff[i - 1][2] / 2;
    y3 = (p + 1) * p * (p - 1) * diff[i - 2][3] / 6;
    y4 = (p + 1) * p * (p - 1) * (p - 2) * diff[i - 3][4] / 24;

    // Summing up the result
    y = ay[i] + y1 + y2 + y3 + y4;

    // Output Section
    printf("\nWhen x = %6.4f, y = %6.8f\n", x, y);
}
