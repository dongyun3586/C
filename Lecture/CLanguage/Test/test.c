#include<stdio.h>
#include<math.h>

#define PI 3.1415926535  // 180

int main(void) {

	int angle[] = { 0,30,45,60,90 };
	double rad[] = { 0,PI / 6,PI / 4,PI / 3,PI / 2 };
	
	for (int i = 0; i < 5; i++)
		printf("sin(%d) = %lf\n", angle[i], sin(rad[i]));
	printf("\n");

	for (int i = 0; i < 5; i++)
		printf("cos(%d) = %lf\n", angle[i], cos(rad[i]));
	printf("\n");

	for (int i = 0; i < 4; i++)
		printf("tan(%d) = %lf\n", angle[i], tan(rad[i]));
	printf("\n");

	return 0;
}