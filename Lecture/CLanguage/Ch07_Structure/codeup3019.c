#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
	char schedule[100];
	int y, m, d;
} ScheduleMemo;

int compareSchedule(const void* a, const void* b)    // �������� �� �Լ� ����
{
	ScheduleMemo s1 = *(ScheduleMemo*)a;    // void �����͸� int �����ͷ� ��ȯ�� �� �������Ͽ� ���� ������
	ScheduleMemo s2 = *(ScheduleMemo*)b;    // void �����͸� int �����ͷ� ��ȯ�� �� �������Ͽ� ���� ������

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

	return 0;    // a�� b�� ���� ���� 0 ��ȯ
}

void printStudents(ScheduleMemo* memo, int n) {
	for (int i = 0; i < n; i++) {
		printf("%s %d %d %d\n", memo[i].schedule, memo[i].y, memo[i].m, memo[i].d);
	}
}

int main() {
	int n;

	// ù°�ٿ� �������� ���� n�� �Էµȴ�.(1<=n<=100)
	scanf("%d", &n);

	// ��° �ٺ��� n+1�ٿ� �л� �̸��� 3���� �������� �������� ���еǾ� �Էµȴ�. (�Է� ���� ����)
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