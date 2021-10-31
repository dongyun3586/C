#include <stdio.h>
#include <string.h>

// 구조체 타입 정의
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
    // 구조체 변수 생성
    struct book book1 = { "HTML CSS JS", "홍길동", 28000 };
    struct book book2 = book1;

    // 구조체 멤버 접근
    strcpy(book2.title, "C language");
    strcpy(book2.author, "켄 톰슨, 데니스 리치");
    book2.price = 35000;

    printBookInfo(book1);
    printBookInfo(book2);
    book1 = changeStruct(book1, "사피엔스", "유발 하라리", 20000);
    book2 = changeStruct(book2, "엔드 오브 타임", "브라이언 그린", 22000);
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
    printf("제목: %s\n", b.title);
    printf("저자: %s\n", b.author);
    printf("가격: %d\n\n", b.price);
}