#include<stdio.h>

int main_ex05_classification() {
	char ch;

	printf("���� �ϳ��� �Է��Ͻÿ�: ");
	scanf("%c", &ch);

	if (ch >= 65 && ch <= 90)
		printf("%c�� �빮���Դϴ�. \n", ch);
	else if (ch >= 'a' && ch <= 'z')
		printf("%c�� �ҹ����Դϴ�. \n", ch);
	else if (ch >= '0' && ch <= '9')
		printf("%c�� �����Դϴ�. \n", ch);
	else
		printf("%c�� ���ĺ��̳� ���ڰ� �ƴմϴ�. \n", ch);

	return 0;
}