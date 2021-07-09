#include<stdio.h>
int factorial(int n);
int permutation(int n, int r);
int main() {
	// �� ���� ���� [2��]
	int a, b, c, d, e;

	// �� �Է� ���� �ȳ� �� �Է� �ޱ� [2��]
	printf("n�� r �Է�: ");
	scanf("%d %d", &a, &b);

	// �� ��� ��� [4��]
	c = factorial(a);
	d = factorial(b);
	printf("P(%d, %d) = %d \n", a, b, permutation(a, b));
	printf("C(%d, %d) = %d \n", a, b, permutation(a, b) / d);

	return 0;
}
// �� factorial �Լ� [4��]
int factorial(int n) {
	if (n == 1)
		return 1;
	else
		return n * factorial(n - 1);
}
// �� permutation �Լ� [3��]
int permutation(int n, int r) {
	int k = n - r;
	return factorial(n) / factorial(k);
}