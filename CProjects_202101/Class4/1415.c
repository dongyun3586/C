#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

#define _CRT_SECURE_NO_WARNINGS  
#define MAX_PLAY 5       //�ִ� ��� ���� ���� ���� 

void init_player(int idx);     //�ش� �Էµ� index�� ���� ����(level, value) �ʱ�ȭ �Ѵ�
int reinforce_player(int idx);    //���õ� ������ ��ȭ�� �����ϰ� ����� 1:����, 0: ���� return �Ѵ�  
int selling_player(char name[], int idx);    //���õ� ������ �Ȱ� ������ BP �� Level�� ���� �Ѵ�
long long player_value_gen(int level);     //��ȭ level�� �ش��ϴ� BP�� ��� �Լ��� ����Ͽ� return �Ѵ�(����)
long long player_value_dec(int level);     //��ȭ level�� �ش��ϴ� BP�� ��� �Լ��� ����Ͽ� return �Ѵ�(����)
void list_players(char arr[][20], int col, int row);    //��ϵ� ���� ������ ��� �Ѵ�
void sort_players_level(char arr[][20], int col, int row);   //��ϵ� ������ ��ȭ level ������ ���� �Ѵ�
void sort_players_value(char arr[][20], int col, int row);   //��ϵ� ������ ��ġ BP ������ ���� �Ѵ� 

struct player_info_t {      //��ȭ ���α׷��� Level & Value ������ ���� ����ü type�� ����
	int level;

	long long value;
};

struct player_info_t player_info[MAX_PLAY];   //��ϵ� ���� MAX_PLAY=5�� ���� level & value ������ ���� ����ü �迭 ����
struct player_info_t my_account;      //��ȭ ���α׷��� �����ϴ� ������� �� BP �� Level ������ ������ ����ü ���� ����

