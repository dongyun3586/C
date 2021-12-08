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
	system("mode con: cols=42 lines=15"); //�ܼ� â ũ�� ����
	printf("\n #######\n");
	printf("    #     #   #  #####  #  #    #   ####\n");
	printf("    #      # #   #    # #  ##   #  #    #\n");
	printf("    #       #    #    # #  # #  #  #\n");
	printf("    #       #    #####  #  #  # #  #  ###\n");
	printf("    #       #    #      #  #   ##  #    #\n");
	printf("    #       #    #      #  #    #   ####\n\n");// ���� ����ȭ�� ���


	printf("1 : �ڸ� ����\n2 : ���� ����\n3 : ���� ����\n4 : ����\n\n��� ���� : ");
	int mode = 0;
	scanf("%d", &mode); // ��� �Է� �ޱ�

	//�ڸ����� ���ĺ� ����
	char seat[52];
	for (int i = 0; i < 26; i++)
		seat[i] = (char)(i + 65);
	for (int i = 26; i < 52; i++)
		seat[i] = (char)(i + 71);

	//�������� �ܾ� ����
	char word[WORD_COUNT][MAX_WORD] = { "Hello", "nice", "happy", "Rain",
		"Cloud", "Sun", "moon", "Earth", "Mars", "plus", "Minus", "gravity",
		"Venus", "language", "unite", "Korea", "kingdom", "grandparent",
		"python", "java", "visual", "Basic", "fundamental", "English" };

	//���� ���� �� ����
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

	//���ӿ��� Ʃ�� ���� �ø��� �ܾ� ����
	char game_tube[20][10] = { "above", "accident", "build", "business", "cabinet",
		"camera", "champion", "confirm", "daughter", "describe", "disaster", "discuss",
		"ecology", "nice", "energy", "like", "health", "holiday", "hospital",
		"idea"
	};

	//���ӿ��� ���� �ø��� �ܾ� ����
	char game_score[20][10] = { "intense", "island", "justice", "language", "lead",
		"letter", "Hello", "local", "majority", "material", "measure", "medicine",
		"grape", "mistake", "music", "need", "neutral", "nominate", "nuclear",
		"ocean"
	};

	switch (mode)//��忡 ���� ����
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

//�ڸ� ����
void seatpractice(char* str)
{
	rewind(stdin);
	system("mode con: cols=14 lines=2");
	char temp; //����� �Է�
	while (1)
	{
		srand(time(NULL)); //�������� ���ĺ� ����� ���ؼ�
		int i;
		i = rand() % 52;
		putchar(str[i]);
		printf("\n");
		temp = getchar(); //���ĺ� �Է� �ޱ�
		if (temp == str[i])
		{
			system("color 10"); // ������ �Ķ������� �ֻܼ� �ٲٱ�
			Sleep(100);
			system("color 70");
			rewind(stdin);
		}

		else
		{
			system("color 40"); // �ٸ��� ���������� �ֻܼ� �ٲٱ�
			Sleep(100);
			system("color 70");
			rewind(stdin);
		}
	}
}

//���� ����
void wordpractice(char str[][MAX_WORD])
{
	rewind(stdin);
	system("mode con: cols=14 lines=2"); //�ܼ� ȭ�� ũ�� ���� 
	char temp[MAX_WORD];
	while (1)
	{
		srand(time(NULL));
		int i; // �ܾ ��� ����
		i = rand() % WORD_COUNT;
		puts(str[i]);
		gets(temp);
		if (strcmp(temp, str[i]) == 0)
		{
			system("color 10");
			Sleep(100);
			system("color 70"); // ���������� ������ �ܼ� ���� �Ķ������� ����
		}

		else
		{
			system("color 40");
			Sleep(100);
			system("color 70"); // Ʋ���� �ֻܼ��� ���������� ����
		}
	}
}

