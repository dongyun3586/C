#include<stdio.h>

/* �Ǻ���ġ ���� ��� */
int main() {

	int a, b, t, n, m;
	a = 0, b = 1, n = a + b;

	printf("���� ����: ");
	scanf("%d", &t);

	printf("%d %d ", a, b);
	for (int i = 0; i <= t; i++) {
		m = b;
		b = n;
		a = m;
		n = a + b;
		if (n > t)
			break;
		printf("%d ", n);
	}

	return 0;
}