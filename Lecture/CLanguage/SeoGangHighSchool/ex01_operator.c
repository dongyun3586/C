#include<stdio.h>

int main1() {
	float w, h, r, pi = 3.14;
	printf("삼각형의 너비와 높이: ");
	scanf("%f %f", &w, &h);

	printf("삼각형의 넓이: %f\n", w * h / 2);

	printf("원의 반지름: ");
	scanf("%f", &r);
	printf("원의 넓이: %f\n", r * r * pi);

	return 0;
}