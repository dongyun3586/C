#include<stdio.h>

int main() {
	// 1��: �հ� ���հ� ����
	int score;
	printf("������ �Է��Ͻÿ�: ");
	scanf("%d", &score);

	if (score >= 60)
		printf("�հ��Դϴ�.\n");
	else
		printf("���հ��Դϴ�.\n");

	//// ���� ������
	// (score>=60)?printf("�հ��Դϴ�.\n"): printf("���հ��Դϴ�.\n");
	// printf("�հ� ����: %d\n", (score >= 60) ? 1 : 0);

	// 2��: ���� �Ǵ� ���α׷�
	int year;

	printf("������ �Է��Ͻÿ�: ");
	scanf("%d", &year);

	// ���� �Ǵ� => ��� ���
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		printf("%d���� �����Դϴ�.\n", year);
	else
		printf("%d���� ����Դϴ�.\n", year);

	return 0;
}