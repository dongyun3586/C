#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h> //랜덤 숫자 생성, 시간 지연**
#include<windows.h>

#define N 25

void gotoxy(int x, int y);
void ConwayTest(int(*arr)[N]);    //중요한 함수. 이 함수에서 다음 단계의 배열을 만든다.
void printConwayArray(int(*arr)[N], int repeat);    //콘웨이 생명게임을 하는 총괄적인 함수
void print2DArray(int arr[][N]);      //그냥 2차원배열 출력



int main() {

	//배열의 인자 생성
	srand(time(NULL));
	int numArr[N][N]; //처음 생성됨

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			numArr[i][j] = rand() % 2;
	}

	//몇 번 반복할 것인지 입력받음
	int repeat;
	printf("\ LIFE GAME\n\n23/3\n\n몇 번 반복하시겠습니까?  (5 < 반복 횟수 < 50) : ");
	scanf("%d", &repeat);
	if (repeat <= 4) {
		printf("범위에 맞지 않는 식입니다.\n생명 게임을 종료합니다.");
		return 0;
	}
	//처음 출력
	system("cls");
	print2DArray(numArr);
	system("cls");

	printConwayArray(numArr, repeat);
	Sleep(2000);

	gotoxy(55, 55);
	printf("게임 종료");
	return 0;
}

void gotoxy(int x, int y)

{

	COORD pos = { x,y };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

}

