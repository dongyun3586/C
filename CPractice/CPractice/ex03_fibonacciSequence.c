#include<stdio.h>

int main() {
	int n, a = 0, b = 1, next;

#pragma region ������ ������ŭ �Ǻ���ġ ���� ���
	printf("�Ǻ���ġ ���� ��� ������? ");
	scanf("%d", &n);

	// for���� �̿��Ͽ� �Ǻ���ġ ���� ���
	for (int i = 0; i < n; i++) {
		printf("%d ", a);
		next = a + b;
		a = b;
		b = next;
	}

	printf("\n\n");
#pragma endregion

#pragma region �Էµ� ���ں��� ���� �Ǻ���ġ ���� ��� ���
	printf("���� ������ �Է��Ͻÿ�: ");
	scanf("%d", &n);

	// while���� ����Ͽ� �Ǻ���ġ ���� ���
	a = 0, b = 1;
	for (; ;) {
		printf("%d ", a);
		next = a + b;
		a = b;
		b = next;
	}
	/*while (a <= n) {
		printf("%d ", a);
		next = a + b;
		a = b;
		b = next;
	}*/

	printf("\n");
#pragma endregion

	return 0;
}