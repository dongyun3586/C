#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <windows.h>

void print_time(int t, int x);				//�ð��� ������ִ� �Լ�
void timer();					//Ÿ�̸Ӱ� �۵��Ǵ� �Լ�

int times[10][5][4] =				//������ ���ڸ� �����ص� 3���� �迭
{
		{	{1,1,1,1},				//0
			{1,0,0,1},
			{1,0,0,1},
			{1,0,0,1},
			{1,1,1,1}
		},
		{	{0,0,0,1},				//1
			{0,0,0,1},
			{0,0,0,1},
			{0,0,0,1},
			{0,0,0,1}
		},
		{	{1,1,1,1},				//2
			{0,0,0,1},
			{1,1,1,1},
			{1,0,0,0},
			{1,1,1,1}
		},
		{	{1,1,1,1},				//3
			{0,0,0,1},
			{1,1,1,1},
			{0,0,0,1},
			{1,1,1,1}
		},
		{	{1,0,0,1},				//4
			{1,0,0,1},
			{1,1,1,1},
			{0,0,0,1},
			{0,0,0,1}
		},
		{	{1,1,1,1},				//5
			{1,0,0,0},
			{1,1,1,1},
			{0,0,0,1},
			{1,1,1,1}
		},
		{	{1,1,1,1},				//6
			{1,0,0,0},
			{1,1,1,1},
			{1,0,0,1},
			{1,1,1,1}
		},
		{	{1,1,1,1},				//7
			{0,0,0,1},
			{0,0,0,1},
			{0,0,0,1},
			{0,0,0,1}
		},
		{	{1,1,1,1},				//8
			{1,0,0,1},
			{1,1,1,1},
			{1,0,0,1},
			{1,1,1,1}
		},
		{	{1,1,1,1},				//9
			{1,0,0,1},
			{1,1,1,1},
			{0,0,0,1},
			{1,1,1,1}
		},
};

int main()
{
	int timer_key;					//�ð踦 �۵���ų�� Ÿ�̸Ӹ� �۵���ų�� �����ϴ� ����

	printf("\n\nŸ�̸Ӹ� �۵��ϰ� �ʹٸ� space��, �ð踦 �۵���Ű�� �ʹٸ� �ƹ�Ű�� ��������\n");

	timer_key = getch();			//Ű�� �Է� ����

	if (timer_key == 32)			//�����̽��ٰ� ������ Ÿ�̸� ����
	{
		timer();
		printf("�ð��� �������ϴ�");
	}
	else if (timer_key != 32)		//�����̽��ٰ� �ƴ� Ű�� ������ ������ �ð� ����
	{
		system("cls");
		while (1)
		{
			int t;
			t = time(NULL);			//���� �ð�(������� �귯�� �ð��� �ʷ� ����Ǿ� ����) ����

			print_time(t, 1);		//�ð� ���

			Sleep(1000);
			system("cls");
		}
	}
	return 0;
}

void print_time(int local_t, int x)	//Ÿ�̸ӿ� �ð��� �ð��� �������, ���⼭ x�� Ÿ�̸����� �ð����� �Ǻ�����(0�̸� Ÿ�̸�, 1�̸� �ð�)
{
	int hour, min, sec;
	int i, j, k, t = 0, clock[6] = { 0 };

	if (x == 1)						//�ð��� ���� ��, ��, �� ������ְ� ����
	{
		hour = ((local_t / 60) / 60 + 9) % 24;
		min = (local_t / 60) % 60;
		sec = local_t % 60;
	}
	else if (x == 0)				//Ÿ�̸Ӷ�� �Է����� ���ڸ� ��, ��, �ʷ� ����ϰ� ����
	{
		sec = local_t % 60;
		min = (local_t / 60) % 60;
		hour = (local_t / 3600);
	}

	if (hour > 12 && x == 1)		//�ð��� �����̶�� t�� 0, ���Ķ�� 1�� �־���´�.
	{
		t = 1;
		hour = hour - 12;
	}

	clock[0] = hour / 10;			//clock �迭�� ����� �ð� ����
	clock[1] = hour % 10;
	clock[2] = min / 10;
	clock[3] = min % 10;
	clock[4] = sec / 10;
	clock[5] = sec % 10;

	printf("\n\n");

	for (i = 0; i < 5; i++)			//������ ���پ� �������
	{
		for (j = 0; j < 5; j++)		//������ ���� �ð� �տ� ���� 5ĭ
		{
			if (i == 2 && j == 2 && x == 1)
			{
				if (t == 1)
					printf(" P");	//���Ķ�� P���
				else if (t == 0)
					printf(" A");	//�����̶�� A���
			}
			else if (i == 2 && j == 3 && x == 1)
				printf("M ");
			else
				printf("  ");
		}

		for (j = 0; j < 6; j++)		//clock�� �����ص״� �� 6���� ���
		{
			for (k = 0; k < 4; k++)
			{
				if (times[clock[j]][i][k] == 1)
				{
					printf("��");
				}
				else if (times[clock[j]][i][k] == 0)
				{
					printf("  ");
				}
			}

			printf("  ");

			if (j == 1 || j == 3)
			{
				if (i == 1 || i == 3)
				{
					printf("��");
					printf("  ");
				}
				else
				{
					printf("    ");
				}
			}
		}

		printf("\n");
	}
}

void timer()						//Ÿ�̸� ����ϴ� �Լ�
{
	system("cls");

	int timer_hour, timer_min, timer_sec, timer_time;

	printf("\n\nŸ�̸� �Դϴ�. �ð�, ��, ���� �Է��� �ּ���\n");
	printf("����)�ð��� ��� ���ļ� 99�ð� 59�� 59�ʰ� ������ �ȵ�\n");
	printf("�ð�,��,�ʸ� �Է��ϽǶ��� ���ڸ� �Է����ּ���\n\n");
	printf("�ð� : ");
	scanf("%d", &timer_hour);

	printf("�� : ");
	scanf("%d", &timer_min);

	printf("�� : ");
	scanf("%d", &timer_sec);

	timer_time = (timer_hour) * 3600 + timer_min * 60 + timer_sec;
	system("cls");

	while (timer_time != 0)			//�Է��� �ð��� ��� ���������� �ݺ�
	{
		print_time(timer_time, 0);
		Sleep(1000);
		timer_time--;
		system("cls");
	}
	return 0;
}