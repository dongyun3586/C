#include<stdio.h>

/* �Ǻ���ġ ���� ��� */
int main() {

	// �� ���� ���� [2��]
	int fibo1 = 0, fibo2 = 1, fibo, n;

	printf("���� ����: ");
	scanf("%d", &n);

	printf("%d %d ", fibo1, fibo2);
	while (1) {
		fibo = fibo1 + fibo2;
		if (fibo <= n) {
			printf("%d ", fibo);
			fibo1 = fibo2;
			fibo2 = fibo;
		}
		else {
			break;
		}
	}

	return 0;
}