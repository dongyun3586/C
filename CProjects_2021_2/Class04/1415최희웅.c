// player_trade_market.cpp : �� ���Ͽ��� 'main' �Լ��� ���Ե˴ϴ�. �ű⼭ ���α׷� ������ ���۵ǰ� ����˴ϴ�.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

#define _CRT_SECURE_NO_WARNINGS

#define SIZE_ID 12		  //���̵� �Է� �ִ� ũ��
#define SIZE_PW 12		 //��ȣ �ִ�ũ��
#define CIPHER  3			 //��ȣȭ ��ȣȭ ����Ʈ ��ġ

typedef unsigned int UINT;     //�����ð��� ��� UINT ����
typedef unsigned long int ULONG;    //unsigned long int�� ULONG ����

typedef struct _User_Info {      //������� user id �� ��ȣ�� ���� ����ü
	char id[SIZE_ID];				//���̵� ���
	char password[SIZE_PW];		//��ȣ ���
}User_Info;

typedef struct _Football_Player {	//�౸���� �Ѹ��� ������ ���� ������� ������ �ִ� ����ü
	char name[20];				//���� �̸�
	char nation[20];			//��� ����
	UINT position;				//��������
	UINT ability;					//�ɷ�ġ
	ULONG value;				//��ġ
	UINT level;					//���� ��ȭ ����
}Football_Player;

typedef struct _User_Data {      //����ں� ������ ���� ������� ���� �ִ� ����ü
	char id[SIZE_ID];				//����� ID
	Football_Player players[22];	//������ ������ ������ 22�� �ִ�	
	ULONG bp;						//����ڰ� ������ �ִ� BP
	UINT num_players;			//������ ������ ���� ��
	UINT point;						//�Ǹ� ������ ���� ���� 
}User_Data;

enum Login { ID = 1, PASSWORD = 2, EXIT = 3 };   //�ʱ� ����� switch ���� ���� ���� ����
enum Main_Menu { BUY_M = 1, SELL_M = 2, LIST_M = 3, FORCE = 4, HISTORY = 5, LOG_OUT = 6, END_G = 7 };
enum Trade_Type { BUY, SELL };					//����=0, �Ǹ�=1 ���� ����

void encrypt(char* cipher, int shift) {		//����� ID�� Password�� ��ȣȭ �Ѵ�
	for (int i = 0; cipher[i] != '\0'; i++) {
		cipher[i] += shift;
	}
}

void decrypt(char* cipher, int shift) {		//����� ID �� Password�� ��ȣȭ �Ѵ�
	for (int i = 0; cipher[i] != '\0'; i++) {
		cipher[i] -= shift;
	}
}

UINT user_info_read(int num_user, User_Info* user_data)   //��ϵ� ������� ID �� Password ������ File���� �ҷ� �´�
{
	FILE* user_fp = NULL;
	char id[SIZE_ID] = { 0 };			//ID ���ڿ� �ʱ�ȭ
	char password[SIZE_PW] = { 0 };			//Password ���ڿ� �ʱ�ȭ

	user_fp = fopen(".\\user_info.txt", "r+");       //��ϵ� ����� ���� file�� open �Ѵ�

	if (user_fp == NULL) {			 // ���� ���⿡ ����������
		printf("����� ���� ���� ���⿡ �����Ͽ����ϴ�.\n");
		return 0;
	}

	for (int i = 0; i < num_user; i++) {			//��ϵ� ����� ����ŭ for loop ����
		fread(id, SIZE_PW, 1, user_fp);					//file ������ ���� ID ������ �о� �´�
		decrypt(id, CIPHER);								//��ȣȭ�� �����Ѵ�
		strcpy(user_data[i].id, id);					//user_data ����ü�� ID ���� �Է�
		fread(password, SIZE_PW, 1, user_fp);			//file ������ ���� password ������ �о� �´�
		decrypt(password, CIPHER);						//��ȣȭ�� �����Ѵ�
		strcpy(user_data[i].password, password);    //user_data ����ü�� password ���� ����
	}

	fclose(user_fp);				//file �� �ݴ´�

	return 1;
}

UINT user_info_write(char* id, char* password, int user_cnt) {	//��ϵ� ����� ������ �����Ѵ�
	FILE* ufp;
	FILE* nfp;
	char ntemp[5];

	ufp = fopen(".\\user_info.txt", "a+");    //����� ID�� password�� ��ȣȭ �ؼ� file�� �߰� ���� �Ѵ�	

	if (ufp == NULL) {           // ���� ���⿡ ����������
		printf("����� ���� ���� open�� �����Ͽ����ϴ�.\n");
		return 0;
	}
	encrypt(id, CIPHER);				//����� ID ��ȣȭ
	fwrite(id, SIZE_ID, sizeof(char), ufp);		//���� ũ��� ���
	encrypt(password, CIPHER);				//Password ��ȣ��
	fwrite(password, SIZE_PW, sizeof(char), ufp);   //���� ũ��� ���
	fclose(ufp);

	nfp = fopen(".\\user_no.txt", "w+");    	//������ file�� ���Ӱ� ����� ���� ��� �Ѵ�

	if (nfp == NULL) {			 // ���� ���⿡ ����������
		printf("����� ��ϼ� ���� open�� �����Ͽ����ϴ�.\n");
		return 0;
	}

	sprintf(ntemp, "%02d", user_cnt);      //�� ��ϵ� ������� ��
	fwrite(ntemp, 2, 1, nfp);					//����ڼ� ���� ���Ͽ� ���
	fclose(nfp);

	return 1;
}

