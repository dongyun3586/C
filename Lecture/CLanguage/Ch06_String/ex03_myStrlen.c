#include <stdio.h>
int myStrlen(const char* str);

int main(void)
{
    char str[] = "Hello world";
    printf("%s�� ���ڿ� ���� : %d\n", str, myStrlen(str));
}

// myStrlen( ) �Լ� ����
int myStrlen(const char* str) {
    int l = 0;
    while (str[l] != '\0')
        l++;
    return l;
}

