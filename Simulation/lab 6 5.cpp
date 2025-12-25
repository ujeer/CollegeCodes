#include<stdio.h>
#include<conio.h>
#define SIZE 100
int main()
{
		int x[SIZE],i;
		int m=100,a=5,c=13;
		x[0]=11;
		for(i=0;i<100;i++)
		{
		x[i+1]=(a*x[i]+c)%m;
		}
		printf("\n By Reeju Pandit\n");
		printf("\nGeneration of random numbers using linear congruentialmethod");
		for(i=0;i<100;i++)
		{
		printf("%d\t",x[i]);
		}
		getch();
		return 0;
}