UINT check_login_id(char* user_id, int num_user, User_Info* user_data)    //�Է��� ID�� ����� ������ �ִ��� Ȯ���Ѵ�
{
	for (int i = 0; i < num_user; i++) {			//����� ����ŭ for loop ���� 
		if (strcmp(user_data[i].id, user_id) == 0) {
			return i + 1;				//user_data ����ü�� ��ġ�ϴ� ����� ID�� ������ ����� ��ġ index�� '1'�� ���� �� return
		}
	}

	return 0;				//��ġ�ϴ� user ID�� ������ '0' return
}

UINT check_login_password(char* user_pw, UINT user_idx, User_Info* user_data)    //�Է��� password�� ����� ������ �ִ��� Ȯ���Ѵ�
{
	if (strcmp(user_data[user_idx - 1].password, user_pw) == 0) {
		return 1;			//user_data ����ü�� ID ������ match �ϴ� ��ġ�� ��ġ�ϴ� ����� password�� ������ '1' return
	}
	else {
		return 0;			//password ������ ��ġ���� ����
	}
}

void read_player_data(Football_Player* one_player, char* one_line) {     //���Ͽ� �ִ� ���� ������ �о� �������� ����ü ��� �������� �и��Ͽ� ������ �ش�
	char* read_one;
	read_one = strtok(one_line, " ");   //" " �������� ù��° �ܾ �и��Ͽ� name�� �����Ѵ�
	strcpy(one_player->name, read_one);
	read_one = strtok(NULL, " ");		//strtok�� ������ �ִ� ������ ��ġ���� �ٽ� ������ ã�� ��� ������ �����Ѵ�
	strcpy(one_player->nation, read_one);
	read_one = strtok(NULL, " ");		//������ ������� Footbll_Player�� ������ ���� �����Ѵ�
	one_player->position = atoi(read_one);
	read_one = strtok(NULL, " ");		//������ ������� Footbll_Player�� �ɷ�ġ ���� �����Ѵ�
	one_player->ability = atoi(read_one);
	read_one = strtok(NULL, " ");		//������ ������� Footbll_Player�� ��ġ ���� �����Ѵ�
	one_player->value = atol(read_one);
	read_one = strtok(NULL, " ");		//������ ������� Footbll_Player�� ��ȭ ���� �����Ѵ�
	one_player->level = atoi(read_one);
}

UINT load_player(Football_Player* all_player) {
	const UINT max = 512;             //������ �ִ� ����
	char one_line[max];                   //������ �д� ��Ʈ�� ����
	char* read_one;						//���� Data���� ù��°�� ����Ű�� ������ ����
	FILE* in = fopen(".\\player_info.txt", "r");        //�������忡 ��� �Ǿ� �ִ� ���� ������ ������ �ִ� file
	UINT register_player = 0;			//��ϵ� ������ ���� ����Ͽ� return

	if (in == NULL) {			 // ���� ���⿡ ����������
		printf("�౸ ���� ��� ���� open�� �����Ͽ����ϴ�.\n");
		return 0;
	}


	while (!feof(in)) {						//file�� ���������� �д´�
		if (fgets(one_line, max, in) == NULL) {
			break;			//������ �о� ���µ� ���ڿ��� ������ �׸� �д´�	
		}
		read_player_data(all_player, one_line);
		register_player++;					//���ٿ� �Ѹ� ���� ������ �߰��Ѵ�
		all_player++;						//Football_Player ����ü ���� all_player�� ���� ��ġ�� �̵��Ѵ�
	}
	fclose(in);								//file�� �ݴ´�

	return register_player;				//��ϵ� �� ���� ������ return �Ѵ�
}

void print_players(Football_Player* player, UINT num_player)   //Football_Player ����ü�� �ش� �ϴ� ���� ������ ��� �Ѵ�
{
	printf("       ������    ��ű���  ������  �ɷ�       ��ġ    ��� \n");
	printf("***********************************************************\n");

	for (int i = 0; i < num_player; i++) //�����̸��� �ش� index�� �ش��ϴ� ������ level �� ��ġ ���� ��� 
	{
		char position_name[5][3] = { "GK", "DF", "MF", "CF", "ST" };      //����� �������� ���� ������ ��Ī���� ǥ���Ѵ�
		printf("%02d | %10s %10s   %02s    %03d %12ld   %01d �� \n", i + 1, player->name, player->nation, position_name[player->position], player->ability, player->value, player->level);
		player++;				//���� ������ �ϳ��� ��� �Ѵ�
	}

	printf("***********************************************************\n");
}

