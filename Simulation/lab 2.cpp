#include<stdio.h>
#include<conio.h>

int main()
{
float l,m,e;
float p,et;
printf("\n By Reeju Pandit\n");
printf("Enter Inter arrival time of customers per hours:");
scanf("%f",&l);
printf("\nEnter The average time spent by cutomers per hour:");
scanf("%f",&m);
p=1-l/m;
e=l/(m-l);
et=1/(m-l);
et=et*60;
printf("\nThe probability That a customer wont't have to wait atcounter:%f ",p);
printf("\n\nExpected number of customer: %f",e);
printf("\n\nExpected time to be spent in bank: %f minutes",et);
getch();
return 0;
}
