#include<stdio.h>
#include<stdlib.h>
#include<time.h>//srand(time(NULL))
#include<windows.h>//Sleep �Լ� ��� (�ð� ����)
#include<process.h>//������ ����� �����ϰ� �ϴ� �������
// scanf������ �ߴ� ��� �Ű澲���� �� scanf_s�� �ٲ��־���.

/*�������?
���Ը���, 2���� �Լ��� ���ÿ� �����Ű�� ��*/

int graphfirst(int r);//ù��° �׷��� ���
int graph(int r, int fr);//�ι�° ������ �׷��� ���
void textcolor(int color_number);//���� ��

int M1 = 1, M2 = 2;

void* Thread_ms(void* fr) {		//�ż��� ����ϴ� ������
	int ms;
	scanf_s("%d", &ms);
	if (ms == 1)
		M1 = (int)fr;
}
void* Thread_md(void* fr) {		//�ŵ��� ����ϴ� ������
	int md;
	scanf_s("%d", &md);
	if (md == 2)
		M2 = (int)fr;
}
void* Thread_mo(void* r) {		//�� ����� ����ϴ� ������
	int mo, money = 1000, nmoney = 0;
	float rate = 0;
	scanf_s("%d", &mo);
	if (mo == 3) {
		nmoney = ((M2 - M1) * money / M1) + money;
		rate = (float)(nmoney * 100 / money);
		money = nmoney;
		printf("���� �ܰ�: %d, ��·�(%): %.1f %\n", money, rate);
	}
}

int main() {//main������ �׷��� �Լ��� ���ư���, �����忡���� �ż�, �ŵ��� ���ư���..

	srand(time(NULL));//��������

	int r1, r, fr;//r1: ù��°�� ���̰�, r: �ι�°������ ���̰�, fr: ����� ���� �������� ���鰪
	r1 = rand() % 5 + 1;
	printf("******���� �ֽİ���******\n�������� �׷����� ����ϰ�, �׿����� ������ ���Ѵ�.");
	printf("���η� �׷����� ��µȴ�.\n1�� ������ �ż�, 2�� ������ �ŵ�, 3�� ������ ��Ȳ����. �ŵ��� �ѵڿ� 1�� �ѹ� �� ������ �� �������� �ż��� �����Ͻʽÿ�.\n\n");
	printf("�����ݾ�: %d\n", 1000);

	fr = graphfirst(r1);
	Sleep(1500);
	while (1) {
		r = r1 * (rand() % 5 + 1);
		fr = graph(r, fr);//fr�� �� ���� ����+-���̷� ���־�� ���� �׷����� �� �׷����� ������ �����Ѵ�.
		_beginthread(Thread_mo, 0, (void*)r);//�����
		_beginthread(Thread_md, 0, (void*)fr);//�ŵ�
		_beginthread(Thread_ms, 0, (void*)fr);//�ż�
		Sleep(1500);
	}
	return 0;
}

int graphfirst(int r) {		//ù��° �� �׷��� ���
	r = r * (rand() % 5 + 1);
	if (r % 2 == 1) {
		textcolor(9);
		for (int i = 1; i <= 15; i++)//�׷����� �ʹ� ���ʿ� ġ��ģ�� ���� 15ĭ�� ����ĭ���� ����������
			printf(" ");
		for (int i = 1; i <= 36; i++)
			printf(" ");
		for (int j = 1; j <= r; j++)
			printf("*");
		printf("\n");
		return (36 + r);
	}
	else {
		textcolor(12);
		for (int i = 1; i <= 15; i++)
			printf(" ");
		for (int i = 1; i <= (36 - r); i++)
			printf(" ");
		for (int j = 1; j <= r; j++)
			printf("*");
		printf("\n");
		return (36 - r);
	}
}

int graph(int r, int fr) {		//�ι�° �̻� ���� �׷��� ���
	if (r % 2 == 1 || fr - r < 0) { //r�� Ȧ���϶��� �ð� ���
		textcolor(9);
		for (int i = 1; i <= 15; i++)
			printf(" ");
		for (int i = 1; i <= fr; i++)
			printf(" ");
		for (int j = 1; j <= r; j++)
			printf("*");
		printf("\n");
		return (fr + r);
	}
	else
		textcolor(12); //¦���϶��� �ð� �϶�.
	for (int i = 1; i <= 15; i++)
		printf(" ");
	for (int i = 1; i <= (fr - r); i++)
		printf(" ");
	for (int j = 1; j <= r; j++)
		printf("*");
	printf("\n");
	return (fr - r);
}

void textcolor(int color_number) {		//�׷��� ��
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_number);
}