#include<stdio.h>

int isLeapNum = 0;
void isLeap(int year);


int main() {

	/*
		计算一段时间中，11月11日是周末的次数
		
	
		1900 年 1 月 1 日是星期一

		判断闰年：
			year % 4 == 0 && year % 100 != 0
				or
			year % 400 == 0



	*/

	int x, y;	// 起止年份

	scanf("%d %d", &x, &y);

	int i = 0;
	int day_start = 0;	// 星期日
	// 还是得先判断起始年份的第一天是星期几 害
	/*
		365 % 7 = 1
		366 % 7 = 2
	*/
	for (i = 1900; i < x; i++)
	{
		isLeap(i);
		if (isLeapNum == 1)
		{
			// 闰年
			day_start = (day_start + 2) % 7;
		}
		else
		{
			// 平年
			day_start = (day_start + 1) % 7;
		}
	}

	/*
		31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 11 = 315

		2018

		day_start = 1
		day_week = (day_start + 315) % 7 = 5

		2025
		day_start = 3
		day_week = (day_start + 315) % 7 = 1
	*/

	int day_week = 0;
	int day_sum = 0;

	for (i = x; i <= y; i ++)
	{
		isLeap(i);
		day_week = 0;
		if (isLeapNum == 1)
		{
			day_week = (day_start + 316) % 7;
			if (day_week == 0 || day_week == 6)
			{
				day_sum++;
			}
			day_start = (day_start + 2) % 7;
		}
		else
		{
			day_week = (day_start + 315) % 7;
			if (day_week == 0 || day_week == 6)
			{
				day_sum++;
			}
			day_start = (day_start + 1) % 7;
		}
	}

	printf("%d\n", day_sum);


	return 0;
}

void isLeap(int year) {
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
	{
		isLeapNum = 1;	// 闰年喵
	}
	else
	{
		isLeapNum = 0;	// 默认为非闰年喵
	}
}