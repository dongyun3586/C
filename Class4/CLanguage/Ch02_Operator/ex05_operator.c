// (연습문제5) 삼각형과 원의 넓이 구하기 (ex05_operator.c)
#include<stdio.h>

int main() {
	// 필요한 변수 선언
	float w, h;

	// 필요한 값 입력받기
	printf("삼각형의 밑변의 길이와 높이 입력: ");
	scanf("%f %f", &w, &h);

	// 삼각형의 넓이 계산 및 결과 출력
	printf("삼각형의 넓이 %f \n", w * h / 2);


	return 0;
}