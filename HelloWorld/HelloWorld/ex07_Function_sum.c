#include <stdio.h>

// int sum(int value1, int value2);     // �Լ� ���� ����

int sum(int value1, int value2)         // function definition   
{
    int result = value1 + value2;
    return result;                  // return statement
}

void main()
{
    int s;
    s = sum(2, 3);        // function call
    printf("���ϱ� �۾��� ����� %d \n", s);
}