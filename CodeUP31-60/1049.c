//�� ����(a, b)�� �Է¹޾�
//a�� b���� ũ�� 1��, a�� b���� �۰ų� ������ 0�� ����ϴ� ���α׷��� �ۼ��غ���.

#include<stdio.h>

int main_1049(void) {
	int a, b;
	scanf("%d %d", &a, &b);
	if (a > b)
		printf("%d\n", 1);
	if (a < b || a==b)
		printf("%d\n", 0);

	return 0;
}
