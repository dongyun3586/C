#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printBookInfo(struct book b);

// ����ü ����
struct book
{
    char title[30];
    char author[30];
    int price;
};

void main()
{
    // ����ü ���� ����
    struct book book1 = { "HTML CSS JS", "ȫ�浿", 28000 };
    struct book book2;

    // ����ü ��� ����
    strcpy(book2.title, "C language");
    strcpy(book2.author, "�� �轼, ���Ͻ� ��ġ");
    book2.price = 35000;

    printBookInfo(book1);
    printBookInfo(book2);

    return 0;
}

void printBookInfo(struct book b) {
    printf("����: %s\n", b.title);
    printf("����: %s\n", b.author);
    printf("����: %d\n\n", b.price);
}

