#include <stdio.h> 
#include <conio.h> 
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

// 용어 설명 1 : 할로포인트 : 그냥 총알 종류입니다. 별 뜻이라고 할 만한 것은 1-6에서 밈으로 쓰이는 단어입니다.
// 용어 설명 2 : 하진몬 : 몬스터로 등장하는 하진몬은 6반 조하진이 모델인데 본인에게 허락을 받았습니다.
// 용어 설명 3 : 정신공격 : 그 정신공격을 표현하기 위해 어쩔 수 없이 비속어가 조금 섞였습니다. 죄송합니다.
// 그냥 설명 1 : 하진몬의 공격 모션은 모두 1-6 조하진이 만들어달라 의뢰한 모션들입니다.
// 그냥 설명 2 : 함수들 번호가 2부터 시작한 이유는 1이라고 각 함수의 예시를 하나씩 만들어 두었던 것을 지우고 나니 2부터 시작하게 되었습니다.

void fightmotion2(int i, int sp, int hp, int wp, int monsterhp, int hachori, int jungsin, int halopoint); // fightmotion 2,3,4는 user의 싸우는 애니메이션을 출력하는 함수
void fightmotion3(int sp, int hp, int wp, int hachori, int jungsin, int halopoint); //2,3,4는 각각 회초리 모션, 정신공격 모션, 할로포인트(총) 모션
void fightmotion4(int sp, int hp, int wp, int hachori, int jungsin, int halopoint);

void monsterturn2(int sp, int hp, int wp, int hachori, int jungsin, int halopoint); // monsterturn 2,3,4는 hajinmon(monster)의 공격 애니메이션을 출력하는 함수
void monsterturn3(int sp, int hp, int wp, int hachori, int jungsin, int halopoint); //2,3,4는 각각 침뱉기, 딱밤, 발차기 모션
void monsterturn4(int sp, int hp, int wp, int hachori, int jungsin, int halopoint);

void userinterface1(int linehp, int linesp, int linewp, int point, int hp, int sp, int wp); // 유저의 게임 시작 후 바로 나오는 인터페이스 창 이 창이 나오는 시점에서 wp나 hp 등을 올릴 수 있다.

void hajinmon(int monsterhp, int hp, int sp, int wp, int hachori, int jungsin, int halopoint); // 작업량의 문제로 하나 밖에 만들지 못한 몬스터. 이 몬스터를 사냥하려는 대련 장면이 나오는 인터페이스이다.

