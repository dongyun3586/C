#include<stdio.h>

/* �Ǻ���ġ ���� ��� */
int main() {

	// �� ���� ���� [2��]
	int a, b, t, num;

	// �� �Է� ���� �ȳ� �� �Է� �ޱ� [2��]
	printf("���� ����: ");
	scanf("%d", &num);
	a = 0; b = 1;

	// �� ó�� �� ��� [8��]
	printf("0 1 ");
	while (1) {
		t = a + b;
		if (t > num)
			break;
		printf("%d ", t);
		b = a;
		a = t;
	}

	return 0;
}