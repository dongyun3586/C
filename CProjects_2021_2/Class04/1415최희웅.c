// player_trade_market.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

#define _CRT_SECURE_NO_WARNINGS

#define SIZE_ID 12		  //아이디 입력 최대 크가
#define SIZE_PW 12		 //암호 최대크기
#define CIPHER  3			 //암호화 복호화 시프트 수치

typedef unsigned int UINT;     //수업시간에 배운 UINT 선언
typedef unsigned long int ULONG;    //unsigned long int를 ULONG 선언

typedef struct _User_Info {      //사용자의 user id 와 암호를 가진 구조체
	char id[SIZE_ID];				//아이디 멤버
	char password[SIZE_PW];		//암호 멤버
}User_Info;

typedef struct _Football_Player {	//축구선수 한명의 정보에 대한 선언들을 가지고 있는 구조체
	char name[20];				//선수 이름
	char nation[20];			//출신 국가
	UINT position;				//주포지션
	UINT ability;					//능력치
	ULONG value;				//가치
	UINT level;					//선수 강화 레벨
}Football_Player;

typedef struct _User_Data {      //사용자별 정보에 대한 선어들을 갖고 있는 구조체
	char id[SIZE_ID];				//사용자 ID
	Football_Player players[22];	//구단이 가지는 선수수 22명 최대	
	ULONG bp;						//사용자가 가지고 있는 BP
	UINT num_players;			//구단이 보유한 선수 수
	UINT point;						//판매 실적에 따른 가점 
}User_Data;

enum Login { ID = 1, PASSWORD = 2, EXIT = 3 };   //초기 모드의 switch 구문 선택 문구 정의
enum Main_Menu { BUY_M = 1, SELL_M = 2, LIST_M = 3, FORCE = 4, HISTORY = 5, LOG_OUT = 6, END_G = 7 };
enum Trade_Type { BUY, SELL };					//구매=0, 판매=1 구분 정보

void encrypt(char* cipher, int shift) {		//사용지 ID와 Password를 암호화 한다
	for (int i = 0; cipher[i] != '\0'; i++) {
		cipher[i] += shift;
	}
}

void decrypt(char* cipher, int shift) {		//사용자 ID 와 Password를 복호화 한다
	for (int i = 0; cipher[i] != '\0'; i++) {
		cipher[i] -= shift;
	}
}

UINT user_info_read(int num_user, User_Info* user_data)   //등록된 사용자의 ID 및 Password 값들을 File에서 불러 온다
{
	FILE* user_fp = NULL;
	char id[SIZE_ID] = { 0 };			//ID 문자열 초기화
	char password[SIZE_PW] = { 0 };			//Password 문자열 초기화

	user_fp = fopen(".\\user_info.txt", "r+");       //등록된 사용자 정보 file을 open 한다

	if (user_fp == NULL) {			 // 파일 열기에 실패했을때
		printf("사용자 정보 파일 열기에 실패하였습니다.\n");
		return 0;
	}

	for (int i = 0; i < num_user; i++) {			//등록된 사용자 수만큼 for loop 수행
		fread(id, SIZE_PW, 1, user_fp);					//file 포인터 에서 ID 정보를 읽어 온다
		decrypt(id, CIPHER);								//암호화를 해제한다
		strcpy(user_data[i].id, id);					//user_data 구조체에 ID 정보 입력
		fread(password, SIZE_PW, 1, user_fp);			//file 포인터 에서 password 정보를 읽어 온다
		decrypt(password, CIPHER);						//암호화를 해제한다
		strcpy(user_data[i].password, password);    //user_data 구조체에 password 정보 복사
	}

	fclose(user_fp);				//file 을 닫는다

	return 1;
}

UINT user_info_write(char* id, char* password, int user_cnt) {	//등록된 사용자 정보를 저장한다
	FILE* ufp;
	FILE* nfp;
	char ntemp[5];

	ufp = fopen(".\\user_info.txt", "a+");    //사용자 ID와 password를 암호화 해서 file에 추가 저장 한다	

	if (ufp == NULL) {           // 파일 열기에 실패했을때
		printf("사용자 정보 파일 open에 실패하였습니다.\n");
		return 0;
	}
	encrypt(id, CIPHER);				//사용자 ID 암호화
	fwrite(id, SIZE_ID, sizeof(char), ufp);		//일정 크기로 기록
	encrypt(password, CIPHER);				//Password 암호와
	fwrite(password, SIZE_PW, sizeof(char), ufp);   //일정 크기로 기록
	fclose(ufp);

	nfp = fopen(".\\user_no.txt", "w+");    	//동일한 file에 새롭게 사용자 수를 기록 한다

	if (nfp == NULL) {			 // 파일 열기에 실패했을때
		printf("사용자 등록수 파일 open에 실패하였습니다.\n");
		return 0;
	}

	sprintf(ntemp, "%02d", user_cnt);      //총 등록된 사용자의 수
	fwrite(ntemp, 2, 1, nfp);					//사용자수 가진 파일에 기록
	fclose(nfp);

	return 1;
}

