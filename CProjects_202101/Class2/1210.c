#include <stdio.h>
#include <time.h>
#include <Windows.h>
//gotoxy 함수를 사용하기 위해 검색을 통해 찾은 헤더파일

void gotoxy(int x, int y);
//자리표를 출력할 때 번호와 글자가 출력될 위치를 지정하는 함수

void printSeat(int row, int column);
//행과 열, 학생 수를 입력받아 이차원 배열에 학생들의 번호를 각각 저장하고 그 번호를 섞어 출력하는 함수

int main(void) {
	srand(time(NULL)); //학생들의 자리를 섞을 때 난수를 사용
	int row, column, student;
	// 행, 열, 학생수를 각각 나타내는 변수

	printf("*** 1210 이유겸 정보프로젝트 수행평가***\n\n\n");
	printf("자리배치 프로그램\n\n");

	printf("행의 수를 입력하세요 : ");
	scanf("%d", &row);//행 입력

	printf("열의 수를 입력하세요 : ");
	scanf("%d", &column);//열 입력

	printf("학생 수를 입력하세요 : ");
	scanf("%d", &student);//학생수 입력


	printSeat(row, column, student);  // 입력받은 값을 통해 자리를 배치하고 자리표를 출력


	return 0;  //main함수 종료
}

void gotoxy(int x, int y)  // 배열을 출력하는 방법을 검색하다 찾은 함수입니다.

{

	COORD pos = { x,y };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

}

void printSeat(int row, int column, int student)
{

	// 이차원 배열 선언과 초기화
	int sit[20][20] = { 0 };

	// 배열에 순서대로 학생들의 번호를 채우기(학생수보다 자리수가 많으면 0이 채워진다)

	for (int i = 0; i < column; i++) //한 행에 모두 번호가 채워지면 다음 열로 넘어간다
	{

		for (int j = 0; j < row; j++) //한 행에 대해서 행의 길이만큼 반복 
		{

			while (j + row * i < student) //자리에 순서대로 학생들의 번호를 채우기
			{
				sit[j][i] = j + row * i + 1;
				break;
			}

		}

	}
	int a, b, temp = 0; // 행과 열의 변수 a, b와 두 위치의 배열에 저장된 값을 바꿀 때 사용하는 변수 temp

	for (int i = 0; i < column; i++) //행에 대해 반복이 끝나면 열이 넘어간다.
	{
		for (int j = 0; j < row; j++) //한 행에 대해서 행의 길이만큼
		{
			a = rand() % row;
			b = rand() % column;  //임의의 행과 열을 잡는다

			temp = sit[j][i];  //sit[i][j]의 값을 temp에 저장

			sit[j][i] = sit[a][b];
			sit[a][b] = temp;  //sit[i][j]와 sit[a][b]의 값을 바꾼다
		}
	}



	gotoxy(2 * column + 7, 8);//자리표를 출력할 위치를 가운데로 설정하고 출력
	printf("<자리표>");


	for (int i = 1; i <= column; i++) //행에 대한 for문이 끝나면 다음 열로 넘어감
	{
		for (int j = 1; j <= row; j++) // 행의 길이만큼 반복
		{
			gotoxy(j * 4 + 6, i * 2 + 8);
			printf("%3d", sit[j - 1][i - 1]);  //각 행과 열에 대해 위치를 설정하고 출력
		}
	}


}