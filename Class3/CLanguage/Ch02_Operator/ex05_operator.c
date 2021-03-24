// (연습문제5) 삼각형과 원의 넓이 구하기 (ex05_operator.c)
#include<stdio.h>

int main() {
	// 필요한 변수 선언
	float w, h, r;
	const float PI = 3.14f;

	// 삼각형의 밑변 길이와 높이 값을 입력받기
	printf("삼각형의 너비와 높이: ");
	scanf("%f %f", &w, &h);

	// 삼각형의 넓이를 계산해서 출력
	printf("삼각형의 넓이: %f \n", w * h / 2);

	// 원의 반지름 입력받기

	// 원의 넓이를 계산해서 출력

	return 0;
}