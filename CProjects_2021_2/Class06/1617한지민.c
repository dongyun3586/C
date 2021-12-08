#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include <time.h>
#include <memory.h>
#include <string.h>	//strlen memset
#include <windows.h>

int mypoint(int id);
void setpoint(int id, int pt);
int pointret(int n);
char converter(int n);

void initializeVar();
void ReadDataFile();//user 값 읽는 함수
void WriteDataFile();//user값 파일 입력 함수

// 전역변수로 선언하여 아무 함수에나 사용할 수 있게 처리함.
#define MAX_ID 101 //최대 등록 가능 아이디개수를 0~100까지 101개를 만듬 
//user 고유값 선언, 아이디갯수만큼 아이디를 통해 연동하여 정보확인.
int Userpw[MAX_ID];
int Userid[MAX_ID];
int UserPT[MAX_ID];
int UserOVR[MAX_ID];
int Userst[MAX_ID];
int Userlife[MAX_ID];

int nret; //다용도 값을 받을 때 사용

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

	while (checkpoint_1 == 1)
	{
		printf("로그인을 하시려면 1번, ID를 새로 만드시려면 2번을 선택해주세요.\n");
		scanf("%d", &con);
		if (con == 1)
		{
		IDCHECK:	//ID확인 앞서 말했던 것처럼 아이디를 나머지 고유값의 배열 주소로 사용하여 비밀번호 확인

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
		IDREGISTER:	//ID신규 등록 user고유값 설정, 그전까지 ID 고유값은 0으로 설정되어있음. 즉, 주인 없는 아이디는 비밀번호 0으로 접근가능
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
				printf("비밀번호를 등록하십시오.(반드시 번호로 등록하십시오.)\n");
				printf("PASSWORD: ");
				scanf("%d", &password);
				printf("초기 포인트 1000이 지급 됩니다.\n");
				printf("카드의 이름을 등록하십시오.\n");
				Userid[id] = id;
				Userpw[id] = password;
				UserPT[id] = 1000;
				Userst[id] = 0;
				UserOVR[id] = 70;
				Userlife[id] = 3;
				WriteDataFile();
				goto LOBBY;
			}

		}
		else
		{
			printf("다시 입력해주십시오.\n");
		}
	}
	ReadDataFile();
