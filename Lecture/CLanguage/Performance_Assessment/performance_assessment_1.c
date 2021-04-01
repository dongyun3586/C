#include<stdio.h>

int main() {
	int inputNum, jungdap, count=0;

	// 1~100 사이의 랜덤 숫자 생성 및 저장
	srand(time(NULL));
	jungdap = rand() % 100 + 1;

	// 정답 출력
	printf("jungdap: %d\n", jungdap);
	
	printf("1~100사이의 숫자를 추측하는 게임입니다.\n");
	
	while (1) {
		// 사용자에게 1~100사이의 정수값 입력받기
		printf("1~100사이의 값 입력: ");
		scanf("%d", &inputNum);

		// 추측 횟수 1 증가 시키기
		count++;

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

	printf("\n%d번만에 맞혔습니다.\n", count);

	return 0;
}