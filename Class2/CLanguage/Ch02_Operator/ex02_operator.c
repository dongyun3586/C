#include<stdio.h>

int main_ex02_operator() {
	int a = 1, b = 1;

	//a++;	// a = a + 1;
	//++b;
	//printf("a = %d \n", a);  // 2
	//printf("b = %d \n", b);  // 2

	//a--;
	//--b;
	//printf("a = %d \n", a);	// 1
	//printf("b = %d \n", b);	// 1

	// 증감 연산자가 다른 연산자와 결합된 경우 전위형과 후위형의 결과가 달라짐.
	a = 1, b = 1;
	b = ++a;
	printf("a = %d \n", a);	// 2
	printf("b = %d \n", b);	// 2

	a = 1;
	b = a++;
	printf("a = %d \n", a);	// 2
	printf("b = %d \n", b);	// 1
}