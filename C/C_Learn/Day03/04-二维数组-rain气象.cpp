//#define _CRT_SECURE_NO_WARNINGS
//
///*
//气象研究员Tempest Cloud为完成她的研究项目要分析5年内每个月的降水量数据，
//她首先要解决的问题是如何表示数据。
//一个方案是创建60个变量，每个变量储存一个数据项
//（我们曾经提到过这一笨拙的方案，和以前一样，这个方案并不合适）。
//使用一个内含60个元素的数组比将建60个变量好，但是如果能把各年的数据分开储存会更好，
//即创建5个数组，每个数组12个元素。
//然而，这样做也很麻烦，如果Tempest决定研究50年的降水量，岂不是要创建50个数组。
//是否能有更好的方案？*/
//
//#define YEARS 5
//#define MONTHS 12
//
//#include <stdio.h>
//
//
//int main() {
//
//    // 用2010～2014年的降水量数据初始化数组
//    const float rain[YEARS][MONTHS] =
//    {
//        { 4.3, 4.3, 4.3, 3.0, 2.0, 1.2, 0.2, 0.2, 0.4, 2.4, 3.5, 6.6 },
//        { 8.5, 8.2, 1.2, 1.6, 2.4, 0.0, 5.2, 0.9, 0.3, 0.9, 1.4, 7.3 },
//        { 9.1, 8.5, 6.7, 4.3, 2.1, 0.8, 0.2, 0.2, 1.1, 2.3, 6.1, 8.4 },
//        { 7.2, 9.9, 8.4, 3.3, 1.2, 0.8, 0.4, 0.0, 0.6, 1.7, 4.3, 6.2 },
//        { 7.6, 5.6, 3.8, 2.8, 3.8, 0.2, 0.0, 0.0, 0.0, 1.3, 2.6, 5.2 }
//    };
//
//	int year, month;
//	// 计算每年的降水量
//	float subtotal, total;
//
//	printf(" YEAR    RAINFALL (inches)\n");	// 打印表头
//
//	/*
//	第1个嵌套循环的内层循环，在year不变的情况下，
//	遍历month计算某年的总降水量；
//	而外层循环，改变year的值，重复遍历month，计算5年的总降水量
//	*/
//	for (year = 0, total = 0; year < YEARS; year++)
//	{
//		for (month = 0, subtotal = 0; month < MONTHS; month++)
//		{
//			// 计算每年的降水量
//			subtotal += rain[year][month];
//		}
//		printf("%5d %15.1f\n", 2010 + year, subtotal);
//		total += subtotal;
//	}
//
//	printf("\nThe yearly average is %.1f inches.\n\n", total / YEARS);
//	
//	// 计算每月的平均降水量
//	printf("MONTHLY AVERAGES:\n\n");
//	printf(" Jan Feb Mar Apr May Jun Jul Aug Sep Oct Nov Dec\n");
//
//	for (month = 0; month < MONTHS; month++)
//	{
//		for (year = 0, subtotal = 0; year < YEARS; year++)
//		{
//			subtotal += rain[year][month];
//		}
//		printf("%4.1f ", subtotal / YEARS);
//	}
//	printf("\n");
//
//	// 计算每月的总降水量
//	printf("\nMONTHLY TOTALS:\n\n");
//	printf(" Jan Feb Mar Apr May Jun Jul Aug Sep Oct Nov Dec\n");
//	for (size_t month = 0; month < MONTHS; month++)
//	{
//		for(year = 0, subtotal = 0; year < YEARS; year++)
//		{
//			subtotal += rain[year][month];
//		}
//		printf("%4.1f ", subtotal);
//	}
//	printf("\n");
//
//
//
//	return 0;
//
//
//
//
//}
