#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <conio.h> //�Լ� kbhit()�� ��������
#include <windows.h> //�Լ� GetTickCount()�� ��������

/* �Լ� GetTickCount()�� ���� �ð��� ��ȯ�ϴ� �Լ��Դϴ�. 2��° ������ �����ӵ� �׽�Ʈ���� ����ؼ� Ư�� �ð��� �����ؾ��ϱ� ������ ����Ͽ����ϴ�. -������� ���ͳݿ��� �����߽��ϴ�.
�Լ� kbhit()�� �Է��� ������ ���͸� ������ �ʰ��� �ٷ� ����Ǳ����� ���ۿ� ���� ������ ��(1)�� ��ȯ�ϴ� �Լ��� ����߽��ϴ�. -������� ���ͳݿ��� �����߽��ϴ�.-
					   �� �� �Լ� ������ ������ ������ 2�������� �ڵ�� ���� ���� �ۼ��Ͽ����ϴ�.*/

void RSP(int num); //���������� �Լ� ����
void UpDown(int num); //���ٿ� ���� �Լ� ����

int main() {
	srand(time(NULL)); //����
	int gameNum; //������ ��ȣ
	int renum; //������ ������ ������ ���� ����
	int gameCount = 0; //�� ���� ���?
	int timeStart, timeEnd;
	printf("�����������������������������������������\n");
	printf("                        �ڡڡ� 1408�� �̴ϰ��ӱ� �ڡڡ�\n\n");
	printf("�̴ϰ��ӱ��� �������δ� �̰͵��� �־��!   1. �Ÿ����� ����������,  2. ������ �����ӵ� �׽�Ʈ,  3. �Ƿ������� ���ٿ����\n\n");
	timeStart = GetTickCount64();
start:
	printf("\n���� ������ �÷����ϰ� �����Ű���?: ");
	scanf("%d", &gameNum);
	while (gameNum < 1 || gameNum>3) {
		printf("\n����� �� ���ڸ� �Է����ּ���: ");
		scanf("%d", &gameNum);
	}
	if (gameNum == 1) {
		int RSPnum; //���������� �÷��� Ƚ��
	again1:
		printf("\n                '�Ÿ����� ����������' ������ �����մϴ�!!\n\n");
		printf("'�Ÿ����� ����������' ���ӿ�����  �ָ�:1, ����:2, ��:3 �� �Է����ֽø� �˴ϴ�!");
		printf("\n\n������������ ��� �÷��� �Ͻ� �ǰ���?: ");
		scanf("%d", &RSPnum);
		RSP(RSPnum);
		gameCount++;
		printf("\n\n                           �ڡڡڡڡڰ����� �������ϴ�!�ڡڡڡڡ�\n\n�ٽ� �� ������ �÷��� �Ͻ÷��� 1��, �ٸ� ������ �÷��� �Ͻ÷��� 2��, �̴ϰ����� �����Ϸ��� 3���� ��������: ");
		scanf("%d", &renum);
		while (renum < 1 || renum>3) {
			printf("\n����� �� ���ڸ� �Է����ּ���: ");
			scanf("%d", &renum);
		}
		if (renum == 1) goto again1;
		else if (renum == 2) goto start;
		else if (renum == 3) goto end;
	}
	else if (gameNum == 2) { //�����ӵ� �׽�Ʈ �ڵ�
		int time1, time2;
		int randomTime;
	again2:
		printf("�����ӵ� �׽�Ʈ�� �����մϴ� ������ ������ �ƹ� Ű�� ��������!");
		_sleep(1000);
		time1 = GetTickCount64();
		randomTime = rand() % 4000 + 400;
	regame:
		while (1)
		{
			if (GetTickCount64() - time1 >= randomTime) {
				printf("\n���������\n���������\n���������\n���������\n���������\n���������\n���������\n���������");
				time2 = GetTickCount64();
				break;
			}
		}
		while (1) {
			if (kbhit())
			{
				printf("\n\n����� �����ӵ��� %.2f�Դϴ�.", (float)(GetTickCount64() - time2) / 1000);
				break;
			}
		}
		gameCount++;
		printf("\n\n                           �ڡڡڡڡڰ����� �������ϴ�!�ڡڡڡڡ�\n\n�ٽ� �� ������ �÷��� �Ͻ÷��� 1��, �ٸ� ������ �÷��� �Ͻ÷��� 2��, �̴ϰ����� �����Ϸ��� 3���� ��������: ");
		scanf("%d", &renum);
		while (renum < 1 || renum>3) {
			printf("\n����� �� ���ڸ� �Է����ּ���: ");
			scanf("%d", &renum);
		}
		if (renum == 1) goto again2;
		else if (renum == 2) goto start;
		else if (renum == 3) goto end;
	}
	else if (gameNum == 3) {
		int level; //���� ���̵�
	again3:
		printf("\n               '�Ƿ������� ���ٿ����' �� �����մϴ�!!\n\n");
		printf("'�Ƿ������� ���ٿ����'�� ���̵��� ������ �� �ֽ��ϴ�. �ܰ踦 �����ּ��� 1, 2, 3: ");
		scanf("%d", &level);
		UpDown(level);
		gameCount++;
		printf("\n\n                           �ڡڡڡڡڰ����� �������ϴ�!�ڡڡڡڡ�\n\n�ٽ� �� ������ �÷��� �Ͻ÷��� 1��, �ٸ� ������ �÷��� �Ͻ÷��� 2��, �̴ϰ����� �����Ϸ��� 3���� ��������: ");
		scanf("%d", &renum);
		while (renum < 1 || renum>3) {
			printf("\n����� �� ���ڸ� �Է����ּ���: ");
			scanf("%d", &renum);
		}
		if (renum == 1) goto again3;
		else if (renum == 2) goto start;
		else if (renum == 3) goto end;
	}
end:
	timeEnd = GetTickCount64();
	printf("\n�̿����༭ �����մϴ�!  ����� �� %d���� ������ �÷����Ͽ����� �� %d�� ���� �̿��ϼ̽��ϴ�.\n", gameCount, (timeEnd - timeStart) / 1000);

	return 0;
}

