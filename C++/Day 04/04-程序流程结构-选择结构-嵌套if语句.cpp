//#include<iostream>
//using namespace std;
//
///*
//	嵌套if语句
//		在if语句中，可是嵌套使用if语句，达到更精准的条件判断
//*/
//
//int main() {
//	
//	//接着上个笔记的问题
//
//	//1.输入高考分数
//	int score = 0;
//	cout << "请输入您的考试分数：" << endl;
//	cin >> score;
//
//	//2.显示高考分数
//	cout << "您输入的考试分数：" << score << endl;
//
//	//3.判断
//	if (score>600)
//	{
//		cout << "恭喜您，考上了一本大学！" << endl;
//		cout << "想确认您可以考上那所高校？" << endl;
//		cout << "请等待……" << endl;
//
//		if (score > 700) {
//			cout << "恭喜您，考上了北京大学！" << endl;
//		}
//		else if (score > 650)
//		{
//			cout << "恭喜您，考上了清华大学！" << endl;
//		}
//		else if(score>600)
//		{
//			cout << "您可以考入人民大学！" << endl;
//			cout << "或许，您可以考虑其他的大学！" << endl;
//		}
//	}
//	else if (score>500)
//	{
//		cout << "恭喜您，考上了二本大学！" << endl;
//	}
//	else if (score>400)
//	{
//		cout << "恭喜您，考上了三本大学！" << endl;
//	}
//	else
//	{
//		cout << "很遗憾，您未能考上大学。再接再厉！" << endl;
//	}
//
//	system("pause");
//
//	return 0;
//}