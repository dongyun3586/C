#include<stdio.h>

/* �Ǻ���ġ ���� ��� */
int main() {

	// �� ���� ���� [2��]
	int a = 0, b = 1, c=0, x;

	// �� �Է� ���� �ȳ� �� �Է� �ޱ� [2��]
	printf("���� ����: ");
	scanf("%d", &x);

	// �� ó�� �� ��� [8��]
	while (c <= x) {
		printf("%d ", c);
		c = a + b;
		a = b;
		b = c;
	}

#pragma region MyRegion
	//// �� ó�� �� ��� [8��]
	//while (a <= x) {
	//	printf("%d ", a);
	//	c = a + b;
	//	a = b;
	//	b = c;
	//}
#pragma endregion


	return 0;
}