#include<stdio.h>

int main() {
	int sum, n;
	sum = 0;

	printf("1���� �հ踦 ���� ������ �Է��Ͻÿ�: ");
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		sum += i;
	}
	printf("1 ~ %d������ ���� %d �Դϴ�.\n", n, sum);

	return 0;
}