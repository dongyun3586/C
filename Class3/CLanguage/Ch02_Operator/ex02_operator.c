#include<stdio.h>

int main_ex02_operator() {
	int a = 1, b = 1;

	a++;	// a = a + 1
	++b;
	printf("a = %d \n", a);
	printf("b = %d \n", b);

	a--;
	--b;
	printf("a = %d \n", a);
	printf("b = %d \n", b);

	// ���� �����ڰ� �ٸ� �����ڿ� ���յ� ��� �������� �������� ����� �޶���.
	b = ++a;
	printf("a = %d \n", a);
	printf("b = %d \n", b);

	a = 1;
	b = a++;
	printf("a = %d \n", a);
	printf("b = %d \n", b);
}