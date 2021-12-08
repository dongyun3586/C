#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_NAME 10
#define MAX_SUB 4
#define MAX_STU 16

enum choose { INPUT = 1, SEARCH, DELETE, RANK, EXIT } choice;     //main 함수에서 메뉴를 선택할때 우리가 배운 enum을 사용해서 직관적으로 switch case 문에 추가하고자 했다.

struct subject {     //과목과 평균을 하나로 묶은 구조체
	float kor;
	float eng;
	float math;
	float sci;
	float sum;
};

typedef struct {                    //학생의 정보를 담은 구조체로 이름, 출석 번호, 과목 점수가 있다.
	char name[MAX_NAME];
	int number;
	struct subject sub;
}student;

int inputstudent(student* p, int count);      //학생을 추가하는 함수
void search(student* p, int count);  //조건에 맞춰서 학생을 검색하는 함수로 이동시켜주는 함수
int searchstudent(student* p);   //학생을 검색하는 함수
void showstudentlist(student* p, int count);     //지금까지 저장된 학생을 보여주는 함수
int delete(student* p, int count);  //조건에 맞춰서 학생을 제거하는 함수로 이동시켜주는 함수
void deletestudent(student* p, int num, int count);  //학생을 제거하는 함수
void rankstudent(student* p, int count);  //학생의 등수를 보여주는 함수

int main() {      //main 함수는 사용자가 선택할 메뉴를 다루는 함수로 switch case 문을 사용함
	student stu[MAX_STU] = { "", 0, {0,0,0,0,0} };
	int count = 0;
	printf("***********1408의 성적 관리 시스템에 오신것을 환영합니다!***********\n\n");

	while (1) {
		printf("메뉴로는  1: 학생 추가, 2: 학생 검색, 3: 학생 제거, 4: 등수 확인, 5: 나가기\n메뉴 선택: ");
		scanf("%d", &choice);
		system("cls"); //기존에 있던 것을 다 지워주기 위해 사용함
		switch (choice) {  //이 코드는 수업시간에 했던 연습문제 13: 친구관리 시스템에서 일부 인용해왔다.
		case INPUT:
			if (inputstudent(stu, count) == 1) count++;
			break;
		case SEARCH:
			search(stu, count);
			break;
		case DELETE:
			if (delete(stu, count) == 1) count--;
			break;
		case RANK:
			rankstudent(stu, count);
			break;
		case EXIT:
			printf("\n성적 관리 프로그램을 종료합니다. 이용해 주셔서 감사합니다.\n");
			exit(0);
		default:
			printf("정확한 값을 입력해주세요!\n\n");
			break;
		}
	}

}

int inputstudent(student* p, int count) {
	if (count < MAX_STU) {
		printf("추가할 학생의 정보를 입력해주세요.\n");
		printf("학생 이름: ");
		scanf("%s", &(p[count].name));
		printf("국어 성적: ");
		scanf("%f", &(p[count].sub.kor));
		printf("영어 성적: ");
		scanf("%f", &(p[count].sub.eng));
		printf("수학 성적: ");
		scanf("%f", &(p[count].sub.math));
		printf("과학 성적: ");
		scanf("%f", &(p[count].sub.sci));
		p[count].sub.sum = p[count].sub.kor + p[count].sub.eng + p[count].sub.math + p[count].sub.sci;
		p[count].number = count + 1;
		printf("정상적으로 학생이 추가되었습니다!\n\n");
		return 1;
	}
	else
		printf("학생을 이미 최대로 저장했습니다. 학생 제거 후 다시 시도해주세요\n\n");
	return 0;
}

void showstudentlist(student* p, int count) {
	int i;
	int number;
	if (count > 0) {  //저장된 학생이 한명이라도 있어야지 학생을 보여줌
		printf("\n등록된 학생 목록\n");
		printf(" 번호   이름\n");
		printf("=============\n");
		for (i = 0; i < count; i++) {

			printf(" %2d :  %-10s\n", (p + i)->number, (p + i)->name);
		}
		printf("=============\n\n");
		return 0;
	}
	else {
		printf("\n등록된 학생이 없습니다.\n\n");
		return 0;
	}
}

