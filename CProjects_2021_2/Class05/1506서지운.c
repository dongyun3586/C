#include <stdio.h>
#include <stdlib.h>
#include <windows.h>			// SetConsoleTextAttribute �Լ� ����� ���� �������
#include <stdbool.h>
#include <string.h>
#include <ctype.h>				// isalnum �Լ� ����� ���� �������

#define LENGTH			9		// 9 X 9 ������ ���� 
#define MAX_FILENUMBER	12		// ������ ���� ���� �ִ� ����
#define MAXWORDS		10		// ���ڿ����� �ִ� �ܾ� ����
#define MAXCHAR			50		// ���ڿ��� �ִ� ���� ����
#define GREEN			10		// SetConsoleTextAttribute �Լ��� �ؽ�Ʈ ���� ��ȣ(�ʷϻ�)
#define WHITE			15		// SetConsoleTextAttribute �Լ��� �ؽ�Ʈ ���� ��ȣ(���)

enum {
	MENU_ERROR,		// ����
	PLAY_GAME,		// ���� �ϱ�
	PLAY_REDO,		// ���� �ٽ� �ϱ�
	SHOW_SOLUTION,	// ���� ����
	EXIT_GAME,		// ���� �ϱ�
};

int number[LENGTH][LENGTH] = { 0 };			// ������ ���� ����(sudoku%03d.txt)���� �о�ͼ� �����ϱ� ���� ����
int number_temp[LENGTH][LENGTH] = { 0 };	// ������ ���� ���� ����(sudokuSol%03d.txt)���� �о�ͼ� �����ϱ� ���� ����
char blank[LENGTH][LENGTH][5] = { '\0' };	// ������ ������ ��ĭ�� ���ڸ� �����ϱ� ���� ����

int fileNums = 0;							// ���� ���� ������ ���ڸ� �����ϱ� ���� ����				

bool ReadFileNo();										// �������� �� ������ ������ ���ڸ� ����(sudokuFileNo.txt)���� �б�
bool WriteFileNo();										// �������� �� ������ ������ ���ڸ� ����(sudokuFileNo.txt)�� ����
int printMenu();										// ȭ�鿡 ���� �޴��� ǥ���ϰ� ������ �޴� �޾ƿ���
void playGame();										// ������ ���� �ϱ�
bool Read(int* blk, bool solution);						// ������ ���� ����(sudoku%03d.txt) => ����(int number[LENGTH][LENGTH]), ��ĭ�� ���� �޾ƿ���
														// ������ ���� ���� ����(sudokuSol%03d.txt) => ����(int number_temp[LENGTH][LENGTH])
int getDigit(int no);									// 0 ~ 9 ���ڷ� ����
void setBlank();										// ��ĭ�� ���ڷ� �����ؼ� ����(char blank[LENGTH][LENGTH][5])�� ����(��: aa, ab, ..., ii)
void printSudoku(bool solution);						// ȭ�鿡 ������ ���� ǥ��
void removeDuplicateSpace(char* str);					// �ܾ� ���̿� ���� �ϳ��� ����� ��� ���� ����
int countWords(char* str);								// ���ڿ����� �ܾ��� ���� �ľ�
void spliteString(char* str, char strArr[][MAXCHAR]);	// ���ڿ����� ������ �������� �и��Ͽ� ���ڿ� �迭�� ����
bool findPositon(char* strblank, int* x, int* y);		// ������ ��ĭ�� ������ ���ڷκ��� ��ĭ�� ��ġ �ľ�	
bool showSolution();									// ȭ�鿡 ���� ǥ��

