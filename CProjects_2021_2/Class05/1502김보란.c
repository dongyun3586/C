#include <stdio.h>
#include <string.h>//printPot에서 strlen 이용하기 위함//
#include <stdlib.h>//_sleep 이용하기 위함
#include <windows.h>//콘솔창 크기 정하기 위함

void start();
void printPoint();
void spring();
void grow();
void result();
void printPot(int which, char* name);
void printUserBox1(int* word);
void printUserBox2(char* words);

char name[10] = { 0 };
int point = 0, ans, num = 1;

int main() {
	system("mode con cols=52 lines=50"); //콘솔창 크기 정하기
	start(); //키우기 시작
	spring(); //싹 틔우기
	grow(); //자라기
	result(); //결과(point)
	return 0;
}

void printPoint() {
	printf("                                        point:%d\n", point);
} //현재 포인트 출력

void printPot(int which, char* name) {
	int n = strlen(name);

	if (which == 0) {//기본 화분
		printf("_____________\n");
		printf("|___________|\n");
		printf(" ＼        /\n");
		printf("  |       |\n");
		printf(" _|_______|_\n");
		printf("'----' '----'\n");
		return 0;
	}

	else if (which == 1) {//초반에 void start에서 화분 고를 때 출력
		printf("_____________ _____________\n");
		printf("|___________| |___________|\n");
		printf(" ＼       ／   ＼       ／\n");
		printf("  |       |     |       |\n");
		printf(" _|_______|_   _|_______|_\n");
		printf("'----' '----' '-----------'\n");
		return 0;
	}

	else if (which == 2) {//이름이 있는 기본 화분
		printf("_____________\n");
	}

	else if (which == 3) {//물주기 화분
		printf("           . .       o\n");
		printf("      ．˙˙．˙-./'''''＼_\n");
		printf("   ·  ·  ．   ＼|▒ ▒ ▒ |))\n");
		printf(" ．  ．   ．      |▒ ▒ ▒ |´\n");
		printf("_____________\n");
	}

	else if (which == 4) {//씨앗에 빛 X 경우
		printf("		 +    -=+.  +\n");
		printf("		    +   | ＼  ·\n");
		printf("		+ ·    |  |\n");
		printf("		  .  __/   /  +\n");
		printf("		   ＼____,' + ·\n");
		printf("_____________   +       ·\n");
	}
	else if (which == 5) {//씨앗에 빛 주는 경우
		printf("	       + + + \n");
		printf("	    +  .----. +\n");
		printf("	   + /       ＼+\n");
		printf("	   + | ■==■ | +\n");
		printf("	    +＼ _~~_ / +\n");
		printf("_____________ + + + +\n");
	}

	else if (which == 6) {//새싹 화분
		printf("     (Y)\n");
		printf("______|______\n");
	}

	printf("|");//이름 출력
	for (int i = (11 - n) / 2; i > 0; i--)
		printf("_");//_을 절반 출력하고
	printf("%s", name);//이름 출력하고
	n = (11 - n) / 2;
	while (n + 1) {//나머지 _ 출력
		printf("_");
		n--;
	}
	printf("|\n");	//화분 아래쪽 출력 (which=0또는1을 제외하면 아래쪽이 같으므로)
	printf(" ＼        /\n");
	printf("  |       |\n");
	printf(" _|_______|_\n");
	printf("'----' '----'\n");
}

void printUserBox1(int* word) {//번호를 물을 때 사용하는 입력 박스
	int s = 0, n = 51;
	printf(" __________________________________________________\n");
	printf("|");
	scanf("%d", &s);//번호 입력받기
	*word = s;//포인터 이용해 반환
	while (n) {
		printf(" ");
		n--;
	}
	printf("|\n|__________________________________________________|");//박스 닫기
}

void printUserBox2(char* words) {//문자열을 입력받을 때 사용하는 입력 박스
	printf(" __________________________________________________\n");
	printf("|");
	scanf("%s", words);
	int num = 51;
	while (num) {
		printf(" ");
		num--;
	}
	printf("|\n|__________________________________________________|");
}

