#include<stdio.h>

/* �˶� �ð� ��� */
int main() {
	int time, hour, m, n;

	printf("���� �ð�: ");
	scanf("%d %d", &hour, &time);
	printf("�˶� �ð�: ");
	scanf("%d %d", &m, &n);

	if(m>=hour, n>=time)
		printf("%d�ð� %d�� ", m-hour, n-time);

	return 0;
}