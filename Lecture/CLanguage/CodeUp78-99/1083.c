//3 6 9 ������ �ϴ� �����̴� 3 6 9 ���ӿ��� ���� �Ǽ��� ����ؼ� ��Ģ�� �ް� �Ǿ���.
//3 6 9 ������ ���� �Ǳ� ���� ������ ���α׷��� �ۼ��� ����.

#include<stdio.h>

int main_1083() {
	int n, i;
	scanf("%d", &n);

	for (i = 1; i <= n; i++)
	{
		if (i % 3 != 0)
			printf("%d ", i);
		else
			printf("X ");
	}

	return 0;
}