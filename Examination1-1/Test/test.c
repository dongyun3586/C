#include<stdio.h>

/* �˶� �ð� ���  1612 �ӿ��� */
int main() {
	int hh, hm, rh, rm;

	printf("���� �ð�: ");
	scanf("%d %d", &hh, &hm);
	printf("�˶� �ð�: ");
	scanf("%d %d", &rh, &rm);

	if (rm >= hm)	// �˶��� > �����
		// (�˶��ð� - ����ð� + 24) % 24
		printf("%d�ð� %d�� ", (rh - hh + 24) % 24, rm - hm);
	else
		printf("%d�ð� %d�� ", (rh - hh + 23) % 24, rm - hm + 60);

	return 0;
}