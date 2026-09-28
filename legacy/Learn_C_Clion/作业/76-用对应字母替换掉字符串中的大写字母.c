#include<stdio.h>

int main() {

	char str[80];

	printf("Input a string: ");
	
	int i;
	char c;
	for ( i = 0; i < 79; i++)
	{
		c = getchar();
		if (c == '\n')
		{
			break;
		}
		str[i] = c;
	}
	str[79] = '\0';
	
	for ( i = 0; i < 79 && str[i] != '\0'; i++)
	{
		/*
			abcdefghijklm	13
			nopqrstuvwxyz	13

			1 -> 26 +25
			2 -> 25 +23
			3 -> 24 +21
		*/
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			//str[i] = 27 - 2 * (str[i]);
			str[i] = 'Z' - (str[i] - 'A');
		}
		
	}

	printf("After replaced: ");
	printf("%s\n", str);











	return 0;
}