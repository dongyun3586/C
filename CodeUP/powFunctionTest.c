#include<stdio.h>

//int intPow(int base, int exponent);

int main_powFunctionTest(void) {

	printf("%d\n", intPow(10, 4));
	return 0;
}

//int intPow(int base, int exponent) {
//	int result = 1;
//
//	for (int i = exponent; i > 0; i--) {
//		result *= base;
//	}
//
//	return result;
//}