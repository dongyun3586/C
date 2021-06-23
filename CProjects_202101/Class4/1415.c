#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

#define _CRT_SECURE_NO_WARNINGS  
#define MAX_PLAY 5       //최대 등록 선수 개수 정의 

void init_player(int idx);     //해당 입력된 index의 선수 값을(level, value) 초기화 한다
int reinforce_player(int idx);    //선택된 선수의 강화를 실행하고 결과를 1:성공, 0: 실패 return 한다  
int selling_player(char name[], int idx);    //선택된 선수를 팔고 계정에 BP 와 Level을 누적 한다
long long player_value_gen(int level);     //강화 level에 해당하는 BP를 재귀 함수로 계산하여 return 한다(증가)
long long player_value_dec(int level);     //강화 level에 해당하는 BP를 재귀 함수로 계산하여 return 한다(감소)
void list_players(char arr[][20], int col, int row);    //등록된 선수 정보를 출력 한다
void sort_players_level(char arr[][20], int col, int row);   //등록된 선수를 강화 level 순으로 정렬 한다
void sort_players_value(char arr[][20], int col, int row);   //등록된 선수를 가치 BP 순으로 정렬 한다 

struct player_info_t {      //강화 프로그램의 Level & Value 정보를 가진 구조체 type을 선언
	int level;

	long long value;
};

struct player_info_t player_info[MAX_PLAY];   //등록된 선수 MAX_PLAY=5명에 대한 level & value 정보를 가진 구조체 배열 정의
struct player_info_t my_account;      //강화 프로그램을 진행하는 사용자의 총 BP 및 Level 정보를 저장할 구조체 변수 정의

int main() {
	char players[MAX_PLAY][20] = { "호나우두","베컴    ","크루이프","베르캄프","굴리트  " };   //선수 이름 등록

	int col, row;       //선수 이름 행과 열 변수

	int menu_num, select_num;    //scanf 로 입력 받을 변수

	for (int i = 0; i < MAX_PLAY; i++)    //선수 5명의 Level=1, BP를 초기화 한다 
	{
		init_player(i);
	}

	my_account.value = 0;    //강화 프로그램 이용자 계정 초기화

	my_account.level = 0;

	col = sizeof(players[0]) / sizeof(char);   //선수 이름 배열의 행과 열 계산

	row = sizeof(players) / sizeof(players[0]);


	while (1) {    //while() 구문을 이용하여 기본 메뉴 "7...끝내기" 가  선택 되어지지 않으면 계속 반복 한다
		system("cls");
		printf("------------------------------------------\n");
		printf("  월드 Class 축구 선수 강화 프로그램 메뉴 \n");
		printf("------------------------------------------\n");
		printf("1. 선수 목록 보기\n");
		printf("2. 월드 Class 축구 선수 강화\n");
		printf("3. 월드 Class 축구 선수 판매\n");
		printf("4. 강화단계 순서 정렬 보기\n");
		printf("5. 선수 가치 우선 정렬 보기\n");
		printf("6. 나의 선수 판매 결과(BP 계정) 보기\n");
		printf("7. 프로그램 끝내기\n");
		printf("------------------------------------------\n");

		printf("메뉴를 선택 하시오 : ");

		scanf("%d", &menu_num);    //이용자가 원하는 menu 번호를 입력 받는다


		switch (menu_num) {    //입력 받은 번호로 switch..case 구문을 사용하여 입력 된 메뉴 번호로 이동한다

		case 1:

			list_players(players, col, row);  //등록된 선수의 기본 정보를 출력 한다
			Sleep(3000);
			printf("\n\n");
			break;

		case 2:

			list_players(players, col, row);  //등록된 선수들을 출력하고

			do {     //등록 되어진 선수가 선택될 때가지 do..while 구문을 이용하여 계속한다 

				printf("-------------------------------\n");

				printf("강화할 선수를 선택 하세요:");

				scanf("%d", &select_num);

				if (select_num > MAX_PLAY) {


					printf("\n---등록되지 않은 선수 번호를 입력 하였습니다.---\n");


				}

			} while (select_num > MAX_PLAY);

			if (reinforce_player(select_num - 1))   //배열이므로 선택된 선수번호-1 을 하여 이용자가 원하는 선수의 강화를 실행한다.

			{
				printf("\n강화 시도중...\n");
				Sleep(1000);

				system("color 2F");
				printf("\n#################\n");

				printf("### 강화 성공 ###\n");      //reinforce_player 함수 return 이 "1" 이면 성공

				printf("#################\n\n");

				Sleep(1000);
				system("color 0F");

				list_players(players, col, row);    //강화를 성공하면 변경되는 선수 정보 출력

			}

			else

			{
				printf("강화 시도중...");
				Sleep(1000);
				system("color 4F");
				printf("\n!!!!!!!!!!!!!!!!!\n");

				printf("!!! 강화 실패 !!!\n");     //reinforce_player 함수 return 이 "0" 이면 실패

				printf("!!!!!!!!!!!!!!!!!\n\n");

				Sleep(1000);
				system("color 0F");
				printf("\n\n");
			}

			break;

		case 3:

			list_players(players, col, row);    //등록된 선수들을 보여준다



			do {      //판매할 선수를 선택될 때가지 do..while 구문을 이용하여 계속한다

				printf("--------------------------\n");

				printf("판매할 선수를 선택 하세요:");



				scanf("%d", &select_num);



				if (select_num > MAX_PLAY) {

					printf("\n---등록되지 않은 선수 번호를 입력 하였습니다.---\n");

				}

			} while (select_num > MAX_PLAY);



			selling_player(players[select_num - 1], select_num - 1);  //선택된 선수번호-1의 배열 index 값으로 선수 판매 함수를 호출한다
			Sleep(1000);
			printf("\n\n");
			break;

		case 4:

			sort_players_level(players, col, row);    //선수 강화 순서로 등록 순서를 sorting 한다
			Sleep(3000);
			printf("\n\n");
			break;

		case 5:

			sort_players_value(players, col, row);    //선수 가치 순서로 등록 순서를 sorting 한다
			Sleep(3000);
			printf("\n\n");
			break;

		case 6:        //강화 프로그램 이용자의 계정 정보를 출력 한다

			printf("\n+++++++++++++++++++++++++++++++++++++++++++++++++\n");

			printf("+++ 당신의 총 자산 가치는 %10ld BP 입니다+++", my_account.value);

			printf("\n+++++++++++++++++++++++++++++++++++++++++++++++++");

			printf("\n+++     총 누적 강화는 %5d level  입니다    +++", my_account.level);

			printf("\n+++++++++++++++++++++++++++++++++++++++++++++++++\n\n");
			Sleep(3000);
			printf("\n\n");
			break;

		case 7:

			goto end;    //프로그램 끝내기를 선택하면 메뉴 while() 구문을 탈출하여 선언된":end"로 실행 위치를 이동한다.
			Sleep(1000);
			printf("\n\n");
			break;

		default:

			printf("\n---메뉴에 없는 번호를 입력 하였습니다.---\n");  //잘못된 메뉴 번호 선택시 안내를 출력 한다
			Sleep(1000);
			break;

		}

	}

end:
	return 0;
}