UINT check_login_id(char* user_id, int num_user, User_Info* user_data)    //입력한 ID가 사용자 정보에 있는지 확인한다
{
	for (int i = 0; i < num_user; i++) {			//사용자 수만큼 for loop 수행 
		if (strcmp(user_data[i].id, user_id) == 0) {
			return i + 1;				//user_data 구조체에 일치하는 사용자 ID가 있으면 사용자 위치 index에 '1'을 더한 후 return
		}
	}

	return 0;				//일치하는 user ID가 없으면 '0' return
}

UINT check_login_password(char* user_pw, UINT user_idx, User_Info* user_data)    //입력한 password가 사용자 정보에 있는지 확인한다
{
	if (strcmp(user_data[user_idx - 1].password, user_pw) == 0) {
		return 1;			//user_data 구조체의 ID 정보와 match 하는 위치에 일치하는 사용자 password가 있으면 '1' return
	}
	else {
		return 0;			//password 정보가 일치하지 않음
	}
}

void read_player_data(Football_Player* one_player, char* one_line) {     //파일에 있는 선수 정보를 읽어 공백으로 구조체 멤버 정보들을 분리하여 대입해 준다
	char* read_one;
	read_one = strtok(one_line, " ");   //" " 공백으로 첫번째 단어를 분리하여 name에 복사한다
	strcpy(one_player->name, read_one);
	read_one = strtok(NULL, " ");		//strtok가 가지고 있는 포인터 위치에서 다시 공백을 찾아 출신 국가를 복사한다
	strcpy(one_player->nation, read_one);
	read_one = strtok(NULL, " ");		//동일한 방법으로 Footbll_Player의 포지션 정보 대입한다
	one_player->position = atoi(read_one);
	read_one = strtok(NULL, " ");		//동일한 방법으로 Footbll_Player의 능력치 정보 대입한다
	one_player->ability = atoi(read_one);
	read_one = strtok(NULL, " ");		//동일한 방법으로 Footbll_Player의 가치 정보 대입한다
	one_player->value = atol(read_one);
	read_one = strtok(NULL, " ");		//동일한 방법으로 Footbll_Player의 강화 정보 대입한다
	one_player->level = atoi(read_one);
}

UINT load_player(Football_Player* all_player) {
	const UINT max = 512;             //한줄의 최대 길이
	char one_line[max];                   //한줄을 읽는 스트링 버퍼
	char* read_one;						//읽은 Data줄의 첫번째를 가리키는 포인터 변수
	FILE* in = fopen(".\\player_info.txt", "r");        //이적시장에 등록 되어 있는 선수 정보를 가지고 있는 file
	UINT register_player = 0;			//등록된 선수의 수를 계산하여 return

	if (in == NULL) {			 // 파일 열기에 실패했을때
		printf("축구 선수 등록 파일 open에 실패하였습니다.\n");
		return 0;
	}


	while (!feof(in)) {						//file의 마지막까지 읽는다
		if (fgets(one_line, max, in) == NULL) {
			break;			//한줄을 읽어 오는데 문자열이 없으면 그만 읽는다	
		}
		read_player_data(all_player, one_line);
		register_player++;					//한줄에 한명씩 선수 개수를 추가한다
		all_player++;						//Football_Player 구조체 변수 all_player의 다음 위치로 이동한다
	}
	fclose(in);								//file을 닫는다

	return register_player;				//등록된 총 선수 개수를 return 한다
}

void print_players(Football_Player* player, UINT num_player)   //Football_Player 구조체에 해당 하는 선수 정보를 출력 한다
{
	printf("       선수명    출신국가  포지션  능력       가치    등급 \n");
	printf("***********************************************************\n");

	for (int i = 0; i < num_player; i++) //선수이름과 해당 index에 해당하는 선수의 level 및 가치 정보 출력 
	{
		char position_name[5][3] = { "GK", "DF", "MF", "CF", "ST" };      //저장된 정수값을 선수 포지션 별칭으로 표현한다
		printf("%02d | %10s %10s   %02s    %03d %12ld   %01d 강 \n", i + 1, player->name, player->nation, position_name[player->position], player->ability, player->value, player->level);
		player++;				//선수 정보를 하나씩 출력 한다
	}

	printf("***********************************************************\n");
}

