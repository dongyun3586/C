#include<stdio.h>

/* �Ǻ���ġ ���� ��� */
int main() {

	// �� ���� ���� [2��]
	int a = 0;
	int b = 1;
	int Data;
	int temp;

	// �� �Է� ���� �ȳ� �� �Է� �ޱ� [2��]
	printf("���� ����: ");
	scanf("%d", &Data);

	printf("\n"); // ����

	// �� ó�� �� ��� [8��]
	while (a < Data + 1) {
		printf("%d ", a);
		temp = a;
		a = b;
		b = b+temp;
	}

	return 0;
}