UINT user_data_init(User_Data user_data, char* id) {
	FILE* fp;
	char filename[20];
	char one_line[20];

	user_data.bp = 20000;      //���� ��� 2�� BP�� �����Ѵ�.
	user_data.num_players = 0;	     //�ʱ� ���� ������ 0 �̴�
	user_data.point = 0;				//����� �Ǹ� ����
	strcpy(user_data.id, id);           //user id�� user_data ����ü�� �Է�

	sprintf(filename, ".\\%s.txt", id);		//����� ID�� �����̸��� ���Ѵ�
	fp = fopen(filename, "w+");			//���� �������� ������ open �Ѵ�
	if (fp == NULL) {			 // ���� ���⿡ ����������
		printf("�����  ���� ���� open�� �����Ͽ����ϴ�.\n");
		return 0;
	}
	sprintf(one_line, "%ld\n", user_data.bp);		//����� BP ������ ó�� line�� ���
	fputs(one_line, fp);
	sprintf(one_line, "%d\n", user_data.num_players);		//�ι�° line�� ����ڰ� ������ ������ ������ ���
	fputs(one_line, fp);
	sprintf(one_line, "%d\n", user_data.point);		//����° line�� ����ڰ� ������ �Ǹ� ������ ���
	fputs(one_line, fp);
	fclose(fp);			//������ �ݴ´�

	return 1;
}

UINT user_data_read(User_Data* user_data) {
	FILE* fp;
	char filename[20];						//����� ������ ������ �ִ� ���� �̸�
	const UINT max = 512;             //������ �ִ� ����
	char one_line[max];                   //������ �д� ��Ʈ�� ����

	sprintf(filename, ".\\%s.txt", user_data->id);
	fp = fopen(filename, "r+");         //����� ������ ���� ������ open �Ѵ�
	if (fp == NULL) {			 // ���� ���⿡ ����������
		printf("����� ���� ���� ���⿡ �����Ͽ����ϴ�.\n");
		return 0;
	}
	fgets(one_line, max, fp);
	user_data->bp = (ULONG)atol(one_line);	//����� BP ������ ���� �о�� user_data�� �����Ѵ�
	fgets(one_line, max, fp);
	user_data->num_players = (UINT)atoi(one_line);	//����� ���� ���� ���� ������ ���� �о�� user_data�� �����Ѵ�
	fgets(one_line, max, fp);
	user_data->point = (UINT)atoi(one_line);	//����� �Ǹ� ���� ������ ���� �о�� user_data�� �����Ѵ�

	if (user_data->num_players > 0) {
		UINT idx = 0;
		while (idx < user_data->num_players) {		//����ڰ� ������ ������ ������ �о� �´�
			fgets(one_line, max, fp);
			read_player_data(&(user_data->players[idx]), one_line);	//������ �о�� �ܾ ã�� players ����ü�� ���� �־��ִ� �Լ��� ȣ���Ѵ�
			idx++;     //���� ������ �Ѿ��
		}
	}

	fclose(fp);

	return 1;
}

UINT user_data_write(User_Data* user_data) {
	FILE* fp;
	char filename[20];
	const UINT max = 512;             //������ �ִ� ����
	char one_line[max];                   //������ �д� ��Ʈ�� ����
	UINT idx = 0;							//���� �������� ������ ����Ű�� ����

	sprintf(filename, ".\\%s.txt", user_data->id);
	fp = fopen(filename, "w+");						//���� �������� ������ open �Ѵ�
	if (fp == NULL) {			 // ���� ���⿡ ����������
		printf("����� ���� ���� ���⿡ �����Ͽ����ϴ�.\n");
		return 0;
	}
	sprintf(one_line, "%ld\n", user_data->bp);
	fputs(one_line, fp);									//����� BP ������ ���� ��� �Ѵ�
	sprintf(one_line, "%d\n", user_data->num_players);
	fputs(one_line, fp);									//�ι�° line�� ����ڰ� ������ ������ ������ ��� �Ѵ�
	sprintf(one_line, "%d\n", user_data->point);
	fputs(one_line, fp);									//����° line�� ����ڰ� ������ �Ǹ� ������ ���

	while (idx < user_data->num_players) {		//������ �ٵ鿡 ���� ���� ����ŭ �������� ������ �����Ѵ�.
		sprintf(one_line, "%s %s %d %d %ld %d\n", user_data->players[idx].name, user_data->players[idx].nation,
			user_data->players[idx].position, user_data->players[idx].ability, user_data->players[idx].value, user_data->players[idx].level);
		fputs(one_line, fp);     //���� ���� ���·� ����� �Ѹ� ������ ���� ���ٿ� �����Ѵ�
		idx++;
	}
	fclose(fp);

	return 1;
}

