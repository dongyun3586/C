#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
int start_1();
int plus();
int minus();
int mult();
void print();
clock_t start, end;
int score = 0;
int main()
{
	printf("�� ���α׷��� �������� ���Ƿ��� ����Ű�� ���� ���α׷��Դϴ�.\n");
	Sleep(2000);
	system("cls");
	start_1();
	plus();
	minus();
	mult();
	print();
	return 0;
}
int start_1()
{
	int ready;
	printf("�ð������� ������ �����Ͻð�, �غ� �Ǽ����� ""4"" �� �����ּ��� :)\n");
	scanf("%d", &ready);
	if (ready == 4)
	{
		Sleep(1000);
		system("cls");
		return 0;
	}
	else
		start_1();
}
int plus()
{
	srand(time(NULL));
	int a, b, c, d, answer;
	printf("Chapter1, ����\n");
	Sleep(2000);
	system("cls");
	//Level 1
	printf("Level 1 : ���ڸ����� ���\n");
	Sleep(1000);
	system("cls");
	a = rand() % 19 - 9;
	b = rand() % 10 - 9;
	c = rand() % 10 - 9;
	d = rand() % 10 - 9;
	printf("%d + %d + %d + %d = ", a, b, c, d);
	start = clock();
	scanf("%d", &answer);
	end = clock();
	system("cls");
	if (answer == a + b + c + d)
	{
		score += 10;
		printf("�����Դϴ�!\n%.3f�� �ɸ��̽��ϴ�\n���� ���ھ�� %d �� �Դϴ�.", (double)(end - start) / 1000, score);
	}
	else
	{
		printf("�����Դϴ�;; ������ %d �Դϴ�.\n%.3f�� �ɸ��̽��ϴ�\n���� ���ھ�� %d �� �Դϴ�.\n", a + b + c + d, (double)(end - start) / 1000, score);
		Sleep(3000);
		system("cls");
		printf("Level 1_��õ�\n");
		Sleep(1000);
		system("cls");
		a = rand() % 19 - 9;
		b = rand() % 10 - 9;
		c = rand() % 10 - 9;
		d = rand() % 10 - 9;
		printf("%d + %d + %d + %d = ", a, b, c, d);
		start = clock();
		scanf("%d", &answer);
		end = clock();
		system("cls");
		if (answer == a + b + c + d)
		{
			score += 5;
			printf("�����Դϴ�!\n%.3f�� �ɸ��̽��ϴ�\n���� ���ھ�� %d �� �Դϴ�.", (double)(end - start) / 1000, score);
		}
		else
			printf("�����Դϴ�;; ������ %d �Դϴ�.\n%.3f�� �ɸ��̽��ϴ�\n���� ���ھ�� %d �� �Դϴ�.\n", a + b + c + d, (double)(end - start) / 1000, score);
	}
	Sleep(3000);
	system("cls");
	//Level 2
	printf("Level 2 : ���ڸ����� ���");
	Sleep(1000);
	system("cls");
	a = rand() % 199 - 99;
	b = rand() % 199 - 99;
	c = rand() % 199 - 99;
	d = rand() % 199 - 99;
	printf("%d + %d + %d + %d = ", a, b, c, d);
	start = clock();
	scanf("%d", &answer);
	end = clock();
	system("cls");
	if (answer == a + b + c + d)
	{
		score += 20;
		printf("�����Դϴ�!\n%.3f�� �ɸ��̽��ϴ�\n���� ���ھ�� %d �� �Դϴ�.", (double)(end - start) / 1000, score);
	}
	else
	{
		printf("�����Դϴ�;; ������ %d �Դϴ�.\n%.3f�� �ɸ��̽��ϴ�\n���� ���ھ�� %d �� �Դϴ�.\n", a + b + c + d, (double)(end - start) / 1000, score);
		Sleep(3000);
		system("cls");
		printf("Level 2_��õ�\n");
		Sleep(1000);
		system("cls");
		a = rand() % 199 - 99;
		b = rand() % 199 - 99;
		c = rand() % 199 - 99;
		d = rand() % 199 - 99;
		printf("%d + %d + %d + %d = ", a, b, c, d);
		start = clock();
		scanf("%d", &answer);
		end = clock();
		system("cls");
		if (answer == a + b + c + d)
		{
			score += 10;
			printf("�����Դϴ�!\n%.3f�� �ɸ��̽��ϴ�\n���� ���ھ�� %d �� �Դϴ�.", (double)(end - start) / 1000, score);
		}
		else
			printf("�����Դϴ�;; ������ %d �Դϴ�.\n%.3f�� �ɸ��̽��ϴ�\n���� ���ھ�� %d �� �Դϴ�.\n", a + b + c + d, (double)(end - start) / 1000, score);
	}
	Sleep(3000);
	system("cls");
	//Level 3
	printf("Level 3 : ���ڸ����� ���");
	Sleep(1000);
	system("cls");
	a = rand() % 1999 - 999;
	b = rand() % 1999 - 999;
	c = rand() % 1999 - 999;
	d = rand() % 1999 - 999;
	printf("%d + %d + %d + %d = ", a, b, c, d);
	start = clock();
	scanf("%d", &answer);
	end = clock();
	system("cls");
	if (answer == a + b + c + d)
	{
		score += 40;
		printf("�����Դϴ�!\n%.3f�� �ɸ��̽��ϴ�\n���� ���ھ�� %d �� �Դϴ�.", (double)(end - start) / 1000, score);
	}
	else
	{
		printf("�����Դϴ�;; ������ %d �Դϴ�.\n%.3f�� �ɸ��̽��ϴ�\n���� ���ھ�� %d �� �Դϴ�.\n", a + b + c + d, (double)(end - start) / 1000, score);
		Sleep(3000);
		system("cls");
		printf("Level 3_��õ�");
		Sleep(1000);
		system("cls");
		a = rand() % 1999 - 999;
		b = rand() % 1999 - 999;
		c = rand() % 1999 - 999;
		d = rand() % 1999 - 999;
		printf("%d + %d + %d + %d = ", a, b, c, d);
		start = clock();
		scanf("%d", &answer);
		end = clock();
		system("cls");
		if (answer == a + b + c + d)
		{
			score += 20;
			printf("�����Դϴ�!\n%.3f�� �ɸ��̽��ϴ�\n���� ���ھ�� %d �� �Դϴ�.", (double)(end - start) / 1000, score);
		}
		else
			printf("�����Դϴ�;; ������ %d �Դϴ�.\n%.3f�� �ɸ��̽��ϴ�\n���� ���ھ�� %d �� �Դϴ�.\n", a + b + c + d, (double)(end - start) / 1000, score);
	}
	Sleep(1000);
	system("cls");
	return 0;
}
int minus()
{
	srand(time(NULL));
	int a, b, c, d, answer;
	printf("Chapter2, ����\n");
	Sleep(2000);
	system("cls");
	//Level 1
	printf("Level 1 : ���ڸ����� ���\n");
	Sleep(1000);
	system("cls");
	a = rand() % 19 - 9;
	b = rand() % 10 - 9;
	c = rand() % 10 - 9;
	d = rand() % 10 - 9;
	printf("%d - %d - %d - %d = ", a, b, c, d);
	start = clock();
	scanf("%d", &answer);
	end = clock();
	system("cls");
	if (answer == a - b - c - d)
	{
		score += 10;
		printf("�����Դϴ�!\n%.3f�� �ɸ��̽��ϴ�\n���� ���ھ�� %d �� �Դϴ�.", (double)(end - start) / 1000, score);
	}
	else
	{
		printf("�����Դϴ�;; ������ %d �Դϴ�.\n%.3f�� �ɸ��̽��ϴ�\n���� ���ھ�� %d �� �Դϴ�.\n", a - b - c - d, (double)(end - start) / 1000, score);
		Sleep(3000);
		system("cls");
		printf("Level 1_��õ�");
		Sleep(1000);
		system("cls");
		a = rand() % 19 - 9;
		b = rand() % 10 - 9;
		c = rand() % 10 - 9;
		d = rand() % 10 - 9;
		printf("%d + %d + %d + %d = ", a, b, c, d);
		start = clock();
		scanf("%d", &answer);
		end = clock();
		system("cls");
		if (answer == a - b - c - d)
		{
			score += 5;
			printf("�����Դϴ�!\n%.3f�� �ɸ��̽��ϴ�\n���� ���ھ�� %d �� �Դϴ�.", (double)(end - start) / 1000, score);
		}
		else
			printf("�����Դϴ�;; ������ %d �Դϴ�.\n%.3f�� �ɸ��̽��ϴ�\n���� ���ھ�� %d �� �Դϴ�.\n", a - b - c - d, (double)(end - start) / 1000, score);
	}
	Sleep(3000);
	system("cls");
	//Level 2
	printf("Level 2 : ���ڸ����� ���\n");
	Sleep(1000);
	system("cls");
	a = rand() % 199 - 99;
	b = rand() % 199 - 99;
	c = rand() % 199 - 99;
	d = rand() % 199 - 99;
	printf("%d + %d + %d + %d = ", a, b, c, d);
	start = clock();
	scanf("%d", &answer);
	end = clock();
	system("cls");
	if (answer == a - b - c - d)
	{
		score += 20;
		printf("�����Դϴ�!\n%.3f�� �ɸ��̽��ϴ�\n���� ���ھ�� %d �� �Դϴ�.", (double)(end - start) / 1000, score);
	}
	else
	{
		printf("�����Դϴ�;; ������ %d �Դϴ�.\n%.3f�� �ɸ��̽��ϴ�\n���� ���ھ�� %d �� �Դϴ�.\n", a - b - c - d, (double)(end - start) / 1000, score);
		Sleep(3000);
		system("cls");
		printf("Level 2_��õ�");
		Sleep(1000);
		system("cls");
		a = rand() % 199 - 99;
		b = rand() % 199 - 99;
		c = rand() % 199 - 99;
		d = rand() % 199 - 99;
		printf("%d + %d + %d + %d = ", a, b, c, d);
		start = clock();
		scanf("%d", &answer);
		end = clock();
		system("cls");
		if (answer == a - b - c - d)
		{
			score += 10;
			printf("�����Դϴ�!\n%.3f�� �ɸ��̽��ϴ�\n���� ���ھ�� %d �� �Դϴ�.", (double)(end - start) / 1000, score);
		}
		else
			printf("�����Դϴ�;; ������ %d �Դϴ�.\n%.3f�� �ɸ��̽��ϴ�\n���� ���ھ�� %d �� �Դϴ�.\n", a + b + c + d, (double)(end - start) / 1000, score);
	}
	Sleep(3000);
	system("cls");
	//Level 3
	printf("Level 3 : ���ڸ����� ���\n");
	Sleep(1000);
	system("cls");
	a = rand() % 1999 - 999;
	b = rand() % 1999 - 999;
	c = rand() % 1999 - 999;
	d = rand() % 1999 - 999;
	printf("%d - %d - %d - %d = ", a, b, c, d);
	start = clock();
	scanf("%d", &answer);
	end = clock();
	system("cls");
	if (answer == a - b - c - d)
	{
		score += 40;
		printf("�����Դϴ�!\n%.3f�� �ɸ��̽��ϴ�\n���� ���ھ�� %d �� �Դϴ�.", (double)(end - start) / 1000, score);
	}
	else
	{
		printf("�����Դϴ�;; ������ %d �Դϴ�.\n%.3f�� �ɸ��̽��ϴ�\n���� ���ھ�� %d �� �Դϴ�.\n", a - b - c - d, (double)(end - start) / 1000, score);
		Sleep(3000);
		system("cls");
		printf("Level 3_��õ�");
		Sleep(1000);
		system("cls");
		a = rand() % 1999 - 999;
		b = rand() % 1999 - 999;
		c = rand() % 1999 - 999;
		d = rand() % 1999 - 999;
		printf("%d - %d - %d - %d = ", a, b, c, d);
		start = clock();
		scanf("%d", &answer);
		end = clock();
		system("cls");
		if (answer == a - b - c - d)
		{
			score += 20;
			printf("�����Դϴ�!\n%.3f�� �ɸ��̽��ϴ�\n���� ���ھ�� %d �� �Դϴ�.", (double)(end - start) / 1000, score);
		}
		else
			printf("�����Դϴ�;; ������ %d �Դϴ�.\n%.3f�� �ɸ��̽��ϴ�\n���� ���ھ�� %d �� �Դϴ�.\n", a + b + c + d, (double)(end - start) / 1000, score);
	}
	Sleep(3000);
	system("cls");
	return 0;
}
int mult()
{
	srand(time(NULL));
	int a, b, c, d, answer;
	printf("Chapter3, ����� ����\n");
	Sleep(2000);
	system("cls");
	//Level 1
	printf("Level 1 : ���ڸ����� ���\n");
	Sleep(1000);
	system("cls");
	a = rand() % 19 - 9;
	b = rand() % 10 - 9;
	c = rand() % 10 - 9;
	d = rand() % 10 - 9;
	printf("%d * %d * %d * %d = ", a, b, c, d);
	start = clock();
	scanf("%d", &answer);
	end = clock();
	system("cls");
	if (answer == a * b * c * d)
	{
		score += 40;
		printf("�����Դϴ�!\n%.3f�� �ɸ��̽��ϴ�\n���� ���ھ�� %d �� �Դϴ�.", (double)(end - start) / 1000, score);
	}
	else
	{
		printf("�����Դϴ�;; ������ %d �Դϴ�.\n%.3f�� �ɸ��̽��ϴ�\n���� ���ھ�� %d �� �Դϴ�.\n", a * b * c * d, (double)(end - start) / 1000, score);
		Sleep(3000);
		system("cls");
		printf("Level 1_��õ�");
		Sleep(1000);
		system("cls");
		a = rand() % 19 - 9;
		b = rand() % 10 - 9;
		c = rand() % 10 - 9;
		d = rand() % 10 - 9;
		printf("%d * %d * %d * %d = ", a, b, c, d);
		start = clock();
		scanf("%d", &answer);
		end = clock();
		system("cls");
		if (answer == a * b * c * d)
		{
			score += 20;
			printf("�����Դϴ�!\n%.3f�� �ɸ��̽��ϴ�\n���� ���ھ�� %d �� �Դϴ�.", (double)(end - start) / 1000, score);
		}
		else
			printf("�����Դϴ�;; ������ %d �Դϴ�.\n%.3f�� �ɸ��̽��ϴ�\n���� ���ھ�� %d �� �Դϴ�.\n", a * b * c * d, (double)(end - start) / 1000, score);
	}
	Sleep(3000);
	system("cls");
	//Level 2
	printf("Level 2 : ���ڸ����� ���\n");
	Sleep(1000);
	system("cls");
	a = rand() % 199 - 99;
	b = rand() % 199 - 99;
	c = rand() % 199 - 99;
	d = rand() % 199 - 99;
	printf("%d * %d * %d * %d = ", a, b, c, d);
	start = clock();
	scanf("%d", &answer);
	end = clock();
	system("cls");
	if (answer == a * b * c * d)
	{
		score += 160;
		printf("�����Դϴ�!\n%.3f�� �ɸ��̽��ϴ�\n���� ���ھ�� %d �� �Դϴ�.", (double)(end - start) / 1000, score);
	}
	else
	{
		printf("�����Դϴ�;; ������ %d �Դϴ�.\n%.3f�� �ɸ��̽��ϴ�\n���� ���ھ�� %d �� �Դϴ�.\n", a * b * c * d, (double)(end - start) / 1000, score);
		Sleep(3000);
		system("cls");
		printf("Level 2_��õ�");
		Sleep(1000);
		system("cls");
		a = rand() % 199 - 99;
		b = rand() % 199 - 99;
		c = rand() % 199 - 99;
		d = rand() % 199 - 99;
		printf("%d * %d * %d * %d = ", a, b, c, d);
		start = clock();
		scanf("%d", &answer);
		end = clock();
		system("cls");
		if (answer == a * b * c * d)
		{
			score += 80;
			printf("�����Դϴ�!\n%.3f�� �ɸ��̽��ϴ�\n���� ���ھ�� %d �� �Դϴ�.", (double)(end - start) / 1000, score);
		}
		else
			printf("�����Դϴ�;; ������ %d �Դϴ�.\n%.3f�� �ɸ��̽��ϴ�\n", a * b * c * d, (double)(end - start) / 1000);
	}
	Sleep(1000);
	system("cls");
	return 0;
}
void print()
{
	if (score == 340)
		printf("õ��Ű���? ����� �� ������ %d �� �Դϴ�.\n", score);
	else if (score >= 180)
		printf("���ϼ̽��ϴ�. ����ó׿�. ����� �� ������ %d �� �Դϴ�.\n", score);
	else if (score >= 100)
		printf("���� �� �����ϼž߰ڳ׿�. ����� �� ������ %d �� �Դϴ�.\n", score);
	else
		printf("���� ����Ǯ�� ���ž��ҰŰ��ƿ�. ����� �� ������ %d �� �Դϴ�.\n", score);
}