UINT user_data_init(User_Data user_data, char* id) {
	FILE* fp;
	char filename[20];
	char one_line[20];

	user_data.bp = 20000;      //가입 기념 2만 BP를 지급한다.
	user_data.num_players = 0;	     //초기 구매 선수는 0 이다
	user_data.point = 0;				//사용자 판매 가점
	strcpy(user_data.id, id);           //user id를 user_data 구저체에 입력

	sprintf(filename, ".\\%s.txt", id);		//사용자 ID로 파일이름을 정한다
	fp = fopen(filename, "w+");			//쓰기 전용으로 파일을 open 한다
	if (fp == NULL) {			 // 파일 열기에 실패했을때
		printf("사용자  정보 파일 open에 실패하였습니다.\n");
		return 0;
	}
	sprintf(one_line, "%ld\n", user_data.bp);		//사용자 BP 정보를 처음 line에 기록
	fputs(one_line, fp);
	sprintf(one_line, "%d\n", user_data.num_players);		//두번째 line에 사용자가 소유한 선수의 개수를 기록
	fputs(one_line, fp);
	sprintf(one_line, "%d\n", user_data.point);		//세번째 line에 사용자가 소유한 판매 가점을 기록
	fputs(one_line, fp);
	fclose(fp);			//파일을 닫는다

	return 1;
}

UINT user_data_read(User_Data* user_data) {
	FILE* fp;
	char filename[20];						//사용자 정보를 가지고 있는 파일 이름
	const UINT max = 512;             //한줄의 최대 길이
	char one_line[max];                   //한줄을 읽는 스트링 버퍼

	sprintf(filename, ".\\%s.txt", user_data->id);
	fp = fopen(filename, "r+");         //사용자 정보를 가진 파일을 open 한다
	if (fp == NULL) {			 // 파일 열기에 실패했을때
		printf("사용자 정보 파일 열기에 실패하였습니다.\n");
		return 0;
	}
	fgets(one_line, max, fp);
	user_data->bp = (ULONG)atol(one_line);	//사용자 BP 정보를 한줄 읽어와 user_data에 대입한다
	fgets(one_line, max, fp);
	user_data->num_players = (UINT)atoi(one_line);	//사용자 선수 보유 개수 정보를 한줄 읽어와 user_data에 대입한다
	fgets(one_line, max, fp);
	user_data->point = (UINT)atoi(one_line);	//사용자 판매 가점 정보를 한줄 읽어와 user_data에 대입한다

	if (user_data->num_players > 0) {
		UINT idx = 0;
		while (idx < user_data->num_players) {		//사용자가 보유한 선수의 정보를 읽어 온다
			fgets(one_line, max, fp);
			read_player_data(&(user_data->players[idx]), one_line);	//한줄을 읽어와 단어를 찾아 players 구조체에 값을 넣어주는 함수를 호출한다
			idx++;     //다음 선수로 넘어간다
		}
	}

	fclose(fp);

	return 1;
}

UINT user_data_write(User_Data* user_data) {
	FILE* fp;
	char filename[20];
	const UINT max = 512;             //한줄의 최대 길이
	char one_line[max];                   //한줄을 읽는 스트링 버퍼
	UINT idx = 0;							//구단 선수정보 정보를 가리키는 변수

	sprintf(filename, ".\\%s.txt", user_data->id);
	fp = fopen(filename, "w+");						//쓰기 전용으로 파일을 open 한다
	if (fp == NULL) {			 // 파일 열기에 실패했을때
		printf("사용자 정보 파일 열기에 실패하였습니다.\n");
		return 0;
	}
	sprintf(one_line, "%ld\n", user_data->bp);
	fputs(one_line, fp);									//사용자 BP 정보를 한줄 기록 한다
	sprintf(one_line, "%d\n", user_data->num_players);
	fputs(one_line, fp);									//두번째 line에 사용자가 소유한 선수의 개수를 기록 한다
	sprintf(one_line, "%d\n", user_data->point);
	fputs(one_line, fp);									//세번째 line에 사용자가 소유한 판매 가점을 기록

	while (idx < user_data->num_players) {		//나머지 줄들에 가진 선수 수만큼 선수들의 정보를 저장한다.
		sprintf(one_line, "%s %s %d %d %ld %d\n", user_data->players[idx].name, user_data->players[idx].nation,
			user_data->players[idx].position, user_data->players[idx].ability, user_data->players[idx].value, user_data->players[idx].level);
		fputs(one_line, fp);     //선수 정보 형태로 만들어 한명 정보를 파일 한줄에 저장한다
		idx++;
	}
	fclose(fp);

	return 1;
}

