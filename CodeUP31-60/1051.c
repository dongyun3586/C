//�� ����(a, b)�� �Է¹޾�
//b�� a���� ũ�ų� ������ 1��, �׷��� ������ 0�� ����ϴ� ���α׷��� �ۼ��غ���.

#include<stdio.h>

int main_1051(void) {
	int a, b;
	scanf("%d %d", &a, &b);
	if (b >= a)
		printf("%d\n", 1);
	else
		printf("%d\n", 0);

	return 0;
}