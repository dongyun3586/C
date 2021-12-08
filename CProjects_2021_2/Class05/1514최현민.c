#include <stdio.h>
#include <stdlib.h>		// ���� ������� �����ϱ� ���� �߰��� ��� ����
#include <string.h>		// ������ ������ ������ �̸��� ���ڿ��� ���·� �Է¹ޱ� ���� ��� ����
#include <windows.h>	// ǥ�� ���̺귯�� �ƴϹǷ� �ڵ� ���� X / system("cls") (Ŭ����)�� �������ֱ� ���� �߰��� ��� ����
#include <time.h>		// �˶� ������� ���� �ð��� ǥ�����ֱ� ���� �߰��� ��� ����

typedef struct THINGS_TO_DO {		// �ؾ� �� ���� ����ü�� ���·� ����
	int hour;			// �ؾ� �� ���� ���� �ð�
	int minute;			// �ؾ� �� ���� ���� ��
	char context[200];	// �ؾ� �� ���� ����
}th;

typedef struct alarm {		// �ؾ� �� ���� �����ϱ���� ���� �ð��� ����ü�� ���·� ����
	int lefthour;		// �ؾ� �� ���� �����ϱ���� ���� �ð�
	int leftminute;		// �ؾ� �� ���� �����ϱ���� ���� ��
	int leftsecond;		// �ؾ� �� ���� �����ϱ���� ���� ��
	char context[200];	// �ؾ� �� ���� ����
}ala;

th certain[100] = { 0 };		// Ȱ��ȭ�� �÷����� �� �ϵ��� ������ �������ִ� ��������
int num = 0;					// Ȱ��ȭ�� �÷����� �� �ϵ��� ������ �������ִ� ��������
void ReadPlanner();			// �ؽ�Ʈ ���Ͽ� ����� �ؾ� �� �ϵ��� �о�� ����ϴ� �Լ�
void WritePlanner();		// �ؽ�Ʈ ���Ͽ� �ڽ��� �ؾ� �� �ϵ��� �Է��� �÷��ʸ� ����� �Լ�
void ActivatePlanner(char* filename, th* a);		// ReadPlanner���� ���� �÷��ʿ� ����� �ؾ� �� �ϵ��� certain�� �����ϰ�, �� ������ num�� �����ϴ� �Լ�
void TimeAlarm(int num, th* a);		// GetMinute �Լ��� ���� certain�� ����� �ؾ� �� �ϵ��� �����ϱ���� ���� �ð��� ���� ������ִ� �Լ�(7�ʵ���)
void ArrayStruct(th* a, int num);	// certain�� ����� �ؾ� �� �ϵ��� �ð� ������ ��迭�ϴ� �Լ�
ala GetMinute(th k);		// certain�� ����� �ؾ� �� �ϵ��� ������� ���� �ð��� ala ����ü�� ���·� �����ϴ� �Լ�

int main() {
	int det = 0;
	do {		// ���α׷��� �ݺ������� �����ϱ� ���� do - while �� ���
		system("cls");
		printf("1514 �������� �÷��� �ۼ� ���α׷��� ���� ���� ȯ���մϴ�!~~\n\n");
		printf("�����ϰ� ���� �۾��� �������ּ���!\n\n");
	doyouknow:
		printf("1 - �÷��� �ۼ��ϱ�  |  2 - �÷��� Ȱ��ȭ�ϱ�  |  3 - ���� ���� Ȯ���ϱ�  |  4 - ���� : ");		// ���α׷����� �ϰ� ���� �۾��� ����
		scanf("%d", &det);		// �ϰ� ���� �۾��� int�� ���� det�� �Էµ� ������ �Ǻ�
		rewind(stdin);			// ReadPlanner, WritePlanner���� �÷��ʸ� �����ϰų� �о�� ������ �̸��� �Է¹ޱ� ���� ��Ʈ���� ���� �ڵ�(�� �Լ����� ����ϴ� �ͺ��� ȿ����)
		system("cls");			// ȭ���� ����.(clear)
		switch (det) {			// switch ���� ���� det�� ���� ���� ���� �ٸ� �Լ��� ����
		case 1:
			WritePlanner();		// �÷��ʸ� �ۼ��ϴ� WritePlanner �Լ� ����
			break;
		case 2:
			ReadPlanner();		// �÷��ʿ� ����� ������ �о���� ReadPlanner �Լ� ���� -> �Լ� ���� ActivatePlanner �Լ� ����
			break;
		case 3:
			TimeAlarm(num, certain);		// Ȱ��ȭ�� �÷����� �ؾ� �� �ϵ���� ���� �ð��� ������ִ� �Լ� TimeAlarm ����
			break;
		case 4:
			goto hello;			// 4(����)�� �ԷµǾ��� ������ do-while �� �ٱ��� �ִ� hello: �� �̵�(break ���� do-while���� Ż��)
		default:
			printf("1~4 ������ �ڿ����� �Է����ּ���.\n\n");
			goto doyouknow;		// det�� ���� 1~4 ������ ���� �ƴ� ��쿡�� �ٽ� ���α׷����� �ϰ� ���� �۾��� �����ϴ� �κ����� �̵�
		}
	} while (1);
hello:
	printf("���α׷��� �̿����ּż� �����մϴ�~\n"); // ���� do - while������ 4�� �Է��� ���������� ��� ���α׷� ����
	return 0;
}

