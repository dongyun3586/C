#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUBJECTNUMBER 20          //���� �ִ� ����
#define SUBJECTNAMELENGTH 10      //���� ��Ī �ִ� ����
#define DAYLENGTH 10              //�ִ� �Ϸ� ���� ��
#define CLASSNUMBER 10            //�ִ� �� ��

char* subjectList[SUBJECTNUMBER] = { 0 };   //���� ��Ī ���
int subjectCredit[SUBJECTNUMBER] = { 0 };   //���� ���� ���
int timeTable[5][DAYLENGTH][CLASSNUMBER] = { 0 };     //��ü ���� �ð�ǥ ���             ���� : �� 5��, ���� : �ִ� ���� ��, ��ü�� : �� ��
int classNumber = 0;                    //��ü �� ����
int dayLength = 0;                      //�Ϸ� ���� ��
int subjectNum = 0;                     //������ ����

int timetable_class_f_check[CLASSNUMBER][SUBJECTNUMBER] = { 0, };        //�� �ݺ���, �� ����� ������ �󸶳� á���� Ȯ��.

int checkValidCredit(int s, int l);
void printTimeTable();
void generateTimetableList();
void allocateRandomNumberInList();
void deleteQueue(int* arr, int k);
void rotateQueue(int* arr, int k);
int sameNumberChecking(int* arr, int k);

int temp_timetable_list[CLASSNUMBER][5][SUBJECTNUMBER] = { 0 };     // �� �ð���, �� ������ŭ�� ���� ����Ʈ�� �ۼ�
int temp_timetable_check[5][SUBJECTNUMBER] = { 0 };     // �� �ð���, �� ������ŭ�� ������ �Ҵ�Ǿ����� Ȯ��

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

void generateTimetableList() {//���������� ������ ������ �������� �̿���

	allocateRandomNumberInList();

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < dayLength; j++) {
			for (int k = 0; k < classNumber; k++) {

				int check_subjectFilled = (timetable_class_f_check[k][temp_timetable_list[i][j][k]] < subjectCredit[temp_timetable_list[i][j][k]]);
				int check_subjectInDay = (0);
			again:
				if ((check_subjectFilled) && !(check_subjectInDay)) {                       //���õ� ������ �̹� ä���� �� �ִ� ������ ��쿡 : ������ Ȯ���ϰ� check++, ť���� �ϳ� ����
					timeTable[i][j][k] = temp_timetable_list[i][j][k];
					timetable_class_f_check[k][temp_timetable_list[i][j][k]] ++;

					deleteQueue(temp_timetable_list[i][j], classNumber);                  // ������ؼ� & �ʿ����� �� ������
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

void allocateRandomNumberInList() {            //  �� ���� ������ŭ, �� �ð��� ���� index�� �Ҵ�
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
		printf("%d��\n\n", k + 1);
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

	printf("��ü �� ������ �Է��ϼ��� : ");
	scanf("%d", &classNumber);

	printf("�Ϸ翡 �� �������� �Է��ϼ��� : ");
	scanf("%d", &dayLength);

	printf("������ ������ �Է��ϼ��� : ");
	scanf("%d", &subjectNum);

	/*printf("������ �̸��� �Է��ϼ���(���� ����, �����) : ");
	for(int i = 0; i < subjectNum; i++) {
		scanf("%s", &subjectList[i]);
	}*/

	printf("������ ������ �Է��ϼ���(���� �̸��� �Է��� �������) : ");
	int tempsum = 0;
	for (int i = 0; i < subjectNum; i++) {
		scanf("%d", &subjectCredit[i]);
		tempsum += subjectCredit[i];
	}
	if (!checkValidCredit(tempsum, dayLength)) {
		printf("�ùٸ��� ���� �����Դϴ�.\n���α׷��� �����մϴ�.");
		return 0;
	}


	generateTimetableList();
	printTimeTable();
}