ULONG team_value(User_Data current_user) {
	ULONG total_value = 0;
	for (int i = 0; i < current_user.num_players; i++) {    //사용자가 가지고 있는 선수 개수만큼 for loop 수행   
		total_value += current_user.players[i].value;			//각 선수의 가치값을 합산한다
	}
	return total_value;		//합산된 값을 돌려 준다
}

ULONG player_value_gen(UINT level)   //강화 성공에 따른 level 수치에 따라 가치를 상향한다.
{
	return((rand() % level + 1));    //Level이 높을수록 rand()를 나눈 값이 커질수 있어 더큰 가치를 가진다. 
}

UINT reinforce_player(User_Data* current_user, UINT idx)  //선택된 선수의 강화를 실행하고 결과를 1:성공, 0: 실패 return 한다
{
	srand(time(NULL));
	UINT probability = rand();  //random 함수를 이용해 임의의 정수를 발생 시킨다
	UINT agent;

	agent = current_user->players[idx].level;   //샌택된 선수의 현재 level을 agent에 대입한다

	if (((probability % 10) != agent) && (agent == 1)) {   //Level 1 일때는 임의의 숫자가 10으로 나누어 나머지가 1이 아니면 무조건 강화 성공
		current_user->players[idx].level++;    //Level 증가
		current_user->players[idx].value = current_user->players[idx].value * player_value_gen(current_user->players[idx].level);    //BP 발생 함수를 호출하여 BP값 return 받는다
		return 1;    //강화 성공
	}

	if (probability % (agent) == 0) {   //Level 2 이상이면 임의의 발생수가 Level로 나누어 떨어지면(나머지=0) 강화 성공이다
		current_user->players[idx].level++;  //Level 증가
		current_user->players[idx].value = current_user->players[idx].value * player_value_gen(current_user->players[idx].level);  //BP 발생 함수를 호출하여 해당 Level 만큰 재귀 호출하여 BP값 return 받는다
		return 1;    //강화 성공
	}

	if (current_user->players[idx].value > 1000) {		//강화를 실패하면 선수의 가치 1000BP를 줄인다
		current_user->players[idx].value -= 1000;
		printf("### 강화 실패로 선수 가치 1000 BP 줄어 들었습니다.###\n");
	}
	return 0;
}

UINT user_history_read(User_Data* user_data) {		//사용자 구매 및 판매 정보를 기록하는 함수
	FILE* fp;
	char filename[20];
	const UINT max = 512;             //한줄의 최대 길이
	char one_line[max];                   //한줄을 읽는 스트링 버퍼
	UINT type;
	char* read_one;
	Football_Player data;

	sprintf(filename, ".\\%s_h.txt", user_data->id);		//사용자 구매 및 판매 이력을 저장할 파일 이름
	fp = fopen(filename, "r+");			//파일을 생성하고 아무것도 저장하지 않는다

	if (fp == NULL) {			 // 파일 열기에 실패했을때
		printf("사용자 이력 파일 열기에 실패하였습니다.\n");
		return 0;
	}

	for (int i = 0; i < user_data->point; i++) {      //구매와 판매가 누적된 수 point  만큼 이력을 출력 시켜준다
		if (feof(fp)) {				//만약 파일의 마지막이면 for loop 탈출
			break;
		}
		fgets(one_line, max, fp);				//한줄을 읽어 들인다
		read_one = strtok(one_line, " ");
		type = (UINT)atoi(read_one);	//구매인지 판매인지 변수를 읽어 온다

		read_one = strtok(NULL, "\0");	//저장된 나머지 문자열은 선수 정보에 대한 내용을 가져온다

		if (type == 0) {
			printf("구매선수: ");
		}
		else {
			printf("판매선수: ");
		}
		read_player_data(&data, read_one);	//선수정보를 읽어온 문자열로 축구선수정보 구조체에 각 변수에 맞게 자료형을 가져오는 함수 호출
		printf("%s %s %d %d %ld %d\n", data.name, data.nation, data.position, data.ability, data.value, data.level);		//선수 정보 출력 한다
	}
	fclose(fp);			//파일을 닫는다

	return 1;
}

