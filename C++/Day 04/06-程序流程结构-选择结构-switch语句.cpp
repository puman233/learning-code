//#include<iostream>
//using namespace std;
//
//int main() {
//
//	/*
//		switch语句
//			
//			作用：
//				执行多条分支语句
//	*/
//
//	//给电影进行打分
//	// 10 ~ 9 经典
//	// 8 ~ 7 非常好
//	// 6 ~ 5 一般
//	// < 5 差
//
//	//1.用户提示给电影打分
//	cout << "请给这部电影进行打分。" << endl;
//	cout << "切记是十分制哦o((>ω< ))o" << endl;
//
//	//2.用户开始打分
//	int score = 0;
//	cin >> score;
//	cout << "您输入的分数为：" << score << endl;
//
//	//3.根据用户输入的分数来提示用户最后的结果
//	switch (score)
//	{
//	case 10:
//		cout << "您认为是经典电影！" << endl;
//		break;
//	case 9:
//		cout << "您认为是经典电影！" << endl;
//		break;
//	case 8:
//		cout << "您认为电影非常好！" << endl;
//		break;
//	case 7:
//		cout << "您认为电影非常好！" << endl;
//		break;
//	case 6:
//		cout << "您认为电影一般！" << endl;
//		break;
//	case 5:
//		cout << "您认为电影一般！" << endl;
//		break;
//	default:
//		cout << "您认为这是烂片！" << endl;
//	}
//
//	system("pause");
//}