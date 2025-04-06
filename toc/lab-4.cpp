//WAP for DFA that accept string ending with 11
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
				if(str[i] == '0')
				f='q';
				else if(str[i] == '1')
				f='x';
				break;
			
			case 'x':
				if(str[i] == '0')
				f='q';
				else if(str[i] == '1')
				f='y';
				break;
			
			case 'y':
				if(str[i] == '0')
				f='q';
				else if(str[i] == '1')
				f='y';
				break;
		} 
	}
	if(f =='y')
	printf("string is accepeted");
	else
	printf("string is rejected");
}



