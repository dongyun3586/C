#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>
#define M 16                   //�ִ� 16�� ���� ����
#define MAX 25                 //25�� ���� ����
typedef struct {
	int table;
	char person[10];
	int phoneNum;
	int time;
	int member;
	int price;                 //���ı��� �Է��Ϸ��� �޴��� �ʿ��ϹǷ� �ű������ �� ��
	int usage;                 //���� ���̺� �ɾƼ� �԰� �ִٸ� 1, �̹� �������� 2, ���� �� ������ 0
}info;

void printStruct(info* n, int a);

int main() {
	info Group[MAX];
	int n;
	int count = 0;
	while (1) {


		printf("���� �Է�:1  �ֹ� �Է�:2  ���� ��Ȳ:3  ����Ȯ��:4  ����:5  ���Ӱ� �ڸ���ġ:6  ������� �湮�� �մ� ���:7  ���α׷� ����:8\n");

		scanf("%d", &n);
		switch (n) {
		case(1): {   //���� �Է�   ���� ��ȭ�ؼ� ����������
			if (count < MAX)
			{
				printf("�̸��� �Է��ϼ���:");
				scanf("%s", Group[count].person);

				do {
					printf("���̺��� �Է��ϼ���:");
					scanf("%d", &Group[count].table);
				} while (Group[count].table > M);
				printf("�ο� ���� �Է��ϼ���:");
				scanf("%d", &Group[count].member);
				printf("010 ���� ��ȭ��ȣ�� �Է��ϼ���:");
				scanf("%d", &Group[count].phoneNum);
				while (Group[count].phoneNum >= (int)pow(10, 8) || Group[count].phoneNum < (int)pow(10, 7)) {
					printf("010 ���� ��ȭ��ȣ�� �Է��ϼ���:");
					scanf("%d", &Group[count].phoneNum);
				}
				printf("�ð��� �Է��ϼ���(���� 1�� 39�� = 1339,���� 0�� 23�� = 23, ���� 1�� 16�� = 116):");             //���������� �ð��� �����ؾ� �Ǳ� ����
				scanf("%d", &Group[count].time);
				while (Group[count].time / 100 >= 24 || Group[count].time % 100 >= 60) {
					printf("�ٽ� �Է��ϼ���(���� 1�� 39�� = 1339,���� 0�� 23�� = 23, ���� 1�� 16�� = 116):");
					scanf("%d", &Group[count].time);
				}
				Group[count].price = 0;
				Group[count].usage = 0;

			}
			count++;
			break;
		}
		case(2): {         //�ֹ� �Է�   Ư�� ���̺��� �ֹ��� ��� �����ؾ� �� �� �߰�
			int a;
			printf("���̺�:");
			scanf("%d", &a);
			for (int i = 0; i < count; i++)
			{
				if (Group[i].table == a && Group[i].usage == 1)
				{
					int add;
					printf("�߰� �ݾ�:");
					scanf("%d", &add);
					Group[i].price += add;
					break;
				}
			}
			break;
		}
		case(3): {              //���� ��Ȳ(���� ��� �԰� �ִ���)

			printf("�¼�  �̸�         �ο� ��   ��ȭ��ȣ    �ð�    �ݾ�\n");
			for (int i = 0; i < count; i++)
			{
				if (Group[i].usage == 1) {
					printStruct(Group, i);
				}
			}
			break;
		}
		case(4): {     //���� Ȯ��(���� �� �� �����)
			printf("�¼�  �̸�         �ο� ��   ��ȭ��ȣ    �ð�    �ݾ�\n");
			for (int i = 0; i < count; i++)
			{
				if (Group[i].usage == 0)
				{
					printStruct(Group, i);

				}
			}
			break;
		}
		case(5): {                    //����
			int b;
			printf("������ ���̺�:");
			scanf("%d", &b);
			for (int i = 0; i < count; i++)
			{
				if (Group[i].table == b && Group[i].usage != 0)
				{
					printf("%d\n", Group[i].price);
					Group[i].usage = 2;

				}
			}

			break;
		}
		case(6): {                         //���Ӱ� �ڸ���ġ(������ ����� �����ؼ� �ڸ��� �����ϱ�)
			printf("�̸��� �Է��ϼ���:");
			char newname[10];

			scanf("%s", newname);
			for (int i = 0; i < count; i++)
			{

				if (strcmp(newname, &Group[i].person) == 0)
				{
					Group[i].usage = 1;


				}

			}

			break;
		}
		case(7): {    //���� ���� �湮�� �մ� ���(���������� ���� �� �»�� ���X)
			printf("�¼�  �̸�         �ο� ��   ��ȭ��ȣ    �ð�    �ݾ�\n");
			for (int i = 0; i < count; i++)
			{
				if (Group[i].usage != 0) {
					printStruct(Group, i);
				}

			}
			break;
		}
		case(8): {                //���α׷� ����
			exit(0);
		}
		default: printf("1~8������ �Է� �����մϴ�.\n");
		}

	}
	return 0;
}


void printStruct(info* n, int a) {

	printf(" ");
	printf("%-3d", (n + a)->table);

	printf(" %-10s   ", (n + a)->person);
	printf(" %-4d  ", (n + a)->member);
	printf("    ");
	int Num = (n + a)->phoneNum;
	for (int i = 0; i < 8; i++)  //0000-0000������ ����ϱ� ����
	{


		printf("%d", Num / (int)pow(10, 7 - i));
		Num = Num % (int)pow(10, 7 - i);
		if (i == 3) {
			printf("-");
		}
	}
	printf("   ");
	int time = (n + a)->time;
	if (time >= 1000) {     //00:02,00:12,05:30,11:20 ���� ��� ���� ���
		for (int i = 0; i < 4; i++)
		{
			printf("%d", time / (int)pow(10, 3 - i));
			time = time % (int)pow(10, 3 - i);
			if (i == 1)
			{
				printf(":");
			}
		}
	}
	else if (time >= 100) {
		printf("0");
		for (int i = 0; i < 3; i++) {

			printf("%d", time / (int)pow(10, 2 - i));
			time = time % (int)pow(10, 2 - i);
			if (i == 0) printf(":");
		}
	}
	else if (time >= 10) {
		printf("00:%d", time);
	}
	else {
		printf("00:0%d", time);
	}
	printf("   ");
	printf("%-7d\n", (n + a)->price);

}
