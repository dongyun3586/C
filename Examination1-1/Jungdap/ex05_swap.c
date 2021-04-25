#include <stdio.h>
int main()
{
	int a, b, t;

	printf("정수 두 개를 입력하시오: ");
	scanf("%d %d", &a, &b);

	printf("a=%2d, b=%2d\n", a, b);
	// 두 변수의 값 교환하여 저장
	t = a;
	a = b;
	b = t;

#pragma region case 2
	/*a = a + b;
	b = a - b;
	a = a - b;*/
#pragma endregion

	printf("a=%2d, b=%2d\n", a, b);
}