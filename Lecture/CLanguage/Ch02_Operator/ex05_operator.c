/* (��������5) �ﰢ���� ���� ���� ���ϱ� */

#include<stdio.h>

int main_ex05_operator() {
	// ���� ����
	double width, height, radius;
	const float PI = 3.14;

	// �ﰢ���� ���� ���ϱ�
	printf("�ﰢ���� �ʺ�� ����: ");
	scanf_s("%f %f", &width, &height);
	printf("�ﰢ���� ����: %f\n\n", width * height / 2);

	// ���� ���� ���ϱ�
	printf("���� ������: ");
	scanf_s("%f", &radius);
	printf("���� ����: %f\n", radius * radius * PI);

	return 0;
}