int main() {
	int menu;
	bool exit;

	if (!ReadFileNo())					// �������� �� ������ ������ ���ڸ� ���Ͽ��� �б�
		fileNums = 0;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);		// �ܼ��� �ؽ�Ʈ�� �������� ������� ����

	exit = false;
	while (!exit) {
		system("cls");					// �ܼ� ȭ�� �����
		menu = printMenu();				// ȭ�鿡 ���� �޴��� ǥ���ϰ� ������ �޴� �޾ƿ���
		switch (menu) {
		case MENU_ERROR:
			break;

		case PLAY_GAME:					// 1. ���� �ϱ�
			// �������� �� ������ ������ ���� ������ �ҷ����� ���� �κ�
			fileNums++;
			if (fileNums > MAX_FILENUMBER)		// ������ �ִ� �������� Ŭ ��� ù��° �������� ���ư��� �ݺ��ϱ�
				fileNums = 1;

			playGame();					// ������ ���� �ϱ�
			break;

		case PLAY_REDO:					// 2. ���� �ٽ� �ϱ�(��� �� ������ �ٽ� �ϱ�)
			if (fileNums < 1 || fileNums > MAX_FILENUMBER) {
				printf("�������� ������ �����ϴ�.\n");
				Sleep(1000);
			}
			else
				playGame();				// ������ ���� �ϱ�
			break;

		case SHOW_SOLUTION:				// 3. ���� ����(��� �� ������ ���� ����)
			if (fileNums < 1 || fileNums > MAX_FILENUMBER) {
				printf("�������� ������ �����ϴ�.\n");
				Sleep(1000);
			}
			else {
				if (!showSolution())	// ȭ�鿡 ���� ǥ��
					printf("���� ������ ǥ���� �� �����ϴ�.\n");
			}
			break;

		case EXIT_GAME:					// 4. ����(���α׷� �����ϱ�)
			exit = true;
			break;

		default:
			break;
		}
	}

	if (fileNums >= 1 && fileNums <= MAX_FILENUMBER)
		WriteFileNo();					// �������� �� ������ ������ ���ڸ� ���Ͽ� ����

	return 0;
}

// �������� �� ������ ������ ���ڸ� ���Ͽ��� �б�
bool ReadFileNo() {
	char temp[5] = "";
	int no;
	FILE* fpFileNo;			// �������� �� ������ ������ ���ڸ� ����(sudokuFileNo.txt)�� �б����� ���� ������

	fpFileNo = fopen("sudokuFileNo.txt", "r");
	if (fpFileNo == NULL)
		return false;

	fgets(temp, 5, fpFileNo);
	no = atoi(temp);		// ���ڸ� ���ڷ� ����
	if (no >= 0)
		fileNums = no;
	else
		fileNums = 0;		// ������ ���ڰ� 0���� ���� ���� �ʱⰪ(0)���� ����

	fclose(fpFileNo);
	return true;
}

// �������� �� ������ ������ ���ڸ� ���Ͽ� ����
bool WriteFileNo() {
	FILE* fpFileNo;			// �������� �� ������ ������ ���ڸ� ����(sudokuFileNo.txt)�� �������� ���� ������

	fpFileNo = fopen("sudokuFileNo.txt", "w");
	if (fpFileNo == NULL)
		return false;

	fprintf(fpFileNo, "%d", fileNums);
	fclose(fpFileNo);
	return true;
}

// ȭ�鿡 ���� �޴��� ǥ���ϰ� ������ �޴� �޾ƿ���
int printMenu() {
	int menu = 0;
	char str[MAXCHAR] = "";

	printf("  ������ �޴� �����ϱ� \n\n");
	printf("  1. ���� �ϱ�         \n");
	printf("  2. ���� �ٽ� �ϱ�    \n");
	printf("  3. ���� ����         \n");
	printf("  4. ����              \n\n");

	while (true) {
		scanf("%d", &menu);
		gets(str);	// gets �Լ��� ����� �� enter��� �Էº����� �����ֱ� ���ؼ� �����(gets �Լ��� ���Ⱑ �ִ� ������ �о���� �� ������ �ʼ������� �Էº����� �����־�� ��)
		break;
	}
	return menu;
}

