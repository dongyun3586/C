#include<stdio.h>
#include<stdlib.h>

typedef struct {
	char name[12];
	int A, B, C;
} Student;

int compareStudent(const void* a, const void* b)    // 오름차순 비교 함수 구현
{
	Student s1 = *(Student*)a;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴
	Student s2 = *(Student*)b;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴

	if (s1.A > s2.A)    // a가 b보다 작을 때는
		return -1;      // -1 반환

	if (s1.A < s2.A)    // a가 b보다 클 때는
		return 1;       // 1 반환

	return 0;    // a와 b가 같을 때는 0 반환
}

void printStudents(Student* students, int n) {
	for (int i = 0; i < n; i++) {
		printf("%s %d %d %d\n", students[i].name, students[i].A, students[i].B, students[i].C);
	}
}

int main() {
	int n;

	// 첫째 줄에 데이터의 개수 n (3<=n<=100)
	scanf("%d", &n);

	// 둘째 줄부터 n+1줄에 학생 이름과 3과목 점수들이 공백으로 구분되어 입력된다. (입력 예시 참고)
	Student* students = (Student*)malloc(sizeof(Student) * n);
	int* scores = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		scanf("%s", &students[i].name);
		scanf("%d", &students[i].A);
		scanf("%d", &students[i].B);
		scanf("%d", &students[i].C);
	}

	//printStudents(students, n);
	qsort(students, n, sizeof(Student), compareStudent);
	//printStudents(students, n);

	int rankB = 1;
	int rankC = 1;
	for (int i = 1; i < n; i++) {
		if (students[0].B < students[i].B)	rankB++;
		if (students[0].C < students[i].C)	rankC++;
	}

	printf("%s %d %d", students[0].name, rankB, rankC);


	return 0;
}