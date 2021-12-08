#include<stdio.h>
#include<stdlib.h>  //rand(), srand() 
#include<time.h>  // time()
#include<windows.h>  // COORD, SetConsoleCursorPosition, SetConsoleTextAttribute

#define length 17
#define row 10

void gotoxy(int x, int y);  // 좌표 이동
void color(int color_number);  // 글자 색깔 바꾸기
void makesadari(int arr[row][length]);
void printsadari(int arr[row][length], int i, int j, int n);

int main() {
	int map[row][length] = {  //사다리 세로줄 10, 가로 최대 100까지 가능
	{0},
	{0}
	};

	char* stuNum[] = { "명준", "규헌", "동빈", "성우", "시우", "영우", "은우", "정우", "현우", "명헌", "정민", "원상", "종훈", "수민", "하진", "정윤", "지민" };

	// 학생 이름 출력
	printf(" ");
	for (int i = 0; i < length; i++) {
		printf(" %s", *(stuNum + i));
	}
	printf("\n");
	// 사다리 만들기
	makesadari(map);

	// 사다리 출력
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < length; j++) {
			printsadari(map, i, j, 0);
		}
		printf("\n");
	}

	int result[100] = { 0 };  //결과 배열
	for (int i = 0; i < length; i++)  //배열 초기화
		result[i] = i + 1;

	srand(time(NULL));
	for (int i = 0; i < 30; i++) {    // 섞는작업을 30번 반복하기
		int randNum1 = rand() % length;    // 1~사람 수 까지의 랜덤한 수를 발생한다.
		int randNum2 = rand() % length;
		int temp;

		temp = result[randNum1];
		result[randNum1] = result[randNum2];
		result[randNum2] = temp;
	}

	// 결과줄 출력
	for (int i = 0; i < length; i++)
		printf("%5d", result[i]);

	int jul = 0, temp = 0;  //사다리 내려가기 시작할 줄, 결과 출력할 때 쓰일 값

	// 사다리 내려가기 및 결과 출력
	for (int k = 1; k <= length; k++) {

		// 사다리 내려갈 줄 입력받기
		printf("\n\n   몇번째 줄에서 내려갈까요? 전체 결과를 보려면 0을 입력하세요. : ");
		scanf("%d", &jul);
		temp = jul;
		jul--;  //배열 0부터 시작하니까 1 빼줌

		//한번에 결과 출력
		if (temp == 0) {
			for (int h = 0; h < length; h++) {
				int track = h;
				for (int i = 0; i < row; i++) {
					for (int j = 1; j <= row; j++) {
						//어디로 내려갈지 판단하기
						if (map[i][track] == 0 && map[i][track + 1] == 1) {
							track++;
							break;
						}
						else if (map[i][track] == 1) {
							track--;
							break;
						}
					}
				}
				printf("   %s: %2d번 자리\n", *(stuNum + h), result[track]);
			}
			break;
		}

		//하나씩 내려가기
		else {
			color(k);  //글자 색깔 바꾸기. 새로 내려갈 때마다 색깔이 바뀌도록 함

			for (int i = 0; i < row; i++) {
				for (int j = 0; j < row; j++) {
					gotoxy(jul, i - 1); //좌표 이동
					printsadari(map, i, jul, 50); // 새로운 색깔로 사다리 재출력

					if (map[i][jul] == 0 && map[i][jul + 1] == 1) { //다음에 어디로 내려갈지 판단하기
						jul++;
						gotoxy(jul, i - 1);
						printsadari(map, i, jul, 50);
						break;
					}

					else if (map[i][jul] == 1) {
						jul--;
						break;
					}
				}
			}
		}
		for (int h = 0; h <= 5 * k; h++) {
			printf("\n");
		}
		color(15);  // 15는 하얀색
		// 결과 출력
		printf("   %s의 자리는 %d~\n", *(stuNum + temp - 1), result[jul]);
	}
	return 0;
}

// 좌표 이동
void gotoxy(int x, int y) {
	COORD Pos;
	Pos.X = 5 * x;  // %c%c%c%c로 출력하기 때문에 5를 곱해줘야 알맞은 자리에 들어감
	Pos.Y = 2 + y;  // 사람 수 입력 줄과 번호 출력 줄을 고려해서 2를 더해줌
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
// 글자 색깔 바꾸기
void color(int color_number) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_number);
};

void makesadari(int arr[row][length]) {
	srand(time(NULL));

	for (int i = 1; i < row - 1; i++) {
		for (int j = 1; j < length; j++) {
			arr[i][j] = rand() % 2;

			if (arr[i][j - 1] == 1 && arr[i][j] == 1)  //연속으로 ㅓ가 생기지 않도록 함
				arr[i][j] = 0;  // 1을 0으로 바꿔줌
		}
	}

}

void printsadari(int arr[row][length], int i, int j, int n) {
	if (arr[i][j] == 1) {
		printf("%c%c%c%c%c", 6, 6, 6, 6, 23); //아스키코드 -, -, -, ㅓ
		Sleep(n * 10);
	}

	if (arr[i][j] == 0) {
		printf("%5c", 5); // 아스키코드 ㅣ
		Sleep(n);
	}
}