#include<stdio.h>
#include<math.h>

int main(){

    float x,u1,u,y;
    int n,fact;

    printf("Enter the number of terms\n ");
    scanf("%d",&n);

    float a[n][n+1];
    printf("Enter the values of X\n ");
    for(int i=0;i<n;i++){
        scanf("%f",&a[i][0]);
    }
    
    printf("Enter the values of Y\n ");
    for(int i=0;i<n;i++){
        scanf("%f",&a[i][1]);
    }
    
    printf("Enter value x for which you want to find y\n");
    scanf("%f",&x);

    //find difference table
    for(int j=2;j<n+1;j++){
        for(int i=0;i<n-j+1;i++){
            a[i][j]=a[i+1][j-1]-a[i][j-1];
        }
    }

    printf("The difference table is as follows:\n"); 
    for(int i=0;i<n;i++){
        for(int j=0;j<n+1-i;j++){
            printf("%f\t",a[i][j]);
        }
        printf("\n");
}

//find u
u=(x-a[0][0])/(a[1][0]-a[0][0]);

//find y
y=a[0][1];
u1=u;
fact=1;

for(int i=2;i<=n;i++){
    y=y+(u1*a[0][i])/fact;

    fact=fact*i;
    u1=u1*(u-(i-1));
}

printf("The value of y at x=%f is %f",x,y);


}