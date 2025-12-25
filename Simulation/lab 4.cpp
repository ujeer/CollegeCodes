#include<stdio.h>
#include<conio.h>
#include<math.h>

int main()
{
	float l,m,p[16],pr,x,a,i;
	int j;
	 printf("\n By Reeju Pandit\n");
	printf("Enter arrival rate per hours:");
	scanf("%f",&l);
for(x=0;x<16;x++)
{
	a=1;
	for(i=1;i<=x;i++)
	{
	a=a*i;
	}
	pr= (pow(2.71,-l)*pow(l,x))/a;
	// p[x]= (pow(2.71,-l)*pow(l,x))/a;
	printf("\nP(X=%f) = %f\n",x,pr);
}

/* for(x=0;x<16;x++)
{

printf("\nP(X=%2d) = %f\n",x,p[x]);
}*/

getch();
return 0;
}