int main() {
	char players[MAX_PLAY][20] = { "ȣ�����","����    ","ũ������","����į��","����Ʈ  " };   //���� �̸� ���

	int col, row;       //���� �̸� ��� �� ����

	int menu_num, select_num;    //scanf �� �Է� ���� ����

	for (int i = 0; i < MAX_PLAY; i++)    //���� 5���� Level=1, BP�� �ʱ�ȭ �Ѵ� 
	{
		init_player(i);
	}

	my_account.value = 0;    //��ȭ ���α׷� �̿��� ���� �ʱ�ȭ

	my_account.level = 0;

	col = sizeof(players[0]) / sizeof(char);   //���� �̸� �迭�� ��� �� ���

	row = sizeof(players) / sizeof(players[0]);


	while (1) {    //while() ������ �̿��Ͽ� �⺻ �޴� "7...������" ��  ���� �Ǿ����� ������ ��� �ݺ� �Ѵ�
		system("cls");
		printf("------------------------------------------\n");
		printf("  ���� Class �౸ ���� ��ȭ ���α׷� �޴� \n");
		printf("------------------------------------------\n");
		printf("1. ���� ��� ����\n");
		printf("2. ���� Class �౸ ���� ��ȭ\n");
		printf("3. ���� Class �౸ ���� �Ǹ�\n");
		printf("4. ��ȭ�ܰ� ���� ���� ����\n");
		printf("5. ���� ��ġ �켱 ���� ����\n");
		printf("6. ���� ���� �Ǹ� ���(BP ����) ����\n");
		printf("7. ���α׷� ������\n");
		printf("------------------------------------------\n");

		printf("�޴��� ���� �Ͻÿ� : ");

		scanf("%d", &menu_num);    //�̿��ڰ� ���ϴ� menu ��ȣ�� �Է� �޴´�


		switch (menu_num) {    //�Է� ���� ��ȣ�� switch..case ������ ����Ͽ� �Է� �� �޴� ��ȣ�� �̵��Ѵ�

		case 1:

			list_players(players, col, row);  //��ϵ� ������ �⺻ ������ ��� �Ѵ�
			Sleep(3000);
			printf("\n\n");
			break;

		case 2:

			list_players(players, col, row);  //��ϵ� �������� ����ϰ�

			do {     //��� �Ǿ��� ������ ���õ� ������ do..while ������ �̿��Ͽ� ����Ѵ� 

				printf("-------------------------------\n");

				printf("��ȭ�� ������ ���� �ϼ���:");

				scanf("%d", &select_num);

				if (select_num > MAX_PLAY) {


					printf("\n---��ϵ��� ���� ���� ��ȣ�� �Է� �Ͽ����ϴ�.---\n");


				}

			} while (select_num > MAX_PLAY);

			if (reinforce_player(select_num - 1))   //�迭�̹Ƿ� ���õ� ������ȣ-1 �� �Ͽ� �̿��ڰ� ���ϴ� ������ ��ȭ�� �����Ѵ�.

			{
				printf("\n��ȭ �õ���...\n");
				Sleep(1000);

				system("color 2F");
				printf("\n#################\n");

				printf("### ��ȭ ���� ###\n");      //reinforce_player �Լ� return �� "1" �̸� ����

				printf("#################\n\n");

				Sleep(1000);
				system("color 0F");

				list_players(players, col, row);    //��ȭ�� �����ϸ� ����Ǵ� ���� ���� ���

			}

			else

			{
				printf("��ȭ �õ���...");
				Sleep(1000);
				system("color 4F");
				printf("\n!!!!!!!!!!!!!!!!!\n");

				printf("!!! ��ȭ ���� !!!\n");     //reinforce_player �Լ� return �� "0" �̸� ����

				printf("!!!!!!!!!!!!!!!!!\n\n");

				Sleep(1000);
				system("color 0F");
				printf("\n\n");
			}

			break;

		case 3:

			list_players(players, col, row);    //��ϵ� �������� �����ش�



			do {      //�Ǹ��� ������ ���õ� ������ do..while ������ �̿��Ͽ� ����Ѵ�

				printf("--------------------------\n");

				printf("�Ǹ��� ������ ���� �ϼ���:");



				scanf("%d", &select_num);



				if (select_num > MAX_PLAY) {

					printf("\n---��ϵ��� ���� ���� ��ȣ�� �Է� �Ͽ����ϴ�.---\n");

				}

			} while (select_num > MAX_PLAY);



			selling_player(players[select_num - 1], select_num - 1);  //���õ� ������ȣ-1�� �迭 index ������ ���� �Ǹ� �Լ��� ȣ���Ѵ�
			Sleep(1000);
			printf("\n\n");
			break;

		case 4:

			sort_players_level(players, col, row);    //���� ��ȭ ������ ��� ������ sorting �Ѵ�
			Sleep(3000);
			printf("\n\n");
			break;

		case 5:

			sort_players_value(players, col, row);    //���� ��ġ ������ ��� ������ sorting �Ѵ�
			Sleep(3000);
			printf("\n\n");
			break;

		case 6:        //��ȭ ���α׷� �̿����� ���� ������ ��� �Ѵ�

			printf("\n+++++++++++++++++++++++++++++++++++++++++++++++++\n");

			printf("+++ ����� �� �ڻ� ��ġ�� %10ld BP �Դϴ�+++", my_account.value);

			printf("\n+++++++++++++++++++++++++++++++++++++++++++++++++");

			printf("\n+++     �� ���� ��ȭ�� %5d level  �Դϴ�    +++", my_account.level);

			printf("\n+++++++++++++++++++++++++++++++++++++++++++++++++\n\n");
			Sleep(3000);
			printf("\n\n");
			break;

		case 7:

			goto end;    //���α׷� �����⸦ �����ϸ� �޴� while() ������ Ż���Ͽ� �����":end"�� ���� ��ġ�� �̵��Ѵ�.
			Sleep(1000);
			printf("\n\n");
			break;

		default:

			printf("\n---�޴��� ���� ��ȣ�� �Է� �Ͽ����ϴ�.---\n");  //�߸��� �޴� ��ȣ ���ý� �ȳ��� ��� �Ѵ�
			Sleep(1000);
			break;

		}

	}

end:
	return 0;
}

