#include<stdio.h>
#include<math.h>

int main(){
    float x,y,u1,u;
    int n,fact=1;

    printf("Enter the number of terms\n");
    scanf("%d",&n);
    float a[n][n+1];

    printf("Enter the values of X\n");
    for(int i=0;i<n;i++){
        scanf("%f",&a[i][0]);
    }

    printf("Enter the values of Y\n");
    for(int i=0;i<n;i++){
        scanf("%f",&a[i][1]);
    }

   printf("Enter value x for which you want to find y\n");
    scanf("%f",&x);
   //find the difference table

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

u=(x-a[n-1][0])/(a[1][0]-a[0][0]);
y=a[n-1][1];

u1=u;
int j=2;
for(int i=n-2;i>=0;i--){
   y=y+(u1*a[i][j])/fact;
   fact=fact*j;
   u1=u1*(u+(j-1));
   j++;
}
printf("The value of y at x= %.2f is %.2f",x,y);
}