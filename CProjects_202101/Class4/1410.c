#include<stdio.h>
#include<stdlib.h> // => �̱⿡���� Ȯ���� �ο��ϱ� ���� �����. rand()�� 1���� 100������ ���� �������� ������ ����, ���� ������ ������ �װ����� Ȯ���� �����Ѵ�. 
#include<time.h>
#include<windows.h> // ����Ʈ �ο� �� UI ������ ���ؼ� �����

int gamble(int stat, int money, int jujak);
int nowstat(int stat, int money, int jujak);
int blackcow(int stat, int money, int jujak);
void print_legend(); // ������ ���� ������ �� ��µǴ� ����Ʈ
void print_wow(); // 50¥�� ������ ���� ��� ��µǴ� ����Ʈ

int main() {
	int a, stat = 50, money = 0, jujak = 0;
	srand(time(NULL));
	printf("ȯ���մϴ�!\n�� ������ �̱�� �������� ������ �ø��� �����Դϴ�!\n�⺻ ������ 50���� �־����ϴ�. \n\n�̱�: 1\n����: 2\n");
	scanf("%d", &a); // �� ���� �����ϴ� �ý���
	if (a == 1) {
		gamble(stat, money, jujak);
	}
	else if (a == 2) {
		blackcow(stat, money, jujak);
	}
	else printf("ġ����......���� �߻�....");//���� �� �̽��Ϳ�����. 1�� 2�� ������ �ٸ� ���� �Է� �� �ٷ� ���α׷��� �����.
	return 0;
}

int nowstat(int stat, int money, int jujak) {//������ �����ִ� �ý����̴�.
	int gamma;
	system("cls");//UI������ �ٽ� ���. 
	printf("���� ������ %d�Դϴ�. \n������ �̾ƺ���! \n\n", stat);
	printf("�̱�: 1\n����: 2\n ");
	scanf("%d", &gamma); // �� ���� �����ϴ� �ý���
	if (gamma == 1) {
		gamble(stat, money, jujak);
	}
	else if (gamma == 2) {
		blackcow(stat, money, jujak);
	}
}

int gamble(int stat, int money, int jujak) {//���������� �̱⸦ �Ͽ� ������ �ø��� �ý����̴�.
	int c;
	system("cls");
	printf("�̰��� �̱⸦ �ϴ� ���Դϴ�!. \n\n���� ���� Ȯ��: 1\n�̱�: 2 \n");
	system("color 5B");
	scanf("%d", &c); // �� �� ����
	if (c == 1) {
		nowstat(stat, money, jujak);
	}
	else if (c == 2);
	int gatcha, d;

	printf("�� �� �����ðڽ��ϱ�?\n10+1: 1 �Է�\n1: 2 �Է�\n"); // ��í�� ���� Ƚ���� ���ϴ� �ý���
	scanf("%d", &gatcha);
	if (gatcha == 1) gatcha = 11;
	else if (gatcha == 2)gatcha = 1;
	switch (jujak) {
	case 0:
		for (int i = 0; i < gatcha; i++) { // ������ �ƴ� �̱� �Ǵ� Ȯ�� �� �̱�. ������ ������ 50 10 1�� �� 3����, Ȯ���� 5 25 70. 50 ���� �� �ؾ��� Ȯ���� �����. 
			int upstat, per = rand() % 100 + 1;
			if (per >= 1 && per < 6) {
				upstat = 50;
				system("color 5B");
				for (int i = 1; i < 10; i++) {
					printf("*"); Sleep(10); system("color 2D"); // 50�� ���� ���� ����Ʈ
					printf("/"); Sleep(10); system("color 4E");
					printf("$"); Sleep(10); system("color 1C");
					printf("#"); Sleep(10); system("color 69");
				}
				print_wow();
				printf("+50\n");
				Sleep(100);
				stat = stat + upstat;
				jujak = 1;
			}
			else if (per >= 6 && per < 31) {
				upstat = 10;
				system("color 5C");
				printf("+10\n");
				Sleep(100);
				stat = stat + upstat;
			}
			else if (per >= 31 && per <= 100) {
				upstat = 1;
				system("color 2E");
				printf("+1\n");
				Sleep(100);
				stat = stat + upstat;
			}
		}
		break;
	case 1:
		for (int i = 0; i < gatcha; i++) { // ������ �� �ؾ��� Ȯ�� �̱�. ���� ������ ���� ����, Ȯ���� 1 5 94
			int upstat, per = rand() % 100 + 1;
			if (per == 1) {
				upstat = 50;
				system("color 5B");
				for (int i = 1; i < 10; i++) {
					printf("*"); Sleep(10); system("color 2D");
					printf("/"); Sleep(10); system("color 4E");
					printf("$"); Sleep(10); system("color 1C");
					printf("#"); Sleep(10); system("color 69");
				}
				print_wow();
				printf("+50\n");
				Sleep(100);
				stat = stat + upstat;
			}
			else if (per > 1 && per <= 6) {
				upstat = 10;
				system("color 5C");
				printf("+10\n");
				Sleep(100);
				stat = stat + upstat;
			}
			else if (per > 6 && per <= 100) {
				upstat = 1;
				system("color 2E");
				printf("+1\n");
				Sleep(100);
				stat = stat + upstat;
			}
		}
		break;
	case 2:
		for (int i = 0; i < gatcha; i++) { // �� Ȯ�� �� �̱�. ���� ������ ���� ����, Ȯ���� 19 40 41. ��, ����� 50�� ��÷�� �� �Ϲ� Ȯ���� ����.
			int upstat, per = rand() % 100 + 1;
			if (per >= 1 && per < 20) {
				upstat = 50;
				system("color 5B");
				for (int i = 1; i < 10; i++) {
					printf("*"); Sleep(5); system("color 2D");
					printf("/"); Sleep(5); system("color 4E");
					printf("$"); Sleep(5); system("color 1C");
					printf("#"); Sleep(5); system("color 69");
				}
				print_wow();
				printf("+50\n");
				Sleep(100);
				stat = stat + upstat;
				jujak = 0;
			}
			else if (per >= 20 && per < 60) {
				upstat = 10;
				system("color 5C");
				printf("+10\n");
				Sleep(100);
				stat = stat + upstat;
			}
			else if (per >= 60 && per <= 100) {
				upstat = 1;
				system("color 2E");
				printf("+1\n");
				Sleep(100);
				stat = stat + upstat;
			}
		}
		break;
	}
	if (stat >= 10000) {
		system("color 92");
		printf("�����մϴ�! ���� ������ �� �� �ְڱ���! \n�� %d���� ���̳׿�! \n�׷� �ȳ�!\n", money);// ������ 10,000 �̻� �޼� �� ������ ����, �� ���� �ݾ׵� ���� ������.
		exit(0);
	}
	printf("���� ������ %d�Դϴ�!\n\n�ٽ� �̱�: 1\n����: 2\n", stat);
	scanf("%d", &d); // �� �� ����
	if (d == 1) {
		gamble(stat, money, jujak);
	}
	else if (d == 2) {
		blackcow(stat, money, jujak);
	}
}

