#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <math.h>

#define MAX_WORD 12
#define WORD_COUNT 24
#define SENTENCE_MAX 100
#define SENTENCE_COUNT 10 
#define long_TEXT 15

void seatpractice(char* str);
void wordpractice(char str[][MAX_WORD]);
void sentencepractice(char str[][SENTENCE_MAX]);
void gotoxy(int x, int y);
void game(char tubeword[][10], char scroreword[][10]);
void character(int n);
void down(int floor, int level, int score, int t, int s, char tube[][10], char Score[][10]);
void up(int floor, int level, int score, int t, int s, char tube[][10], char Score[][10]);

int main()
{
	system("color 70");
	system("mode con: cols=42 lines=15"); //콘솔 창 크기 조절
	printf("\n #######\n");
	printf("    #     #   #  #####  #  #    #   ####\n");
	printf("    #      # #   #    # #  ##   #  #    #\n");
	printf("    #       #    #    # #  # #  #  #\n");
	printf("    #       #    #####  #  #  # #  #  ###\n");
	printf("    #       #    #      #  #   ##  #    #\n");
	printf("    #       #    #      #  #    #   ####\n\n");// 게임 메인화면 출력


	printf("1 : 자리 연습\n2 : 낱말 연습\n3 : 문장 연습\n4 : 게임\n\n모드 선택 : ");
	int mode = 0;
	scanf("%d", &mode); // 모드 입력 받기

	//자리연습 알파벳 저장
	char seat[52];
	for (int i = 0; i < 26; i++)
		seat[i] = (char)(i + 65);
	for (int i = 26; i < 52; i++)
		seat[i] = (char)(i + 71);

	//낱말연습 단어 저장
	char word[WORD_COUNT][MAX_WORD] = { "Hello", "nice", "happy", "Rain",
		"Cloud", "Sun", "moon", "Earth", "Mars", "plus", "Minus", "gravity",
		"Venus", "language", "unite", "Korea", "kingdom", "grandparent",
		"python", "java", "visual", "Basic", "fundamental", "English" };

	//문장 연습 글 저장
	char sentence[SENTENCE_COUNT][SENTENCE_MAX] = { "Miracles happen to only those who believe in them.",
		"Think like a man of action and act like man of thought.",
		"By doubting we come at the truth.",
		"Error is the discipline through which we advance.",
		"Forgiveness is better than revenge.",
		"Who begins too much accomplishes little.",
		"To doubt is safer than to be secure.",
		"A full belly is the mother of all evil.",
		"To be trusted is a greater compliment than to be loved.",
		"Appearances are deceptive." };

	//게임에서 튜브 개수 늘리는 단어 저장
	char game_tube[20][10] = { "above", "accident", "build", "business", "cabinet",
		"camera", "champion", "confirm", "daughter", "describe", "disaster", "discuss",
		"ecology", "nice", "energy", "like", "health", "holiday", "hospital",
		"idea"
	};

	//게임에서 점수 올리는 단어 저장
	char game_score[20][10] = { "intense", "island", "justice", "language", "lead",
		"letter", "Hello", "local", "majority", "material", "measure", "medicine",
		"grape", "mistake", "music", "need", "neutral", "nominate", "nuclear",
		"ocean"
	};

	switch (mode)//모드에 따라 실행
	{
	case 1:
		seatpractice(seat);
		break;
	case 2:
		wordpractice(word);
		break;
	case 3:
		sentencepractice(sentence);
		break;
	case 4:
		game(game_tube, game_score);
	}

	return 0;
}

//자리 연습
void seatpractice(char* str)
{
	rewind(stdin);
	system("mode con: cols=14 lines=2");
	char temp; //사용자 입력
	while (1)
	{
		srand(time(NULL)); //랜덤으로 알파벳 출력을 위해서
		int i;
		i = rand() % 52;
		putchar(str[i]);
		printf("\n");
		temp = getchar(); //알파벳 입력 받기
		if (temp == str[i])
		{
			system("color 10"); // 같으면 파란색으로 콘솔색 바꾸기
			Sleep(100);
			system("color 70");
			rewind(stdin);
		}

		else
		{
			system("color 40"); // 다르면 붉은색으로 콘솔색 바꾸기
			Sleep(100);
			system("color 70");
			rewind(stdin);
		}
	}
}

