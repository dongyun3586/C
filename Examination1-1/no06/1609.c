#include<stdio.h>

/* �Ǻ���ġ ���� ��� */
int main() {

	// �� ���� ���� [2��]
	int a = 0, b = 1, n = 0, s = 0;

	// �� �Է� ���� �ȳ� �� �Է� �ޱ� [2��]
	printf("���� ����: ");
	scanf("%d", &n);

	// �� ó�� �� ��� [8��]
	printf("0 ");  // ����
	while (1) {
		printf("%d ", s);	// ���� 
		s = a + b;
		a = b;
		b = s;
		if (s > n) break;
	}

	return 0;
}









