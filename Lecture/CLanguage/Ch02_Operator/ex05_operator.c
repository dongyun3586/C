/* (연습문제5) 삼각형과 원의 넓이 구하기 */

#include<stdio.h>

int main_ex05_operator() {
	// 변수 선언
	double width, height, radius;
	const float PI = 3.14;

	// 삼각형의 넓이 구하기
	printf("삼각형의 너비와 높이: ");
	scanf_s("%f %f", &width, &height);
	printf("삼각형의 넓이: %f\n\n", width * height / 2);

	// 원의 넓이 구하기
	printf("원의 반지름: ");
	scanf_s("%f", &radius);
	printf("원의 넓이: %f\n", radius * radius * PI);

	return 0;
}