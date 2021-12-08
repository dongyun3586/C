#include <stdio.h>
#include <windows.h>
#include <string.h>
int programexplain(int* p);
void namecompatibility();
void character();
void annoytest();
void stresstest();
int main() {
	printf("1학년 1반 14번 전승원\n");
	Sleep(1000);
	printf("이 프로그램은 여러 가지 검사를 한번에 할 수 있는 프로그램입니다.");
	Sleep(2000);
	system("cls");
	int n = 0, a;
	a = programexplain(&n);//포인터를 통해 programexpllain함수에서 진행할 검사의 종류를 입력받는다.
	if (a == 1)//a의 값에 따라 4가지의 검사를 진행한다.
		character();
	if (a == 2)
		namecompatibility();
	if (a == 3)
		annoytest();
	if (a == 4)
		stresstest();
	return 0;
}
int programexplain(int* p) {
	printf("초간단 성격유형검사(MBTI)는 1번\n커플 이름궁합 검사는 2번\n분노조절장애 검사는 3번\n스트레스 지수 검사는 4번을 눌러주세요\n");
	scanf("%d", &(*p));
	if (*p != 1 && *p != 2 && *p != 3 && *p != 4) {
		printf("잘못된 입력입니다");
		Sleep(1000);
		system("cls");
		programexplain(p);//1~4의 숫자가 아닌 다른 숫자를 입력하면 잘못된 입력임을 알려주며 다시 입력받는다.
	}
	else
	{
		system("cls");
		return *p;
	}
}
void namecompatibility() {
	printf("안녕하세요. 이름궁합 검사를 하러 오신 당신을 환영합니다.\n");
	Sleep(1000);
	printf("\n\n이런 궁합검사, 재미로 하는거 아시죠?\n\n");
	Sleep(1000);
	printf("두 명의 이름을 입력하되, 키보드를 영어로 입력해주세요. ex)전승원-->wjstmddnjs\n\n");
	char arr[16], brr[16];
	int num = 0, k;
	scanf("%s", arr);
	scanf("%s", brr);
	system("cls");
	for (int i = 0; arr[i] != '\0'; i++)//입력받은 이름을 숫자로 변환한다.
	{
		if (arr[i] == 'r' || arr[i] == 'f' || arr[i] == 'l' || arr[i] == 'm')
			num += 1;
		else if (arr[i] == 's' || arr[i] == 'q' || arr[i] == 'z' || arr[i] == 'j' || arr[i] == 'u' || arr[i] == 'y' || arr[i] == 'n' || arr[i] == 'b' || arr[i] == 'p')
			num += 2;
		else if (arr[i] == 'e' || arr[i] == 'a' || arr[i] == 'k' || arr[i] == 'i' || arr[i] == 'h')
			num += 3;
		else
			num += 4;
	}
	for (int i = 0; brr[i] != '\0'; i++)
	{
		if (brr[i] == 'r' || brr[i] == 'f' || brr[i] == 'l' || brr[i] == 'm')
			num += 1;
		else if (brr[i] == 's' || brr[i] == 'q' || brr[i] == 'z' || brr[i] == 'j' || brr[i] == 'u' || brr[i] == 'y' || brr[i] == 'n' || brr[i] == 'b' || brr[i] == 'p')
			num += 2;
		else if (brr[i] == 'e' || brr[i] == 'a' || brr[i] == 'k' || brr[i] == 'i' || brr[i] == 'h')
			num += 3;
		else
			num += 4;
	}
	num %= 40;
	if (num == 0)
		num = 40;
	printf("숫자 : %d\n\n", num);
	switch (num)//1~40까지의 숫자를 switch문을 이용해 검사결과를 알려준다.
	{
	case 1:
		printf("이별하기 쉽대요 ㅠ\n"); break;
	case 2:
		printf("2년 이상 오래간대요!\n"); break;
	case 3:
		printf("완벽한 사랑이라네요\n"); break;
	case 4:
		printf("진실한 사랑이라네요\n"); break;
	case 5:
		printf("절교...\n"); break;
	case 6:
		printf("안타깝게 기다린대요 ㅠ\n"); break;
	case 7:
		printf("서로 사랑한대요 :)\n"); break;
	case 8:
		printf("짝사랑이네요..\n"); break;
	case 9:
		printf("죽을만큼 사랑한대요\n"); break;
	case 10:
		printf("서로 좋아한대요\n"); break;
	case 11:
		printf("거짓 사랑이라네요..\n"); break;
	case 12:
		printf("싫으면서도 좋대요\n"); break;
	case 13:
		printf("마음과 정반대네요\n"); break;
	case 14:
		printf("꼭 만날 인연이에요\n"); break;
	case 15:
		printf("남자가 여자땜에 우네요\n"); break;
	case 16:
		printf("무한질주 사랑!!\n"); break;
	case 17:
		printf("잠깐 좋은 사랑..\n"); break;
	case 18:
		printf("영원한 사랑!!\n"); break;
	case 19:
		printf("다시 사귄다네요\n"); break;
	case 20:
		printf("무조건 사랑한대요\n"); break;
	case 21:
		printf("이별,,\n"); break;
	case 22:
		printf("미래에 키스할 사이?!\n"); break;
	case 23:
		printf("잊을 수 없는 사랑\n"); break;
	case 24:
		printf("양다리\n"); break;
	case 25:
		printf("이제 곧 썸타네요\n"); break;
	case 26:
		printf("서로 사랑한대요\n"); break;
	case 27:
		printf("운명적 실수..?\n"); break;
	case 28:
		printf("서로에 대해서 잘 몰라요\n"); break;
	case 29:
		printf("결혼 가능!!\n"); break;
	case 30:
		printf("여자가 남자조심\n"); break;
	case 31:
		printf("여자가 더 이쁘대요..\n"); break;
	case 32:
		printf("남자가 여자조심\n"); break;
	case 33:
		printf("남자가 짝사랑..\n"); break;
	case 34:
		printf("여자가 남자땜에 우네요\n"); break;
	case 35:
		printf("깨지기 쉬워요..\n"); break;
	case 36:
		printf("어울리지 않는다네요\n"); break;
	case 37:
		printf("남자가 더 예쁘대요,,\n"); break;
	case 38:
		printf("비글미 커플!\n"); break;
	case 39:
		printf("여자가 짝사랑..ㅠ\n"); break;
	case 40:
		printf("평생 갈 사이네요 :)\n"); break;
	}
	printf("\n\n검사지 출처 : www.instagram.com\n\n");
}
void character() {
	int num = 0, p;
	printf("안녕하세요. 굉장히 간단한 성격검사를 하러 오신 당신을 환영합니다.\n");
	Sleep(1000);
	printf("\n\n이런 검사, 참고만 해주세요!+대학생 전용 검사입니다;;  :)\n\n");
	Sleep(2000);
	system("cls");
	printf("MT, 3학년인데도 간다/2학년 때도 갈까 말까-->전자:1, 후자:2\n");
	scanf("%d", &p);
	if (p == 2) num += 1;
	printf("공부, 노트에 써가면서 무작정 외움/이해할때까지 텍스트 쳐다봄-->전자:1, 후자:2\n");
	scanf("%d", &p);
	if (p == 2) num += 2;
	printf("지금, 이거 보면서 \"미친 나다\"하는중/\"엥 이건 아닌데\"하면서 보고 있음-->전자:1, 후자:2\n");
	scanf("%d", &p);
	if (p == 2) num += 4;
	printf("과제, 과제 다하고 놈/놀고나서 과제함-->전자:1, 후자:2\n");
	scanf("%d", &p);
	if (p == 2) num += 8;
	Sleep(1000);
	system("cls");
	printf("당신의 MBTI는.....\n\n");
	Sleep(2000);
	switch (num)//0~15까지의 num에 따라 검사결과를 알려준다.
	{
	case 0: printf("ESFJ"); break;
	case 1: printf("ISFJ"); break;
	case 2: printf("ENFJ"); break;
	case 3: printf("INFJ"); break;
	case 4: printf("ESTJ"); break;
	case 5: printf("ISTJ"); break;
	case 6: printf("ENTJ"); break;
	case 7: printf("INTJ"); break;
	case 8: printf("ESFP"); break;
	case 9: printf("ISFP"); break;
	case 10: printf("ENFP"); break;
	case 11: printf("INFP"); break;
	case 12: printf("ESTP"); break;
	case 13: printf("ISTP"); break;
	case 14: printf("ENTP"); break;
	case 15: printf("INTP"); break;
	}
	printf("입니다!!\n\n검사지 출처 : www.instagram.com");
}
void annoytest()
{
	printf("안녕하세요. 분노조절검사를 하러 오신 당신을 환영합니다.\n");
	Sleep(1000);
	system("cls");
	printf("주어질 14개의 질문에 대해 맞다고 생각하면 1, 아니라고 생각한다면 0을 눌러주세요\n\n");
	Sleep(3000);
	int num = 0, a = 1;
	{
		printf("화를 잘 내며 성격이 급하다.\n");
		scanf("%d", &a);
		num += a;
		printf("평상시에 작은 일에도 자주 욱한다.\n");
		scanf("%d", &a);
		num += a;
		printf("화가 나면 스스로 조절하지 못한다.\n");
		scanf("%d", &a);
		num += a;
		printf("잘한 일에 칭찬이나 적절한 보상이 없을 시 몹시 화가 난다.\n");
		scanf("%d", &a);
		num += a;
		printf("타인의 잘못을 비판하고 꼬집어 말해서 충돌이 생긴다.\n");
		scanf("%d", &a);
		num += a;
		printf("화가 나면 물건을 부수거나 던진다.\n");
		scanf("%d", &a);
		num += a;
		printf("분노 상태에서 폭언이나 폭력을 사용한다.\n");
		scanf("%d", &a);
		num += a;
		printf("화가 너무 많이 나서 눈물이 난 적이 있다.\n");
		scanf("%d", &a);
		num += a;
		printf("자기 잘못을 다른 사람의 잘못으로 돌린 적이 있다.\n");
		scanf("%d", &a);
		num += a;
		printf("다른 사람들이 자신을 무시하는 것 같다.\n");
		scanf("%d", &a);
		num += a;
		printf("억울하다는 생각이 종종 든다.\n");
		scanf("%d", &a);
		num += a;
		printf("화를 참지 못해서 중요한 일을 망친적이 있다.\n");
		scanf("%d", &a);
		num += a;
		printf("게임을 하던 중에 자신의 마음대로 되지 않아서 화를 낸 적이 있다.\n");
		scanf("%d", &a);
		num += a;
		printf("하던 일이 잘 풀리지 않을 때 쉽게 좌절하고 포기한다.\n");
		scanf("%d", &a);
		num += a;
	}
	system("cls");
	if (num <= 4)//num의 크기에 따라 검사 결과를 3가지 경우로 나눠 알려준다.
		printf("스스로 분노조절이 가능한 정도입니다!");
	else if (num <= 9)
		printf("도움이 필요한 정도이며 스스로 분노조절을 잘하지 못하는 상태에요..");
	else
		printf("전문가와의 상담이 필요해요");
	printf("\n\n검사지 출처 : https://blog.naver.com/aescular/222485306154 \n\n");
}
void stresstest()
{
	printf("안녕하세요. 스트레스 검사를 하러 오신 당신을 환영합니다.\n");
	Sleep(1000);
	system("cls");
	printf("주어질 10개의 검사문항에 대해, '지난 한 달 동안' \n 전혀없다:0, 거의 드물게:1, 가끔:2, 자주:3, 매우 자주:4 를 눌러주세요\n\n");
	Sleep(4000);
	int num = 0, a;
	{
		printf("1. 예상치 못한 일이 생겨서 기분 나빠진 적이 얼마나 있었나요?\n");
		scanf("%d", &a);
		num += a;
		printf("2. 중요한 일들을 통제할 수 없다고 느낀 적은 얼마나 있었나요?\n");
		scanf("%d", &a);
		num += a;
		printf("3. 초조하거나 스트레스가 쌓인다고 느낀 적은 얼마나 있었나요?\n");
		scanf("%d", &a);
		num += a;
		printf("4. 짜증나고 성가신 일들을 성공적으로 처리한 적이 얼마나 있었나요?\n");
		scanf("%d", &a);
		num += a;
		printf("5. 생활 속에서 일어난 중요한 변화들을 효과적으로 대처한 적이 얼마나 있었나요?\n");
		scanf("%d", &a);
		num += a;
		printf("6. 개인적인 문제를 처리하는 능력에 대해 자신감을 느낀 적은 얼마나 있었나요?\n");
		scanf("%d", &a);
		num += a;
		printf("7. 자신의 뜻대로 일이 진행된다고 느낀 적은 얼마나 있었나요?\n");
		scanf("%d", &a);
		num += a;
		printf("8. 매사를 잘 컨트롤하고 있다고 느낀 적이 얼마나 있었나요?\n");
		scanf("%d", &a);
		num += a;
		printf("9. 당신이 통제할 수 없는 범위에서 발생한 일 때문에 화가 난 적이 얼마나 있었나요?\n");
		scanf("%d", &a);
		num += a;
		printf("10. 어려운 일이 너무 많이 쌓여서 극복할 수 없다고 느낀 적이 얼마나 있었나요?\n");
		scanf("%d", &a);
		num += a;
	}
	system("cls");
	if (num <= 12)//num의 값에 따라 결과를 4가지 경우로 나누어서 검사결과를 알려준다.
		printf("스트레스 정도는 정상적인 수준으로 심리적으로 안정되어 있어요");
	else if (num <= 19)
		printf("약간의 스트레스를 받고 있으나 심각한 수준은 아닌 것으로 보여요. 이를 해소하기 위해 운동, 예술 활동 등 자신만의 방법을 찾는 것도 좋습니다");
	else if (num <= 25)
		printf("중간 정도의 스트레스를 받고 있는 것으로 보이며 이를 해소하기 위한 적극적인 노력이 필요해요.	스스로 필요 하다고 생각되면 전문가 상담을 신청해보시면 됩니다​");
	else
		printf("심한 스트레스를 받고 있어 일상 생활에 어려움을 겪고 있을 것으로 판단되므로, 가능한 빨리 전문가의 도움을 받기를 권유해요");
	printf("\n\n검사지 출처 : https://blog.naver.com/danica11/222463267642 \n\n");
}