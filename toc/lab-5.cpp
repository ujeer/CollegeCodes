//WAP for DFA that accept the string having substring "aa" E(a,b)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	int len,i,f='q';
	char str[10];
	printf("Enter a string:");
	scanf("%s",&str);
	len = strlen(str);
	for(i=0;i<strlen(str);i++)
	{
		switch(f)
		{
			case 'q':
				if(str[i] == 'a')
				f='x';
				else if(str[i] == 'b')
				f='q';
				break;
			
			case 'x':
				if(str[i] == 'a')
				f='y';
				else if(str[i] == 'b')
				f='q';
				break;
			
			case 'y':
				break;
		} 
	}
	if(f =='y')
	printf("string is accepeted");
	else
	printf("string is rejected");
}