void start() {
	printPoint();
	printf("환영합니다!\n");
	printf("화분을 골라주세요\n\n\n      1             2\n");//화분 고르기
	printPot(1, &name);
	printf("\n\n");
	printUserBox1(&ans);
	while (ans == 2) {
		printf("\n물구멍이 없는 화분은 식물을 키우기에 좋지 않습니다\n다시 골라주세요(-10p)\n\n");
		printUserBox1(&ans);
		num = 0;//한 번 틀린 후 맞으면 점수 부여 X,  한번에 맞아야만 point 증가
		point -= 10;//여러번 틀리면 여러번 점수 감소
	}
	if (num = 0) {
		printf("좋은 화분은 골랐군요");//포인트 증가 X
		_sleep(1500);//1.5초 대기
		system("cls");//화면 지우기
	}
	else {
		printf("좋은 화분은 골랐군요(+15p)");//포인트 증가
		point += 15;
		_sleep(1500);
		system("cls");
	}
	point = point - 10 * num;//점수 차감

	printPoint();//식물 이름붙이기
	printf("식물에게 이름을 붙여주세요\n(길이 제한 영문 10자 한글 5자)\n\n\n");
	printPot(2, &name);
	printUserBox2(&name);
	printf("멋진 이름이에요");
	_sleep(1500);
	system("cls");

	printPoint();//키우기 시작
	printf("어떤 생명이든 애정을 담아 키웁시다\n%s은(는) 사랑을 받으며 자랄 것입니다\n\n이제 싹을 틔워봅시다(yes/no)\n\n\n", name);
	printPot(2, &name);
	char wouldYou[5];
	printUserBox2(&wouldYou);
	while (wouldYou[0] != 'y') {
		printf("%s가(이) 당신을 원망합니다\n다시 한 번 생각해볼까요?(-5p)\n", name);
		point -= 5;
		printUserBox2(&wouldYou);
	}
	if (wouldYou[0] == 'y') {
		printf("시작합시다");
		_sleep(1500);
		system("cls");
	}
}

void spring() {
	printPoint();//씨앗 심기
	printf("      ¤\n\n\n\n");
	printPot(2, &name);
	_sleep(300);
	system("cls");
	printPoint();
	printf("\n      ¤\n\n\n");
	printPot(2, &name);
	_sleep(300);
	system("cls");
	printPoint();
	printf("\n\n      ¤\n\n");
	printPot(2, &name);
	_sleep(300);
	system("cls");
	printPoint();
	printf("\n\n\n      ¤\n");
	printPot(2, &name);
	_sleep(300);
	system("cls");

	num = 1;//num 초기화
	printPoint();//1. 물을 얼마나 줄 것인가?
	printf("씨앗을 심었습니다\n물을 얼마나 줘야 하나요?\n\n1. 흙의 표면이 촉촉~하게 분사해주기\n2. 아직 싹이 안났으니까, 씨앗 주변만 집중적으로\n3. 물이 스미는 걸 확인할 수 있을만큼 듬뿍\n\n\n");
	printPot(2, &name);
	printUserBox1(&ans);
	while (ans != 3) {
		num = 0;
		if (ans == 1) {
			printf("흙은 생각보다 빨리 마릅니다(-10p)\n");
			point = point - 10;
			printUserBox1(&ans);
		}
		else if (ans == 2) {
			printf("국지성 홍수는 대부분의 경우 기피됩니다(-10p)\n");
			point = point - 10;
			printUserBox1(&ans);
		}
	}
	if (num) {
		point += 20;
		printf("수분이 충분한 상태를 유지합니다(+20p)");
	}
	else printf("수분이 충분한 상태를 유지합니다");
	_sleep(1500);
	system("cls");

	num = 1;//2. 물을 얼마나 자주 줄 것인가?
	printPoint();
	printf("물을 얼마나 자주 줄 건가요?\n\n1. 하루 한 번 이상\n2. 이틀에 한 번\n3. 일주일에 한 번\n\n\n");
	printPot(2, &name);
	printUserBox1(&ans);
	while (ans != 1) {
		num = 0;
		if (ans == 2) {
			printf("씨앗은 생각보다 물을 많이 원합니다(-5p)\n");
			point = point - 5;
			printUserBox1(&ans);
		}
		else if (ans == 3) {
			printf("다시 한 번 생각해보세요(-10p)\n");
			point = point - 10;
			printUserBox1(&ans);
		}
	}
	if (num) {
		point = point + 10;
		printf("흙이 마르지 않게 합니다(+10p)");
	}
	else printf("흙이 마르지 않게 합니다");
	_sleep(1500);
	system("cls");
	printPot(3, &name);//물주기 화분 출력
	_sleep(1500);
	system("cls");

	printPoint();	//3. 해를 얼마나 쬐어줄 것인가?
	printf("해를 얼마나 쬘 수 있게 할건가요?\n\n1. 전혀\n2. 반나절\n\n\n");
	printPot(2, &name);
	printUserBox1(&ans);
	printf("사실 둘 다 정답입니다\n어떤 씨앗은 빛을 받아야 싹을 잘 틔우고 어떤 것들은 그 반대입니다(+5p)\n");
	point += 5;
	_sleep(3000);
	system("cls");
	if (ans == 1)
		printPot(4, &name);//달 화분 출력
	else printPot(5, &name);//해 화분 출력
	_sleep(1500);
	system("cls");

	num = 1;
	printPoint();//4. 통풍은 어떻게 할 것인가?
	printf("통풍은 어떻게 할까요?\n\n1. 통풍이 잘 되지 않게 한다\n2. 통풍이 되도록 한다\n\n\n");
	printPot(2, &name);
	printUserBox1(&ans);
	while (ans == 2) {
		printf("흙 표면이 촉촉하게 유지되어야 하는데 통풍이 잘 되면 건조해지기 쉽습니다(-5p)\n");
		point -= 5;
		num = 0;
		printUserBox1(&ans);
	}
	if (num) {
		point += 10;
		printf("때론 표면을 타올이나 랩으로 덮어주기도 합니다(+10p)");
	}
	else printf("때론 표면을 타올이나 랩으로 덮어주기도 합니다");
	_sleep(2000);
	system("cls");

	char hi[100] = { 0 };//식물에게 인사하기
	printPoint();
	printf("이제 모든 준비가 끝났습니다\n%s을(를) 기다려줍시다\n\n\n", name);
	printPot(2, &name);
	_sleep(2000);
	system("cls");
	printPoint();
	printf("\n      ...LATER...\n\n\n");
	printPot(2, &name);
	_sleep(3000);
	system("cls");
	printPoint();
	printf("%s이(가) 깨어났습니다!\n조그만 싹에게 짤막한 인사를 건네봅시다\n\n\n", name);
	printPot(6, &name);
	printUserBox2(&hi);
	_sleep(2000);
	system("cls");
}