// ������ �����ϱ�
void playGame() {
	char str[MAXCHAR] = "";						// ���ڿ�
	char strArr[MAXWORDS][MAXCHAR] = { '\0' };	// ���ڿ��� ���ԵǾ� �ִ� �ܾ �����ϱ� ���� �迭
	int blkcount;								// ������ ��ĭ�� ����
	int wordscount;								// ���ڿ��� �ܾ��� ����
	bool finish = false;						// �������� �Ǻ�

	system("cls");						// �ܼ� ȭ�� �����

	if (!Read(&blkcount, false))		// ������ ����: ����(sudoku%03d.txt) => ����(int number[LENGTH][LENGTH]), ��ĭ�� ������ �޾ƿ�
		return 0;
	//printf("blkcount = %d\n", blkcount);

	if (!Read(0, true))					// ������ ���� ����: ����(sudokuSol%03d.txt) => ����(int number_temp[LENGTH][LENGTH])
		return 0;

	setBlank();							// ��ĭ�� ���ڷ� �����ؼ� ����(char blank[LENGTH][LENGTH][5])�� ����(��: aa, ab, ..., ii)
	printSudoku(false);					// ȭ�鿡 ������ ���� ǥ��

	while (true) {
		if (finish)
			printf("������ �����Ͻ÷��� 'exit'�� �Է����ּ���.\n");
		else {
			printf("������ ��ġ���ڿ� ���ڸ� �Է����ּ���. (��: aa 1)\n");
			printf("������ �����Ͻ÷��� 'exit'�� �Է����ּ���.\n");
		}

		gets(str);												// ���ڿ� �޾ƿ���
		removeDuplicateSpace(str);								// ���ڿ����� �ܾ� ���̿� ���� �ϳ��� ����� ��� ���� ����
		wordscount = countWords(str);							// ���ڿ����� �ܾ��� ���� �ľ�
		spliteString(str, strArr);								// ���ڿ����� ������ �������� �и��Ͽ� ���ڿ� �迭�� ����
		//printf("%s, �ܾ� ���� : %d\n", str, wordscount);
		if (wordscount == 1) {									// �ܾ�� == 1�̸� 'exit' ���� �ľ� �� 1. ���� �ϱ� �Ǵ� 2. ���� �ٽ� �ϱ� ����
			CharLowerBuffA(strArr[0], strlen(strArr[0]));		// ��ҹ��� �������� �ʰ� 'exit'���� �ľ��ϱ� ����
			if (strcmp("exit", strArr[0]) == 0)
				break;
			else
				printf("���Ŀ� ���� �ʽ��ϴ�. �ٽ� �Է����ּ���.\n");
		}
		else if (!finish && wordscount == 2) {					// �ܾ�� == 2�̸� ��ĭ�� ������ ��������? ��ĭ�� ��������? �ľ�
			int x, y, answer;

			answer = atoi(strArr[1]);							// ���ڸ� ���ڷ� ����
			if (answer >= 1 && answer <= 9) {					// 1 ~ 9 �������� �ľ�
				if (findPositon(&strArr[0], &x, &y)) {			// ��ĭ�� ������ ���ڷκ��� ��ĭ�� ��ġ �ľ�
					//printf("findPositon = %d, %d\n", x, y);
					//printf("number_temp[%d][%d] = %d, answer = %d\n", x, y, number_temp[x][y], answer);
					if (number[x][y] == 0) {					// ������ ��ĭ���� �ľ�
						if (number_temp[x][y] == answer) {		// �������� �ľ�
							printf("�����Դϴ�.");
							number[x][y] = answer;

							// ������ ȭ�� �ٽ� ǥ��
							system("cls");
							printSudoku(false);

							blkcount--;
							if (blkcount == 0) {				// ��ĭ�� ������ 0�̸� ���� �ϼ�
								finish = true;
								printf("������ ��� �ϼ��ϼ̽��ϴ�. �����մϴ�!!\n");
							}
						}
						else
							printf("������ �ƴմϴ�. �ٽ� �Է����ּ���.\n");
					}
					else
						printf("������ ��ġ�� ���� �ʽ��ϴ�. �ٽ� �Է����ּ���.\n");
				}
				else
					printf("������ ��ġ�� ã�� �� �����ϴ�. �ٽ� �Է����ּ���.\n");
			}
			else
				printf("���� ����(1���� 9���� ����)�� ������ϴ�. �ٽ� �Է����ּ���.\n");
		}
	}
}

