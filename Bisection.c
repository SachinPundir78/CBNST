#include<stdio.h>
#include<math.h>

double solve(double val) {
    return val*log(val)-1.2;  // f(x) = x * log(x) - 1.2
}

int main() {
    double a, b, x, aerr;
    int flag = 0, itr = 0;

    // Input loop for valid a and b values
    do {
        printf("Enter the values of a and b: \n");
        scanf("%lf%lf", &a, &b);

        if (solve(a) * solve(b) > 0) {
            printf("Invalid values of a and b, as f(a) and f(b) must have opposite signs.\n");
        } else {
            flag = 1;
            printf("Your entered values are %lf and %lf\n", a, b);
        }
    } while (flag != 1);

    // Input the allowed error
    printf("Enter the allowed error: \n");
    scanf("%lf", &aerr);

    // Bisection method iterations
    do {
        itr++;
        x = (a + b) / 2;

        printf("%d Iteration, value of x is %lf, value of f(x) is %lf\n", itr, x, solve(x));

        if (fabs(solve(x)) <= aerr) {
            flag = 0; 
            printf("Root found: %lf\n", x);
            break;
        } else if (solve(a) * solve(x) < 0) {
            b = x; // Root lies between a and x
        } else {
            a = x; // Root lies between x and b
        }
    } while (flag != 0);

    return 0;
}
