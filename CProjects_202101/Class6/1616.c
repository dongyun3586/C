#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int random(int n);						//중간단계에서 랜덤으로 번호 골라주기
void finalrandom(int num);				//최종단계에서 랜덤으로 메뉴 결정해주기
//int error(int x, int i, int f);		//주어진 번호가 아닌 번호를 골랐을때 다시 고르라고 하기

int main() {
	int a, b;
	printf("메뉴 선정? 내가 도와주겠어.\n\n");
	//CHECK:
	printf("1. 한식  2. 일식  3. 중식  4. 양식  5. 분식/야식  6. 고기  7. 기타  8. 디저트  9. 아무거나!\n숫자 입력: ");
	scanf("%d", &a);
	/*if (1 > a || a > 9)
	{
		printf("error\n");
		goto CHECK;
	}
	//error(a, 1, 9);
	*/

	while (a == 9) {
		printf("%d로 골라봤어!", random(8));
		a = random(8);
	}

	switch (a) {
	case 1:
		printf("\n\n한식!\n1. 국물 O, 매움    2. 국물 O, 안매움    3. 국물 X, 매움    4. 국물 X, 안매움\n숫자 입력: ");
		scanf("%d", &b);

		//error(b, 1, 4);

		switch (b) {
		case 1:
			printf("\n\n1 김치찌개   2 육개장   3 매운탕   4 부대찌개   5 감자탕\n");
			break;
		case 2:
			printf("\n\n1 닭볶음탕   2 양념게장   3 김치볶음밥   4 곱창볶음   5 낙지볶음\n");
			break;
		case 3:
			printf("\n\n1 설렁탕   2 미역국   3 된장찌개   4 냉면   5 떡국\n");
			break;
		case 4:
			printf("\n\n1 갈비찜   2 간장게장   3 불고기 백반   4 비빔밥   5 떡갈비\n");
			break;
		}

		finalrandom(5);
		break;
	case 2:
		printf("\n\n일식!\n1. 국물 O    2. 국물 X\n숫자 입력: ");
		scanf("%d", &b);

		if (b == 1) printf("1 우동   2 라멘   3 샤부샤부   4 스키야키");
		else printf("1 초밥   2 장어덮밥   3 오코노미야키   4 돈카츠");

		finalrandom(4);
		break;

	case 3:
		printf("\n\n중식!\n1. 매움  2. 안매움\n숫자 입력: ");
		scanf("%d", &b);

		switch (b) {
		case 1:
			printf("\n\n1 김치찌개   2 육개장   3 매운탕   4 부대찌개\n");
			break;

		case 2:
			printf("\n\n1 닭볶음탕   2 양념게장   3 김치볶음밥   4 곱창볶음\n");
			break;
		}

		finalrandom(4);
		break;

	case 4:
		printf("\n\n양식!\n\n");
		printf("1 피자   2 파스타   3 스테이크   4 햄버거");

		finalrandom(4);
		break;

	case 5:
		printf("\n\n분식 / 야식!\n\n");
		printf("1 떡볶이   2 라면   3 닭발   4 후라이드 치킨   5 양념치킨   6 상추튀김   7 김밥");
		finalrandom(7);
		break;

	case 6:
		printf("\n\n고기!\n1. 돼지고기   2. 소고기   3. 닭 & 오리고기\n숫자 입력: ");
		scanf("%d", &b);

		switch (b) {
		case 1:
			printf("\n\n1 삼겹살   2 목살   3 보쌈, 족발   4 돼지갈비\n");
			finalrandom(4);
			break;

		case 2:
			printf("\n\n1 등심   2 소불고기   3 갈비살\n");
			finalrandom(3);
			break;

		case 3:
			printf("\n\n1 훈제오리   2 오리백숙   3 닭백숙   4 닭갈비\n");
			finalrandom(4);
			break;
		}

		break;

	case 7:
		printf("\n\n기타!\n\n");
		printf("1 쌀국수   2 라면   3 닭발   4 후라이드 치킨   5 양념치킨   6 상추튀김   7 김밥");
		finalrandom(7);
		break;

	case 8:
		printf("\n\n디저트!\n1 빙수   2 케이크   3 크로플   4 떡   5 마카롱   6 아이스크림\n숫자 입력: ");
		finalrandom(6);

		break;
	}
}

void finalrandom(int num) {
	srand(time(NULL));
	int t, r = rand() % num + 1;
	printf("\n\n여기서도 못고르겠으면 내가 랜덤으로 골라줄게!\n");
	printf("1. 아니야 괜찮아!  2. 골라줘!\n숫자 입력: ");
	scanf("%d", &t);

	if (t == 1) printf("알았어! 밥 맛있게 먹어~ :)");
	else printf("\n\n내가 골라준 번호는 %d야! 밥 맛있게 먹어~ :)", r);
}

int random(int n) {
	srand(time(NULL));
	int r = rand() % n + 1;

	return r;
}
/*
int error(int a, int i, int f) {
	int x = a, y=0;
	while (x<i || x>f) {
		printf("에러! %d ~ %d 중에서 골라줘!\n", i, f);
		printf("숫자 입력: ");
		scanf("%d, &y");
		x = y;
	}
	return a;
}
*/