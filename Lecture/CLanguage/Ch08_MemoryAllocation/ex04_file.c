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

	// append 모드로 파일 열기
	if (fileOpen(&fp, fileName, "a") == 0) exit(1);

	// 학생 정보 입력 받아 파일에 저장
	while (1) {
		printf("학생 정보 입력(id name score)(종료=-1): ");
		scanf("%d", &s.id);
		if (s.id < 0) break;				// -1이 입력되면 종료

		scanf("%s %f", &s.name, &s.score);
		getchar();							// 버퍼에서 '\n' 문자 제거

		// 파일에 특정 포맷형식으로 쓰기
		fprintf(fp, "%d %s %.1f\n", s.id, s.name, s.score);
	}

	fclose(fp);

	// read 모드로 파일 열기
	if (fileOpen(&fp, fileName, "r") == 0)exit(1);

	int n = 0;
	float sum = 0;

	// 학생 정보 읽고, 평균 계산
	while (!feof(fp)) {		// feof(fp) => 파일 끝이면 true, 아니면 flase
		fscanf(fp, "%d %s %f\n", &s.id, &s.name, &s.score);
		sum += s.score;
		n++;
	}

	printf("학생 수 : %d명, 평균 점수 : %.2f\n", n, sum / n);

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