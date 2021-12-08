#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <Windows.h>
#include <string.h>
#include <MMSystem.h>
#pragma comment(lib,"Winmm.lib")

struct tile {
	int time;//�Է��ؾ��ϴ� �ð�
	int ER;//ErrorRange
	int num;//��� hit�� ����
};

struct tile tilestr[10000]; //tile�� ������ ������ �迭

char musicRoute[100];// ������ ��θ� ������ ���ڿ�

void Gmap();// get map

int Gtypt();//get typing time

int main() {
	int a = 0;
	Gmap();
	if (Gtypt()) {
		printf("   88888888      88              888888888888      88888888      8888888888      88  \n");
		printf(" 88        88    88              88              88        88    88        88    88  \n");
		printf(" 88              88              88              88        88    88        88    88  \n");
		printf(" 88              88              888888888888    888888888888    8888888888      88  \n");
		printf(" 88              88              88              88        88    88        88    88  \n");
		printf(" 88        88    88              88              88        88    88        88        \n");
		printf("   88888888      888888888888    888888888888    88        88    88        88    88  \n");//���� �˸���

	}
	else {
		printf("     88        88   88888888888   88  88   \n");
		printf("    8888       88     88   88     88  88   \n");
		printf("   88  88      88     88   88     88  88   \n");
		printf("  88    88     88     88   88     88  88   \n");
		printf("  88    88     88     88   88     88  88   \n");
		printf("         88888888   88888888888   888888   \n");
		printf("               88                 88  88   \n");
		printf("         88888888                 88  88   \n");
		printf("         88                       88  88   \n");
		printf("         88888888                 88  88   \n");//���� �˸���
		printf("�ٽ��ϰڽ��ϱ�? �ٽ��Ϸ��� 1, �������� 1�̿��� �Է��� �ϼ���");//���� ���࿩�� ����
		scanf("%d", &a);
	}
	if (a == 1)
		main();//���� �����
	return 0;
}

void Gmap() {
	printf("�뷡�� ��θ� �Է��Ͻÿ�(��,���������� �ι� �������)\n");
	rewind(stdin);//���ۿ��� enter �����
	gets(musicRoute, stdin);//�뷡�� ��θ� �Է¹ޱ�
	int a = 0;
	int cl, ER, num;
	Sleep(100);
	system("cls");//100ms���� ��ٷȴٰ� �ܼ�â �ʱ�ȭ
	while (1) {
		printf("���� �Է��Ͻÿ�\n");
		printf("cl ER num\n");
		scanf("%d %d %d", &cl, &ER, &num);// ���� ���� �Է¹ޱ�
		(*(tilestr + a)).time = cl;
		(*(tilestr + a)).ER = ER;
		(*(tilestr + a)).num = num;//����ü �迭�� ����â���Ͽ� ����ü �迭�� ���� ���� �Է�
		a++;
		if (cl == 0 && ER == 0 && num == 0) {//�� �Է� ���� ����
			system("cls");
			break;
		}
		system("cls");//�ܼ�â �ʱ�ȭ
	}
}

int Gtypt() {
	int a = 0;//Ÿ�� ������ ���� ����ü �迭�� ������ ���ʸ� �����ϴ� ����
	int b = 0;//��ӵǴ� �ð� ����� ����
	int c = 0;//���۽ð� ����� ����
	printf("    33333333    \n");
	printf("  33        33  \n");
	printf("            33  \n");
	printf("    33333333    \n");
	printf("            33  \n");
	printf("  33        33  \n");
	printf("    33333333    \n");//3�Է�
	Sleep(1000);//1�ʴ��
	system("cls");//�ܼ�â �ʱ�ȭ
	printf("    22222222    \n");
	printf("  22        22  \n");
	printf("            22  \n");
	printf("        2222    \n");
	printf("    2222        \n");
	printf("  22            \n");
	printf("  222222222222  \n");//2�Է�
	Sleep(1000);//1�ʴ��
	system("cls");//�ܼ�â �ʱ�ȭ
	printf("       11       \n");
	printf("      111       \n");
	printf("     1111       \n");
	printf("    11 11       \n");
	printf("       11       \n");
	printf("       11       \n");
	printf("       11       \n");
	printf("    11111111    \n");//1�Է�
	Sleep(1000);//1�ʴ��
	system("cls");//�ܼ�â �ʱ�ȭ
	sndPlaySoundA(musicRoute, SND_ASYNC | SND_NODEFAULT);//�뷡 ���
	c = clock();//���۽ð� �Է�
	while (1) {
		b = clock();//����ð� �Է�
		if (b - c >= tilestr[a].time - tilestr[a].ER && b - c <= tilestr[a].time + tilestr[a].ER) {
			for (int i = 0; i < tilestr[a].num; i++)
				printf("hit");
			system("cls");
		}//�Է��ؾ��ϴ� �ð��� hit�� ����
		if (_kbhit()) {
			if (tilestr[a].time == 0 && tilestr[a].ER == 0) {
				return 1;// �����Ͽ��� �� ���� ��ȯ( ������ 1, ���д� 0)
			}
			_getch();//_kbhit()���ʱ�ȭ
			if (b - c > tilestr[a].time + tilestr[a].ER) {
				PlaySound(NULL, 0, 0);
				return 0;// �����Ͽ��� �� �뷡 �ߴ� �� ���� ��ȯ
			}
			else if (b - c >= tilestr[a].time - tilestr[a].ER)
				a++;// �������Ͻ� a�� ���� �÷� ���� �Է��� ���� �� �ֵ��� �ϱ�
		}
	}
}