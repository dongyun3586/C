#include<stdio.h>

void printStudentInfo(void** info, int n);

int main() {
	char* nameA = "홍길동";
	char* nameB = "고길동";
	char* subjectA[] = { "객체지향프로그래밍", "머신러닝과딥러닝", "서버프로그래밍" };
	char* subjectB[] = { "고전역학", "선형대수", "전자기학", "미적분학" };
	int scoreA[] = { 70, 85, 90 };
	int scoreB[] = { 77, 88, 66, 99 };
	int numSubjectA = sizeof(subjectA) / sizeof(char*);
	int numSubjectB = sizeof(subjectB) / sizeof(char*);

	// ① 변수 선언 및 초기화 [4점]
	void* studentA[] = { nameA, subjectA, scoreA };
	void* studentB[] = { nameB, subjectB, scoreB };

	printStudentInfo(studentA, numSubjectA);
	printStudentInfo(studentB, numSubjectB);

	return 0;
}

void printStudentInfo(void** info, int n) {
	// ② 이름 출력 [2점]
	printf("<%s>\n", (char*)*info);

	// ③ printArray( ) 과목명과 점수 출력 [6점]
	for (int i = 0; i < n; i++) {
		printf("%s : ", *((char**)*(info + 1) + i));
		printf("%d\n", *((int*)*(info + 2) + i));
	}

	int sum = 0;
	float avg = 0;

	// ④ 총점과 평균 구하기 [4점]
	for (int i = 0; i < n; i++)
		sum += *((int*)*(info + 2) + i);
	avg = (float)sum / n;

	printf("총점: %d, 평균: %.2f\n\n", sum, avg);
}