#include<stdio.h>

/* ���� ���� ��� ��� */
int main() {
	int n;
	long long sum = 1;

	printf("���� ���� �Է�: ");
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		int num = 1;
		for (int j = 1; j <= i; j++)
			num *= i;
		sum *= num;
	}

	printf("%d", sum);

	return 0;
}