#include<stdio.h>
#include<math.h>

int main(){
    int n;
    float temp, error, a, sum = 0;
    float matrix[10][10], value[10], aerr;

    printf("\n Enter the Total Number of Equations: ");
    scanf("%d", &n);

    printf("Enter the allowed error: ");
    scanf("%f", &aerr);

    printf("Enter the coefficients (augmented matrix):\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n + 1; j++){
            printf("Matrix[%d][%d] = ", i, j);
            scanf("%f", &matrix[i][j]);
        }
    }

    // Initialize values of x (initial guess)
    for(int i = 0; i < n; i++){
        value[i] = 0;
    }

    do{
        a = 0;  // Reset maximum error for this iteration
        for(int i = 0; i < n; i++){
            sum = 0;
            for(int j = 0; j < n; j++){
                if(i != j){
                    sum += matrix[i][j] * value[j];  // Exclude diagonal element
                }
            }
            temp = (matrix[i][n] - sum) / matrix[i][i];  // Correct indexing for constant term

            error = fabs(temp - value[i]);  // Calculate error for current variable

            if(error > a){  // Update maximum error if current error is larger
                a = error;
            }
            value[i] = temp;  // Update value for the current variable
            printf("\nvalue[%d] = %f", i, value[i]);
        }
        printf("\n");
    } while(a >= aerr);  // Compare max error with allowed error

    printf("\nRoots are:\n");
    for(int i = 0; i < n; i++){
        printf("x[%d] = %f\n", i, value[i]);
    }

    return 0;
}
