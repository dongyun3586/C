#include<stdio.h>
#include<stdlib.h>

typedef struct {
	char name[12];
	int A, B, C;
} Student;

int compareStudent(const void* a, const void* b)    // �������� �� �Լ� ����
{
	Student s1 = *(Student*)a;    // void �����͸� int �����ͷ� ��ȯ�� �� �������Ͽ� ���� ������
	Student s2 = *(Student*)b;    // void �����͸� int �����ͷ� ��ȯ�� �� �������Ͽ� ���� ������

	if (s1.A > s2.A)    // a�� b���� ���� ����
		return -1;      // -1 ��ȯ

	if (s1.A < s2.A)    // a�� b���� Ŭ ����
		return 1;       // 1 ��ȯ

	return 0;    // a�� b�� ���� ���� 0 ��ȯ
}

void printStudents(Student* students, int n) {
	for (int i = 0; i < n; i++) {
		printf("%s %d %d %d\n", students[i].name, students[i].A, students[i].B, students[i].C);
	}
}

int main() {
	int n;

	// ù° �ٿ� �������� ���� n (3<=n<=100)
	scanf("%d", &n);

	// ��° �ٺ��� n+1�ٿ� �л� �̸��� 3���� �������� �������� ���еǾ� �Էµȴ�. (�Է� ���� ����)
	Student* students = (Student*)malloc(sizeof(Student) * n);
	int* scores = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		scanf("%s", &students[i].name);
		scanf("%d", &students[i].A);
		scanf("%d", &students[i].B);
		scanf("%d", &students[i].C);
	}

	//printStudents(students, n);
	qsort(students, n, sizeof(Student), compareStudent);
	//printStudents(students, n);

	int rankB = 1;
	int rankC = 1;
	for (int i = 1; i < n; i++) {
		if (students[0].B < students[i].B)	rankB++;
		if (students[0].C < students[i].C)	rankC++;
	}

	printf("%s %d %d", students[0].name, rankB, rankC);


	return 0;
}