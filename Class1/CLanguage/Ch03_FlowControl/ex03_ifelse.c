#include<stdio.h>

int main_ex03_ifelse() {
	int score;
	printf("������ �Է��Ͻÿ�: ");
	scanf("%d", &score);

	if (score >= 60)
		printf("�հ��Դϴ�.\n");
	else
		printf("���հ��Դϴ�.\n");

	//// ���� ������
	// (score>=60)?printf("�հ��Դϴ�.\n"): printf("���հ��Դϴ�.\n");

	// ���� �Ǵ� ���α׷�
	int year;

	printf("������ �Է��Ͻÿ�: ");
	scanf("%d", &year);

	// ���� �Ǵ� => ��� ���
	if ((year%4==0&&year%100!=0) || year%400==0)
		printf("%d���� �����Դϴ�.\n", year);
	else
		printf("%d���� ����Դϴ�.\n", year);

	return 0;
}