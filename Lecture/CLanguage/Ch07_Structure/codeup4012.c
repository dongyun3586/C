#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
	int no;
	int score;
	int order;
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

int compareStudent2(const void* a, const void* b)    // �������� �� �Լ� ����
{
	Student s1 = *(Student*)a;    // void �����͸� int �����ͷ� ��ȯ�� �� �������Ͽ� ���� ������
	Student s2 = *(Student*)b;    // void �����͸� int �����ͷ� ��ȯ�� �� �������Ͽ� ���� ������

	if (s1.no < s2.no)    // a�� b���� ���� ����
		return -1;      // -1 ��ȯ

	if (s1.no > s2.no)    // a�� b���� Ŭ ����
		return 1;       // 1 ��ȯ

	return 0;    // a�� b�� ���� ���� 0 ��ȯ
}

void printArr(Student* students, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d %d\n", students[i].score, students[i].order);
		//printf("%d %d %d\n", students[i].no, students[i].score, students[i].order);
	}
}

int main() {
	int n;

	// 1) ù ��° ���� ó���� ������ ���� n ( n <= 200 )
	scanf("%d", &n);

	Student* students = (Student*)malloc(sizeof(Student) * n);

	// 2) �� ��° ���� ó���� ���� ������ (0~100��)
	for (int i = 0; i < n; i++) {
		students[i].no = i;
		scanf("%d", &students[i].score);
	}

	//printArr(students, n);
	// �������� ����
	qsort(students, n, sizeof(Student), compareStudent);

	students[0].order = 1;
	for (int i = 1; i < n; i++) {
		if (students[i - 1].score == students[i].score)
			students[i].order = students[i - 1].order;
		else
			students[i].order = i + 1;
	}

	// ���� ������� �ǵ�����
	qsort(students, n, sizeof(Student), compareStudent2);

	printArr(students, n);

	return 0;
}