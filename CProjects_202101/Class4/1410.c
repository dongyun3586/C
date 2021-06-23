#include<stdio.h>
#include<stdlib.h> // => 뽑기에서의 확률을 부여하기 위해 사용함. rand()를 1부터 100까지의 수가 나오도록 설정한 다음, 수의 범위를 설정해 그것으로 확률을 조작한다. 
#include<time.h>
#include<windows.h> // 이펙트 부여 및 UI 개선을 위해서 사용함

int gamble(int stat, int money, int jujak);
int nowstat(int stat, int money, int jujak);
int blackcow(int stat, int money, int jujak);
void print_legend(); // 레전드 팩을 구매할 시 출력되는 이펙트
void print_wow(); // 50짜리 스탯이 나올 경우 출력되는 이펙트

int main() {
	int a, stat = 50, money = 0, jujak = 0;
	srand(time(NULL));
	printf("환영합니다!\n이 게임은 뽑기로 여러분의 스탯을 올리는 게임입니다!\n기본 스탯은 50으로 주어집니다. \n\n뽑기: 1\n상점: 2\n");
	scanf("%d", &a); // 갈 곳을 선택하는 시스템
	if (a == 1) {
		gamble(stat, money, jujak);
	}
	else if (a == 2) {
		blackcow(stat, money, jujak);
	}
	else printf("치지직......오류 발생....");//게임 내 이스터에그임. 1과 2를 제외한 다른 것을 입력 시 바로 프로그램이 종료됨.
	return 0;
}

int nowstat(int stat, int money, int jujak) {//스탯을 보여주는 시스템이다.
	int gamma;
	system("cls");//UI개선의 핵심 요소. 
	printf("현재 스탯은 %d입니다. \n열심히 뽑아봐요! \n\n", stat);
	printf("뽑기: 1\n상점: 2\n ");
	scanf("%d", &gamma); // 갈 곳을 선택하는 시스템
	if (gamma == 1) {
		gamble(stat, money, jujak);
	}
	else if (gamma == 2) {
		blackcow(stat, money, jujak);
	}
}

int gamble(int stat, int money, int jujak) {//본격적으로 뽑기를 하여 스탯을 올리는 시스템이다.
	int c;
	system("cls");
	printf("이곳은 뽑기를 하는 곳입니다!. \n\n현재 스탯 확인: 1\n뽑기: 2 \n");
	system("color 5B");
	scanf("%d", &c); // 갈 곳 선택
	if (c == 1) {
		nowstat(stat, money, jujak);
	}
	else if (c == 2);
	int gatcha, d;

	printf("몇 번 뽑으시겠습니까?\n10+1: 1 입력\n1: 2 입력\n"); // 가챠를 뽑을 횟수를 정하는 시스템
	scanf("%d", &gatcha);
	if (gatcha == 1) gatcha = 11;
	else if (gatcha == 2)gatcha = 1;
	switch (jujak) {
	case 0:
		for (int i = 0; i < gatcha; i++) { // 주작이 아닌 뽑기 또는 확률 업 뽑기. 나오는 스탯은 50 10 1로 총 3가지, 확률은 5 25 70. 50 등장 시 극악의 확률로 변경됨. 
			int upstat, per = rand() % 100 + 1;
			if (per >= 1 && per < 6) {
				upstat = 50;
				system("color 5B");
				for (int i = 1; i < 10; i++) {
					printf("*"); Sleep(10); system("color 2D"); // 50이 나올 때의 이펙트
					printf("/"); Sleep(10); system("color 4E");
					printf("$"); Sleep(10); system("color 1C");
					printf("#"); Sleep(10); system("color 69");
				}
				print_wow();
				printf("+50\n");
				Sleep(100);
				stat = stat + upstat;
				jujak = 1;
			}
			else if (per >= 6 && per < 31) {
				upstat = 10;
				system("color 5C");
				printf("+10\n");
				Sleep(100);
				stat = stat + upstat;
			}
			else if (per >= 31 && per <= 100) {
				upstat = 1;
				system("color 2E");
				printf("+1\n");
				Sleep(100);
				stat = stat + upstat;
			}
		}
		break;
	case 1:
		for (int i = 0; i < gatcha; i++) { // 주작이 들어간 극악의 확률 뽑기. 등장 스탯은 위와 동일, 확률은 1 5 94
			int upstat, per = rand() % 100 + 1;
			if (per == 1) {
				upstat = 50;
				system("color 5B");
				for (int i = 1; i < 10; i++) {
					printf("*"); Sleep(10); system("color 2D");
					printf("/"); Sleep(10); system("color 4E");
					printf("$"); Sleep(10); system("color 1C");
					printf("#"); Sleep(10); system("color 69");
				}
				print_wow();
				printf("+50\n");
				Sleep(100);
				stat = stat + upstat;
			}
			else if (per > 1 && per <= 6) {
				upstat = 10;
				system("color 5C");
				printf("+10\n");
				Sleep(100);
				stat = stat + upstat;
			}
			else if (per > 6 && per <= 100) {
				upstat = 1;
				system("color 2E");
				printf("+1\n");
				Sleep(100);
				stat = stat + upstat;
			}
		}
		break;
	case 2:
		for (int i = 0; i < gatcha; i++) { // 초 확률 업 뽑기. 등장 스탯은 위와 동일, 확률은 19 40 41. 단, 여기는 50에 당첨될 시 일반 확률로 돌림.
			int upstat, per = rand() % 100 + 1;
			if (per >= 1 && per < 20) {
				upstat = 50;
				system("color 5B");
				for (int i = 1; i < 10; i++) {
					printf("*"); Sleep(5); system("color 2D");
					printf("/"); Sleep(5); system("color 4E");
					printf("$"); Sleep(5); system("color 1C");
					printf("#"); Sleep(5); system("color 69");
				}
				print_wow();
				printf("+50\n");
				Sleep(100);
				stat = stat + upstat;
				jujak = 0;
			}
			else if (per >= 20 && per < 60) {
				upstat = 10;
				system("color 5C");
				printf("+10\n");
				Sleep(100);
				stat = stat + upstat;
			}
			else if (per >= 60 && per <= 100) {
				upstat = 1;
				system("color 2E");
				printf("+1\n");
				Sleep(100);
				stat = stat + upstat;
			}
		}
		break;
	}
	if (stat >= 10000) {
		system("color 92");
		printf("축하합니다! 이제 엔딩을 볼 수 있겠군요! \n총 %d원을 쓰셨네요! \n그럼 안녕!\n", money);// 스탯을 10,000 이상 달성 시 엔딩이 열림, 총 현질 금액도 같이 공개됨.
		exit(0);
	}
	printf("현재 스탯은 %d입니다!\n\n다시 뽑기: 1\n상점: 2\n", stat);
	scanf("%d", &d); // 갈 곳 선택
	if (d == 1) {
		gamble(stat, money, jujak);
	}
	else if (d == 2) {
		blackcow(stat, money, jujak);
	}
}

