#include<stdio.h>

int main() {

	float a, b, c;
	scanf("%f %f %f", &a, &b, &c);

	
	if (a + b > c && a + c > b && b + c > a)
	{
		//printf("Yes\n");
		if (a == b && b == c)
		{
			printf("equilateral triangle\n");
		}
		else if (a == b || a == c || b == c)
		{
			printf("isosceles triangle\n");
		}
		else if (a * a + b * b == c * c || a * a + c * c == b * b || b * b + c * c == a * a)
		{
			printf("right-angled triangle\n");
		}
		else
		{
			printf("ordinary triangle\n");
		}
	}
	else
	{
		printf("It isn't triangle.\n");
	}





	return 0;
}