#include<stdio.h>
#define NUM_STUDENT 5
#define MAX_NUM_STUDENT 5

typedef struct {
	int id;
	char name[10];
	float score;
} Student;

int fileOpen(FILE** fp, char* fileName, char* mode) {
	*fp = fopen(fileName, mode);
	if (!*fp) {
		printf("Fail to open - %s\n", fileName);
		return 0;
	}
	return 1;
}

int main() {
#pragma region 1. 바이너리 파일 쓰기
	char* fileName = "studentList.bin";
	FILE* fp = NULL;

	// Write data
	Student s[NUM_STUDENT] = {
		{1101, "Kim", 50.1}, {1102, "Lee", 60.2}, {1103, "Park", 70.3},
		{1104, "Hong", 80.4}, {1105, "Jang", 90.5}
	};

	// append 모드로 파일 열기
	if (fileOpen(&fp, fileName, "ab") == 0) exit(1);

	fwrite(s, sizeof(Student), NUM_STUDENT, fp);

	fclose(fp);
#pragma endregion

#pragma region 2. 바이너리 파일 읽기
	if (fileOpen(&fp, fileName, "rb") == 0)exit(1);

	Student buf[MAX_NUM_STUDENT] = { 0 };
	float sum = 0;
	int n = fread(buf, sizeof(Student), MAX_NUM_STUDENT, fp);

	for (int i = 0; i < n; i++)
		sum += buf[i].score;

	for (int i = 0; i < n; i++)
		printf("%d %s %.1f\n", buf[i].id, buf[i].name, buf[i].score);
	printf("%d students, Average = %.2f\n", n, sum / n);

	fclose(fp);
#pragma endregion

	return 0;
}