// ������ ���� ����(sudoku%03d.txt) => ����(int number[LENGTH][LENGTH]), ��ĭ�� ���� �޾ƿ���
// ������ ���� ���� ����(sudokuSol%03d.txt) => ����(int number_temp[LENGTH][LENGTH])
bool Read(int* blk, bool solution) {	// solution = true�� ��� ���� ����(sudokuSol%03d.txt)�� �а�, solution = false�� ��� ���� ����(sudoku%03d.txt)�� �а� ��ĭ�� ������ blk ������ ����
	int no;								// 0 ~ 9 ���ڷ� �����ϱ� ���� ����
	int size = LENGTH;					// 9 x 9 ����
	char fileName[MAXCHAR] = "";		// ���� �̸��� ���� ����
	FILE* fp;							// ������ ���� ����(sudoku%03d.txt), ������ ���� ���� ����(sudokuSol%03d.txt)�� �б����� ���� ������

	if (!solution)						// ������ ���� ������ ��� ��ĭ�� ���� 0���� �ʱ�ȭ
		*blk = 0;

	// ������ ���� �Ǵ� ���� ���� ����
	if (solution)
		sprintf(fileName, "sudokuSol%03d.txt", fileNums);
	else
		sprintf(fileName, "sudoku%03d.txt", fileNums);

	fp = fopen(fileName, "r");
	if (fp == NULL) {
		printf("������ �� �� �����ϴ�.\n");
		return false;
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size + 1; j++) {	// �ٹٲ� ó��(j < size + 1)
			no = fgetc(fp);						// ���Ͽ��� ���� 1�� �б�				
			no = getDigit(no);					// 0 ~ 9 ���ڷ� ����
			if (no < 0)							// �ٹٲ� ó��
				break;

			if (solution)
				number_temp[i][j] = no;			// ������ number_temp ������ ����
			else
				number[i][j] = no;				// ������ number ������ ����

			if (!solution) {					// ������ ��� ��ĭ ���� �˻�
				if (no == 0)
					*blk = *blk + 1;
			}
		}
	}

	fclose(fp);
	return true;
}

// 0 ~ 9 ���ڷ� ����
int getDigit(int no) {
	if (no >= '0' && no <= '9')		// ���� ����(0 ~ 9)
		no = no - '0';
	else
		no = -1;					// �ٹٲ� ó���� ���� �κ�

	return no;
}

// ��ĭ�� ���ڷ� �����ؼ� ����(char blank[LENGTH][LENGTH][5])�� ����(��: aa, ab, ..., ii)
// 9 x 9 ������ 3 x 3 ����� ������ 9���� 3 x 3 ������ ����
// 9���� 3 x 3 ������ ������ ���ʿ��� ����������, ������ �Ʒ��� ���ؼ� a, b, ..., i���� ù ��° ���� ����
// ������ 3 x 3 ���񿡼� ��ĭ�� ������ ���� a, b, ..., i���� �� ��° ���� ����
// �� ���ڸ� ���ļ� ��ĭ�� ���ڷ� ����
void setBlank() {
	int count;					// ������ 3 x 3 ���񿡼� ��ĭ�� ����
	int temp;
	char blankname1[5] = "";	// ù ��° ���ڸ� ���� ����
	char blankname2[5] = "";	// �� ��° ���ڸ� ���� ����

	// ���� �ʱ�ȭ
	for (int i = 0; i < LENGTH; i++) {
		for (int j = 0; j < LENGTH; j++)
			blank[i][j][0] = '\0';
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			count = 0;
			for (int k = 0; k < 3; k++) {
				for (int l = 0; l < 3; l++) {
					if (number[j * 3 + k][i * 3 + l] == 0) {				// ��ĭ�� ���
						temp = 'a' + i + j * 3;								// ù ��° ���� ����							
						blankname1[0] = (char)temp;
						blankname1[1] = '\0';
						temp = 'a' + count;									// �� ��° ���� ����
						blankname2[0] = (char)temp;
						blankname2[1] = '\0';
						//printf("(%d, %d) = %c %c\n", i * 3 + k, j * 3 + l, blankname1[0], blankname2[0]);
						strcat(blankname1, blankname2);						// �� ���ڸ� ��ħ
						//printf("(%d, %d) = %s\n", i * 3 + k, j * 3 + l, blankname1);
						strcpy(blank[j * 3 + k][i * 3 + l], blankname1);	// ��ĭ�� ������ ���ڸ� ����(char blank[LENGTH][LENGTH][5])�� ����
						count++;
					}
				}
			}
		}
	}
}

