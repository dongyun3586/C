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
    int a; /* ������ ������ �޴� */
    int total = 0; /* ���� å�� �� */

    BOOK* booklist;

    printf("�������� �ִ� ���� �弭 ���� �������ּ��� : ");
    scanf_s("%d", &a);

    booklist = (BOOK*)malloc(sizeof(BOOK) * a);

    while (1) {
        printf("���� ���� ���α׷� \n");
        printf("�޴��� �����ϼ��� \n");
        printf("1. å�� ���� �߰��ϱ� \n");
        printf("2. å�� �˻��ϱ� \n");
        printf("3. å�� ������ \n");
        printf("4. å�� �ݳ��ϱ� \n");
        printf("5. ���α׷� ���� \n");

        printf("����� ������ : ");
        scanf_s("%d", &a);

        if (a == 1) {
            /* å�� ���� �߰��ϴ� �Լ� ȣ�� */
            addbook(booklist, &total);
        }
        else if (a == 2) {
            /* å�� �˻��ϴ� �Լ� ȣ�� */
            searchbook(booklist, total);
        }
        else if (a == 3) {
            /* å�� ������ �Լ� ȣ�� */
            borrowbook(booklist);
        }
        else if (a == 4) {
            /* å�� �ݳ��ϴ� �Լ� ȣ�� */
            returnbook(booklist);
        }
        else {
            printf("�̿����ּż� �����մϴ�.");
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
    printf("å ���� : ");
    scanf_s("%s", booklist[*num].title, sizeof(booklist[*num].title));

    printf("���� : ");
    scanf_s("%s", booklist[*num].author, sizeof(booklist[*num].author));

    printf("���ǻ� : ");
    scanf_s("%s", booklist[*num].publisher, sizeof(booklist[*num].publisher));

    booklist[*num].borrowed = 0;
    (*num)++;

    return 0;
}

int searchbook(BOOK* booklist, int total) {
    int b; /* ������� �Է��� �޴´�. */
    int i;

    char search[30];
    printf("��� ������ �˻� �� ���ΰ���? \n");
    printf("1. å ���� �˻� \n");
    printf("2. ���� �˻� \n");
    printf("3. ���ǻ� �˻� \n");
    scanf_s("%d", &b);

    printf("�˻��� �ܾ �Է����ּ��� : ");
    scanf_s("%s", search, sizeof(search));
    printf("�˻� ��� \n");

    if (b == 1) {
        for (i = 0; i < total; i++) {
            if (searchword(booklist[i].title, search) >= 0) {
                printf("��ȣ : %d // å ���� : %s // ���� : %s // ���ǻ� : %s \n", i, booklist[i].title, booklist[i].author, booklist[i].publisher);
            }
            else printf("���� ����.\n");
        }
    }
    else if (b == 2) {
        for (i = 0; i < total; i++) {
            if (searchword(booklist[i].author, search) >= 0) {
                printf("��ȣ : %d // å ���� : %s // ���� : %s // ���ǻ� : %s \n", i, booklist[i].title, booklist[i].author, booklist[i].publisher);
            }
            else printf("���� ����.\n");
        }
    }
    else if (b == 3) {
        for (i = 0; i < total; i++) {
            if (searchword(booklist[i].publisher, search) >= 0) {
                printf("��ȣ : %d // å ���� : %s // ���� : %s // ���ǻ� : %s \n", i, booklist[i].title, booklist[i].author, booklist[i].publisher);
            }
            else printf("���� ����.\n");
        }
    }
    return 0;
}
int borrowbook(BOOK* booklist) {
    /* ����ڷ� ���� å��ȣ�� ���� ����*/
    int n;

    printf("���� å�� ��ȣ�� �����ּ��� \n");
    printf("å ��ȣ : ");
    scanf_s("%d", &n);

    if (booklist[n].borrowed == 1) {
        printf("�̹� ����� å�Դϴ�. \n");
    }
    else {
        printf("å�� ����Ǿ����ϴ�. \n");
        booklist[n].borrowed = 1;
    }

    return 0;
}
int returnbook(BOOK* booklist) {
    /* �ݳ��� å�� ��ȣ */
    int m;

    printf("�ݳ��� å�� ��ȣ�� ���ּ��� \n");
    printf("å ��ȣ : ");
    scanf_s("%d", &m);

    if (booklist[m].borrowed == 0) {
        printf("�̹� �ݳ��Ǿ� �ִ� �����Դϴ�.\n");
    }
    else {
        booklist[m].borrowed = 0;
        printf("���������� �ݳ��Ǿ����ϴ�.\n");
    }

    return 0;
}
