//#include<stdio.h>
//
//int main() {
//	/*
//		for ( init; condition; increment )
//			{
//			   statement(s);
//			}
//
//		for循环括号中的可省略，只留3个分号
//
//		下面是 for 循环的控制流：
//
//		init 会首先被执行，且只会执行一次。这一步允许您声明并初始化任何循环控制变量。您也可以不在这里写任何语句，只要有一个分号出现即可。
//		接下来，会判断 condition。如果为真，则执行循环主体。如果为假，则不执行循环主体，且控制流会跳转到紧接着 for 循环的下一条语句。
//		在执行完 for 循环主体后，控制流会跳回上面的 increment 语句。该语句允许您更新循环控制变量。该语句可以留空，只要在条件后有一个分号出现即可。
//		条件再次被判断。如果为真，则执行循环，这个过程会不断重复（循环主体，然后增加步值，再然后重新判断条件）。在条件变为假时，for 循环终止。
//	*/
//	
//	// 阶乘 案例
//
//	int i, result = 1;
//	long int num;
//	printf("【阶乘】请输入一个整数：");
//	scanf_s("%d", &num);
//
//	for (i = 1; i <= num; i++)
//	{
//		result *= i;
//	}
//	printf("%ld\n", result);
//
//	// 素数 案例	(素数 大于1的自然数，除了1和它本身外，无法被其他自然数整除的数)
//
//	int x, n;
//	bool JudgePrimeNum = true;
//
//	printf("【判断素数】请输入一个数：");
//	scanf_s("%d", &x);
//
//	/*
//		break	跳出循环
//		continue	跳出这一轮循环，进入下一轮循环
//	*/
//	for (n = 2; n < x; n++)	// n递增，使x%n取余判断素数
//	{
//		if (x % n == 0) {
//			JudgePrimeNum = false;
//			break;
//		}
//		//printf("n = %d\n", n);
//	}
//
//	printf("n = %d\n", n);
//
//	if (JudgePrimeNum == false)
//	{
//		printf("不是素数。\n");
//	}
//	else {
//		printf("是素数。\n");
//	}
//
//	// 嵌套循环：输入1~100内的素数
//
//	int numX;
//	
//	printf("1~100内的素数是：\n");
//
//	for (numX = 2; numX < 100; numX++)
//	{
//		int count;
//		bool JudgePrimeNum2 = true;
//
//		for (count = 2; count < numX; count++)	
//		{
//			if (numX % count == 0) {
//				JudgePrimeNum2 = false;
//				break;	// 此时必须跳出内部循环
//			}
//		}
//
//		if (JudgePrimeNum2 == true)
//		{
//			printf("%d ", numX);
//		}
//	}
//	printf("\n");
//
//	// 嵌套升级：使用计数器，输出多少个素数
//	
//	// numCounter为计数器（递增）
//	int comNum, numCounter = 0, numPlayer;
//
//	printf("你想输出多少个素数：");
//	scanf_s("%d", &numPlayer);
//	
//	for (comNum = 2; numCounter < numPlayer; comNum++)
//	{
//		int count;
//		bool JudgePrimeNum3 = true;
//
//		for (count = 2; count < comNum; count++)
//		{
//			if (comNum % count == 0) {
//				JudgePrimeNum3 = false;
//				break;	// 此时必须跳出内部循环
//			}
//		}
//
//		if (JudgePrimeNum3 == true)
//		{
//			printf("%d ", comNum);
//			numCounter++;
//		}
//	}
//	printf("\n");
//
//	/*
//		goto out;
//
//		out:
//
//		goto函数可以跳出多重嵌套，并跳转到指定的位置
//	*/
//	// 例如
//
//	int ex;
//	for (ex = 0; ex < 100; ex++)
//	{
//		int ex2;
//		for (ex2 = 0; ex2 <= ex; ex2++)
//		{
//			if (ex2 == 76)
//			{
//				printf("尝试逃逸\n");
//				goto example;
//			}
//		}
//	}
//
//example:
//	printf("逃逸成功\n");
//
//	// 实现 分数求和
//
//	int numSum, iSum;
//	//int sign = 1;
//	double sum = 0.0, sign = 1.0;
//
//	printf("输入一个整数：");
//	scanf_s("%d", &numSum);
//	
//	for (iSum = 1; iSum <= numSum; iSum++)
//	{
//		//sum += sign * 1.0 / iSum;
//		sum += sign / iSum;
//		sign *= -1;
//	}
//
//	printf("f(%d) = %f\n", numSum, sum);
//
//
//	return 0;
//}