void ConwayTest(int(*arr)[N]) {

	int i, j;

	//처음 입력받은 배열 저장용 생성
	int* cpyArr[N][N]; //numArr 바꿀 때 쓰는 저장용 배열

	//cpyArr(전 단계 원형 보존)에 arr 복사 (NGD)
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++) {
			cpyArr[i][j] = arr[i][j];
		}
	}

	//테스트 : NGD

	for (i = 0; i < N; i++) {
		for (j = 1; j < N; j++) {

			if (arr[i][j] == 1) //현재 살아있을 때
			{
				if (i == 0 && j == 0) {   //(0,0)
					if ((int)(cpyArr[0][1] + 1) * ((int)cpyArr[1][0] + 1) * ((int)cpyArr[1][1] + 1) == 8 || (int)(cpyArr[0][1] + 1) * ((int)cpyArr[1][0] + 1) * ((int)cpyArr[1][1] + 1) == 4) {
						arr[i][j] = 1;
					}
					else
						arr[i][j] = 0;
				}
				else if (i == N - 1 && j == 0) {   // (N-1,0)
					if ((int)(cpyArr[N - 2][1] + 1) * ((int)cpyArr[N - 2][0] + 1) * ((int)cpyArr[N - 1][1] + 1) == 8 || (int)(cpyArr[N - 2][1] + 1) * ((int)cpyArr[N - 2][0] + 1) * ((int)cpyArr[N - 1][1] + 1) == 4) {
						arr[i][j] = 1;
					}
					else
						arr[i][j] = 0;
				}
				else if (i == 0 && j == N - 1) {  // (0, N-1)
					if ((int)(cpyArr[N - 2][1] + 1) * ((int)cpyArr[N - 2][0] + 1) * ((int)cpyArr[N - 1][1] + 1) == 8 || (int)(cpyArr[N - 2][1] + 1) * ((int)cpyArr[N - 2][0] + 1) * ((int)cpyArr[N - 1][1] + 1) == 4) {
						arr[i][j] = 1;
					}
					else
						arr[i][j] = 0;
				}
				else if (i == N - 1 && j == N - 1) {   // (N-1, N-1)
					if ((int)(cpyArr[N - 2][N - 1] + 1) * ((int)cpyArr[N - 1][N - 2] + 1) * ((int)cpyArr[N - 2][N - 2] + 1) == 8 || (int)(cpyArr[N - 2][N - 1] + 1) * ((int)cpyArr[N - 1][N - 2] + 1) * ((int)cpyArr[N - 2][N - 2] + 1) == 4) {
						arr[i][j] = 1;
					}
					else
						arr[i][j] = 0;
				}
				else if (i == 0) {   // 위쪽 행
					if (((int)cpyArr[1][j - 1] + 1) * ((int)cpyArr[1][j] + 1) * ((int)cpyArr[1][j + 1] + 1) * ((int)cpyArr[0][j - 1] + 1) * ((int)cpyArr[0][j + 1] + 1) == 8 || ((int)cpyArr[1][j - 1] + 1) * ((int)cpyArr[1][j] + 1) * ((int)cpyArr[1][j + 1] + 1) * ((int)cpyArr[0][j - 1] + 1) * ((int)cpyArr[0][j + 1] + 1) == 4)
						arr[i][j] = 1;
					else arr[i][j] = 0;
				}
				else if (i == N - 1) {   // 아래쪽 행
					if (((int)cpyArr[N - 2][j - 1] + 1) * ((int)cpyArr[N - 2][j] + 1) * ((int)cpyArr[N - 2][j + 1] + 1) * ((int)cpyArr[N - 1][j - 1] + 1) * ((int)cpyArr[N - 1][j + 1] + 1) == 8 || ((int)cpyArr[N - 2][j - 1] + 1) * ((int)cpyArr[N - 2][j] + 1) * ((int)cpyArr[N - 2][j + 1] + 1) * ((int)cpyArr[N - 1][j - 1] + 1) * ((int)cpyArr[N - 1][j + 1] + 1) == 4)
						arr[i][j] = 1;
					else arr[i][j] = 0;
				}
				else if (j == 0) {   // 왼쪽 행
					if (((int)cpyArr[i - 1][0] + 1) * ((int)cpyArr[i + 1][0] + 1) * ((int)cpyArr[i - 1][1] + 1) * ((int)cpyArr[i][1] + 1) * ((int)cpyArr[i + 1][1] + 1) == 8 || ((int)cpyArr[i - 1][0] + 1) * ((int)cpyArr[i + 1][0] + 1) * ((int)cpyArr[i - 1][1] + 1) * ((int)cpyArr[i][1] + 1) * ((int)cpyArr[i + 1][1] + 1) == 4)
						arr[i][j] = 1;
					else arr[i][j] = 0;
				}
				else if (j == N - 1) {  //오른쪽 행
					if (((int)cpyArr[i - 1][N - 1] + 1) * ((int)cpyArr[i + 1][N - 1] + 1) * ((int)cpyArr[i - 1][N - 2] + 1) * ((int)cpyArr[i][N - 2] + 1) * ((int)cpyArr[i + 1][N - 2] + 1) == 8 || ((int)cpyArr[i - 1][N - 1] + 1) * ((int)cpyArr[i + 1][N - 1] + 1) * ((int)cpyArr[i - 1][N - 2] + 1) * ((int)cpyArr[i][N - 2] + 1) * ((int)cpyArr[i + 1][N - 2] + 1) == 4)
						arr[i][j] = 1;
					else arr[i][j] = 0;
				}
				else {   // 나머지 = 판의 내부
					if (((int)cpyArr[i - 1][j - 1] + 1) * ((int)cpyArr[i - 1][j] + 1) * ((int)cpyArr[i - 1][j + 1] + 1) * ((int)cpyArr[i][j - 1] + 1) * ((int)cpyArr[i][j + 1] + 1) * ((int)cpyArr[i + 1][j - 1] + 1) * ((int)cpyArr[i + 1][j] + 1) * ((int)cpyArr[i + 1][j + 1] + 1) == 8 || ((int)cpyArr[i - 1][j - 1] + 1) * ((int)cpyArr[i - 1][j] + 1) * ((int)cpyArr[i - 1][j + 1] + 1) * ((int)cpyArr[i][j - 1] + 1) * ((int)cpyArr[i][j + 1] + 1) * ((int)cpyArr[i + 1][j - 1] + 1) * ((int)cpyArr[i + 1][j] + 1) * ((int)cpyArr[i + 1][j + 1] + 1) == 4)
						arr[i][j] = 1;
					else arr[i][j] = 0;
				}
				break;

			}

			else if (arr[i][j] == 0) //현재 죽어있을 때
			{
				if (i == 0 && j == 0) {   //(0,0)
					if ((int)(cpyArr[0][1] + 1) * ((int)cpyArr[1][0] + 1) * ((int)cpyArr[1][1] + 1) == 8) {
						arr[i][j] = 1;
					}
					else
						arr[i][j] = 0;
				}
				else if (i == N - 1 && j == 0) {   // (N-1,0)
					if ((int)(cpyArr[N - 2][1] + 1) * ((int)cpyArr[N - 2][0] + 1) * ((int)cpyArr[N - 1][1] + 1) == 8) {
						arr[i][j] = 1;
					}
					else
						arr[i][j] = 0;
				}
				else if (i == 0 && j == N - 1) {  // (0, N-1)
					if ((int)(cpyArr[N - 2][1] + 1) * ((int)cpyArr[N - 2][0] + 1) * ((int)cpyArr[N - 1][1] + 1) == 8) {
						arr[i][j] = 1;
					}
					else
						arr[i][j] = 0;
				}
				else if (i == N - 1 && j == N - 1) {   // (N-1, N-1)
					if ((int)(cpyArr[N - 2][N - 1] + 1) * ((int)cpyArr[N - 1][N - 2] + 1) * ((int)cpyArr[N - 2][N - 2] + 1) == 8) {
						arr[i][j] = 1;
					}
					else
						arr[i][j] = 0;
				}
				else if (i == 0) {   // 위쪽 행
					if (((int)cpyArr[1][j - 1] + 1) * ((int)cpyArr[1][j] + 1) * ((int)cpyArr[1][j + 1] + 1) * ((int)cpyArr[0][j - 1] + 1) * ((int)cpyArr[0][j + 1] + 1) == 8)
						arr[i][j] = 1;
					else arr[i][j] = 0;
				}
				else if (i == N - 1) {   // 아래쪽 행
					if (((int)cpyArr[N - 2][j - 1] + 1) * ((int)cpyArr[N - 2][j] + 1) * ((int)cpyArr[N - 2][j + 1] + 1) * ((int)cpyArr[N - 1][j - 1] + 1) * ((int)cpyArr[N - 1][j + 1] + 1) == 8)
						arr[i][j] = 1;
					else arr[i][j] = 0;
				}
				else if (j == 0) {   // 왼쪽 행
					if (((int)cpyArr[i - 1][0] + 1) * ((int)cpyArr[i + 1][0] + 1) * ((int)cpyArr[i - 1][1] + 1) * ((int)cpyArr[i][1] + 1) * ((int)cpyArr[i + 1][1] + 1) == 8)
						arr[i][j] = 1;
					else arr[i][j] = 0;
				}
				else if (j == N - 1) {  //오른쪽 행
					if (((int)cpyArr[i - 1][N - 1] + 1) * ((int)cpyArr[i + 1][N - 1] + 1) * ((int)cpyArr[i - 1][N - 2] + 1) * ((int)cpyArr[i][N - 2] + 1) * ((int)cpyArr[i + 1][N - 2] + 1) == 8)
						arr[i][j] = 1;
					else arr[i][j] = 0;
				}
				else {   // 나머지 = 판의 내부
					if (((int)cpyArr[i - 1][j - 1] + 1) * ((int)cpyArr[i - 1][j] + 1) * ((int)cpyArr[i - 1][j + 1] + 1) * ((int)cpyArr[i][j - 1] + 1) * ((int)cpyArr[i][j + 1] + 1) * ((int)cpyArr[i + 1][j - 1] + 1) * ((int)cpyArr[i + 1][j] + 1) * ((int)cpyArr[i + 1][j + 1] + 1) == 8)
						arr[i][j] = 1;
					else arr[i][j] = 0;
				}
				break;
			}

		}
	}

	//배열 출력하기
	print2DArray(arr);

}

void printConwayArray(int(*arr)[N], int repeat) {
	//repeat번 반복
	while (repeat >= 1) {

		ConwayTest(*arr);

		//시간 지연(0.5s)
		Sleep(500);
		repeat--;
	}

}

void print2DArray(int arr[][N]) {
	gotoxy(1, 1);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			gotoxy(2 * i + 1, j + 1);
			printf("%d ", arr[i][j]);    //포인터는 내일 다루자. 여기서 하고자 하는 것은 2차원 배열을 입력받는 것이다.
		}
		printf("\n");
	}
}