int main() {

	int monsterhp = 100, hp = 20, sp = 1, wp = 1, monsterhit, color, key, hit; // 각종 변수들, 변수들의 이름에서도 어렴풋이 알 수 있듯 몬스터나 유저의 hp, 출력 시 나오게 되는 글자의 색, 유저의 선택, 공격량등을 나타낼 변수들이다.
	int linesp = 10, linewp = 10, linehp = 20, point = 60; // 대부분 유저 인터페이스 창에서 선택할 수 있는 것들의 가격, 보유 포인트
	int monsterlevel = 0; // 몬스터의 레벨
	int hachori = 10, jungsin = 15, halopoint = 13; // 각각 공격의 종류에 따라 다른 공격력을 표시


	srand(time(NULL)); // 다양하게 활용도를 위한 난수 생성


	while (1) { // while문을 사용함으로써 아래에 지정한 출력문의 색상을 계속 다르게 설정

		color = rand() % 14 + 1; // 특정 문자의 색을 계속해서 변경해주기 위해 color 변수에 1~14의 랜덤한 값을 입력

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // 7번(흰색) 으로 글자의 색상변경
		printf("┌--------------------------------┐\n"); // 출력
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color); // 전에 설정되는 랜덤한 색상으로 색상 변경 (반짝반짝 효과)
		printf("│☆★☆★☆★☆★☆★☆★☆★☆★│\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		printf("│    랄-랄루 포켓치킨몬 게-임    │\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
		printf("│☆★☆★☆★☆★☆★☆★☆★☆★│\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		printf("└--------------------------------┘\n");
		printf("\n\n\n\n");
		printf(" 시작하시려면 spacebar를 눌러주세요.\n"); // 이 문자는 흰색으로 출력
		Sleep(100); // 100밀리 세컨드 정지
		system("cls"); // 화면을 모두 지운 후 다시 색상이 바뀐채로 출력

		if (kbhit()) { // 키보드의 키를 입력받는 함수
			key = getch(); // key변수에 입력 받는 키의 정보(아스키코드)를 받아준다.
			if (key == 32) // key변수에 입력되는 키의 정보가 아스키코드 32 즉 공백문자일때 다음의 과정을 실행한다.
			{
				system("cls"); // 화면을 모두 지운다.
				break; // 반복문(while)문을 탈출한다.
			}
		}

	}



	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // 글자의 색상을 다시 흰색으로 설정해준다.
	system("cls"); // 다음 과정은 게임의 인터페이스로 넘어가는 과정에서 roding 화면을 생동감을 더하기 위해 집어넣은 것이다.
	printf("\n\n  Roding");
	Sleep(100);
	printf(".");
	Sleep(300);
	printf(".");
	Sleep(300);
	printf(".");
	Sleep(300);
	printf(".");
	Sleep(300);
	system("cls");
	// 위의 과정은 Roding.... 의 모습을 로딩이 되는 것처럼 시간차를 두어 출력하는 출력문 각 과정마다 100밀리세컨드나 300밀리세컨드 쉬게 코딩하였다.

	system("cls"); // 다시금 화면 전체 지워주기

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // 글자의 색상을 흰색으로 변경
	printf("\n\n  Let's start the game!"); // 유저 인터페이스 입장 상황의 환영문 출력
	Sleep(1000); // 1000 밀리세컨드 동안 정지
	system("cls"); // 화면 클리어
	Sleep(1000); // 1000 밀리세컨드 동안 정지

	userinterface1(linehp, linesp, linewp, point, hp, sp, wp); // 함수 유저인터페이스 호출

	while (1) { // 일련의 과정 동안 유저 인터페이스에서 유저가 사용할 수 있는 키를 입력받고 작동하기 위해 while문을 탈출 없이는 무한히 반복하도록 설정
		if (kbhit()) { // 키보드 입력
			key = getch();
			if (key == 49) // 1(아스키코드 49)을 입력받았을 때
			{
				system("cls");
				printf("\n\n  Roding");
				Sleep(100);
				printf(".");
				Sleep(300);
				printf(".");
				Sleep(300);
				printf(".");
				Sleep(300);
				printf(".");
				Sleep(300);
				system("cls");
				break; // 아까의 로딩 화면과 같은 과정 이후 while문을 탈출하여 대련의 과정으로 넘어가도록 설계
			}
			else if (point >= linesp && key == 50) // 2(아스키코드 50)을 입력받았을 때 작동, 보유 포인트의 양이 sp를 올리는데 필요한 양보다 많아야 작동한다.
			{
				sp += 1; // sp는 방어 포인트, 1올릴 때마다 대련하는 몬스터의 최대공격력은 1씩 낮아진다. 
				point -= linesp; // 재화(point)변수에서 sp를 올릴 때 필요한 포인트를 빼준다.

				linesp *= 2; // 다음번 레벨업에 필요한 포인트는 지금의 두배로 만든다.
				system("cls"); // 화면 클리어
				userinterface1(linehp, linesp, linewp, point, hp, sp, wp); // 유저의 인터페이스를 다시 호출하여 변화된 값을 바로 적용시켜준다.
				continue; // 다른 작업을 할 수 있도록 반복문의 시작으로 회귀
			}
			else if (point >= linewp && key == 51) // 3의 아스키코드인 51이 입력되었을때, 보유한 포인트의 양이 wp를 올리는데 필요한 양보다 많다면 작동한다.
			{
				wp += 1; // wp는 공격 포인트, 1 올릴 때마다 유저의 최대공격력이 1씩 늘어난다.
				point -= linewp; // 재화(point)변수에서 wp를 올릴 때 필요한 포인트를 제해준다.

				hachori = 10 + wp, jungsin = 15 + wp, halopoint = 13 + wp; // 회초리, 욕설, 총 각각의 유저 공격 모션의 최대 공격력을 기본값과 유저가 올린 공격력의 합으로 결정지어준다.

				linewp *= 2; // wp를 올리는 데에 필요한 포인트를 지금의 두배로 만든다.
				system("cls");
				userinterface1(linehp, linesp, linewp, point, hp, sp, wp); // 지금 있는 인터페이스는 현재 변경되기 전의 값을 담고 있으므로 지우고 새로운 정보로 업데이트 한다.
				continue; // 다른 작업이 가능하게끔 반복문의 시작으로 회귀
			}
			else if (point >= linehp && key == 52) // 재화가 hp(체력)을 올리는 데에 필요한 포인트를 넘으며, 4에 해당하는 아스키코드인 52를 눌렀을 때 실행한다.
			{
				hp = 100; // hp를 100(한계치)로 회복시킨다.
				point -= linehp; // 사용한 포인트를 보유 포인트에서 제한다.
				system("cls");
				userinterface1(linehp, linesp, linewp, point, hp, sp, wp); // 유저 인터페이스 업데이트
				continue; // 다음 실행을 위한 반복문 회귀
			}
			else // 키를 눌렀으나 위의 조건들에 해당되지 못할때 실행
			{
				system("cls");
				printf("\n\n  재화가 부족한것 같네요, 사냥으로 재화를 버세요."); // 대련을 통해 재화를 얻을 수 있도록 유도
				Sleep(1200);
				system("cls");
				userinterface1(linehp, linesp, linewp, point, hp, sp, wp); // 다시 유저를 유저 인터페이스 창으로 되돌려주기
				continue; // 다음 선택 실행을 위한 반복문 회귀
			}
		}

	}

	printf("\n\n  사냥에 들어갑니다!"); // break문을 통해 반복문에서 빠져나와 게임으로 들어가는 부분에서 실행
	Sleep(1000);
	system("cls");

	hajinmon(monsterhp, hp, sp, wp, hachori, jungsin, halopoint); // 원래 계획은 원대하게 3가지 정도의 몬스터를 만들어 랜덤하게 등장시킬 계획이었으나 기간과 시간 상의 문제로 하나의 몬스터 만을 등장시키게 되었다.

	while (1) { // 대련 부분의 시작

		while (1) { // 유저가 공격을 하게 되는 부분


			system("cls");
			printf("\n\n  user의 턴! 공격을 성공해내세요!");
			Sleep(1000);
			system("cls"); // 유저에게 공격을 안내하는 메시지 출력

			hajinmon(monsterhp, hp, sp, wp, hachori, jungsin, halopoint); // 몬스터와 대련하는 모습의 콘솔 화면 구성 함수를 호출하여 출력

			while (1) { // 유저가 어떤 종류의 공격을 구사할 지 입력받기 위한 반복문 while

				if (kbhit()) { // 키를 입력받기 위한 함수
					key = getch(); // key 변수에 아스키코드를 입력받는다.
					if (key == 49) // 아스키코드 49일때 실행
					{
						hit = rand() % hachori + 1; // 공격력은 앞에서 설정한 회초리 공격의 최대공격력 범위 내에서 랜덤으로 적용
						monsterhp -= hit; // 몬스터의 체력에서 바로 앞의 과정에서 구한 공격력을 빼준다.

						system("cls");

						fightmotion2(5, sp, hp, wp, monsterhp, hachori, jungsin, halopoint); // 유저가 선택한 공격의 공격 모션을 출력하여 주는 함수 호출

						printf("\n\n   뼈 밖에 없는 하진몬에게 효과는 굉장했다!"); // 공격 끝을 알리는 안내문 출력
						Sleep(1500);
						system("cls");

						printf("\n\n   공격량 : %d", hit); // 몬스터에게 입힌 피해량 출력
						Sleep(1000);
						system("cls");

						hajinmon(monsterhp, hp, sp, wp, hachori, jungsin, halopoint); // 유저의 공격이 끝났으니 몬스터와의 대련 인터페이스로 복귀
						Sleep(1500); // 1.5초간 정지

						break; // 반복문 탈출
					}
					else if (key == 50) // 입력받은 문자가 아스키코드 50일때 실행
					{
						hit = rand() % jungsin + 1; // 공격력 설정
						monsterhp -= hit; // 공격

						fightmotion3(sp, hp, wp, hachori, jungsin, halopoint); // 정신공격의 공격 모션 출력 함수 호출
						printf("\n\n   이미 제정신이 아닌 하진몬에게 생각보다 큰 피해를 입히지 못했다!"); // 공격 종료 안내문
						Sleep(1500);
						system("cls");

						printf("\n\n   공격량 : %d", hit); // 공격량 출력
						Sleep(1000);
						system("cls");

						hajinmon(monsterhp, hp, sp, wp, hachori, jungsin, halopoint); // 다시 몬스터와 대련 장면 출력
						Sleep(1500);

						break; // 반복문 탈출
					}
					else if (key == 51) //아스키 코드 51일때 실행
					{
						hit = rand() % halopoint + 1; // 공격력 설정
						monsterhp -= hit;

						fightmotion4(sp, hp, wp, hachori, jungsin, halopoint); // 공격 모션 출력 함수 호출
						printf("\n\n   사람의 신체를 관통하지 못하는 할로포인트로는 큰 피해를 입히지 못했다!"); // 안내 메시지 출력
						Sleep(1500);
						system("cls");

						printf("\n\n   공격량 : %d", hit);
						Sleep(1000);
						system("cls");

						hajinmon(monsterhp, hp, sp, wp, hachori, jungsin, halopoint);
						Sleep(1500);

						break; // 위의 다른 선택들과 동일과정
					}
					else if (key == 52) // 52즉 도망가기 키이나 재미요소로 도망갈 수 없음을 집어넣었다.
					{
						system("cls");
						printf("와... 정말 도망가시는 건가요..?");
						Sleep(1200);
						system("cls");
						printf("다시 한번만 생각해주세요..");
						Sleep(1200);
						system("cls");
						printf("사실 이 전투에 도망이란 없습니다! 배산임수의 기세! 다시 뛰어드세요!!");
						Sleep(1700);
						system("cls");

						hajinmon(monsterhp, hp, sp, wp, hachori, jungsin, halopoint);

						continue; // 게임 재참여
					}
				}
			}

			if (monsterhp <= 0) { // 유저의 공격이 끝난 이후 몬스터의 체력이 0 이하라면 사냥 성공을 알리고 인터페이스로 귀환
				system("cls");
				point += rand() % 50 + 1;// 1~50 의 범위에서 랜덤하게 포인트 획득
				Sleep(100);
				printf("\n\n  사냥에 성공하셨습니다.");
				Sleep(1000);
				system("cls");
				printf("\n\n  메뉴창으로 돌아갑니다.");
				Sleep(1000);
				system("cls");
				break;
			}


			system("cls");// monster가 유저의 공격이 죽지 않았을때 랜덤으로 3가지 몬스터의 공격 모션 중 하나가 출력되며 공격
			printf("\n\n  Hajinmon의 턴! 공격을 버텨내세요!"); // 몬스터의 공격 차례임을 유저에게 전달
			Sleep(1000);
			system("cls"); // 화면 클리어

			monsterhit = rand() % 3 + 1; // 몬스터의 공격 모션 3 가지 중 하나를 선택하도록 랜덤으로 숫자 선택

			if (monsterhit == 1) { // 랜덤 선택된 숫자가 1일때 실행

				hit = rand() % (10 + monsterlevel - sp) + 1; // 유저의 공격력과 같이 10에 몬스터의 레벨을 더하고, 유저의 방어력을 뺀 최대 공격력의 범위 안에서 랜덤한 공격력 부여
				hp -= hit; // 공격
				system("cls");

				monsterturn2(sp, hp, wp, hachori, jungsin, halopoint); // 몬스터 2번 공격 모션 함수 호출
				system("cls");

				printf("\n\n   피해량 : %d", hit); // 유저에게 입은 피해량 전달
				Sleep(1000);
				system("cls");

				hajinmon(monsterhp, hp, sp, wp, hachori, jungsin, halopoint); // 대련 인터페이스로 복귀

			}
			else if (monsterhit == 2) { // 랜덤 선택된 숫자가 2일때 실행

				hit = rand() % (10 + monsterlevel - sp) + 1; // 공격력 부여
				hp -= hit; // 공격
				system("cls");

				monsterturn3(sp, hp, wp, hachori, jungsin, halopoint); // 3번 공격 모션 함수 호출
				system("cls");

				printf("\n\n   피해량 : %d", hit); // 피해량 표시
				Sleep(1000);
				system("cls");

				hajinmon(monsterhp, hp, sp, wp, hachori, jungsin, halopoint); // 대련 인터페이스 복귀

			}
			else if (monsterhit == 3) { // 랜덤 선택된 숫자가 3일때 실행

				hit = rand() % (10 + monsterlevel - sp) + 1; // 공격력 부여
				hp -= hit;// 공격
				system("cls");

				monsterturn4(sp, hp, wp, hachori, jungsin, halopoint);// 4번 공격 모션 호출
				system("cls");

				printf("\n\n   피해량 : %d", hit); // 피해량 표시
				Sleep(1000);
				system("cls");

				hajinmon(monsterhp, hp, sp, wp, hachori, jungsin, halopoint);// 복귀

			}

			if (hp <= 0) {//몬스터의 공격 이후 유저의 체력이 0 이하라면 몬스터의 레벨을 1 올리고 유저 인터페이스에서 부활
				monsterlevel++; // 몬스터 레벨 +1
				system("cls");
				Sleep(100);
				printf("\n\n  사망하셨습니다."); // 사망 소식 전달
				Sleep(1000);
				system("cls");
				printf("\n\n  부활합니다.");
				Sleep(1000);
				system("cls");
				break; // 대련 상황 탈출
			}

		}

		if (hp <= 0) {
			break; // 대련 상황 탈출
		}

		if (monsterhp <= 0) {
			break; // 대련 상황 탈출
		}

	}

	// 여기서 다시 지정된 코드로 이동시켜 과정을 반복하다가 메뉴(유저 인터페이스)에서 탈출 선택시 종료할 계획이었으나 분량과 시간 상의 문제로 이 과정에서 체험판 종료를 선언

	userinterface1(linehp, linesp, linewp, point, hp, sp, wp); // 유저 인터페이스 호출

	printf("\n\n잠시 뒤 체험판이 종료됩니다."); // 게임 체험판 종료 안내
	Sleep(3000);
	system("cls");
	printf("\n\n  여기까지 포켓치킨몬 게-임의 체험판이 종료되었습니다.\n  플레이 해주셔서 감사합니다. (^-^) "); // 인사
	printf("\n  3");
	Sleep(1000);
	printf("\n  2");
	Sleep(1000);
	printf("\n  1");
	Sleep(1000);
	printf("  -체험판 종료- ");




	return 0;


} // 본 프로그램

// 여기서부터는 각 장면 별 유저나 몬스터의 공격 애니메이션(모션), 유저 인터페이스, 대련 인터페이스를 출력하도록 만들어둔 함수들입니다. 원래는 2~3마리의 몬스터를 제작할 계획이었던지라 호출할 수 있도록 함수로 모션을 제작하였습니다.

void fightmotion2(int i, int sp, int hp, int wp, int monsterhp, int hachori, int jungsin, int halopoint) { // 유저의 공격모션_1
	printf("┌------------------------------------------------┐\n");
	printf("│         ■             ■                      │\n");
	printf("│       ■■            ■■                     │\n");
	printf("│        ■■■      ■■■                      │\n");
	printf("│         ■■■■■■■■                       │\n");
	printf("│         ■■  □■■ □■   회.초.리.후.리.기  │\n");
	printf("│         ■■■■┼ ┼ ■■                       │\n");
	printf("│      ■■■■■■■■■■■                    │\n");
	printf("│   ■■ ■■■■■■■■■  ■■     -user-     │\n");
	printf("└------------------------------------------------┘\n\n");

	printf("hp : %d\n", hp);
	printf("sp : %d\n", sp);
	printf("wp : %d\n", wp);
	printf("\n");


	printf("횟초리 휘두르기 (MAX : %d) : 1\n", hachori);
	printf("정신 공격 (MAX : %d) : 2\n", jungsin);
	printf("할로 포인트 (MAX : %d) : 3\n", halopoint);
	printf("36계 줄행랑 : 4\n");

	Sleep(1000);
	system("cls");

	// 공격의 종류를 유저에게 전달

	for (int a = 1; a <= i; a++) { // for 문을 활용한 애니메이션 출력
		printf("┌------------------------------------------------┐\n");
		printf("│         ■             ■           /          │\n");
		printf("│       ■■            ■■         /     홋    │\n");
		printf("│        ■■■      ■■■         /            │\n");
		printf("│         ■■■■■■■■       ■/             │\n");
		printf("│         ■■  □■■ □■   ■■               │\n");
		printf("│         ■■■■┼ ┼ ■■ ■■                  │\n");
		printf("│      ■■■■■■■■■■■                    │\n");
		printf("│   ■■ ■■■■■■■■■           -user-     │\n");
		printf("└------------------------------------------------┘\n\n");

		printf("hp : %d\n", hp);
		printf("sp : %d\n", sp);
		printf("wp : %d\n", wp);
		printf("\n");


		printf("횟초리 휘두르기 (MAX : %d) : 1\n", hachori);
		printf("정신 공격 (MAX : %d) : 2\n", jungsin);
		printf("할로 포인트 (MAX : %d) : 3\n", halopoint);
		printf("36계 줄행랑 : 4\n");

		Sleep(100);
		system("cls");

		printf("┌------------------------------------------------┐\n");
		printf("│         ■             ■                      │\n");
		printf("│       ■■            ■■               치    │\n");
		printf("│        ■■■      ■■■         4------------│\n");
		printf("│         ■■■■■■■■       ■/             │\n");
		printf("│         ■■  □■■ □■   ■■               │\n");
		printf("│         ■■■■┼ ┼ ■■ ■■                  │\n");
		printf("│      ■■■■■■■■■■■                    │\n");
		printf("│   ■■ ■■■■■■■■■           -user-     │\n");
		printf("└------------------------------------------------┘\n\n");

		printf("hp : %d\n", hp);
		printf("sp : %d\n", sp);
		printf("wp : %d\n", wp);
		printf("\n");


		printf("횟초리 휘두르기 (MAX : %d) : 1\n", hachori);
		printf("정신 공격 (MAX : %d) : 2\n", jungsin);
		printf("할로 포인트 (MAX : %d) : 3\n", halopoint);
		printf("36계 줄행랑 : 4\n");

		Sleep(100);
		system("cls");
	}
}// 함수 종료

void fightmotion3(int sp, int hp, int wp, int hachori, int jungsin, int halopoint) { // 유저의 공격모션_2

	system("cls");
	printf("┌------------------------------------------------┐\n");
	printf("│         ■             ■                      │\n");
	printf("│       ■■            ■■                     │\n");
	printf("│        ■■■      ■■■                      │\n");
	printf("│         ■■■■■■■■                       │\n");
	printf("│         ■■  □■■ □■      정.신.공.격     │\n");
	printf("│         ■■■■┼ ┼ ■■                       │\n");
	printf("│      ■■■■■■■■■■■                    │\n");
	printf("│   ■■ ■■■■■■■■■  ■■     -user-     │\n");
	printf("└------------------------------------------------┘\n\n");

	printf("hp : %d\n", hp);
	printf("sp : %d\n", sp);
	printf("wp : %d\n", wp);
	printf("\n");


	printf("횟초리 휘두르기 (MAX : %d) : 1\n", hachori);
	printf("정신 공격 (MAX : %d) : 2\n", jungsin);
	printf("할로 포인트 (MAX : %d) : 3\n", halopoint);
	printf("36계 줄행랑 : 4\n");

	Sleep(150);
	system("cls");

	// 공격 종류 안내

	for (int i = 1; i <= 3; i++) { // 공격 애니메이션(모션)

		printf("┌------------------------------------------------┐\n");
		printf("│         ■             ■                      │\n");
		printf("│       ■■            ■■                     │\n");
		printf("│        ■■■      ■■■                      │\n");
		printf("│         ■■■■■■■■                       │\n");
		printf("│         ■■  □■■ □■         아니         │\n");
		printf("│         ■■■■┼ ┼ ■■                       │\n");
		printf("│      ■■■■■■■■■■■                    │\n");
		printf("│   ■■ ■■■■■■■■■  ■■     -user-     │\n");
		printf("└------------------------------------------------┘\n\n");

		printf("hp : %d\n", hp);
		printf("sp : %d\n", sp);
		printf("wp : %d\n", wp);
		printf("\n");


		printf("횟초리 휘두르기 (MAX : %d) : 1\n", hachori);
		printf("정신 공격 (MAX : %d) : 2\n", jungsin);
		printf("할로 포인트 (MAX : %d) : 3\n", halopoint);
		printf("36계 줄행랑 : 4\n");

		Sleep(50);
		system("cls");

		printf("┌------------------------------------------------┐\n");
		printf("│         ■             ■                      │\n");
		printf("│       ■■            ■■                     │\n");
		printf("│        ■■■      ■■■                      │\n");
		printf("│         ■■■■■■■■                       │\n");
		printf("│         ■■  □■■ □■         그걸         │\n");
		printf("│         ■■■■┼ ┼ ■■                       │\n");
		printf("│      ■■■■■■■■■■■                    │\n");
		printf("│   ■■ ■■■■■■■■■  ■■     -user-     │\n");
		printf("└------------------------------------------------┘\n\n");

		printf("hp : %d\n", hp);
		printf("sp : %d\n", sp);
		printf("wp : %d\n", wp);
		printf("\n");


		printf("횟초리 휘두르기 (MAX : %d) : 1\n", hachori);
		printf("정신 공격 (MAX : %d) : 2\n", jungsin);
		printf("할로 포인트 (MAX : %d) : 3\n", halopoint);
		printf("36계 줄행랑 : 4\n");

		Sleep(50);
		system("cls");

		printf("┌------------------------------------------------┐\n");
		printf("│         ■             ■                      │\n");
		printf("│       ■■            ■■                     │\n");
		printf("│        ■■■      ■■■                      │\n");
		printf("│         ■■■■■■■■                       │\n");
		printf("│         ■■  □■■ □■         못해?        │\n");
		printf("│         ■■■■┼ ┼ ■■                       │\n");
		printf("│      ■■■■■■■■■■■                    │\n");
		printf("│   ■■ ■■■■■■■■■  ■■     -user-     │\n");
		printf("└------------------------------------------------┘\n\n");

		printf("hp : %d\n", hp);
		printf("sp : %d\n", sp);
		printf("wp : %d\n", wp);
		printf("\n");


		printf("횟초리 휘두르기 (MAX : %d) : 1\n", hachori);
		printf("정신 공격 (MAX : %d) : 2\n", jungsin);
		printf("할로 포인트 (MAX : %d) : 3\n", halopoint);
		printf("36계 줄행랑 : 4\n");

		Sleep(50);
		system("cls");

		printf("┌------------------------------------------------┐\n");
		printf("│         ■             ■                      │\n");
		printf("│       ■■            ■■                     │\n");
		printf("│        ■■■      ■■■                      │\n");
		printf("│         ■■■■■■■■                       │\n");
		printf("│         ■■  □■■ □■         에휴         │\n");
		printf("│         ■■■■┼ ┼ ■■                       │\n");
		printf("│      ■■■■■■■■■■■                    │\n");
		printf("│   ■■ ■■■■■■■■■  ■■     -user-     │\n");
		printf("└------------------------------------------------┘\n\n");

		printf("hp : %d\n", hp);
		printf("sp : %d\n", sp);
		printf("wp : %d\n", wp);
		printf("\n");


		printf("횟초리 휘두르기 (MAX : %d) : 1\n", hachori);
		printf("정신 공격 (MAX : %d) : 2\n", jungsin);
		printf("할로 포인트 (MAX : %d) : 3\n", halopoint);
		printf("36계 줄행랑 : 4\n");

		Sleep(50);
		system("cls");

		printf("┌------------------------------------------------┐\n");
		printf("│         ■             ■                      │\n");
		printf("│       ■■            ■■                     │\n");
		printf("│        ■■■      ■■■                      │\n");
		printf("│         ■■■■■■■■                       │\n");
		printf("│         ■■  □■■ □■         벌레         │\n");
		printf("│         ■■■■┼ ┼ ■■                       │\n");
		printf("│      ■■■■■■■■■■■                    │\n");
		printf("│   ■■ ■■■■■■■■■  ■■     -user-     │\n");
		printf("└------------------------------------------------┘\n\n");

		printf("hp : %d\n", hp);
		printf("sp : %d\n", sp);
		printf("wp : %d\n", wp);
		printf("\n");


		printf("횟초리 휘두르기 (MAX : %d) : 1\n", hachori);
		printf("정신 공격 (MAX : %d) : 2\n", jungsin);
		printf("할로 포인트 (MAX : %d) : 3\n", halopoint);
		printf("36계 줄행랑 : 4\n");

		Sleep(50);
		system("cls");

		printf("┌------------------------------------------------┐\n");
		printf("│         ■             ■                      │\n");
		printf("│       ■■            ■■                     │\n");
		printf("│        ■■■      ■■■                      │\n");
		printf("│         ■■■■■■■■                       │\n");
		printf("│         ■■  □■■ □■         같은         │\n");
		printf("│         ■■■■┼ ┼ ■■                       │\n");
		printf("│      ■■■■■■■■■■■                    │\n");
		printf("│   ■■ ■■■■■■■■■  ■■     -user-     │\n");
		printf("└------------------------------------------------┘\n\n");

		printf("hp : %d\n", hp);
		printf("sp : %d\n", sp);
		printf("wp : %d\n", wp);
		printf("\n");


		printf("횟초리 휘두르기 (MAX : %d) : 1\n", hachori);
		printf("정신 공격 (MAX : %d) : 2\n", jungsin);
		printf("할로 포인트 (MAX : %d) : 3\n", halopoint);
		printf("36계 줄행랑 : 4\n");

		Sleep(50);
		system("cls");

		printf("┌------------------------------------------------┐\n");
		printf("│         ■             ■                      │\n");
		printf("│       ■■            ■■                     │\n");
		printf("│        ■■■      ■■■                      │\n");
		printf("│         ■■■■■■■■                       │\n");
		printf("│         ■■  □■■ □■         shaki        │\n");
		printf("│         ■■■■┼ ┼ ■■                       │\n");
		printf("│      ■■■■■■■■■■■                    │\n");
		printf("│   ■■ ■■■■■■■■■  ■■     -user-     │\n");
		printf("└------------------------------------------------┘\n\n");

		printf("hp : %d\n", hp);
		printf("sp : %d\n", sp);
		printf("wp : %d\n", wp);
		printf("\n");


		printf("횟초리 휘두르기 (MAX : %d) : 1\n", hachori);
		printf("정신 공격 (MAX : %d) : 2\n", jungsin);
		printf("할로 포인트 (MAX : %d) : 3\n", halopoint);
		printf("36계 줄행랑 : 4\n");

		Sleep(50);
		system("cls");

		printf("┌------------------------------------------------┐\n");
		printf("│         ■             ■                      │\n");
		printf("│       ■■            ■■                     │\n");
		printf("│        ■■■      ■■■                      │\n");
		printf("│         ■■■■■■■■                       │\n");
		printf("│         ■■  □■■ □■         그렇게       │\n");
		printf("│         ■■■■┼ ┼ ■■                       │\n");
		printf("│      ■■■■■■■■■■■                    │\n");
		printf("│   ■■ ■■■■■■■■■  ■■     -user-     │\n");
		printf("└------------------------------------------------┘\n\n");

		printf("hp : %d\n", hp);
		printf("sp : %d\n", sp);
		printf("wp : %d\n", wp);
		printf("\n");


		printf("횟초리 휘두르기 (MAX : %d) : 1\n", hachori);
		printf("정신 공격 (MAX : %d) : 2\n", jungsin);
		printf("할로 포인트 (MAX : %d) : 3\n", halopoint);
		printf("36계 줄행랑 : 4\n");

		Sleep(50);
		system("cls");

		printf("┌------------------------------------------------┐\n");
		printf("│         ■             ■                      │\n");
		printf("│       ■■            ■■                     │\n");
		printf("│        ■■■      ■■■                      │\n");
		printf("│         ■■■■■■■■                       │\n");
		printf("│         ■■  □■■ □■         살면         │\n");
		printf("│         ■■■■┼ ┼ ■■                       │\n");
		printf("│      ■■■■■■■■■■■                    │\n");
		printf("│   ■■ ■■■■■■■■■  ■■     -user-     │\n");
		printf("└------------------------------------------------┘\n\n");

		printf("hp : %d\n", hp);
		printf("sp : %d\n", sp);
		printf("wp : %d\n", wp);
		printf("\n");


		printf("횟초리 휘두르기 (MAX : %d) : 1\n", hachori);
		printf("정신 공격 (MAX : %d) : 2\n", jungsin);
		printf("할로 포인트 (MAX : %d) : 3\n", halopoint);
		printf("36계 줄행랑 : 4\n");

		Sleep(50);
		system("cls");

		printf("┌------------------------------------------------┐\n");
		printf("│         ■             ■                      │\n");
		printf("│       ■■            ■■                     │\n");
		printf("│        ■■■      ■■■                      │\n");
		printf("│         ■■■■■■■■                       │\n");
		printf("│         ■■  □■■ □■         재밌냐?      │\n");
		printf("│         ■■■■┼ ┼ ■■                       │\n");
		printf("│      ■■■■■■■■■■■                    │\n");
		printf("│   ■■ ■■■■■■■■■  ■■     -user-     │\n");
		printf("└------------------------------------------------┘\n\n");

		printf("hp : %d\n", hp);
		printf("sp : %d\n", sp);
		printf("wp : %d\n", wp);
		printf("\n");


		printf("횟초리 휘두르기 (MAX : %d) : 1\n", hachori);
		printf("정신 공격 (MAX : %d) : 2\n", jungsin);
		printf("할로 포인트 (MAX : %d) : 3\n", halopoint);
		printf("36계 줄행랑 : 4\n");

		Sleep(50);
		system("cls");

		printf("┌------------------------------------------------┐\n");
		printf("│         ■             ■                      │\n");
		printf("│       ■■            ■■                     │\n");
		printf("│        ■■■      ■■■                      │\n");
		printf("│         ■■■■■■■■                       │\n");
		printf("│         ■■  □■■ □■         ㅉㅉ         │\n");
		printf("│         ■■■■┼ ┼ ■■                       │\n");
		printf("│      ■■■■■■■■■■■                    │\n");
		printf("│   ■■ ■■■■■■■■■  ■■     -user-     │\n");
		printf("└------------------------------------------------┘\n\n");

		printf("hp : %d\n", hp);
		printf("sp : %d\n", sp);
		printf("wp : %d\n", wp);
		printf("\n");


		printf("횟초리 휘두르기 (MAX : %d) : 1\n", hachori);
		printf("정신 공격 (MAX : %d) : 2\n", jungsin);
		printf("할로 포인트 (MAX : %d) : 3\n", halopoint);
		printf("36계 줄행랑 : 4\n");

		Sleep(50);
		system("cls");
	}
} // 모션 종료

void fightmotion4(int sp, int hp, int wp, int hachori, int jungsin, int halopoint) {//유저의 공격 모션_3

	system("cls");

	printf("┌------------------------------------------------┐\n");
	printf("│         ■             ■                      │\n");
	printf("│       ■■            ■■                     │\n");
	printf("│        ■■■      ■■■                      │\n");
	printf("│         ■■■■■■■■                       │\n");
	printf("│         ■■  □■■ □■     할.로.포.인.트   │\n");
	printf("│         ■■■■┼ ┼ ■■                       │\n");
	printf("│      ■■■■■■■■■■■                    │\n");
	printf("│   ■■ ■■■■■■■■■  ■■     -user-     │\n");
	printf("└------------------------------------------------┘\n\n");

	printf("hp : %d\n", hp);
	printf("sp : %d\n", sp);
	printf("wp : %d\n", wp);
	printf("\n");


	printf("횟초리 휘두르기 (MAX : %d) : 1\n", hachori);
	printf("정신 공격 (MAX : %d) : 2\n", jungsin);
	printf("할로 포인트 (MAX : %d) : 3\n", halopoint);
	printf("36계 줄행랑 : 4\n");

	Sleep(500);
	system("cls");

	printf("┌------------------------------------------------┐\n");
	printf("│         ■             ■                      │\n");
	printf("│       ■■            ■■      할로가....     │\n");
	printf("│        ■■■      ■■■          진다.....   │\n");
	printf("│         ■■■■■■■■                       │\n");
	printf("│         ■■  □■■ □■   ┌-----┤            │\n");
	printf("│         ■■■■┼ ┼ ■■  ■■┤---┘            │\n");
	printf("│      ■■■■■■■■■■■■-┘                │\n");
	printf("│   ■■ ■■■■■■■■■           -user-     │\n");
	printf("└------------------------------------------------┘\n\n");

	printf("hp : %d\n", hp);
	printf("sp : %d\n", sp);
	printf("wp : %d\n", wp);
	printf("\n");


	printf("횟초리 휘두르기 (MAX : %d) : 1\n", hachori);
	printf("정신 공격 (MAX : %d) : 2\n", jungsin);
	printf("할로 포인트 (MAX : %d) : 3\n", halopoint);
	printf("36계 줄행랑 : 4\n");

	Sleep(500);
	system("cls");

	for (int i = 1; i <= 10; i++) {

		printf("┌------------------------------------------------┐\n");
		printf("│         ■             ■                      │\n");
		printf("│       ■■            ■■                     │\n");
		printf("│        ■■■      ■■■                      │\n");
		printf("│         ■■■■■■■■                       │\n");
		printf("│         ■■  □■■ □■   ┌-----┤  _         │\n");
		printf("│         ■■■■┼ ┼ ■■  ■■┤---┘            │\n");
		printf("│      ■■■■■■■■■■■■-┘                │\n");
		printf("│   ■■ ■■■■■■■■■           -user-     │\n");
		printf("└------------------------------------------------┘\n\n");

		printf("hp : %d\n", hp);
		printf("sp : %d\n", sp);
		printf("wp : %d\n", wp);
		printf("\n");


		printf("횟초리 휘두르기 (MAX : %d) : 1\n", hachori);
		printf("정신 공격 (MAX : %d) : 2\n", jungsin);
		printf("할로 포인트 (MAX : %d) : 3\n", halopoint);
		printf("36계 줄행랑 : 4\n");

		Sleep(30);
		system("cls");

		printf("┌------------------------------------------------┐\n");
		printf("│         ■             ■                      │\n");
		printf("│       ■■            ■■                     │\n");
		printf("│        ■■■      ■■■                      │\n");
		printf("│         ■■■■■■■■                       │\n");
		printf("│         ■■  □■■ □■   ┌-----┤     _      │\n");
		printf("│         ■■■■┼ ┼ ■■  ■■┤---┘            │\n");
		printf("│      ■■■■■■■■■■■■-┘                │\n");
		printf("│   ■■ ■■■■■■■■■           -user-     │\n");
		printf("└------------------------------------------------┘\n\n");

		printf("hp : %d\n", hp);
		printf("sp : %d\n", sp);
		printf("wp : %d\n", wp);
		printf("\n");


		printf("횟초리 휘두르기 (MAX : %d) : 1\n", hachori);
		printf("정신 공격 (MAX : %d) : 2\n", jungsin);
		printf("할로 포인트 (MAX : %d) : 3\n", halopoint);
		printf("36계 줄행랑 : 4\n");

		Sleep(30);
		system("cls");

		printf("┌------------------------------------------------┐\n");
		printf("│         ■             ■                      │\n");
		printf("│       ■■            ■■                     │\n");
		printf("│        ■■■      ■■■                      │\n");
		printf("│         ■■■■■■■■                       │\n");
		printf("│         ■■  □■■ □■   ┌-----┤          _ │\n");
		printf("│         ■■■■┼ ┼ ■■  ■■┤---┘            │\n");
		printf("│      ■■■■■■■■■■■■-┘                │\n");
		printf("│   ■■ ■■■■■■■■■           -user-     │\n");
		printf("└------------------------------------------------┘\n\n");

		printf("hp : %d\n", hp);
		printf("sp : %d\n", sp);
		printf("wp : %d\n", wp);
		printf("\n");


		printf("횟초리 휘두르기 (MAX : %d) : 1\n", hachori);
		printf("정신 공격 (MAX : %d) : 2\n", jungsin);
		printf("할로 포인트 (MAX : %d) : 3\n", halopoint);
		printf("36계 줄행랑 : 4\n");

		Sleep(30);
		system("cls");

		printf("┌------------------------------------------------┐\n");
		printf("│         ■             ■                      │\n");
		printf("│       ■■            ■■                     │\n");
		printf("│        ■■■      ■■■                      │\n");
		printf("│         ■■■■■■■■                       │\n");
		printf("│         ■■  □■■ □■   ┌-----┤_          _│\n");
		printf("│         ■■■■┼ ┼ ■■  ■■┤---┘            │\n");
		printf("│      ■■■■■■■■■■■■-┘                │\n");
		printf("│   ■■ ■■■■■■■■■           -user-     │\n");
		printf("└------------------------------------------------┘\n\n");

		printf("hp : %d\n", hp);
		printf("sp : %d\n", sp);
		printf("wp : %d\n", wp);
		printf("\n");


		printf("횟초리 휘두르기 (MAX : %d) : 1\n", hachori);
		printf("정신 공격 (MAX : %d) : 2\n", jungsin);
		printf("할로 포인트 (MAX : %d) : 3\n", halopoint);
		printf("36계 줄행랑 : 4\n");

		Sleep(30);
		system("cls");

	}
}

void monsterturn2(int sp, int hp, int wp, int hachori, int jungsin, int halopoint) { // 몬스터의 공격 모션_1

	printf("┌------------------------------------------------┐\n");
	printf("│    하.진.투.법              ■■■■■         │\n");
	printf("│   -   침.퉷   -           ■■■■■■■       │\n");
	printf("│                          ■□ ■■□ ■■      │\n");
	printf("│                         ■■■■■■■■■     │\n");
	printf("│                         ■■■○■■■■■     │\n");
	printf("│                          ■■■■■■■■      │\n");
	printf("│                           ■■■■■■■       │\n");
	printf("│                            ■■■■■■■      │\n");
	printf("└------------------------------------------------┘\n\n");

	printf("hp : %d\n", hp);
	printf("sp : %d\n", sp);
	printf("wp : %d\n", wp);
	printf("\n");


	printf("횟초리 휘두르기 (MAX : %d) : 1\n", hachori);
	printf("정신 공격 (MAX : %d) : 2\n", jungsin);
	printf("할로 포인트 (MAX : %d) : 3\n", halopoint);
	printf("36계 줄행랑 : 4\n");

	Sleep(1000);
	system("cls");

	for (int i = 1; i <= 10; i++) {
		printf("┌------------------------------------------------┐\n");
		printf("│                             ■■■■■         │\n");
		printf("│                           ■■■■■■■       │\n");
		printf("│                          ■□ ■■□ ■■      │\n");
		printf("│                         ■■■■■■■■■     │\n");
		printf("│                         ■※■○■■■■■     │\n");
		printf("│                          ■■■■■■■■      │\n");
		printf("│                           ■■■■■■■       │\n");
		printf("│                            ■■■■■■■      │\n");
		printf("└------------------------------------------------┘\n\n");

		printf("hp : %d\n", hp);
		printf("sp : %d\n", sp);
		printf("wp : %d\n", wp);
		printf("\n");


		printf("횟초리 휘두르기 (MAX : %d) : 1\n", hachori);
		printf("정신 공격 (MAX : %d) : 2\n", jungsin);
		printf("할로 포인트 (MAX : %d) : 3\n", halopoint);
		printf("36계 줄행랑 : 4\n");

		Sleep(30);
		system("cls");

		printf("┌------------------------------------------------┐\n");
		printf("│                             ■■■■■         │\n");
		printf("│                           ■■■■■■■       │\n");
		printf("│                          ■□ ■■□ ■■      │\n");
		printf("│                         ■■■■■■■■■     │\n");
		printf("│                     ※  ■■■○■■■■■     │\n");
		printf("│                          ■■■■■■■■      │\n");
		printf("│                           ■■■■■■■       │\n");
		printf("│                            ■■■■■■■      │\n");
		printf("└------------------------------------------------┘\n\n");

		printf("hp : %d\n", hp);
		printf("sp : %d\n", sp);
		printf("wp : %d\n", wp);
		printf("\n");


		printf("횟초리 휘두르기 (MAX : %d) : 1\n", hachori);
		printf("정신 공격 (MAX : %d) : 2\n", jungsin);
		printf("할로 포인트 (MAX : %d) : 3\n", halopoint);
		printf("36계 줄행랑 : 4\n");

		Sleep(30);
		system("cls");

		printf("┌------------------------------------------------┐\n");
		printf("│                             ■■■■■         │\n");
		printf("│                           ■■■■■■■       │\n");
		printf("│                          ■□ ■■□ ■■      │\n");
		printf("│                         ■■■■■■■■■     │\n");
		printf("│            ※           ■■■○■■■■■     │\n");
		printf("│                          ■■■■■■■■      │\n");
		printf("│                           ■■■■■■■       │\n");
		printf("│                            ■■■■■■■      │\n");
		printf("└------------------------------------------------┘\n\n");

		printf("hp : %d\n", hp);
		printf("sp : %d\n", sp);
		printf("wp : %d\n", wp);
		printf("\n");


		printf("횟초리 휘두르기 (MAX : %d) : 1\n", hachori);
		printf("정신 공격 (MAX : %d) : 2\n", jungsin);
		printf("할로 포인트 (MAX : %d) : 3\n", halopoint);
		printf("36계 줄행랑 : 4\n");

		Sleep(30);
		system("cls");


		printf("┌------------------------------------------------┐\n");
		printf("│                             ■■■■■         │\n");
		printf("│                           ■■■■■■■       │\n");
		printf("│                          ■□ ■■□ ■■      │\n");
		printf("│                         ■■■■■■■■■     │\n");
		printf("│                         ■■■○■■■■■     │\n");
		printf("│      ※                  ■■■■■■■■      │\n");
		printf("│                           ■■■■■■■       │\n");
		printf("│                            ■■■■■■■      │\n");
		printf("└------------------------------------------------┘\n\n");

		printf("hp : %d\n", hp);
		printf("sp : %d\n", sp);
		printf("wp : %d\n", wp);
		printf("\n");


		printf("횟초리 휘두르기 (MAX : %d) : 1\n", hachori);
		printf("정신 공격 (MAX : %d) : 2\n", jungsin);
		printf("할로 포인트 (MAX : %d) : 3\n", halopoint);
		printf("36계 줄행랑 : 4\n");

		Sleep(30);
		system("cls");

		printf("┌------------------------------------------------┐\n");
		printf("│                             ■■■■■         │\n");
		printf("│                           ■■■■■■■       │\n");
		printf("│                          ■□ ■■□ ■■      │\n");
		printf("│                         ■■■■■■■■■     │\n");
		printf("│                         ■■■○■■■■■     │\n");
		printf("│                          ■■■■■■■■      │\n");
		printf("│※                         ■■■■■■■       │\n");
		printf("│                            ■■■■■■■      │\n");
		printf("└------------------------------------------------┘\n\n");

		printf("hp : %d\n", hp);
		printf("sp : %d\n", sp);
		printf("wp : %d\n", wp);
		printf("\n");


		printf("횟초리 휘두르기 (MAX : %d) : 1\n", hachori);
		printf("정신 공격 (MAX : %d) : 2\n", jungsin);
		printf("할로 포인트 (MAX : %d) : 3\n", halopoint);
		printf("36계 줄행랑 : 4\n");

		Sleep(30);
		system("cls");
	}

}

void monsterturn3(int sp, int hp, int wp, int hachori, int jungsin, int halopoint) { // 몬스터의 공격 모션_2
	system("cls");

	printf("┌------------------------------------------------┐\n");
	printf("│    하.진.투.법              ■■■■■         │\n");
	printf("│   -   딱.밤   -           ■■■■■■■       │\n");
	printf("│                          ■□ ■■□ ■■      │\n");
	printf("│             ■■        ■■■■■■■■■     │\n");
	printf("│           ■■■■      ■■■○■■■■■     │\n");
	printf("│          ■■   ■■     ■■■■■■■■      │\n");
	printf("│            ■■   ■■    ■■■■■■■       │\n");
	printf("│                    ■■    ■■■■■■■      │\n");
	printf("└------------------------------------------------┘\n\n");

	printf("hp : %d\n", hp);
	printf("sp : %d\n", sp);
	printf("wp : %d\n", wp);
	printf("\n");


	printf("횟초리 휘두르기 (MAX : %d) : 1\n", hachori);
	printf("정신 공격 (MAX : %d) : 2\n", jungsin);
	printf("할로 포인트 (MAX : %d) : 3\n", halopoint);
	printf("36계 줄행랑 : 4\n");

	Sleep(1000);
	system("cls");

	for (int i = 1; i <= 20; i++) {

		printf("┌------------------------------------------------┐\n");
		printf("│                             ■■■■■         │\n");
		printf("│                           ■■■■■■■       │\n");
		printf("│                          ■□ ■■□ ■■      │\n");
		printf("│             ■■        ■■■■■■■■■     │\n");
		printf("│           ■■■■      ■■■○■■■■■     │\n");
		printf("│          ■■   ■■     ■■■■■■■■      │\n");
		printf("│            ■■   ■■    ■■■■■■■       │\n");
		printf("│                    ■■    ■■■■■■■      │\n");
		printf("└------------------------------------------------┘\n\n");
		printf("hp : %d\n", hp);
		printf("sp : %d\n", sp);
		printf("wp : %d\n", wp);
		printf("\n");


		printf("횟초리 휘두르기 (MAX : %d) : 1\n", hachori);
		printf("정신 공격 (MAX : %d) : 2\n", jungsin);
		printf("할로 포인트 (MAX : %d) : 3\n", halopoint);
		printf("36계 줄행랑 : 4\n");

		Sleep(30);
		system("cls");


		printf("┌------------------------------------------------┐\n");
		printf("│            ■               ■■■■■         │\n");
		printf("│           ■              ■■■■■■■       │\n");
		printf("│            ■            ■□ ■■□ ■■      │\n");
		printf("│             ■■        ■■■■■■■■■     │\n");
		printf("│               ■■      ■■■○■■■■■     │\n");
		printf("│                 ■■     ■■■■■■■■      │\n");
		printf("│                   ■■    ■■■■■■■       │\n");
		printf("│                    ■■    ■■■■■■■      │\n");
		printf("└------------------------------------------------┘\n\n");

		printf("hp : %d\n", hp);
		printf("sp : %d\n", sp);
		printf("wp : %d\n", wp);
		printf("\n");


		printf("횟초리 휘두르기 (MAX : %d) : 1\n", hachori);
		printf("정신 공격 (MAX : %d) : 2\n", jungsin);
		printf("할로 포인트 (MAX : %d) : 3\n", halopoint);
		printf("36계 줄행랑 : 4\n");

		Sleep(30);
		system("cls");

	}
}


void monsterturn4(int sp, int hp, int wp, int hachori, int jungsin, int halopoint) { // 몬스터의 공격 모션_3


	printf("┌------------------------------------------------┐\n");
	printf("│    하.진.투.법                                 │\n");
	printf("│   -  발.찱.이  -                ■■           │\n");
	printf("│                              ■■■■■        │\n");
	printf("│                             ■□■□■■       │\n");
	printf("│                           ■ ■○■■■ ■     │\n");
	printf("│                          ■   ■■■■   ■    │\n");
	printf("│                              ■■   ■■       │\n");
	printf("│                           ■■         ■■    │\n");
	printf("└------------------------------------------------┘\n\n");


	printf("hp : %d\n", hp);
	printf("sp : %d\n", sp);
	printf("wp : %d\n", wp);
	printf("\n");


	printf("횟초리 휘두르기 (MAX : %d) : 1\n", hachori);
	printf("정신 공격 (MAX : %d) : 2\n", jungsin);
	printf("할로 포인트 (MAX : %d) : 3\n", halopoint);
	printf("36계 줄행랑 : 4\n");

	Sleep(1000);
	system("cls");

	for (int i = 1; i <= 7; i++) {

		printf("┌------------------------------------------------┐\n");
		printf("│                                                │\n");
		printf("│                                 ■■           │\n");
		printf("│                              ■■■■■        │\n");
		printf("│                          ■ ■□■□■■       │\n");
		printf("│                           ■ ■○■■■ ■     │\n");
		printf("│                       ■      ■■■■   ■    │\n");
		printf("│                        ■■■■     ■■       │\n");
		printf("│                                        ■■    │\n");
		printf("└------------------------------------------------┘\n\n");

		printf("hp : %d\n", hp);
		printf("sp : %d\n", sp);
		printf("wp : %d\n", wp);
		printf("\n");


		printf("횟초리 휘두르기 (MAX : %d) : 1\n", hachori);
		printf("정신 공격 (MAX : %d) : 2\n", jungsin);
		printf("할로 포인트 (MAX : %d) : 3\n", halopoint);
		printf("36계 줄행랑 : 4\n");

		Sleep(30);
		system("cls");


		printf("┌------------------------------------------------┐\n");
		printf("│                                                │\n");
		printf("│                                 ■■           │\n");
		printf("│                              ■■■■■        │\n");
		printf("│                          ■ ■□■□■■       │\n");
		printf("│                           ■ ■○■■■ ■     │\n");
		printf("│               ■              ■■■■   ■    │\n");
		printf("│                ■■■■■■■■     ■■       │\n");
		printf("│                                        ■■    │\n");
		printf("└------------------------------------------------┘\n\n");

		printf("hp : %d\n", hp);
		printf("sp : %d\n", sp);
		printf("wp : %d\n", wp);
		printf("\n");


		printf("횟초리 휘두르기 (MAX : %d) : 1\n", hachori);
		printf("정신 공격 (MAX : %d) : 2\n", jungsin);
		printf("할로 포인트 (MAX : %d) : 3\n", halopoint);
		printf("36계 줄행랑 : 4\n");

		Sleep(30);
		system("cls");


		printf("┌------------------------------------------------┐\n");
		printf("│                                                │\n");
		printf("│                                 ■■           │\n");
		printf("│                              ■■■■■        │\n");
		printf("│                          ■ ■□■□■■       │\n");
		printf("│                           ■ ■○■■■ ■     │\n");
		printf("│ ■                            ■■■■   ■    │\n");
		printf("│  ■■■■■■■■■■■■■■■     ■■       │\n");
		printf("│                                        ■■    │\n");
		printf("└------------------------------------------------┘\n\n");

		printf("hp : %d\n", hp);
		printf("sp : %d\n", sp);
		printf("wp : %d\n", wp);
		printf("\n");


		printf("횟초리 휘두르기 (MAX : %d) : 1\n", hachori);
		printf("정신 공격 (MAX : %d) : 2\n", jungsin);
		printf("할로 포인트 (MAX : %d) : 3\n", halopoint);
		printf("36계 줄행랑 : 4\n");

		Sleep(30);
		system("cls");


		printf("┌------------------------------------------------┐\n");
		printf("│                                                │\n");
		printf("│                                 ■■           │\n");
		printf("│                              ■■■■■        │\n");
		printf("│                          ■ ■□■□■■       │\n");
		printf("│                           ■ ■○■■■ ■     │\n");
		printf("│               ■              ■■■■   ■    │\n");
		printf("│                ■■■■■■■■     ■■       │\n");
		printf("│                                        ■■    │\n");
		printf("└------------------------------------------------┘\n\n");

		printf("hp : %d\n", hp);
		printf("sp : %d\n", sp);
		printf("wp : %d\n", wp);
		printf("\n");


		printf("횟초리 휘두르기 (MAX : %d) : 1\n", hachori);
		printf("정신 공격 (MAX : %d) : 2\n", jungsin);
		printf("할로 포인트 (MAX : %d) : 3\n", halopoint);
		printf("36계 줄행랑 : 4\n");

		Sleep(30);
		system("cls");


		printf("┌------------------------------------------------┐\n");
		printf("│                                                │\n");
		printf("│                                 ■■           │\n");
		printf("│                              ■■■■■        │\n");
		printf("│                          ■ ■□■□■■       │\n");
		printf("│                           ■ ■○■■■ ■     │\n");
		printf("│                       ■      ■■■■   ■    │\n");
		printf("│                        ■■■■     ■■       │\n");
		printf("│                                        ■■    │\n");
		printf("└------------------------------------------------┘\n\n");

		printf("hp : %d\n", hp);
		printf("sp : %d\n", sp);
		printf("wp : %d\n", wp);
		printf("\n");


		printf("횟초리 휘두르기 (MAX : %d) : 1\n", hachori);
		printf("정신 공격 (MAX : %d) : 2\n", jungsin);
		printf("할로 포인트 (MAX : %d) : 3\n", halopoint);
		printf("36계 줄행랑 : 4\n");

		Sleep(30);
		system("cls");


		printf("┌------------------------------------------------┐\n");
		printf("│                                                │\n");
		printf("│                                 ■■           │\n");
		printf("│                              ■■■■■        │\n");
		printf("│                             ■□■□■■       │\n");
		printf("│                           ■ ■○■■■ ■     │\n");
		printf("│                          ■   ■■■■   ■    │\n");
		printf("│                              ■■   ■■       │\n");
		printf("│                           ■■         ■■    │\n");
		printf("└------------------------------------------------┘\n\n");

		printf("hp : %d\n", hp);
		printf("sp : %d\n", sp);
		printf("wp : %d\n", wp);
		printf("\n");


		printf("횟초리 휘두르기 (MAX : %d) : 1\n", hachori);
		printf("정신 공격 (MAX : %d) : 2\n", jungsin);
		printf("할로 포인트 (MAX : %d) : 3\n", halopoint);
		printf("36계 줄행랑 : 4\n");

		Sleep(30);
		system("cls");

	}
}


void userinterface1(int linehp, int linesp, int linewp, int point, int hp, int sp, int wp) {// 유저 인터페이스 (메뉴)
	printf("┌--------------------------------┐\n");
	printf("│☆★☆★☆★☆★☆★☆★☆★☆★│\n");
	printf("│    랄-랄루 포켓치킨몬 게-임    │\n");
	printf("│☆★☆★☆★☆★☆★☆★☆★☆★│\n");
	printf("└--------------------------------┘\n");
	printf("\n\n");

	printf("PRICE : 1hp/%d , 1sp/%d, 1wp/%d\n\n", linehp, linesp, linewp);

	printf("GOLD : %d\n", point);
	printf("hp : %d\n", hp);
	printf("sp : %d\n", sp);
	printf("wp : %d\n", wp);
	printf("\n");


	printf("포켓치킨몬과의 전투 : 1\n");
	printf("방어구 레벨업 : 2\n");
	printf("무기 레벨업 : 3\n");
	printf("체력 회복 : 4\n");
}


void hajinmon(int monsterhp, int hp, int sp, int wp, int hachori, int jungsin, int halopoint) { // 대련 인터페이스
	printf("┌------------------------------------------------┐\n");
	printf("│                                    ■■■      │\n");
	printf("│   hp : %3d                       ■□■□■    │\n", hp);
	printf("│  ■      ■                   ■ ■■○■■ ■ │\n");
	printf("│    □■□             VS     ■  ■■■■■  ■│\n");
	printf("│ ■ ■■■ ■■                  ■  ■ ■ ■   │\n");
	printf("│ ■ ■■■                    -pocket Hajinmon- │\n");
	printf("│    ■  ■                         hp : %3d     │\n", monsterhp);
	printf("│    -user-                                      │\n");
	printf("└------------------------------------------------┘\n\n");

	printf("hp : %d\n", hp);
	printf("sp : %d\n", sp);
	printf("wp : %d\n", wp);
	printf("\n");


	printf("횟초리 휘두르기 (MAX : %d) : 1\n", hachori);
	printf("정신 공격 (MAX : %d) : 2\n", jungsin);
	printf("할로 포인트 (MAX : %d) : 3\n", halopoint);
	printf("36계 줄행랑 : 4\n");
}
