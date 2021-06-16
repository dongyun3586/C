#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include <time.h>
#include <memory.h>
#include <string.h>?//strlen memset
#include <windows.h>

char converter_1(int n);
char converter_2(int n);

int idarr(int id);
int mypoint(int id);
void setpoint(int id, int pt);
int randomcode(int n);
int idcheck(int n, int m);
int pointret_1(int n);
int pointret_2(int n);
void end();

void initializeVar();
void ReadDataFile();//user 값 읽는거
void WriteDataFile();//user값 파일 입력 함수

// 전역변수로 선언하여 아무 함수에나 사용할 수 있게 처리함.
#define MAX_ID		101
int Userpw[MAX_ID];
int Userid[MAX_ID];
int UserPT[MAX_ID];
FILE* fp;


void main()
{
	int password;
	int con;
	int id;
	int checkpoint_1 = 1, checkpoint_2 = 1;
	int i, j;
	int selslot;


	initializeVar();

LOBBY:

	printf("안녕하세요. 아름다운 포인트 기계입니다..\n");

	while (checkpoint_1 == 1)
	{
		printf("로그인을 하시려면 1번, ID를 새로 만드시려면 2번을 선택해주세요.\n");
		scanf("%d", &con);
		if (con == 1)
		{
		IDCHECK://ID CHECK 나중에 파일이랑 다시 연결할 예정 아직 파일 생성, 입출력이 익숙하지 않아 좀 더 공부하고 다시 만들 예정

			printf("ID를 입력하십시요.   ID: ");
			scanf("%d", &id);
			if (id > 100)
			{
				printf("아이디나 비밀번호가 틀렸습니다. 다시 입력해주십시오.\n");
				printf("ID 를 1~100에서 선택하십시오.\n");
				goto IDCHECK;
			}

			printf("PASSWORD: ");
			scanf("%d", &password);
			if (Userpw[id] == password)
			{
				goto machine;
			}

			else
			{
				printf("아이디나 비밀번호가 틀렸습니다. 다시 입력해주십시오.\n");
				goto IDCHECK;
			}
		}
		else if (con == 2)
		{
		IDREGISTER://ID CHECK 나중에 파일이랑 다시 연결할 예정 아직 파일 생성, 입출력이 익숙하지 않아 좀 더 공부하고 다시 만들 예정
			printf("새로 만들 ID하나를 1~100에서 선택하십시오.\n");
			printf("ID: ");
			scanf("%d", &id);
			if (id > 100 && id < 0)
			{
				printf("아이디나 비밀번호가 틀렸습니다. 다시 입력해주십시오.\n");
				goto IDREGISTER;
			}
			else if (Userid[id] != 0)
			{
				printf("이미 존재하는 아이디입니다.\n");
				goto IDREGISTER;
			}
			else if (Userid[id] == 0)
			{
				printf("비밀번호를 등록하십시오.\n");
				printf("PASSWORD: ");
				scanf("%d", &password);
				printf("초기 포인트 1000이 지급 됩니다.\n");
				UserPT[id] = 1000;
				Userid[id] = id;
				Userpw[id] = password;
				WriteDataFile();
				goto LOBBY;
			}
		}
		else
		{
			printf("다시 입력해주십시오.\n");
		}
	}

machine:
	while (checkpoint_2 == 1)
	{
		int nbet = 0;
		printf("현재 포인트는 %d 입니다.\n", mypoint(id));
		printf("3자리 슬롯 머신과 4자리 슬롯머신이 존재합니다. 3자리 슬롯 머신을 선택하려면 1번, 4자리 슬롯머신을 선택하려면 2번을 누르십시오.\n");
		scanf("%d", &selslot);
		printf("몇 포인트를 넣겠습니까?\n");
		scanf("%d", &nbet);
		if (selslot == 1)
		{
			int bonus = pointret_1(nbet);

			UserPT[id] = UserPT[id] - nbet + bonus;
		}
		else if (selslot == 2)
		{
			int bonus = pointret_2(nbet);

			UserPT[id] = UserPT[id] - nbet + bonus;
		}
		else
		{
			printf("잘못된 접근입니다.\n");
			goto RECHECK;
		}

		WriteDataFile();

		//mypoint(id) = mypoint(id) - pointret(nbet);

	RECHECK:
		printf("다시 하시겠습니까?\n");
		printf("다시하려면 1번, 종료하시려면 2번을 누르십시오.\n");
		scanf("%d", &con);
		if (con == 2)
		{
			return;
		}
		else if (con == 1)
		{
			goto machine;
		}
		else
		{
			printf("잘못된 접근입니다.\n");
			goto RECHECK;
		}
	}
}


int mypoint(int id)
{
	return UserPT[id];
}

void setpoint(int id, int pt)
{
	UserPT[id] = pt;
}


