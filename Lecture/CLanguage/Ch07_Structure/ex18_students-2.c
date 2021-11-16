#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 20      // �̸��� �ִ� ����
int usedMemory = 0;      // �� �޸� ��뷮 ���� ����

typedef struct {
    int age;
    int score;
    char* name;
} Student;

int setStudent(Student* s);

int main() {
    int n = 0;
    printf("How many students? ");
    scanf("%d", &n);

    Student* students = malloc(sizeof(Student) * n);
    memset(students, 0, sizeof(Student) * n);
    usedMemory += sizeof(Student) * n;          // �Ҵ�� �޸� ũ�� ����

    // ���� �л� ���� ���� �� ���
    for (int i = 0; i < n; i++)
        setStudent(&students[i]);   // students+i

    // ��� ��� �� ���
    float avg = 0;
    for (int i = 0; i < n; i++)
        avg += students[i].score;
    avg /= n;
    printf("Average score = %.2f\n", avg);

    // release name for each Student
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

int setStudent(Student* s) {
    s->age = rand() % 10 + 10;  // 10 ~ 19
    s->score = rand() % 101;    // 0 ~ 100
    int nameLen = rand() % (MAX_NAME - 1) + 1;    // 1 ~ 19

    // 4. �̸��� ������ �޸� �Ҵ�
    s->name = calloc(nameLen + 1, sizeof(char));    // 2 ~ 20 byte��ŭ 0���� �ʱ�ȭ�� �޸� �Ҵ�
    usedMemory += sizeof(char) * nameLen;           // �Ҵ�� �޸� ũ�� ����

    int i;
    for (i = 0; i < nameLen; i++)           // 1 ~ 19 
        s->name[i] = 'a' + rand() % 26;     // ������ ���ĺ� ����
    s->name[i] = '\0';                      // �������� �ι��� �߰�
    printf("%d %2d %s\n", s->age, s->score, s->name);
}