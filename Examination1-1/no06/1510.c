#include<stdio.h>

/* �Ǻ���ġ ���� ��� */
int main() {

	// �� ���� ���� [2��]
	printf("���� ����: "); 
	
	int a = 0, b = 1, next, n;

	// �� �Է� ���� �ȳ� �� �Է� �ޱ� [2��]
	scanf("%d", &n);

	// �� ó�� �� ��� [8��]
	if (n <= 2)
		printf("0 1 1 2");
	else if (n == 1)
		printf("0 1 1");
	else
		while (1)
			printf(" 0 1 ");
	next = a + b;

	int k = 1;
	if (k % 2 == 0)
		b = next;
	else
		a = next;
	if (next > n)
		//break;
	printf("%d ", next);

	return 0;
}