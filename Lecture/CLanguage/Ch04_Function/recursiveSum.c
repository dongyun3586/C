#include<stdio.h>

int recursiveSum(int n);

int main() {
	int n;
	printf("���� ����: ");
	scanf("%d", &n);

	printf("1~%d�� �հ�: %d\n", n, recursiveSum(n));

	return 0;
}

int recursiveSum(int n)
{
	if (n == 1)                   // n�� 1�̸�, �׳� 1�� ��ȯ��.
	{
		return 1;
	}
	return n + recursiveSum(n - 1); // n�� 1�� �ƴϸ�, n�� 1���� (n-1)������ �հ� ���� ���� ��ȯ��.
}