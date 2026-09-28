#include<stdio.h>


int main() {

	char str[100];

	/*
					青年大学习
		char* fgets(char* str, int n, FILE* stream);
		
		str: 存放读取结果的字符数组（目标缓冲区）
		n: 最多读取的字符数（包括结尾的'\0'）
		stream: 输入流（通常是stdin，表示标准输入）
	*/
	fgets(str, sizeof(str), stdin);

	int i = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		/*if (str[i] != '\0') {*/
		if (str[i] >= 'a' && str[i] <= 'z') {
			//str[i] = str[i] - ('a' - 'A');
			if (str[i] >= 'w' && str[i] <= 'z')
			{
				str[i] -= 22;
			}
			else
			{
				str[i] += 4;
			}
		}
		else if (str[i] >= 'A' && str[i] <= 'Z') {
			//str[i] = str[i] + ('a' - 'A');
			if (str[i] >= 'W' && str[i] <= 'Z')
			{
				str[i] -= 22;
			}
			else
			{
				str[i] += 4;
			}
		}
		//}
	}

	printf("%s\n", str);


	return 0;
}