// ȭ�鿡 ������ ���� ǥ��
void printSudoku(bool solution) {
	printf("�������������������������������������������������������������������������� \n");
	for (int i = 0; i < LENGTH; i++) {
		for (int j = 0; j < LENGTH; j++) {
			if (j % ((LENGTH) / 3) == 0) printf("��  ");
			if (solution) {		// ������ ���� ǥ��					
				if (number[i][j] != 0) {				// ���ڴ� �ʷϻ����� ǥ��
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), GREEN);
					printf(" %d ", number_temp[i][j]);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
				}
				else
					printf(" %d ", number_temp[i][j]);	// ��ĭ�� ����(����)�� ������� ǥ��
			}
			else {			// ������ ���� ǥ��
				if (number[i][j] != 0) {				// ���� ǥ��
					if (blank[i][j][0] == '\0')
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), GREEN);	// ���ڴ� �ʷϻ����� ǥ��
					else
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);	// ��ĭ�� ����(����)�� ������� ǥ��

					printf(" %d ", number[i][j]);

					if (blank[i][j][0] == '\0')
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);	// �ܼ� �ؽ�Ʈ ������ �ʱⰪ ������� ����
				}
				else
					printf("%s ", blank[i][j]);			// ��ĭ�� ���ڴ� ������� ǥ��
			}
		}
		printf("�� ");
		if (i % ((LENGTH) / 3) == 2 && i != (LENGTH)-1) printf("\n�������������������������������������������������������������������������� ");
		printf("\n");
	}
	printf("�������������������������������������������������������������������������� \n");
}

// ���ڿ����� �ܾ� ���̿� ���� �ϳ��� ����� ��� ���� ����
void removeDuplicateSpace(char* str) {
	int i, j;
	int strLength;

	strLength = strlen(str);

	for (i = 0; i < strLength; i++) {
		if (i == 0) {											// ���ڿ��� ó�� ������ ���
			if (*(str + i) == ' ') {							// ó�� ���ڰ� ������ ���
				for (j = i; j < (strLength - 1); j++) {			// �� ��° ���ں��� ������ ���ڱ��� �� ���ھ� ������ �̵��Ͽ� ó�� ������ ���� ����
					*(str + j) = *(str + j + 1);
				}
				*(str + j) = '\0';								// �ܾ��� ���������� ǥ��
				strLength--;									// 1���� ������ �����Ͽ����Ƿ� ���ڼ� 1�� ����
			}
		}
		else if (i == (strLength - 1)) {						// ���ڿ��� ������ ������ ���
			if (*(str + i) == ' ') {							// ������ ���ڰ� ������ ���
				*(str + i) = '\0';								// �ܾ��� ���������� ǥ���Ͽ� ���� ����
				strLength--;									// 1���� ������ �����Ͽ����Ƿ� ���ڼ� 1�� ����
			}
		}
		else {												// ���ڿ��� ó�� �Ǵ� ������ ���ڰ� �ƴ� ���
			if ((*(str + i) == ' ') && *(str + i + 1) == ' ') {	// ������ ���̾� ���� ���
				for (j = i; j < (strLength - 1); j++) {			// �� ���ھ� ������ �̵��Ͽ� ���� ����
					*(str + j) = *(str + j + 1);
				}
				*(str + j) = '\0';								// �ܾ��� ���������� ǥ��
				strLength--;									// 1���� ������ �����Ͽ����Ƿ� ���ڼ� 1�� ����
			}
		}
	}
}

// ���ڿ����� �ܾ��� ���� �ľ�
// ���ڿ����� ������ �Ǵ� ���ڸ����� �Ǿ��ִ� �ܾ��� ���� �ľ�
int countWords(char* str) {
	int wordCount = 0;			// �ܾ��� ����
	bool isNewWord = false;		// ���ο� �ܾ� ����

	for (int i = 0; i < strlen(str); i++) {
		if (isalnum(*(str + i)) != 0) {									// ������ �Ǵ� �������� �Ǻ�
			isNewWord = true;
			for (; isalnum(*(str + i)) != 0 && i < strlen(str); i++) {	// ������ �Ǵ� ���ڰ� �ƴ� ������ ������ ��ġ ����
			}
		}
		if (isNewWord) {
			wordCount++;
			isNewWord = false;
		}
	}

	return wordCount;
}

