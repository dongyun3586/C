//�� ����(a, b)�� �Է¹޾�
//a�� b�� ���� �ٸ��� 1��, �׷��� ������ 0�� ����ϴ� ���α׷��� �ۼ��غ���.

#include<stdio.h>

int main(void) {
	int a, b;
	scanf("%d %d", &a, &b);
	if (a != b)
		printf("%d\n", 1);
	else
		printf("%d\n", 0);

	return 0;
}
