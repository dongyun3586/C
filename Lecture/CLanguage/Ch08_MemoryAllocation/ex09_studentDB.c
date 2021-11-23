#include<stdio.h>

#define MAX_NUM_STUDENT 100

enum action { ADD, FIND, EXIT };

typedef struct {
	int id;
	char name[10];
	float score;
} Student;

int fileOpen(FILE** fp, char* fileName, char* mode);
int selectAction();
int printStudentInfo(Student* s);
int addStudentInfo(FILE* fp, Student* s);
long findStudent(FILE* fp, Student* s);

int main() {
	FILE* fp = NULL;
	Student data = { 0 };
	fileOpen(&fp, "StudentDB", "ab+");

	// 학생 정보 입력 받아 파일에 저장
	while (1) {
		switch (selectAction()) {
		case ADD:
			addStudentInfo(fp, &data);
			break;
		case FIND:
			if (findStudent(fp, &data) < 0)
				printf("Cannot find the student\n");
			else
				printStudentInfo(&data);
			break;
		case EXIT:
			exit(0);
		}
	}

	fclose(fp);
	return 0;
}

int fileOpen(FILE** fp, char* fileName, char* mode) {
	*fp = fopen(fileName, mode);
	if (!*fp) {
		printf("Fail to open - %s\n", fileName);
		return -1;
	}
	return 1;
}

int selectAction() {
	int choice = 0;
	printf("[%d]add [%d]find [%d]exit: ", ADD, FIND, EXIT);
	scanf("%d", &choice);
	return choice;
}

int printStudentInfo(Student* s) {
	printf("%d %s %.2f\n", s->id, s->name, s->score);
}

int addStudentInfo(FILE* fp, Student* s) {
	printf("Enter(id name score) : ");
	scanf("%d %s %f", &s->id, &s->name, &s->score);
	getchar();

	fseek(fp, 0, SEEK_END);
	fwrite(s, sizeof(Student), 1, fp);

	return 0;
}

long findStudent(FILE* fp, Student* s) {
	char name[255] = { 0 };
	printf("Name: ");
	scanf("%s", name); getchar();

	int elementSize = sizeof(Student);
	fseek(fp, 0, SEEK_SET);

	while (!feof(fp)) {
		fread(s, elementSize, 1, fp);
		if (strcmp(s->name, name) == 0) {	// Find
			fseek(fp, -elementSize, SEEK_CUR);
			return ftell(fp);
		}
	}
	return -1;
}