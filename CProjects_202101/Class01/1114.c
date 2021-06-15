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
	printf("이 프로그램은 여러분의 계산실력을 향상시키기 위한 프로그램입니다.\n");
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
	printf("시간제한이 있으니 참고하시고, 준비가 되셨으면 ""4"" 를 눌러주세요 :)\n");
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
	printf("Chapter1, 덧셈\n");
	Sleep(2000);
	system("cls");
	//Level 1
	printf("Level 1 : 한자릿수의 계산\n");
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
		printf("정답입니다!\n%.3f초 걸리셨습니다\n현재 스코어는 %d 점 입니다.", (double)(end - start) / 1000, score);
	}
	else
	{
		printf("오답입니다;; 정답은 %d 입니다.\n%.3f초 걸리셨습니다\n현재 스코어는 %d 점 입니다.\n", a + b + c + d, (double)(end - start) / 1000, score);
		Sleep(3000);
		system("cls");
		printf("Level 1_재시도\n");
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
			printf("정답입니다!\n%.3f초 걸리셨습니다\n현재 스코어는 %d 점 입니다.", (double)(end - start) / 1000, score);
		}
		else
			printf("오답입니다;; 정답은 %d 입니다.\n%.3f초 걸리셨습니다\n현재 스코어는 %d 점 입니다.\n", a + b + c + d, (double)(end - start) / 1000, score);
	}
	Sleep(3000);
	system("cls");
	//Level 2
	printf("Level 2 : 두자릿수의 계산");
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
		printf("정답입니다!\n%.3f초 걸리셨습니다\n현재 스코어는 %d 점 입니다.", (double)(end - start) / 1000, score);
	}
	else
	{
		printf("오답입니다;; 정답은 %d 입니다.\n%.3f초 걸리셨습니다\n현재 스코어는 %d 점 입니다.\n", a + b + c + d, (double)(end - start) / 1000, score);
		Sleep(3000);
		system("cls");
		printf("Level 2_재시도\n");
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
			printf("정답입니다!\n%.3f초 걸리셨습니다\n현재 스코어는 %d 점 입니다.", (double)(end - start) / 1000, score);
		}
		else
			printf("오답입니다;; 정답은 %d 입니다.\n%.3f초 걸리셨습니다\n현재 스코어는 %d 점 입니다.\n", a + b + c + d, (double)(end - start) / 1000, score);
	}
	Sleep(3000);
	system("cls");
	//Level 3
	printf("Level 3 : 세자릿수의 계산");
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
		printf("정답입니다!\n%.3f초 걸리셨습니다\n현재 스코어는 %d 점 입니다.", (double)(end - start) / 1000, score);
	}
	else
	{
		printf("오답입니다;; 정답은 %d 입니다.\n%.3f초 걸리셨습니다\n현재 스코어는 %d 점 입니다.\n", a + b + c + d, (double)(end - start) / 1000, score);
		Sleep(3000);
		system("cls");
		printf("Level 3_재시도");
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
			printf("정답입니다!\n%.3f초 걸리셨습니다\n현재 스코어는 %d 점 입니다.", (double)(end - start) / 1000, score);
		}
		else
			printf("오답입니다;; 정답은 %d 입니다.\n%.3f초 걸리셨습니다\n현재 스코어는 %d 점 입니다.\n", a + b + c + d, (double)(end - start) / 1000, score);
	}
	Sleep(1000);
	system("cls");
	return 0;
}
int minus()
{
	srand(time(NULL));
	int a, b, c, d, answer;
	printf("Chapter2, 뺄셈\n");
	Sleep(2000);
	system("cls");
	//Level 1
	printf("Level 1 : 한자릿수의 계산\n");
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
		printf("정답입니다!\n%.3f초 걸리셨습니다\n현재 스코어는 %d 점 입니다.", (double)(end - start) / 1000, score);
	}
	else
	{
		printf("오답입니다;; 정답은 %d 입니다.\n%.3f초 걸리셨습니다\n현재 스코어는 %d 점 입니다.\n", a - b - c - d, (double)(end - start) / 1000, score);
		Sleep(3000);
		system("cls");
		printf("Level 1_재시도");
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
			printf("정답입니다!\n%.3f초 걸리셨습니다\n현재 스코어는 %d 점 입니다.", (double)(end - start) / 1000, score);
		}
		else
			printf("오답입니다;; 정답은 %d 입니다.\n%.3f초 걸리셨습니다\n현재 스코어는 %d 점 입니다.\n", a - b - c - d, (double)(end - start) / 1000, score);
	}
	Sleep(3000);
	system("cls");
	//Level 2
	printf("Level 2 : 두자릿수의 계산\n");
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
		printf("정답입니다!\n%.3f초 걸리셨습니다\n현재 스코어는 %d 점 입니다.", (double)(end - start) / 1000, score);
	}
	else
	{
		printf("오답입니다;; 정답은 %d 입니다.\n%.3f초 걸리셨습니다\n현재 스코어는 %d 점 입니다.\n", a - b - c - d, (double)(end - start) / 1000, score);
		Sleep(3000);
		system("cls");
		printf("Level 2_재시도");
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
			printf("정답입니다!\n%.3f초 걸리셨습니다\n현재 스코어는 %d 점 입니다.", (double)(end - start) / 1000, score);
		}
		else
			printf("오답입니다;; 정답은 %d 입니다.\n%.3f초 걸리셨습니다\n현재 스코어는 %d 점 입니다.\n", a + b + c + d, (double)(end - start) / 1000, score);
	}
	Sleep(3000);
	system("cls");
	//Level 3
	printf("Level 3 : 세자릿수의 계산\n");
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
		printf("정답입니다!\n%.3f초 걸리셨습니다\n현재 스코어는 %d 점 입니다.", (double)(end - start) / 1000, score);
	}
	else
	{
		printf("오답입니다;; 정답은 %d 입니다.\n%.3f초 걸리셨습니다\n현재 스코어는 %d 점 입니다.\n", a - b - c - d, (double)(end - start) / 1000, score);
		Sleep(3000);
		system("cls");
		printf("Level 3_재시도");
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
			printf("정답입니다!\n%.3f초 걸리셨습니다\n현재 스코어는 %d 점 입니다.", (double)(end - start) / 1000, score);
		}
		else
			printf("오답입니다;; 정답은 %d 입니다.\n%.3f초 걸리셨습니다\n현재 스코어는 %d 점 입니다.\n", a + b + c + d, (double)(end - start) / 1000, score);
	}
	Sleep(3000);
	system("cls");
	return 0;
}
int mult()
{
	srand(time(NULL));
	int a, b, c, d, answer;
	printf("Chapter3, 대망의 곱셈\n");
	Sleep(2000);
	system("cls");
	//Level 1
	printf("Level 1 : 한자릿수의 계산\n");
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
		printf("정답입니다!\n%.3f초 걸리셨습니다\n현재 스코어는 %d 점 입니다.", (double)(end - start) / 1000, score);
	}
	else
	{
		printf("오답입니다;; 정답은 %d 입니다.\n%.3f초 걸리셨습니다\n현재 스코어는 %d 점 입니다.\n", a * b * c * d, (double)(end - start) / 1000, score);
		Sleep(3000);
		system("cls");
		printf("Level 1_재시도");
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
			printf("정답입니다!\n%.3f초 걸리셨습니다\n현재 스코어는 %d 점 입니다.", (double)(end - start) / 1000, score);
		}
		else
			printf("오답입니다;; 정답은 %d 입니다.\n%.3f초 걸리셨습니다\n현재 스코어는 %d 점 입니다.\n", a * b * c * d, (double)(end - start) / 1000, score);
	}
	Sleep(3000);
	system("cls");
	//Level 2
	printf("Level 2 : 두자릿수의 계산\n");
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
		printf("정답입니다!\n%.3f초 걸리셨습니다\n현재 스코어는 %d 점 입니다.", (double)(end - start) / 1000, score);
	}
	else
	{
		printf("오답입니다;; 정답은 %d 입니다.\n%.3f초 걸리셨습니다\n현재 스코어는 %d 점 입니다.\n", a * b * c * d, (double)(end - start) / 1000, score);
		Sleep(3000);
		system("cls");
		printf("Level 2_재시도");
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
			printf("정답입니다!\n%.3f초 걸리셨습니다\n현재 스코어는 %d 점 입니다.", (double)(end - start) / 1000, score);
		}
		else
			printf("오답입니다;; 정답은 %d 입니다.\n%.3f초 걸리셨습니다\n", a * b * c * d, (double)(end - start) / 1000);
	}
	Sleep(1000);
	system("cls");
	return 0;
}
void print()
{
	if (score == 340)
		printf("천재신가요? 당신의 총 점수는 %d 점 입니다.\n", score);
	else if (score >= 180)
		printf("잘하셨습니다. 고수시네요. 당신의 총 점수는 %d 점 입니다.\n", score);
	else if (score >= 100)
		printf("조금 더 연습하셔야겠네요. 당신의 총 점수는 %d 점 입니다.\n", score);
	else
		printf("당장 문제풀러 가셔야할거같아요. 당신의 총 점수는 %d 점 입니다.\n", score);
}