void ReadPlanner() {
	char filename[80];		// �ҷ��� ������ �̸��� ������ ���ڿ�
helloboy:
	printf("�÷����� ������ �������� ������ �̸��� �Է��ϼ���. : ");
	gets(filename);			// ������ �̸��� gets �Լ��� �Է¹ޱ�
	int size = strlen(filename);
	if (strcmp(&filename[size - 4], ".txt") != 0)		// ������ �̸��� �ڿ� ".txt"�� ���� ��� ".txt"�� �߰����ֱ�
		strcpy(&filename[size], ".txt");
	system("cls");		// ȭ���� �ʱ�ȭ�ϱ�
	FILE* fk = fopen(filename, "r");		// �Է¹��� ������ ������ �о����
	if (fk == NULL) {			// ������ ���������� �ҷ��� �� ���� ��� ��� ��� & ������ �̸� �ٽ� �Է¹ޱ�
		system("cls");
		printf("������ ����� ������ �ʾҽ��ϴ�.\n");
		printf("�ٸ� ������ ���ų� ���� �̸��� �ؽ�Ʈ ������ ������ �� ���α׷��� �ٽ� �������ּ���.\n");
		goto helloboy;			// ������ �̸� �Է� ������ �̵��Ͽ� �̸� �ٽ� �Է¹ޱ�
	}
	char c = fgetc(fk);		// ���Ͽ� ����ִ� ���� ������ ���ڿ� ������ ����ϱ�
	printf("\n");
	while (c != EOF) {
		printf("%c", c);	// �� ���ڸ��� �ݺ� & �� ĭ �̵�
		c = fgetc(fk);
	}
	fclose(fk);				// �ҷ��� ���� �ݱ�
	int det = 1;			// �÷��� Ȱ��ȭ ���θ� ���� int�� ����
	printf("�� �÷��ʸ� Ȱ��ȭ�Ͻðڽ��ϱ�?\n");
	printf("1 - �� | 2 - �ƴϿ� : ");		// det�� 1�� �Է¹޾��� �� Ȱ��ȭ, 2 �Է¹޾��� �� ���α׷� ���� â���� ���ư���
	scanf("%d", &det);
	if (det == 1)
		ActivatePlanner(filename, certain);	// det�� 1�� ��� �÷��� Ȱ��ȭ(ActivatePlanner �Լ� ����)
}

