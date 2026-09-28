#include<stdio.h>
#include<math.h>

int main() {

	float r, h;
	float zc = 0, mj = 0, cmj = 0, v = 0;
	float pai = 3.1415926;

	scanf("%f %f", &r, &h);

	zc = r * 2 * pai;
	mj = pow(r, 2.0) * pai;

	cmj = zc * h;

	v = mj * h;

	printf("%.2f %.2f %.2f %.2f", zc, mj, cmj, v);



	return 0;
}