#include <stdio.h>
int main_ex06_scanfExercise()
{
	int a, b, temp;
	scanf("%d %d", &a, &b);
	printf("a=%d, b=%d\n", a, b);

	temp = a;
	a = b;
	b = temp;

	printf("a=%d, b=%d\n", a, b);
}