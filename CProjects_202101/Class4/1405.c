#include <stdio.h>

//double : 소수 밑 수 사용 가능

int day();
int totalday(int, int, int);  // 년, 월, 일로 총 일 수를 구함

int main()
{
	float a;  // a : 키[m]
	float b;  // b : 몸무게[kg]

	printf("키[m] = ");  // 본인의 키 입력
	scanf("%f", &a);
	printf("몸무게[kg] = ");  // 본인의 몸무게 입력
	scanf("%f", &b);

	// 결과 출력
	if (b / (a * a) <= 18.5)
		printf("저체중입니다. 많이 먹으세요.\n\n");
	else if (18.5 < b / (a * a) && b / (a * a) <= 23)
		printf("정상입니다. 아주 좋아요.\n\n");
	else if (23 < b / (a * a) && b / (a * a) <= 25)
		printf("과체중입니다. 약간 위험해요.\n\n");
	else if (25 < b / (a * a) && b / (a * a) <= 30)
		printf("비만입니다. 살 빼세요.\n\n");
	else if (b / (a * a) > 30)
		printf("고도비만입니다. 심각하네요.\n\n");

	float c;  // c : 아버지의 키
	float d;  // d : 어머니의 키

	printf("아버지의 키[cm] = ");  // 아버지의 키 입력
	scanf("%f", &c);
	printf("어머니의 키[cm] = ");  // 어머니의 키 입력
	scanf("%f", &d);

	char m[6];  // 성별

	printf("man? or woman?");  // 본인의 성별 입력
	scanf("%s", m);

	if (m[0] == 'm', m[1] == 'a', m[2] == 'n')  // 남자일 때의 예상 키
		printf("당신의 예상 키는 %.2fcm입니다.\n\n", (c + d + 13) / 2);
	if (m[0] == 'w', m[1] == 'o', m[2] == 'm', m[3] == 'a', m[4] == 'n')  // 여자일 때의 예상 키
		printf("당신의 예상 키는 %.2fcm입니다.\n\n", (c + d - 13) / 2);

	printf("이번에는 우울증 테스트입니다.\n");  // 우울증 테스트
	printf("전혀 아니다: 0점, 가끔 그렇다: 1점, 자주 그렇다: 2점, 항상 그렇다: 3점\n");
	printf(" 1. 나는 슬프고 기분이 울적하다.\n 2. 나는 다른 삶에 비해 열등하고 뭔가 잘못되어 있다고 느껴진다.\n 3. 나는 쉽게 화가 나고 짜증이 난다.\n 4.나의 외모는 추하다고 생각한다.\n 5.성(SEX)에 대한 관심을 잃었다.\n");  // 문항

	int e;  //우울증 점수

	printf("당신의 점수는 몇 점입니까?(숫자만 입력)");  // 우울증 점수 출력
	scanf("%d", &e);

	if (0 <= e && e <= 3)
		printf("당신은 우울하지 않습니다.\n\n");
	else if (3 < e && e <= 6)
		printf("약간의 우울한 상태입니다.\n\n");
	else if (6 < e && e <= 10)
		printf("무시하기 힘든 우울함이 있습니다.\n\n");
	else if (10 < e && e <= 15)
		printf("심한 우울 상태입니다.\n\n");
	// 1차 제출-----------------------------------------------------------------------1차 제출

	int drink;  // 음료수의 종류
	printf("평소의 당 습관을 알아보는 시험입니다.\n");
	printf("1.탄산음료 2.버블티 3.이온음료 4. 과일음료\n");  // 음료수의 종류
	printf("가장 좋아하는 음료수 종류가 무엇입니까?");
	scanf("%d", &drink);

	switch (drink) {
	case 1:
		printf("탄산음료를 선택하셨군요. 많이 먹으면 몸이 안 좋아질 것입니다.\n\n");
		break;
	case 2:
		printf("버블티를 선택하셨군요. 거의 안 먹는게 건강에 도움이 됩니다.\n\n");
		break;
	case 3:
		printf("이온음료를 선택하셨군요. 당이 없는 건 아니지만 좋은 선택이에요.\n\n");
		break;
	case 4:
		printf("과일음료를 선택하셨군요. 최선의 선택이네요.\n\n");
		break;
	}

	day();  // 태어난 지 얼마나 되었는지 알려주는 함수
}

int day()
{
	int aY, aM, aD;  // 년, 월, 일 
	int bY, bM, bD;  // 년, 월, 일
	int aday, bday, cday;  // 총 일 수 

	// 입력
	printf("태어난 지 얼마나 되었는 지 알면 의미 있고 유용하겠죠?\n");
	printf("당신이 태어난 연도, 월, 일을 입력하시오. ");
	scanf("%d %d %d", &aY, &aM, &aD);
	printf("오늘의 연도, 월, 일을 입력하시오. ");
	scanf("%d %d %d", &bY, &bM, &bD);

	// 함수로 총일자 구함
	aday = totalday(aY, aM, aD);  // 총 일 
	bday = totalday(bY, bM, bD);  // 총 일 
	cday = bday - aday;

	// 결과 출력
	printf("태어난지 %d일 되셨습니다.\n", cday);

	printf("수고하셨습니다!");
	return 0;
}

int totalday(int year, int month, int day)  // 총 일 수를 구하는 함수
{
	int monthD[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int result = (year - 1) * 365 + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400;  // 작년까지 일자
	int m;
	for (m = 1; m < month; m++)  // 지난달까지 일자
		result = result + monthD[m];

	return result + day;  // 일자를 더해서 반환
}