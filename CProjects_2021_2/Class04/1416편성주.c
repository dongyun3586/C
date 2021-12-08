#include<stdio.h>
#include<string.h>
int main()
{
	int money;
	printf("현재 당신이 가지고 있는 금액을 입력하시오:");
	scanf_s("%d", &money);
	printf("<치킨류>\n");
	char* chicken[6] = { "[1 포켓 데리야끼]", "[2 포켓 양념]", "[3 포켓 프라이드]", "[4 포켓 양파]", "[5 하림 숯불갈비]", "[6 하림 간장]" }; //치킨의 번호와 이름을 저장하는 포인터 배열
	for (int i = 0; i < 4; i++)
	{
		printf("%s ", chicken[i]);
		printf("3000원\n");
	}
	for (int i = 4; i < 6; i++)
	{
		printf("%s ", chicken[i]);
		printf("4000원\n");
	} //치킨의 이름과 가격을 출력
	printf("[7 더 이상 구매 안 함]\n");
	int chickennum;
	int chickenbuy[10] = { 0 }; //구매한 순서에 따라 구매한 치킨의 번호를 저장하는 함수. 첫 번째 구매한 치킨이 포켓 양파라면 chickenbuy[0]=4가 됌.
	if (money >= 3000)
	{
		for (int i = 0; i < 10; i++)
		{
			printf("구매하고 싶은 치킨의 번호를 입력하시오:");
			scanf_s("%d", &chickennum);
			if (chickennum == 1 || chickennum == 2 || chickennum == 3 || chickennum == 4)
			{
				money = money - 3000;
				chickenbuy[i] = chickennum;
			}
			if (chickennum == 5 || chickennum == 6)
			{
				money = money - 4000;
				chickenbuy[i] = chickennum;
			}
			if (chickennum == 7 || money < 3000)break;
		}
	}//구매하고 싶은 치킨의 번호를 입력하면 chickenbuy에 이를 저장
	printf("<아이스크림류>\n");
	char* icecream[5] = { "[1 슈퍼콘]", "[2 월드콘]", "[3 요맘때]", "[4 메로나]", "[5 돼지바]" }; //아이스크림의 번호와 이름을 저장하는 포인터 배열
	for (int i = 0; i < 3; i++)
	{
		printf("%s ", icecream[i]);
		printf("1200원 \n");
	}
	for (int i = 3; i < 5; i++)
	{
		printf("%s", icecream[i]);
		printf("800원 \n");
	}//아이스크림의 이름과 가격을 출력

	printf("[6 더 이상 구매 안 함]\n");
	int j = 0;
	int icecreambuy[10] = { 0 };
	while (j == 0)
	{
		int icecreamnum;

		printf("구매하고 싶은 아이스크림의 번호를 입력하시오: ");
		scanf_s("%d", &icecreamnum);
		switch (icecreamnum)
		{
		case 1:
			icecreambuy[0]++;
			money = money - 1200;
			break;
		case 2:
			icecreambuy[1]++;
			money = money - 1200;
			break;
		case 3:
			icecreambuy[2]++;
			money = money - 1200;
			break;
		case 4:
			icecreambuy[3]++;
			money = money - 800;
			break;
		case 5:
			icecreambuy[4]++;
			money = money - 800;
			break;
		case 6:
			j = 1;
			break;
		default:
			printf("잘못 입력하셨습니다\n");
			break;
		}
	}//치킨과는 다른 매커니즘. 1번 아이스크림의 구매한 횟수는 icecreambuy[0]에 저장됨.

	printf("<사탕류>\n");
	int i = 1;
	int candynum;
	int candybuy[10] = { 0 };

	char* candy[5] = { "[1 마이쮸]", "[2 새콤달콤]", "[3 송이버섯]", "[4 하리보]" }; //캔디의 번호와 이름을 저장하는 포인터 배열
	printf("%s ", candy[0]);
	printf("800원 \n");
	printf("%s", candy[1]);
	printf("600원 \n");
	for (int i = 2; i < 4; i++)
	{
		printf("%s", candy[i]);
		printf("200원 \n");
	}//캔디의 이름과 가격을 출력
	printf("[5 더 이상 구매 안 함]\n");
	while (i == 1)
	{
		printf("구매하고 싶은 사탕의 번호를 입력하시오: ");
		scanf_s("%d", &candynum);
		switch (candynum)
		{
		case 1:
			candybuy[0]++;
			money = money - 800;
			break;
		case 2:
			candybuy[1]++;
			money = money - 600;
			break;
		case 3:
			candybuy[2]++;
			money = money - 200;
			break;
		case 4:
			candybuy[3]++;
			money = money - 200;
			break;
		case 5:
			i = 0;
			break;
		default:
			printf("잘못 입력하셨습니다\n");
			break;
		}
	}//구매한 캔디의 종류별 구매된 횟수를 candybuy배열에 저장
	printf("<영수증>\n"); //영수증 출력
	printrecipe(chickenbuy, icecreambuy, candybuy, chicken, icecream, candy);
	printf("당신은 치킨으로 %d칼로리, 아이스크림으로 %d칼로리, 캔디로 %d 칼로리를 섭취하여 총 %d 칼로리를 섭취하셨습니다\n", calculatechicken(chickenbuy), calculateicecream(icecreambuy), calculatecandy(candybuy), calculatechicken(chickenbuy) + calculateicecream(icecreambuy) + calculatecandy(candybuy));
	printf("남은 돈은 %d원 입니다", money);
}
int calculatechicken(int* chickenbuy)
{
	int count1 = 0, count2 = 0, count3 = 0, count4 = 0, count5 = 0, count6 = 0;
	for (int i = 0; i < 10; i++)
	{
		if (chickenbuy[i] == 1)count1++;
		if (chickenbuy[i] == 2)count2++;
		if (chickenbuy[i] == 3)count3++;
		if (chickenbuy[i] == 4)count4++;
		if (chickenbuy[i] == 5)count5++;
		if (chickenbuy[i] == 6)count6++;
	}
	return count1 * 405 + count2 * 485 + count3 * 465 + count4 * 505 + count5 * 600 + count6 * 600;
}//구매한 치킨 열량 계산 함수
int calculateicecream(int* icecreambuy)
{
	int count1 = 0, count2 = 0, count3 = 0, count4 = 0, count5 = 0;
	for (int i = 0; i < 10; i++)
	{
		if (icecreambuy[i] == 1)count1++;
		if (icecreambuy[i] == 2)count2++;
		if (icecreambuy[i] == 3)count3++;
		if (icecreambuy[i] == 4)count4++;
		if (icecreambuy[i] == 5)count5++;
	}
	return 265 * count1 + 255 * count2 + 240 * count3 + 165 * count4 + 120 * count5;
}//구매한 아이스크림 열량 계산 함수
int calculatecandy(int* candybuy) {

	return 175 * candybuy[0] + 125 * candybuy[1] + 200 * candybuy[2] + 50 * candybuy[3];
}//구매한 캔디 열량 계산 함수
int printrecipe(int* chickenbuy, int* icecreambuy, int* candybuy, char** chicken, char** icecream, char** candy)
{
	int count1 = 0, count2 = 0, count3 = 0, count4 = 0, count5 = 0, count6 = 0;
	for (int i = 0; i < 10; i++)
	{
		if (chickenbuy[i] == 1)count1++;
		if (chickenbuy[i] == 2)count2++;
		if (chickenbuy[i] == 3)count3++;
		if (chickenbuy[i] == 4)count4++;
		if (chickenbuy[i] == 5)count5++;
		if (chickenbuy[i] == 6)count6++;
	}
	int count[6] = { count1, count2, count3, count4, count5, count6 };
	for (int i = 0; i < 6; i++)
	{
		if (count[i] != 0)
		{
			printf("%s %d개 \n", chicken[i], count[i]);
		}
	}
	for (int i = 0; i < 6; i++)
	{
		if (icecreambuy[i] != 0)
		{
			printf("%s %d개 \n", icecream[i], icecreambuy[i]);
		}
	}
	for (int i = 0; i < 5; i++)
	{
		if (candybuy[i] != 0)
		{
			printf("%s %d개 \n", candy[i], candybuy[i]);
		}
	}
	return 0;
}//영수증 출력 함수