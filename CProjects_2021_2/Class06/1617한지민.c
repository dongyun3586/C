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
void ReadDataFile();//user �� �д� �Լ�
void WriteDataFile();//user�� ���� �Է� �Լ�

// ���������� �����Ͽ� �ƹ� �Լ����� ����� �� �ְ� ó����.
#define MAX_ID 101 //�ִ� ��� ���� ���̵𰳼��� 0~100���� 101���� ���� 
//user ������ ����, ���̵𰹼���ŭ ���̵� ���� �����Ͽ� ����Ȯ��.
int Userpw[MAX_ID];
int Userid[MAX_ID];
int UserPT[MAX_ID];
int UserOVR[MAX_ID];
int Userst[MAX_ID];
int Userlife[MAX_ID];

int nret; //�ٿ뵵 ���� ���� �� ���

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
		printf("�α����� �Ͻ÷��� 1��, ID�� ���� ����÷��� 2���� �������ּ���.\n");
		scanf("%d", &con);
		if (con == 1)
		{
		IDCHECK:	//IDȮ�� �ռ� ���ߴ� ��ó�� ���̵� ������ �������� �迭 �ּҷ� ����Ͽ� ��й�ȣ Ȯ��

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
		IDREGISTER:	//ID�ű� ��� user������ ����, �������� ID �������� 0���� �����Ǿ�����. ��, ���� ���� ���̵�� ��й�ȣ 0���� ���ٰ���
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
				printf("��й�ȣ�� ����Ͻʽÿ�.(�ݵ�� ��ȣ�� ����Ͻʽÿ�.)\n");
				printf("PASSWORD: ");
				scanf("%d", &password);
				printf("�ʱ� ����Ʈ 1000�� ���� �˴ϴ�.\n");
				printf("ī���� �̸��� ����Ͻʽÿ�.\n");
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
			printf("�ٽ� �Է����ֽʽÿ�.\n");
		}
	}
	ReadDataFile();
machine:	//ī���Ʋ �κ� ��ȭ�� �ϰų� ������ �ϴ� ���� ���ð���
	while (checkpoint_2 == 1)
	{
		int sel;
		printf("���� ī���� �����Դϴ�.\n");
		printf("OVERALL: %d\n", UserOVR[id]);
		printf("POINT: %d\n", UserPT[id]);
		printf("LIFE: %d\n", Userlife[id]);
		printf("������ �Ϸ��� 1��, ��ȭ�� �Ϸ��� 2���� �����ּ���.");
		scanf("%d", &sel);
		if (sel == 1) //���� ������ ī���� �������� ���Ͽ� ������ �¸�
		{
			srand(time(NULL));
			int comovr = Userst[id] * 100 + rand() % 100;
			printf(" ��ī���� �ɷ�ġ: %d\n", UserOVR[id]);
			printf("���ī���� �ɷ�ġ: %d\n", comovr);
			if (UserOVR[id] > comovr)
			{
				nret = 100 * (Userst[id] + 1);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
				printf("�����մϴ� �������� �¸��ϼ̽��ϴ�.\n");
				printf("����: %d\n", nret);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
			}
			else if (UserOVR[id] == comovr)
			{
				nret = 100;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
				printf("���º� �ٽ� �����Ͻʽÿ�.\n");
				printf("����: 100\n");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
			}
			else
			{
				nret = 100;
				Userlife[id]--;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
				printf("�������� �й��ϼ̽��ϴ�.\n");
				printf("����: %d\n", nret);
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
		else if (sel == 2) //��ȭ: ����Ȯ���� �������� ����(Ȯ���� ���� �ö󰡴� �������� �ٸ�)
		{
		upgrade:
			srand(time(NULL));
			printf("POINT: %d\n", UserPT[id]);
			printf("��ȭ�� ����� 100����Ʈ�Դϴ�.\n ��ȭ�� �Ͻ÷��� 1��, �ٽõ��ư��÷��� 2���� �����ּ���.\n");
			scanf("%d", &sel);
			if (sel == 1)
			{
				if (UserPT[id] < 100)
				{
					printf("����Ʈ�� �����մϴ�.\n");
					goto machine;
				}
				UserPT[id] -= 100;
				int bonus = pointret(100);	//������ ������� ���Ըӽ��� ��Ȱ���Ͽ� ����Ȯ���� �������� ������
				UserOVR[id] = UserOVR[id] + bonus;
				goto upgrade;
			}
			else if (sel == 2)
			{
				goto machine;
			}
			else
			{
				printf("�߸��� �����Դϴ�.\n");
				goto upgrade;
			}
		}
		else
		{
			printf("�߸��� �����Դϴ�.\n");
			goto machine;
		}


		WriteDataFile();

		//mypoint(id) = mypoint(id) - pointret(nbet);
	RECHECK:
		printf("�ٽ� �Ͻðڽ��ϱ�?\n");
		printf("�ٽ��Ϸ��� 1��, �����Ͻ÷��� 2���� �����ʽÿ�.\n");
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
			printf("�߸��� �����Դϴ�.\n");
			goto RECHECK;
		}

	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
End:	//��� 3���� �پ��� ���� ������ �ڽ��� ���ӿ��� ������� ������ �÷ȴ��� ������
	printf("END\n");
	printf("ī�� ����:\n");
	printf("ī�� �ɷ�ġ: %d\n", UserOVR[id]);
	printf("�ܿ�����Ʈ: %d\n", UserPT[id]);
	printf("Ŭ������ ��������: %d\n", Userst[id]);
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
		printf("...���Դϴ�.\n");
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

void ReadDataFile()//user�� �������� �д� �Լ�
{
	//���ڿ��� ���� ���� �ҷ����⿡ ���ڿ� �迭����
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
			if (fgets(str, 101, fp) == NULL)
				break;
			//fgets�� \n���� ��´�. �� ������ \n�� �������ش�.
			int max_len = strlen(str);
			if (max_len > 0)
			{
				str[max_len - 1] = '\0';
			}
			// ������ �и� ����
			memset(strid, '\0', sizeof(strid));
			memset(strpw, '\0', sizeof(strpw));
			memset(strPT, '\0', sizeof(strPT));
			memset(strst, '\0', sizeof(strst));
			memset(strOVR, '\0', sizeof(strOVR));
			memset(strlife, '\0', sizeof(strlife));
			SubIndex = 0;							//�ؽ�Ʈ ���Ͽ� ������ �� ���̿� ������ �ִٴ� ���� �̿��Ͽ�, SubIndex��, FullIndex��� ������ �̿��Ͽ� ���Ͽ� ����ִ� ������ �и��س��� ����
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


			Userid[i] = atoi(strid);		//atoi: ascii to integer ascii���� int������ �ٲپ��� �Լ��̴�.
			Userpw[i] = atoi(strpw);		//char(���ڿ�)�� int������ �ٲٴ� �ڵ�. ���Ͽ� ���ڿ������� ���� �����߱⿡ �� �ڵ带 ����Ѵ�.
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
//user�� ������ ���� �Է� �Լ�
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
			sprintf(str, "%d %d %d %d %d %d\n", Userid[i], Userpw[i], UserPT[i], Userst[i], UserOVR[i], Userlife[i]);	//���Ͽ� ������ ���� ���ڿ��� ����
			fputs(str, fp);	//���Ͽ� ���ڿ��� ����
		}
		fclose(fp);
	}
}
//user�� ���� ����� �Լ�
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