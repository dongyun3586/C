#include<stdio.h>

/* �Ǻ���ġ ���� ��� */
int main() {

	// �� ���� ���� [2��]
	int num, sum = 0, temp;

	// �� �Է� ���� �ȳ� �� �Է� �ޱ� [2��]
	printf("���� ����: ");
	scanf("%d", &num);

	// �� ó�� �� ��� [8��]
	for (int i = 0; i < num; i = temp) {
		while (sum <= num) {
			temp = sum;
			sum = sum + i;
			printf("%d", sum);
		}
	}

	return 0;
}