#include<stdio.h>
#include<stdlib.h>  //rand(), srand() 
#include<time.h>  // time()
#include<windows.h>  // COORD, SetConsoleCursorPosition, SetConsoleTextAttribute

void gotoxy(int x, int y);  // 좌표 이동
void color(int color_number);  // 글자 색깔 바꾸기

int main() {

	int length; //사다리 가로줄 수

	int map[10][100] = {  //사다리 세로줄 10, 가로 최대 100까지 가능
	{0},
	{0}
	};

	int row = sizeof(map) / sizeof(map[0]); //사다리 세로 줄 

	srand(time(NULL));

	printf("사람 수를 입력하세요: ");
	scanf("%d", &length);

	// 사다리 번호 출력
	for (int i = 1; i <= length; i++) {

		if (i <= 10)
			printf("   %d", i);

		else if (i >= 10)  //사람수가 10이 늘어나면 한칸씩 땡겨서 줄 바로 위에 숫자가 있도록 함
			printf("  %d", i);
		// 100부터는 배열을 넘어가고 솔직히 100명이서 사다리타기를 할 일도 없을 것 같아요
	}
	printf("\n");

	// 사다리 만들기
	for (int i = 1; i < row - 1; i++) {  //맨 첫 가로줄과 마지막 가로줄은 1이 생기지 않도록 함

		for (int j = 1; j < length; j++) {
			map[i][j] = rand() % 2;

			if (map[i][j - 1] == 1 && map[i][j] == 1)  //연속으로 ㅓ가 생기지 않도록 함
				map[i][j] = 0;  // 1을 0으로 바꿔줌
		}
	}

	// 사다리 출력
	for (int i = 0; i < row; i++) {

		for (int j = 0; j < length; j++) {

			if (map[i][j] == 1)
				printf("%c%c%c%c", 6, 6, 6, 23); //아스키코드 -, -, -, ㅓ

			if (map[i][j] == 0)
				printf("   %c", 5); // 아스키코드 ㅣ

		}
		printf("\n");
	}


	int result[100] = { 0 };  //꽝, 당첨 결과가 있는 배열

	result[rand() % length] = 1;  // result 배열 중 하나는 1(당첨)이 들어가도록 함

	// 결과줄 출력
	for (int i = 0; i < length; i++) {

		if (result[i] == 0)
			printf("  꽝");

		else if (result[i] == 1)
			printf(" 당첨");
	}

	int jul = 0, temp = 0;  //사다리 내려가기 시작할 줄, 결과 출력할 때 쓰일 값

	// 사다리 내려가기 및 결과 출력
	for (int k = 1; k <= length; k++) {

		// 사다리 내려갈 줄 입력받기
		printf("\n\n몇번째 줄에서 내려갈까요?: ");
		scanf("%d", &jul);
		temp = jul;
		jul--;  //배열 0부터 시작하니까 1 빼줌

		color(k);  //글자 색깔 바꾸기. 새로 내려갈 때마다 색깔이 바뀌도록 함

		for (int i = 0; i < row; i++) {

			for (int j = 1; j <= 10; j++) {

				// 좌표 이동
				gotoxy(jul, i);

				// 새로운 색깔로 사다리 경로 재출력
				if (map[i][jul] == 0) {

					printf("   %c", 5);
					Sleep(50);  //기다리기
				}

				else if (map[i][jul] == 1) {

					printf("%c%c%c%c", 6, 6, 6, 23);
					Sleep(200);  //기다리기
				}

				//다음에 어디로 내려갈지 판단하기

				if (map[i][jul] == 0 && map[i][jul + 1] == 1) {

					jul++;

					gotoxy(jul, i);

					if (map[i][jul] == 0) {
						printf("   %c", 5);
						Sleep(50);  //기다리기
					}

					else if (map[i][jul] == 1) {
						printf("%c%c%c%c", 6, 6, 6, 23);
						Sleep(200);  //기다리기
					}

					break;
				}

				else if (map[i][jul] == 1) {

					jul--;

					break;
				}
			}
		}

		for (int h = 0; h <= 5 * k; h++) {

			printf("\n");
		}

		color(15);  // 15는 하얀색

		// 결과 출력
		if (result[jul] == 0)
			printf("%d번째 줄의 결과는 꽝입니다~\n", temp);

		else if (result[jul] == 1)
			printf("%d번째 줄의 결과는 당첨입니다!\n", temp);
	}

	return 0;
}

// 좌표 이동
void gotoxy(int x, int y) {

	COORD Pos;

	Pos.X = 4 * x;  // %c%c%c%c로 출력하기 때문에 4를 곱해줘야 알맞은 자리에 들어감
	Pos.Y = 2 + y;  // 사람 수 입력 줄과 번호 출력 줄을 고려해서 2를 더해줌

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);

}

// 글자 색깔 바꾸기
void color(int color_number) {

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_number);
};