//낱말 연습
void wordpractice(char str[][MAX_WORD])
{
	rewind(stdin);
	system("mode con: cols=14 lines=2"); //콘솔 화면 크기 조정 
	char temp[MAX_WORD];
	while (1)
	{
		srand(time(NULL));
		int i; // 단어를 담는 변수
		i = rand() % WORD_COUNT;
		puts(str[i]);
		gets(temp);
		if (strcmp(temp, str[i]) == 0)
		{
			system("color 10");
			Sleep(100);
			system("color 70"); // 마찬가지로 맞으면 콘솔 색을 파란색으로 변경
		}

		else
		{
			system("color 40");
			Sleep(100);
			system("color 70"); // 틀리면 콘솔색을 붉은색으로 변경
		}
	}
}

//문장 연습
void sentencepractice(char str[][SENTENCE_MAX])
{
	float start, end; // 문장을 치기 시작하는 시점과 다 친 시각을 저장하는 변수
	float time_taken; // 걸린 시간을 저장하는 변수
	rewind(stdin);
	system("mode con: cols=100 lines=5"); // 콘솔 크기 조정
	char temp[SENTENCE_MAX - 1]; // 사용자 입력을 받을 변수 선언 (첫 단어는 따로 받아야해서 크기가 -1 되었다)
	char Temp[SENTENCE_MAX]; // 사용자 입력을 받은 문자열과 따로 입력받은 첫 글자를 합친 문자열을 저장하기 위한 변수
	int i = 0; //문장의 순서를 담는 변수
	while (i < SENTENCE_COUNT) // 모든 문장을 다 돌 때 까지 반복
	{
		for (int j = 0; j < 100; j++)
			printf("="); // 형식 제공
		printf("\n");
		printf("| 문장 : %s", str[i]); //문장 출력
		for (int j = 0; j < 75 - strlen(str[i]); j++)
			printf(" ");
		printf("|"); // 형식 제공
		for (int j = 0; j < 14; j++)
			printf(" ");
		printf("|\n");
		printf("|-----------------------------------------------------------------------------------|"); //형식 제공
		if (i != 0)
			printf("  %.2f글자/s  |\n|", strlen(str[i - 1]) / time_taken); //그 전에 친 문장의 타수를 보여줌
		else
			printf("              |\n|"); //그 전에 친 문장의 타수를 보여주므로 첫번째 문장을 칠 때는 보여줄 타수가 없다. -> 조건문으로 따로 처리
		printf(" 입력 : ");
		for (int j = 0; j < 75; j++)
			printf(" ");
		printf("|");
		for (int j = 0; j < 14; j++)
			printf(" ");
		printf("|\n");
		for (int j = 0; j < 100; j++)
			printf("="); //형식 제공
		gotoxy(9, 3); // 형식을 다 만들고, 사용자가 입력하는 곳으로 커서 이동
		char c = getche(); // Enter나 공백 없이 문자가 입력되면 바로 변수에 저장되는 getche를 이용하여 사용자가 입력을 시작하자마자 
		start = (float)clock() / CLOCKS_PER_SEC; // time_taken이 측정되기 시작하도록 함
		gets(temp); // 사용자 입력을 받음
		for (int j = 1; j < SENTENCE_MAX; j++)
			Temp[j] = temp[j - 1];
		Temp[0] = c; // Temp에 temp와 첫글자 c를 저장
		if (strcmp(Temp, str[i]) == 0)
		{
			end = (float)clock() / CLOCKS_PER_SEC;
			time_taken = end - start;
			system("color 10");
			Sleep(100);
			system("color 70"); // 같으면 콘솔색을 파란색으로 바꾸는 조건문
		}

		else
		{
			end = (float)clock() / CLOCKS_PER_SEC;
			time_taken = end - start;
			system("color 40");
			Sleep(100);
			system("color 70"); //다르면 콘솔색을 붉은색으로 바꾸는 조건문
		}
		i++; // 다음 문장으로 넘어감
	}
}

