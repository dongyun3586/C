#include <stdio.h>
#include <string.h>    // strcpy �Լ��� ����� ��� ����
#include <stdlib.h>    // malloc, free �Լ��� ����� ��� ����

struct Person {           // ����ü ����
    char* name;        // ����ü ��� 1
    int age;              // ����ü ��� 2
    char* address;    // ����ü ��� 3
};

int heapUsage = 0;      // �� �޸� ��뷮 ���� ����

int main()
{
    struct Person* p1 = malloc(sizeof(struct Person));    // ����ü ������ ����, �޸� �Ҵ�
    heapUsage += sizeof(sizeof(struct Person));

    // ȭ��ǥ �����ڷ� ����ü ����� �����Ͽ� �� �Ҵ�
    p1->name = malloc(sizeof(char) * sizeof("ȫ�浿"));
    strcpy(p1->name, "ȫ�浿");
    heapUsage += sizeof(char) * sizeof("ȫ�浿");

    p1->age = 30;
    p1->address = malloc(sizeof(char) * sizeof("����� ��걸 �ѳ���"));
    strcpy(p1->address, "����� ��걸 �ѳ���");
    heapUsage += sizeof(char) * sizeof("����� ��걸 �ѳ���");

    // �޸� ��뷮 ���
    printf("heap memory usage = %d bytes\n\n", heapUsage);

    // ȭ��ǥ �����ڷ� ����ü ����� �����Ͽ� �� ���
    printf("�̸�: %s\n", p1->name);       // ȫ�浿
    printf("����: %d\n", p1->age);        // 30
    printf("�ּ�: %s\n", p1->address);    // ����� ��걸 �ѳ���

    free(p1);    // ���� �޸� ����

    return 0;
}