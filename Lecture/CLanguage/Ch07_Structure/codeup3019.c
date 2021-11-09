#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
	char schedule[100];
	int y, m, d;
} ScheduleMemo;

int compareSchedule(const void* a, const void* b)    // 오름차순 비교 함수 구현
{
	ScheduleMemo s1 = *(ScheduleMemo*)a;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴
	ScheduleMemo s2 = *(ScheduleMemo*)b;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴

	if (s1.y < s2.y)
		return -1;
	else if (s1.y > s2.y)
		return 1;
	else if (s1.m < s2.m)
		return -1;
	else if (s1.m > s2.m)
		return 1;
	else if (s1.d < s2.d)
		return -1;
	else if (s1.d > s2.d)
		return 1;
	else if (strcmp(s1.schedule, s2.schedule) > 0)
		return 1;

	return 0;    // a와 b가 같을 때는 0 반환
}

void printStudents(ScheduleMemo* memo, int n) {
	for (int i = 0; i < n; i++) {
		printf("%s %d %d %d\n", memo[i].schedule, memo[i].y, memo[i].m, memo[i].d);
	}
}

int main() {
	int n;

	// 첫째줄에 데이터의 개수 n이 입력된다.(1<=n<=100)
	scanf("%d", &n);

	// 둘째 줄부터 n+1줄에 학생 이름과 3과목 점수들이 공백으로 구분되어 입력된다. (입력 예시 참고)
	ScheduleMemo* memo = (ScheduleMemo*)malloc(sizeof(ScheduleMemo) * n);

	for (int i = 0; i < n; i++) {
		scanf("%s", &memo[i].schedule);
		scanf("%d", &memo[i].y);
		scanf("%d", &memo[i].m);
		scanf("%d", &memo[i].d);
	}

	//printStudents(memo, n);
	qsort(memo, n, sizeof(ScheduleMemo), compareSchedule);
	//printStudents(memo, n);

	for (int i = 0; i < n; i++)
		printf("%s\n", memo[i].schedule);


	return 0;
}