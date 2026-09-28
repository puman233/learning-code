#include<iostream>
using namespace std;

int main() {
	//Âß¼­ÔËËã·û		Óë &&

	int a = 10;
	int b = 10;

	cout << (a && b) << endl;

	a = 0;
	b = 10;
	cout << (a && b) << endl;

	a = 0;
	b = 0;
	cout << (a && b) << endl;


	system("pause");
}