int blackcow(int stat, int money, int jujak) {//������ �Ͽ� Ȯ���� ��½�Ű��, �߰� ������ ���� �� �ִ� ��Ű���� �����ϴ� �ý����̴�.
	int pack;
	system("cls");
	printf("�� ���� �����Դϴ�!\n��Ű�� ��ǰ�� �����ϼ���!\n\n1. �˶� �̱���(Ȯ�� �� �̱�): 5,500 \n2. ��� �̱���(�� Ȯ�� �� �̱�): 11,000 \n3. ���� ���� ��(���� +300, �� Ȯ�� �� �̱�): 25,000 \n4. �������� �� Vol 1(���� +1,500, �� Ȯ�� �� �̱�): 110,000\n5. �������� �� Vol 2(���� +5,000, �� Ȯ�� �� �̱�): 450,000\n6. �� �� Ŭ���� ��Ű��(���� Ŭ����): 1,100,000\n7. ���� �� ��\n");
	scanf("%d", &pack); // ��Ű�� ��ǰ�� ������ �� �ֵ��� �ϴ� �ý���.
	system("color 6D");
	switch (pack) {
	case 1:
		money = money + 5500;
		jujak = 0;
		printf("�����մϴ�!");
		Sleep(3000);
		break;
	case 2:
		money = money + 11000;
		jujak = 2;
		printf("�����մϴ�!");
		Sleep(3000);
		break;
	case 3:
		money = money + 25000;
		jujak = 2;
		stat = stat + 300;
		printf("�����մϴ�!");
		Sleep(3000);
		break;
	case 4:
		print_legend();
		money = money + 110000;
		jujak = 2;
		stat = stat + 1500;
		break;
	case 5:
		print_legend();
		money = money + 450000;
		jujak = 2;
		stat = stat + 5000;
		break;
	case 6:
		money = money + 1100000;
		printf("�����մϴ�! ���� ������ �� �� �ְڱ���! \n�� %d���� ���̳׿�! \n�׷� �ȳ�!\n", money);
		Sleep(1000);
		exit(0);

	case 7:
		break;
	}
	gamble(stat, money, jujak);
}
void print_wow() // �̱⿡�� ���� Ȯ���� ��÷�� �� ���� ���� ����Ʈ
{
	system("cls");
	printf("                           \n");
	printf("                           \n");
	printf("                           \n");
	printf("            *              \n");
	printf("                           \n");
	printf("                           \n");
	printf("                           \n");
	Sleep(100); system("cls");
	system("color 59");
	system("cls");
	printf("                           \n");
	printf("                           \n");
	printf("            *              \n");
	printf("           * *             \n");
	printf("            *              \n");
	printf("                           \n");
	printf("                           \n");
	Sleep(100); system("cls");
	system("color 4E");
	system("cls");
	printf("                           \n");
	printf("            *              \n");
	printf("           * *             \n");
	printf("          *   *            \n");
	printf("           * *             \n");
	printf("            *              \n");
	printf("                           \n");
	Sleep(100); system("cls");
	system("color 6C");
	system("cls");
	printf("            *              \n");
	printf("           * *             \n");
	printf("          *   *            \n");
	printf("         *     *           \n");
	printf("          *   *            \n");
	printf("           * *             \n");
	printf("            *              \n");
	Sleep(200); system("cls");
	printf("            W              \n");
	printf("           W O             \n");
	printf("          W O W            \n");
	printf("         W O W O           \n");
	printf("          W O W            \n");
	printf("           W O             \n");
	printf("            W              \n");
	Sleep(500); system("cls");
	system("color 3C");
	printf("            N              \n");
	printf("           N I             \n");
	printf("          N I C            \n");
	printf("         N I C E           \n");
	printf("          N I C            \n");
	printf("           N I             \n");
	printf("            N              \n");
	Sleep(500); system("cls");
	system("color A4");
	printf("         55555   000000    \n");
	printf("  +      5       0    0    \n");
	printf("  +      5       0    0    \n");
	printf("+++++    55555   0    0    \n");
	printf("  +          5   0    0    \n");
	printf("  +          5   0    0    \n");
	printf("         55555   000000    \n");
	Sleep(700); system("cls");
	system("color 68");
	printf("\n");

}
void print_legend() // ������ ���� ������ �� ������ ����Ʈ
{
	system("cls");
	printf("                           \n");
	printf("                           \n");
	printf("                           \n");
	printf("            ��             \n");
	printf("                           \n");
	printf("                           \n");
	printf("                           \n");
	Sleep(600); system("cls");
	system("color 18");
	system("cls");
	printf("                           \n");
	printf("                           \n");
	printf("          ����           \n");
	printf("          ��  ��           \n");
	printf("          ����           \n");
	printf("                           \n");
	printf("                           \n");
	Sleep(100); system("cls");
	system("color B4");
	system("cls");
	printf("                           \n");
	printf("        ������         \n");
	printf("        ��      ��         \n");
	printf("        ��      ��         \n");
	printf("        ��      ��         \n");
	printf("        ������         \n");
	printf("                           \n");
	Sleep(100); system("cls");
	system("color 54");
	system("cls");
	printf("      ��������       \n");
	printf("      ��          ��       \n");
	printf("      ��          ��       \n");
	printf("      ��          ��       \n");
	printf("      ��          ��       \n");
	printf("      ��          ��       \n");
	printf("      ��������       \n");
	Sleep(100); system("cls");
	system("color 2D");
	system("cls");
	printf("                           \n");
	printf("                           \n");
	printf("                           \n");
	printf("            ��             \n");
	printf("                           \n");
	printf("                           \n");
	printf("                           \n");
	Sleep(700); system("cls");
	system("color E6");
	system("cls");
	printf("            *              \n");
	printf("          ** **            \n");
	printf("        **     **          \n");
	printf("       *         *         \n");
	printf("        **     **          \n");
	printf("          ** **            \n");
	printf("            *              \n");
	Sleep(100); system("cls");
	system("color 59");
	system("cls");
	printf("                           \n");
	printf("       ������������        \n");
	printf("         ��������          \n");
	printf("           ����            \n");
	printf("         ��������          \n");
	printf("       ������������        \n");
	printf("                           \n");
	Sleep(200); system("cls");
	system("color D1");
	system("cls");
	printf("                           \n");
	printf("           ����            \n");
	printf("         ��������          \n");
	printf("       ������������        \n");
	printf("         ��������          \n");
	printf("           ����            \n");
	printf("                           \n");
	Sleep(200); system("cls");
	system("color 6C");
	system("cls");
	printf("-----------BOX-------------\n");
	printf("|         LEGEND          |\n");
	printf("|     LEGEND LEGEND       |\n");
	printf("|  LEGEND LEGEND LEGEND   |\n");
	printf("|     LEGEND LEGEND       |\n");
	printf("|         LEGEND          |\n");
	printf("-----------BOX-------------\n");
	Sleep(1500); system("cls");
	system("color A4");
}