ULONG team_value(User_Data current_user) {
	ULONG total_value = 0;
	for (int i = 0; i < current_user.num_players; i++) {    //����ڰ� ������ �ִ� ���� ������ŭ for loop ����   
		total_value += current_user.players[i].value;			//�� ������ ��ġ���� �ջ��Ѵ�
	}
	return total_value;		//�ջ�� ���� ���� �ش�
}

ULONG player_value_gen(UINT level)   //��ȭ ������ ���� level ��ġ�� ���� ��ġ�� �����Ѵ�.
{
	return((rand() % level + 1));    //Level�� �������� rand()�� ���� ���� Ŀ���� �־� ��ū ��ġ�� ������. 
}

UINT reinforce_player(User_Data* current_user, UINT idx)  //���õ� ������ ��ȭ�� �����ϰ� ����� 1:����, 0: ���� return �Ѵ�
{
	srand(time(NULL));
	UINT probability = rand();  //random �Լ��� �̿��� ������ ������ �߻� ��Ų��
	UINT agent;

	agent = current_user->players[idx].level;   //���õ� ������ ���� level�� agent�� �����Ѵ�

	if (((probability % 10) != agent) && (agent == 1)) {   //Level 1 �϶��� ������ ���ڰ� 10���� ������ �������� 1�� �ƴϸ� ������ ��ȭ ����
		current_user->players[idx].level++;    //Level ����
		current_user->players[idx].value = current_user->players[idx].value * player_value_gen(current_user->players[idx].level);    //BP �߻� �Լ��� ȣ���Ͽ� BP�� return �޴´�
		return 1;    //��ȭ ����
	}

	if (probability % (agent) == 0) {   //Level 2 �̻��̸� ������ �߻����� Level�� ������ ��������(������=0) ��ȭ �����̴�
		current_user->players[idx].level++;  //Level ����
		current_user->players[idx].value = current_user->players[idx].value * player_value_gen(current_user->players[idx].level);  //BP �߻� �Լ��� ȣ���Ͽ� �ش� Level ��ū ��� ȣ���Ͽ� BP�� return �޴´�
		return 1;    //��ȭ ����
	}

	if (current_user->players[idx].value > 1000) {		//��ȭ�� �����ϸ� ������ ��ġ 1000BP�� ���δ�
		current_user->players[idx].value -= 1000;
		printf("### ��ȭ ���з� ���� ��ġ 1000 BP �پ� ������ϴ�.###\n");
	}
	return 0;
}

UINT user_history_read(User_Data* user_data) {		//����� ���� �� �Ǹ� ������ ����ϴ� �Լ�
	FILE* fp;
	char filename[20];
	const UINT max = 512;             //������ �ִ� ����
	char one_line[max];                   //������ �д� ��Ʈ�� ����
	UINT type;
	char* read_one;
	Football_Player data;

	sprintf(filename, ".\\%s_h.txt", user_data->id);		//����� ���� �� �Ǹ� �̷��� ������ ���� �̸�
	fp = fopen(filename, "r+");			//������ �����ϰ� �ƹ��͵� �������� �ʴ´�

	if (fp == NULL) {			 // ���� ���⿡ ����������
		printf("����� �̷� ���� ���⿡ �����Ͽ����ϴ�.\n");
		return 0;
	}

	for (int i = 0; i < user_data->point; i++) {      //���ſ� �ǸŰ� ������ �� point  ��ŭ �̷��� ��� �����ش�
		if (feof(fp)) {				//���� ������ �������̸� for loop Ż��
			break;
		}
		fgets(one_line, max, fp);				//������ �о� ���δ�
		read_one = strtok(one_line, " ");
		type = (UINT)atoi(read_one);	//�������� �Ǹ����� ������ �о� �´�

		read_one = strtok(NULL, "\0");	//����� ������ ���ڿ��� ���� ������ ���� ������ �����´�

		if (type == 0) {
			printf("���ż���: ");
		}
		else {
			printf("�Ǹż���: ");
		}
		read_player_data(&data, read_one);	//���������� �о�� ���ڿ��� �౸�������� ����ü�� �� ������ �°� �ڷ����� �������� �Լ� ȣ��
		printf("%s %s %d %d %ld %d\n", data.name, data.nation, data.position, data.ability, data.value, data.level);		//���� ���� ��� �Ѵ�
	}
	fclose(fp);			//������ �ݴ´�

	return 1;
}

