#include <stdio.h>

void time() //시간대 선택을 출력하는 함수
{
	int t;
	printf("시간대: \n");
	printf("1. 08:40\n2. 11:20\n3. 14:10\n4. 15:30\n");
	printf("가능한 시간을 선택해주세요: ");
}

void num() // 인원수 선택을 출력하는 함수
{
	int n;
	printf("*4명 이상 관람 시 1인당 10% 할인 중*\n한 명당 10000원\n");
	printf("관람하실 인원수를 선택해주세요: ");
}

void seat() // 좌석 선택을 출력하는 함수
{
	int arr[4][5] = { 0, }, k = 0;
	printf("좌석: \n");
	// 좌석을 직사각형 모양으로 출력 
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			arr[i][j] = k;
			printf("%3d", arr[i][j]);
			k++;
		}
		printf("\n");
	}
	printf("원하는 좌석을 선택하세요: ");

}

void printTime(int t) // 예매한 내용을 보여줄 때 시간대를 출력하기 위한 함수
{
	if (t == 1)
		printf("08:40");
	else if (t == 2)
		printf("11:20");
	else if (t == 3)
		printf("14:10");
	else
		printf("15:30");
}

int price(int n) // 금액을 계산하는 함수
{
	int p;
	if (n >= 4)
		p = 10000 * 0.9 * n; // 4명 이상 예매하면 10% 할인되므로 0.9를 곱함
	else
		p = 10000 * n;
	return p;
}

void movie(int n) // 영화 제목을 출력하는 함수
{
	if (n == 1)
		printf("컨저링 3\n");
	else if (n == 2)
		printf("크루엘라\n");
	else if (n == 3)
		printf("분노의 질주: 더 얼티메이트\n");
	else if (n == 4)
		printf("파이프라인\n");
	else
		printf("극장판: 귀멸의 칼날\n");
}


int main()
{
	int a; // 첫 화면에서 영화 선택할 때 입력받는 변수
	int t, n, s, pay; // 시간, 인원수, 좌석번호, 금액 변수
	int A[20] = { 0, }, B[20] = { 0, }, C[20] = { 0, }, D[20] = { 0, }, E[20] = { 0, };
	int countA[20] = { 0, }, countB[20] = { 0, }, countC[20] = { 0, }, countD[20] = { 0, }, countE[20] = { 0, }; // 좌석 선택시 겹침 여부를 확인하기 위해 각 영화 별로 배열을 만들고 그 개수를 세는 배열 만듦.
	while (1) {
		printf("***영화예매프로그램***\n\n");
		printf("상영 중인 영화\n");
		printf("1. 컨저링3\n");
		printf("2. 크루엘라\n");
		printf("3. 분노의 질주: 더 얼티메이트\n");
		printf("4. 파이프라인\n");
		printf("5. 극장판: 귀멸의 칼날\n");
		printf("6. 종료\n");
		printf("원하는 영화를 선택하세요: ");
		scanf("%d", &a);
		if (a == 6)
			break; // 종료 누르면 while문을 빠져나가서 프로그램 종료됨
		movie(a);
		time();
		scanf("%d", &t);
		num();
		scanf("%d", &n);
		switch (a)
		{
		case 1:
			seat();
			for (int i = 0; i < n; i++)
			{
				scanf("%d", &A[i]); // 배열에 좌석 번호 입력받음
				if (countA[A[i]] == 1) // 개수 세는 배열에 1이 있으면 예매된 좌석이므로 다른 좌석 선택 입력 받음
				{
					printf("%d번은 이미 예매된 좌석입니다 다른 좌석을 선택해주세요.\n", A[i]);
					scanf("%d", &A[i]);
				}

				countA[A[i]]++; // 입력된 좌석 번호는 예매된 좌석이 될 것이므로 구분하기 위해 1을 더해줌
			}
			movie(a);
			printTime(t);
			printf("  %d  ", n);
			for (int i = 0; i < n; i++)
				printf("%d ", A[i]);
			break;
		case 2:
			seat();
			for (int i = 0; i < n; i++)
			{
				scanf("%d", &B[i]);
				if (countB[B[i]] == 1)
				{
					printf("%d번은 이미 예매된 좌석입니다 다른 좌석을 선택해주세요.\n", B[i]);
					scanf("%d", &B[i]);
				}

				countB[B[i]]++;
			}
			movie(a);
			printTime(t);
			printf("  %d  ", n);
			for (int i = 0; i < n; i++)
				printf("%d ", B[i]);
			break;
		case 3:
			seat();
			for (int i = 0; i < n; i++)
			{
				scanf("%d", &C[i]);
				if (countC[C[i]] == 1)
				{
					printf("%d번은 이미 예매된 좌석입니다 다른 좌석을 선택해주세요.\n", C[i]);
					scanf("%d", &C[i]);
				}

				countC[C[i]]++;
			}
			movie(a);
			printTime(t);
			printf("  %d  ", n);
			for (int i = 0; i < n; i++)
				printf("%d ", C[i]);
			break;
		case 4:
			seat();
			for (int i = 0; i < n; i++)
			{
				scanf("%d", &D[i]);
				if (countD[D[i]] == 1)
				{
					printf("%d번은 이미 예매된 좌석입니다 다른 좌석을 선택해주세요.\n", D[i]);
					scanf("%d", &D[i]);
				}

				countD[D[i]]++;
			}
			movie(a);
			printTime(t);
			printf("  %d  ", n);
			for (int i = 0; i < n; i++)
				printf("%d ", D[i]);
			break;
		case 5:
			seat();
			for (int i = 0; i < n; i++)
			{
				scanf("%d", &E[i]);
				if (countE[E[i]] == 1)
				{
					printf("%d번은 이미 예매된 좌석입니다 다른 좌석을 선택해주세요.\n", E[i]);
					scanf("%d", &E[i]);
				}

				countE[E[i]]++;
			}
			movie(a);
			printTime(t);
			printf("  %d  ", n);
			for (int i = 0; i < n; i++)
				printf("%d ", E[i]);
			break;
		}
		printf("가격:%d\n", price(n));
		printf("해당 금액을 입력해주세요: ");
		scanf("%d", &pay);
		if (pay == price(n)) // 최종 금액과 입력된 금액이 같으면 예매 완료
			printf("\n***예매가 완료되었습니다***\n\n");
		if (pay<price(n) || pay>price(n))
		{
			while (pay != price(n)) // 입력된 금액과 최종 금액이 같아질 때까지 다시 입력 받음
			{
				printf("금액이 맞지 않습니다.다시 입력해주세요:");
				scanf("%d", &pay);
			}
			printf("\n***예매가 완료되었습니다***");
		}
	}
}
