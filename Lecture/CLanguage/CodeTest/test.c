#include<stdio.h>

int main() {
	int score;
	printf("������ �Է��Ͻÿ�: ");
	scanf("%d", &score);

	if (score >= 60)
		printf("�հ��Դϴ�.\n");
	else
		printf("���հ��Դϴ�.\n");

	//// ���� ������
	// (score>=60)?printf("�հ��Դϴ�.\n"): printf("���հ��Դϴ�.\n");

	//// ���� �Ǵ� ���α׷�
	//int year;

	//printf("������ �Է��Ͻÿ�: ");
	//scanf("%d", &year);

	//// ���� �Ǵ� => ��� ���

	return 0;
}