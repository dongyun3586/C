#include <stdio.h>
#include <stdlib.h>  
#include <string.h>

typedef struct BOOK {
    char title[30];
    char author[30];
    char publisher[30];
    int borrowed;
}BOOK;
char searchword(char* str, char* dest);
int addbook(BOOK* booklist, int* num);
int searchbook(BOOK* booklist, int total);
int borrowbook(BOOK* booklist);
int returnbook(BOOK* booklist);

int main() {
    int a; /* 유저가 선택한 메뉴 */
    int total = 0; /* 현재 책의 수 */

    BOOK* booklist;

    printf("도서관의 최대 보관 장서 수를 설정해주세요 : ");
    scanf_s("%d", &a);

    booklist = (BOOK*)malloc(sizeof(BOOK) * a);

    while (1) {
        printf("도서 관리 프로그램 \n");
        printf("메뉴를 선택하세요 \n");
        printf("1. 책을 새로 추가하기 \n");
        printf("2. 책을 검색하기 \n");
        printf("3. 책을 빌리기 \n");
        printf("4. 책을 반납하기 \n");
        printf("5. 프로그램 종료 \n");

        printf("당신의 선택은 : ");
        scanf_s("%d", &a);

        if (a == 1) {
            /* 책을 새로 추가하는 함수 호출 */
            addbook(booklist, &total);
        }
        else if (a == 2) {
            /* 책을 검색하는 함수 호출 */
            searchbook(booklist, total);
        }
        else if (a == 3) {
            /* 책을 빌리는 함수 호출 */
            borrowbook(booklist);
        }
        else if (a == 4) {
            /* 책을 반납하는 함수 호출 */
            returnbook(booklist);
        }
        else {
            printf("이용해주셔서 감사합니다.");
            break;
        }
    }
    free(booklist);
    return 0;
}

char searchword(char* str, char* dest) {
    int src = 0;
    int searchsrc = 0;

    while (*str) {
        if (*str == *dest) {
            while (*dest) {
                if (*str != *dest) {
                    dest -= searchsrc;
                    src += searchsrc;
                    searchsrc = 0;
                    break;
                }
                str++;
                dest++;
                searchsrc++;
                if (*dest == 0) {
                    return src;
                }
            }
        }
        str++;
        src++;
    }
    return -1;
}

int addbook(BOOK* booklist, int* num) {
    printf("책 제목 : ");
    scanf_s("%s", booklist[*num].title, sizeof(booklist[*num].title));

    printf("저자 : ");
    scanf_s("%s", booklist[*num].author, sizeof(booklist[*num].author));

    printf("출판사 : ");
    scanf_s("%s", booklist[*num].publisher, sizeof(booklist[*num].publisher));

    booklist[*num].borrowed = 0;
    (*num)++;

    return 0;
}

int searchbook(BOOK* booklist, int total) {
    int b; /* 사용자의 입력을 받는다. */
    int i;

    char search[30];
    printf("어느 것으로 검색 할 것인가요? \n");
    printf("1. 책 제목 검색 \n");
    printf("2. 저자 검색 \n");
    printf("3. 출판사 검색 \n");
    scanf_s("%d", &b);

    printf("검색할 단어를 입력해주세요 : ");
    scanf_s("%s", search, sizeof(search));
    printf("검색 결과 \n");

    if (b == 1) {
        for (i = 0; i < total; i++) {
            if (searchword(booklist[i].title, search) >= 0) {
                printf("번호 : %d // 책 제목 : %s // 저자 : %s // 출판사 : %s \n", i, booklist[i].title, booklist[i].author, booklist[i].publisher);
            }
            else printf("정보 없음.\n");
        }
    }
    else if (b == 2) {
        for (i = 0; i < total; i++) {
            if (searchword(booklist[i].author, search) >= 0) {
                printf("번호 : %d // 책 제목 : %s // 저자 : %s // 출판사 : %s \n", i, booklist[i].title, booklist[i].author, booklist[i].publisher);
            }
            else printf("정보 없음.\n");
        }
    }
    else if (b == 3) {
        for (i = 0; i < total; i++) {
            if (searchword(booklist[i].publisher, search) >= 0) {
                printf("번호 : %d // 책 제목 : %s // 저자 : %s // 출판사 : %s \n", i, booklist[i].title, booklist[i].author, booklist[i].publisher);
            }
            else printf("정보 없음.\n");
        }
    }
    return 0;
}
int borrowbook(BOOK* booklist) {
    /* 사용자로 부터 책번호를 받을 변수*/
    int n;

    printf("빌릴 책의 번호를 말해주세요 \n");
    printf("책 번호 : ");
    scanf_s("%d", &n);

    if (booklist[n].borrowed == 1) {
        printf("이미 대출된 책입니다. \n");
    }
    else {
        printf("책이 대출되었습니다. \n");
        booklist[n].borrowed = 1;
    }

    return 0;
}
int returnbook(BOOK* booklist) {
    /* 반납할 책의 번호 */
    int m;

    printf("반납할 책의 번호를 써주세요 \n");
    printf("책 번호 : ");
    scanf_s("%d", &m);

    if (booklist[m].borrowed == 0) {
        printf("이미 반납되어 있는 상태입니다.\n");
    }
    else {
        booklist[m].borrowed = 0;
        printf("성공적으로 반납되었습니다.\n");
    }

    return 0;
}