//���� ����
void sentencepractice(char str[][SENTENCE_MAX])
{
	float start, end; // ������ ġ�� �����ϴ� ������ �� ģ �ð��� �����ϴ� ����
	float time_taken; // �ɸ� �ð��� �����ϴ� ����
	rewind(stdin);
	system("mode con: cols=100 lines=5"); // �ܼ� ũ�� ����
	char temp[SENTENCE_MAX - 1]; // ����� �Է��� ���� ���� ���� (ù �ܾ�� ���� �޾ƾ��ؼ� ũ�Ⱑ -1 �Ǿ���)
	char Temp[SENTENCE_MAX]; // ����� �Է��� ���� ���ڿ��� ���� �Է¹��� ù ���ڸ� ��ģ ���ڿ��� �����ϱ� ���� ����
	int i = 0; //������ ������ ��� ����
	while (i < SENTENCE_COUNT) // ��� ������ �� �� �� ���� �ݺ�
	{
		for (int j = 0; j < 100; j++)
			printf("="); // ���� ����
		printf("\n");
		printf("| ���� : %s", str[i]); //���� ���
		for (int j = 0; j < 75 - strlen(str[i]); j++)
			printf(" ");
		printf("|"); // ���� ����
		for (int j = 0; j < 14; j++)
			printf(" ");
		printf("|\n");
		printf("|-----------------------------------------------------------------------------------|"); //���� ����
		if (i != 0)
			printf("  %.2f����/s  |\n|", strlen(str[i - 1]) / time_taken); //�� ���� ģ ������ Ÿ���� ������
		else
			printf("              |\n|"); //�� ���� ģ ������ Ÿ���� �����ֹǷ� ù��° ������ ĥ ���� ������ Ÿ���� ����. -> ���ǹ����� ���� ó��
		printf(" �Է� : ");
		for (int j = 0; j < 75; j++)
			printf(" ");
		printf("|");
		for (int j = 0; j < 14; j++)
			printf(" ");
		printf("|\n");
		for (int j = 0; j < 100; j++)
			printf("="); //���� ����
		gotoxy(9, 3); // ������ �� �����, ����ڰ� �Է��ϴ� ������ Ŀ�� �̵�
		char c = getche(); // Enter�� ���� ���� ���ڰ� �ԷµǸ� �ٷ� ������ ����Ǵ� getche�� �̿��Ͽ� ����ڰ� �Է��� �������ڸ��� 
		start = (float)clock() / CLOCKS_PER_SEC; // time_taken�� �����Ǳ� �����ϵ��� ��
		gets(temp); // ����� �Է��� ����
		for (int j = 1; j < SENTENCE_MAX; j++)
			Temp[j] = temp[j - 1];
		Temp[0] = c; // Temp�� temp�� ù���� c�� ����
		if (strcmp(Temp, str[i]) == 0)
		{
			end = (float)clock() / CLOCKS_PER_SEC;
			time_taken = end - start;
			system("color 10");
			Sleep(100);
			system("color 70"); // ������ �ֻܼ��� �Ķ������� �ٲٴ� ���ǹ�
		}

		else
		{
			end = (float)clock() / CLOCKS_PER_SEC;
			time_taken = end - start;
			system("color 40");
			Sleep(100);
			system("color 70"); //�ٸ��� �ֻܼ��� ���������� �ٲٴ� ���ǹ�
		}
		i++; // ���� �������� �Ѿ
	}
}

void character(int n)
{
	gotoxy(0, n - 1); // ĳ���͸� ����� ������ Ŀ�� �̵�
	for (int i = 0; i < 21; i++)
		printf(" ");
	printf("A____A\n");
	for (int i = 0; i < 21; i++)
		printf(" ");
	printf("|^��^ |\n");
	for (int i = 0; i < 21; i++)
		printf(" ");
	printf("|�� ��|\n");
	for (int i = 0; i < 21; i++)
		printf(" ");
	printf("|     |\n");
	for (int i = 0; i < 21; i++)
		printf(" ");
	printf("|     |\n");
	for (int i = 0; i < 21; i++)
		printf(" ");
	printf("U����U\n"); // ����� ��� ����
}

