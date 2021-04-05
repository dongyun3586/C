#include<stdio.h>

int main() {
	// rand()함수의 랜덤 숫자 생성을 위한 seed값 설정
	srand(time(NULL));

	// 변수 선언
	int inputNum, jungdap, count=0;

	// 1~100 사이의 랜덤 숫자 저장
	jungdap = rand() % 100 + 1;

	// 게임 소개 문자열 출력
	printf("1~100사이의 숫자를 추측하는 게임입니다.\n");

	// 테스트를 위한 정답 출력
	printf("\n정답: %d\n\n", jungdap);
	
	// 정답을 맞출 때 까지 반복 실행
	while (1) {
		// 추측 횟수 1 증가 시키기
		count++;

		// 사용자에게 1~100사이의 정수값 입력받기
		printf("정답은?: ");
		scanf("%d", &inputNum);

		// 사용자가 입력한 값과 정답 비교
		if (jungdap < inputNum)
			printf("틀렸습니다. %d 보다 작습니다.\n", inputNum);
		else if (jungdap > inputNum)
			printf("틀렸습니다. %d 보다 큽니다.\n", inputNum);
		else {
			printf("정답입니다.\n");
			break;
		}
	}

	// 추측 횟수 출력
	printf("\n%d번 만에 맞혔습니다.\n", count);

	return 0;
}