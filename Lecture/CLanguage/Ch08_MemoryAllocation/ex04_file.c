#include<stdio.h>

typedef struct {
	int id;
	char name[10];
	float score;
} Student;


int fileOpen(FILE** fp, char* fileName, char* mode);

int main() {
	Student s = { 0 };
	char* fileName = "studentList.txt";
	FILE* fp = NULL;

	// append ���� ���� ����
	if (fileOpen(&fp, fileName, "a") == 0) exit(1);

	// �л� ���� �Է� �޾� ���Ͽ� ����
	while (1) {
		printf("�л� ���� �Է�(id name score)(����=-1): ");
		scanf("%d", &s.id);
		if (s.id < 0) break;				// -1�� �ԷµǸ� ����

		scanf("%s %f", &s.name, &s.score);
		getchar();							// ���ۿ��� '\n' ���� ����

		// ���Ͽ� Ư�� ������������ ����
		fprintf(fp, "%d %s %.1f\n", s.id, s.name, s.score);
	}

	fclose(fp);

	// read ���� ���� ����
	if (fileOpen(&fp, fileName, "r") == 0)exit(1);

	int n = 0;
	float sum = 0;

	// �л� ���� �а�, ��� ���
	while (!feof(fp)) {		// feof(fp) => ���� ���̸� true, �ƴϸ� flase
		fscanf(fp, "%d %s %f\n", &s.id, &s.name, &s.score);
		sum += s.score;
		n++;
	}

	printf("�л� �� : %d��, ��� ���� : %.2f\n", n, sum / n);

	fclose(fp);

	return 0;
}

int fileOpen(FILE** fp, char* fileName, char* mode) {
	*fp = fopen(fileName, mode);
	if (!*fp) {
		printf("Fail to open - %s\n", fileName);
		return 0;
	}
	return 1;
}