#include<stdio.h>

// func �Լ� �ۼ��ϱ� a�� ��� 3��, b�� ��� 3��
void func(int x1, int y1, int x2, int y2, double* a, double* b) {
	*a = (y2 - y1) / (double)(x2 - x1);
	*b = y1 - *a * x1;
}

int main() {
	double a = 0, b = 0;

	func(1, 2, 3, 3, &a, &b);
	printf("y = %0.1fx + %0.1f\n", a, b);

	return 0;
}