//#include<stdio.h>
//
//int main() {
//
//	char ch;
//	int sum_en = 0, sum_space = 0, sum_num = 0, sum_other = 0;
//
//	printf("Please input:");
//	while (1) {
//		ch = getchar();
//		if (ch == '\n')
//		{
//			break;
//		}
//		else if (ch == ' ')
//		{
//			sum_space++;
//		}
//		else if (ch >= 'a' && ch <= 'z')
//		{
//			sum_en++;
//		}
//		else if (ch >= 'A' && ch <= 'Z')
//		{
//			sum_en++;
//		}
//		else if (ch >= '0' && ch <= '9')
//		{
//			sum_num++;
//		}
//		else
//		{
//			sum_other++;
//		}
//	}
//
//	printf("char=%d space=%d digit=%d others=%d\n", sum_en, sum_space, sum_num, sum_other);
//
//
//	return 0;
//}