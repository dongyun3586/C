#include<stdio.h>

/* ���� ���� ��� ��� */
int main() {
	int n, gob = 1, jegob = 0;

	printf("���� ���� �Է�: ");
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		jegob = i * i;
		gob *= jegob;
	}
	printf("%d\n", gob);

	return 0;
}