#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

#define SMAX 10

typedef struct { //하나의 코돈을 하나의 구조체로 저장(코돈은 염기서열 3개)로 구성되어 있음
	int c1;
	int c2;
	int c3;
} Code;

Code C[SMAX] = { 0, };

void randomCode(Code* C) {   //랜덤 염기서열 생성 함수

	for (int i = 0; i < SMAX; i++) {
		int x = rand() % 4;
		int y = rand() * rand() % 4;
		int z = rand() * rand() * rand() % 4;

		if (x == 0)
			C[i].c1 = 'A';
		else if (x == 1)
			C[i].c1 = 'U';
		else if (x == 2)
			C[i].c1 = 'G';
		else
			C[i].c1 = 'C';

		if (y == 0)
			C[i].c2 = 'A';
		else if (y == 1)
			C[i].c2 = 'U';
		else if (y == 2)
			C[i].c2 = 'G';
		else
			C[i].c2 = 'C';

		if (z == 0)
			C[i].c3 = 'A';
		else if (z == 1)
			C[i].c3 = 'U';
		else if (z == 2)
			C[i].c3 = 'G';
		else
			C[i].c3 = 'C';

	}
	for (int i = 0; i < SMAX; i++) {
		printf("%c%c%c/", C[i].c1, C[i].c2, C[i].c3);
	}
}

void randomSequence(Code* C) { //구조체에 저장된 서열을 인식하여 해당 아미노산을 출력하는 함수
	printf("폴리펩타이드 서열: ");

	for (int i = 0; i < SMAX; i++) { //64가지의 각각의 코돈을 조건문으로 분류
		if (C[i].c1 == 'U') {
			if (C[i].c2 == 'U') {
				if (C[i].c3 == 'U' || C[i].c3 == 'C')
					printf("Phe-");
				else if (C[i].c3 == 'A' || C[i].c3 == 'G')
					printf("Leu-");
			}
			else if (C[i].c2 == 'C')
				printf("Ser-");
			else if (C[i].c2 == 'A') {
				if (C[i].c3 == 'U' || C[i].c3 == 'C')
					printf("Tyr-");
				else if (C[i].c3 == 'A' || C[i].c3 == 'G') {
					printf("종료");
					break;
				}
			}
			else if (C[i].c2 == 'G') {
				if (C[i].c3 == 'U' || C[i].c3 == 'C')
					printf("Cys-");
				else if (C[i].c3 == 'A') {
					printf("종료");
					break;
				}
				else if (C[i].c3 == 'G') {
					printf("Trp-");
				}
			}
		}
		else if (C[i].c1 == 'C') {
			if (C[i].c2 == 'U')
				printf("Leu-");
			else if (C[i].c2 == 'C')
				printf("Pro-");
			else if (C[i].c2 == 'A') {
				if (C[i].c3 == 'U' || C[i].c3 == 'C')
					printf("His-");
				else if (C[i].c3 == 'A' || C[i].c3 == 'G')
					printf("Gin-");
			}
			else if (C[i].c2 == 'G')
				printf("Arg-");
		}
		else if (C[i].c1 == 'A') {
			if (C[i].c2 == 'U') {
				if (C[i].c3 == 'U' || C[i].c3 == 'C' || C[i].c3 == 'A')
					printf("lle-");
				else if (C[i].c3 == 'G')
					printf("Met(시작)-");
			}
			else if (C[i].c2 == 'C')
				printf("Thr-");
			else if (C[i].c2 == 'A') {
				if (C[i].c3 == 'U' || C[i].c3 == 'C')
					printf("Asn-");
				else if (C[i].c3 == 'A' || C[i].c3 == 'G')
					printf("Lys-");
			}
			else if (C[i].c2 == 'G') {
				if (C[i].c3 == 'U' || C[i].c3 == 'C')
					printf("Ser-");
				else if (C[i].c3 == 'A' || C[i].c3 == 'G') {
					printf("Arg-");
				}
			}
		}
		else if (C[i].c1 == 'G') {
			if (C[i].c2 == 'U')
				printf("Val-");
			else if (C[i].c2 == 'C')
				printf("Ala-");
			else if (C[i].c2 == 'A') {
				if (C[i].c3 == 'U' || C[i].c3 == 'C')
					printf("Asp-");
				else if (C[i].c3 == 'A' || C[i].c3 == 'G')
					printf("Glu-");
			}
			else if (C[i].c2 == 'G')
				printf("Gly-");
		}
	}
	return 0;
}


int main()
{
	srand(time(NULL));
	int n, i;
	char ans;

	printf("서열 입력 방법을 선택하시오.\n1. 랜덤 생성\n2. 직접 입력\n3. 외부 파일 입력\n");
	scanf("%d", &n);
	if (n == 1) {                        //서열 랜덤 생성
		printf("\n입력된 서열: \n");
		randomCode(&C);
	}
	else if (n == 2) {                   //직접 입력하기
		for (i = 0; i < SMAX; i++) {
			scanf("%c%c%c", &C[i].c1, &C[i].c2, &C[i].c3);
		}
		printf("\n입력된 서열: \n");
		for (i = 0; i < SMAX; i++) {
			printf("%c%c%c/", C[i].c1, C[i].c2, C[i].c3);
		}
		Sleep(10000);
	}
	else if (n == 3) {                   //외부 파일 입력받기
		printf("파일 이름이 text인가요?(y/n)\n");
		rewind(stdin);
		scanf("%c", &ans);
		if (ans == 'Y' || ans == 'y') {
			FILE* f;
			f = fopen("text.txt", "r");
			printf("\n입력된 서열: \n");
			for (i = 0; i < SMAX; i++) {
				fscanf(f, "%c%c%c", &C[i].c1, &C[i].c2, &C[i].c3);
				printf("%c%c%c\n", C[i].c1, C[i].c2, C[i].c3);
			}
			fclose(f);
		}
		else if (ans == 'N' || ans == 'n') {
			printf("파일 입력을 다시 설정하세요.");
		}
	}
	printf("\n\n");
	randomSequence(&C);
	printf("\n\n프로그램 종료\n");
}
