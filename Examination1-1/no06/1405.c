#include<stdio.h>

/* �Ǻ���ġ ���� ��� */
int main() {

	// �� ���� ���� [2��]
	int a, b, next, n;

	// �� �Է� ���� �ȳ� �� �Է� �ޱ� [2��]
	printf("���� ����: ");
	scanf("%d", &n);

	// �� ó�� �� ��� [8��]
	for (int a = 1; a <= n; ) {
		b = 1;
		next = a + b;
		b = next;
		printf("%d ", a);
	}

#pragma region MyRegion
	//// �� ó�� �� ��� [8��]
	//b = 1;
	//for (int a = 0; a <= n; ) {
	//	printf("%d ", a);
	//	next = a + b;
	//	a = b;
	//	b = next;
	//}
#pragma endregion


	return 0;
}