#include<stdio.h>

/* �Ǻ���ġ ���� ��� */
int main() {

	// �� ���� ���� [2��]
	int a, b, next, num;
	a = 0;
	b = 1;
	next = 1;

	printf("���� ����: ");
	scanf("%d", &num);
	printf("%d %d ", a, b);

	while (1) {
		a = b;
		b = next;
		next = a + b;
		if (next > num)
			break;
		printf("%d ", next);
	}

	return 0;
}