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
void ReadDataFile();//user �� �д°�
void WriteDataFile();//user�� ���� �Է� �Լ�

// ���������� �����Ͽ� �ƹ� �Լ����� ����� �� �ְ� ó����.
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

	printf("�ȳ��ϼ���. �Ƹ��ٿ� ����Ʈ ����Դϴ�..\n");

	while (checkpoint_1 == 1)
	{
		printf("�α����� �Ͻ÷��� 1��, ID�� ���� ����÷��� 2���� �������ּ���.\n");
		scanf("%d", &con);
		if (con == 1)
		{
		IDCHECK://ID CHECK ���߿� �����̶� �ٽ� ������ ���� ���� ���� ����, ������� �ͼ����� �ʾ� �� �� �����ϰ� �ٽ� ���� ����

			printf("ID�� �Է��Ͻʽÿ�.   ID: ");
			scanf("%d", &id);
			if (id > 100)
			{
				printf("���̵� ��й�ȣ�� Ʋ�Ƚ��ϴ�. �ٽ� �Է����ֽʽÿ�.\n");
				printf("ID �� 1~100���� �����Ͻʽÿ�.\n");
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
				printf("���̵� ��й�ȣ�� Ʋ�Ƚ��ϴ�. �ٽ� �Է����ֽʽÿ�.\n");
				goto IDCHECK;
			}
		}
		else if (con == 2)
		{
		IDREGISTER://ID CHECK ���߿� �����̶� �ٽ� ������ ���� ���� ���� ����, ������� �ͼ����� �ʾ� �� �� �����ϰ� �ٽ� ���� ����
			printf("���� ���� ID�ϳ��� 1~100���� �����Ͻʽÿ�.\n");
			printf("ID: ");
			scanf("%d", &id);
			if (id > 100 && id < 0)
			{
				printf("���̵� ��й�ȣ�� Ʋ�Ƚ��ϴ�. �ٽ� �Է����ֽʽÿ�.\n");
				goto IDREGISTER;
			}
			else if (Userid[id] != 0)
			{
				printf("�̹� �����ϴ� ���̵��Դϴ�.\n");
				goto IDREGISTER;
			}
			else if (Userid[id] == 0)
			{
				printf("��й�ȣ�� ����Ͻʽÿ�.\n");
				printf("PASSWORD: ");
				scanf("%d", &password);
				printf("�ʱ� ����Ʈ 1000�� ���� �˴ϴ�.\n");
				UserPT[id] = 1000;
				Userid[id] = id;
				Userpw[id] = password;
				WriteDataFile();
				goto LOBBY;
			}
		}
		else
		{
			printf("�ٽ� �Է����ֽʽÿ�.\n");
		}
	}

machine:
	while (checkpoint_2 == 1)
	{
		int nbet = 0;
		printf("���� ����Ʈ�� %d �Դϴ�.\n", mypoint(id));
		printf("3�ڸ� ���� �ӽŰ� 4�ڸ� ���Ըӽ��� �����մϴ�. 3�ڸ� ���� �ӽ��� �����Ϸ��� 1��, 4�ڸ� ���Ըӽ��� �����Ϸ��� 2���� �����ʽÿ�.\n");
		scanf("%d", &selslot);
		printf("�� ����Ʈ�� �ְڽ��ϱ�?\n");
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
			printf("�߸��� �����Դϴ�.\n");
			goto RECHECK;
		}

		WriteDataFile();

		//mypoint(id) = mypoint(id) - pointret(nbet);

	RECHECK:
		printf("�ٽ� �Ͻðڽ��ϱ�?\n");
		printf("�ٽ��Ϸ��� 1��, �����Ͻ÷��� 2���� �����ʽÿ�.\n");
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
			printf("�߸��� �����Դϴ�.\n");
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
			//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2); ���� �־��ٰ� ������ �ȵ� ��
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
		printf("...���Դϴ�.\n");
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
	// 4��, 3��, 2��
	//ȯ���� 70%
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
		printf("...���Դϴ�.\n");
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




void ReadDataFile()//user �� �д°�
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
		printf("�� ������ �������� �ʽ��ϴ�\n");
		return;
	}
	else
	{
		i = 0;
		FullIndex = 0;
		while (1)
		{
			memset(str, '\0', sizeof(str));
			//���پ� �д´�.
			if (fgets(str, 100, fp) == NULL)
				break;
			//fgets�� \n���� ��´�. �� ������ \n�� �������ش�.
			int max_len = strlen(str);
			if (max_len > 0)
			{
				str[max_len - 1] = '\0';
			}
			// ������ �и�
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
//user�� ���� �Է� �Լ�
void WriteDataFile()
{
	char str[100];
	int i;
	fp = fopen("UserInformation.txt", "w+");
	if (fp == NULL)
	{
		printf("�� ������ �������� �ʽ��ϴ�\n");
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
//user�� ���� ����� ��
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
