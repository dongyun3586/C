#include <stdio.h>
#include <string.h>//printPot���� strlen �̿��ϱ� ����//
#include <stdlib.h>//_sleep �̿��ϱ� ����
#include <windows.h>//�ܼ�â ũ�� ���ϱ� ����

void start();
void printPoint();
void spring();
void grow();
void result();
void printPot(int which, char* name);
void printUserBox1(int* word);
void printUserBox2(char* words);

char name[10] = { 0 };
int point = 0, ans, num = 1;

int main() {
	system("mode con cols=52 lines=50"); //�ܼ�â ũ�� ���ϱ�
	start(); //Ű��� ����
	spring(); //�� Ʒ���
	grow(); //�ڶ��
	result(); //���(point)
	return 0;
}

void printPoint() {
	printf("                                        point:%d\n", point);
} //���� ����Ʈ ���

void printPot(int which, char* name) {
	int n = strlen(name);

	if (which == 0) {//�⺻ ȭ��
		printf("_____________\n");
		printf("|___________|\n");
		printf(" ��        /\n");
		printf("  |       |\n");
		printf(" _|_______|_\n");
		printf("'----' '----'\n");
		return 0;
	}

	else if (which == 1) {//�ʹݿ� void start���� ȭ�� �� �� ���
		printf("_____________ _____________\n");
		printf("|___________| |___________|\n");
		printf(" ��       ��   ��       ��\n");
		printf("  |       |     |       |\n");
		printf(" _|_______|_   _|_______|_\n");
		printf("'----' '----' '-----------'\n");
		return 0;
	}

	else if (which == 2) {//�̸��� �ִ� �⺻ ȭ��
		printf("_____________\n");
	}

	else if (which == 3) {//���ֱ� ȭ��
		printf("           . .       o\n");
		printf("      ����������-./'''''��_\n");
		printf("   ��  ��  ��   ��|�� �� �� |))\n");
		printf(" ��  ��   ��      |�� �� �� |��\n");
		printf("_____________\n");
	}

	else if (which == 4) {//���ѿ� �� X ���
		printf("		 +    -=+.  +\n");
		printf("		    +   | ��  ��\n");
		printf("		+ ��    |  |\n");
		printf("		  .  __/   /  +\n");
		printf("		   ��____,' + ��\n");
		printf("_____________   +       ��\n");
	}
	else if (which == 5) {//���ѿ� �� �ִ� ���
		printf("	       + + + \n");
		printf("	    +  .----. +\n");
		printf("	   + /       ��+\n");
		printf("	   + | ��==�� | +\n");
		printf("	    +�� _~~_ / +\n");
		printf("_____________ + + + +\n");
	}

	else if (which == 6) {//���� ȭ��
		printf("     (Y)\n");
		printf("______|______\n");
	}

	printf("|");//�̸� ���
	for (int i = (11 - n) / 2; i > 0; i--)
		printf("_");//_�� ���� ����ϰ�
	printf("%s", name);//�̸� ����ϰ�
	n = (11 - n) / 2;
	while (n + 1) {//������ _ ���
		printf("_");
		n--;
	}
	printf("|\n");	//ȭ�� �Ʒ��� ��� (which=0�Ǵ�1�� �����ϸ� �Ʒ����� �����Ƿ�)
	printf(" ��        /\n");
	printf("  |       |\n");
	printf(" _|_______|_\n");
	printf("'----' '----'\n");
}

void printUserBox1(int* word) {//��ȣ�� ���� �� ����ϴ� �Է� �ڽ�
	int s = 0, n = 51;
	printf(" __________________________________________________\n");
	printf("|");
	scanf("%d", &s);//��ȣ �Է¹ޱ�
	*word = s;//������ �̿��� ��ȯ
	while (n) {
		printf(" ");
		n--;
	}
	printf("|\n|__________________________________________________|");//�ڽ� �ݱ�
}

