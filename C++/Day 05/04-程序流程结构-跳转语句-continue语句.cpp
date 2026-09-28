//#include<iostream>
//using namespace std;
//
//int main() {
//	
//	/*
//		continue语句
//			作用：在循环语句中，跳过本次循环中余下尚未执行的语句，继续执行下一次循环
//	*/
//
//	for (int i = 0; i <= 100; i++)
//	{
//		//奇数输出，偶数不输出
//		if (i % 2 ==0)
//		{
//			continue;	//可以筛选条件，执行到此就不再向下执行，执行下一次循环
//			//break	会退出循环，而continue不会
//		}
//		cout << i << endl;
//	}
//
//	cout << "——————分割线——————" << endl;
//
//	for (int i = 0; i < 100; i++)
//	{
//		//奇数不输出，偶数输出
//		if (i % 2 != 0)
//		{
//			continue;
//		}
//		cout << i << endl;
//	}
//}