machine:	//카드배틀 부분 강화를 하거나 전투를 하는 등의 선택가능
	while (checkpoint_2 == 1)
	{
		int sel;
		printf("현재 카드의 상태입니다.\n");
		printf("OVERALL: %d\n", UserOVR[id]);
		printf("POINT: %d\n", UserPT[id]);
		printf("LIFE: %d\n", Userlife[id]);
		printf("전투를 하려면 1번, 강화를 하려면 2번을 눌러주세요.");
		scanf("%d", &sel);
		if (sel == 1) //전투 서로의 카드의 오버롤을 비교하여 높으면 승리
		{
			srand(time(NULL));
			int comovr = Userst[id] * 100 + rand() % 100;
			printf(" 내카드의 능력치: %d\n", UserOVR[id]);
			printf("상대카드의 능력치: %d\n", comovr);
			if (UserOVR[id] > comovr)
			{
				nret = 100 * (Userst[id] + 1);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
				printf("축하합니다 전투에서 승리하셨습니다.\n");
				printf("보상: %d\n", nret);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
			}
			else if (UserOVR[id] == comovr)
			{
				nret = 100;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
				printf("무승부 다시 도전하십시오.\n");
				printf("보상: 100\n");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
			}
			else
			{
				nret = 100;
				Userlife[id]--;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
				printf("전투에서 패배하셨습니다.\n");
				printf("보상: %d\n", nret);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
			}

			if (Userlife[id] != 0)
			{
				UserPT[id] += nret;
				Userst[id]++;
				goto RECHECK;
			}
			else
			{
				goto End;
			}

		}
		else if (sel == 2) //강화: 일정확률로 오버롤을 높임(확률에 따라 올라가는 오버롤이 다름)
		{
		upgrade:
			srand(time(NULL));
			printf("POINT: %d\n", UserPT[id]);
			printf("강화를 비용은 100포인트입니다.\n 강화를 하시려면 1번, 다시돌아가시려면 2번을 눌러주세요.\n");
			scanf("%d", &sel);
			if (sel == 1)
			{
				if (UserPT[id] < 100)
				{
					printf("포인트가 부족합니다.\n");
					goto machine;
				}
				UserPT[id] -= 100;
				int bonus = pointret(100);	//예전에 만들었던 슬롯머신을 재활용하여 일정확률로 오버롤을 높여줌
				UserOVR[id] = UserOVR[id] + bonus;
				goto upgrade;
			}
			else if (sel == 2)
			{
				goto machine;
			}
			else
			{
				printf("잘못된 선택입니다.\n");
				goto upgrade;
			}
		}
		else
		{
			printf("잘못된 선택입니다.\n");
			goto machine;
		}


		WriteDataFile();

		//mypoint(id) = mypoint(id) - pointret(nbet);
	RECHECK:
		printf("다시 하시겠습니까?\n");
		printf("다시하려면 1번, 종료하시려면 2번을 누르십시오.\n");
		scanf("%d", &con);
		if (con == 2)
		{
			WriteDataFile();
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
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
End:	//목숨 3개를 다쓰면 게임 오버로 자신이 게임에서 어느정도 성과를 올렸는지 보여줌
	printf("END\n");
	printf("카드 정보:\n");
	printf("카드 능력치: %d\n", UserOVR[id]);
	printf("잔여포인트: %d\n", UserPT[id]);
	printf("클리어한 스테이지: %d\n", Userst[id]);
	return 0;
}


int mypoint(int id)
{
	return UserPT[id];
}

void setpoint(int id, int pt)
{
	UserPT[id] = pt;
}

int pointret(int n)
{
	int a = 0, b = 0, c = 0;
	char disp_1, disp_2, disp_3;
	int nret = 0;
	srand(time(NULL));

	a = rand() % 10;
	b = rand() % 10;
	c = rand() % 10;
	//printf("%d %d %d", a, b, c);
	disp_1 = converter(a);
	disp_2 = converter(b);
	disp_3 = converter(c);

	printf("\n");
	if (disp_1 == disp_2 && disp_2 == disp_3)
	{
		switch (disp_1)
		{
		case '#':
			printf("!!!! %d !!!!\n", nret = n * 2);
			break;
		case '7':
			printf("!!!! %d !!!!\n", nret = n * 10);
			break;
		case '%':
			printf("!!!! %d !!!!\n", nret = n);
			break;
		case '@':
			printf("!!!! %d !!!!\n", nret = n / 2);
			break;
		}
	}
	else
	{
		printf("...꽝입니다.\n");
	}


	return nret;
}

char converter(int n)
{
	char	display;
	if (n >= 8) display = '#';
	else if (n == 7) display = '7';
	else if (n >= 4) display = '%';
	else display = '@';

	printf("%c ", display);
	return  display;
}

void ReadDataFile()//user의 고유값을 읽는 함수
{
	//문자열로 받은 값을 불러오기에 문자열 배열선언
	char str[101];
	char strid[101];
	char strpw[101];
	char strPT[101];
	char strst[101];
	char strOVR[101];
	char strlife[101];
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
			if (fgets(str, 101, fp) == NULL)
				break;
			//fgets는 \n까지 얻는다. 맨 마지막 \n를 제거해준다.
			int max_len = strlen(str);
			if (max_len > 0)
			{
				str[max_len - 1] = '\0';
			}
			// 데이터 분리 과정
			memset(strid, '\0', sizeof(strid));
			memset(strpw, '\0', sizeof(strpw));
			memset(strPT, '\0', sizeof(strPT));
			memset(strst, '\0', sizeof(strst));
			memset(strOVR, '\0', sizeof(strOVR));
			memset(strlife, '\0', sizeof(strlife));
			SubIndex = 0;							//텍스트 파일에 각각의 값 사이에 공백이 있다는 점을 이용하여, SubIndex와, FullIndex라는 변수를 이용하여 파일에 들어있는 값들을 분리해내는 과정
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
			while (str[FullIndex] != ' ')
			{
				strPT[SubIndex] = str[FullIndex];
				FullIndex++;
				SubIndex++;
				if (max_len < FullIndex) break;
			}
			strPT[SubIndex] = '\0';
			SubIndex = 0;
			FullIndex++;
			while (str[FullIndex] != ' ')
			{
				strst[SubIndex] = str[FullIndex];
				FullIndex++;
				SubIndex++;
				if (max_len < FullIndex) break;
			}
			strst[SubIndex] = '\0';
			SubIndex = 0;
			FullIndex++;
			while (str[FullIndex] != ' ')
			{
				strOVR[SubIndex] = str[FullIndex];
				FullIndex++;
				SubIndex++;
				if (max_len < FullIndex) break;
			}
			strOVR[SubIndex] = '\0';
			SubIndex = 0;
			FullIndex++;
			while (str[FullIndex] != '\0')
			{
				strlife[SubIndex] = str[FullIndex];
				FullIndex++;
				SubIndex++;
				if (max_len < FullIndex) break;
			}
			strlife[SubIndex] = '\0';


			Userid[i] = atoi(strid);		//atoi: ascii to integer ascii값을 int값으로 바꾸어준 함수이다.
			Userpw[i] = atoi(strpw);		//char(문자열)을 int값으로 바꾸는 코드. 파일에 문자열값으로 값을 저장했기에 이 코드를 사용한다.
			UserPT[i] = atoi(strPT);
			Userst[i] = atoi(strst);
			UserOVR[i] = atoi(strOVR);
			Userlife[i] = atoi(strlife);
			i++;
		}
		fclose(fp);
	}
	return;
}
//user의 고유값 파일 입력 함수
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
			sprintf(str, "%d %d %d %d %d %d\n", Userid[i], Userpw[i], UserPT[i], Userst[i], UserOVR[i], Userlife[i]);	//파일에 저장할 값을 문자열로 저장
			fputs(str, fp);	//파일에 문자열을 저장
		}
		fclose(fp);
	}
}
//user값 파일 만드는 함수
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
			Userst[i] = 0;
			UserOVR[i] = 0;
			Userlife[i] = 0;
		}
	}
	else
	{
		fclose(fp);
		ReadDataFile();
	}
	return;
}