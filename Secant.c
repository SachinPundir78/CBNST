#include<stdio.h>
#include<math.h>

float f(float x){
    return x*x*x - 5*x + 1;
}

int main(){
    float x0, x1,x2, aerr;
    int flag=0,itr=0;

    do{
        printf("Enter value of x0 and x1: ");
        scanf("%f%f",&x0,&x1);

        if(f(x0)*f(x1)<0){
            flag=1;
            printf("Case satisfied\n");
        }else{
            printf("Wrong intervals,try again\n");
        }
    }while(flag!=1);

    printf("Enter value of allowed error: ");
    scanf("%f",&aerr);

    do{
    
       itr++;
       x2=x1-((x1-x0)/(f(x1)-f(x0)))*f(x1);

       printf("\n%d Iteration ,value of x is %f,value of (%f) is %f",itr,x2,x2,f(x2));

       if(fabs(f(x2))<=aerr){
           flag=0;
           printf("\nRoot found %f after %d iteration\n",x2,itr);
       }else{
           x0=x1;
           x1=x2;
       }

    }while(flag!=0);
    return 0;
}
