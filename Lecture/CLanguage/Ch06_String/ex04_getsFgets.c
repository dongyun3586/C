#include<stdio.h>

int main() {
	char str[12] = "";

	printf("���ڿ� �Է� : ");
	gets(str);					// '\n'�� ���ŵǰ�, ���ڿ��� �������� NULL���� '\0'�� �߰��ȴ�.
	printf("%s\n", str);
	puts(str);					// ��� �� �� NULL ����('\0')�� '\n'���� �����Ѵ�.

	printf("���ڿ� �Է� : ");
	fgets(str, 12, stdin);		// ���� ���ڱ��� ���Եȴ�.
	puts(str);
	printf("%s\n", str);

	return 0;
}