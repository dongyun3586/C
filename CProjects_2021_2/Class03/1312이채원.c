#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DELAY 30000

#define true 1

void GotoXY(int x, int y)
{
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}/*���ͳݿ��� �ۿ� �Լ��Դϴ�. (x, y)�� ��� ��ǥ�� �̵������ִ� �Լ��Դϴ�. */


int main__() {
	srand(time(NULL));//��Ʈ������ ��ǥ�� �������� �������ֱ� ���ؼ� ���� ����
	time_t new_time = 0, old_time = 0; // �ð��� ���ѽð��� �Ѿ�� �Ǹ� �����ֱ� ���� ���� ����

	int money = 0;	// ���� �����
	int level = 0;	// ���� ����
	char flag;		// ���� �����ϱ�
	GotoXY(85, 20);
	printf("  ��Ʈ���� ô���ϱ�\n                                                                                  Press X to start the game:  ");
	scanf("%c", &flag);

	if (flag == 'X') {
		system("cls");
	}
	else {
		return 0;
	}

	char notflag;
	/*������ʹ� ������ ���丮�� ���� printf�� �ݺ�.*/
	char yourname[10];
	printf("����� �̸���? �̸��� �Է��ϼ���.");
	scanf("%s", &yourname);
	system("cls");


	printf("���� : %s! �� ��� �þ�? ���� �츮���󿡼� �ܷ����� ���� ��ģ�ٴµ�...\n", yourname);
	Sleep(1000);
	printf("���� : ���, ������ ��Ʈ���ƴ� ������ ���� �ش�!\n");
	Sleep(1000);
	printf("���� : �� ���� ���� �� �����ϱ� �ѵ�... \n");
	Sleep(1000);
	printf("���� : %s �װ� �� �� ������ٷ�? �� �����̸� �� ������ �ؾ���.\n", yourname);
	Sleep(1000);
	system("cls");

	printf("ū�ϳ���! ȯ���� �����̵� �����ϴ� §���� ������ ��Ʈ���� ô���� �䱸�ߴ�!\n");
	Sleep(1000);
	printf("����� �ϳ��ۿ� ����. ��Ʈ���Ƹ� ô������!\nô���� ������ ���̵��� �Է��ϼ���. (1~4)");
	getchar();
	scanf("%c", &notflag);


	if (notflag == '1') { //���̵� 1
		level = 1;
		system("cls");
	}
	else if (notflag == '2') {//���̵� 2
		level = 2;
		system("cls");
	}
	else if (notflag == '3') {//���̵� 3
		level = 3;
		system("cls");
	}
	else if (notflag == '4') {//���̵� 4
		level = 4;
		system("cls");
	}
	else {
		return 0;
	}
	/*����� ���̵��� ���� ��Ʈ���ư� ���� ������ ���̸� �ǹ�.
	4�� ���� ���� �����̸� 1�� ���� ���� ����.*/


	/* ������ ��Ʈ���� ��ġ ���� �� ��ġ�� ������ ����� �߰��ϱ�*/
	int x = 0, y = 0;
	old_time = clock();
	char Hey = 0;
	int* ddx[15], ddy[15];
	for (int i = 0; i < 15; i++) {
		*(ddx + i) = rand() % 40 * level;
		*(ddy + i) = rand() % 10 * level;

		GotoXY(ddx[i], ddy[i]);
		printf("d"); //��Ʈ���� ��ġ ǥ��

	}
	while (true) {
		new_time = clock();    // ���� �ð� 
		GotoXY(0, 1);
		printf("%2d", 30 - (new_time - old_time) / 1000);
		if (difftime(new_time, old_time) > DELAY) {    // �ð� �ʰ� �˻�; �ð��� 30�ʸ� ������ �ڵ����� ���� �ߴ�
			system("cls");
			printf("������ %d������ ���� �ް�� �ູ���մϴ�!", money);
			Sleep(3000); // �ٷ� �����ϰ� �Ǹ� �������� ġ�� Ÿ�ڷ� ���� ������ Ȯ�ε� �� �ϰ� �ܼ�â�� ������ �һ�� �߻�
			return 0; // ���� ����
		}


		GotoXY(x, y);			// ó�� x�� y�� ���� 0�̱� ������ ���� ����
		printf("0");			// �츮�� ��Ʈ���Ƹ� ���� Ŀ���� ���
		if (kbhit()) {			// Ű���尡 �Է��� �Ǹ�?
			GotoXY(x, y);		// ���� �ִ� ���� ��ǥ���� 
			printf("  ");		// ������ ��µ� ��
			Hey = getch();		// �Էµ� Ű������ ���� Hey��� ������ �����ϰ� �Ʒ��� switch case������ 
			switch (Hey) {		// Ű������ ���� ���� ��Ȳ�� ������
			case 'w':
				if (y == 0) {	// w�� �Է��� �Ǹ� ���� �� ĭ�� �̵�, ������ ���� y��ǥ�� 0�̴� ���¿��� 
					break;		// �� �̻� ���� ���� ���ϱ� ������ ������ ����
				}				// �׷��� ������ y�� 0�� ���� 0�� �ƴ� ���� ������ �ڵ� ¥�ֱ�
				else {
					y--;
					break;
				}
			case 'a':			// �������� �� ĭ�� �̵��ϴ� a�� ��������.
				if (x == 0) {
					break;
				}
				else {
					x--;
					break;
				}
			case 's':			// ��ǥ�� ���� ���ҽ����ִ� �� �ƴ� s�� d�� �ƹ� ��� ����.
				y++;
				break;
			case 'd':
				x++;
				break;
			case 'p':			// �������� ������ �ߴ��ϰ� �ʹٸ� p�� ������. ���� ������ �Բ� ������ �ߴܵ�.
				system("cls");
				printf("������ %d������ ���� �ް�� �ູ���մϴ�!", money);
				Sleep(3000); // ���������� �ٷ� ������ ���� ����
				return 0;

			}
			for (int i = 0; i < 15; i++) {
				if (x == ddx[i] && y == ddy[i]) {	// ���� ���� ��ġ�� ��Ʈ���� ��ġ�� ������ �ÿ���? ->
					GotoXY(ddx[i], ddy[i]);			// ��Ʈ���ư� ǥ�õǴ� ��ġ�� ����
					printf("  ");					// ������ ����� ��Ʈ���Ƹ� �����ְ�
					ddx[i] = 200;					// ��Ʈ������ ��ġ�� ������ ������ �ö󰡱� ������ �һ�縦 �����ֱ� ����
					ddy[i] = 200;					// Ŀ���� ���� �� ���� ���� ������ ��ǥ�� �̵�������
					money += 3;						// �׸��� ����� 30000��!
					GotoXY(0, 0);					// ���� �޾����� ǥ������
					printf("%d", money);
				}
			}
			Sleep(1);			// sleep ���� �صθ� �����̴� ������ ������ ���� �Ҿ��� ���������� �� �ð� ������ ��
		}


	}


	return 0;
}
