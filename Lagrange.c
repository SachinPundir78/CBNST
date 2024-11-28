#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{

	printf("***********************************************************");printf("\n");
    printf("***********************************************************");printf("\n");
    printf("*              Lagrange Interpolation                        *");printf("\n");
    printf("***********************************************************");printf("\n");
    printf("***********************************************************");printf("\n");
	float x[101],y[101],xp,yp=0,point;
	int n;

	printf("Enter the number of points: \n");
	scanf("%d",&n);

	printf("Enter the values of x and y: \n");

	for(int i=1;i<=n;++i)
	{
		printf("x[%d]= ",i);
		scanf("%f",&x[i]);

		printf("y[%d]= ",i);
		scanf("%f",&y[i]);
	}
	printf("Enter the interpolation point: ");
	scanf("%f",&xp);

	for(int i=1;i<n;++i)
	{
		point=1;

		for(int j=1;j<=n;++j)
		{
			if(i!=j)
			{
				point*=(xp-x[j])/(x[i]-x[j]);
			}
		}
		yp+=point*y[i];
	}
	printf("The value of y at %.3f is %.3f",xp,yp);
}