void printUserBox2(char* words) {//���ڿ��� �Է¹��� �� ����ϴ� �Է� �ڽ�
	printf(" __________________________________________________\n");
	printf("|");
	scanf("%s", words);
	int num = 51;
	while (num) {
		printf(" ");
		num--;
	}
	printf("|\n|__________________________________________________|");
}

void start() {
	printPoint();
	printf("ȯ���մϴ�!\n");
	printf("ȭ���� ����ּ���\n\n\n      1             2\n");//ȭ�� ����
	printPot(1, &name);
	printf("\n\n");
	printUserBox1(&ans);
	while (ans == 2) {
		printf("\n�������� ���� ȭ���� �Ĺ��� Ű��⿡ ���� �ʽ��ϴ�\n�ٽ� ����ּ���(-10p)\n\n");
		printUserBox1(&ans);
		num = 0;//�� �� Ʋ�� �� ������ ���� �ο� X,  �ѹ��� �¾ƾ߸� point ����
		point -= 10;//������ Ʋ���� ������ ���� ����
	}
	if (num = 0) {
		printf("���� ȭ���� �������");//����Ʈ ���� X
		_sleep(1500);//1.5�� ���
		system("cls");//ȭ�� �����
	}
	else {
		printf("���� ȭ���� �������(+15p)");//����Ʈ ����
		point += 15;
		_sleep(1500);
		system("cls");
	}
	point = point - 10 * num;//���� ����

	printPoint();//�Ĺ� �̸����̱�
	printf("�Ĺ����� �̸��� �ٿ��ּ���\n(���� ���� ���� 10�� �ѱ� 5��)\n\n\n");
	printPot(2, &name);
	printUserBox2(&name);
	printf("���� �̸��̿���");
	_sleep(1500);
	system("cls");

	printPoint();//Ű��� ����
	printf("� �����̵� ������ ��� Ű��ô�\n%s��(��) ����� ������ �ڶ� ���Դϴ�\n\n���� ���� Ʒ�����ô�(yes/no)\n\n\n", name);
	printPot(2, &name);
	char wouldYou[5];
	printUserBox2(&wouldYou);
	while (wouldYou[0] != 'y') {
		printf("%s��(��) ����� �����մϴ�\n�ٽ� �� �� �����غ����?(-5p)\n", name);
		point -= 5;
		printUserBox2(&wouldYou);
	}
	if (wouldYou[0] == 'y') {
		printf("�����սô�");
		_sleep(1500);
		system("cls");
	}
}

