#include <stdio.h>
#include <string.h>

void jumsuCalculator(float jumsu, float* sum);
void hakjumCalculator(char hakjum[], float* sum, int b);
int isuhakjumSum(int b, int* isusum);

int main() {
	printf("�� ���α׷��� �����б� ���л����� ���� ���۵Ǿ����ϴ�.\n\n");

	printf("������ �� ���̳���?\n");
	int ans;
	printf("1 : ��\n2 : ����\n");
	scanf("%d", &ans);

	if (ans == 1) {
		printf("��� �������� ������ �Է��Ͻ� �� �ְھ��.\n\n");
	}
	else if (ans == 2) {
		printf("��ö�� �ڱ� �Ǵ��� ���� ���� ������ ���͵帮�ڽ��ϴ�.\n\n");
	}
	else {
		printf("\n");
	}

	int re = 1;

	while (re == 1) {
		printf("-----------------------------------------------------\n\n");
		printf("� ������ Ȯ���ϰ� �����Ű���?\n");
		int choice;
		printf("1 : ���\n2: �������\n");
		scanf("%d", &choice);

		if (choice == 1 || choice == 2) {
			printf("\n***�� ������ �Է��� ������ enterŰ�� ��������***\n\n");

			if (choice == 1) {
				printf("������ ��� �Է��� �ּ���\n");
				printf("(��� �Է��� ������ '999'�� �Է��� �ֽñ� �ٶ��ϴ�)\n");
				float jumsu = 0;
				float sumj = 0;
				int a = 0;
				float mean;

				while (jumsu != 999) {
					scanf("%f", &jumsu);
					jumsuCalculator(jumsu, &sumj);
					a++;
				}
				sumj -= 999;
				mean = sumj / (a - 1);
				printf("����� %f�� �Դϴ�.\n", mean);
			}

			else if (choice == 2) {
				printf("�� ������ ��ް� �̼� ������ �Է��� �ּ���(��� �Է� �Ŀ��� enter�Է�)\n");
				printf("(��� �Է��� ������ 'gg, 0'�� �Է��� �ֽñ� �ٶ��ϴ�)\n");
				char hakjum[3] = { 0 };
				float sumh = 0;
				int b = 0;
				int isusum = 0;
				float grade;

				while (strcmp(hakjum, "gg") != 0) {
					rewind(stdin);
					fgets(hakjum, 3, stdin);
					scanf("%d", &b);
					hakjumCalculator(hakjum, &sumh, b);
					isuhakjumSum(b, &isusum);
				}
				grade = sumh / isusum;
				printf("��������� %f�� �Դϴ�.\n", grade);
			}
		}

		else {
			printf("�ٽ� �Է����ּ���\n\n");
			continue;
		}

		printf("\n������ ������ Ȯ���Ͻ� �ǰ���?\n");
		printf("1 : ��\n2 : ����\n");
		scanf("%d", &re);
		printf("\n");
	}

	printf("*************************\n");
	printf("�̿��� �ּż� �����մϴ�\n\n");
	printf("���� �׻� ��������!!!\n");
	printf("*************************\n");
}

void jumsuCalculator(float jumsu, float* sum) {
	*sum += jumsu;
}

void hakjumCalculator(char hakjum[], float* sum, int b) {
	float k = 0;
	if (strcmp(hakjum, "A+") == 0) {
		k = 4.3;
	}
	else if (strcmp(hakjum, "A0") == 0) {
		k = 4.0;
	}
	else if (strcmp(hakjum, "A-") == 0) {
		k = 3.7;
	}
	else if (strcmp(hakjum, "B+") == 0) {
		k = 3.3;
	}
	else if (strcmp(hakjum, "B0") == 0) {
		k = 3.0;
	}
	else if (strcmp(hakjum, "B-") == 0) {
		k = 2.7;
	}
	else if (strcmp(hakjum, "C+") == 0) {
		k = 2.3;
	}
	*sum += k * b;
}

int isuhakjumSum(int b, int* isusum) {
	*isusum += b;
}