void WritePlanner() {
	char filename[80];		// �ҷ��� ������ �̸��� ������ ���ڿ�
mynameis:
	printf("�÷��ʸ� �������� ������ �̸��� �Է��ϼ���. : ");
	gets(filename);			// ������ �̸��� gets �Լ��� �Է¹ޱ�
	int size = strlen(filename);
	if (strcmp(&filename[size - 4], ".txt") != 0)		// ������ �̸��� �ڿ� ".txt"�� ���� ��� ".txt"�� �߰����ֱ�
		strcpy(&filename[size], ".txt");
	FILE* fk = fopen(filename, "r");	// �Է¹��� ������ ������ �о����
	if (fk == NULL) {			// ������ ���������� �ҷ��� �� ���� ��� ��� ��� & ������ �̸� �ٽ� �Է¹ޱ�
		system("cls");
		printf("������ ����� ������ �ʾҽ��ϴ�.\n");
		printf("�ٸ� ������ ���ų� ���� �̸��� �ؽ�Ʈ ������ ������ �� ���α׷��� �ٽ� �������ּ���.\n");
		goto mynameis;			// ������ �̸� �Է� ������ �̵��Ͽ� �̸� �ٽ� �Է¹ޱ�
	}
	char c = fgetc(fk);		// ���Ͽ� ����ִ� ���� ������ ���ڿ� ������ ����ϱ�
	if (c != EOF) {
		int det;			// �÷����� ������ ��� �������� ���θ� �����ϴ� int�� ����
		printf("�̹� %s�� �Էµ� ������ �ֽ��ϴ�. ����ðڽ��ϱ�?\n", filename);
		printf("1 - �� | 2 - �ƴϿ�\n");		// det�� 1�� �Է¹޾��� �� �����, 2 �Է¹޾��� �� ���α׷� ���� â���� ���ư���
		scanf("%d", &det);
		fclose(fk);			// �ҷ��� ���� �ݱ�
		if (det == 2)
			return;			// 2 �Է¹޾��� �� ���α׷� ���� â���� ���ư���
	}
	system("cls");		// ȭ�� �ʱ�ȭ�ϱ�
	FILE* fp = fopen(filename, "w");		// �ؽ�Ʈ�� �Է��ϱ� ���� ���� �ҷ�����
	th b;				// ���Ͽ� �Է��� �÷����� ������ ����ü�� ���·� �Է¹ޱ�
	int count = 1;		// �� ��° �ؾ� �� ������ �˷��ִ� �뵵
	printf("�÷��ʿ� �����ϰ� ���� �� ���� �ð��� �� ������ �Է��ϼ���!\n");
	printf("ex) 4 0 ���� ����Ʈ Ǯ��\n");
	printf("�÷��� �ۼ��� ������ ���� ������ 0 0 0�� �Է����ּ���!\n");
	do {
		printf("%d��° ����: ", count);			// �� ��° �ؾ� �� ���� �Է��ϰ� �ִ��� �˷���
		scanf("%d %d", &b.hour, &b.minute);		// �ؾ� �� ���� �� / ���� �Է¹���.
		gets(b.context);				// �ؾ� �� ���� ������ �Է¹���.
		if (b.hour >= 0 && b.hour < 24 && b.minute >= 0 && b.minute < 60) {
			fprintf(fp, "%d %d%s\n", b.hour, b.minute, b.context);		// �Է¹��� ������ �ؽ�Ʈ ���Ͽ� �����ϱ�
			count++;		// �ؾ� �� ���� ������ 1�� �߰�
		}
		else
			printf("�ð��� 0�ú��� 23��, ���� 0�к��� 59�б��� �Է� �����մϴ�!\n");		// ������ ���� �ʴ� �� / ���� �Է����־��� �� ��� ���
	} while (b.hour != 0 || b.minute != 0 || strcmp(b.context, " 0") != 0);
	fclose(fp); // �ҷ��� ���� �ݱ�
	system("cls"); // ȭ�� �ʱ�ȭ�ϱ�
}

void ActivatePlanner(char* filename, th* a) {
	FILE* fp = fopen(filename, "r");		// �÷��ʿ� �ִ� ������ �о���� ���� ���� ����
	char c = fgetc(fp);			// �÷��ʿ� �ִ� ������ ���ں��� fgetc �Լ��� �̿��� �ޱ�
	int i = 0, count = 0, charnum = 0;		// i�� �� ��° �ؾ� �� ��������, count�� �� / �� / ���� �� ������ �Է¹޴�����, charnum�� context�� ����Ǵ� ���ڰ� �� ��°������ �˷���.
	while (c != EOF) {
		if (count == 0) {
			if (c == ' ')			// ������ ������ �� �Է¹޾ƾ� �Ѵٴ� ��ȣ
				count++, c = fgetc(fp);
			else
				a[i].hour = a[i].hour * 10 + c - 48;		// �� ���ں��� ������ hour���� 10�� ������ �� �ؽ�Ʈ�� ����� ���� �����ֱ�(-48�� �ƽ�Ű�ڵ� ����)
		}
		if (count == 1) {
			if (c == ' ')			// ������ ������ ���� �Է¹޾ƾ� �Ѵٴ� ��ȣ
				count++, c = fgetc(fp);
			else
				a[i].minute = a[i].minute * 10 + c - 48;	// �� ���ں��� ������ minute���� 10�� ������ �� �ؽ�Ʈ�� ����� ���� �����ֱ�(-48�� �ƽ�Ű�ڵ� ����)
		}
		if (count == 2) {
			if (c == '\n' && (a[i].hour != 0 || a[i].minute != 0 || a[i].context != "0")) {		// ���� ���ڰ� �ְų� ���Ͽ� '0 0 0'�� �ԷµǾ� ������ ���� �Է� ����
				printf("%d %d %s\n", a[i].hour, a[i].minute, a[i].context);		// ���Ͽ� ����Ǿ� �־��� ���� ����ϱ�
				count = 0, charnum = 0, i++;		// count & charnum ���� �ʱ�ȭ �� i, �� �ؾ� �� ���� ������ 1 �����ֱ�
				goto hello;		// ���� ���� �ݺ�
			}
			a[i].context[charnum] = c;		// context ���ڿ��� ���Ͽ� ����Ǿ� �ִ� ���� ���ں��� �����ϱ�
			charnum++;
		}
	hello:
		c = fgetc(fp);
	}
	ArrayStruct(a, i);		// �ؾ� �� �ϵ��� ����ü�� �ð� ������� �迭���ִ� �Լ�
	num = i;		// �ؾ� �� �ϵ��� ������ �������� num�� ����
	TimeAlarm(i, a);		// �ؾ� �� �ϵ���� ���� �ð��� �ʺ��� ������ִ� �Լ�
}

