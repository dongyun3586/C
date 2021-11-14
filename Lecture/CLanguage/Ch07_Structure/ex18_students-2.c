#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXNAME 64      // �̸��� �ִ� ����
int usedMemory = 0;      // �� �޸� ��뷮 ���� ����

typedef struct {
    int age;
    float score;
    char* name;         // char name[MAXNAME];
} student;

int setStudent(student* s) {
    s->age = rand() % 10;
    s->score = rand() % 100;

    int nameLen = rand() % MAXNAME;
    s->name = (char*)calloc(nameLen, sizeof(char));  // �̸��� ������ �޸� �Ҵ�
    usedMemory += sizeof(char) * nameLen;                // �Ҵ�� �޸� ũ�� ����
    for (int i = 0; i < nameLen; i++)
        s->name[i] = 'a' + rand() % 26;
}

int main() {
    int n = 0;
    printf("How many students? ");
    scanf("%d", &n);

    // n ���� ��ŭ�� student ������ �޸� �Ҵ�
    student* students = (student*)malloc(sizeof(student) * n);
    memset(students, 0, sizeof(student) * n);  // 0 ���� �ʱ�ȭ
    usedMemory += sizeof(student) * n;          // �Ҵ�� �޸� ũ�� ����

    // n ���� ��ŭ ������ �л����� ����
    for (int i = 0; i < n; i++)
        setStudent(&students[i]);

    // ��� ��� �� ���
    float avg = 0;
    for (int i = 0; i < n; i++)
        avg += students[i].score;
    avg /= n;
    printf("Average score = %.2f\n", avg);

    // release name for each student
    for (int i = 0; i < n; i++)
        if (students->name) {
            free(students->name);
            students->name = NULL;
        }

    // release students
    if (students) {
        free(students);
        students = NULL;
    }

    printf("heap memory usage = %d bytes\n", usedMemory);

    return 0;
}