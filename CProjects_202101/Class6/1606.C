#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include <windows.h>
void rock(); //그림입니다
void scissors();
void paper();
int main() {
	int com; // 컴퓨터가낸값을저장합니다. 
	int user; // 사용자가낸값을저장합니다. 
	int win = 0, tie = 0, lose = 0; // 게임의결과를저장합니다.
	// result 배열의모든요소를0으로초기화합니다. 
	int cnt = 0; // 게임의횟수를저장합니다. 0으로초기화합니다. 
	srand(time(NULL)); // rand 함수의결과가매번다르도록시드값을지정합니다. 
	while (1) // 사용자가종료할때까지반복합니다. 
	{
		com = rand() % 3 + 1; // 1~3 값중하나를저장합니다. 
		printf("**************** 가위바위보게임****************\n");
		printf("(1. 가위_ 2. 바위_ 3. 보_ 0. 종료)\n\n");
		printf("입력해주세요: ");
		scanf_s("%d", &user);
		if (user > 0 && user < 4) // 사용자가1~3 값을입력했을경우입니다.
		{
			cnt++; // 정상적인입력의경우게임횟수를증가시킵니다. 

			// 컴퓨터, 사용자가낸값에따라가위, 바위, 보중출력할값을선택합니다. 
			printf("\n컴퓨터: %s\n", (com == 1 ? "가위" : com == 2 ? "바위" : "보"));
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
			if (com == 1) {
				scissors();
			}
			if (com == 2) {
				rock();
			}
			if (com == 3) {
				paper();
			}
			printf("사용자: %s\n\n", (user == 1 ? "가위" : user == 2 ? "바위" : "보"));
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
			if (user == 1) {
				scissors();
			}
			if (user == 2) {
				rock();
			}
			if (user == 3) {
				paper();
			}
			if (com == user) // 컴퓨터의값과사용자의값이같으면비기는경우입니다. 
			{
				printf("오랜만에좋은상대를만났군. \n\n");
				tie++; // 무승부횟수를증가시킵니다. 
			}// 지는경우의수입니다. 
			else if (((com == 1) && (user == 3)) ||
				((com == 2) && (user == 1)) ||
				((com == 3) && (user == 2)))
			{
				printf("나약한녀석\n\n");
				lose++; // 패배횟수를증가시킵니다. 
			}
			else // 나머지는이긴경우입니다. 
			{
				printf("운이좋았네\n\n");
				win++; // 승리횟수를증가시킵니다. 
			}
			printf("%d전%d승%d무%d패\n\n", cnt, win, tie, lose);
		}
		else // 사용자가입력한값이1, 2, 3이아닌경우
		{
			if (user == 0) // 사용자가입력한값이0이면종료합니다. 
			{
				printf("게임을종료합니다.\n");
				break
			}
			printf("숫자를제대로입력해주세요\n\n");// 그외에는예외처리메세지출력
		}
		system("pause"); // 일시정지아무키나누르면진행됩니다. 
		system("cls"); // 화면내용을모두지웁니다. 
	}
	return 0;
}

void scissors() {
	printf("\n");
	printf("   $$$$$    $$$$$ \n");
	printf("   $$$$$    $$$$$ \n");
	printf("   $$$$$    $$$S$ \n");
	printf("   $$$$$    $$$$$ \n");
	printf("   $$$$$    $$$$$\n");
	printf("  $$$S$$$$$$$$$$$ \n");
	printf("  $$$$$$$$$$$$$$$ \n");
	printf("  $$$$$$$$$$$$$$$ \n");
	printf("  $$$$$$$$$$$$$$$ \n");
	printf("  $$$$$$$$$$$$$$$ \n");
	printf("%c[0m\n", 27); //원래색으로되돌림
}

void rock() {
	printf("   \n");
	printf("   \n");
	printf("   \n");
	printf("      $$$$$$$$$$  \n");
	printf("   $$$$$$$$$$$$$$ \n");
	printf("  $$$S$$$$$$$$$$$$\n");
	printf("  $$$$$$$$$$$$$$$$\n");
	printf("  $$$$$$$$$$$$$$$ \n");
	printf("  $$$$$$$$$$$$$$$ \n");
	printf("  \n");
	printf("%c[0m\n", 27); //원래색으로되돌림

}


void paper() {
	printf("\n");
	printf("  $$  $$  $$  $$  \n");
	printf("  $$  $$  $$  $$  \n");
	printf("  $$  $$  $$  $S  \n");
	printf("  $$  $$  $$  $$$ \n");
	printf("  $$$$$$$$$$$$$$$$\n");
	printf("  $$$S$$$$$$$$$$$$  $$\n");
	printf("  $$$$$$$$$$$$$$$$$$$\n");
	printf("  $$$$$$$$$$$$$$$$$ \n");
	printf("  $$$$$$$$$$$$$$$ \n");
	printf("    $$$$$$$$$$$$$ \n");
	printf("%c[0m\n", 27); //원래색으로되돌림
}