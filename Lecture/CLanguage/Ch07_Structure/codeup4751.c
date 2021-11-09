#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
	int c_code;
	int s_code;
	int score;
} Student;

int compareScore(const void* a, const void* b)    // 오름차순 비교 함수 구현
{
	Student s1 = *(Student*)a;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴
	Student s2 = *(Student*)b;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴

	if (s1.score > s2.score)    // a가 b보다 작을 때는
		return -1;      // -1 반환

	if (s1.score < s2.score)    // a가 b보다 클 때는
		return 1;       // 1 반환

	return 0;    // a와 b가 같을 때는 0 반환
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

	// 1) 첫 번째 줄에는 대회참가 학생 수를 나타내는 N 이 주어진다. 단, 3<=N<=100 
	scanf("%d", &n);
	Student* students = (Student*)malloc(sizeof(Student) * n);

	// 2) 두 번째 줄부터 N 개의 줄에는 각 줄마다 한 학생의 소속 국가 번호, 학생 번호, 그리고 성적이 하나의 빈칸을 사이에 두고 주어진다
	for (int i = 0; i < n; i++)
		scanf("%d %d %d", &students[i].c_code, &students[i].s_code, &students[i].score);

	//printArr(students, n);

	// 성적으로 정렬
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