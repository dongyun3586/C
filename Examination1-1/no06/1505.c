#include<stdio.h>

/* �Ǻ���ġ ���� ��� */
int main() {

	// �� ���� ���� [2��]
	int a, x = 0, y = 1, z;

	// �� �Է� ���� �ȳ� �� �Է� �ޱ� [2��]
	printf("���� ����: ");
	scanf("%d", &a);

	// �� ó�� �� ��� [8��]
	for (z = 0; z < a; z = z + 1) {  // z ����, <= ����
		printf("%d ", x);
		z = x + y;
		x = y;
		y = z;
	}

#pragma region MyRegion
	//// �� ó�� �� ��� [8��]
	//for (z = 0; x <= a; z = z + 1) {
	//	printf("%d ", x);
	//	z = x + y;
	//	x = y;
	//	y = z;
	//}
#pragma endregion


	return 0;
}