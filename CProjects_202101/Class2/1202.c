#include<stdio.h>

int mbti(int n);	//mbti조사 실행 함수
int survey1(int n);	//성격유형 E,I 구분 함수 
int survey2(int n);	//성격유형 S,N 구분 함수 
int survey3(int n);	//성격유형 T,F 구분 함수 
int survey4(int n);	//성격유형 P,J 구분 함수 
int scank(); //지정 외의 숫자 입력시 오류를 뜨게 해주는 함수
int dep();	//지정 외의 숫자 입력시 오류를 뜨게 해주는 함수	


int main()
{
	int g;

	g = 0;
	int n = 0;
	int mbti_1 = mbti(n);
	printf("다른 사람의 mbti도 검사 하시겠습니까? (끝내시려면 1을 눌러 주세요) > ");

	scanf("%d", &g);



	while (g != 1) {
		int g;
		g = 0;
		int n = 0;
		int mbti_1 = mbti(n);
		printf("다른 사람의 mbti도 검사 하시겠습니까? (끝내시려면 1을 눌러 주세요) > ");

		scanf("%d", &g);

		if (g == 1) {
			return 0;
		}
	}
}


int mbti(int n) {
	//프로그램 소개
	printf("\n당신의 성격유형을 검사해주는 프로그램 입니다.\n");
	printf("각 문항에 대한 답을 입력하고 Enter를 눌러주세요.\n");
	printf("각 질문에 대한 답은 숫자로만 입력해주세요\n");
	printf("1:전혀그렇지않다 2:그렇지않다 3:보통이다 4:그렇다 5:매우그렇다\n\n");

	//조사 결과 출력
	int ser1 = survey1(n);
	int ser2 = survey2(n);
	int ser3 = survey3(n);
	int ser4 = survey4(n);
	printf("\n당신의 mbti유형은 ");
	if (ser1 > 12.5)
		printf("I");
	else
		printf("E");

	if (ser2 > 12.5)
		printf("S");
	else
		printf("N");

	if (ser3 > 12.5)
		printf("T");
	else
		printf("F");

	if (ser4 > 12.5)
		printf("P");
	else
		printf("J");

	printf(" 입니다.\n\n");
}
int scank()
{
	int n = 0;
	scanf("%d", &n);
	if (n > 5 || n < 1)
	{
		printf("[error] 1~5번 중에서만 선택해주세요. > ");

		return 0;
	}
	else
		return n;
}

int dep()
{
	int nfromscan = scank();
	if (nfromscan == 0)
		dep();
	else
		return nfromscan;
}


int survey1(int n)
{
	//숫자가 12.5보다 클 경우 I
	int sum = 0;
	printf("나는 보통 대화를 먼저 시작하지 않는다 > ");
	sum += dep();
	printf("나는 주목받는 일에는 관심이 없다 > ");
	sum += dep();
	printf("재미있는 책이나 비디오 게임이 사교 모임이 더 낫다 > ");
	sum += dep();
	printf("방에 사람이 가득 찬 경우, 방의 중앙보다는 벽의 가까이에 자리합니다. > ");
	sum += dep();
	printf("다른사람들에게 자신을 소개하는 것을 어려워 합니다. > ");
	sum += dep();
	return sum;

}

int survey2(int n)
{
	//숫자가 12.5보다 클경우 S
	int sum = 0;
	printf("\n본인은 창의적이기보다 현실적인 사람이라고 생각합니다. > ");
	sum += dep();
	printf("공상과 아이디어 때문에 흥분하는 일은 없습니다. > ");
	sum += dep();;
	printf("꿈이 현실 세계와 사건에 중점을 두는 경향이 있습니다. > ");
	sum += dep();
	printf("자신의 행동이 다른 사람들에게 어떠한 영향을 주는 지에 대해 거의 걱정하지 않습니다. > ");
	sum += dep();
	printf("다른 사람들이 본인의 행동에 영향을 주는 것을 허용하지 않습니다. > ");
	sum += dep();
}

int survey3(int n)
{
	//숫자가 12.5보다 클경우 T
	int sum = 0;
	printf("\n중요한 결정을 내려야 할 때 일반적으로 가슴보다 논리가 중요합니다. > ");
	sum += dep();
	printf("논쟁에서 이기는 것이 상대방을 불쾌하지 않도록 하는 것보다 중요합니다. > ");
	sum += dep();
	printf("토론 시 사람들의 민감한 반응보다 보다 진실을 더 중요시해야 합니다. > ");
	sum += dep();
	printf("종종 다른 사람들의 감정에 공감하기가 어렵습니다. > ");
	sum += dep();
	printf("사람들 때문에 화나는 일이 거의 없습니다. > ");
	sum += dep();
}
int survey4(int n)
{
	//숫자가 12.5보다 클경우 P
	int sum = 0;
	printf("\n주의깊게 미리 계획하기 보다는 즉흥적으로 움직입니다. > ");
	sum += dep();
	printf("구체적인 계획을 갖고 시간을 보내기보다는 다소 즉흥적으로 움직입니다. > ");
	sum += dep();
	printf("업무 스타일이 체계적이고 조직적이라기보다는 그때그때 몰아서 처리하는 편입니다. > ");
	sum += dep();
	printf("종종 물건을 제자리에 두지 않습니다. > ");
	sum += dep();
	printf("시간이 부족할 때까지 일을 미우는 경향이 있습니다. > ");
	sum += dep();
}