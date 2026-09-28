#include<stdio.h>

int main() {
	int a = 0;

	scanf("%d", &a);
	
	int result = a / 10;

	switch (result)
	{
	case 0:
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
		printf("m=1\n");
		break;
	case 6:
		printf("m=2\n");
		break;
	case 7:
		printf("m=3\n");
		break;
	case 8:
		printf("m=4\n");
		break;
	default:
		printf("m=5\n");
		break;
	}





	return 0;
}