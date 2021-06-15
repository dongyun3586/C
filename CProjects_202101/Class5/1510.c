#include <stdio.h>
#include <string.h>

void printBody(int mistakes, char body[], char error[]);	//��� �ϱ�

int main(void)
{
	char body[7] = { 0 };
	char error[7] = { 0 };
	int end = 0;
	int sum = 0;
	int before = 0;		//���� ��
	int mistake = 0;	//�Ǽ� Ƚ��
	char chance;	//�õ��� ���ĺ�
	char under_bar[101];
	memset(under_bar, '_', 101);	//ó������ 101��° �迭���� ��� _(�����)�� �ʱ�ȭ���ִ� �Լ�
	char word[101] = { 0 };		//������ �ܾ�
	printf("���� �ܾ��� ���ĺ� ������ �Է��Ͽ� �ּ���.\n");
	int cnt;
	scanf("%d", &cnt);
	printf("���� �ܾ �Է����ּ���.\n");
	int i;
	scanf("%s", word);
	for (i = 0; i < 200; i++)
	{
		printf("\n");
	}
	printf("**** Hangman Game ***\n");
	printf("\n\n\n");
	printf("���߾����\n");
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
		printf("����� �й��Ͽ����ϴ�.\n");
		printf("�ܾ��");
		printf("%s", word);
		printf("�����ϴ�.");
	}
	else if (end == 1)
	{
		printf("����� �¸��Ͽ����ϴ�.");
	}
}

void printBody(int mistakes, char body[], char error[])	//�� �����
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
		printf("\t___________%c\n"//_10��
			"\t|          %c\n"
			"\t|          %c%c%c\n"
			"\t|          %c\n"
			"\t|          %c%c%c\n", body[1], body[2], body[3], body[2], body[4], body[2], body[5], body[2], body[6]);
	}
	else if (body[3] != 0 && body[5] == 0)
	{
		printf("\t___________%c\n"//_10��
			"\t|          %c\n"
			"\t|         %c%c%c\n"
			"\t|          %c\n"
			"\t|          %c%c%c\n", body[1], body[2], body[3], body[2], body[4], body[2], body[5], body[2], body[6]);
	}
	else if (body[5] != 0)
	{
		printf("\t___________%c\n"//_10��
			"\t|          %c\n"
			"\t|         %c%c%c\n"
			"\t|          %c\n"
			"\t|         %c%c%c\n", body[1], body[2], body[3], body[2], body[4], body[2], body[5], body[2], body[6]);
	}
	printf("error word: %s\n", error);
}