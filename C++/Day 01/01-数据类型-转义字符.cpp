#include<iostream>
using namespace std;

/*
	转义字符
		作用：
			用于表示一些不能显示出来的ASCII字符

		常用的有：
			\n
			\\ 
*/
int main() {
	//转义字符

	//换行符	\n
	cout << "hello world\n";
	//反斜杠	\\
	
	cout << "\\" << endl;

	//水平制表符		\t

	cout << "aaaaa\thelloworld" << endl;
	cout << "aaa\thelloworld" << endl;
	cout << "aaaaaaa\thelloworld" << endl;

	system("pause");

	return 0;
};