UINT user_history_write(User_Data* user_data, Football_Player data, UINT type) {		//����� ���� �� �Ǹ� ������ ����ϴ� �Լ�
	FILE* fp;
	char filename[20];
	const UINT max = 512;             //������ �ִ� ����
	char one_line[max];                   //������ �д� ��Ʈ�� ����

	sprintf(filename, ".\\%s_h.txt", user_data->id);		//����� ���� �� �Ǹ� �̷��� ������ ���� �̸�
	fp = fopen(filename, "a+");			//������ data �߰� ���·� �����ش�

	if (fp == NULL) {			 // ���� ���⿡ ����������
		printf("����� �̷� ���� ���⿡ �����Ͽ����ϴ�.\n");
		return 0;
	}

	sprintf(one_line, "%d %s %s %d %d %ld %d\n", type, data.name, data.nation, data.position, data.ability, data.value, data.level);
	fputs(one_line, fp);						//���� �� �Ǹ� ���ο� ���� ������ ����Ѵ�

	fclose(fp);			//������ �ݴ´�

	return 1;
}

UINT buying_player(Football_Player* all_player, User_Data* current_user, UINT no_reg_player) {
	UINT selected_num = 0;
	Football_Player* selected_player;
	do {
		printf("---------------------------------------------------------\n");
		print_players(all_player, no_reg_player);					//���� ������ ��� ������ ����� �ش�
		printf("������ ������ ���� �ϼ��� (���� �޴� = 0) : ");
		scanf("%d", &selected_num);							//������ ���� ��ȣ ����
		if (selected_num > no_reg_player) {					//��ȣ�� ����� ���
			printf("\n---��ϵ��� ���� ���� ��ȣ�� �Է� �Ͽ����ϴ�.---\n");
		}
	} while (selected_num > no_reg_player);

	if (selected_num == 0) { return 0; }			//'0' �� ��� ���� �޴��� �̵��Ѵ�

	selected_player = all_player + selected_num - 1;		//��ü list���� ���õ� ������ �����͸� ������ �ش�

	if (current_user->bp > selected_player->value) {
		current_user->bp -= selected_player->value;			//������ ���� ��ġ�� ����� BP���� �����Ͽ� �ش�
		current_user->num_players++;					//���� ���� ���� 1�� ������Ų��
		current_user->players[current_user->num_players - 1] = *(selected_player);    //������ ���� ������ user_data ����ü�� plaers ����ü type�� �����Ѵ�
		current_user->point++;			//���� ���ſ� ���� ���� �Ѱ� ����
		printf("###########################################\n");
		printf("###  %10s ���� ���Ÿ� �����մϴ�. ### \n", selected_player->name);
		printf("###########################################\n");
		printf("������ ���� ������ Ȯ���ϼ���\n");
		if (current_user->point % 4 == 0) {		//���� 4���� �Ǹ� ���ʽ� õ BP �ο�
			current_user->bp += 1000;		//�Ǹ��� ������ ��ġ�� ����� BP�� ���� �شٴ�
			printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
			printf("$$$ �����Ǹ� ����Ʈ 1000 BP �߰��� ȹ�� �Ͽ����ϴ�. $$$\n");
			printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
		}
		else {
			printf("-------------------------------------------------------\n");
		}

		print_players(selected_player, 1);		//������ ���� ���� ���
		printf("������ �� ���� ��ġ�� %ld BP�� ���� �Ǿ����ϴ�.\n", team_value(*current_user));
		user_data_write(current_user);							//user data ���Ͽ� ���� ���ſ� ���� ����� ������ �����Ѵ�
		user_history_write(current_user, *selected_player, BUY);		//������ ������ ���� ����� ���Ͽ� �����
		return 1;
	}
	else {
		printf("-------------------------------------------------------\n");
		printf("!!! ����� BP�� �����Ͽ� ���Ű� �Ұ��� �մϴ� !!! \n");
	}
}

