#include<stdio.h>
#include<time.h>
#include<ctype.h>
#include<string.h>
#include<windows.h>
#include<math.h>
#include <conio.h> 
#define level 3;//�� ���� ��ȯ���Ѽ� ��ǻ���� Ȯ���� �ٲ㼭 ���̵��� �����Ҽ� �ֽ��ϴ�.
#define point 5;//�� ������ �ʱ� ����Ʈ�� �󸶳� ������ ���� �ֽ��ϴ�.
void person1(int x, int y, char* name);//007������ �����ϴ� ����� �����ϴ� �Լ��Դϴ�.
void eakm(int p, int c1, int c2, int c3);//���� ������ �ϴ��� �߰��� �з��ϴ� �Լ��Դϴ�.
int timeget(char* c, float time) {
	clock_t start = clock();
	while (1)
	{
		if (kbhit())
		{
			scanf("%s", c);
			return 0;
		}
		if ((clock() - start) / CLOCKS_PER_SEC > time)
			return -1;
	}
}//���ͳݿ��� �����ͼ� �ణ ������ �Լ��� ������ �ð��ȿ� �Է��� �޴� �Լ��Դϴ�. �ð��ȿ� ���������� �Է¹����� 0�� ��ȯ�ǰ� �ƴϸ� -1�� ��ȯ�˴ϴ�.//���� ���� ����� ���� ���� �Է¹޾Ƽ� ������ �ؾ��ϴ� ����� �з��ϴ� �Լ��Դϴ�.
void eak(int tem, int* p, int* c1, int* c2, int* c3);//���� �������� �������� �Է¹޾Ƽ� Ȯ���� ���� ��ǻ�Ͱ� ������ �ϴ��� �ƴϸ� ���ϴ����� �����ϰ� �÷��̾ ������ �ϴ��� ���ϴ��� �ð��ȿ� �Է¹޽��ϴ�.
void arrow(int num);//���� 007������ �������� ȭ��ǥ�� ���ִ����� ȭ�鿡�� �����ִ� �Լ��Դϴ�.
void display1();//�ʱ⿡ �������� ����� ���� �⺻���� ȭ���� �����ϴ� �Լ��Դϴ�.
void person(int x, int y, char* name);//�������� ���� �׷��ִ� �Լ��Դϴ�.
void gotoxy(int x, int y) {
	x *= 2;
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}//���ͳݿ��� �����°ɷ� ������ xy��ǥ�� Ŀ���� �̵������ݴϴ�.

