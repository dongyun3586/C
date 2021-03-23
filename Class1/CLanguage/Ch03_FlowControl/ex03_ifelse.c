#include<stdio.h>

int main_ex03_ifelse() {
	int score;
	printf("점수를 입력하시오: ");
	scanf("%d", &score);

	if (score >= 60)
		printf("합격입니다.\n");
	else
		printf("불합격입니다.\n");

	//// 조건 연산자
	// (score>=60)?printf("합격입니다.\n"): printf("불합격입니다.\n");

	// 윤년 판단 프로그램
	int year;

	printf("연도를 입력하시오: ");
	scanf("%d", &year);

	// 윤년 판단 => 결과 출력
	if ((year%4==0&&year%100!=0) || year%400==0)
		printf("%d년은 윤년입니다.\n", year);
	else
		printf("%d년은 평년입니다.\n", year);

	return 0;
}