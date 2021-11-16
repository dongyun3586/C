#include <stdio.h>
#include <string.h>    // strcpy 함수가 선언된 헤더 파일
#include <stdlib.h>    // malloc, free 함수가 선언된 헤더 파일

struct Person {
    char name[20];
    int age;
    char address[100];
} person;

int main()
{
    struct Person* p1 = &person;
    printf("size of Person = %d bytes\n\n", sizeof(person));

    // 구조체에 값 입력
    strcpy(p1->name, "홍길동");
    p1->age = 30;
    strcpy(p1->address, "서울시 용산구 한남동");

    // 구조체 값 출력
    printf("이름: %s\n", p1->name);
    printf("나이: %d\n", p1->age);
    printf("주소: %s\n", p1->address);

    return 0;
}