void init_player(int idx)   //idx�� �ش��ϴ� ���� ����(level, value) �ʱ�ȭ �Ѵ�
{
	player_info[idx].level = 1;    // 1 level

	player_info[idx].value = player_value_gen(player_info[idx].level);  //1 level�� �ش��ϴ� BP ��
}


int reinforce_player(int idx)  //���õ� ������ ��ȭ�� �����ϰ� ����� 1:����, 0: ���� return �Ѵ�
{

	srand(time(NULL));

	int probability = rand();  //random �Լ��� �̿��� ������ ������ �߻� ��Ų��

	int agent;



	agent = player_info[idx].level;   //���õ� ������ ���� level�� agent�� �����Ѵ�



	if (((probability % 10) != agent) && (agent == 1)) {   //Level 1 �϶��� ������ ���ڰ� 10���� ������ �������� 1�� �ƴϸ� ������ ��ȭ ����

		player_info[idx].level++;    //Level ����

		player_info[idx].value = player_value_gen(player_info[idx].level);    //BP �߻� �Լ��� ȣ���Ͽ� BP�� return �޴´�

		return 1;    //��ȭ ����

	}

	if (probability % (agent) == 0) {   //Level 2 �̻��̸� ������ �߻����� Level�� ������ ��������(������=0) ��ȭ �����̴�

		player_info[idx].level++;  //Level ����

		player_info[idx].value = player_value_gen(player_info[idx].level);   //BP �߻� �Լ��� ȣ���Ͽ� �ش� Level ��ū ��� ȣ���Ͽ� BP�� return �޴´�

		return 1;    //��ȭ ����

	}

	player_info[idx].level--;
	player_info[idx].value = player_value_dec(player_info[idx].level);

	return 0;

}



int selling_player(char name[], int idx)   //���õ� ������ �Ȱ� ������ BP �� Level�� ���� �Ѵ�

{

	my_account.value += player_info[idx].value;  //��ġ BP ����

	my_account.level += player_info[idx].level;   //Level ����



	printf("\n###########################################################\n");

	printf("### %s ������ %d BP�� �ǸŰ� �Ϸ� �Ǿ����ϴ�. ###\n", name, player_info[idx].value);

	printf("###########################################################\n\n");



	init_player(idx);     //�Ǹŵ� ������ Level ���� 1 �� �ʱ�ȭ �Ѵ�



	printf("-------------------------------------------------\n");

	printf("------ ������ �ڻ��� %10ld BP �Դϴ�.-------\n", my_account.value);

	printf("-------------------------------------------------\n");

}



long long player_value_gen(int level)   //��ȭ level�� �ش��ϴ� BP�� ��� �Լ��� ����Ͽ� return �Ѵ�

{

	if (level == 1)

	{

		return((rand() % 10 + 1) * 10);    //Level=1 �� �ɶ� ������ ��� ȣ��� �Լ��� 1~10 ������ ���Ǿ� ���� return �Ѵ� 

	}



	srand(time(NULL));



	return player_value_gen(level - 1) * (rand() % 10 + 1);  //1~10�� ���� ���� ��� ȣ��

}
long long player_value_dec(int level)   //��ȭ level�� �ش��ϴ� BP�� ��� �Լ��� ����Ͽ� return �Ѵ�

{
	if (level == 1)

	{

		return((rand() % 10 + 1) * 10);    //Level=1 �� �ɶ� ������ ��� ȣ��� �Լ��� 1~10 ������ ���Ǿ� ���� return �Ѵ� 

	}



	srand(time(NULL));



	return player_value_gen(level - 1) * (rand() % 10 + 1);  //1~10�� ���� ���� ��� ȣ��

}




void list_players(char arr[][20], int col, int row)   //��ϵ� ���� ������ ��� �Ѵ�

