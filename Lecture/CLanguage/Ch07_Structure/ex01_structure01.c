#include <stdio.h>
#include <string.h>

// ����ü Ÿ�� ����
struct book
{
    char title[30];
    char author[30];
    int price;
};

struct book changeStruct(struct book b, char* title, char* author, int price);
void printBookInfo(struct book b);

void main()
{
    // ����ü ���� ����
    struct book book1 = { "HTML CSS JS", "ȫ�浿", 28000 };
    struct book book2 = book1;

    // ����ü ��� ����
    strcpy(book2.title, "C language");
    strcpy(book2.author, "�� �轼, ���Ͻ� ��ġ");
    book2.price = 35000;

    printBookInfo(book1);
    printBookInfo(book2);
    book1 = changeStruct(book1, "���ǿ���", "���� �϶�", 20000);
    book2 = changeStruct(book2, "���� ���� Ÿ��", "����̾� �׸�", 22000);
    printBookInfo(book1);
    printBookInfo(book2);

    return 0;
}

struct book changeStruct(struct book b, char* title, char* author, int price) {
    strcpy(b.title, title);
    strcpy(b.author, author);
    b.price = price;
    return b;
}

void printBookInfo(struct book b) {
    printf("����: %s\n", b.title);
    printf("����: %s\n", b.author);
    printf("����: %d\n\n", b.price);
}