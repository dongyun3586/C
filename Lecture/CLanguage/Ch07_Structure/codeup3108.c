#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
	char code;
	int no;
	char name[12];
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

// ������ �Էµ� �ڷῡ ������ �����ȣ�� �����ϴ��� �˻�
int checkNo(Student* students, int no, int n) {
	for (int i = 0; i < n; i++)
		if (no == students[i].no)
			return 0;
	return 1;
}

int deleteStudent(Student* students, int no, int n) {
	for (int i = 0; i < n; i++)
		if (no == students[i].no) {
			// �迭�� ��� ����
			for (int j = i; j < n; j++)
				students[j] = students[j + 1];
			return 1;
		}
	return 0;
}

int main() {
	int n;
	Student temp;
	int printPosition[5];

	// ù° �ٿ� �Է� �������� ���� n�� �Էµȴ�. (10<=n<=100)
	scanf("%d", &n);
	//rewind(stdin);
	getchar();

	Student* students = (Student*)malloc(sizeof(Student) * n);

	// ��° �ٺ��� n+1��° �ٱ��� ó�� �ڵ�c(���� 1�ڸ�), ���� ��ȣ no(1<=no<=10,000), �̸�(10����Ʈ �̳�)�� �Է�
	int index = 0;
	for (int i = 0; i < n; i++) {
		scanf("%c %d %s", &temp.code, &temp.no, temp.name);
		getchar();	//rewind(stdin);

		// code�� 'I' �̰�, ������ �Էµ� �ڷῡ ������ �����ȣ�� ������ �߰�
		if (temp.code == 'I' && checkNo(students, temp.no, i + 1) == 1) {
			students[index] = temp;
			index++;
		}
		else if (temp.code == 'D') {	// ó�� �ڵ尡 ��D���̸� �޸��� ������ �߿��� �ش� ���� ��ȣ�� ã�� �����Ѵ�.
			if (deleteStudent(students, temp.no, index)) {
				index--;
			}
		}
	}
	for (int i = 0; i < 5; i++)
		scanf("%d", &printPosition[i]);

	//printStudents(students, n);
	qsort(students, index, sizeof(Student), compareStudents);
	//printStudents(students, index);

	for (int i = 0; i < 5; i++)
		printf("%d %s\n", students[printPosition[i] - 1].no, students[printPosition[i] - 1].name);

	return 0;
}