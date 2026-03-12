//WAP for DFA that accept the string starting with a and ending with bb
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
				f='d';
				break;
			
			case 'x':
				if(str[i] == 'b')
				f='y';
				else if(str[i] == 'a')
				f='x';
				break;
			
			case 'y':
				if(str[i] == 'b')
				f='z';
				else if(str[i] == 'a')
				f='x';
				break;
			
			case 'z':
				if(str[i] == 'b')
				f='z';
				else if(str[i] == 'a')
				f='x';
				break;
		} 
	}
	if(f =='z')
	printf("string is accepeted");
	else
	printf("string is rejected");
}
