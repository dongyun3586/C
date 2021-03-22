#include<stdio.h>

int main() {

	// 1. 실행문장이 하나인 경우 { } 생략 가능
	int number;
	printf("정수를 입력하시오: ");
	scanf("%d", &number);

	if (number > 0) 
		printf("\n양수입니다.");
	
	printf("\n작업1 종료\n\n");

	// 2. 실행문장이 둘 이상인 경우 { } 사용
	int score;
	printf("점수를 입력하시오: ");
	scanf("%d", &score);
	char grade;

	if (score >= 90) {
		grade = 'A';
		printf("\n당신의 점수는 %d점이고, 학점은 %c입니다.", score, grade);
	}
	printf("\n작업2 종료\n\n");

	// 3. 참(0이 아님)과 거짓(0)
	if (0)
		printf("'0'은 거짓\n");
	if (1)
		printf("'1'은 참\n");				// '1'은 참
	if (2)
		printf("'2'는 참\n");				// '2'는 참
	if (-1)
		printf("'-1'은 참\n");				// '-1'은 참
	if ('a')
		printf("'a'는 참\n");				// 'a'는 참
	if ("안녕하세요")
		printf("\"안녕하세요\"는 참\n");	// "안녕하세요"는 참

	return 0;
}