//���������� �Լ� ����
void RSP(int num) {
	int comnum; //��ǻ�Ͱ� ���°�, comnum==1: �ָ�, comnum==2: ����, comnum==3: ��
	int mynum; //���� ���°� 
	int count = 0; //�̱� Ƚ�� ���� ����

	for (int i = 1; i <= num; i++) {
		comnum = rand() % 3 + 1;
		printf("\n\n������ ���ǰǰ���?: ");
		scanf("%d", &mynum);
		while (mynum < 1 || mynum>3) {
			printf("�ٽ� �Է����ּ���: ");
			scanf("%d", &mynum);
		}
		if (mynum == 1) {
			switch (comnum) {
			case 1:
				printf("��ǻ��: �ָ�\n���: �ָ�\n����.");
				break;
			case 2:
				printf("��ǻ��: ����\n���: �ָ�\n�̰��!");
				count++;
				break;
			case 3:
				printf("��ǻ��: ��\n���: �ָ�\n���� ��");
				break;
			}
		}
		else if (mynum == 2) {
			switch (comnum) {
			case 2:
				printf("��ǻ��: ����\n���: ����\n����.");
				break;
			case 3:
				printf("��ǻ��: ��\n���: ����\n�̰��!");
				count++;
				break;
			case 1:
				printf("��ǻ��: �ָ�\n���: ����\n���� ��");
				break;
			}
		}
		else if (mynum == 3) {
			switch (comnum) {
			case 3:
				printf("��ǻ��: ��\n���: ��\n����\n");
				break;
			case 1:
				printf("��ǻ��: �ָ�\n���: ��\n�̰��!");
				count++;
				break;
			case 2:
				printf("��ǻ�� ����\n���: ��\n���� ��");
				break;
			}
		}
	}
	printf("\n\n����� %d�� �� %d�� �̱�̽��ϴ�.", num, count);
}



//���ٿ� ���� �Լ� ����
void UpDown(int num) {
	srand(time(NULL));
	int max, n;
	int m = 0, chance, count = 0;
	if (num == 1) {
		max = 50;
		n = rand() % max + 1;
		chance = 6;
		printf("1�ܰ�� ���� �Ǿ����ϴ�.\n");
		_sleep(1000);
		printf("���ٿ������ �����մϴ�!");
	}
	else if (num == 2) {
		max = 100;
		n = rand() % max + 1;
		chance = 5;
		printf("2�ܰ�� ���� �Ǿ����ϴ�.\n");
		_sleep(1000);
		printf("���ٿ������ �����մϴ�!");
	}
	else if (num == 3) {
		max = 500;
		n = rand() % max + 1;
		chance = 7;
		printf("3�ܰ�� ���� �Ǿ����ϴ�.\n");
		_sleep(1000);
		printf("���ٿ������ �����մϴ�!");
	}
	else {
		max = 2000;
		n = rand() % max + 1;
		chance = 7;
		printf("��ȣ? ����� ���̵��� ���� ���ڸ� �Է��ϼ̽��ϴ�.\n");
		_sleep(2000);
		printf("�ؾ��� ���̵��� ���ٿ������ ���۵˴ϴ�.");
	}

	printf("\n\n1���� %d ������ ���� �����ϴ� �����Դϴ�!", max);
	while (n != m) {
		printf("\n\n������?: ");
		scanf("%d", &m);
		if (n > m) {
			printf("Ʋ�Ƚ��ϴ�. %d ���� Ů�ϴ�.", m);
		}
		else if (n < m) {
			printf("Ʋ�Ƚ��ϴ�. %d ���� �۽��ϴ�.", m);
		}
		if (n == m) break;
		chance--;
		count++;
		printf("\n\n���� ��ȸ: %d��", chance);
		if (chance == 0) {
			printf("\n�����߽��ϴ�. ������ %d�̾����ϴ�.", n);
			goto ending;
		}
	}
	printf("\n�����Դϴ�.\n\n%d�� ���� �������ϴ�.", count);
ending:
	printf("������");
}