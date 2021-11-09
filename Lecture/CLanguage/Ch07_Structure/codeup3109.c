#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
	char code;
	int no;
	char name[20];
} Student;

int compareStudents(const void* a, const void* b)    // 오름차순 비교 함수 구현
{
	Student s1 = *(Student*)a;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴
	Student s2 = *(Student*)b;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴

	if (s1.no < s2.no)
		return -1;

	if (s1.no > s2.no)
		return 1;

	return 0;
}

void printStudents(Student* students, int n) {
	printf("\n");
	for (int i = 0; i < n; i++) {
		printf("%c %d %s\n", students[i].code, students[i].no, students[i].name);
	}
	printf("\n");
}

int checkNo(Student* students, Student* new, int n) {
	for (int i = 0; i < n; i++) {
		if (new->no == students[i].no) {
			for (int j = n - 1; j >= i; j--)
				students[j + 1] = students[j];
			students[i] = *new;
			return 0;
		}
	}
	return 1;
}

int deleteStudent(Student* students, int no, int n) {
	for (int i = 0; i < n; i++)
		if (no == students[i].no) {
			// 배열의 요소 제거
			for (int j = i; j < n - 1; j++)
				students[j] = students[j + 1];
			return 1;
		}
	return 0;
}

int main() {
	int n;
	Student temp;
	int rightPosition[5] = { 0 };

	// 첫째 줄에 입력 데이터의 개수 n이 입력된다. (10<=n<=20,000)
	scanf("%d", &n);
	getchar();

	// 둘째 줄부터 n+1번째 줄까지 처리 코드c(문자 1자리), 수험 번호 no(1<=no<=1,000,000,000), 이름(10바이트 이내)이 입력된다.
	Student* students = (Student*)malloc(sizeof(Student) * n);

	int index = 0;
	for (int i = 0; i < n; i++) {
		scanf("%c %d %s", &temp.code, &temp.no, temp.name);
		getchar();

		// code가 'I' 이고, 이전에 입력된 자료에 동일한 수험번호가 없으면 추가
		if (temp.code == 'I') {
			// 같은 수험번호 맨 앞에 삽입
			if (checkNo(students, &temp, index)) {
				students[index] = temp;
			}
			index++;
		}
		else if (temp.code == 'D') {	// 처리 코드가 ‘D’이면 메모리의 데이터 중에서 해당 수험 번호를 찾아 삭제한다.
			if (deleteStudent(students, temp.no, index)) {
				index--;
			}
		}
	}
	for (int i = 0; i < 5; i++)
		scanf("%d", &rightPosition[i]);

	//printStudents(students, index);
	qsort(students, index, sizeof(Student), compareStudents);
	//printStudents(students, index);

	for (int i = 0; i < 5; i++)
		printf("%d %s\n", students[rightPosition[i] - 1].no, students[rightPosition[i] - 1].name);

	return 0;
}