UINT user_history_write(User_Data* user_data, Football_Player data, UINT type) {		//사용자 구매 및 판매 정보를 기록하는 함수
	FILE* fp;
	char filename[20];
	const UINT max = 512;             //한줄의 최대 길이
	char one_line[max];                   //한줄을 읽는 스트링 버퍼

	sprintf(filename, ".\\%s_h.txt", user_data->id);		//사용자 구매 및 판매 이력을 저장할 파일 이름
	fp = fopen(filename, "a+");			//파일을 data 추가 형태로 열어준다

	if (fp == NULL) {			 // 파일 열기에 실패했을때
		printf("사용자 이력 파일 열기에 실패하였습니다.\n");
		return 0;
	}

	sprintf(one_line, "%d %s %s %d %d %ld %d\n", type, data.name, data.nation, data.position, data.ability, data.value, data.level);
	fputs(one_line, fp);						//구매 및 판매 여부와 선수 정보를 기록한다

	fclose(fp);			//파일을 닫는다

	return 1;
}

UINT buying_player(Football_Player* all_player, User_Data* current_user, UINT no_reg_player) {
	UINT selected_num = 0;
	Football_Player* selected_player;
	do {
		printf("---------------------------------------------------------\n");
		print_players(all_player, no_reg_player);					//구매 가능한 모든 선수를 출력해 준다
		printf("구매할 선수를 선택 하세요 (이전 메뉴 = 0) : ");
		scanf("%d", &selected_num);							//구매할 선수 번호 선택
		if (selected_num > no_reg_player) {					//번호가 벗어났을 경우
			printf("\n---등록되지 않은 선수 번호를 입력 하였습니다.---\n");
		}
	} while (selected_num > no_reg_player);

	if (selected_num == 0) { return 0; }			//'0' 인 경우 이전 메뉴로 이동한다

	selected_player = all_player + selected_num - 1;		//전체 list에서 선택된 선수의 포인터를 대입해 준다

	if (current_user->bp > selected_player->value) {
		current_user->bp -= selected_player->value;			//구매한 선수 가치를 사용자 BP에서 차감하여 준다
		current_user->num_players++;					//구단 선수 개수 1명 증가시킨다
		current_user->players[current_user->num_players - 1] = *(selected_player);    //선택한 선수 정보를 user_data 구조체의 plaers 구조체 type에 대입한다
		current_user->point++;			//선수 구매에 대한 가점 한개 증가
		printf("###########################################\n");
		printf("###  %10s 선수 구매를 축하합니다. ### \n", selected_player->name);
		printf("###########################################\n");
		printf("구매한 선수 정보를 확인하세요\n");
		if (current_user->point % 4 == 0) {		//가점 4점이 되면 보너스 천 BP 부여
			current_user->bp += 1000;		//판매한 선수의 가치를 사용자 BP에 더해 준다다
			printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
			printf("$$$ 구매판매 포인트 1000 BP 추가로 획득 하였습니다. $$$\n");
			printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
		}
		else {
			printf("-------------------------------------------------------\n");
		}

		print_players(selected_player, 1);		//구매한 선수 정보 출력
		printf("현재의 총 구단 가치는 %ld BP로 상향 되었습니다.\n", team_value(*current_user));
		user_data_write(current_user);							//user data 파일에 선수 구매에 대한 변경된 내용을 저장한다
		user_history_write(current_user, *selected_player, BUY);		//구매한 선수에 대한 기록을 파일에 남긴다
		return 1;
	}
	else {
		printf("-------------------------------------------------------\n");
		printf("!!! 사용할 BP가 부족하여 구매가 불가능 합니다 !!! \n");
	}
}

