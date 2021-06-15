#include <stdio.h>
#include <string.h>

void printBody(int mistakes, char body[], char error[]);	//행맨 하기

int main(void)
{
	char body[7] = { 0 };
	char error[7] = { 0 };
	int end = 0;
	int sum = 0;
	int before = 0;		//전과 비교
	int mistake = 0;	//실수 횟수
	char chance;	//시도한 알파벳
	char under_bar[101];
	memset(under_bar, '_', 101);	//처음부터 101번째 배열까지 모두 _(언더바)로 초기화해주는 함수
	char word[101] = { 0 };		//정답인 단어
	printf("맞출 단어의 알파벳 개수를 입력하여 주세요.\n");
	int cnt;
	scanf("%d", &cnt);
	printf("맞출 단어를 입력해주세요.\n");
	int i;
	scanf("%s", word);
	for (i = 0; i < 200; i++)
	{
		printf("\n");
	}
	printf("**** Hangman Game ***\n");
	printf("\n\n\n");
	printf("맞추어보세요\n");
	printBody(mistake, body, error);
	printf("\n");
	for (i = 0; i <= cnt - 1; i++)
	{
		printf("%c", under_bar[i]);
	}
	while (end == 0)
	{
		for (i = 0; i <= cnt; i++)
		{
			if (under_bar[i] == '_')
			{
				before++;
			}
		}
		scanf("\n%c", &chance);
		for (i = 0; i < cnt; i++)
		{
			if (word[i] == chance)
			{
				under_bar[i] = chance;
			}
		}
		for (i = 0; i <= cnt; i++)
		{
			if (under_bar[i] == '_')
			{
				sum++;
			}
		}
		if (mistake < 6 && sum == 1)
		{
			end = 1;
		}
		else if (mistake == 6)
		{
			end = -1;
		}
		if (sum == before)
		{
			error[mistake] = chance;
			++mistake;
		}
		printBody(mistake, body, error);
		printf("\n");
		for (i = 0; i <= cnt - 1; i++)
		{
			printf("%c", under_bar[i]);
		}
		printf("\n");
		sum = 0;
		before = 0;
		if (mistake == 6)
		{
			end = -1;
			break;
		}
	}
	if (end == -1)
	{
		printf("당신은 패배하였습니다.\n");
		printf("단어는");
		printf("%s", word);
		printf("였습니다.");
	}
	else if (end == 1)
	{
		printf("당신은 승리하였습니다.");
	}
}

void printBody(int mistakes, char body[], char error[])	//몸 만들기
{
	printf("\tMistakes :%d\n", mistakes);
	switch (mistakes) {

	case 1: body[1] = 'O';
		break;
	case 2:body[2] = '|';
		break;
	case 3:body[3] = '/';
		break;
	case 4:body[4] = '\\';
		break;
	case 5: body[5] = '/';
		break;
	case 6:body[6] = '\\';
		break;
	default: break;

	}
	if (body[3] == 0)
	{
		printf("\t___________%c\n"//_10개
			"\t|          %c\n"
			"\t|          %c%c%c\n"
			"\t|          %c\n"
			"\t|          %c%c%c\n", body[1], body[2], body[3], body[2], body[4], body[2], body[5], body[2], body[6]);
	}
	else if (body[3] != 0 && body[5] == 0)
	{
		printf("\t___________%c\n"//_10개
			"\t|          %c\n"
			"\t|         %c%c%c\n"
			"\t|          %c\n"
			"\t|          %c%c%c\n", body[1], body[2], body[3], body[2], body[4], body[2], body[5], body[2], body[6]);
	}
	else if (body[5] != 0)
	{
		printf("\t___________%c\n"//_10개
			"\t|          %c\n"
			"\t|         %c%c%c\n"
			"\t|          %c\n"
			"\t|         %c%c%c\n", body[1], body[2], body[3], body[2], body[4], body[2], body[5], body[2], body[6]);
	}
	printf("error word: %s\n", error);
}