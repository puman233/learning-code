#include<stdio.h>

int main() {

	char word[8];
	char word2[8];

	// 防止野指针
	//char* string;
	char word3[8];
	char* string = word3;
	
	scanf_s("%7s", string, 8);

	printf("%s\n", string);

	// 空字符串
	char bufffer[100] = "";
	// 数组长度只有1
	char bufferZero[] = "";

	// 不安全
	/*scanf_s("%s", word, 8);
	scanf_s("%s", word2, 8);*/
	scanf_s("%7s", word, 8);
	scanf_s("%7s", word2, 8);

	// 输出：hellowo##rld##
	printf("%s##%s##\n", word, word2);
	








	return 0;
}