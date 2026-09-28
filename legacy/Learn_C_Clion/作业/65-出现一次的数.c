#include<stdio.h>

int main() {

	int i = 0, j = 0;

	int num[10];

	for ( i = 0; i < 10; i++)
	{
		scanf("%d", &num[i]);
	}

	int count = 0, once_num[10], if_once = 0, once_count = 0;
	for ( i = 0; i < 10; i++)
	{
		int tnum = num[i];
		if_once = 1;
		for ( j = 0; j < 10; j++)
		{
			// 细节 i != j 防止自己和自己重复
			if (num[j] == tnum && i != j) {
				count++;
				if_once = 0;
				break;
			}
		}
		if (if_once == 1)
		{
			once_num[once_count] = tnum;
			once_count++;
		}
	}

	if (count == 10)
	{
		printf("None\n");
	}
	else
	{
		for ( i = 0; i < once_count; i++)
		{
			printf("%d ", once_num[i]);
		}
	}




	return 0;
}