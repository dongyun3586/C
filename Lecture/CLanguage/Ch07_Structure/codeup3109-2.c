#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char c;
    int no;
    char name[30];
} Student;

void insertStudent(Student* arr, Student* temp, int* s_count) {
    int flag = 1;
    for (int i = 0; i < *s_count; i++) {
        // 번호 순서대로 삽입
        if (temp->no <= arr[i].no) {
            for (int j = *s_count - 1; j >= i; j--)
                arr[j + 1] = arr[j];
            arr[i] = *temp;
            flag = 0;
            break;
        }
    }
    if (flag == 1) arr[*s_count] = *temp;
    (*s_count)++;
}

void deleteStudent(Student* arr, Student* temp, int* s_count) {
    for (int i = 0; i < *s_count; i++) {
        if (temp->no == arr[i].no) {
            for (int j = i + 1; j < *s_count; j++)
                arr[j - 1] = arr[j];
            (*s_count)--;
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    getchar();

    Student temp;
    Student* students = (Student*)calloc(n, sizeof(Student));

    int s_count = 0;
    for (int i = 0; i < n; i++) {
        scanf("%c %d %s", &temp.c, &temp.no, temp.name);
        getchar();

        // 처리 코드가 'I'이면 데이터를 수험 번호 순서에 맞게 삽입
        // 만약 입력할 때 이미 수험 번호가 입력되어 있다면 같은 수험 번호의 맨 앞에 삽입한다.
        if (temp.c == 'I') {
            insertStudent(students, &temp, &s_count);
        }
        // 처리 코드가 ‘D’이면 메모리의 해당 수험 번호의 데이터 중에서 가장 앞쪽 데이터를 찾아 삭제한다.
        // 만약 처리 코드가 'D'이고 해당 수험 번호가 존재하지 않으면 아무 작업도 하지 않는다.
        if (temp.c == 'D') {
            deleteStudent(students, &temp, &s_count);
        }
    }

    int index[5] = { 0 };
    for (int i = 0; i < 5; i++)
        scanf("%d", &index[i]);

    for (int i = 0; i < 5; i++) {
        printf("%d %s\n", students[index[i] - 1].no, students[index[i] - 1].name);
    }

    return 0;
}