void init_player(int idx)   //idx에 해당하는 선수 값을(level, value) 초기화 한다
{
	player_info[idx].level = 1;    // 1 level

	player_info[idx].value = player_value_gen(player_info[idx].level);  //1 level에 해당하는 BP 값
}


int reinforce_player(int idx)  //선택된 선수의 강화를 실행하고 결과를 1:성공, 0: 실패 return 한다
{

	srand(time(NULL));

	int probability = rand();  //random 함수를 이용해 임의의 정수를 발생 시킨다

	int agent;



	agent = player_info[idx].level;   //선택된 선수의 현재 level을 agent에 대입한다



	if (((probability % 10) != agent) && (agent == 1)) {   //Level 1 일때는 임의의 숫자가 10으로 나누어 나머지가 1이 아니면 무조건 강화 성공

		player_info[idx].level++;    //Level 증가

		player_info[idx].value = player_value_gen(player_info[idx].level);    //BP 발생 함수를 호출하여 BP값 return 받는다

		return 1;    //강화 성공

	}

	if (probability % (agent) == 0) {   //Level 2 이상이면 임의의 발생수가 Level로 나누어 떨어지면(나머지=0) 강화 성공이다

		player_info[idx].level++;  //Level 증가

		player_info[idx].value = player_value_gen(player_info[idx].level);   //BP 발생 함수를 호출하여 해당 Level 만큰 재귀 호출하여 BP값 return 받는다

		return 1;    //강화 성공

	}

	player_info[idx].level--;
	player_info[idx].value = player_value_dec(player_info[idx].level);

	return 0;

}



int selling_player(char name[], int idx)   //선택된 선수를 팔고 계정에 BP 와 Level을 누적 한다

{

	my_account.value += player_info[idx].value;  //가치 BP 누적

	my_account.level += player_info[idx].level;   //Level 누적



	printf("\n###########################################################\n");

	printf("### %s 선수가 %d BP에 판매가 완료 되었습니다. ###\n", name, player_info[idx].value);

	printf("###########################################################\n\n");



	init_player(idx);     //판매된 선수는 Level 값을 1 로 초기화 한다



	printf("-------------------------------------------------\n");

	printf("------ 누적된 자산은 %10ld BP 입니다.-------\n", my_account.value);

	printf("-------------------------------------------------\n");

}