int blackcow(int stat, int money, int jujak) {//현질을 하여 확률을 상승시키고, 추가 스탯을 얻을 수 있는 패키지를 구매하는 시스템이다.
	int pack;
	system("cls");
	printf("이 곳은 상점입니다!\n패키지 상품을 선택하세요!\n\n1. 알뜰 뽑기팩(확률 업 뽑기): 5,500 \n2. 고급 뽑기팩(초 확률 업 뽑기): 11,000 \n3. 슈퍼 성장 팩(스탯 +300, 초 확률 업 뽑기): 25,000 \n4. 레전더리 팩 Vol 1(스탯 +1,500, 초 확률 업 뽑기): 110,000\n5. 레전더리 팩 Vol 2(스탯 +5,000, 초 확를 업 뽑기): 450,000\n6. 한 방 클리어 패키지(게임 클리어): 1,100,000\n7. 구매 안 함\n");
	scanf("%d", &pack); // 패키지 상품을 선택할 수 있도록 하는 시스템.
	system("color 6D");
	switch (pack) {
	case 1:
		money = money + 5500;
		jujak = 0;
		printf("감사합니다!");
		Sleep(3000);
		break;
	case 2:
		money = money + 11000;
		jujak = 2;
		printf("감사합니다!");
		Sleep(3000);
		break;
	case 3:
		money = money + 25000;
		jujak = 2;
		stat = stat + 300;
		printf("감사합니다!");
		Sleep(3000);
		break;
	case 4:
		print_legend();
		money = money + 110000;
		jujak = 2;
		stat = stat + 1500;
		break;
	case 5:
		print_legend();
		money = money + 450000;
		jujak = 2;
		stat = stat + 5000;
		break;
	case 6:
		money = money + 1100000;
		printf("축하합니다! 이제 엔딩을 볼 수 있겠군요! \n총 %d원을 쓰셨네요! \n그럼 안녕!\n", money);
		Sleep(1000);
		exit(0);

	case 7:
		break;
	}
	gamble(stat, money, jujak);
}
void print_wow() // 뽑기에서 최저 확률에 당첨될 때 나올 때의 이펙트
{
	system("cls");
	printf("                           \n");
	printf("                           \n");
	printf("                           \n");
	printf("            *              \n");
	printf("                           \n");
	printf("                           \n");
	printf("                           \n");
	Sleep(100); system("cls");
	system("color 59");
	system("cls");
	printf("                           \n");
	printf("                           \n");
	printf("            *              \n");
	printf("           * *             \n");
	printf("            *              \n");
	printf("                           \n");
	printf("                           \n");
	Sleep(100); system("cls");
	system("color 4E");
	system("cls");
	printf("                           \n");
	printf("            *              \n");
	printf("           * *             \n");
	printf("          *   *            \n");
	printf("           * *             \n");
	printf("            *              \n");
	printf("                           \n");
	Sleep(100); system("cls");
	system("color 6C");
	system("cls");
	printf("            *              \n");
	printf("           * *             \n");
	printf("          *   *            \n");
	printf("         *     *           \n");
	printf("          *   *            \n");
	printf("           * *             \n");
	printf("            *              \n");
	Sleep(200); system("cls");
	printf("            W              \n");
	printf("           W O             \n");
	printf("          W O W            \n");
	printf("         W O W O           \n");
	printf("          W O W            \n");
	printf("           W O             \n");
	printf("            W              \n");
	Sleep(500); system("cls");
	system("color 3C");
	printf("            N              \n");
	printf("           N I             \n");
	printf("          N I C            \n");
	printf("         N I C E           \n");
	printf("          N I C            \n");
	printf("           N I             \n");
	printf("            N              \n");
	Sleep(500); system("cls");
	system("color A4");
	printf("         55555   000000    \n");
	printf("  +      5       0    0    \n");
	printf("  +      5       0    0    \n");
	printf("+++++    55555   0    0    \n");
	printf("  +          5   0    0    \n");
	printf("  +          5   0    0    \n");
	printf("         55555   000000    \n");
	Sleep(700); system("cls");
	system("color 68");
	printf("\n");

}
void print_legend() // 레전드 팩을 구매할 시 나오는 이펙트
{
	system("cls");
	printf("                           \n");
	printf("                           \n");
	printf("                           \n");
	printf("            ■             \n");
	printf("                           \n");
	printf("                           \n");
	printf("                           \n");
	Sleep(600); system("cls");
	system("color 18");
	system("cls");
	printf("                           \n");
	printf("                           \n");
	printf("          ■■■           \n");
	printf("          ■  ■           \n");
	printf("          ■■■           \n");
	printf("                           \n");
	printf("                           \n");
	Sleep(100); system("cls");
	system("color B4");
	system("cls");
	printf("                           \n");
	printf("        ■■■■■         \n");
	printf("        ■      ■         \n");
	printf("        ■      ■         \n");
	printf("        ■      ■         \n");
	printf("        ■■■■■         \n");
	printf("                           \n");
	Sleep(100); system("cls");
	system("color 54");
	system("cls");
	printf("      ■■■■■■■       \n");
	printf("      ■          ■       \n");
	printf("      ■          ■       \n");
	printf("      ■          ■       \n");
	printf("      ■          ■       \n");
	printf("      ■          ■       \n");
	printf("      ■■■■■■■       \n");
	Sleep(100); system("cls");
	system("color 2D");
	system("cls");
	printf("                           \n");
	printf("                           \n");
	printf("                           \n");
	printf("            ■             \n");
	printf("                           \n");
	printf("                           \n");
	printf("                           \n");
	Sleep(700); system("cls");
	system("color E6");
	system("cls");
	printf("            *              \n");
	printf("          ** **            \n");
	printf("        **     **          \n");
	printf("       *         *         \n");
	printf("        **     **          \n");
	printf("          ** **            \n");
	printf("            *              \n");
	Sleep(100); system("cls");
	system("color 59");
	system("cls");
	printf("                           \n");
	printf("       ♥♥♥♥♥♥        \n");
	printf("         ♥♥♥♥          \n");
	printf("           ♥♥            \n");
	printf("         ♥♥♥♥          \n");
	printf("       ♥♥♥♥♥♥        \n");
	printf("                           \n");
	Sleep(200); system("cls");
	system("color D1");
	system("cls");
	printf("                           \n");
	printf("           ♥♥            \n");
	printf("         ♥♥♥♥          \n");
	printf("       ♥♥♥♥♥♥        \n");
	printf("         ♥♥♥♥          \n");
	printf("           ♥♥            \n");
	printf("                           \n");
	Sleep(200); system("cls");
	system("color 6C");
	system("cls");
	printf("-----------BOX-------------\n");
	printf("|         LEGEND          |\n");
	printf("|     LEGEND LEGEND       |\n");
	printf("|  LEGEND LEGEND LEGEND   |\n");
	printf("|     LEGEND LEGEND       |\n");
	printf("|         LEGEND          |\n");
	printf("-----------BOX-------------\n");
	Sleep(1500); system("cls");
	system("color A4");
}