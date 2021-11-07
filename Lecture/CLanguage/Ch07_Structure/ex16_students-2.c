#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXNAME 64      // �̸��� �ִ� ����
int heapUsage = 0;      // �� �޸� ��뷮 ���� ����

typedef struct {
    int age;
    float score;
    char* name;         // char name[MAXNAME];
} student;

int setStudent(student* _dst) {
    _dst->age = rand() % 10;
    _dst->score = rand() % 100;

    int nameLen = rand() % MAXNAME;
    _dst->name = (char*)calloc(nameLen, sizeof(char));  // �̸��� ������ �޸� �Ҵ�
    heapUsage += sizeof(char) * nameLen;                // �Ҵ�� �޸� ũ�� ����
    for (int i = 0; i < nameLen; i++)
        _dst->name[i] = 'a' + rand() % 26;
}

int main() {
    int numStudent = 0;
    printf("How many students? ");
    scanf("%d", &numStudent);

    // numStudent ���� ��ŭ�� student ������ �޸� �Ҵ�
    student* students = (student*)malloc(sizeof(student) * numStudent);
    memset(students, 0, sizeof(student) * numStudent);  // 0 ���� �ʱ�ȭ
    heapUsage += sizeof(student) * numStudent;          // �Ҵ�� �޸� ũ�� ����

    // numStudent ���� ��ŭ ������ �л����� ����
    for (int i = 0; i < numStudent; i++)
        setStudent(&students[i]);

    // ��� ��� �� ���
    float avg = 0;
    for (int i = 0; i < numStudent; i++)
        avg += students[i].score;
    avg /= numStudent;
    printf("Average score = %.2f\n", avg);

    // release name for each student
    for (int i = 0; i < numStudent; i++)
        if (students->name) {
            free(students->name);
            students->name = NULL;
        }

    // release students
    if (students) {
        free(students);
        students = NULL;
    }

    printf("heap memory usage = %d bytes\n", heapUsage);

    return 0;
}