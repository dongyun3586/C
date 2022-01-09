#include<stdio.h>

int main() {
	int score;
	printf("점수를 입력하시오: ");
	scanf("%d", &score);

	if (score >= 60)
		printf("합격입니다.\n");
	else
		printf("불합격입니다.\n");

	//// 조건 연산자
	// (score>=60)?printf("합격입니다.\n"): printf("불합격입니다.\n");

	//// 윤년 판단 프로그램
	//int year;

	//printf("연도를 입력하시오: ");
	//scanf("%d", &year);

	//// 윤년 판단 => 결과 출력

	return 0;
}