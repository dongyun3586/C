#include<stdio.h>

/* ���� ���� ��� ��� */
int main() {
	int a, sum;

	printf("���� ���� �Է�: ");
	scanf("%d", &a);

	for (int i = 0; i <= a; i++) {
		//b = 1;
		for (int j = 0; j <= i; j++)
			i = j * j;
		sum += i;
	}

	printf("%d", sum);

	return 0;
}