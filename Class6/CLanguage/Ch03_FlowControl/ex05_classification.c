#include<stdio.h>

int main_ex05_classification() {
	char ch;

	printf("���� �ϳ��� �Է��Ͻÿ�: ");
	scanf("%c", &ch);

	if (ch >= '0' && ch<='9')
		printf("%c�� �빮�� �Դϴ�. \n", ch);

	return 0;
}