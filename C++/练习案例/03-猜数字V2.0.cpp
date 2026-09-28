//#include<iostream>
//using namespace std;
////time系统时间头文件
//#include<ctime>
//
//int main() {
//
//	while (1)
//	{
//		//添加随机数种子，作用：利用当前系统时间生成随机数，防止每次随机数一样
//		srand((unsigned int)time(NULL));
//
//		//1.生成随机数
//		int num = rand() % 100 + 1;		//生成0 + 1 ~ 99 + 1的随机数
//		//cout << num << endl;
//
//		char exitNum = 0;
//		int timeNum = 5;
//
//		//2.玩家进行猜测
//		printf("欢迎来到【猜数字】游戏\n");
//		printf("您猜测的范围是1~100！\n");
//		printf("输入 0 以退出程序\n");
//
//		while (1)
//		{
//
//			int val = 0;	//玩家输入数据
//
//			cout << "请输入您要猜测的数字：" << endl;
//			cin >> val;
//
//			//3.玩家猜测的判断
//			if (val > num)
//			{
//				cout << "很遗憾，猜测过大！" << endl;
//				cout << "  " << endl;
//			}
//			else if (val < num && val != 0)
//			{
//				cout << "很遗憾，猜测过小！" << endl;
//				cout << "  " << endl;
//			}
//			else if (val == exitNum)
//			{
//				int key = 0;
//				cout << "您真的要退出吗？" << endl;
//				cout << "1：退出 | 2：继续" << endl;
//				cin >> key;
//				if (key == 1)
//				{
//					break;
//				}
//				else if (key == 2)
//				{
//
//				}
//			}
//			else
//			{
//				cout << "恭喜您，猜对了！" << endl;
//				cout << "正确答案为：" << num << endl;
//				cout << "  " << endl;
//				break;
//			}
//
//			int keyNum = 0;
//			cout << "您还想继续游戏吗？" << endl;
//			cout << "1：退出 | 2：继续" << endl;
//			cin >> keyNum;
//			if (keyNum == 2)
//			{
//
//			}
//			else if (keyNum == 1)
//			{
//				break;	//退出程序
//			}
//		}
//
//		//4.猜对，退出游戏	|	猜错，提示猜的结果，过大或过小，重新返回第二步
//	}
//}
//
