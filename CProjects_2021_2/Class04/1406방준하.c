#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>
#define M 16                   //최대 16팀 수용 가능
#define MAX 25                 //25팀 저장 가능
typedef struct {
	int table;
	char person[10];
	int phoneNum;
	int time;
	int member;
	int price;                 //음식까지 입력하려면 메뉴가 필요하므로 거기까지는 안 감
	int usage;                 //현재 테이블에 앉아서 먹고 있다면 1, 이미 갔거으면 2, 아직 안 왔으면 0
}info;

void printStruct(info* n, int a);

int main() {
	info Group[MAX];
	int n;
	int count = 0;
	while (1) {


		printf("예약 입력:1  주문 입력:2  현재 상황:3  예약확인:4  결제:5  새롭게 자리배치:6  현재까지 방문한 손님 명단:7  프로그램 종료:8\n");

		scanf("%d", &n);
		switch (n) {
		case(1): {   //예약 입력   누가 전화해서 예약했을때
			if (count < MAX)
			{
				printf("이름을 입력하세요:");
				scanf("%s", Group[count].person);

				do {
					printf("테이블을 입력하세요:");
					scanf("%d", &Group[count].table);
				} while (Group[count].table > M);
				printf("인원 수를 입력하세요:");
				scanf("%d", &Group[count].member);
				printf("010 없이 전화번호를 입력하세요:");
				scanf("%d", &Group[count].phoneNum);
				while (Group[count].phoneNum >= (int)pow(10, 8) || Group[count].phoneNum < (int)pow(10, 7)) {
					printf("010 없이 전화번호를 입력하세요:");
					scanf("%d", &Group[count].phoneNum);
				}
				printf("시간을 입력하세요(오후 1시 39분 = 1339,오전 0시 23분 = 23, 오전 1시 16분 = 116):");             //정수형으로 시간을 저장해야 되기 때문
				scanf("%d", &Group[count].time);
				while (Group[count].time / 100 >= 24 || Group[count].time % 100 >= 60) {
					printf("다시 입력하세요(오후 1시 39분 = 1339,오전 0시 23분 = 23, 오전 1시 16분 = 116):");
					scanf("%d", &Group[count].time);
				}
				Group[count].price = 0;
				Group[count].usage = 0;

			}
			count++;
			break;
		}
		case(2): {         //주문 입력   특정 테이블이 주문할 경우 지불해야 될 돈 추가
			int a;
			printf("테이블:");
			scanf("%d", &a);
			for (int i = 0; i < count; i++)
			{
				if (Group[i].table == a && Group[i].usage == 1)
				{
					int add;
					printf("추가 금액:");
					scanf("%d", &add);
					Group[i].price += add;
					break;
				}
			}
			break;
		}
		case(3): {              //현재 상황(누가 어디서 먹고 있는지)

			printf("좌석  이름         인원 수   전화번호    시각    금액\n");
			for (int i = 0; i < count; i++)
			{
				if (Group[i].usage == 1) {
					printStruct(Group, i);
				}
			}
			break;
		}
		case(4): {     //예약 확인(아직 안 온 사람들)
			printf("좌석  이름         인원 수   전화번호    시각    금액\n");
			for (int i = 0; i < count; i++)
			{
				if (Group[i].usage == 0)
				{
					printStruct(Group, i);

				}
			}
			break;
		}
		case(5): {                    //결제
			int b;
			printf("결제할 테이블:");
			scanf("%d", &b);
			for (int i = 0; i < count; i++)
			{
				if (Group[i].table == b && Group[i].usage != 0)
				{
					printf("%d\n", Group[i].price);
					Group[i].usage = 2;

				}
			}

			break;
		}
		case(6): {                         //새롭게 자리배치(예약한 사람이 도착해서 자리에 배정하기)
			printf("이름을 입력하세요:");
			char newname[10];

			scanf("%s", newname);
			for (int i = 0; i < count; i++)
			{

				if (strcmp(newname, &Group[i].person) == 0)
				{
					Group[i].usage = 1;


				}

			}

			break;
		}
		case(7): {    //지금 까지 방문한 손님 명단(예약했지만 아직 안 온사람 출력X)
			printf("좌석  이름         인원 수   전화번호    시각    금액\n");
			for (int i = 0; i < count; i++)
			{
				if (Group[i].usage != 0) {
					printStruct(Group, i);
				}

			}
			break;
		}
		case(8): {                //프로그램 종료
			exit(0);
		}
		default: printf("1~8까지만 입력 가능합니다.\n");
		}

	}
	return 0;
}


void printStruct(info* n, int a) {

	printf(" ");
	printf("%-3d", (n + a)->table);

	printf(" %-10s   ", (n + a)->person);
	printf(" %-4d  ", (n + a)->member);
	printf("    ");
	int Num = (n + a)->phoneNum;
	for (int i = 0; i < 8; i++)  //0000-0000식으로 출력하기 위해
	{


		printf("%d", Num / (int)pow(10, 7 - i));
		Num = Num % (int)pow(10, 7 - i);
		if (i == 3) {
			printf("-");
		}
	}
	printf("   ");
	int time = (n + a)->time;
	if (time >= 1000) {     //00:02,00:12,05:30,11:20 같은 경우 각각 대비
		for (int i = 0; i < 4; i++)
		{
			printf("%d", time / (int)pow(10, 3 - i));
			time = time % (int)pow(10, 3 - i);
			if (i == 1)
			{
				printf(":");
			}
		}
	}
	else if (time >= 100) {
		printf("0");
		for (int i = 0; i < 3; i++) {

			printf("%d", time / (int)pow(10, 2 - i));
			time = time % (int)pow(10, 2 - i);
			if (i == 0) printf(":");
		}
	}
	else if (time >= 10) {
		printf("00:%d", time);
	}
	else {
		printf("00:0%d", time);
	}
	printf("   ");
	printf("%-7d\n", (n + a)->price);

}