UINT selling_player(Football_Player* all_player, User_Data* current_user) {
	UINT selected_num = 0;		//판매할 선수 선택 번호
	UINT idx = 0;					//판매한 선수 삭제하고 위로 데이타 올릴때 사용한 위치 변수	

	do {
		printf("-------------------------------------------------------\n");
		print_players(current_user->players, current_user->num_players);		//보유하고 있는 선수들 출력
		printf("-------------------------------------------------------\n");
		printf("판매할 선수를 선택 하세요 (이전 메뉴 = 0) : ");
		scanf("%d", &selected_num);

		if (selected_num > current_user->num_players) {
			printf("\n---등록되지 않은 선수 번호를 입력 하였습니다.---\n");
		}
	} while (selected_num > current_user->num_players);		//선택이 이루어 질때까지 수행

	if (selected_num == 0) { return 0; }		//이전 메뉴로 이동

	idx = selected_num - 1;      //판매를 선택한 선수의 index
	current_user->bp += current_user->players[idx].value;		//판매한 선수의 가치를 사용자 BP에 더해 준다
	current_user->point++;   //판매가 이루어 지면 사용가점을 부여한다
	current_user->num_players--;		//판매된 선수 1명의 소유 개수에서 차감

	user_history_write(current_user, current_user->players[idx], SELL);		//판매한 선수에 대한 기록을 파일에 남긴다

	printf("\n#################################################################\n");
	printf("### %10s 선수가 %10ld BP에 판매가 완료 되었습니다. ###\n", current_user->players[idx].name, current_user->players[idx].value);
	printf("#################################################################\n");

	if (current_user->point % 4 == 0) {		//가점 4점이 되면 보너스 천 BP 부여
		current_user->bp += 1000;		//판매한 선수의 가치를 사용자 BP에 더해 준다다
		printf("$$$ 구매판매에 대한 1000 BP 추가로 획득 하였습니다. $$$\n");
		printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
	}
	printf("-----------------------------------------------------------\n");
	printf(" %s 님 사용 가능한 포인트는 %10ld BP 입니다.\n", current_user->id, current_user->bp);


	for (int i = idx; i < current_user->num_players; i++) {	//판매된 선수를 삭제하고 선수 Data를 위로 하나씩 올려 준다
		current_user->players[i] = current_user->players[i + 1];
	}
	user_data_write(current_user);		//사용자 파일에 변경된 정보를 저장한다

	return 0;
}

