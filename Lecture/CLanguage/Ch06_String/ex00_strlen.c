#include <stdio.h>
int calculateLength(char*);

void main()
{
	char str[25] = "Hello world";
	printf("문자열 길이 구하기\n");
	printf("%s의 문자열 길이 : %d ", str, calculateLength(str));
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