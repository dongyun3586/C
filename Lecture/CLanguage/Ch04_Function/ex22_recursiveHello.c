#include <stdio.h>

void hello(int count);

int main()
{
    hello(5);    // hello �Լ� ȣ��
    return 0;
}

void hello(int count)
{
    if (count == 0)     // ���� ������ ����. count�� 0�̸� �ٽ� hello �Լ��� ȣ������ �ʰ� ����
        return;

    printf("Hello, world! %d\n", count);
    hello(--count);     // count�� ���ҽ��Ѽ� �ٽ� hello�� ����
}