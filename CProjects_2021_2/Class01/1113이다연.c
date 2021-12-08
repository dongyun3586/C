#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

#define SMAX 10

typedef struct { //�ϳ��� �ڵ��� �ϳ��� ����ü�� ����(�ڵ��� ���⼭�� 3��)�� �����Ǿ� ����
	int c1;
	int c2;
	int c3;
} Code;

Code C[SMAX] = { 0, };

void randomCode(Code* C) {   //���� ���⼭�� ���� �Լ�

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

void randomSequence(Code* C) { //����ü�� ����� ������ �ν��Ͽ� �ش� �ƹ̳���� ����ϴ� �Լ�
	printf("������Ÿ�̵� ����: ");

	for (int i = 0; i < SMAX; i++) { //64������ ������ �ڵ��� ���ǹ����� �з�
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
					printf("����");
					break;
				}
			}
			else if (C[i].c2 == 'G') {
				if (C[i].c3 == 'U' || C[i].c3 == 'C')
					printf("Cys-");
				else if (C[i].c3 == 'A') {
					printf("����");
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
					printf("Met(����)-");
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

	printf("���� �Է� ����� �����Ͻÿ�.\n1. ���� ����\n2. ���� �Է�\n3. �ܺ� ���� �Է�\n");
	scanf("%d", &n);
	if (n == 1) {                        //���� ���� ����
		printf("\n�Էµ� ����: \n");
		randomCode(&C);
	}
	else if (n == 2) {                   //���� �Է��ϱ�
		for (i = 0; i < SMAX; i++) {
			scanf("%c%c%c", &C[i].c1, &C[i].c2, &C[i].c3);
		}
		printf("\n�Էµ� ����: \n");
		for (i = 0; i < SMAX; i++) {
			printf("%c%c%c/", C[i].c1, C[i].c2, C[i].c3);
		}
		Sleep(10000);
	}
	else if (n == 3) {                   //�ܺ� ���� �Է¹ޱ�
		printf("���� �̸��� text�ΰ���?(y/n)\n");
		rewind(stdin);
		scanf("%c", &ans);
		if (ans == 'Y' || ans == 'y') {
			FILE* f;
			f = fopen("text.txt", "r");
			printf("\n�Էµ� ����: \n");
			for (i = 0; i < SMAX; i++) {
				fscanf(f, "%c%c%c", &C[i].c1, &C[i].c2, &C[i].c3);
				printf("%c%c%c\n", C[i].c1, C[i].c2, C[i].c3);
			}
			fclose(f);
		}
		else if (ans == 'N' || ans == 'n') {
			printf("���� �Է��� �ٽ� �����ϼ���.");
		}
	}
	printf("\n\n");
	randomSequence(&C);
	printf("\n\n���α׷� ����\n");
}