void grow() {
	num = 1;//새싹 화분 장소 정하기
	printPoint();
	printf("%s을(를) 어디에 둘까요?\n\n1. 직사광선이 내리쬐는 곳\n2. 햇볕이 잘 들고 통풍이 좋은 곳\n3. 습하고 그늘진 곳\n\n\n", name);
	printPot(6, &name);
	printUserBox1(&ans);
	while (ans != 2) {
		num = 0;
		if (ans == 1) printf("잎이 탈 수 있습니다(-5p)\n");
		else if (ans == 3) printf("곰팡이가 필 수 있고 광합성하기 좋지 않습니다(-5p)\n");
		point -= 5;
		printUserBox1(&ans);
	}
	if (num) {
		printf("근사한 장소입니다(+15p)");
		point += 15;
	}
	else printf("근사한 장소입니다");
	_sleep(2000);
	system("cls");

	num = 1;//해충 대응
	printPoint();
	printf("%s에게 벌레가 생겼습니다\n어떤 조치를 취할건가요?\n\n1. 그냥 둔다\n2. 선풍기를 틀어준다\n3. 약을 친다\n4. 직접 잡아준다\n\n\n", name);
	printPot(6, &name);
	printUserBox1(&ans);
	while (ans < 3) {
		num = 0;
		if (ans == 1) {
			printf("무책임한 행동은 %s을(를) 아프게 합니다(-15p)\n", name);
			point -= 15;
		}
		else {
			printf("다시 생각해보는게 좋겠습니다(-10p)\n");
			point -= 10;
		}
		printUserBox1(&ans);
	}
	if (num) {
		if (ans == 3) printf("편하고 확실한 방법을 선택하였습니다(+10p)");
		else printf("당신의 정성에 %s이(가) 감동합니다(+10p)", name);
		point += 10;
	}
	else {
		if (ans == 3) printf("편하고 확실한 방법을 선택하였습니다");
		else printf("당신의 정성에 %s이(가) 감동합니다", name);
	}
	_sleep(2000);
	system("cls");
}

