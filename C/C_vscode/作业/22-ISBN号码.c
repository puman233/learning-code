#include<stdio.h>
#include<string.h>

int main() {

	/*
		以下为 Basic 版本
	*/

	int n1, n2, n3, n4, n5, n6, n7, n8, n9, n10;
	//char ch1, ch2, ch3;
	/*scanf_s("%1d%c%1d%1d%1d%c%1d%1d%1d%1d%1d%c%1d", 
		&n1, 
		&ch1,
		&n2, &n3, &n4, 
		&ch2, 
		&n5, &n6, &n7, &n8, &n9,
		&ch3, 
		&n10);*/
	scanf("%1d-%1d%1d%1d-%1d%1d%1d%1d%1d-%1d", 
		&n1, 
		&n2, &n3, &n4, 
		&n5, &n6, &n7, &n8, &n9,
		&n10);


	int isbn_end = n10;
	int isbn_sum = 0;

	isbn_sum += n1 * 1 + n2 * 2 + n3 * 3 + n4 * 4 
		+ n5 * 5 + n6 * 6 + n7 * 7 + n8 * 8 + n9 * 9;

	char isbn_endX;

	if (isbn_end == isbn_sum % 11) {
		printf("Right\n");
	}
	else
	{
		isbn_end = isbn_sum % 11;
		if (isbn_end == 10)
		{
			isbn_endX = 'X';
			//printf("%1d%c%1d%1d%1d%c%1d%1d%1d%1d%1d%c%c\n", n1, ch1, n2, n3, n4, ch2, n5, n6, n7, n8, n9, ch3, isbn_endX);
			printf("%1d-%1d%1d%1d-%1d%1d%1d%1d%1d-%c\n", n1, n2, n3, n4, n5, n6, n7, n8, n9, isbn_endX);
		}
		else
		{
			n10 = isbn_end;
			//printf("%1d%c%1d%1d%1d%c%1d%1d%1d%1d%1d%c%1d\n", n1, ch1, n2, n3, n4, ch2, n5, n6, n7, n8, n9, ch3, n10);
			printf("%1d-%1d%1d%1d-%1d%1d%1d%1d%1d-%1d\n", n1, n2, n3, n4, n5, n6, n7, n8, n9, n10);
		}
		//printf("%1d%c%1d%1d%1d%c%1d%1d%1d%1d%1d%c%1d\n", n1,ch1,n2,n3,n4,ch2,n5,n6,n7,n8,n9,ch3,n10);
	}



	/*

		以下为 Pro 版本

	char isbn[14];
	scanf_s("%s", isbn, (unsigned)__crt_countof(isbn));

	int isbn_end = 0;
	int isbn_sum = 0;

	int i = 0;
	
	int count = 1;
	for (i = 0; isbn[i] != '\0'; i++)
	{
		if (isbn[i] != '-')
		{
			//isbn_sum += (isbn[i] - '0') * (i + 1);
			if (count <= 9)
			{
				isbn_sum += (isbn[i] - '0') * count;
			}
			count++;
		}
	}

	isbn_end = isbn[strlen(isbn) - 1] - '0';
	//isbn_end = isbn[12] - '0';

	if (isbn_end == isbn_sum % 11)
	{
		printf("Right\n");
	}
	else
	{
		isbn_end = isbn_sum % 11;
		if (isbn_end == 10)
		{
			isbn[strlen(isbn) - 1] = 'X';
		}
		else
		{
			isbn[strlen(isbn) - 1] = isbn_end + '0';
		}
		printf("%s\n", isbn);
	}

	*/



	return 0;
}