void game(char tubeword[][10], char scoreword[][10])
{
	rewind(stdin);
	void(*fp[2])(int, int, int, int, int, char**, char**) = { down, up }; // ĳ���͸� ���Ʒ��� ������ �Լ������� �迭 ����
	system("mode con: cols=50 lines=20"); // �ܼ� ũ�� ����
	int floor = 9; // ĳ���Ͱ� �ִ� ��(�ֿܼ����� ����)�� ��� ���� ����
	int score = 0; // ������ ��� ����
	int level = 1; // ������ ��� ����
	char temp[10]; // ����� �Է��� ���� ���� ����
	float start, end; // �ܾ ġ�µ� �ɸ��� �ð��� �����ϱ� ���� ���� 2��
	float time_taken; // �ɸ� �ð��� �����ϴ� ����
	int t = 0, s = 0; // Ʃ�긦 ������� �ܾ�� ������ ������� �ܾ��� ������ �����ϴ� ����
	fp[0](floor - 1, level, score, t, s, tubeword, scoreword);
	while (floor < 12) //���� Ʃ�갡 ������ ���� ����
	{
		gotoxy(11 + strlen(tubeword[t]), 18); // ����� �Է��� �޴� ������ Ŀ�� �̵�
		start = (float)clock() / CLOCKS_PER_SEC;
		gets(temp);
		if (strcmp(temp, tubeword[t]) == 0)
			fp[1](floor--, level, score, ++t, s, tubeword, scoreword); // ������ ����
		if (strcmp(temp, scoreword[s]) == 0)
			fp[0](floor - 1, level, ++score, t, ++s, tubeword, scoreword);
		end = (float)clock() / CLOCKS_PER_SEC;
		time_taken = end - start;
		if (s + t > 3 * level)
			level++; // 3���� �ܾ ���� ������ ���� ���
		if ((int)((time_taken)*level / 6) > 1) // ������ �ö� ������ �ö󰡱� ��ư� �ϱ� ���ؼ�
			fp[0](floor++, level, score, t, s, tubeword, scoreword);
	}
	printf("\n\nlevel : %d, score : %d", level, score);
}

void down(int floor, int level, int score, int t, int s, char tube[][10], char Score[][10])
{
	system("cls"); // �ܼ� �ʱ�ȭ
	printf("              level : %d   score : %d", level, score);
	character(floor + 1); // ���� ������ ��ĭ ������ ĳ���� ���
	gotoxy(0, floor + 6);
	for (int i = 0; i < 11 - floor; i++)
	{
		for (int j = 0; j < 15; j++)
			printf(" ");
		printf("[[[[[[ Ʃ�� ]]]]]]\n");
	}
	for (int i = 0; i < 50; i++)
		printf("=");
	printf("\nTube : %s ||", tube[t]);
	for (int i = 0; i < 20 - strlen(Score[s]); i++)
		printf(" ");
	printf("|| Score : %s\n", Score[s]); //���� ����
	for (int i = 0; i < 50; i++)
		printf("=");
}

void up(int floor, int level, int score, int t, int s, char tube[][10], char Score[][10])
{
	system("cls"); // �ܼ� �ʱ�ȭ
	printf("              level : %d   score : %d", level, score);
	character(floor - 1); // ���� ������ �� ĭ ������ ĳ���� ���
	gotoxy(0, floor + 4);
	for (int i = 0; i < 13 - floor; i++)
	{
		for (int j = 0; j < 15; j++)
			printf(" ");
		printf("[[[[[[ Ʃ�� ]]]]]]\n");
	}
	for (int i = 0; i < 50; i++)
		printf("=");
	printf("\nTube : %s ||", tube[t]);
	for (int i = 0; i < 20 - strlen(Score[s]); i++)
		printf(" ");
	printf("|| Score : %s\n", Score[s]); //���� ����
	for (int i = 0; i < 50; i++)
		printf("=");
}

void gotoxy(int x, int y)
{
	//x, y ��ǥ ����
	COORD pos = { x,y };
	//Ŀ�� �̵�
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}