#include<stdio.h>

/* �Ǻ���ġ ���� ��� */
int main() {

	// �� ���� ���� [2��]
	int num, a = 0, b = 1, t;

	// �� �Է� ���� �ȳ� �� �Է� �ޱ� [2��]
	printf("���� ����: ");
	scanf("%d", &num);

	// �� ó�� �� ��� [8��]
	while (a <= num) {
		printf("%d ", a);
		t = a;
		a = b;
		b += t;
	}

	return 0;
}











