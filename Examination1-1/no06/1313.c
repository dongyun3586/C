#include<stdio.h>

/* �Ǻ���ġ ���� ��� */
int main() {

	// �� ���� ���� [2��]
	int n, a = 0, b = 1;

	scanf("%d", &n);

	while (1) {
		if (a > n)
			break;
		printf("%d ", a);
		if (b > n)
			break;
		printf("%d ", b);
		a = a + b;
		b = a + b;
	}

	return 0;
}