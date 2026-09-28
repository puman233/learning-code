#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main() {

	double pi = 0;
	
	int count = 1, n = 1;
	
	double temp = 1.0;

	while (temp >= 0.00000001) {

		/*if (count % 2 == 1) {
			pi += 1.0 / count;
		}
		else {
			pi -= 1.0 / count;
		}*/

		//pi += (count % 2 == 1 ? 1.0 : -1.0) / count;

		pi += pow(-1, ++n) / count;

		count += 2;

		temp = 1.0 / count;
	}

	printf("pi=%.8lf\n", pi * 4.0);

	return 0;
}