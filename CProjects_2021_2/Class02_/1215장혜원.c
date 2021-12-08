#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUBJECTNUMBER 20          //과목 최대 개수
#define SUBJECTNAMELENGTH 10      //과목 명칭 최대 길이
#define DAYLENGTH 10              //최대 하루 교시 수
#define CLASSNUMBER 10            //최대 반 수

char* subjectList[SUBJECTNUMBER] = { 0 };   //과목 명칭 목록
int subjectCredit[SUBJECTNUMBER] = { 0 };   //과목 학점 목록
int timeTable[5][DAYLENGTH][CLASSNUMBER] = { 0 };     //전체 반의 시간표 목록             가로 : 주 5일, 세로 : 최대 교시 수, 입체축 : 반 수
int classNumber = 0;                    //전체 반 개수
int dayLength = 0;                      //하루 교시 수
int subjectNum = 0;                     //과목의 개수

int timetable_class_f_check[CLASSNUMBER][SUBJECTNUMBER] = { 0, };        //각 반별로, 각 과목당 학점이 얼마나 찼는지 확인.

int checkValidCredit(int s, int l);
void printTimeTable();
void generateTimetableList();
void allocateRandomNumberInList();
void deleteQueue(int* arr, int k);
void rotateQueue(int* arr, int k);
int sameNumberChecking(int* arr, int k);

int temp_timetable_list[CLASSNUMBER][5][SUBJECTNUMBER] = { 0 };     // 각 시간당, 반 개수만큼의 과목 리스트를 작성
int temp_timetable_check[5][SUBJECTNUMBER] = { 0 };     // 각 시간당, 반 개수만큼의 과목이 할당되었는지 확인

void deleteQueue(int* arr, int k) {
	for (int l = k - 2; l >= 0; l--) {
		arr[l] = arr[l + 1];
	}
	arr[k] = 0;
}

void rotateQueue(int* arr, int k) {
	int temp = arr[0];
	for (int l = 0; l < k - 1; l++) {
		arr[l] = arr[l + 1];
	}
	arr[k - 1] = temp;
}

void generateTimetableList() {//전역변수로 선언한 과목의 정보들을 이용함

	allocateRandomNumberInList();

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < dayLength; j++) {
			for (int k = 0; k < classNumber; k++) {

				int check_subjectFilled = (timetable_class_f_check[k][temp_timetable_list[i][j][k]] < subjectCredit[temp_timetable_list[i][j][k]]);
				int check_subjectInDay = (0);
			again:
				if ((check_subjectFilled) && !(check_subjectInDay)) {                       //선택된 과목이 이미 채워질 수 있는 조건일 경우에 : 과목을 확정하고 check++, 큐에서 하나 지움
					timeTable[i][j][k] = temp_timetable_list[i][j][k];
					timetable_class_f_check[k][temp_timetable_list[i][j][k]] ++;

					deleteQueue(temp_timetable_list[i][j], classNumber);                  // 디버그해서 & 필요한지 형 봐보기
				}
				else {
					rotateQueue(temp_timetable_list[i][j], classNumber);
					goto again;
				}
			}
		}
	}

}

int sameNumberChecking(int* arr, int k) {
	int check[SUBJECTNUMBER] = { 0 };
	for (int i = 0; i < k; i++) {
		check[arr[i]] ++;
	}
	for (int i = 0; i < subjectNum; i++) {
		if (check[i] >= 2) {
			return 0;
		}
	}
}

void allocateRandomNumberInList() {            //  각 반의 개수만큼, 각 시간당 과목 index를 할당
	srand(time(NULL));
	int loc = 0;
	int sameNumber = sameNumberChecking(temp_timetable_list[loc % 5][(loc - loc % 5) / 5], temp_timetable_check[loc % 5][(loc - loc % 5) / 5]);

	for (int i = 0; i < subjectNum; i++) {
		for (int j = 0; j < subjectCredit[i] * classNumber; j++) {
		ALLOCAGAIN:
			loc = rand() % (dayLength * 5);
			if ((temp_timetable_check[loc % 5][(loc - loc % 5) / 5] < classNumber) && sameNumber) {
				temp_timetable_list[loc % 5][(loc - loc % 5) / 5][temp_timetable_check[loc % 5][(loc - loc % 5) / 5]] = i;
				temp_timetable_check[loc % 5][(loc - loc % 5) / 5] ++;
			}
			else {
				goto ALLOCAGAIN;
			}

		}
	}
}

void printTimeTable() {
	for (int k = 0; k < classNumber; k++) {
		printf("%d반\n\n", k + 1);
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < dayLength; j++) {
				printf("%d ", /*subjectList[timeTable[i][j][k]]*/ timeTable[i][j][k]); //SUBJECTNAMELENGTH = 10;
			}
			printf("\n");
		}
		printf("\n\n");
	}
}



int checkValidCredit(int s, int l) {
	if (s != l * 5) return 0;
	else return 1;
}

int main(void) {

	printf("전체 몇 반인지 입력하세요 : ");
	scanf("%d", &classNumber);

	printf("하루에 몇 교시인지 입력하세요 : ");
	scanf("%d", &dayLength);

	printf("과목의 개수를 입력하세요 : ");
	scanf("%d", &subjectNum);

	/*printf("과목의 이름을 입력하세요(띄어쓰기 없이, 영어로) : ");
	for(int i = 0; i < subjectNum; i++) {
		scanf("%s", &subjectList[i]);
	}*/

	printf("과목의 학점을 입력하세요(과목 이름을 입력한 순서대로) : ");
	int tempsum = 0;
	for (int i = 0; i < subjectNum; i++) {
		scanf("%d", &subjectCredit[i]);
		tempsum += subjectCredit[i];
	}
	if (!checkValidCredit(tempsum, dayLength)) {
		printf("올바르지 않은 학점입니다.\n프로그램을 종료합니다.");
		return 0;
	}


	generateTimetableList();
	printTimeTable();
}