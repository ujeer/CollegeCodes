//WAP for the DFA that accept the string aababaa.
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char ACCEPTED_STRING[] = "aababaa";
int main()
{
	int len,i;
	char str[10];
	printf("Enter a string:");
	scanf("%s",&str);
	len = strlen(str);
	if(len == strlen(ACCEPTED_STRING))
    {
		for(i=0;i<strlen(ACCEPTED_STRING);i++)
		{
			if(str[i] != ACCEPTED_STRING[i])
			{
				printf("string is rejected");
            	exit(0);
			}
            	
    	}
    	printf("String is accepted");
    }
	else
	{
	   	printf("The string must be of length %d",strlen(ACCEPTED_STRING));	
	}
}