UINT selling_player(Football_Player* all_player, User_Data* current_user) {
	UINT selected_num = 0;		//�Ǹ��� ���� ���� ��ȣ
	UINT idx = 0;					//�Ǹ��� ���� �����ϰ� ���� ����Ÿ �ø��� ����� ��ġ ����	

	do {
		printf("-------------------------------------------------------\n");
		print_players(current_user->players, current_user->num_players);		//�����ϰ� �ִ� ������ ���
		printf("-------------------------------------------------------\n");
		printf("�Ǹ��� ������ ���� �ϼ��� (���� �޴� = 0) : ");
		scanf("%d", &selected_num);

		if (selected_num > current_user->num_players) {
			printf("\n---��ϵ��� ���� ���� ��ȣ�� �Է� �Ͽ����ϴ�.---\n");
		}
	} while (selected_num > current_user->num_players);		//������ �̷�� �������� ����

	if (selected_num == 0) { return 0; }		//���� �޴��� �̵�

	idx = selected_num - 1;      //�ǸŸ� ������ ������ index
	current_user->bp += current_user->players[idx].value;		//�Ǹ��� ������ ��ġ�� ����� BP�� ���� �ش�
	current_user->point++;   //�ǸŰ� �̷�� ���� ��밡���� �ο��Ѵ�
	current_user->num_players--;		//�Ǹŵ� ���� 1���� ���� �������� ����

	user_history_write(current_user, current_user->players[idx], SELL);		//�Ǹ��� ������ ���� ����� ���Ͽ� �����

	printf("\n#################################################################\n");
	printf("### %10s ������ %10ld BP�� �ǸŰ� �Ϸ� �Ǿ����ϴ�. ###\n", current_user->players[idx].name, current_user->players[idx].value);
	printf("#################################################################\n");

	if (current_user->point % 4 == 0) {		//���� 4���� �Ǹ� ���ʽ� õ BP �ο�
		current_user->bp += 1000;		//�Ǹ��� ������ ��ġ�� ����� BP�� ���� �شٴ�
		printf("$$$ �����Ǹſ� ���� 1000 BP �߰��� ȹ�� �Ͽ����ϴ�. $$$\n");
		printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
	}
	printf("-----------------------------------------------------------\n");
	printf(" %s �� ��� ������ ����Ʈ�� %10ld BP �Դϴ�.\n", current_user->id, current_user->bp);


	for (int i = idx; i < current_user->num_players; i++) {	//�Ǹŵ� ������ �����ϰ� ���� Data�� ���� �ϳ��� �÷� �ش�
		current_user->players[i] = current_user->players[i + 1];
	}
	user_data_write(current_user);		//����� ���Ͽ� ����� ������ �����Ѵ�

	return 0;
}

