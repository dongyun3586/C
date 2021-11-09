#include <stdio.h>
#include <string.h>    // strcpy 함수가 선언된 헤더 파일
#include <stdlib.h>    // malloc, free 함수가 선언된 헤더 파일

struct Person {           // 구조체 정의
    char* name;        // 구조체 멤버 1
    int age;              // 구조체 멤버 2
    char* address;    // 구조체 멤버 3
};

int heapUsage = 0;      // 힙 메모리 사용량 저장 변수

int main()
{
    struct Person* p1 = malloc(sizeof(struct Person));    // 구조체 포인터 선언, 메모리 할당
    heapUsage += sizeof(sizeof(struct Person));

    // 화살표 연산자로 구조체 멤버에 접근하여 값 할당
    p1->name = malloc(sizeof(char) * sizeof("홍길동"));
    strcpy(p1->name, "홍길동");
    heapUsage += sizeof(char) * sizeof("홍길동");

    p1->age = 30;
    p1->address = malloc(sizeof(char) * sizeof("서울시 용산구 한남동"));
    strcpy(p1->address, "서울시 용산구 한남동");
    heapUsage += sizeof(char) * sizeof("서울시 용산구 한남동");

    // 메모리 사용량 출력
    printf("heap memory usage = %d bytes\n\n", heapUsage);

    // 화살표 연산자로 구조체 멤버에 접근하여 값 출력
    printf("이름: %s\n", p1->name);       // 홍길동
    printf("나이: %d\n", p1->age);        // 30
    printf("주소: %s\n", p1->address);    // 서울시 용산구 한남동

    free(p1);    // 동적 메모리 해제

    return 0;
}