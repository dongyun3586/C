#include<stdio.h>

// swap 함수 정의
void swap(int* a, int* b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int main() {
	int a = 10, b = 20;

	printf("a=%d, b=%d\n", a, b);
	// swap 함수 호출
	swap(&a, &b);
	printf("a=%d, b=%d\n", a, b);

	return 0;
}