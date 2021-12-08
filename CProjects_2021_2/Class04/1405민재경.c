#include <stdio.h>

typedef struct {
	char* name;
	int price1;
	int price2;
} burger_;

int main()
{
	//인사
	printf("저희 RotteQueen에 오신 것을 환영합니다.\n");
	printf("*(처음 결정을 하실거면 1을 누르시고, 다른 결정을 하실거면 2를 누르시면 됩니다.)*\n");
	int a, b, c, d, e, f, g, h = 0;

	//섭취 장소 질문
	printf("매장에서 드시겠습니까? 포장하시겠습니까?\n");
	scanf("%d", &a);
	if (a == 1) {
		printf("\n매장을 선택하셨습니다.\n");
	}
	else if (a == 2) {
		printf("\n포장을 선택하셨습니다.\n");
	}
	else {
		printf("잘못된 정보를 입력했습니다. 다시 이용해 주시기 바랍니다.\n");
		return 0;
	}

	//햄버거 종류 질문
	//1. 기본 햄버거(3900 / 5900)  2. 치즈 햄버거(4400 / 6400)  3. 새우 버거(4900 / 6900)  4. 치킨 버거(5400 / 7400)  5. 더블 버거(5400 / 7400)
	printf("어떤 햄버거를 드시겠습니까?\n");
	burger_ burger[6] = { "\n", 0, 0, "기본 햄버거", 3900, 5900, "치즈 햄버거", 4400, 6400, "새우 버거", 4900, 6900, "치킨 버거", 5400, 7400, "더블 버거", 5400, 7400 };
	for (int i = 1; i < 6; i++)
		printf("%d. %s \n", i, burger[i].name);
	scanf("%d", &b);

	//단품인지 세트인지 질문
	printf("\n단품을 드시겠습니까? 세트를 드시겠습니까?\n");
	scanf("%d", &c);
	if (c == 1) {
		printf("\n단품을 선택하셨습니다.\n");
		printf("가격은 %d원입니다.\n\n", burger[b].price1);

		//추가 메뉴 질문
		printf("추가 메뉴는 어떻게 하시겠습니까?\n");
		printf("1. 콜라->사이다(+0원)  2. 감자튀김->치즈볼(+1000원)\n");
		printf("(둘 다는 12를 누르세요.)\n");
		scanf("%d", &d);
		if (d == 1) {
			printf("\n최종 가격은 %d원입니다.\n\n", burger[b].price1);
		}
		else if (d == 2) {
			printf("\n최종 가격은 %d원입니다.\n\n", burger[b].price1 + 1000);
		}
		else if (d == 12) {
			printf("\n최종 가격은 %d원입니다.\n\n", burger[b].price1 + 1000);
		}
		else {
			printf("잘못된 정보를 입력했습니다. 다시 이용해 주시기 바랍니다.\n");
			return 0;
		}
	}

	else if (c == 2) {
		printf("\n세트를 선택하셨습니다.\n");
		printf("가격은 %d원입니다.\n\n", burger[b].price2);

		//추가 메뉴 질문
		printf("추가 메뉴는 어떻게 하시겠습니까?\n");
		printf("1. 콜라->사이다(+0원)  2. 감자튀김->치즈볼(+1000원)\n");
		printf("(둘 다는 12를 누르세요.)\n");
		scanf("%d", &d);
		if (d == 1) {
			printf("\n최종 가격은 %d원입니다.\n\n", burger[b].price2);
		}
		else if (d == 2) {
			printf("\n최종 가격은 %d원입니다.\n\n", burger[b].price2 + 1000);
		}
		else if (d == 12) {
			printf("\n최종 가격은 %d원입니다.\n\n", burger[b].price2 + 1000);
		}
		else {
			printf("잘못된 정보를 입력했습니다. 다시 이용해 주시기 바랍니다.\n");
			return 0;
		}
	}
	else {
		printf("잘못된 정보를 입력했습니다. 다시 이용해 주시기 바랍니다.\n");
		return 0;
	}

	//결제 수단 질문
	printf("\n결제 수단 : 1. 카드  2. 3성페이\n");
	scanf("%d", &e);
	if (e == 1) {
		printf("\n카드로 결제합니다. 카드를 화면의 옆 칸에 꽂아주시기 바랍니다.\n\n");
	}
	else if (e == 2) {
		printf("\n3성페이로 결제합니다. 밑 카메라에 핸드폰 화면을 대시기 바랍니다.\n\n");
	}
	else {
		printf("잘못된 정보를 입력했습니다. 다시 이용해 주시기 바랍니다.\n");
		return 0;
	}

	//설문 조사 참여 여부 질문
	printf("혹시 저희가 진행하고 있는 설문 조사에 참여해 주시겠습니까?\n");
	printf("설문 조사에서 질문은 총 두 개입니다.\n\n");
	printf("1. 예 2. 아니오\n");
	scanf("%d", &f);
	if (f == 1) {
		printf("\n저희의 설문 조사에 참여해 주셔서 감사합니다.\n");
	}
	else {
		printf("\n안녕히 가십시오. 다음에도 많은 이용 바랍니다.\n");
		return 0;
	}

	//설문 조사 1번
	printf("Q1. 성별이 어떻게 되십니까?\n");
	printf("1. 남자 2. 여자\n");
	scanf("%d", &g);
	if (g == 1 || g == 2) {
		printf("\n응답해 주셔서 감사합니다.\n");
	}
	else {
		printf("잘못된 답변을 해주셨습니다. 안녕히 가십시오. 다음에도 많은 이용 바랍니다.\n");
		return 0;
	}

	//설문 조사 2번
	printf("Q2. 연령대가 어떻게 되십니까?\n");
	printf("1. 10대\n2. 20대\n3. 30대\n4. 40대\n5. 50대 이상\n");
	scanf("%d", &h);
	if (h == 1 || h == 2 || h == 3 || h == 4 || h == 5) {
		printf("\n응답해 주셔서 감사합니다.\n");
	}
	else {
		printf("잘못된 답변을 해주셨습니다. 안녕히 가십시오. 다음에도 많은 이용 바랍니다.\n");
		return 0;
	}

	printf("설문해주신 답변으로 더 나은 RotteQueen이 되겠습니다.\n");
	printf("좋은 하루 되십시오. 다음에도 많은 이용 바랍니다.\n");
}