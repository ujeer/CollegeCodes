//WAP for DFA that accept the string where number of a is twice number of b over alphabet E(a,b)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	int len,i,count_a=0,count_b=0;
	char str[10];
	printf("Enter a string:");
	scanf("%s",&str);
	len = strlen(str);
	for(i=0;i<strlen(str);i++)
	{
		if(str[i] == 'a')
		{
			count_a += 1;
		}
		if(str[i] == 'b')
		{
			count_b += 1;
		}
	}
	if(count_a/2 == count_b)
	{
		printf("String is accepeted");
	}
	else
	{
		printf("String is rejected");
	}
            	 	
}