void character(int n)
{
	gotoxy(0, n - 1); // 캐릭터를 출력할 층으로 커서 이동
	for (int i = 0; i < 21; i++)
		printf(" ");
	printf("A____A\n");
	for (int i = 0; i < 21; i++)
		printf(" ");
	printf("|^ㅅ^ |\n");
	for (int i = 0; i < 21; i++)
		printf(" ");
	printf("|っ ｃ|\n");
	for (int i = 0; i < 21; i++)
		printf(" ");
	printf("|     |\n");
	for (int i = 0; i < 21; i++)
		printf(" ");
	printf("|     |\n");
	for (int i = 0; i < 21; i++)
		printf(" ");
	printf("U￣￣U\n"); // 고양이 출력 ㅎㅎ
}

void game(char tubeword[][10], char scoreword[][10])
{
	rewind(stdin);
	void(*fp[2])(int, int, int, int, int, char**, char**) = { down, up }; // 캐릭터를 위아래로 움직일 함수포인터 배열 선언
	system("mode con: cols=50 lines=20"); // 콘솔 크기 선언
	int floor = 9; // 캐릭터가 있는 층(콘솔에서의 높이)를 담는 변수 선언
	int score = 0; // 점수를 담는 변수
	int level = 1; // 레벨을 담는 변수
	char temp[10]; // 사용자 입력을 받을 변수 선언
	float start, end; // 단어를 치는데 걸리는 시간을 저장하기 위한 변수 2개
	float time_taken; // 걸린 시간을 저장하는 변수
	int t = 0, s = 0; // 튜브를 얻기위한 단어와 점수를 얻기위한 단어의 순서를 저장하는 변수
	fp[0](floor - 1, level, score, t, s, tubeword, scoreword);
	while (floor < 12) //남는 튜브가 없으면 게임 종료
	{
		gotoxy(11 + strlen(tubeword[t]), 18); // 사용자 입력을 받는 곳으로 커서 이동
		start = (float)clock() / CLOCKS_PER_SEC;
		gets(temp);
		if (strcmp(temp, tubeword[t]) == 0)
			fp[1](floor--, level, score, ++t, s, tubeword, scoreword); // 위에서 서술
		if (strcmp(temp, scoreword[s]) == 0)
			fp[0](floor - 1, level, ++score, t, ++s, tubeword, scoreword);
		end = (float)clock() / CLOCKS_PER_SEC;
		time_taken = end - start;
		if (s + t > 3 * level)
			level++; // 3개의 단어를 맞출 때마다 레벨 상승
		if ((int)((time_taken)*level / 6) > 1) // 레벨이 올라갈 때마다 올라가기 어렵게 하기 위해서
			fp[0](floor++, level, score, t, s, tubeword, scoreword);
	}
	printf("\n\nlevel : %d, score : %d", level, score);
}

void down(int floor, int level, int score, int t, int s, char tube[][10], char Score[][10])
{
	system("cls"); // 콘솔 초기화
	printf("              level : %d   score : %d", level, score);
	character(floor + 1); // 원래 층에서 한칸 내려서 캐릭터 출력
	gotoxy(0, floor + 6);
	for (int i = 0; i < 11 - floor; i++)
	{
		for (int j = 0; j < 15; j++)
			printf(" ");
		printf("[[[[[[ 튜브 ]]]]]]\n");
	}
	for (int i = 0; i < 50; i++)
		printf("=");
	printf("\nTube : %s ||", tube[t]);
	for (int i = 0; i < 20 - strlen(Score[s]); i++)
		printf(" ");
	printf("|| Score : %s\n", Score[s]); //형식 제공
	for (int i = 0; i < 50; i++)
		printf("=");
}

void up(int floor, int level, int score, int t, int s, char tube[][10], char Score[][10])
{
	system("cls"); // 콘솔 초기화
	printf("              level : %d   score : %d", level, score);
	character(floor - 1); // 원래 층에서 한 칸 내려서 캐릭터 출력
	gotoxy(0, floor + 4);
	for (int i = 0; i < 13 - floor; i++)
	{
		for (int j = 0; j < 15; j++)
			printf(" ");
		printf("[[[[[[ 튜브 ]]]]]]\n");
	}
	for (int i = 0; i < 50; i++)
		printf("=");
	printf("\nTube : %s ||", tube[t]);
	for (int i = 0; i < 20 - strlen(Score[s]); i++)
		printf(" ");
	printf("|| Score : %s\n", Score[s]); //형식 제공
	for (int i = 0; i < 50; i++)
		printf("=");
}

void gotoxy(int x, int y)
{
	//x, y 좌표 설정
	COORD pos = { x,y };
	//커서 이동
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}