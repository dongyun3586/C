#include<stdio.h>

void printStudentInfo(void** info, int n);

int main() {
	char* nameA = "ȫ�浿";
	char* nameB = "��浿";
	char* subjectA[] = { "��ü�������α׷���", "�ӽŷ��װ�������", "�������α׷���" };
	char* subjectB[] = { "��������", "�������", "���ڱ���", "��������" };
	int scoreA[] = { 70, 85, 90 };
	int scoreB[] = { 77, 88, 66, 99 };
	int numSubjectA = sizeof(subjectA) / sizeof(char*);
	int numSubjectB = sizeof(subjectB) / sizeof(char*);

	// �� ���� ���� �� �ʱ�ȭ [4��]
	void* studentA[] = { nameA, subjectA, scoreA };
	void* studentB[] = { nameB, subjectB, scoreB };

	printStudentInfo(studentA, numSubjectA);
	printStudentInfo(studentB, numSubjectB);

	return 0;
}

void printStudentInfo(void** info, int n) {
	// �� �̸� ��� [2��]
	printf("<%s>\n", (char*)*info);

	// �� printArray( ) ������ ���� ��� [6��]
	for (int i = 0; i < n; i++) {
		printf("%s : ", *((char**)*(info + 1) + i));
		printf("%d\n", *((int*)*(info + 2) + i));
	}

	int sum = 0;
	float avg = 0;

	// �� ������ ��� ���ϱ� [4��]
	for (int i = 0; i < n; i++)
		sum += *((int*)*(info + 2) + i);
	avg = (float)sum / n;

	printf("����: %d, ���: %.2f\n\n", sum, avg);
}