// ���ڿ����� ������ �������� �и��Ͽ� ���ڿ� �迭�� ����
void spliteString(char* str, char strArr[][MAXCHAR]) {
	int a = 0, b = 0;
	for (int i = 0; str[i] != '\0'; i++) {
		if (isalnum(*(str + i)) != 0) {							// ������ �Ǵ� �������� �Ǻ�
			while (true) {
				if (*(str + i) == ' ' || *(str + i) == '\0') {	// ���� �Ǵ� ������ ������ ���
					strArr[b][a] = '\0';						// ������ �������� ǥ��
					break;
				}
				strArr[b][a] = *(str + i);						// ���ڿ� �迭�� �ܾ��� ���ڸ� ����
				a++;
				i++;
			}
			b++;												// �ܾ� �� ����
			a = 0;												// �ܾ��� ���� ��ġ 0���� �ʱ�ȭ
		}
	}
	strArr[b][a] = '\0';										// ���ڿ� ���� �����ϸ� ������ �ܾ��� �������� '\0'���� �߰�
}

// ������ ��ĭ�� ������ ���ڷκ��� ��ĭ�� ��ġ �ľ�
bool findPositon(char* strblank, int* x, int* y) {
	for (int i = 0; i < LENGTH; i++) {
		for (int j = 0; j < LENGTH; j++) {
			if (strcmp(strblank, blank[i][j]) == 0) {	// ���ڰ� ����(char blank[LENGTH][LENGTH][5])�� ����� ���ڿ� ������ ����� ��ġ ����
				*x = i;
				*y = j;
				return true;
			}
		}
	}
	return false;
}

// ȭ�鿡 ���� ǥ��
bool showSolution() {
	char str[MAXCHAR] = "";						// ���ڿ�
	char strArr[MAXWORDS][MAXCHAR] = { '\0' };	// ���ڿ��� ���ԵǾ� �ִ� �ܾ �����ϱ� ���� �迭
	int blkcount;								// ������ ��ĭ�� ����
	int wordscount;								// ���ڿ��� �ܾ��� ����

	if (!Read(&blkcount, false))							// ������ ����: ����(sudoku%03d.txt) => ����(int number[LENGTH][LENGTH]), ��ĭ�� ������ �޾ƿ�
		return false;

	if (!Read(0, true))										// ������ ���� ����: ����(sudokuSol%03d.txt) => ����(int number_temp[LENGTH][LENGTH])
		return false;

	system("cls");											// �ܼ� ȭ�� �����
	printSudoku(true);										// ȭ�鿡 ������ ���� ǥ��

	while (true) {
		printf("���亸�⸦ �����Ͻ÷��� 'exit'�� �Է����ּ���.\n");

		gets(str);											// ���ڿ� �޾ƿ���
		removeDuplicateSpace(str);							// ���ڿ����� �ܾ� ���̿� ���� �ϳ��� ����� ��� ���� ����
		wordscount = countWords(str);						// ���ڿ����� �ܾ��� ���� ���
		spliteString(str, strArr);							// ���ڿ����� ������ �������� �и��Ͽ� ���ڿ� �迭�� ����

		//printf("str = %s, wordscount = %d\n", str, wordscount);
		if (wordscount == 1) {								// �ܾ�� == 1�̸� 'exit' ���� �ľ� �� 3. ���� ���� ����
			CharLowerBuffA(strArr[0], strlen(strArr[0]));	// ��ҹ��� �������� �ʰ� 'exit'���� �ľ��ϱ� ����
			if (strcmp("exit", strArr[0]) == 0)
				break;
			else
				printf("���Ŀ� ���� �ʽ��ϴ�. �ٽ� �Է����ּ���.\n");
		}
		else
			printf("���Ŀ� ���� �ʽ��ϴ�. �ٽ� �Է����ּ���.\n");
	}
	return true;
}