void result() {
	printPoint();
	printf("\n\n\n시간이 흐르고...\n\n\n");
	printPot(6, &name);
	_sleep(1500);
	system("cls");
	printPoint();
	printf("\n\n\n%s은(는) 조용히, 그리고 열심히 자랐습니다...\n\n\n", name);
	printPot(6, &name);
	_sleep(2000);
	system("cls");

	while (1) {//자라는 모습 출력
		printPoint();
		printf("\n\n\n\n\n\n\n\n\n\n");
		printf("       /\n");
		printf("     ○|\n");
		printf(" _____/|_____\n");
		printPot(10, &name);
		_sleep(500);
		system("cls");

		printPoint();
		printf("\n\n\n\n\n\n\n\n");
		printf("       /○\n");
		printf("       |\n");
		printf("       /\n");
		printf("    ○||\n");
		printf(" _____/|_____\n");
		printPot(10, &name);
		_sleep(500);
		system("cls");

		printPoint();
		printf("\n\n\n\n\n\n\n\n");
		printf("       /○\n");
		printf("       |_○\n");
		printf("      |/\n");
		printf("    ○||\n");
		printf(" ____/_|_____\n");
		printPot(10, &name);
		_sleep(500);
		system("cls");

		printPoint();
		printf("\n\n\n\n\n\n\n");
		printf("      ○/\n");
		printf("       /○\n");
		printf("       ||_○\n");
		printf("      |/\n");
		printf("    ○||\n");
		printf(" ____/_|_____\n");
		printPot(10, &name);
		_sleep(500);
		system("cls");

		printPoint();
		printf("\n\n\n\n\n\n");
		printf("       ○/\n");
		printf("        /○\n");
		printf("       //\n");
		printf("       ||_/○\n");
		printf("    ○|/\n");
		printf("      ||\n");
		printf(" ____/_|_____\n");
		printPot(10, &name);
		_sleep(500);
		system("cls");

		printPoint();
		printf("\n\n\n\n\n\n");
		printf("        ○/*\n");
		printf("        /|\n");
		printf("      *//  _\n");
		printf("    ＼ ||_/*\n");
		printf("    ○|/\n");
		printf("      ||\n");
		printf(" ____/_|_____\n");
		printPot(10, &name);
		_sleep(500);
		system("cls");

		printPoint();//점수가 20점 미만일 때 엔딩
		if (point < 20)
			printf("점수는 %d점\n\n%s은(는) 조금 왜소합니다\n\n\n", point, &name);
		else printf("\n\n\n\n\n");
		printf("           _/\n");
		printf("      **＼/**\n");
		printf("        /|\n");
		printf("      *//  _*\n");
		printf("   *＼ ||_/*\n");
		printf("     *|/\n");
		printf("      ||\n");
		printf(" ____/_|_____\n");
		printPot(10, &name);
		_sleep(500);
		if (point < 20) {
			_sleep(5000);
			break;
		}
		system("cls");

		printPoint();//점수가 40점 미만 20점 이상일 때 엔딩
		if (point < 40)
			printf("점수는 %d점\n\n%s은(는) 다행히 잘 자라주었습니다\n\n\n", point, &name);
		else printf("\n\n\n\n");
		printf("            *\n");
		printf("           _|*\n");
		printf("      **＼/**\n");
		printf("       */|\n");
		printf("  ＼   //  __/*\n");
		printf("  **＼ ||_/**\n");
		printf("     *|/\n");
		printf("      ||\n");
		printf(" ____/_|_____\n");
		printPot(10, &name);
		_sleep(500);
		if (point < 40) {
			_sleep(5000);
			break;
		}
		system("cls");

		printPoint();//점수가 60점 미만 40점 이상일 때 엔딩
		if (point < 60)
			printf("점수는 %d점\n\n%s은(는) 건강한 식물로 자랐습니다\n", point, &name);
		else printf("\n\n\n\n");
		printf("            *_**\n");
		printf("      *_*  _|\n");
		printf("       *＼/**\n");
		printf("**      /|*\n");
		printf(" *＼  *// *__*\n");
		printf("   *＼ ||_/***\n");
		printf("      |/\n");
		printf("      ||\n");
		printf(" ____/_|_____\n");
		printPot(10, &name);
		_sleep(500);
		if (point < 60) {
			_sleep(5000);
			break;
		}
		system("cls");

		printPoint();//점수가 80점 미만 60점 이상일 때 엔딩
		if (point < 80)
			printf("점수는 %d점\n\n%s은(는) 멋지게 자라났습니다\n", point, &name);
		else printf("\n\n\n");
		printf("             *\n");
		printf("    *       */**\n");
		printf("    *＼_*  _|\n");
		printf(" * *  **＼/**\n");
		printf("**|     /|   ***\n");
		printf("  ＼  *//  __/*\n");
		printf("   *＼ ||_/*\n");
		printf("     *|/\n");
		printf("      ||\n");
		printf(" ____/_|_____\n");
		printPot(10, &name);
		_sleep(500);
		if (point < 80) {
			_sleep(5000);
			break;
		}
		system("cls");

		printPoint();//점수가 80점 이상일 때 엔딩
		if (point >= 80)
			printf("point는 %d점\n\n%s은(는) 아름다운 식물이 되었습니다\n", point, &name);
		else printf("\n\n\n");
		printf("             **\n");
		printf("    ***     */**\n");
		printf("    *＼_* *_|*\n");
		printf(" ***  **＼/**\n");
		printf("**|*   */|   ***\n");
		printf("* ＼  *//  __/*\n");
		printf("   *＼ ||_/**\n");
		printf("     *|/\n");
		printf("      ||\n");
		printf(" ____/_|_____\n");
		printPot(10, &name);
		_sleep(5000);
		system("cls");
		break;
	}
	system("cls");
	printf("%s는 작별인사를 합니다...\n\n", name);//마무리
	_sleep(2000);
	printf("%s는 자신과 보낸 시간이 즐거웠기를 빕니다\n\n", name);
	_sleep(3000);
	system("cls");
	printf("\n\n	The End");
	_sleep(2000);
}