#include<stdio.h>

/* �Ǻ���ġ ���� ��� */
int main() {

	int a = 1, b = 0, c = 0, n;

	printf("���� ����: ");
	scanf("%d", &n);

	for (int i = 0; ; i++) {
		if (c >= n)
			break;
		printf("%d ", c);
		c = a + b;
		a = b;
	}

	return 0;
}