void color(int a, int b) {
	int i = a + b * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i); //a�� ������ �����̰� b�� �������� ���ͳݿ� �ִ� ���� ǥ�� ���� �Է��ѵ� �����ϸ� �� �Լ� ���� ���ڵ��� ���� ���մϴ�.
}//���ͳݿ��� �����ͼ� �ణ ��ȯ��Ų�ɷ� ������ ���ڻ��� �ٲ��ݴϴ�.
void poi(int x, int y) {
	gotoxy(57, 25);
	for (int j = 0; j < 8; j++) {
		for (int i = 0; i < 50; i++) {
			printf("  ");
		}
		gotoxy(57, 25 + j);
	}//������ �̹� �����ϴ� ��ź �������� �����
	gotoxy(x - 1, y - 2);
	color(4, 0);
	printf("   ��   ");
	gotoxy(x - 1, y - 1);
	printf("   ��   ");
	gotoxy(x - 1, y);
	printf("����ࢹ");
	gotoxy(x - 1, y + 1);
	printf("����ࢹ");
	gotoxy(x - 1, y + 2);
	printf("  ���  ");//��ǥ�� ��ź �������� �׷��ݴϴ�.
	color(15, 0);
}//arrow�Լ��� ȭ�鿡 007�� �Ѿ��� �ִ� ��ġ�� ǥ���ؾ��ϴµ� ǥ���ϴ� �������� �׷��ִ� �Լ��Դϴ�.
void damage(int x, int y, char* c) {
	color(12, 0);//���������� �ٲ㼭
	person(x, y, c);//����� �ٽ� �׸���
	Sleep(500);//�ִٰ�
	color(15, 0);//����������
	person(x, y, c);//����� �ٽ� �׸��ϴ�.
}//���ӿ��� ���� ����Ʈ�� ���̸� ��������� �ϴ� ���� ������ �����̰� �ϴ� �����Դϴ�.
void start1(int* r);//������ ���ϴ� ����� ���ϴ� �����̱� �Լ��Դϴ�.
void choice(int* r);//����� ������ ���ϴ� ��� ������� ���� ����� �����Դϴ�.
void start2(int* r);//��ǻ�Ͱ� ������ �����Ұ�� �� �����ߴ��� �����̱��ϴ� �Լ��Դϴ�.
int game();//���� 3�Լ��� �����Ͽ��� ���� �Լ��� ������ �����Ҷ� ������ ���ϴ� ������ �Լ��Դϴ�.
void number(int a, int b, int c);//���ϴ� ���ڸ� ���ϴ� ��ǥ�� �׷��ִ� �Լ��Դϴ�.
void zzsnum(int num) {
	if (num == 4) {//�̹� �Ѿ��� ù��° 0���� ��Ÿ���ϴ�.
		number(0, 50, 15);
	}
	if (num == 3) {//�̹��Ѿ��� �ι�° 0���� ��Ÿ���ϴ�.
		number(0, 55, 15);
	}
	if (num == 2) {//�̹��Ѿ��� 7
		number(7, 60, 15);
	}
	if (num == 1) {//�̹��� ���̶�� ���� ��Ÿ���ݴϴ�.

		gotoxy(66 - 1, 17 - 2);
		color(4, 0);
		printf("   ��   ");
		gotoxy(66 - 1, 17 - 1);
		printf("   ��   ");
		gotoxy(66 - 1, 17);
		printf("����ࢹ");
		gotoxy(66 - 1, 17 + 1);
		printf("����ࢹ");
		gotoxy(66 - 1, 17 + 2);
		printf("  ���  ");
		color(15, 0);
	}
}//007������ �̹��� �����Ѽ� ���޵� �Ѿ��� ���° �Ѿ����� �˷��ִ� ���� ǥ���Ͽ����ϴ�.


void game1(int* p, int* s1, int* s2, int* s3);//��ġ������ �����ϴ� �Լ��Դϴ�.
void game2(int* p, int* s1, int* s2, int* s3);//007���� �����ϴ� �Լ��Դϴ�.
void comsel(int* c1, int* c2, int* c3, int s1, int s2, int s3);//��ġ���ӿ��� ������ ��ǻ�Ͱ� ���ڸ� �θ����� �� �θ����� ���� �����Լ��Դϴ�.
void zzs(int* x);//007������ �Ѿ��� �������� �������� ���� �Լ��Դϴ�.
void clear();//������ ���ڰ� ������ �κ��� ��� �����ִ� �Լ��Դϴ�.
typedef struct tim {
	int sec;
	int min;
	int hour;
}tm;//���Ӱ����� ����ؼ� �ؽ�Ʈ���Ϸ� �������ǵ� �̶� �ð��� ����ϱ����� ����ü�� �ϳ� ��������ϴ�.
void main() {
	FILE* fp = fopen("score.txt", "w");//score.txt�� ������� ���ϴ�.
	time_t ti = time(NULL);//ti�� ����ð��� �����ϰ� 
	tm* tim = localtime(&ti);//tim�� �����մϴ�.
	display1();//�ʱ�ȭ���� ����
	int scorep = point;
	int score1 = point;
	int score2 = point;
	int score3 = point;//�ʱ� ������ �ݴϴ�.
	fprintf(fp, "%2d h:%2d m:%2d s     %d %d %d %d\n", tim->hour, tim->min, tim->sec, scorep, score1, score2, score3);//�޸��忡 ���� ���� ���
	printf("    ���ӽ���\n"); int s;
	do {
		clear();//����â�� �����ְ�
		Sleep(1000);
		gotoxy(0, 0);
		s = game();//������ �����ݴϴ�.
		switch (s) {
		case 1:game1(&scorep, &score1, &score2, &score3);//1�̸� ��ġ����
			break;
		case 2: game2(&scorep, &score1, &score2, &score3);//2�̸� 007���� �����մϴ�.
			poi(66, 17);//poi���� ������ ������ ����� �ڵ带 ���ְ�
			for (int i = 50; i < 69; i++) {
				for (int j = 15; j < 21; j++) {
					gotoxy(i, j);
					printf("  ");
				}
			}//007���� ǥ�ÿ� ���ڵ��� �����ݴϴ�.
			break;
		}
		ti = time(NULL);
		tim = localtime(&ti);//����ð��� �����ϰ�
		fprintf(fp, "%2d h:%2d m:%2d s     %d %d %d %d\n", tim->hour, tim->min, tim->sec, scorep, score1, score2, score3);//�� �޸��忡 ������ ����Ѵ�.

		number(scorep, 93, 2);
		number(score1, 93 + 6, 2);
		number(score2, 93 + 2 * 6, 2);
		number(score3, 93 + 3 * 6, 2);//�������� ��Ĩ�ϴ�.
	} while (scorep != 0 && score1 != 0 && score2 != 0 && score3 != 0);//���� 0�� �Ǹ� �����ϴ�.
	fprintf(fp, "����\n\n");//�޸��忡 ������ ����մϴ�.
}