void search(student* p, int count) {
	if (count > 0) {  //저장된 학생이 한명 이상일때 검색함수로 보냄
		showstudentlist(p, count);
		searchstudent(p);
	}
	else return 0;
}

int searchstudent(student* p) {
	int stunum;

	while (1) {
		printf("검색하고 싶은 학생의 번호를 입력해주세요: ");
		scanf("%d", &stunum);
		stunum--;  //배열이기 때문에 우리가 보는 번호는 1부터이므로 -1을 해줌(stunum을 계속 써야하기 때문에 그냥 p[stunum-1]...계속 쓰는 것보다 그냥 1줄여버림
		if (p[stunum].number < MAX_STU && p[stunum].number>0) {    //처음에 0으로 초기화 했기 때문에 0과 최대 학생수 사이에 있는 번호여야지 출력
			printf("\n     이름           국어    수학   영어   과학\n");
			printf("===============================================\n");
			printf("    %-14s %5.2f, %5.2f, %5.2f, %5.2f\n", p[stunum].name, p[stunum].sub.kor, p[stunum].sub.eng, p[stunum].sub.math, p[stunum].sub.sci);
			printf("===============================================\n\n");
			return 0;
		}
		else {
			printf("학생의 번호를 정확히 입력해주세요!\n\n");
		}
	}
}

int delete(student* p, int count) {
	int stunum;
	if (count > 0) {  //학생이 한명이라도 있어야지 제거 가능
		showstudentlist(p, count);  //학생의 명부를 보여줌
		while (1) {
			printf("제거할 학생의 번호를 입력해주세요: ");
			scanf("%d", &stunum);
			if (p[stunum - 1].number < 17 && p[stunum - 1].number>0) {
				deletestudent(p, stunum, count);
				printf("학생이 정상적으로 제거되었습니다\n\n");
				return 1;
			}
			else printf("학생의 번호를 정확히 입력해주세요!\n\n");
		}
	}
	else {
		printf("\n등록된 학생이 없습니다.\n\n");
		return 0;



	}
}

void deletestudent(student* p, int num, int count) {
	for (int i = num - 1; i < count; i++) {   //제거하려는 학생부터 한칸씩 옮겨주는 코드
		p[i] = p[i + 1];
	}
	for (int i = num - 1; i < count - 1; i++) {  //위의 코드로 출석번호 까지 베껴져서 1,2,3에서 2를 제거하면 1,3이 되므로 삭제한 지점부터 번호를 1씩 낮춤
		p[i].number--;
	}
}

void rankstudent(student* p, int count) {  //등수를 출력하기 위해서는 학생들의 위치를 배열 내에서 바꿔야한다. 그런데 원래 구조체배열에서 바꾸면 안되기 때문에 새로운 rank배열을 만들어 주았다.
	int choice;
	if (count > 0) {
		student rank[MAX_STU] = { "", 0, {0,0,0,0,0} };
		student temp[MAX_STU];
		for (int i = 0; i < count; i++) {
			rank[i] = p[i];   //rank 배열에 본래 구조체 배열안에 있는 값을 순서대로 넣어준다
		}
		for (int i = 1; i < count; i++) {
			for (int j = 0; j < count - i; j++) {   //뒷사람이 앞사람보다 성적이 높을 때 rank배열의 순서를 바꿔준다.
				if (rank[j + 1].sub.sum > rank[j].sub.sum) {
					temp[j] = rank[j];
					rank[j] = rank[j + 1];
					rank[j + 1] = temp[j];
				}
			}
		}
		printf("***********총합 성적 등수***********\n\n");  //원래는 총합 등수 말고도 각 과목별로 등수를 나누려 했으나 똑같은 코드에서 sum-->(kor, math...등)으로 만 바꾸기 때문에 똑같은 코드가 너무 많이 반복되어 총합 등수 하나만 했다.
		printf(" 등수   번호   이름    평균\n");
		printf("=============================\n");
		for (int i = 0; i < count; i++) {
			printf("  %d등   %2d :  %-4s   %.2f\n", i + 1, rank[i].number, rank[i].name, rank[i].sub.sum / MAX_SUB);
		}
		printf("=============================\n\n");
		return 0;
	}
	else {
		printf("\n등록된 학생이 없습니다.\n\n");
		return 0;
	}
}