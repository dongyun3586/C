#include<stdio.h>

int main() {
	// ���� ����
	char ch;

	// �Է� �ޱ�
	printf("���� �ϳ��� �Է��Ͻÿ�. ");
	scanf("%c", &ch);

	// ó�� �� ���
	if (ch >= 'A' && ch <= 'Z')
		printf("%c�� �빮�� �Դϴ�.\n", ch);
	else if (ch >= 'a' && ch <= 'z')
		printf("%c�� �ҹ��� �Դϴ�.\n", ch);
	else if (ch >= '0' && ch <= '9')
		printf("%c�� ���� �Դϴ�.\n", ch);
	else
		printf("%c�� �����ڳ� ���ڰ� �ƴմϴ�.\n", ch);


	return 0;
}