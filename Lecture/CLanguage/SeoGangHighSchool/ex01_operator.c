#include<stdio.h>

int main1() {
	float w, h, r, pi = 3.14;
	printf("�ﰢ���� �ʺ�� ����: ");
	scanf("%f %f", &w, &h);

	printf("�ﰢ���� ����: %f\n", w * h / 2);

	printf("���� ������: ");
	scanf("%f", &r);
	printf("���� ����: %f\n", r * r * pi);

	return 0;
}