void spring() {
	printPoint();//���� �ɱ�
	printf("      ��\n\n\n\n");
	printPot(2, &name);
	_sleep(300);
	system("cls");
	printPoint();
	printf("\n      ��\n\n\n");
	printPot(2, &name);
	_sleep(300);
	system("cls");
	printPoint();
	printf("\n\n      ��\n\n");
	printPot(2, &name);
	_sleep(300);
	system("cls");
	printPoint();
	printf("\n\n\n      ��\n");
	printPot(2, &name);
	_sleep(300);
	system("cls");

	num = 1;//num �ʱ�ȭ
	printPoint();//1. ���� �󸶳� �� ���ΰ�?
	printf("������ �ɾ����ϴ�\n���� �󸶳� ��� �ϳ���?\n\n1. ���� ǥ���� ����~�ϰ� �л����ֱ�\n2. ���� ���� �ȳ����ϱ�, ���� �ֺ��� ����������\n3. ���� ���̴� �� Ȯ���� �� ������ŭ ���\n\n\n");
	printPot(2, &name);
	printUserBox1(&ans);
	while (ans != 3) {
		num = 0;
		if (ans == 1) {
			printf("���� �������� ���� �����ϴ�(-10p)\n");
			point = point - 10;
			printUserBox1(&ans);
		}
		else if (ans == 2) {
			printf("������ ȫ���� ��κ��� ��� ���ǵ˴ϴ�(-10p)\n");
			point = point - 10;
			printUserBox1(&ans);
		}
	}
	if (num) {
		point += 20;
		printf("������ ����� ���¸� �����մϴ�(+20p)");
	}
	else printf("������ ����� ���¸� �����մϴ�");
	_sleep(1500);
	system("cls");

	num = 1;//2. ���� �󸶳� ���� �� ���ΰ�?
	printPoint();
	printf("���� �󸶳� ���� �� �ǰ���?\n\n1. �Ϸ� �� �� �̻�\n2. ��Ʋ�� �� ��\n3. �����Ͽ� �� ��\n\n\n");
	printPot(2, &name);
	printUserBox1(&ans);
	while (ans != 1) {
		num = 0;
		if (ans == 2) {
			printf("������ �������� ���� ���� ���մϴ�(-5p)\n");
			point = point - 5;
			printUserBox1(&ans);
		}
		else if (ans == 3) {
			printf("�ٽ� �� �� �����غ�����(-10p)\n");
			point = point - 10;
			printUserBox1(&ans);
		}
	}
	if (num) {
		point = point + 10;
		printf("���� ������ �ʰ� �մϴ�(+10p)");
	}
	else printf("���� ������ �ʰ� �մϴ�");
	_sleep(1500);
	system("cls");
	printPot(3, &name);//���ֱ� ȭ�� ���
	_sleep(1500);
	system("cls");

	printPoint();	//3. �ظ� �󸶳� �ؾ��� ���ΰ�?
	printf("�ظ� �󸶳� �� �� �ְ� �Ұǰ���?\n\n1. ����\n2. �ݳ���\n\n\n");
	printPot(2, &name);
	printUserBox1(&ans);
	printf("��� �� �� �����Դϴ�\n� ������ ���� �޾ƾ� ���� �� Ʒ��� � �͵��� �� �ݴ��Դϴ�(+5p)\n");
	point += 5;
	_sleep(3000);
	system("cls");
	if (ans == 1)
		printPot(4, &name);//�� ȭ�� ���
	else printPot(5, &name);//�� ȭ�� ���
	_sleep(1500);
	system("cls");

	num = 1;
	printPoint();//4. ��ǳ�� ��� �� ���ΰ�?
	printf("��ǳ�� ��� �ұ��?\n\n1. ��ǳ�� �� ���� �ʰ� �Ѵ�\n2. ��ǳ�� �ǵ��� �Ѵ�\n\n\n");
	printPot(2, &name);
	printUserBox1(&ans);
	while (ans == 2) {
		printf("�� ǥ���� �����ϰ� �����Ǿ�� �ϴµ� ��ǳ�� �� �Ǹ� ���������� �����ϴ�(-5p)\n");
		point -= 5;
		num = 0;
		printUserBox1(&ans);
	}
	if (num) {
		point += 10;
		printf("���� ǥ���� Ÿ���̳� ������ �����ֱ⵵ �մϴ�(+10p)");
	}
	else printf("���� ǥ���� Ÿ���̳� ������ �����ֱ⵵ �մϴ�");
	_sleep(2000);
	system("cls");

	char hi[100] = { 0 };//�Ĺ����� �λ��ϱ�
	printPoint();
	printf("���� ��� �غ� �������ϴ�\n%s��(��) ��ٷ��ݽô�\n\n\n", name);
	printPot(2, &name);
	_sleep(2000);
	system("cls");
	printPoint();
	printf("\n      ...LATER...\n\n\n");
	printPot(2, &name);
	_sleep(3000);
	system("cls");
	printPoint();
	printf("%s��(��) ������ϴ�!\n���׸� �Ͽ��� ©���� �λ縦 �ǳ׺��ô�\n\n\n", name);
	printPot(6, &name);
	printUserBox2(&hi);
	_sleep(2000);
	system("cls");
}

