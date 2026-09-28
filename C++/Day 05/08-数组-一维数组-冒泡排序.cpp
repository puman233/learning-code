#include<iostream>
using namespace std;

/*
	作用：最常用的排序算法，对数组内元素进行排序

	比较相邻的元素，如果第一个比第二个大，就交换他们两个
	对每一个相邻元素做同样的工作，执行完毕后，找到一个最大值
	重复以上的步骤，每次比较次数-1，直到不需要比较
*/

int main() {
	//1.利用冒泡顺序实现升序序列
	int arr[9] = { 4,2,5,0,7,1,9,6,3 };

	cout << "排序前：" << endl;
	for (int a = 0; a < 9; a++) {
		cout << arr[a] << "  ";
	}
	cout << endl;

	//开始冒泡顺序
	//总共排序轮数为 元素个数-1
	for (int i = 0; i < 9 - 1; i++) {
		//内层循环对比 次数 = 元素个数 - 当前轮数 -1
		for (int j = 0; j < 9 - i - 1; j++) {
			//如果第一个数字，比第二个数字大，交换两个数字
			if (arr[j] < arr [j + 1] ) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	//排序后结果
	cout << "排序后：" << endl;
	for (int a = 0; a < 9; a++) {
		cout << arr[a] << "  ";
	}
	cout << endl;

	system("pause");

	return 0;
}