//A, B, C, D, E, F �� �ϳ��� �Էµ� ��, 1���� F���� ���� 16���� �������� ������ ����غ���.
//(��, A ~F ������ �Էµȴ�.)

#include<stdio.h>

int main_1082() {
	int n, i;
	scanf("%X", &n);

	for (i = 1; i < 16; i++)
	{
		printf("%X*%X=%X\n", n, i, n * i);
	}

	return 0;
}