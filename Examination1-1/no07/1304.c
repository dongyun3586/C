#include<stdio.h>

/* �˶� �ð� ��� 1301 ������ */
int main() {
	int h, m, H, M;

	printf("���� �ð�: ");
	scanf("%d %d", &h, &m);
	printf("�˶� �ð�: ");
	scanf("%d %d", &H, &M);

	int ah = (1440 - ((60 * h + m) - (60 * H + M) + 1440) % 1440) / 60;
	int am = (1440 - ((60 * h + m) - (60 * H + M) + 1440) % 1440) % 60;

	printf("%d�ð� %d�� ", ah, am);

	return 0;
}