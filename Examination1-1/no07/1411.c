#include<stdio.h>

/* �˶� �ð� ��� */
int main() {
	int time, hour, m, n;

	printf("���� �ð�: ");
	scanf("%d %d", &hour, &time);
	printf("�˶� �ð�: ");
	scanf("%d %d", &m, &n);

	if (m >= hour, n >= time)
		printf("%d�ð� %d�� ", m - hour, n - time);
	if (m >= hour, n < time)
		printf("%d�ð� %d�� ", m - hour - 1, n + 60 - time);
	if (m < hour, n >= time)
		printf("%d�ð� %d�� ", 24 + m - hour, n - time);
	if (m < hour, n < time)
		printf("%d�ð� %d�� ", 24 + m - hour - 1, n + 60 - time);

	return 0;
}