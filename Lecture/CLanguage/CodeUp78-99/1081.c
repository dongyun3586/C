//1���� n����, 1���� m���� ���ڰ� ����
//���� �ٸ� �ֻ��� 2���� ������ �� ���� �� �ִ� ��� ��츦 ����غ���.

#include<stdio.h>

int main_1081() {
	int i, j, n, m;
	scanf("%d %d", &n, &m);
	
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			printf("%d %d\n", i, j);
		}
	}

	return 0;
}