#include<stdio.h>

/* �˶� �ð� ��� */
int main() {
	// ��) ���� ���� [2��]
	int a, b, c, d;

	// �� �Է� ���� �ȳ� �� �Է� �ޱ� [2��]
	printf("���� �ð�: ");
	scanf("%d %d", &a, &b);
	printf("�˶� �ð�: ");
	scanf("%d %d", &c, &d);

	// �� ó�� [8��]
	if (c > a && d > b)
		printf("%d�ð� %d�� ", c - a, d - b);
	else if (c > a && d < b)
		printf("%d�ð� %d�� ", c - a - 1, 60 - d + b);
	else if (c < a && d < b)
		printf("%d�ð� %d�� ", 24-c+a, d - b);
	else
		printf("%d�ð� %d�� ", 24 - c + a-1, 60-d + b);

	// �� ��� [3��]

	return 0;
}