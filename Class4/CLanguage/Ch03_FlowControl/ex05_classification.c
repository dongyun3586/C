// (��������5) ���ںз� (ex05_classification.c)

#include<stdio.h>

int main_ex05_classification() {
	char ch;

	printf("���� �ϳ� �Է�: ");
	scanf("%c", &ch);
	
	if (ch >= '0' && ch <= '9')
		printf("%c�� �����Դϴ�. \n", ch);

}