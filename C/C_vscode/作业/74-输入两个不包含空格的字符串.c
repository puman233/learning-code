#include<stdio.h>
#include<string.h>

int main() {

	char str1[50] = "";
	char str2[50] = "";
	/*char ch1[50];
	char ch2[50];*/

	int i = 0, j = 0;
	
	scanf("%s", str1);
	scanf("%s", str2);

	/*printf("%s\n", str1);
	printf("%s\n", str2);*/

	/*for ( i = 0; i < strlen(str1); i++)
	{
		ch1[i] = str1[i];
	}
	ch1[i] = '\0';
	for ( i = 0; i < strlen(str2); i++)
	{
		ch2[i] = str2[i];
	}
	ch2[i] = '\0';*/

	// 测试
	/*for ( i = 0; i < strlen(ch1); i++)
	{
		printf("%c ", ch1[i]);
	}
	printf("\n");
	for ( i = 0; i < strlen(ch2); i++)
	{
		printf("%c ", ch2[i]);
	}*/


	char same[50];
	int count = 0;

	for ( i = 0; i < strlen(str1); i++)
	{
		for ( j = 0; j < strlen(str2); j++)
		{
			if (str1[i] == str2[j] && i == j) {
				same[count] = str1[i];
				count++;
				break;
			}
		}
	}
	same[count] = '\0';

	printf("%s", same);




	return 0;
}