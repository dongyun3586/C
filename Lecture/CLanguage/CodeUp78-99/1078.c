// ����(1 ~ 100) 1���� �Է¹޾� 1���� �� ������ ¦���� ���� ���غ���.

	#include<stdio.h>

	int main_1078() {
		int n, sum=0;
		scanf("%d", &n);

		for (int i = 0; i <= n; i++) {
			if (i % 2 == 0)
				sum = sum + i;
		}
		printf("%d\n", sum);

		return 0;
	}