#include<stdio.h>
#include<stdlib.h>

typedef struct {
	char name[12];
	int score;
} Student;

int compareStudent(const void* a, const void* b)    // �������� �� �Լ� ����
{
	Student s1 = *(Student*)a;    // void �����͸� int �����ͷ� ��ȯ�� �� �������Ͽ� ���� ������
	Student s2 = *(Student*)b;    // void �����͸� int �����ͷ� ��ȯ�� �� �������Ͽ� ���� ������

	if (s1.score > s2.score)    // a�� b���� ���� ����
		return -1;      // -1 ��ȯ

	if (s1.score < s2.score)    // a�� b���� Ŭ ����
		return 1;       // 1 ��ȯ

	return 0;    // a�� b�� ���� ���� 0 ��ȯ
}

void printStudents(Student* students, int n) {
	for (int i = 0; i < n; i++) {
		printf("%s %d\n", students[i].name, students[i].score);
	}
}

int main() {
	int n, m;

	// ù° �ٿ� �������� ���� n (3<=n<=100)�� ����ο� m (1<=m<=n)�� �������� ���еǾ� �Է�
	scanf("%d %d", &n, &m);

	// ��° �ٺ��� �л� �̸��� ����(0 100)�� �������� ���еǾ� �Էµȴ�. 
	Student* students = (Student*)malloc(sizeof(Student) * n);
	int* scores = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		scanf("%s", &students[i].name);
		scanf("%d", &students[i].score);
	}

	//printStudents(students, n);
	qsort(students, n, sizeof(Student), compareStudent);
	//printStudents(students, n);

	for (int i = 0; i < m; i++)
		printf("%s\n", students[i].name);

	return 0;
}