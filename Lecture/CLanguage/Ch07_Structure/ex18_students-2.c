#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXNAME 64      // 이름의 최대 길이
int usedMemory = 0;      // 힙 메모리 사용량 저장 변수

typedef struct {
    int age;
    float score;
    char* name;         // char name[MAXNAME];
} student;

int setStudent(student* s) {
    s->age = rand() % 10;
    s->score = rand() % 100;

    int nameLen = rand() % MAXNAME;
    s->name = (char*)calloc(nameLen, sizeof(char));  // 이름을 저장할 메모리 할당
    usedMemory += sizeof(char) * nameLen;                // 할당된 메모리 크기 누계
    for (int i = 0; i < nameLen; i++)
        s->name[i] = 'a' + rand() % 26;
}

int main() {
    int n = 0;
    printf("How many students? ");
    scanf("%d", &n);

    // n 개수 만큼의 student 사이즈 메모리 할당
    student* students = (student*)malloc(sizeof(student) * n);
    memset(students, 0, sizeof(student) * n);  // 0 으로 초기화
    usedMemory += sizeof(student) * n;          // 할당된 메모리 크기 누계

    // n 개수 만큼 랜덤한 학생정보 저장
    for (int i = 0; i < n; i++)
        setStudent(&students[i]);

    // 평균 계산 및 출력
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