#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
	char code;
	int no;
	char name[20];
} Student;

int compareStudents(const void* a, const void* b)    // �������� �� �Լ� ����
{
	Student s1 = *(Student*)a;    // void �����͸� int �����ͷ� ��ȯ�� �� �������Ͽ� ���� ������
	Student s2 = *(Student*)b;    // void �����͸� int �����ͷ� ��ȯ�� �� �������Ͽ� ���� ������

	if (s1.no < s2.no)
		return -1;

	if (s1.no > s2.no)
		return 1;

	return 0;
}

void printStudents(Student* students, int n) {
	printf("\n");
	for (int i = 0; i < n; i++) {
		printf("%c %d %s\n", students[i].code, students[i].no, students[i].name);
	}
	printf("\n");
}

int checkNo(Student* students, Student* new, int n) {
	for (int i = 0; i < n; i++) {
		if (new->no == students[i].no) {
			for (int j = n - 1; j >= i; j--)
				students[j + 1] = students[j];
			students[i] = *new;
			return 0;
		}
	}
	return 1;
}

int deleteStudent(Student* students, int no, int n) {
	for (int i = 0; i < n; i++)
		if (no == students[i].no) {
			// �迭�� ��� ����
			for (int j = i; j < n - 1; j++)
				students[j] = students[j + 1];
			return 1;
		}
	return 0;
}

int main() {
	int n;
	Student temp;
	int rightPosition[5] = { 0 };

	// ù° �ٿ� �Է� �������� ���� n�� �Էµȴ�. (10<=n<=20,000)
	scanf("%d", &n);
	getchar();

	// ��° �ٺ��� n+1��° �ٱ��� ó�� �ڵ�c(���� 1�ڸ�), ���� ��ȣ no(1<=no<=1,000,000,000), �̸�(10����Ʈ �̳�)�� �Էµȴ�.
	Student* students = (Student*)malloc(sizeof(Student) * n);

	int index = 0;
	for (int i = 0; i < n; i++) {
		scanf("%c %d %s", &temp.code, &temp.no, temp.name);
		getchar();

		// code�� 'I' �̰�, ������ �Էµ� �ڷῡ ������ �����ȣ�� ������ �߰�
		if (temp.code == 'I') {
			// ���� �����ȣ �� �տ� ����
			if (checkNo(students, &temp, index)) {
				students[index] = temp;
			}
			index++;
		}
		else if (temp.code == 'D') {	// ó�� �ڵ尡 ��D���̸� �޸��� ������ �߿��� �ش� ���� ��ȣ�� ã�� �����Ѵ�.
			if (deleteStudent(students, temp.no, index)) {
				index--;
			}
		}
	}
	for (int i = 0; i < 5; i++)
		scanf("%d", &rightPosition[i]);

	//printStudents(students, index);
	qsort(students, index, sizeof(Student), compareStudents);
	//printStudents(students, index);

	for (int i = 0; i < 5; i++)
		printf("%d %s\n", students[rightPosition[i] - 1].no, students[rightPosition[i] - 1].name);

	return 0;
}
