#include <stdio.h>
#include <math.h>

/*float orgEq(float x)
{
   // return cos(x) - 3 * x + 1;
     return 3*x*x*x -2*x*x -4;
}

float phi(float x)
{
    //return ((1.0 / 3.0) * (cos(x) + 1));
       return pow((2*x*x + 4),1/3);
}

float dphi(float x)
{
    //return ((1.0 / 3.0) * sin(x));
     return (1/3)*((4*x)/pow((2*x*x+4),2/3));
}*/

float orgEq(float x) {
    return 3 * x * x * x - 2 * x * x - 4;
}

// Transformed Function: phi(x) = (2x^2 + 4)^(1/3)
float phi(float x) {
    return pow((2 * x * x + 4), 1.0 / 3.0);
}

// Derivative of phi(x): dphi(x)
float dphi(float x) {
    return (1.0 / 3.0) * (4 * x) / pow((2 * x * x + 4), 2.0 / 3.0);
}

int main(){

    float x0, x1, allowErr;
    int itr = 0, flag = 0;

    do{
        printf("Enter value of x0: ");
        scanf("%f",&x0);
        if(dphi(x0)<1){
            flag=1;
            printf("Case satisfied\n");
        }
        else{
            printf("Change the function phi(x)\n");
        }
    }while(flag!=1);

    printf("Enter value of allow error: ");
    scanf("%f",&allowErr);

    do{
        itr++;
        x1=phi(x0);
        printf("Iteration = %d, value of x1 = %f, value of f(x) = %f\n",itr,x1,orgEq(x1));

        if( fabs(orgEq(x1))<=allowErr){
            flag=0;
            printf("Root found %f after iteration %d\n",x1,itr);
    }
    x0=x1;
    }while(flag!=0);
    return 0;
}