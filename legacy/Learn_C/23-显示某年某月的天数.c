#include<stdio.h>

void Days(int n1, int n2);


int main() {

	int year, month;

	printf("input year and month: ");

	scanf("%d %d", &year, &month);

	int isLeap = 0;	// 默认为非闰年喵

	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
	{
		isLeap = 1;	// 闰年喵
		Days(isLeap, month);
	}
	else
	{
		Days(isLeap, month);
	}




	return 0;
}

// 建一个判断
void Days(int n1, int n2)
{
	switch (n2)	// 这里month
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		printf("31\n");
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		printf("30\n");
		break;
	case 2:
		if (n1 == 0)
		{
			printf("28\n");
		}
		else
		{
			printf("29\n");
		}
	default:
		break;
	}
}


