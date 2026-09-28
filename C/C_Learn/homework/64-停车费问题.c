//#include<stdio.h>
//#include<math.h>
//
//int main() {
//
//	int i = 0;
//	float time[3], time_sum = 0.0;
//	float charge[3], charge_sum = 0.0;
//
//	for ( i = 0; i < 3; i++)
//	{
//		scanf("%f", &time[i]);
//		time_sum += time[i];
//	}
//
//	for ( i = 0; i < 3; i++)
//	{
//		if (time[i] <= 3.0)
//		{
//			charge[i] = 2.00;
//		}
//		else {
//			/*
//				2.2 * 10 = 22
//				21.1 - 3 = 18.1
//				19 * 0.5 = 9.5
//				9.5 + 2.0 =  11.5
//
//				21 - 3 = 20 - 2 >> 18 * 0.5 = 9
//
//				16 - 16 = 0
//				1 - 0 = 1
//
//			*/
//			float tempt = (1.0 - (fabs((int)time[i] - time[i]))) + time[i] - 3.0;
//			if ((1.0 - fabs((int)time[i] - time[i])) == 1.0)
//			{
//				tempt -= 1.0;
//			}
//			//charge[i] = ((int)time[i] - 2) * 0.5 + 2.0;
//			charge[i] = tempt * 0.5 + 2.0;
//			if (charge[i] > 10)
//			{
//				charge[i] = 10.0;
//			}
//		}
//		charge_sum += charge[i];
//	}
//
//
//
//	printf("  Car          Hours         Charge\n");
//
//	for ( i = 0; i < 3; i++)
//	{
//		printf("%5d%15.1f%15.2f\n", i+1, time[i], charge[i]);
//	}
//
//	printf("TOTAL%15.1f%15.2f\n", time_sum, charge_sum);
//
//
//	return 0;
//
//}