#include<stdio.h>

/* ���� ���� ��� ��� */
int main() {
	int n, answer = 1;

	printf("���� ���� �Է�: ");
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		mul = 1;
		for (int j = 0; j <= n; j++)
			mul *= n;
		answer *= mul;
			
	}

	printf("%d", answer);

	return 0;
}