#include<stdio.h>

int Calculate1(int num1, int num2);
int Calculate2(int num);

int main() {
	int kind, num1, num2, i, num;

	printf("****** ���������� ���� ******\n");
	printf("1.����\n2.���캴\n3.����/���Ӹ�\n4.�и�/�����Ӻ�\n5.������ ����\n6.V����/������ �Ӹ���\n7.�ֲ�Ǯ ����\n8.������ ����\n9.��Ӹ� ����\n10.�ֱٱ� ����");
	printf("\n���� ������ �������հ� ���������� Ȯ���� �����ϰ� ����Ͽ����ϴ�.");
	printf("\n���Ǵ� Ȯ���� ù��° �������Դϴ�.");
	printf("\n*****************************");

	printf("\nȮ���ϰ��� �ϴ� ������ ������ �Է��ϼ���: ");
	scanf("%d", &kind);
	switch (kind) {
	case 1:
		printf("\n\n�θ���� �������� �Է����ּ���.\n 1.����O    2.����X");
		printf("\n�ƹ���: ");
		scanf("%d", &num1);
		printf("��Ӵ�: ");
		scanf("%d", &num2);

		Calculate1(num1, num2);

		return 0;
		break;

	case 2:
		printf("\n\n�θ���� �������� �Է����ּ���.\n 1.���캴O    2.���캴X");
		printf("\n�ƹ���: ");
		scanf("%d", &num1);
		printf("��Ӵ�: ");
		scanf("%d", &num2);

		Calculate1(num1, num2);

		return 0;
		break;

	case 3:
		printf("\n\n�θ���� �������� �Է����ּ���.\n 1.�����Ӹ�   2.���Ӹ�");
		printf("\n�ƹ���: ");
		scanf("%d", &num1);
		printf("��Ӵ�: ");
		scanf("%d", &num2);
		num = num1 + num2;

		Calculate2(num);

		return 0;
		break;

	case 4:
		printf("\n\n�θ���� �������� �Է����ּ���.\n 1.�и��Ӻ�   2.�����Ӻ�");
		printf("\n�ƹ���: ");
		scanf("%d", &num1);
		printf("��Ӵ�: ");
		scanf("%d", &num2);
		num = num1 + num2;

		Calculate2(num);

		return 0;
		break;

	case 5:
		printf("\n\n�θ���� �������� �Է����ּ���.\n 1.������ ����   2.������ �Ұ���");
		printf("\n�ƹ���: ");
		scanf("%d", &num1);
		printf("��Ӵ�: ");
		scanf("%d", &num2);
		num = num1 + num2;

		Calculate2(num);

		return 0;
		break;

	case 6:
		printf("\n\n�θ���� �������� �Է����ּ���.\n 1.V���� �Ӹ���   2.������ �Ӹ���");
		printf("\n�ƹ���: ");
		scanf("%d", &num1);
		printf("��Ӵ�: ");
		scanf("%d", &num2);
		num = num1 + num2;

		Calculate2(num);

		return 0;
		break;

	case 7:
		printf("\n\n�θ���� �������� �Է����ּ���.\n 1.�ֲ�Ǯ ����   2.�ֲ�Ǯ ����");
		printf("\n�ƹ���: ");
		scanf("%d", &num1);
		printf("��Ӵ�: ");
		scanf("%d", &num2);
		num = num1 + num2;

		Calculate2(num);

		return 0;
		break;

	case 8:
		printf("\n\n�θ���� �������� �Է����ּ���.\n 1.������ ����   2.������ ����");
		printf("\n�ƹ���: ");
		scanf("%d", &num1);
		printf("��Ӵ�: ");
		scanf("%d", &num2);
		num = num1 + num2;

		Calculate2(num);

		return 0;
		break;

	case 9:
		printf("\n\n�θ���� �������� �Է����ּ���.\n 1.��Ӹ�   2.��Ӹ� �ƴ�");
		printf("\n�ƹ���: ");
		scanf("%d", &num1);
		printf("��Ӵ�: ");
		scanf("%d", &num2);
		num = num1 + num2;

		Calculate2(num);

		return 0;
		break;

	case 10:
		printf("\n\n�θ���� �������� �Է����ּ���.\n 1.�ֱٱ� ����   2.�ֱٱ� ����");
		printf("\n�ƹ���: ");
		scanf("%d", &num1);
		printf("��Ӵ�: ");
		scanf("%d", &num2);
		num = num1 + num2;

		Calculate2(num);

		return 0;
		break;

	}
	return 0;
}

int Calculate1(int num1, int num2) {
	int a, b, c;
	if (num1 == 1) {
		if (num2 == 1) {
			printf("[����Ȯ��] ����: 100%%    ����: 100%%");
		}
		else
			printf("[����Ȯ��] ����: 25%%   ����: 25%% (�������� Ȯ��: 75%%)");
	}
	else {
		if (num2 == 1) {
			printf("[����Ȯ��] ����: 50%%   ����: 0%% (�������� Ȯ��: 100%%)");
		}
		else
			printf("[����Ȯ��] ����: 25%%   ����: 0%% (�������� Ȯ��: 25%%)");
	}
	return num1, num2;
}

int Calculate2(int num) {
	if (num == 2)
		printf("[����Ȯ��] 0%%");
	if (num == 3)
		printf("[����Ȯ��] 75%%");
	if (num == 4)
		printf("[����Ȯ��] 91.7%%");
	return num;
}