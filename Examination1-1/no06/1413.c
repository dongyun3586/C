#include<stdio.h>

/* �Ǻ���ġ ���� ��� */
int main() {

	// �� ���� ���� [2��]
	int a = 0, b = 1, next=1, n;

	// �� �Է� ���� �ȳ� �� �Է� �ޱ� [2��]
	printf("���� ����: ");
	scanf("%d", &n);

	// �� ó�� �� ��� [8��]
	while (next <= n) {
		printf("%d ", next);
		b = next;
		a = b;
		next = a + b;
	}

#pragma region MyRegion
	//// �� ó�� �� ��� [8��]
	//while (a <= n) {
	//	printf("%d ", a);
	//	next = a + b;
	//	a = b;
	//	b = next;
	//}
#pragma endregion


	return 0;
}