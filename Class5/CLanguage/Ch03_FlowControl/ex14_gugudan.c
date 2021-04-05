#include<stdio.h>

int main_ex14_gugudan() {
	int dan, i=1;

	printf("¸î ´Ü? ");
	scanf("%d", &dan);

	while (i<=9) {
		printf("%2d * %2d = %2d\n", dan, i, dan * i);
		i++;
	}

	return 0;
}