int pointret_1(int n)
{
	int a = 0, b = 0, c = 0;
	char disp_1, disp_2, disp_3;
	int nret = 0;
	srand(time(NULL));

	a = rand() % 10;
	b = rand() % 10;
	c = rand() % 10;
	//printf("%d %d %d", a, b, c);
	disp_1 = converter_1(a);
	disp_2 = converter_1(b);
	disp_3 = converter_1(c);

	printf("\n");
	if (disp_1 == disp_2 && disp_2 == disp_3)
	{
		switch (disp_1)
		{
		case '#':
			//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2); 색깔 넣었다가 마음에 안들어서 뺌
			printf("!!!! %d 1!!!\n", nret = n * 70);
			break;
		case '7':
			//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("!!!! %d 1!!!\n", nret = n * 140);
			break;
		case '%':
			//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
			printf("!!!! %d 1!!!\n", nret = n * 35);
			break;
		case '@':
			//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
			printf("!!!! %d 1!!!\n", nret = n * 10);
			break;
		}
	}
	else
	{
		//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
		printf("...꽝입니다.\n");
	}


	return nret;
}

char converter_1(int n)
{
	char	display;
	if (n >= 8) display = '#';
	else if (n == 7) display = '7';
	else if (n >= 4) display = '%';
	else display = '@';

	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	printf("%c ", display);
	return  display;
}
int pointret_2(int n)
{
	int a = 0, b = 0, c = 0, d = 0;
	char disp_1, disp_2, disp_3, disp_4;
	int nret = 0;
	srand(time(NULL));

	a = rand() % 10;
	b = rand() % 10;
	c = rand() % 10;
	d = rand() % 10;
	//printf("%d %d %d", a, b, c);
	//#   , %, @
	// 4배, 3배, 2배
	//환수율 70%
	disp_1 = converter_2(a);
	disp_2 = converter_2(b);
	disp_3 = converter_2(c);
	disp_4 = converter_2(d);

	printf("\n");
	if (disp_1 == disp_2 && disp_2 == disp_3 && disp_3 == disp_4)
	{
		switch (disp_1)
		{
		case '#':
			printf("!!!! %d 1!!!\n", nret = n * 250);
			break;
		case '7':
			printf("!!!! %d 1!!!\n", nret = n * 500);
			break;
		case '%':
			printf("!!!! %d 1!!!\n", nret = n * 120);
			break;
		case '@':
			printf("!!!! %d 1!!!\n", nret = n * 35);
			break;
		}
	}
	else
	{
		printf("...꽝입니다.\n");
	}


	return nret;
}

char converter_2(int n)
{
	char	display;
	if (n >= 8) display = '#';
	else if (n == 7) display = '7';
	else if (n >= 4) display = '%';
	else display = '@';

	printf("%c ", display);
	return  display;
}




void ReadDataFile()//user 값 읽는거
{
	char str[100];
	char strid[100];
	char strpw[100];
	char strPT[100];
	int i, j;
	int FullIndex;
	int SubIndex;

	fp = fopen("UserInformation.txt", "r");
	if (fp == NULL)
	{
		printf("이 파일은 존재하지 않습니다\n");
		return;
	}
	else
	{
		i = 0;
		FullIndex = 0;
		while (1)
		{
			memset(str, '\0', sizeof(str));
			//한줄씩 읽는다.
			if (fgets(str, 100, fp) == NULL)
				break;
			//fgets는 \n까지 얻는다. 맨 마지막 \n를 제거해준다.
			int max_len = strlen(str);
			if (max_len > 0)
			{
				str[max_len - 1] = '\0';
			}
			// 데이터 분리
			memset(strid, '\0', sizeof(strid));
			memset(strpw, '\0', sizeof(strpw));
			memset(strPT, '\0', sizeof(strPT));
			SubIndex = 0;
			FullIndex = 0;
			while (str[FullIndex] != ' ')
			{
				strid[SubIndex] = str[FullIndex];
				FullIndex++;
				SubIndex++;
				if (max_len < FullIndex) break;
			}
			strid[SubIndex] = '\0';
			SubIndex = 0;
			FullIndex++;
			while (str[FullIndex] != ' ')
			{
				strpw[SubIndex] = str[FullIndex];
				FullIndex++;
				SubIndex++;
				if (max_len < FullIndex) break;
			}
			strpw[SubIndex] = '\0';
			SubIndex = 0;
			FullIndex++;
			while (str[FullIndex] != '\0')
			{
				strPT[SubIndex] = str[FullIndex];
				FullIndex++;
				SubIndex++;
				if (max_len < FullIndex) break;
			}
			strPT[SubIndex] = '\0';
			Userid[i] = atoi(strid);
			Userpw[i] = atoi(strpw);
			UserPT[i] = atoi(strPT);
			i++;
		}
		fclose(fp);
	}
	return;
}
//user값 파일 입력 함수
void WriteDataFile()
{
	char str[100];
	int i;
	fp = fopen("UserInformation.txt", "w+");
	if (fp == NULL)
	{
		printf("이 파일은 존재하지 않습니다\n");
		return;
	}
	else
	{
		for (i = 0; i < 100; i++)
		{
			sprintf(str, "%d %d %d\n", Userid[i], Userpw[i], UserPT[i]);
			fputs(str, fp);
		}
		fclose(fp);
	}
}
//user값 파일 만드는 거
void initializeVar()
{
	int i;
	fp = fopen("UserInformation.txt", "r");
	if (fp == NULL)
	{
		for (i = 0; i < 100; i++)
		{
			Userpw[i] = 0;
			Userid[i] = 0;
			UserPT[i] = 0;
		}
	}
	else
	{
		fclose(fp);
		ReadDataFile();
	}
	return;
}
