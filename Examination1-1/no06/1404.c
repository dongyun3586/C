#include<stdio.h>

/* �Ǻ���ġ ���� ��� */
int main() {

	// �� ���� ���� [2��]
	int a, t;
	int b = 0;
	int c = 1;

	// �� �Է� ���� �ȳ� �� �Է� �ޱ� [2��]
	printf("���� ����: ");
	scanf("%d", &a);

	// �� ó�� �� ��� [8��]
	printf("%d ", b);
	while (c <= a) {
		t = c;
		c = b + c;
		b = t;
		printf("%d ", b);
	}

	return 0;
}