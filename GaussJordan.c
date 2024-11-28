#include<stdio.h>
#include<math.h>

int n;

void convertToDiagonal(float a[n][n+1],int n){

    float ratio;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){

            if(j!=i){
                ratio=a[j][i]/a[i][i];
                for(int k=0;k<n+1;k++)
                 a[j][k]-=(ratio*a[i][k]);
            }
        }
    }

    printf("\nDiagonal Matrix:\n");

    for(int i=0;i<n;i++){
        for(int j=0;j<n+1;j++){
            printf("%.2f\t",a[i][j]);
        }
        printf("\n");
    }

    printf("\n");
}

void print(float a[n][n+1],int n){
    printf("Values of unknown are:\n");

    for(int i=0;i<n;i++){
        printf("Value[%d] = %f\n",i,a[i][n]/a[i][i]);
    }
}

int main()
{
    float ratio;
    printf("Enter no of Unknowns\n");
    scanf("%d",&n);
    float a[n][n+1];
    printf("Enter the Augmented Matrix\n");
    for(int i=0;i<n;i++)
    {
     for(int j=0;j<n+1;j++)
        scanf("%f",&a[i][j]);
    }
    convertToDiagonal(a,n);
    print(a,n); 
    return 0;
}