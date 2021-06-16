#include <stdio.h>

void ProcessOfPurchasing(int a);
void ProcessOfCalculating();
void	ProcessOfSaving();


long long int price, a = 0;

int main()
{

	while (price <= 30000)
	{
		printf("안녕하세요. 광주과학고 매점입니다. 구매를 원한다면 1, 취소를 원한다면 2를 눌러주세요\n");
		scanf_s("%ld", &a);
		ProcessOfPurchasing(a);
		if (a == 1)
		{

			ProcessOfCalculating();
			ProcessOfSaving();
		}

	}




	return 0;
}




void ProcessOfPurchasing(int a)
{
	long long int  b = 0, c = 0, d = 0, cnt1 = 0, cnt2 = 0, cnt3 = 0, count1 = 0, count2 = 0, count3 = 0, m = 0;



	if (a == 1)
	{

		printf("구매하고 싶은 물건의 종류를 입력하세요.\n");
		printf("1. 아이스크림  2. 음료\n");
		scanf_s("%ld", &b);

		if (b == 1)
		{
			printf("아이스크림은 3종류가 있습니다.\n선택하세요.");
			printf("1. 막대아이스크림(800원) 2. 콘아이스크림(1200원) 3. 기타(1500원)\n");
			scanf_s("%ld", &c);

			if (c == 1)
			{
				printf("막대아이스크림을 선택하셨습니다.\n몇개를 구매하실 건가요? ");
				scanf_s("%ld", &cnt1);
				price += (800 * cnt1);
			}

			if (c == 2)
			{
				printf("콘아이스크림을 선택하셨습니다.\n몇개를 구매하실 건가요? ");
				scanf_s("%ld", &cnt2);
				price += (1200 * cnt2);
			}

			if (c == 3)
			{
				printf("기타에는 와, 쿠키오, 붕어싸만코가 있습니다.\n몇개를 구매하실 건가요? ");
				scanf_s("%ld", &cnt3);
				price += (1500 * cnt3);
			}

		}
		if (b == 2)
		{
			printf("음료에는 3가지 종류가 있습니다.\n선택하세요");
			printf("1. 캔음료(800원) 2. 병음료(1200원) 3. 페트병음료(1500원)\n");
			scanf_s("%ld", &d);

			if (d == 1)
			{
				printf("캔음료를 선택하셨습니다.\n몇개를 구매하실 건가요?");
				scanf_s("%ld", &count1);
				price += (800 * count1);
			}

			if (d == 2)
			{
				printf("병음료를 선택하셨습니다.\n몇개를 구매하실 건가요?");
				scanf_s("%ld", &count2);
				price += (1200 * count2);
			}

			if (d == 3)
			{
				printf("페트병음료를 선택하셨습니다.\n몇개를 구매하실 건가요?");
				scanf_s("%ld", &count3);
				price += (1500 * count3);
			}
		}

	}

	else
	{
		printf("감사합니다. 또 오세요.\n");
	}

}

void ProcessOfCalculating()
{
	int pay = 0, money;

	printf_s("총 가격은 %d원 입니다. \n", price);
	printf("얼마를 내실 건가요? ");
	scanf_s("%ld", &pay);

	money = pay - price;

	printf("거스름돈은 %d원입니다.\n\n", money);

	printf("10000원 %d장\n\n", money / 10000);

	money = money % 10000;

	printf("5천원 %d장\n\n", money / 5000);

	money = money % 5000;

	printf("1000원 %d장\n\n", money / 1000);

	money = money % 1000;

	printf("500원 %d개\n\n", money / 500);

	money = money % 500;

	printf("100원 %d개\n\n", money / 100);


}


void	ProcessOfSaving()
{
	int a = 0, n = 0, savingprice;

	printf("적립을 할 번호를 가지고 계시나요? 있다면 1, 없다면 0을 눌러주세요.\n");
	scanf_s("%ld", &a);

	if (a == 1)
	{
		printf("번호를 눌러주세요. ");
		scanf_s("%ld", &n);
		savingprice = price / 10;
		printf("\n%d원 적립되셨습니다. 또오세요.\n\n", savingprice);
	}

	if (a == 0)
	{
		printf("적립할 번호를 만들어주세요. 적립할 번호는 각 학급에서 부여한 번호입니다. ex --> 21ooo");
	}

}

