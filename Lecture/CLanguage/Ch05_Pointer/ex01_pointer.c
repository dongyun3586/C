#include<stdio.h>

void swap(int* p1, int* p2) {
	int temp;
	temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

int main() {
	int a = 10, b = 20;

	printf("a=%d, b=%d\n", a, b);
	swap(&a, &b);
	printf("a=%d, b=%d\n", a, b);

	return 0;
}

