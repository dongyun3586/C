#include<stdio.h>
int factorial(int n);
int permutation(int n, int r);
int main() {
	// �� ���� ���� [2��]
	int n, r;

	// �� �Է� ���� �ȳ� �� �Է� �ޱ� [2��]
	printf("n�� r �Է�: ");
	scanf("%d %d", &n, &r);

	// �� ��� ��� [4��]
	printf("P(%d, %d) = %d \n", n, r, permutation(n, r));
	printf("C(%d, %d) = %d \n", n, r, permutation(n, r) / factorial(r));

	return 0;
}
// �� factorial �Լ� [4��]
int factorial(int n) {
	int result = 1;
	for (int i = 1; i <= n; i++)
		result *= i;
	return result;
}
// �� permutation �Լ� [3��]
int permutation(int n, int r) {
	return factorial(n) / factorial(n - r);
}