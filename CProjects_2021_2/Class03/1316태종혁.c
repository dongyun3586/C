#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<math.h>

#define WORDMAX 32 // �ִ� �ܾ� ��
#define STRMAX 20 // �ִ� ���� ��

typedef struct dayword {
	int num_words;
	char word_eng[WORDMAX][STRMAX];
	char word_kor[WORDMAX][STRMAX];
}dayword; // é�͸� ��� ���� ����ü
dayword set = { 0 }; // �н��� é�͸� ��� ���� ����ü
dayword day01_1, day01_2, day15_1; // é�͸� ��� ���� ����ü

#pragma region
void select(); // é�� ����
void setting(char eng[WORDMAX][STRMAX], char kor[WORDMAX][STRMAX], dayword dayset); // set ����ü�� ������ é�� ����
void start(); // �н� ��� ����, �̵�(write, choose)
void write(char put[WORDMAX][STRMAX], char get[WORDMAX][STRMAX]); // �ְ���(��->��)
void choose(char put[WORDMAX][STRMAX], char get[WORDMAX][STRMAX]); // ������
int countWords(char word[WORDMAX][STRMAX]); // ������ �迭�� �ܾ� �� ��ȯ
void generateRandom(); // 1���� �ܾ� �������� ������ �������� �迭(�ߺ� ����)
void printLine(); // �� ���
void swapStructure(dayword* a, dayword* b);
void over(); // ���α׷� ����
#pragma endregion

int mode, day, random[WORDMAX]; // �ܾ� �н� é��, ��� ����, ���� �迭

#pragma region
char day01_1_eng[WORDMAX][STRMAX] = { "annual", "eleborately", "costume", "officially", "declare", "origin", "slave", "rebellion", "rule", "temporary", "celebrate", "coal", "modern", "old-fashioned", "race", "ethnicity", "symbolize", "equality", "integrate", "citizen",  "diversity", "unity", "similarity" };
char day01_1_kor[WORDMAX][STRMAX] = { "�ų���", "���鿩", "�ǻ�", "����������", "�����ϴ�", "���", "�뿹", "�ݶ�", "�����ϴ�", "�Ͻ�����", "�����ϴ�", "��ź", "������", "������", "����", "������", "��¡�ϴ�", "���", "�����ϴ�", "�ù�","�پ缺", "����", "������" };
char day01_2_eng[WORDMAX][STRMAX] = { "ancient", "impressive", "tomb", "monument", "wheat", "sacred", "texture", "nutritional", "benefit", "grain", "fiber", "archaeology", "artwork", "preserve", "yeast", "mud", "method", "reflect", "typical", "revolution", "justice", "represent", "generation", "magnificence", "term" };
char day01_2_kor[WORDMAX][STRMAX] = { "�����", "�λ�����", "����", "��买", "��", "�ż���", "����", "�������", "�̵�", "�", "������", "�����", "����ǰ", "�����ϴ�", "ȿ��", "����", "���", "�ݿ��ϴ�", "��������", "����", "����", "��Ÿ����", "����", "���", "���" };
char day15_1_eng[WORDMAX][STRMAX] = { "witness", "rapid", "ancient", "compete", "government", "profound", "democracy", "rule", "council", "executive", "administrative", "election", "citizen", "assembly", "aristocratic", "authority", "privilege", "inhabitant", "legal", "apparent", "attribute", "limitation", "rebellion", "retain", "stability", "origin", "rivalry", "compromise" };
char day15_1_kor[WORDMAX][STRMAX] = { "����ϴ�", "����", "�����", "�����ϴ�", "����", "����", "��������", "�����ϴ�", "����ȸ", "������", "��������", "����", "�ù�", "��ȸ", "������", "����", "Ư��", "�ֹ�", "��������", "�и���", "Ư��", "�Ѱ�", "�ݶ�", "�����ϴ�", "����", "���", "����", "Ÿ���ϴ�" };
#pragma endregion

int main() {
	select();
}

void select() {
	printf("DAY�� �����ϼ���.\n1. DAY 01-1\n2. DAY 01-2\n3. DAY 15-1\n");
	scanf("%d", &day);
	switch (day) {
	case 1: setting(day01_1_eng, day01_1_kor, day01_1);
		break;
	case 2: setting(day01_2_eng, day01_2_kor, day01_2);
		break;
	case 3: setting(day15_1_eng, day15_1_kor, day15_1);
		break;
	default:
		over();
	}
}

