#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int random(int n);						//�߰��ܰ迡�� �������� ��ȣ ����ֱ�
void finalrandom(int num);				//�����ܰ迡�� �������� �޴� �������ֱ�
//int error(int x, int i, int f);		//�־��� ��ȣ�� �ƴ� ��ȣ�� ������� �ٽ� ����� �ϱ�

int main() {
	int a, b;
	printf("�޴� ����? ���� �����ְھ�.\n\n");
	//CHECK:
	printf("1. �ѽ�  2. �Ͻ�  3. �߽�  4. ���  5. �н�/�߽�  6. ���  7. ��Ÿ  8. ����Ʈ  9. �ƹ��ų�!\n���� �Է�: ");
	scanf("%d", &a);
	/*if (1 > a || a > 9)
	{
		printf("error\n");
		goto CHECK;
	}
	//error(a, 1, 9);
	*/

	while (a == 9) {
		printf("%d�� ���þ�!", random(8));
		a = random(8);
	}

	switch (a) {
	case 1:
		printf("\n\n�ѽ�!\n1. ���� O, �ſ�    2. ���� O, �ȸſ�    3. ���� X, �ſ�    4. ���� X, �ȸſ�\n���� �Է�: ");
		scanf("%d", &b);

		//error(b, 1, 4);

		switch (b) {
		case 1:
			printf("\n\n1 ��ġ�   2 ������   3 �ſ���   4 �δ��   5 ������\n");
			break;
		case 2:
			printf("\n\n1 �ߺ�����   2 ������   3 ��ġ������   4 ��â����   5 ��������\n");
			break;
		case 3:
			printf("\n\n1 ������   2 �̿���   3 �����   4 �ø�   5 ����\n");
			break;
		case 4:
			printf("\n\n1 ������   2 �������   3 �Ұ�� ���   4 �����   5 ������\n");
			break;
		}

		finalrandom(5);
		break;
	case 2:
		printf("\n\n�Ͻ�!\n1. ���� O    2. ���� X\n���� �Է�: ");
		scanf("%d", &b);

		if (b == 1) printf("1 �쵿   2 ���   3 ���λ���   4 ��Ű��Ű");
		else printf("1 �ʹ�   2 ����   3 ���ڳ�̾�Ű   4 ��ī��");

		finalrandom(4);
		break;

	case 3:
		printf("\n\n�߽�!\n1. �ſ�  2. �ȸſ�\n���� �Է�: ");
		scanf("%d", &b);

		switch (b) {
		case 1:
			printf("\n\n1 ��ġ�   2 ������   3 �ſ���   4 �δ��\n");
			break;

		case 2:
			printf("\n\n1 �ߺ�����   2 ������   3 ��ġ������   4 ��â����\n");
			break;
		}

		finalrandom(4);
		break;

	case 4:
		printf("\n\n���!\n\n");
		printf("1 ����   2 �Ľ�Ÿ   3 ������ũ   4 �ܹ���");

		finalrandom(4);
		break;

	case 5:
		printf("\n\n�н� / �߽�!\n\n");
		printf("1 ������   2 ���   3 �߹�   4 �Ķ��̵� ġŲ   5 ���ġŲ   6 ����Ƣ��   7 ���");
		finalrandom(7);
		break;

	case 6:
		printf("\n\n���!\n1. �������   2. �Ұ��   3. �� & �������\n���� �Է�: ");
		scanf("%d", &b);

		switch (b) {
		case 1:
			printf("\n\n1 ����   2 ���   3 ����, ����   4 ��������\n");
			finalrandom(4);
			break;

		case 2:
			printf("\n\n1 ���   2 �ҺҰ��   3 �����\n");
			finalrandom(3);
			break;

		case 3:
			printf("\n\n1 ��������   2 �������   3 �߹��   4 �߰���\n");
			finalrandom(4);
			break;
		}

		break;

	case 7:
		printf("\n\n��Ÿ!\n\n");
		printf("1 �ұ���   2 ���   3 �߹�   4 �Ķ��̵� ġŲ   5 ���ġŲ   6 ����Ƣ��   7 ���");
		finalrandom(7);
		break;

	case 8:
		printf("\n\n����Ʈ!\n1 ����   2 ����ũ   3 ũ����   4 ��   5 ��ī��   6 ���̽�ũ��\n���� �Է�: ");
		finalrandom(6);

		break;
	}
}

void finalrandom(int num) {
	srand(time(NULL));
	int t, r = rand() % num + 1;
	printf("\n\n���⼭�� ���������� ���� �������� ����ٰ�!\n");
	printf("1. �ƴϾ� ������!  2. �����!\n���� �Է�: ");
	scanf("%d", &t);

	if (t == 1) printf("�˾Ҿ�! �� ���ְ� �Ծ�~ :)");
	else printf("\n\n���� ����� ��ȣ�� %d��! �� ���ְ� �Ծ�~ :)", r);
}

int random(int n) {
	srand(time(NULL));
	int r = rand() % n + 1;

	return r;
}
/*
int error(int a, int i, int f) {
	int x = a, y=0;
	while (x<i || x>f) {
		printf("����! %d ~ %d �߿��� �����!\n", i, f);
		printf("���� �Է�: ");
		scanf("%d, &y");
		x = y;
	}
	return a;
}
*/