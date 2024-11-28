#include<math.h>
#include<stdio.h>

#define f(x)(x*x)+4*sin(x)
#define df(x) 2*x+4*cos(x)

//#define f(x) (pow(x, 4) - x - 1)  // New equation: x^3 - x - 2
//#define df(x) (4 * pow(x, 3) - 1)  // Derivative: 3x^2 - 1

int main(){
    float x0,x1,f0,f1,aerr;
    int flag=0,itr=0;
     
    printf("Enter value of x0 : ");
    scanf("%f",&x0);
    printf("Enter the allowed error\n");
    scanf("%f",&aerr);

    do{
        f0=f(x0);
        f1=df(x0);

        if(f1==0){
            printf("Divide by zero error\n");
            return 0;
        }
        x1=x0-(f0/f1);
        itr++;

        printf("Iteration = %d, value of x1 = %f, value of f(x) = %f\n",itr,x1,f(x1));

        if(fabs(f(x1))<=aerr){
            flag=1;
            printf("Root found %f after iteration %d\n",x1,itr);
        }
        x0=x1;
        
    }while(flag!=1);

    printf("\nFinal root after %d iteration =%f\n",itr,x1);

    return 0;
}