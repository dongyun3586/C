#include<stdio.h>

/* �Ǻ���ġ ���� ��� */
int main() {

	// �� ���� ���� [2��]
	int a, i, j, n;

	// �� �Է� ���� �ȳ� �� �Է� �ޱ� [2��]
	printf("���� ����: ");
	scanf("%d", &a);

	i = 0, j = 1;

	printf("%d %d ", i, j);
	n = i + j;

	while (n<a) {
		printf("%d ", n);
		i = n;
		n = n + j;
		j = i;
	}

	return 0;
}