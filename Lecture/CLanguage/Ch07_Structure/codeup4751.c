#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
	int c_code;
	int s_code;
	int score;
} Student;

int compareScore(const void* a, const void* b)    // �������� �� �Լ� ����
{
	Student s1 = *(Student*)a;    // void �����͸� int �����ͷ� ��ȯ�� �� �������Ͽ� ���� ������
	Student s2 = *(Student*)b;    // void �����͸� int �����ͷ� ��ȯ�� �� �������Ͽ� ���� ������

	if (s1.score > s2.score)    // a�� b���� ���� ����
		return -1;      // -1 ��ȯ

	if (s1.score < s2.score)    // a�� b���� Ŭ ����
		return 1;       // 1 ��ȯ

	return 0;    // a�� b�� ���� ���� 0 ��ȯ
}

void printArr(Student* students, int n) {
	for (int i = 0; i < n; i++)
		printf("%d %d %d\n", students[i].c_code, students[i].s_code, students[i].score);
}

int checkCountry(Student* s, Student* winner) {
	int count = 0;
	for (int i = 0; i < 3; i++)
		if (s->c_code == winner[i].c_code)
			count++;
	if (count > 1)return 0;
	else return 1;
}

int main() {
	int n;

	// 1) ù ��° �ٿ��� ��ȸ���� �л� ���� ��Ÿ���� N �� �־�����. ��, 3<=N<=100 
	scanf("%d", &n);
	Student* students = (Student*)malloc(sizeof(Student) * n);

	// 2) �� ��° �ٺ��� N ���� �ٿ��� �� �ٸ��� �� �л��� �Ҽ� ���� ��ȣ, �л� ��ȣ, �׸��� ������ �ϳ��� ��ĭ�� ���̿� �ΰ� �־�����
	for (int i = 0; i < n; i++)
		scanf("%d %d %d", &students[i].c_code, &students[i].s_code, &students[i].score);

	//printArr(students, n);

	// �������� ����
	qsort(students, n, sizeof(Student), compareScore);
	//printArr(students, n);

	Student winner[3] = { 0 };

	int index = 0;
	for (int i = 0; i < n; i++) {
		if (checkCountry(&students[i], winner)) {
			winner[index++] = students[i];
		}
		if (index == 3)break;
	}

	for (int i = 0; i < 3; i++)
		printf("%d %d\n", winner[i].c_code, winner[i].s_code);
	return 0;
}