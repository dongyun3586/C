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

	// 증감 연산자가 다른 연산자와 결합된 경우 전위형과 후위형의 결과가 달라짐.
	b = ++a;
	printf("a = %d \n", a);
	printf("b = %d \n", b);

	a = 1;
	b = a++;
	printf("a = %d \n", a);
	printf("b = %d \n", b);
}