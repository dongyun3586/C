#include<stdio.h>
#include<stdlib.h>

typedef struct {
	char name[12];
	int score;
} Student;

int compareStudent(const void* a, const void* b)    // 오름차순 비교 함수 구현
{
	Student s1 = *(Student*)a;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴
	Student s2 = *(Student*)b;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴

	if (s1.score > s2.score)    // a가 b보다 작을 때는
		return -1;      // -1 반환

	if (s1.score < s2.score)    // a가 b보다 클 때는
		return 1;       // 1 반환

	return 0;    // a와 b가 같을 때는 0 반환
}

void printStudents(Student* students, int n) {
	for (int i = 0; i < n; i++) {
		printf("%s %d\n", students[i].name, students[i].score);
	}
}

int main() {
	int n, m;

	// 첫째 줄에 데이터의 개수 n (3<=n<=100)과 출력인원 m (1<=m<=n)이 공백으로 구분되어 입력
	scanf("%d %d", &n, &m);

	// 둘째 줄부터 학생 이름과 점수(0 100)가 공백으로 구분되어 입력된다. 
	Student* students = (Student*)malloc(sizeof(Student) * n);
	int* scores = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		scanf("%s", &students[i].name);
		scanf("%d", &students[i].score);
	}

	//printStudents(students, n);
	qsort(students, n, sizeof(Student), compareStudent);
	//printStudents(students, n);

	for (int i = 0; i < m; i++)
		printf("%s\n", students[i].name);

	return 0;
}