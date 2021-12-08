#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

#define MAX 100

typedef struct {
	char num[MAX];  //�޽ÿ� ��ȣ
	char name[MAX]; //õü �̸�
	char ra[MAX];   //����
	char dec[MAX];  //����
	char vis[MAX];  //�Ѻ��� ���
	char etc1[MAX]; //�̿��� ��
	char etc2[MAX];
}Messi;

void FindMessier(char* str1);

void Boss();
void printMessi(char* str, int num);
void printinfo(Messi* mess, FILE* fp);
void Editwiki(Messi* mess, FILE* fp);

int flag;

int main() {
	char sta;
	char Messier[110];

	while (1) {      //����ȭ�� ����. ���͸� ������ �ٸ� Ű�� ���� �� �ٽ� ���͸� ������� ������.
		printf("   Welcome to Messier Wiki!\n\n******************************\n\nPress Enter to start searching\n\n");
		scanf("%c", &sta);

		switch (sta) {
		case '\n':
			system("cls");
			FindMessier(Messier);
			break;
		default:
			printf("No!\n");
			Sleep(400);
			system("cls");
			rewind(stdin);
		}
	}
}

void FindMessier(char* str1) {  //�޽ÿ� õü ���� �˻�â. 1~110 ���� �ٸ� ���ڸ� �Է��ϸ� �ٽ� �Է��϶� ����.
	int find = 0;
	printf("\n\nEnter Messier number : ");
	scanf("%d", &find);
	printf("\n\n");
	Sleep(300);
	if (find == 102) {
		if (flag == 0)Boss();
		else printMessi(str1, find);
	}
	else printMessi(str1, find);

}


void Boss() {   //102�� �Է��ϸ� ������ â. �������� 3������ Ǯ�� �ȴ�. ���� �� ���������߰� ������ ��� ������, ���� �� ���α׷��� ����ȴ�.
	system("cls");
	for (int i = 0; i < 10; i++) {
		system("color 70");
		Sleep(10);
		system("color 07");
	}
	char ans[MAX];
	printf("\n\n���� �𸣴� �� ����ٴ�...\n\n");
	Sleep(400);
	printf("���� ���� ���������� ���߸� ���� ����Ű�� �ְڴ�");
	Sleep(500);
	system("cls");
	system("color 24");
	printf("ù ��° �����̴�.");
	Sleep(300);
	printf("\nM42���� Ʈ���������̶�� ���� �갳������ �ִ�.\n���⿡ �ִ� ��ǥ���� ���� ������ ����� ���ڸ� �����\n");
	scanf("%s", ans);
	if (ans[0] != '8') {
		system("cls");
		Sleep(500);
		printf("Ʋ�ȴ�. ����");
		exit(0);
	}
	system("cls");
	system("color 36");
	printf("�� �ƴ±�.\n�׷� ���� ������\n");
	Sleep(523);
	printf("1923�� M31�� �Ÿ��� �����س� ����� �����ΰ�?\n");
	ans[MAX - 1] = "";
	scanf("%s", ans);
	if (strcmp(ans, "Hubble") != 0) {
		system("cls");
		Sleep(500);
		printf("Ʋ�ȴ�. ����\n");
		exit(0);
	}
	system("cls");
	system("color 48");
	printf("���ݱ��� �� �����. \n\n���� ������ �����̴�!\n");
	for (int i = 0; i < 10; i++) {
		system("color 59");
		Sleep(10);
		system("color 48");
	}
	Sleep(523);
	printf("�ʰ� ���� ã��;��ϴ� M102�� ���� �������� ���� ���Ѵ�. \n�̰����� ���� ������ õü�� NGC�̸���?\n");
	ans[MAX - 1] = "";
	scanf("%s", ans);
	if (strcmp(ans, "NGC5866") != 0) {
		system("cls");
		Sleep(500);
		printf("Ʋ�ȴ�. ����\n");
		exit(0);
	}
	flag = 1;
	rewind(stdin);
	system("cls");
	system("color 07");
	printf("��� ������ �� Ǯ������ ������ �ָ�!\n\n�н������ 23jk89xc�̴�.\n\n�� �ܿ��� �����ۼ��� ������!");
	Sleep(500);
	system("cls");
	main();
}

void printinfo(Messi* mess, FILE* fp) {  // �Է��� ��ȣ�� �´� �޽ÿ� õü�� ������ ������ ���Ͽ��� ����ϴ� â
	fgets(mess->num, MAX, fp);
	printf("\n%s\n", mess->num);
	fgets(mess->name, MAX, fp);
	printf("%s\n", mess->name);
	fgets(mess->ra, MAX, fp);
	printf("%s", mess->ra);
	fgets(mess->dec, MAX, fp);
	printf("\n%s", mess->dec);
	fgets(mess->vis, MAX, fp);
	printf("\n%s\n", mess->vis);
	fgets(mess->etc1, MAX, fp);
	printf("%s\n", mess->etc1);
	if (feof(fp) == 0) {
		fgets(mess->etc2, MAX, fp);
		printf("%s\n", mess->etc2);
	}
}

