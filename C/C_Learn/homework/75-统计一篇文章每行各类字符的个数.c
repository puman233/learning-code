//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//
//int main() {
//
//
//	char str[3][80] = { 0 };
//
//	int capital = 0, lower = 0, digit = 0, space = 0, other = 0;
//
//	int i = 0,j = 0;
//
//	// 使用单个字符输入
//	for ( i = 0; i < 3; i++)
//	{
//		j = 0;
//		char c;
//		for ( j = 0; j < 79; j++)
//		{
//			c = getchar();
//			if (c == '\n')
//			{
//				break;
//			}
//			str[i][j] = c;
//		}
//		str[i][j] = '\0';
//	}
//
//	for (i = 0; i < 3; i++)
//	{
//		capital = 0, lower = 0, digit = 0, space = 0, other = 0;
//		for (j = 0; str[i][j] != '\0'; j++)
//		{
//			if (str[i][j] >= 'A' && str[i][j] <= 'Z') {
//				capital++;
//			}
//			else if (str[i][j] >= 'a' && str[i][j] <= 'z')
//			{
//				lower++;
//			}
//			else if (str[i][j] >= '0' && str[i][j] <= '9')
//			{
//				digit++;
//			}
//			else if (str[i][j] == ' ')
//			{
//				space++;
//			}
//			else
//			{
//				other++;
//			}
//		}
//		printf("%d line:capital=%d,lower=%d,digit=%d,space=%d,other=%d\n", i, capital, lower, digit, space, other);
//	}
//
//
//
//
//	return 0;
//}
//
