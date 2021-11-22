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
        // ��ȣ ������� ����
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

        // ó�� �ڵ尡 'I'�̸� �����͸� ���� ��ȣ ������ �°� ����
        // ���� �Է��� �� �̹� ���� ��ȣ�� �ԷµǾ� �ִٸ� ���� ���� ��ȣ�� �� �տ� �����Ѵ�.
        if (temp.c == 'I') {
            insertStudent(students, &temp, &s_count);
        }
        // ó�� �ڵ尡 ��D���̸� �޸��� �ش� ���� ��ȣ�� ������ �߿��� ���� ���� �����͸� ã�� �����Ѵ�.
        // ���� ó�� �ڵ尡 'D'�̰� �ش� ���� ��ȣ�� �������� ������ �ƹ� �۾��� ���� �ʴ´�.
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