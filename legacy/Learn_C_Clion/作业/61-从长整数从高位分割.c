#include<stdio.h>

int main() {

	char n[10];

	int i;

	scanf("%s", n);
	//scanf_s("%9s", n, 10);

	for (i = 0; n[i] != '\0'; i++)
	{
		printf("%c ", n[i]);
	}




	return 0;
}