void Editwiki(Messi* mess, FILE* fp) {  //�н����带 �Է��ϸ� �� �� �ִ� ���� �߰� �ý���. 
	char pw[MAX];
	char input[MAX];
	input[0] = '\0';
	printf("\n\nEnter password.");
	scanf("%s", &pw);
	if (strcmp(pw, "23jk89xc") == 0) {
		system("cls");
		printf("���� �߰��� ����θ� �����մϴ�. \n���� ���ʹ� �νĵ��� �ʽ��ϴ�.\n");
		rewind(stdin);
		fflush(fp);
		fgets(input, 99, stdin);
		rewind(stdin);
		fseek(fp, 0, SEEK_SET);
		strcat(mess->etc2, input);
		fputs(mess->num, fp);
		fputs(mess->name, fp);
		fputs(mess->ra, fp);
		fputs(mess->dec, fp);
		fputs(mess->vis, fp);
		fputs(mess->etc1, fp);
		fputs(mess->etc2, fp);
		system("cls");
		main();
	}
	else {
		printf("\nPassword is Wrong!\n\n");
	}
}

void printMessi(char* str, int num) { // �Է��� �޽ÿ� õü ��ȣ�� �°� �ý����� �����̵��� �ϴ� �Լ�.
	Messi ast;
	char enter[10];
	if (num == 1) {
		system("cls");
		FILE* fp;
		fp = fopen("M1.txt", "r+");
		printinfo(&ast, fp);
		Editwiki(&ast, fp);
		fclose(fp);
	}
	else if (num == 2) {
		system("cls");
		FILE* fp;
		fp = fopen("M2.txt", "r+");
		printinfo(&ast, fp);
		Editwiki(&ast, fp);
		fclose(fp);
	}
	else if (num == 3) {
		system("cls");
		FILE* fp;
		fp = fopen("M3.txt", "r+");
		printinfo(&ast, fp);
		Editwiki(&ast, fp);
		fclose(fp);
	}
	else if (num == 4) {
		system("cls");
		FILE* fp;
		fp = fopen("M4.txt", "r+");
		printinfo(&ast, fp);
		Editwiki(&ast, fp);
		fclose(fp);
	}
	else if (num == 5) {
		system("cls");
		FILE* fp;
		fp = fopen("M5.txt", "r+");
		printinfo(&ast, fp);
		Editwiki(&ast, fp);
		fclose(fp);
	}
	else if (num == 6) {
		system("cls");
		FILE* fp;
		fp = fopen("M6.txt", "r+");
		printinfo(&ast, fp);
		Editwiki(&ast, fp);
		fclose(fp);
	}
	else if (num == 7) {
		system("cls");
		FILE* fp;
		fp = fopen("M7.txt", "r+");
		printinfo(&ast, fp);
		Editwiki(&ast, fp);
		fclose(fp);
	}
	else if (num == 8) {
		system("cls");
		FILE* fp;
		fp = fopen("M8.txt", "r+");
		printinfo(&ast, fp);
		Editwiki(&ast, fp);
		fclose(fp);
	}
	else if (num == 9) {
		system("cls");
		FILE* fp;
		fp = fopen("M9.txt", "r+");
		printinfo(&ast, fp);
		Editwiki(&ast, fp);
		fclose(fp);
	}
	else if (num == 10) {
		system("cls");
		FILE* fp;
		fp = fopen("M10.txt", "r+");
		printinfo(&ast, fp);
		Editwiki(&ast, fp);
		fclose(fp);
	}
	else if (num == 11) {
		system("cls");
		FILE* fp;
		fp = fopen("M11.txt", "r+");
		printinfo(&ast, fp);
		Editwiki(&ast, fp);
		fclose(fp);
	}
	else if (num == 12) {
		system("cls");
		FILE* fp;
		fp = fopen("M12.txt", "r+");
		printinfo(&ast, fp);
		Editwiki(&ast, fp);
		fclose(fp);
	}
	else if (num == 13) {
		system("cls");
		FILE* fp;
		fp = fopen("M13.txt", "r+");
		printinfo(&ast, fp);
		Editwiki(&ast, fp);
		fclose(fp);
	}
	else if (num == 14) {
		system("cls");
		FILE* fp;
		fp = fopen("M14.txt", "r+");
		printinfo(&ast, fp);
		Editwiki(&ast, fp);
		fclose(fp);
	}
	else if (num == 15) {
		system("cls");
		FILE* fp;
		fp = fopen("M15.txt", "r+");
		printinfo(&ast, fp);
		Editwiki(&ast, fp);
		fclose(fp);
	}
	else if (num == 16) {
		system("cls");
		FILE* fp;
		fp = fopen("M16.txt", "r+");
		printinfo(&ast, fp);
		Editwiki(&ast, fp);
		fclose(fp);
	}
	else if (num == 17) {
		system("cls");
		FILE* fp;
		fp = fopen("M17.txt", "r+");
		printinfo(&ast, fp);
		Editwiki(&ast, fp);
		fclose(fp);
	}
	else if (num == 18) {
		system("cls");
		FILE* fp;
		fp = fopen("M18.txt", "r+");
		printinfo(&ast, fp);
		Editwiki(&ast, fp);
		fclose(fp);
	}
	else if (num == 19) {
		system("cls");
		FILE* fp;
		fp = fopen("M19.txt", "r+");
		printinfo(&ast, fp);
		Editwiki(&ast, fp);
		fclose(fp);
	}
	else if (num == 20) {
		system("cls");
		FILE* fp;
		fp = fopen("M20.txt", "r+");
		printinfo(&ast, fp);
		Editwiki(&ast, fp);
		fclose(fp);
	}
	else if (num == 21) {
		system("cls");
		FILE* fp;
		fp = fopen("M21.txt", "r+");
		printinfo(&ast, fp);
		Editwiki(&ast, fp);
		fclose(fp);
	}
	else if (num == 22) {
		system("cls");
		FILE* fp;
		fp = fopen("M22.txt", "r+");
		printinfo(&ast, fp);
		Editwiki(&ast, fp);
		fclose(fp);
	}
	else if (num == 23) {
		system("cls");
		FILE* fp;
		fp = fopen("M23.txt", "r+");
		printinfo(&ast, fp);
		Editwiki(&ast, fp);
		fclose(fp);
	}
	else if (num == 24) {
		system("cls");
		FILE* fp;
		fp = fopen("M24.txt", "r+");
		printinfo(&ast, fp);
		Editwiki(&ast, fp);
		fclose(fp);
	}
	else if (num == 25) {
		system("cls");
		FILE* fp;
		fp = fopen("M25.txt", "r+");
		printinfo(&ast, fp);
		Editwiki(&ast, fp);
		fclose(fp);
	}
	else if (num == 26) {
		system("cls");
		FILE* fp;
		fp = fopen("M26.txt", "r+");
		printinfo(&ast, fp);
		Editwiki(&ast, fp);
		fclose(fp);
	}
	else if (num == 27) {
		system("cls");
		FILE* fp;
		fp = fopen("M27.txt", "r+");
		printinfo(&ast, fp);
		Editwiki(&ast, fp);
		fclose(fp);
	}
	else if (num == 28) {
		system("cls");
		FILE* fp;
		fp = fopen("M28.txt", "r+");
		printinfo(&ast, fp);
		Editwiki(&ast, fp);
		fclose(fp);
	}
	else if (num == 29) {
		system("cls");
		FILE* fp;
		fp = fopen("M29.txt", "r+");
		printinfo(&ast, fp);
		Editwiki(&ast, fp);
		fclose(fp);
	}
	else if (num == 30) {
		system("cls");
		FILE* fp;
		fp = fopen("M30.txt", "r+");
		printinfo(&ast, fp);
		Editwiki(&ast, fp);
		fclose(fp);
	}
	else if (num == 31) {
		system("cls");
		FILE* fp;
		fp = fopen("M31.txt", "r+");
		printinfo(&ast, fp);
		Editwiki(&ast, fp);
		fclose(fp);
	}
	else if (num == 32) {
		system("cls");
		FILE* fp;
		fp = fopen("M32.txt", "r+");
		printinfo(&ast, fp);
		Editwiki(&ast, fp);
		fclose(fp);
	}
	else if (num == 33) {
		system("cls");
		FILE* fp;
		fp = fopen("M33.txt", "r+");
		printinfo(&ast, fp);
		Editwiki(&ast, fp);
		fclose(fp);
	}
	else if (num == 34) {
		system("cls");
		FILE* fp;
		fp = fopen("M34.txt", "r+");
		printinfo(&ast, fp);
		Editwiki(&ast, fp);
		fclose(fp);
	}
	else if (num == 35) {
		system("cls");
		FILE* fp;
		fp = fopen("M35.txt", "r+");
		printinfo(&ast, fp);
		Editwiki(&ast, fp);
		fclose(fp);
	}
	else if (num == 36) {
		system("cls");
		FILE* fp;
		fp = fopen("M36.txt", "r+");
		printinfo(&ast, fp);
		Editwiki(&ast, fp);
		fclose(fp);
	}
	else if (num == 37) {
		system("cls");
		FILE* fp;
		fp = fopen("M37.txt", "r+");
		printinfo(&ast, fp);
		Editwiki(&ast, fp);
		fclose(fp);
	}
	else if (num == 38) {
		system("cls");
		FILE* fp;
		fp = fopen("M38.txt", "r+");
		printinfo(&ast, fp);
		Editwiki(&ast, fp);
		fclose(fp);
	}
	else if (num == 39) {
		system("cls");
		FILE* fp;
		fp = fopen("M39.txt", "r+");
		printinfo(&ast, fp);
		Editwiki(&ast, fp);
		fclose(fp);
	}
	else if (num == 40) {
		system("cls");
		FILE* fp;
		fp = fopen("M40.txt", "r+");
		printinfo(&ast, fp);
		Editwiki(&ast, fp);
		fclose(fp);
	}
	else if (num == 41) {
		system("cls");
		FILE* fp;
		fp = fopen("M41.txt", "r+");
		printinfo(&ast, fp);
		Editwiki(&ast, fp);
		fclose(fp);
	}
	else if (num == 42) {
		system("cls");
		FILE* fp;
		fp = fopen("M42.txt", "r+");
		printinfo(&ast, fp);
		Editwiki(&ast, fp);
		fclose(fp);
	}
	else if (num == 43) {
		system("cls");
		FILE* fp;
		fp = fopen("M43.txt", "r+");
		printinfo(&ast, fp);
		Editwiki(&ast, fp);
		fclose(fp);
	}
	else if (num == 44) {
		system("cls");
		FILE* fp;
		fp = fopen("M44.txt", "r+");
		printinfo(&ast, fp);
		Editwiki(&ast, fp);
		fclose(fp);
	}
	else if (num == 45) {
		system("cls");
		FILE* fp;
		fp = fopen("M45.txt", "r+");
		printinfo(&ast, fp);
		Editwiki(&ast, fp);
		fclose(fp);
	}
	else if (num == 46) {
		system("cls");
		FILE* fp;
		fp = fopen("M46.txt", "r+");
		printinfo(&ast, fp);
		Editwiki(&ast, fp);
		fclose(fp);
	}
	else if (num == 47) {
		system("cls");
		FILE* fp;
		fp = fopen("M47.txt", "r+");
		printinfo(&ast, fp);
		Editwiki(&ast, fp);
		fclose(fp);
	}
	else if (num == 48) {
		system("cls");
		FILE* fp;
		fp = fopen("M48.txt", "r+");
		printinfo(&ast, fp);
		Editwiki(&ast, fp);
		fclose(fp);
	}
	else if (num == 49) {
		system("cls");
		FILE* fp;
		fp = fopen("M49.txt", "r+");
		printinfo(&ast, fp);
		Editwiki(&ast, fp);
		fclose(fp);
	}
	else if (num == 50) {
		system("cls");
		FILE* fp;
		fp = fopen("M50.txt", "r+");
		printinfo(&ast, fp);
		Editwiki(&ast, fp);
		fclose(fp);
	}
	else if (num == 51) {
		system("cls");
		FILE* fp;
		fp = fopen("M51.txt", "r+");
		printinfo(&ast, fp);
		Editwiki(&ast, fp);
		fclose(fp);
	}
	else if (num == 52) {
		system("cls");
		FILE* fp;
		fp = fopen("M52.txt", "r+");
		printinfo(&ast, fp);
		Editwiki(&ast, fp);
		fclose(fp);
	}
	else if (num == 53) {
		system("cls");
		FILE* fp;
		fp = fopen("M53.txt", "r+");
		printinfo(&ast, fp);
		Editwiki(&ast, fp);
		fclose(fp);
	}
	else if (num == 54) {
		system("cls");
		FILE* fp;
		fp = fopen("M54.txt", "r+");
		printinfo(&ast, fp);
		Editwiki(&ast, fp);
		fclose(fp);
	}
	else if (num == 55) {
		system("cls");
		FILE* fp;
		fp = fopen("M55.txt", "r+");
		printinfo(&ast, fp);
		Editwiki(&ast, fp);
		fclose(fp);
	}
	else if (num == 56) {
		system("cls");
		FILE* fp;
		fp = fopen("M56.txt", "r+");
		printinfo(&ast, fp);
		Editwiki(&ast, fp);
		fclose(fp);
	}
	else if (num == 57) {
		system("cls");
		FILE* fp;
		fp = fopen("M57.txt", "r+");
		printinfo(&ast, fp);
		Editwiki(&ast, fp);
		fclose(fp);
	}
	else if (num == 58) {
		system("cls");
		FILE* fp;
		fp = fopen("M58.txt", "r+");
		printinfo(&ast, fp);
		Editwiki(&ast, fp);
		fclose(fp);
	}
	while (1) {
		printf("\nPress Enter to continue... ");
		rewind(stdin);
		enter[0] = getchar();
		if (enter[0] == '\n') break;
	}
	system("cls");
	FindMessier(str);
}
