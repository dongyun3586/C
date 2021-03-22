#include<stdio.h>

int main() {
	// 삼격형과 원의 넓이 계산에 필요한 변수 선언
	float w, h, r;
	const float PI = 3.14f;

	// 삼각형 계산에 필요한 변수값 입력받기
	printf("삼각형의 너비와 높이: ");
	scanf("%f %f", &w, &h);

	// 삼각형의 넓이 계산 및 출력
	printf("삼각형의 넓이: %f \n", w * h / 2);

	// 원의 반지름 입력받기
	printf("원의 반지름: ");
	scanf("%f", &r);

	// 원의 넓이 계산 및 출력
	printf("원의 넓이: %f \n", r * r * PI);
}