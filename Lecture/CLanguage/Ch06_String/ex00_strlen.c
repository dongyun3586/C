#include <stdio.h>
int calculateLength(char*);

void main()
{
	char str[25] = "Hello world";
	printf("���ڿ� ���� ���ϱ�\n");
	printf("%s�� ���ڿ� ���� : %d ", str, calculateLength(str));
	printf("\n\n");

}

int calculateLength(char* ch)
{
	int ctr = 0;
	while (*ch != '\0')
	{
		ctr++;
		ch++;
	}
	return ctr;
}