int main() {
	UINT menu_num, select_num;    //scanf 로 입력 받을 변수

	UINT num_of_user = 0;
	User_Info* user_info = nullptr;     //사용자 ID 및 Password 정보 구조체 포인터
	UINT user_index = 0;					//입력한 ID가 위치한 user_info
	User_Data user_data{};				//사용자 정보 
	UINT user_approved = 0;			//사용자가 인증 되면 '1" 
	UINT pass_fail = 0;

	char input_id[12] = { 0 };			//입력 ID 초기화
	char input_pw[12] = { 0 };		//입력 password 초기화
	char read_buf[20];

	FILE* num_fp = NULL;			//사용자 수를 기록한 파일 포인터

	num_fp = fopen(".\\user_no.txt", "r");    //등록된 사용자 수가 저장된 file을 open 한다
	if (num_fp == NULL) {			 // 파일 등록자수 파일 열기에 실패했을때
		printf("사용자 등록수 파일 open에 실패하였습니다.\n");
		return 0;
	}
	fread(read_buf, 2, 1, num_fp);
	fclose(num_fp);

	num_of_user = (UINT)atoi(read_buf);		//등록된 사용자 수를 문자형에서 정수형 변환하여 대입하여 준다

	while (!user_approved) {    //while() 구문을 이용하여 기본 메뉴 "7...끝내기" 가  선택 되어지지 않으면 계속 반복 한다
		printf("------------------------------------------\n");
		printf("등록된 ID가 없으면 가입을 진행하세요. \n");
	login:
		printf("------------------------------------------\n");
		printf("1. 사용자 로그인\n");
		printf("2. 이적시장 가입하기\n");
		printf("3. 종료하기\n");
		printf("------------------------------------------\n");

		printf("메뉴를 선택 하시오 : ");
		scanf("%d", &menu_num);    //이용자가 원하는 menu 번호를 입력 받는다
		getchar();			//'\n' 을 제거하여 준다

		switch (menu_num) {    //입력 받은 번호로 switch..case 구문을 사용하여 입력 된 메뉴 번호로 이동한다
		case ID:
			user_info = (User_Info*)calloc(num_of_user, sizeof(User_Info));     //사용자 등록 수만큼 user_info 메모리를 동적 할당한다.
			user_info_read(num_of_user, user_info);      //user_data 구조체에 등록된 사용자 수 'num_of_user' 만큼의 정보를 file에서 읽어 온다
		user:
			printf("------------------------------------------\n");
			printf("사용자 ID를 입력 하시오: ");
			fgets(input_id, 12, stdin);								//사용자 ID를 입력 받는다
			input_id[strlen(input_id) - 1] = '\0';				//fgets로 입력 받은 마지막 값 '\n'을 문자의 끝 '\0' 으로 변경한다 			
			user_index = check_login_id(input_id, num_of_user, user_info);	//사용자 ID가 있는지 검사하고 찾으면 위치를 user_index 대입		
			if (user_index == 0) {     //user_index가 '0'보다 크면 다음으로 간다
				printf("------------------------------------------\n");
				printf("ID \"%s\" 는 등록된 정보에 없습니다.\n", input_id);
				if (user_info != nullptr) {
					free(user_info);									//로그인 메뉴로 가기에 user_info 메모리 해제시킨다
				}
				goto login;				//사용자 ID  정보가 없으면 ID 입력 위치로 이동한다
			}
		pass:
			printf("------------------------------------------\n");
			printf("사용자 암호를 입력 하시오: ");
			fgets(input_pw, 12, stdin);					//사용자 암호를 입력 받는다
			input_pw[strlen(input_pw) - 1] = '\0';	//fgets로 입력 받은 마지막 값 '\n'을 문자의 끝 '\0' 으로 변경한다

			if (check_login_password(input_pw, user_index, user_info) == 0) {		//입력한 사용자의 암호가 일치하면 다음으로 이동 한다	
				printf("------------------------------------------\n");
				printf("ID \"%s\" 의 암호와 일치하지 않습니다. \n", input_id);
				pass_fail++;
				if (pass_fail >= 3) {
					if (user_info != nullptr) {
						free(user_info);									//로그인 메뉴로 가기에 user_info 메모리 해제시킨다
					}
					pass_fail = 0;
					printf("!!! ID \"%s\"의 암호 인증에 3회 실패하여 로그인으로 이동 합니다. !!!\n", input_id);
					goto login;
				}
				goto pass;				//사용자 암호가 일치하지 않으면 암호 입력 위치로 이동 한다	
			}

			user_approved = 1;		//사용자 승인 정보 저장	
			free(user_info);
			strcpy(user_data.id, input_id);			//user_data 정보에 ID를 대입한다.
			user_data_read(&user_data);			//해당 ID 이름으로 생성된 user file을 user_data에 넣어준다.
			user_data.bp += 500;
			user_data_write(&user_data);
			printf("------------------------------------------\n");
			printf("### 접속 보너스 5백 BP가 지급되었습니다 ###\n");
			break;
		case PASSWORD:
			printf("------------------------------------------\n");
			printf("2. 이적시장 사용자를 등록 합니다.\n");
			printf("------------------------------------------\n");
			printf("등록 ID 입력(10자리이내): ");
			fgets(input_id, 12, stdin);						//새로운 사용자의 ID를 입력 받는다
			input_id[strlen(input_id) - 1] = '\0';		//fgets로 입력 받은 마지막 값 '\n'을 문자의 끝 '\0' 으로 변경한다
			//getchar();
			printf("------------------------------------------\n");
			printf("사용자 암호 입력(10자리이내): ");
			fgets(input_pw, 12, stdin);				//새로운 사용자의 암호를 입력 받는다
			input_pw[strlen(input_pw) - 1] = '\0';	//fgets로 입력 받은 마지막 값 '\n'을 문자의 끝 '\0' 으로 변경한다
			num_of_user++;								//등록된 사용자 수를 증가 시킨다
			user_info_write(input_id, input_pw, num_of_user);        //사용자 ID 와 암호를 user 정보 파일에 기록한다

			decrypt(input_id, CIPHER);				//암호화된 ID를 풀어서 정상적인 ID로 만든다
			user_data_init(user_data, input_id);	//ID이름으로 user 정보 file을 생성한다

			printf("------------------------------------------\n");
			printf("%s님 사용자 등록이 완료되었습니다. \n", input_id);
			printf("------------------------------------------\n");
			printf("### 가입 기념 20,000BP가 지급되었습다. ###\n");
			printf("------------------------------------------\n");
			printf("등록한 정보로 로그인 하세요\n");
			goto login;
			break;
		case EXIT:
			goto end;
			break;
		default:
			printf("\n---메뉴에 없는 번호를 입력 하였습니다.---\n");  //잘못된 메뉴 번호 선택시 안내를 출력 한다
			break;
		}
	}

	while (1) {
		UINT num_reg_player;
		Football_Player all_player[100];
	selling:
		num_reg_player = load_player(all_player);   //구매가 가능한 모든 선수들을 all_player 구조체에 불러 오고 총 선수 수를 return 받는다.
	menu:
		printf("\n\n---------------------------------------------------------------------------\n");
		printf(" 화이팅 하세요 %s 님 이적 시장 주메뉴 입니다.\n", user_data.id);
		printf("보유 선수는 %d 명, 구단가치 %ld BP, 사용가능 BP는 %ld BP 입니다.\n", user_data.num_players, team_value(user_data), user_data.bp);
		printf("---------------------------------------------------------------------------\n");
		printf("1. 선수 구매하기\n");
		printf("2. 선수 판매하기\n");
		printf("3. 구단 정보\n");
		printf("4. 선수 강화\n");
		printf("5. 구매 / 판매 이력\n");
		printf("6. 로그아웃\n");
		printf("7. 종료\n");
		printf("------------------------------------------\n");
		printf("메뉴를 선택 하시오 : ");
		scanf("%d", &menu_num);    //이용자가 원하는 menu 번호를 입력 받는다
		printf("\n\n");
		switch (menu_num) {    //입력 받은 번호로 switch..case 구문을 사용하여 입력 된 메뉴 번호로 이동한다
		case BUY_M:
			buying_player(all_player, &user_data, num_reg_player);    //선수 구매를 담당하는 함수에 전체 선수정보와 사용자 정보를 넘겨 처리한다
			break;
		case SELL_M:
			if (user_data.num_players == 0) {
				printf("--------------------------------------\n");
				printf("!!!!!판매할 선수가 없습니다.!!!!!\n");
				printf("1번 메뉴에서 선수를 먼저 구매해 주세요!\n");
				goto menu;
			}
			selling_player(all_player, &user_data);    //선수 판매를 담당하는 함수에 전체 선수정보와 사용자 정보를 넘겨 처리한다
			break;
		case LIST_M:
			printf("-----------------------------------------------------------\n");
			printf(" %s 님의 구단 선수 가치= %ld bp, BP=%ld 입니다.\n", input_id, team_value(user_data), user_data.bp);
			printf("-----------------------------------------------------------\n");
			if (user_data.num_players > 0) {
				print_players(user_data.players, user_data.num_players);   //사용자가 가지고 있는 선수들의 정보를 출력한다
			}
			else {
				printf(" %s 님의 현재 보유하고 있는 선수가 없습니다.\n", user_data.id);
			}

			break;
		case FORCE:
			if (user_data.num_players == 0) {
				printf("----------------------------------------\n");
				printf("!!!!!강화할 선수가 없습니다.!!!!!\n");
				printf("1번 메뉴에서 선수를 먼저 구매해 주세요!\n");
				goto menu;
			}

			do {     //등록 되어진 선수가 선택될 때가지 do..while 구문을 이용하여 계속한다 
				printf("--------------------------------------------\n");
				print_players(user_data.players, user_data.num_players);
				printf("강화할 선수를 선택 하세요( 나가기=0) :  ");
				scanf("%d", &select_num);

				if (select_num > user_data.num_players) {
					printf("\n---등록되지 않은 선수 번호를 입력 하였습니다.---\n");
				}
			} while (select_num > user_data.num_players);

			if (select_num == 0) goto menu;

			if (reinforce_player(&user_data, select_num - 1) == 1)   //선택된 선수번호-1 을 하여 이용자가 원하는 선수의 강화를 실행한다.
			{
				printf("\n#################\n");
				printf("### 강화 성공 ###\n");      //reinforce_player 함수 return 이 "1" 이면 성공
				printf("#################\n\n");
				Sleep(1000);
				user_data_write(&user_data);		//변경된 사용자 정보를 저장한다
				print_players(&(user_data.players[select_num - 1]), 1);    //강화를 성공하면 변경되 선수 정보 출력
			}
			else
			{
				printf("\n!!!!!!!!!!!!!!!!!\n");
				printf("!!! 강화 실패 !!!\n");     //reinforce_player 함수 return 이 "0" 이면 실패
				printf("!!!!!!!!!!!!!!!!!\n\n");
				Sleep(1000);
			}
			break;
		case HISTORY:
			printf("-------------------------------------------------------\n");
			printf(" %s 님 구매/판매에 이력 정보 입니다.\n", user_data.id);
			printf("-------------------------------------------------------\n");
			user_history_read(&user_data);
			break;
		case LOG_OUT:
			goto login;
		case END_G:
			goto end;    //프로그램 끝내기를 선택하면 메뉴 while() 구문을 탈출하여 선언된":end"로 실행 위치를 이동한다.
			break;
		default:
			printf("\n---메뉴에 없는 번호를 입력 하였습니다.---\n");  //잘못된 메뉴 번호 선택시 안내를 출력 한다
			break;
		}
	}

end:
	return 0;
}