int main() {
	UINT menu_num, select_num;    //scanf �� �Է� ���� ����

	UINT num_of_user = 0;
	User_Info* user_info = nullptr;     //����� ID �� Password ���� ����ü ������
	UINT user_index = 0;					//�Է��� ID�� ��ġ�� user_info
	User_Data user_data{};				//����� ���� 
	UINT user_approved = 0;			//����ڰ� ���� �Ǹ� '1" 
	UINT pass_fail = 0;

	char input_id[12] = { 0 };			//�Է� ID �ʱ�ȭ
	char input_pw[12] = { 0 };		//�Է� password �ʱ�ȭ
	char read_buf[20];

	FILE* num_fp = NULL;			//����� ���� ����� ���� ������

	num_fp = fopen(".\\user_no.txt", "r");    //��ϵ� ����� ���� ����� file�� open �Ѵ�
	if (num_fp == NULL) {			 // ���� ����ڼ� ���� ���⿡ ����������
		printf("����� ��ϼ� ���� open�� �����Ͽ����ϴ�.\n");
		return 0;
	}
	fread(read_buf, 2, 1, num_fp);
	fclose(num_fp);

	num_of_user = (UINT)atoi(read_buf);		//��ϵ� ����� ���� ���������� ������ ��ȯ�Ͽ� �����Ͽ� �ش�

	while (!user_approved) {    //while() ������ �̿��Ͽ� �⺻ �޴� "7...������" ��  ���� �Ǿ����� ������ ��� �ݺ� �Ѵ�
		printf("------------------------------------------\n");
		printf("��ϵ� ID�� ������ ������ �����ϼ���. \n");
	login:
		printf("------------------------------------------\n");
		printf("1. ����� �α���\n");
		printf("2. �������� �����ϱ�\n");
		printf("3. �����ϱ�\n");
		printf("------------------------------------------\n");

		printf("�޴��� ���� �Ͻÿ� : ");
		scanf("%d", &menu_num);    //�̿��ڰ� ���ϴ� menu ��ȣ�� �Է� �޴´�
		getchar();			//'\n' �� �����Ͽ� �ش�

		switch (menu_num) {    //�Է� ���� ��ȣ�� switch..case ������ ����Ͽ� �Է� �� �޴� ��ȣ�� �̵��Ѵ�
		case ID:
			user_info = (User_Info*)calloc(num_of_user, sizeof(User_Info));     //����� ��� ����ŭ user_info �޸𸮸� ���� �Ҵ��Ѵ�.
			user_info_read(num_of_user, user_info);      //user_data ����ü�� ��ϵ� ����� �� 'num_of_user' ��ŭ�� ������ file���� �о� �´�
		user:
			printf("------------------------------------------\n");
			printf("����� ID�� �Է� �Ͻÿ�: ");
			fgets(input_id, 12, stdin);								//����� ID�� �Է� �޴´�
			input_id[strlen(input_id) - 1] = '\0';				//fgets�� �Է� ���� ������ �� '\n'�� ������ �� '\0' ���� �����Ѵ� 			
			user_index = check_login_id(input_id, num_of_user, user_info);	//����� ID�� �ִ��� �˻��ϰ� ã���� ��ġ�� user_index ����		
			if (user_index == 0) {     //user_index�� '0'���� ũ�� �������� ����
				printf("------------------------------------------\n");
				printf("ID \"%s\" �� ��ϵ� ������ �����ϴ�.\n", input_id);
				if (user_info != nullptr) {
					free(user_info);									//�α��� �޴��� ���⿡ user_info �޸� ������Ų��
				}
				goto login;				//����� ID  ������ ������ ID �Է� ��ġ�� �̵��Ѵ�
			}
		pass:
			printf("------------------------------------------\n");
			printf("����� ��ȣ�� �Է� �Ͻÿ�: ");
			fgets(input_pw, 12, stdin);					//����� ��ȣ�� �Է� �޴´�
			input_pw[strlen(input_pw) - 1] = '\0';	//fgets�� �Է� ���� ������ �� '\n'�� ������ �� '\0' ���� �����Ѵ�

			if (check_login_password(input_pw, user_index, user_info) == 0) {		//�Է��� ������� ��ȣ�� ��ġ�ϸ� �������� �̵� �Ѵ�	
				printf("------------------------------------------\n");
				printf("ID \"%s\" �� ��ȣ�� ��ġ���� �ʽ��ϴ�. \n", input_id);
				pass_fail++;
				if (pass_fail >= 3) {
					if (user_info != nullptr) {
						free(user_info);									//�α��� �޴��� ���⿡ user_info �޸� ������Ų��
					}
					pass_fail = 0;
					printf("!!! ID \"%s\"�� ��ȣ ������ 3ȸ �����Ͽ� �α������� �̵� �մϴ�. !!!\n", input_id);
					goto login;
				}
				goto pass;				//����� ��ȣ�� ��ġ���� ������ ��ȣ �Է� ��ġ�� �̵� �Ѵ�	
			}

			user_approved = 1;		//����� ���� ���� ����	
			free(user_info);
			strcpy(user_data.id, input_id);			//user_data ������ ID�� �����Ѵ�.
			user_data_read(&user_data);			//�ش� ID �̸����� ������ user file�� user_data�� �־��ش�.
			user_data.bp += 500;
			user_data_write(&user_data);
			printf("------------------------------------------\n");
			printf("### ���� ���ʽ� 5�� BP�� ���޵Ǿ����ϴ� ###\n");
			break;
		case PASSWORD:
			printf("------------------------------------------\n");
			printf("2. �������� ����ڸ� ��� �մϴ�.\n");
			printf("------------------------------------------\n");
			printf("��� ID �Է�(10�ڸ��̳�): ");
			fgets(input_id, 12, stdin);						//���ο� ������� ID�� �Է� �޴´�
			input_id[strlen(input_id) - 1] = '\0';		//fgets�� �Է� ���� ������ �� '\n'�� ������ �� '\0' ���� �����Ѵ�
			//getchar();
			printf("------------------------------------------\n");
			printf("����� ��ȣ �Է�(10�ڸ��̳�): ");
			fgets(input_pw, 12, stdin);				//���ο� ������� ��ȣ�� �Է� �޴´�
			input_pw[strlen(input_pw) - 1] = '\0';	//fgets�� �Է� ���� ������ �� '\n'�� ������ �� '\0' ���� �����Ѵ�
			num_of_user++;								//��ϵ� ����� ���� ���� ��Ų��
			user_info_write(input_id, input_pw, num_of_user);        //����� ID �� ��ȣ�� user ���� ���Ͽ� ����Ѵ�

			decrypt(input_id, CIPHER);				//��ȣȭ�� ID�� Ǯ� �������� ID�� �����
			user_data_init(user_data, input_id);	//ID�̸����� user ���� file�� �����Ѵ�

			printf("------------------------------------------\n");
			printf("%s�� ����� ����� �Ϸ�Ǿ����ϴ�. \n", input_id);
			printf("------------------------------------------\n");
			printf("### ���� ��� 20,000BP�� ���޵Ǿ�����. ###\n");
			printf("------------------------------------------\n");
			printf("����� ������ �α��� �ϼ���\n");
			goto login;
			break;
		case EXIT:
			goto end;
			break;
		default:
			printf("\n---�޴��� ���� ��ȣ�� �Է� �Ͽ����ϴ�.---\n");  //�߸��� �޴� ��ȣ ���ý� �ȳ��� ��� �Ѵ�
			break;
		}
	}

	while (1) {
		UINT num_reg_player;
		Football_Player all_player[100];
	selling:
		num_reg_player = load_player(all_player);   //���Ű� ������ ��� �������� all_player ����ü�� �ҷ� ���� �� ���� ���� return �޴´�.
	menu:
		printf("\n\n---------------------------------------------------------------------------\n");
		printf(" ȭ���� �ϼ��� %s �� ���� ���� �ָ޴� �Դϴ�.\n", user_data.id);
		printf("���� ������ %d ��, ���ܰ�ġ %ld BP, ��밡�� BP�� %ld BP �Դϴ�.\n", user_data.num_players, team_value(user_data), user_data.bp);
		printf("---------------------------------------------------------------------------\n");
		printf("1. ���� �����ϱ�\n");
		printf("2. ���� �Ǹ��ϱ�\n");
		printf("3. ���� ����\n");
		printf("4. ���� ��ȭ\n");
		printf("5. ���� / �Ǹ� �̷�\n");
		printf("6. �α׾ƿ�\n");
		printf("7. ����\n");
		printf("------------------------------------------\n");
		printf("�޴��� ���� �Ͻÿ� : ");
		scanf("%d", &menu_num);    //�̿��ڰ� ���ϴ� menu ��ȣ�� �Է� �޴´�
		printf("\n\n");
		switch (menu_num) {    //�Է� ���� ��ȣ�� switch..case ������ ����Ͽ� �Է� �� �޴� ��ȣ�� �̵��Ѵ�
		case BUY_M:
			buying_player(all_player, &user_data, num_reg_player);    //���� ���Ÿ� ����ϴ� �Լ��� ��ü ���������� ����� ������ �Ѱ� ó���Ѵ�
			break;
		case SELL_M:
			if (user_data.num_players == 0) {
				printf("--------------------------------------\n");
				printf("!!!!!�Ǹ��� ������ �����ϴ�.!!!!!\n");
				printf("1�� �޴����� ������ ���� ������ �ּ���!\n");
				goto menu;
			}
			selling_player(all_player, &user_data);    //���� �ǸŸ� ����ϴ� �Լ��� ��ü ���������� ����� ������ �Ѱ� ó���Ѵ�
			break;
		case LIST_M:
			printf("-----------------------------------------------------------\n");
			printf(" %s ���� ���� ���� ��ġ= %ld bp, BP=%ld �Դϴ�.\n", input_id, team_value(user_data), user_data.bp);
			printf("-----------------------------------------------------------\n");
			if (user_data.num_players > 0) {
				print_players(user_data.players, user_data.num_players);   //����ڰ� ������ �ִ� �������� ������ ����Ѵ�
			}
			else {
				printf(" %s ���� ���� �����ϰ� �ִ� ������ �����ϴ�.\n", user_data.id);
			}

			break;
		case FORCE:
			if (user_data.num_players == 0) {
				printf("----------------------------------------\n");
				printf("!!!!!��ȭ�� ������ �����ϴ�.!!!!!\n");
				printf("1�� �޴����� ������ ���� ������ �ּ���!\n");
				goto menu;
			}

			do {     //��� �Ǿ��� ������ ���õ� ������ do..while ������ �̿��Ͽ� ����Ѵ� 
				printf("--------------------------------------------\n");
				print_players(user_data.players, user_data.num_players);
				printf("��ȭ�� ������ ���� �ϼ���( ������=0) :  ");
				scanf("%d", &select_num);

				if (select_num > user_data.num_players) {
					printf("\n---��ϵ��� ���� ���� ��ȣ�� �Է� �Ͽ����ϴ�.---\n");
				}
			} while (select_num > user_data.num_players);

			if (select_num == 0) goto menu;

			if (reinforce_player(&user_data, select_num - 1) == 1)   //���õ� ������ȣ-1 �� �Ͽ� �̿��ڰ� ���ϴ� ������ ��ȭ�� �����Ѵ�.
			{
				printf("\n#################\n");
				printf("### ��ȭ ���� ###\n");      //reinforce_player �Լ� return �� "1" �̸� ����
				printf("#################\n\n");
				Sleep(1000);
				user_data_write(&user_data);		//����� ����� ������ �����Ѵ�
				print_players(&(user_data.players[select_num - 1]), 1);    //��ȭ�� �����ϸ� ����� ���� ���� ���
			}
			else
			{
				printf("\n!!!!!!!!!!!!!!!!!\n");
				printf("!!! ��ȭ ���� !!!\n");     //reinforce_player �Լ� return �� "0" �̸� ����
				printf("!!!!!!!!!!!!!!!!!\n\n");
				Sleep(1000);
			}
			break;
		case HISTORY:
			printf("-------------------------------------------------------\n");
			printf(" %s �� ����/�Ǹſ� �̷� ���� �Դϴ�.\n", user_data.id);
			printf("-------------------------------------------------------\n");
			user_history_read(&user_data);
			break;
		case LOG_OUT:
			goto login;
		case END_G:
			goto end;    //���α׷� �����⸦ �����ϸ� �޴� while() ������ Ż���Ͽ� �����":end"�� ���� ��ġ�� �̵��Ѵ�.
			break;
		default:
			printf("\n---�޴��� ���� ��ȣ�� �Է� �Ͽ����ϴ�.---\n");  //�߸��� �޴� ��ȣ ���ý� �ȳ��� ��� �Ѵ�
			break;
		}
	}

end:
	return 0;
}