#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printBookInfo(struct book b);

// 구조체 정의
struct book
{
    char title[30];
    char author[30];
    int price;
};

void main()
{
    // 구조체 변수 생성
    struct book book1 = { "HTML CSS JS", "홍길동", 28000 };
    struct book book2;

    // 구조체 멤버 접근
    strcpy(book2.title, "C language");
    strcpy(book2.author, "켄 톰슨, 데니스 리치");
    book2.price = 35000;

    printBookInfo(book1);
    printBookInfo(book2);

    return 0;
}

void printBookInfo(struct book b) {
    printf("제목: %s\n", b.title);
    printf("저자: %s\n", b.author);
    printf("가격: %d\n\n", b.price);
}

