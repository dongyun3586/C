#include<stdio.h>

// swap �Լ� ����
void swap(int* a, int* b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int main() {
	int a = 10, b = 20;

	printf("a=%d, b=%d\n", a, b);
	// swap �Լ� ȣ��
	swap(&a, &b);
	printf("a=%d, b=%d\n", a, b);

	return 0;
}