long long player_value_gen(int level)   //강화 level에 해당하는 BP를 재귀 함수로 계산하여 return 한다

{

	if (level == 1)

	{

		return((rand() % 10 + 1) * 10);    //Level=1 이 될때 누적된 재귀 호출된 함수가 1~10 곱으로 계산되어 값을 return 한다 

	}



	srand(time(NULL));



	return player_value_gen(level - 1) * (rand() % 10 + 1);  //1~10의 곱에 대한 재귀 호출

}
long long player_value_dec(int level)   //강화 level에 해당하는 BP를 재귀 함수로 계산하여 return 한다

{
	if (level == 1)

	{

		return((rand() % 10 + 1) * 10);    //Level=1 이 될때 누적된 재귀 호출된 함수가 1~10 곱으로 계산되어 값을 return 한다 

	}



	srand(time(NULL));



	return player_value_gen(level - 1) * (rand() % 10 + 1);  //1~10의 곱에 대한 재귀 호출

}




void list_players(char arr[][20], int col, int row)   //등록된 선수 정보를 출력 한다

{

	printf("-------------------------------\n");

	printf("   World Class 축구 선수 정보  \n");

	printf("-------------------------------\n");



	for (int i = 0; i < row; i++) //선수이름과 해당 index에 해당하는 선수의 level 및 가치 정보 출력 

	{

		printf("%d - %s  %d 강 %ld BP \n", i + 1, arr[i], player_info[i].level, player_info[i].value);

	}

}



void sort_players_level(char arr[][20], int col, int row)    //등록된 선수를 강화 level 순으로 정렬 한다

{

	struct player_info_t temp_info;   //비교해서 값을 치환할때 vale & level을 저장하기 위한 임시변수

	char temp_name[20];     //비교해서 값을 치환할때 선수이름을 임시로 저장하기 위한 변수



	printf("-------------------------------------------\n");

	printf("   World Class 축구 선수 강화 Level 순서   \n");

	printf("-------------------------------------------\n");



	for (int i = 0; i < MAX_PLAY - 1; i++)    //등록된 선수 마지막 앞까지 크기 비교

	{

		for (int j = i + 1; j < MAX_PLAY; j++)    //등록된 선수의 처음 부터 하나씩 증가 시키며 level 순으로 오름 차순 정렬

		{

			if (player_info[j].level > player_info[i].level)   //지정된 선수 강화 level 위치 i번째와 나머지 뒷 부분 비교 

			{

				temp_info = player_info[i];     //배열 뒤에 값 j index가 크면 level & value가 저장된 구조체 변수 위치(i<->j)를 변경한다

				player_info[i] = player_info[j];

				player_info[j] = temp_info;



				strcpy(temp_name, arr[i]);    //선수이름도 strcpy 함수를 이용하여 바꾸어 준다

				strcpy(arr[i], arr[j]);

				strcpy(arr[j], temp_name);

			}

		}

	}



	for (int i = 0; i < row; i++)    //순서가 변경된 선수 등록 정보를 출력 한다

	{

		printf("%d - %s  %d 강 %ld BP \n", i + 1, arr[i], player_info[i].level, player_info[i].value);

	}

}

void sort_players_value(char arr[][20], int col, int row) //등록된 선수를 가치 BP 순으로 정렬 한다

{

	struct player_info_t temp_info;  //비교해서 값을 치환할때 vale & level을 임시로 저장하기 위한 변수

	char temp_name[20];    //비교해서 값을 치환할때 선수이름을 임시로 저장하기 위한 변수

	printf("-----------------------------------------\n");

	printf("   World Class 축구 선수 가치 정보 순서  \n");

	printf("-----------------------------------------\n");


	for (int i = 0; i < MAX_PLAY - 1; i++)  //등록된 선수 마지막 앞까지 크기 비교

	{

		for (int j = i + 1; j < MAX_PLAY; j++) //등록된 선수의 처음 부터 하나씩 증가 시키며 value 순서로 오름 차순 정렬

		{

			if (player_info[j].value > player_info[i].value)  //지정된 선수 value 위치 i번째와 나머지 뒷 부분 비교

			{

				temp_info = player_info[i];    //배열 뒤에 값 j index가 크면 level & value가 저장된 구조체 변수 위치(i<->j)를 변경한다

				player_info[i] = player_info[j];

				player_info[j] = temp_info;



				strcpy(temp_name, arr[i]);    //선수이름도 strcpy 함수를 이용하여 바꾸어 준다

				strcpy(arr[i], arr[j]);

				strcpy(arr[j], temp_name);

			}

		}

	}

	for (int i = 0; i < row; i++)   //순서가 변경된 선수 등록 정보를 출력 한다

	{

		printf("%d - %s  %d 강 %ld BP \n", i + 1, arr[i], player_info[i].level, player_info[i].value);

	}

}