void game1(int* p, int* s1, int* s2, int* s3) {
	int r = 1, number = 1;
	int numbers[4] = { 0 };
	int i, c1, c2, c3;
	int now = 0;
	int now1 = 0, now2 = 0, now3 = 0;
	gotoxy(1, 1);
	while (1) {
		printf("\n%d��°\n", r);//����� ������ ǥ��
		i = 0;
		while (now == 0) {//���� ���� ��ȣ�� ���θ� ��쿡�� ��� �÷��̾��� �Է��� �޴´�.
			scanf("%d", &i);
			if (i == 0 || i == 1)
				break;//0�Ǵ� 1�� �÷��̾�� �Է¹޴´�.
		}
		comsel(&c1, &c2, &c3, now1, now2, now3);//��ǻ���� ������ �Է¹ް�
		printf("%d %d %d %d \n\n", i, c1, c2, c3);//����Ѵ�.
		if (i + c1 + c2 + c3 > 1) {//������ ���ÿ� 1�� �����Ͽ��� ���� 1�� ������
			number = -1;//�ߺ� �������� ������ ǥ���Ѵ�.
			break;//������.
		}
		else {//�Ѹ� ������ ���
			if (i == 1) {//���� 1�̸� 0�� �ڸ��� ���ڸ� �־��ش�. �׸��� number�� �÷��ش�.
				numbers[0] = number;
				now = 1;//������ �÷��̾��� �Է��� �ȹް��Ѵ�.
				number++;//�Ѹ��� ������� �����ش�.
			}
			if (c1 == 1) {//��ǻ��1�� ����Ѱ��
				numbers[1] = number;
				number++;
				now1 = 1;//��ǻ�� 1�� ����Ͽ��� ������ ���ڸ� �θ� �ʿ䰡 ������ ���δ�.
			}
			if (c2 == 1) {//��ǻ��2 ���
				numbers[2] = number;
				number++;
				now2 = 1;
			}
			if (c3 == 1) {//��ǻ�� 3 ���
				numbers[3] = number;
				number++;
				now3 = 1;
			}
		}
		r++;//���� ���� �÷��� ���������� ����.
		if (number == 4 || number == -1)break;//��� ���ڸ� �ҷ��ų� �ߺ������� �Ͼ ��� ���� �����Ű�� ����������� ����.
		Sleep(500);
	}
	if (number == -1) {//�ߺ������ΰ��
		if (i == 1) {//���� ���ڸ� �ҷ����� �ߺ������̸�
			(*p)--;//���� ���
			damage(56, 33, "PLAYER");//�����δ�.
		}
		if (c1 == 1) {
			(*s1)--;
			damage(71, 33, "COM1");
		}
		if (c2 == 1) {
			(*s2)--;
			damage(86, 33, "COM2");
		}
		if (c3 == 1) {
			(*s3)--;
			damage(101, 33, "COM3");
		}//�������� ����
	}
	if (number == 4) {//3���� ���ڸ� �θ����
		if (numbers[0] == 0) {
			(*p)--;
			damage(56, 33, "PLAYER");

		}
		if (numbers[1] == 0) {
			(*s1)--;
			damage(71, 33, "COM1");

		}
		if (numbers[2] == 0) {
			(*s2)--;
			damage(86, 33, "COM2");

		}
		if (numbers[3] == 0) {
			(*s3)--;
			damage(101, 33, "COM3");
			//���ڸ� �Ⱥҷ��� �ڽ��� �ڸ��� ���ڰ� ���� 0�̸� ������ ��´�.
		}
	}
}
void comsel(int* c1, int* c2, int* c3, int s1, int s2, int s3) {
	int d1, d2, d3;
	srand(time(NULL));
	d1 = rand() % level + 1;
	d2 = rand() % level + 1;
	d3 = rand() % level + 1;//�������� ���ڸ� �����Ѵ�.
	if (d1 == 1)*c1 = 1;//d1�� 1�̸� c1�� 1�� �����Ѵ�.
	else *c1 = 0;//�ƴϸ� 0�� �����Ѵ�.
	if (d2 == 1)*c2 = 1;
	else *c2 = 0;
	if (d3 == 1)*c3 = 1;
	else *c3 = 0;
	if (s1 == 1)*c1 = 0;//������ s1�� 1 �� ��ǻ��1�� ���ڸ� �̹� �ҷ��� �θ� �ʿ䰡 ������ �ٽ� 0���� �ٲ��ش�.
	if (s2 == 1)*c2 = 0;
	if (s3 == 1)*c3 = 0;
}
void game2(int* p, int* s1, int* s2, int* s3) {
	int num;
	int eak0 = 0, eak1 = 0, eak2 = 0, eak3 = 0;
	int what = 1;
	int end = 0;
	int tem;
	while (1) {
		num = 4;
		clear();
		for (int i = 50; i < 69; i++) {
			for (int j = 15; j < 21; j++) {
				gotoxy(i, j);
				printf("  ");
			}
		}//������ ��µȰ��� �����ְ�
		gotoxy(1, 1);
		while (1) {
			zzs(&tem);//�������� �Ѿ��� �����ߴ��� ����
			arrow(tem);//ǥ���ϰ�
			gotoxy(1, 1);
			zzsnum(num);//���° �Ѿ����� ǥ���ϰ�
			num--;//�����Ѿ˷� �Ѿ��.
			if (num == 0)break;//�������̸� ���带 �����Ѵ�.
			Sleep(700);
		}
		eak(tem, &eak0, &eak1, &eak2, &eak3);//������ �ߴ��� ���ߴ��� �Է¹ް�
		eakm(eak0, eak1, eak2, eak3);//ǥ�����ְ�
		end = 0;
		switch (tem) {
		case 0:
			if (eak0) {
				end = 1;
				(*p)--;
				damage(56, 33, "PLAYER");
			}
			if (!eak1) {
				end = 1;
				(*s1)--;
				damage(71, 33, "COM1");
			}
			if (eak2) {
				end = 1;
				(*s2)--;
				damage(86, 33, "COM2");
			}
			if (!eak3) {
				end = 1;
				(*s3)--;
				damage(101, 33, "COM3");
			}
			break;
		case 1:
			if (!eak0) {
				end = 1;
				(*p)--;
				damage(56, 33, "PLAYER");
			}
			if (eak1) {
				end = 1;
				(*s1)--;
				damage(71, 33, "COM1");
			}
			if (!eak2) {
				end = 1;
				(*s2)--;
				damage(86, 33, "COM2");
			}
			if (eak3) {
				end = 1;
				(*s3)--;
				damage(101, 33, "COM3");
			}
			break;
		case 2:
			if (eak0) {
				end = 1;
				(*p)--;
				damage(56, 33, "PLAYER");
			}
			if (!eak1) {
				end = 1;
				(*s1)--;
				damage(71, 33, "COM1");
			}
			if (eak2) {
				end = 1;
				(*s2)--;
				damage(86, 33, "COM2");
			}
			if (!eak3) {
				end = 1;
				(*s3)--;
				damage(101, 33, "COM3");
			}
			break;
		case 3:
			if (!eak0) {
				end = 1;
				(*p)--;
				damage(56, 33, "PLAYER");
			}
			if (eak1) {
				end = 1;
				(*s1)--;
				damage(71, 33, "COM1");
			}
			if (!eak2) {
				end = 1;
				(*s2)--;
				damage(86, 33, "COM2");
			}
			if (eak3) {
				end = 1;
				(*s3)--;
				damage(101, 33, "COM3");
			}
			break;
		}//������ �ؾ��ϴ� ����� �ϰ� ���ؾ��ϴ� ����� ���ߴ��� �Ǵ��ϰ� �߸��Ǿ����� ������ ��´�. �߸��� ��찡 ������ end�� 1�� �ȴ�. ��� �ùٸ� ��� end�� �״�� 0�̾ �ٽ� �����ϰ� �ȴ�.
		if (end)return;//�߸��� ��찡 ������ �����Ѵ�.
	}
}
void eak(int tem, int* p, int* c1, int* c2, int* c3) {
	int num1, num2;
	char ans[20] = "kkk";
	char eak[20] = "eak";
	if (tem == 0)//���� ������ �Ѿ��� �÷��̾�� ������
		num1 = 1; num2 = 3;//��ǻ��1�� ��ǻ��3�� ������ �ؾ��Ѵ�.
	if (tem == 1)
		num1 = 0; num2 = 2;
	if (tem == 2)
		num1 = 1; num2 = 3;
	if (tem == 3)
		num1 = 0; num2 = 2;//�������� ����
	gotoxy(1, 6);
	timeget(ans, 0.25);//���� ������ �ϴ��� ���ϴ��� �ð��ȿ� �Է¹ް�
	gotoxy(1, 6);
	printf("                ");
	if (strcmp(ans, eak) == 0)//���� ģ ���ڰ� eak���� �ƴ��� Ȯ���Ѵ�.
		*p = 1;
	else
		*p = 0;
	if (num1 == 1) {
		srand(time(NULL));
		*c1 = rand() % 10;//Ȯ�������� ��ǻ�Ͱ� ������ �Ѵ�.
	}
	else {
		srand(time(NULL));
		*c1 = rand() % 10;
		if (*c1 == 0)
			*c1 = 1;
		else
			*c1 = 0;
	}

	if (num2 == 2) {
		srand(time(NULL));
		*c2 = rand() % 10;
		*c3 = rand() % 10;
		if (*c3 == 0)
			*c3 = 1;
		else
			*c3 = 0;
	}
	if (num2 == 3) {
		srand(time(NULL));
		*c2 = rand() % 10;
		*c3 = rand() % 10;
		if (*c2 == 0)
			*c2 = 1;
		else
			*c2 = 0;
	}//��� ��Ȳ���� Ȯ�������� ������ �Ѵ�.
}
void arrow(int num) {
	switch (num) {
	case 0: poi(59, 28);
		break;
	case 1:
		poi(74, 28);
		break;
	case 2:
		poi(89, 28);
		break;
	case 3:
		poi(104, 28);
		break;
	}//�Ѿ��� �ִ� ��� ���� ��ź �������� ����.
	person(56, 33, "PLAYER");
	person(71, 33, "COM1");
	person(86, 33, "COM2");
	person(101, 33, "COM3");
}
void eakm(int p, int c1, int c2, int c3) {
	if (p)
		person1(56, 33, "PLAYER");
	if (c1)
		person1(71, 33, "COM1");
	if (c2)
		person1(86, 33, "COM2");
	if (c3)
		person1(101, 33, "COM3");//������ ����� ���� ���� ����ٰ� �������.
}
void zzs(int* x) {
	if (*x == 0) {
		gotoxy(1, 5);
		scanf("%d", x);
		gotoxy(1, 5);
		printf("                     ");
		gotoxy(1, 4);
		printf("%d���� �Ѱ���ϴ�.", *x);//���� ��� �Ѿ��� �ѱ��.
	}
	else {
		gotoxy(1, 4);
		srand(time(NULL));
		*x = rand() % 4;
		printf("%d���� �Ѱ���ϴ�.", *x);
	}//��ǻ�Ͱ� �������� �Ѿ��� �ѱ��.
}
int game() {

	srand(time(NULL));
	int r;
	start1(&r);//ó�� ���� ������ �� �� ����
	if (r > 0) {
		start2(&r);//��ǻ�Ͱ� �ɸ��� �������� ����.
		Sleep(500);
	}
	else choice(&r);//���� ���� �ϸ� �Է¹޴´�.

	for (int i = 0; i < 65; i++) {
		gotoxy(0, i);
		for (int j = 0; j < 39; j++)
			printf("  ");//����â�� �����ش�.
	}
	return r;
}
void start1(int* r) {
	int i = rand() % 100 + 1;
	if (i <= 25) {
		printf("    ���� �ɸ�\n");
		*r = 0;
	}//25%Ȯ���� ���� �ɸ���
	else {
		srand(time(NULL));
		int x = rand() % 3 + 1;
		printf("    COM%d�� �ɸ�\n", x);
		*r = x;//������ Ȯ���� ��ǻ�Ͱ� �ɸ���.
		Sleep(300);
	}
}
void start2(int* r) {
	*r = rand() % 2 + 1;
	switch (*r) {
	case 1: printf("    ��ġ����\n");//��ǻ�Ͱ� �ɸ� �ܿ� 50%Ȯ���� ��ġ���� �Ǵ� 007���� ����.
		break;
	case 2: printf("    007\n");
		break;
	}
	Sleep(1000);
}
void choice(int* r) {
	scanf("%d", r);
	switch (*r) {
	case 1: printf("    ��ġ����\n");
		break;
	case 2: printf("    007\n");
		break;//�÷��̾ �ɸ��� ������ �����Ѵ�.
	}
	Sleep(1000);
}
void number(int a, int b, int c) {
	switch (a) {//a�� ����� �Լ��� �ް� b�� c�� ���� xy���� �޾Ƽ� �� ��ġ�� a�� ����Ѵ�.
	case 0:
		gotoxy(b, c);
		printf("����");
		gotoxy(b, c + 1);
		printf("��  ��");
		gotoxy(b, c + 2);
		printf("��  ��");
		gotoxy(b, c + 3);
		printf("��  ��");
		gotoxy(b, c + 4);
		printf("����");
		break;

	case 1:
		gotoxy(b, c);
		printf("  ��  ");
		gotoxy(b, c + 1);
		printf("  ��  ");
		gotoxy(b, c + 2);
		printf("  ��  ");
		gotoxy(b, c + 3);
		printf("  ��  ");
		gotoxy(b, c + 4);
		printf("  ��  ");
		break;

	case 2:
		gotoxy(b, c);
		printf("����");
		gotoxy(b, c + 1);
		printf("    ��");
		gotoxy(b, c + 2);
		printf("����");
		gotoxy(b, c + 3);
		printf("��    ");
		gotoxy(b, c + 4);
		printf("����");
		break;
	case 3:
		gotoxy(b, c);
		printf("����");
		gotoxy(b, c + 1);
		printf("    ��");
		gotoxy(b, c + 2);
		printf("����");
		gotoxy(b, c + 3);
		printf("    ��");
		gotoxy(b, c + 4);
		printf("����");
		break;
	case 4:
		gotoxy(b, c);
		printf("��  ��");
		gotoxy(b, c + 1);
		printf("��  ��");
		gotoxy(b, c + 2);
		printf("����");
		gotoxy(b, c + 3);
		printf("    ��");
		gotoxy(b, c + 4);
		printf("    ��");
		break;
	case 5:
		gotoxy(b, c);
		printf("����");
		gotoxy(b, c + 1);
		printf("��    ");
		gotoxy(b, c + 2);
		printf("����");
		gotoxy(b, c + 3);
		printf("    ��");
		gotoxy(b, c + 4);
		printf("����");
		break;
	case 6:
		gotoxy(b, c);
		printf("����");
		gotoxy(b, c + 1);
		printf("��    ");
		gotoxy(b, c + 2);
		printf("����");
		gotoxy(b, c + 3);
		printf("��  ��");
		gotoxy(b, c + 4);
		printf("����");
		break;
	case 7:
		gotoxy(b, c);
		printf("����");
		gotoxy(b, c + 1);
		printf("��  ��");
		gotoxy(b, c + 2);
		printf("��  ��");
		gotoxy(b, c + 3);
		printf("    ��");
		gotoxy(b, c + 4);
		printf("    ��");
		break;
	case 8:
		gotoxy(b, c);
		printf("����");
		gotoxy(b, c + 1);
		printf("��  ��");
		gotoxy(b, c + 2);
		printf("����");
		gotoxy(b, c + 3);
		printf("��  ��");
		gotoxy(b, c + 4);
		printf("����");
		break;
	case 9:
		gotoxy(b, c);
		printf("����");
		gotoxy(b, c + 1);
		printf("��  ��");
		gotoxy(b, c + 2);
		printf("����");
		gotoxy(b, c + 3);
		printf("    ��");
		gotoxy(b, c + 4);
		printf("����");
		break;
	}
}
void display1() {
	gotoxy(116, 0);//25,0~9
	for (int i = 0; i < 25; i++) {
		gotoxy(91 + i, 0);
		printf("��");
		gotoxy(91 + i, 8);
		printf("��");
		gotoxy(91 + i, 10);
		printf("��");//������ ���
	}
	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 5; j++) {
			gotoxy(91 + j * 6, i);
			printf("��");
		}//������ ������ ���
	}
	int p = point;;
	for (int i = 0; i < 4; i++) {
		number(p, 93 + i * 6, 2);
	}//������ ����Ѵ�.
	gotoxy(93, 9);
	printf("PLAYER");
	gotoxy(99, 9);
	printf("COM1");
	gotoxy(105, 9);
	printf("COM2");
	gotoxy(111, 9);
	printf("COM3");//�������� �̸��� ����Ѵ�.

	person(56, 33, "PLAYER");
	person(71, 33, "COM1");
	person(86, 33, "COM2");
	person(101, 33, "COM3");//���� ����Ѵ�.
	for (int i = 0; i < 65; i++) {
		gotoxy(40, i);
		printf("��");
	}//���ڰ� ������ ĭ�� ������ ���� �׸���.
	gotoxy(0, 0);
}
void person(int x, int y, char* name) {
	gotoxy(x, y);
	printf("��");
	for (int j = 0; j < 16; j++) {
		for (int i = 0; i < 8; i++) {
			gotoxy(x + i, y + j);
			printf("��");
		}
	}
	for (int j = 0; j < 3; j++) {
		for (int i = 0; i < 3 - j; i++) {
			gotoxy(x + i, y + 7 + j);
			printf("  ");
			gotoxy(x + 7 - i, y + 7 + j);
			printf("  ");
		}
	}
	for (int i = 0; i < 4; i++) {
		gotoxy(x - 1, y + 12 + i);
		printf("��");
		gotoxy(x + 8, y + 12 + i);
		printf("��");
	}
	for (int i = 0; i < 6; i++) {
		gotoxy(x + 1 + i, y + 13);
		printf("  ");
	}
	gotoxy(x + 2, y + 13);
	printf("%s", name);
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			gotoxy(x + 1 + i, y + 2 + j);
			printf("  ");
		}
	}
	gotoxy(x + 2, y + 2);
	printf("��");
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			gotoxy(x + 5 + i, y + 2 + j);
			printf("  ");
		}
	}
	gotoxy(x + 5, y + 2);
	printf("��");
	gotoxy(100, 30);
}//����� ǥ���ϴ� ���� �׷��ݴϴ�.
void clear() {
	for (int i = 0; i < 65; i++) {
		for (int j = 0; j < 40; j++) {
			gotoxy(j, i);
			printf("  ");
		}
	}
	gotoxy(0, 0);
}//���ڰ� ������ ĭ�� �����ش�.
void person1(int x, int y, char* name) {
	person(x, y, name);
	for (int i = 0; i < 6; i++) {
		gotoxy(x - 2, y + 3 + i);
		printf("��");
	}
	gotoxy(x - 1, y + 9);
	printf("��");
	for (int i = 0; i < 6; i++) {
		gotoxy(x + 9, y + 3 + i);
		printf("��");
	}
	gotoxy(x + 8, y + 9);
	printf("��");
	Sleep(300);
	for (int i = 0; i < 6; i++) {
		gotoxy(x - 2, y + 3 + i);
		printf("  ");
	}
	gotoxy(x - 1, y + 9);
	printf("  ");
	for (int i = 0; i < 6; i++) {
		gotoxy(x + 9, y + 3 + i);
		printf("  ");
	}
	gotoxy(x + 8, y + 9);
	printf("  ");//���� ���� �׷ȴٰ� ������ ���ƿ´�.

}