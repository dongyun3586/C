#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 1024
#define MAX_NAME 20     // 이름의 최대 크기

typedef struct {
    int age;
    float score;
    char name[MAX_NAME];
} Student;

int setStudent(Student* s) {
    s->age = rand() % 10 + 10;  // 10 ~ 19
    s->score = rand() % 101;    // 0 ~ 100

    int nameLen = rand() % (MAX_NAME - 1) + 1;    // 1 ~ 15
    int i;
    for (i = 0; i < nameLen; i++) {
        s->name[i] = 'a' + rand() % 26;
    }
    s->name[i] = '\0';
    printf("%d %.2f %s\n", s->age, s->score, s->name);
}

int main() {
    int n = 0;
    Student Students[N] = { 0 };
    printf("size of Students array = %d bytes\n", sizeof(Student) * N);

    printf("How many Students? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        setStudent(&Students[i]);

    float avg = 0;
    for (int i = 0; i < n; i++)
        avg += Students[i].score;
    avg /= n;

    printf("\nAverage score = %.2f\n", avg);

    return 0;
}