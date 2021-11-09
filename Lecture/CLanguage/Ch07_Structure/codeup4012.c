#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
	int no;
	int score;
	int order;
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

int compareStudent2(const void* a, const void* b)    // 오름차순 비교 함수 구현
{
	Student s1 = *(Student*)a;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴
	Student s2 = *(Student*)b;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴

	if (s1.no < s2.no)    // a가 b보다 작을 때는
		return -1;      // -1 반환

	if (s1.no > s2.no)    // a가 b보다 클 때는
		return 1;       // 1 반환

	return 0;    // a와 b가 같을 때는 0 반환
}

void printArr(Student* students, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d %d\n", students[i].score, students[i].order);
		//printf("%d %d %d\n", students[i].no, students[i].score, students[i].order);
	}
}

int main() {
	int n;

	// 1) 첫 번째 줄은 처리할 점수의 개수 n ( n <= 200 )
	scanf("%d", &n);

	Student* students = (Student*)malloc(sizeof(Student) * n);

	// 2) 두 번째 줄은 처리할 점수 데이터 (0~100점)
	for (int i = 0; i < n; i++) {
		students[i].no = i;
		scanf("%d", &students[i].score);
	}

	//printArr(students, n);
	// 성적으로 정렬
	qsort(students, n, sizeof(Student), compareStudent);

	students[0].order = 1;
	for (int i = 1; i < n; i++) {
		if (students[i - 1].score == students[i].score)
			students[i].order = students[i - 1].order;
		else
			students[i].order = i + 1;
	}

	// 원래 순서대로 되돌리기
	qsort(students, n, sizeof(Student), compareStudent2);

	printArr(students, n);

	return 0;
}