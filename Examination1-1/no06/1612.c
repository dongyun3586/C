#include<stdio.h>

/* �Ǻ���ġ ���� ��� */
int main() {

	// �� ���� ���� [2��]
	int a1 = 0, a2 = 1, a3 = 1, t, n;

	// �� �Է� ���� �ȳ� �� �Է� �ޱ� [2��]
	printf("���� ����: ");
	scanf("%d", &n);

	// �� ó�� �� ��� [8��]
	while (t <= n) {
		printf("%d ", a1);
		t = a3;
		a3 = a1 + a2;
		a1 = a2;
		a2 = t;
	}

#pragma region MyRegion
		//// �� ���� ���� [2��]
		//int a1 = 0, a2 = 1, a3 = 1, t, n;

		//// �� �Է� ���� �ȳ� �� �Է� �ޱ� [2��]
		//printf("���� ����: ");
		//scanf("%d", &n);

		//// �� ó�� �� ��� [8��]
		//while (a1 <= n) {			// ����1
		//	printf("%d ", a1);

		//	a3 = a1 + a2;
		//	t = a3;					// ����2
		//	a1 = a2;
		//	a2 = t;
		//}
#pragma endregion


	return 0;
}









