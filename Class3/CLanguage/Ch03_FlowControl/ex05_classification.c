#include<stdio.h>

int main_ex05_classification() {

	char ch;

	scanf("%c", &ch);

	if(ch>='A' && ch<='Z')
		printf("�빮�� �Դϴ�.\n");
	else if(ch>='a' && ch<='z')
		printf("�ҹ��� �Դϴ�.\n");
	else if(ch >= '0' && ch <= '9')
		printf("���� �Դϴ�.\n");
	else
		printf("�����ڳ� ���ڰ� �ƴմϴ�.\n");

	return 0;
}