void setting(char eng[WORDMAX][STRMAX], char kor[WORDMAX][STRMAX], dayword dayset) {
	dayset.num_words = countWords(eng); // ����ü ��� ����
	memcpy(dayset.word_eng, eng, WORDMAX * STRMAX); // ����ü ��� ����
	memcpy(dayset.word_kor, kor, WORDMAX * STRMAX); // ����ü ��� ����
	swapStructure(&set, &dayset); // ����ü ��ü ����
	start();
}

void start() {
	printf("�ܾ� �н��� �����մϴ�. �н� ��带 �����ϼ���.\n1. �� -> ��(�ְ���)\n2. �� -> ��(������)\n3. �� -> ��(������)\n");
	scanf("%d", &mode);
	switch (mode) {
	case 1:
		printf("�� -> ��(�ְ���)\n");
		write(set.word_kor, set.word_eng); // ���, �Է� ��
		break;
	case 2:
		printf("�� -> ��(������)\n");
		choose(set.word_kor, set.word_eng); // ���, �Է� ��
		break;
	case 3:
		printf("�� -> ��(������)\n");
		choose(set.word_eng, set.word_kor); // ���, �Է� ��
		break;
	default: over();
	}
}

void write(char put[WORDMAX][STRMAX], char get[WORDMAX][STRMAX]) {
	printLine();
	int count = 0; // ���� ���� ��
	char input[STRMAX];
	srand(time(NULL));
	for (int i = 0; i < set.num_words; i++) {
		int j = rand() % set.num_words;
		printf("%s\n�Է�: ", put[j]);
		scanf("%s", input);
		if (strcmp(input, get[j])) // �� ���ڿ��� ��ġ���� ����
			printf("Ʋ�Ⱦ��.\n");
		else {
			printf("����!\n");
			count++;
		}
		printLine();
	}
	printf("%d�� ����!\n", count);
	over();
}

void choose(char put[WORDMAX][STRMAX], char get[WORDMAX][STRMAX]) {
	printLine();
	int input, count = 0;
	for (int i = 0; i < set.num_words; i++) {
		generateRandom(); // ���� �迭 ����
		int j = random[0], j1 = random[1], j2 = random[2], j3 = random[3]; // ���� �迭���� 4���� �� �̱�
		int n = rand() % 4 + 1; // 1~4 �� ���� 1�� ����
		printf("%s\n", put[j]); // ���� ���
		switch (n) {
		case 1: printf("1. %s\t2. %s\t3. %s\t4. %s\n", get[j], get[j1], get[j2], get[j3]);
			break;
		case 2: printf("1. %s\t2. %s\t3. %s\t4. %s\n", get[j1], get[j], get[j2], get[j3]);
			break;
		case 3: printf("1. %s\t2. %s\t3. %s\t4. %s\n", get[j1], get[j2], get[j], get[j3]);
			break;
		case 4: printf("1. %s\t2. %s\t3. %s\t4. %s\n", get[j1], get[j2], get[j3], get[j]);
			break;
		default: over();
		} // ���� ���
		scanf("%d", &input);
		if (input == n) {
			printf("����!\n");
			count++;
		}
		else printf("Ʋ�Ⱦ��.\n");
		printLine();
	}
	printf("%d�� ����!\n", count);
	over();
}

void generateRandom() {
	int temp, x, y;
	srand(time(NULL));
	for (int i = 0; i < set.num_words; i++)
		random[i] = i;
	for (int i = 0; i < 99; i++) {
		x = rand() % set.num_words;
		y = rand() % set.num_words;
		if (x != y) { // x=y�� ��� ��ȯ���� ����
			temp = random[x];
			random[x] = random[y];
			random[y] = temp;
		}
	}
}

void printLine() {
	for (int i = 0; i < 30; i++)
		printf("-");
	printf("\n");
}

int countWords(char word[WORDMAX][STRMAX]) {
	int i = 0;
	while (strlen(word[i]) != 0)
		i++;
	return i;
}

void swapStructure(dayword* a, dayword* b) {
	dayword temp = *a;
	*a = *b;
	*b = temp;
}

void over() {
	printf("���α׷��� �����մϴ�.");
	exit(0);
}