void grow() {
	num = 1;//���� ȭ�� ��� ���ϱ�
	printPoint();
	printf("%s��(��) ��� �ѱ��?\n\n1. ���籤���� �����ش� ��\n2. �޺��� �� ��� ��ǳ�� ���� ��\n3. ���ϰ� �״��� ��\n\n\n", name);
	printPot(6, &name);
	printUserBox1(&ans);
	while (ans != 2) {
		num = 0;
		if (ans == 1) printf("���� Ż �� �ֽ��ϴ�(-5p)\n");
		else if (ans == 3) printf("�����̰� �� �� �ְ� ���ռ��ϱ� ���� �ʽ��ϴ�(-5p)\n");
		point -= 5;
		printUserBox1(&ans);
	}
	if (num) {
		printf("�ٻ��� ����Դϴ�(+15p)");
		point += 15;
	}
	else printf("�ٻ��� ����Դϴ�");
	_sleep(2000);
	system("cls");

	num = 1;//���� ����
	printPoint();
	printf("%s���� ������ ������ϴ�\n� ��ġ�� ���Ұǰ���?\n\n1. �׳� �д�\n2. ��ǳ�⸦ Ʋ���ش�\n3. ���� ģ��\n4. ���� ����ش�\n\n\n", name);
	printPot(6, &name);
	printUserBox1(&ans);
	while (ans < 3) {
		num = 0;
		if (ans == 1) {
			printf("��å���� �ൿ�� %s��(��) ������ �մϴ�(-15p)\n", name);
			point -= 15;
		}
		else {
			printf("�ٽ� �����غ��°� ���ڽ��ϴ�(-10p)\n");
			point -= 10;
		}
		printUserBox1(&ans);
	}
	if (num) {
		if (ans == 3) printf("���ϰ� Ȯ���� ����� �����Ͽ����ϴ�(+10p)");
		else printf("����� ������ %s��(��) �����մϴ�(+10p)", name);
		point += 10;
	}
	else {
		if (ans == 3) printf("���ϰ� Ȯ���� ����� �����Ͽ����ϴ�");
		else printf("����� ������ %s��(��) �����մϴ�", name);
	}
	_sleep(2000);
	system("cls");
}