{

	printf("-------------------------------\n");

	printf("   World Class �౸ ���� ����  \n");

	printf("-------------------------------\n");



	for (int i = 0; i < row; i++) //�����̸��� �ش� index�� �ش��ϴ� ������ level �� ��ġ ���� ��� 

	{

		printf("%d - %s  %d �� %ld BP \n", i + 1, arr[i], player_info[i].level, player_info[i].value);

	}

}



void sort_players_level(char arr[][20], int col, int row)    //��ϵ� ������ ��ȭ level ������ ���� �Ѵ�

{

	struct player_info_t temp_info;   //���ؼ� ���� ġȯ�Ҷ� vale & level�� �����ϱ� ���� �ӽú���

	char temp_name[20];     //���ؼ� ���� ġȯ�Ҷ� �����̸��� �ӽ÷� �����ϱ� ���� ����



	printf("-------------------------------------------\n");

	printf("   World Class �౸ ���� ��ȭ Level ����   \n");

	printf("-------------------------------------------\n");



	for (int i = 0; i < MAX_PLAY - 1; i++)    //��ϵ� ���� ������ �ձ��� ũ�� ��

	{

		for (int j = i + 1; j < MAX_PLAY; j++)    //��ϵ� ������ ó�� ���� �ϳ��� ���� ��Ű�� level ������ ���� ���� ����

		{

			if (player_info[j].level > player_info[i].level)   //������ ���� ��ȭ level ��ġ i��°�� ������ �� �κ� �� 

			{

				temp_info = player_info[i];     //�迭 �ڿ� �� j index�� ũ�� level & value�� ����� ����ü ���� ��ġ(i<->j)�� �����Ѵ�

				player_info[i] = player_info[j];

				player_info[j] = temp_info;



				strcpy(temp_name, arr[i]);    //�����̸��� strcpy �Լ��� �̿��Ͽ� �ٲپ� �ش�

				strcpy(arr[i], arr[j]);

				strcpy(arr[j], temp_name);

			}

		}

	}



	for (int i = 0; i < row; i++)    //������ ����� ���� ��� ������ ��� �Ѵ�

	{

		printf("%d - %s  %d �� %ld BP \n", i + 1, arr[i], player_info[i].level, player_info[i].value);

	}

}

void sort_players_value(char arr[][20], int col, int row) //��ϵ� ������ ��ġ BP ������ ���� �Ѵ�

{

	struct player_info_t temp_info;  //���ؼ� ���� ġȯ�Ҷ� vale & level�� �ӽ÷� �����ϱ� ���� ����

	char temp_name[20];    //���ؼ� ���� ġȯ�Ҷ� �����̸��� �ӽ÷� �����ϱ� ���� ����

	printf("-----------------------------------------\n");

	printf("   World Class �౸ ���� ��ġ ���� ����  \n");

	printf("-----------------------------------------\n");


	for (int i = 0; i < MAX_PLAY - 1; i++)  //��ϵ� ���� ������ �ձ��� ũ�� ��

	{

		for (int j = i + 1; j < MAX_PLAY; j++) //��ϵ� ������ ó�� ���� �ϳ��� ���� ��Ű�� value ������ ���� ���� ����

		{

			if (player_info[j].value > player_info[i].value)  //������ ���� value ��ġ i��°�� ������ �� �κ� ��

			{

				temp_info = player_info[i];    //�迭 �ڿ� �� j index�� ũ�� level & value�� ����� ����ü ���� ��ġ(i<->j)�� �����Ѵ�

				player_info[i] = player_info[j];

				player_info[j] = temp_info;



				strcpy(temp_name, arr[i]);    //�����̸��� strcpy �Լ��� �̿��Ͽ� �ٲپ� �ش�

				strcpy(arr[i], arr[j]);

				strcpy(arr[j], temp_name);

			}

		}

	}

	for (int i = 0; i < row; i++)   //������ ����� ���� ��� ������ ��� �Ѵ�

	{

		printf("%d - %s  %d �� %ld BP \n", i + 1, arr[i], player_info[i].level, player_info[i].value);

	}

}