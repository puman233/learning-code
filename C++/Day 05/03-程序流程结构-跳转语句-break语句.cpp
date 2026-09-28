//#include<iostream>
//using namespace std;
//
//int main() {
//
//	/*
//		break语句
//
//		作用：用于跳出选择结构或者循环结构
//	*/
//	
//	//break使用时机
//
//	//1.switch语句
//	cout << "请选择副本难度" << endl;
//	cout << "1.普通" << endl;
//	cout << "2.中等" << endl;
//	cout << "3.困难" << endl;
//
//	int select = 0;	//创建选择结果的变量
//
//	cin >> select;
//
//	switch (select)
//	{
//	case 1:
//		cout << "您选择的是【普通】难度" << endl;
//		break;	//退出
//	case 2:
//		cout << "您选择的是【中等】难度" << endl;
//		break;
//	case 3:
//		cout << "您选择的是【困难】难度" << endl;
//		break;
//	default:
//		break;
//	}
//
//	//2.循环语句
//	for (int i = 0; i < 10; i++)
//	{
//		//如果i等于5，退出循环，不再打印
//		if (i == 5)
//		{
//			break;
//		}
//		cout<< i << endl;
//	}
//
//	//3.嵌套循环语句
//	for (int i = 0; i < 10; i++)
//	{
//		for (int j = 0; j < 10; j++)
//		{
//			if (j == 5)
//			{
//				break;	//退出内层循环
//			}
//			cout << " * ";
//		}
//		cout << endl;
//	}
//
//}