void result() {
	printPoint();
	printf("\n\n\n�ð��� �帣��...\n\n\n");
	printPot(6, &name);
	_sleep(1500);
	system("cls");
	printPoint();
	printf("\n\n\n%s��(��) ������, �׸��� ������ �ڶ����ϴ�...\n\n\n", name);
	printPot(6, &name);
	_sleep(2000);
	system("cls");

	while (1) {//�ڶ�� ��� ���
		printPoint();
		printf("\n\n\n\n\n\n\n\n\n\n");
		printf("       /\n");
		printf("     ��|\n");
		printf(" _____/|_____\n");
		printPot(10, &name);
		_sleep(500);
		system("cls");

		printPoint();
		printf("\n\n\n\n\n\n\n\n");
		printf("       /��\n");
		printf("       |\n");
		printf("       /\n");
		printf("    ��||\n");
		printf(" _____/|_____\n");
		printPot(10, &name);
		_sleep(500);
		system("cls");

		printPoint();
		printf("\n\n\n\n\n\n\n\n");
		printf("       /��\n");
		printf("       |_��\n");
		printf("      |/\n");
		printf("    ��||\n");
		printf(" ____/_|_____\n");
		printPot(10, &name);
		_sleep(500);
		system("cls");

		printPoint();
		printf("\n\n\n\n\n\n\n");
		printf("      ��/\n");
		printf("       /��\n");
		printf("       ||_��\n");
		printf("      |/\n");
		printf("    ��||\n");
		printf(" ____/_|_____\n");
		printPot(10, &name);
		_sleep(500);
		system("cls");

		printPoint();
		printf("\n\n\n\n\n\n");
		printf("       ��/\n");
		printf("        /��\n");
		printf("       //\n");
		printf("       ||_/��\n");
		printf("    ��|/\n");
		printf("      ||\n");
		printf(" ____/_|_____\n");
		printPot(10, &name);
		_sleep(500);
		system("cls");

		printPoint();
		printf("\n\n\n\n\n\n");
		printf("        ��/*\n");
		printf("        /|\n");
		printf("      *//  _\n");
		printf("    �� ||_/*\n");
		printf("    ��|/\n");
		printf("      ||\n");
		printf(" ____/_|_____\n");
		printPot(10, &name);
		_sleep(500);
		system("cls");

		printPoint();//������ 20�� �̸��� �� ����
		if (point < 20)
			printf("������ %d��\n\n%s��(��) ���� �ּ��մϴ�\n\n\n", point, &name);
		else printf("\n\n\n\n\n");
		printf("           _/\n");
		printf("      **��/**\n");
		printf("        /|\n");
		printf("      *//  _*\n");
		printf("   *�� ||_/*\n");
		printf("     *|/\n");
		printf("      ||\n");
		printf(" ____/_|_____\n");
		printPot(10, &name);
		_sleep(500);
		if (point < 20) {
			_sleep(5000);
			break;
		}
		system("cls");

		printPoint();//������ 40�� �̸� 20�� �̻��� �� ����
		if (point < 40)
			printf("������ %d��\n\n%s��(��) ������ �� �ڶ��־����ϴ�\n\n\n", point, &name);
		else printf("\n\n\n\n");
		printf("            *\n");
		printf("           _|*\n");
		printf("      **��/**\n");
		printf("       */|\n");
		printf("  ��   //  __/*\n");
		printf("  **�� ||_/**\n");
		printf("     *|/\n");
		printf("      ||\n");
		printf(" ____/_|_____\n");
		printPot(10, &name);
		_sleep(500);
		if (point < 40) {
			_sleep(5000);
			break;
		}
		system("cls");

		printPoint();//������ 60�� �̸� 40�� �̻��� �� ����
		if (point < 60)
			printf("������ %d��\n\n%s��(��) �ǰ��� �Ĺ��� �ڶ����ϴ�\n", point, &name);
		else printf("\n\n\n\n");
		printf("            *_**\n");
		printf("      *_*  _|\n");
		printf("       *��/**\n");
		printf("**      /|*\n");
		printf(" *��  *// *__*\n");
		printf("   *�� ||_/***\n");
		printf("      |/\n");
		printf("      ||\n");
		printf(" ____/_|_____\n");
		printPot(10, &name);
		_sleep(500);
		if (point < 60) {
			_sleep(5000);
			break;
		}
		system("cls");

		printPoint();//������ 80�� �̸� 60�� �̻��� �� ����
		if (point < 80)
			printf("������ %d��\n\n%s��(��) ������ �ڶ󳵽��ϴ�\n", point, &name);
		else printf("\n\n\n");
		printf("             *\n");
		printf("    *       */**\n");
		printf("    *��_*  _|\n");
		printf(" * *  **��/**\n");
		printf("**|     /|   ***\n");
		printf("  ��  *//  __/*\n");
		printf("   *�� ||_/*\n");
		printf("     *|/\n");
		printf("      ||\n");
		printf(" ____/_|_____\n");
		printPot(10, &name);
		_sleep(500);
		if (point < 80) {
			_sleep(5000);
			break;
		}
		system("cls");

		printPoint();//������ 80�� �̻��� �� ����
		if (point >= 80)
			printf("point�� %d��\n\n%s��(��) �Ƹ��ٿ� �Ĺ��� �Ǿ����ϴ�\n", point, &name);
		else printf("\n\n\n");
		printf("             **\n");
		printf("    ***     */**\n");
		printf("    *��_* *_|*\n");
		printf(" ***  **��/**\n");
		printf("**|*   */|   ***\n");
		printf("* ��  *//  __/*\n");
		printf("   *�� ||_/**\n");
		printf("     *|/\n");
		printf("      ||\n");
		printf(" ____/_|_____\n");
		printPot(10, &name);
		_sleep(5000);
		system("cls");
		break;
	}
	system("cls");
	printf("%s�� �ۺ��λ縦 �մϴ�...\n\n", name);//������
	_sleep(2000);
	printf("%s�� �ڽŰ� ���� �ð��� ��ſ��⸦ ���ϴ�\n\n", name);
	_sleep(3000);
	system("cls");
	printf("\n\n	The End");
	_sleep(2000);
}