void ArrayStruct(th* a, int num) {
	for (int i = 0; i < num - 1; i++) {
		for (int j = i + 1; j < num; j++) {
			int imin = (a[i].hour) * 60 + a[i].minute, jmin = (a[j].hour) * 60 + a[j].minute;	// �ؾ� �� �ϵ��� �ð��� ���� ���·� ��ȯ
			if (imin > jmin) {		// �ռ� ����ü�� �ð��� �ڵ������ ����ü�� �ð����� ���� ��� �ڸ� �ٲپ��ֱ�
				th temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}

void TimeAlarm(int num, th* a) {
	ala now[100];			// �ð��� �󸶳� ���Ҵ��� ������ ����ִ� ����ü
	for (int i = 0; i < 7; i++) {		// 7�ʵ��� �ݺ��ϱ�
		system("cls");		// ȭ�� �ʱ�ȭ�ϱ�
		for (int j = 1; j < num; j++) {
			now[j] = GetMinute(a[j]);	// �� �ؾ� �� �ϱ��� �󸶳� ���� �ð��� ���Ҵ����� �������ִ� �Լ�
			if (now[j].lefthour != -1)	// lefthour�� ���� -1���� �ƴ����� ���� ���� ���� �ð��� �������� ���� �Ǵ�
				printf("'%s' �������� %d�� %d�� %d�� ���ҽ��ϴ�.\n", now[j].context, now[j].lefthour, now[j].leftminute, now[j].leftsecond);	// ���� �ð� �� ���� ���
			else
				printf("'%s' ������ �̹� �������ϴ�.\n", now[j].context);		// ���� ���� �ð��� ���������� �˷��ִ� ����
		}
		Sleep(1000);// 1�ʵ��� ��� ���� ����
	}
	system("cls");	// ȭ�� �ʱ�ȭ�ϱ�
}

ala GetMinute(th k) {
	ala res = { 0 };		// ��������� ��ȯ�� ����ü
	time_t timer = time(NULL);
	struct tm* t = localtime(&timer);// ������ �ð��� ��� �ִ� time_t ����ü
	int alarmsec = 0, nowsec = 0;
	alarmsec = 3600 * k.hour + 60 * k.minute, nowsec = (t->tm_hour) * 3600 + (t->tm_min) * 60 + t->tm_sec;	// ���� �ð��� �ؾ� �� ���� ���� �ð��� �ʷ� ��ȯ
	int sec = alarmsec - nowsec; // alarmsec�� nowsec�� �� �����ϴ� int�� ����
	if (sec > 0)		// �ؾ� �� ���� ���� �ð��� ���� �ð����� �ռ� ���
		res.lefthour = sec / 3600;
	else		// ���� �ð��� �ؾ� �� ���� ���� �ð����� �ռ� ���
		res.lefthour = -1;		// lefthour�� -1�� �����Ͽ� �̸� ��Ÿ����
	res.leftminute = (sec % 3600) / 60;	// leftminute�� sec�� 3600���� ���� �������� 60���� ���� ��, �� �� ����
	res.leftsecond = sec % 60;		// leftsecond�� sec�� 60���� ���� ������, �� �� ����
	strcpy(res.context, k.context);	// res.context�� ���Ͽ� ����Ǿ� �־��� �� ���� ������ strcpy �Լ��� ����
	return res;		// res ��ȯ�ϱ�
}