#include<stdio.h>

int main_ex14_gugudan() {
	int dan, i=1;

	printf("�� ��? ");
	scanf("%d", &dan);

	// while������ ������ ����ϱ�
	while (i <= 9) {
		printf("%d * %d = %2d \n", dan, i, dan * i);
		i++;
	}

	return 0;
}