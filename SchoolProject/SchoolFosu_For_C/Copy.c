#include<stdio.h>
#include<math.h>

int main()
{
    int a = 135, b = 246, temp;
    temp = a;      // temp = 135
    a = b;         // a = 246
    b = temp;      // b = 135
    printf("a=%5d,b=%5d\n", a, b);
    return 0;
}


//int main()
//{
//    printf("%d,%o,%x,%X\n", 123, 123, 123, 123);
//    printf("%d,%o,%x\n", 0123, 0123, 0123);        // 整数前加0表示该整数为8进制
//    printf("%d,%o,%x\n", 0x123, 0x123, 0x123);     // 整数前加0x表示该整数为16进制
//    return 0;
//}



//int main()
//{
//    float x, y, z;
//    int a;
//    double w;
//
//    x = 3.14;
//    y = 1.5;
//
//    z = (int)x + y;        // 先转换x，再相加
//    a = (int)(x + y);       // 先相加，再转换结果
//    printf("a=%d,z=%f\n", a, z);
//
//    w = (double)(3 / 2);      // 整数除法，再转换
//    printf("%f\n", w);
//
//    return 0;
//}


//int main()
//{
//    float a;
//    int c;
//    a = 3;           // 整数3被隐式转换为浮点数3.0
//    c = a + 2.8;     // 计算后结果被截断为整数
//    printf("a=%f,c=%d\n", a, c);
//    return 0;
//}


//int main()
//{
//    int j, k;
//
//    j = 3;
//    k = ++j;  // 前缀递增：先递增，再赋值
//    printf("j=%d,k=%d\n", j, k);
//
//    j = 3;
//    k = j++;  // 后缀递增：先赋值，再递增
//    printf("j=%d,k=%d\n", j, k);
//
//    return 0;
//}


//int main() {
//    int intA, intB;
//    printf("Enter num1:");
//    scanf("%d", &intA);
//    printf("Enter num2:");
//    scanf("%d", &intB);
//    printf("%d+%d=%d\n", intA, intB, intA + intB);  // 修正：改为+
//    printf("%d-%d=%d\n", intA, intB, intA - intB);
//    printf("%d*%d=%d\n", intA, intB, intA * intB);  // 修正：添加*
//    printf("%d/%d=%.2f\n", intA, intB, (float)intA / intB);  // 修正：添加/
//    printf("%d%%%d=%d\n", intA, intB, intA % intB);
//    return 0;
//}


//int main() {
//	int intA, intB;
//	scanf("%d %d", &intA, &intB);
//
//	printf("A+B=%d\n", intA + intB);
//	printf("A*B=%d\n", intA * intB);
//	printf("A-B=%d\n", intA - intB);
//	printf("A/B=%d\n", intA / intB);
//	printf("A mod B=%d\n", intA % intB);
//
//	return 0;
//}


//int main() {
//	float a;
//	double b;
//	a = 123456789.123456789;
//	b = 123456789.123456789;
//	printf("a=%f\n", a);
//	printf("b=%lf\n", b);
//
//	return 0;
//}



//int main() {
//	int a = 5;
//	double x;
//	printf("%d %d\n", sizeof(int), sizeof(a));
//	printf("%d %d\n", sizeof(double), sizeof(x));
//	printf("%d %d\n", sizeof(float), sizeof(char));
//
//	return 0;
//}


//int main() {
//	int num1;
//	char num2;
//	num1 = 10;
//	num2 = '1';
//	num1 += num2;
//
//	printf("%d\n", num1);
//
//	return 0;
//}


//int main() {
//	char charC;
//	scanf("%c", &charC);
//	printf("%c's ASCII is %d\n", charC, charC);
//
//	return 0;
//}


//int main(){
//	int num, total;
//	num = 10;
//	total = num * PRICE;
//
//	printf("total=%d\n", total);
//	return 0;
//}

//int main() {
//	unsigned int a, b;
//	// int 最大值为：2147483647
//	a = pow(2, 31) - 1;
//	b = a + 1;
//	printf("a=%d\n", a);
//	printf("b=%d\n", b);
//
//	return 0;
//}