#include <stdio.h>
#include <stdlib.h>
#include <windows.h>			// SetConsoleTextAttribute 함수 사용을 위한 헤더파일
#include <stdbool.h>
#include <string.h>
#include <ctype.h>				// isalnum 함수 사용을 위한 헤더파일

#define LENGTH			9		// 9 X 9 스도쿠 게임 
#define MAX_FILENUMBER	12		// 스도쿠 게임 파일 최대 숫자
#define MAXWORDS		10		// 문자열에서 최대 단어 개수
#define MAXCHAR			50		// 문자열의 최대 문자 개수
#define GREEN			10		// SetConsoleTextAttribute 함수의 텍스트 색상 번호(초록색)
#define WHITE			15		// SetConsoleTextAttribute 함수의 텍스트 색상 번호(흰색)

enum {
	MENU_ERROR,		// 에러
	PLAY_GAME,		// 게임 하기
	PLAY_REDO,		// 게임 다시 하기
	SHOW_SOLUTION,	// 정답 보기
	EXIT_GAME,		// 종료 하기
};

int number[LENGTH][LENGTH] = { 0 };			// 스도쿠 게임 파일(sudoku%03d.txt)에서 읽어와서 저장하기 위한 변수
int number_temp[LENGTH][LENGTH] = { 0 };	// 스도쿠 게임 정답 파일(sudokuSol%03d.txt)에서 읽어와서 저장하기 위한 변수
char blank[LENGTH][LENGTH][5] = { '\0' };	// 스도쿠 게임의 빈칸에 문자를 지정하기 위한 변수

int fileNums = 0;							// 실행 중인 게임의 숫자를 저장하기 위한 변수				

bool ReadFileNo();										// 마지막에 한 스도쿠 게임의 숫자를 파일(sudokuFileNo.txt)에서 읽기
bool WriteFileNo();										// 마지막에 한 스도쿠 게임의 숫자를 파일(sudokuFileNo.txt)에 쓰기
int printMenu();										// 화면에 메인 메뉴를 표시하고 선택한 메뉴 받아오기
void playGame();										// 스도쿠 게임 하기
bool Read(int* blk, bool solution);						// 스도쿠 게임 파일(sudoku%03d.txt) => 변수(int number[LENGTH][LENGTH]), 빈칸의 개수 받아오기
														// 스도쿠 게임 정답 파일(sudokuSol%03d.txt) => 변수(int number_temp[LENGTH][LENGTH])
int getDigit(int no);									// 0 ~ 9 숫자로 변경
void setBlank();										// 빈칸을 문자로 지정해서 변수(char blank[LENGTH][LENGTH][5])에 저장(예: aa, ab, ..., ii)
void printSudoku(bool solution);						// 화면에 스도쿠 게임 표시
void removeDuplicateSpace(char* str);					// 단어 사이에 공백 하나만 남기고 모든 공백 제거
int countWords(char* str);								// 문자열에서 단어의 개수 파악
void spliteString(char* str, char strArr[][MAXCHAR]);	// 문자열에서 공백을 기준으로 분리하여 문자열 배열에 저장
bool findPositon(char* strblank, int* x, int* y);		// 퍼즐의 빈칸에 지정된 문자로부터 빈칸의 위치 파악	
bool showSolution();									// 화면에 정답 표시

int main() {
	int menu;
	bool exit;

	if (!ReadFileNo())					// 마지막에 한 스도쿠 게임의 숫자를 파일에서 읽기
		fileNums = 0;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);		// 콘솔의 텍스트의 색상으로 흰색으로 변경

	exit = false;
	while (!exit) {
		system("cls");					// 콘솔 화면 지우기
		menu = printMenu();				// 화면에 메인 메뉴를 표시하고 선택한 메뉴 받아오기
		switch (menu) {
		case MENU_ERROR:
			break;

		case PLAY_GAME:					// 1. 게임 하기
			// 마지막에 한 스도쿠 게임의 다음 게임을 불러오기 위한 부분
			fileNums++;
			if (fileNums > MAX_FILENUMBER)		// 게임의 최대 개수보다 클 경우 첫번째 게임으로 돌아가서 반복하기
				fileNums = 1;

			playGame();					// 스도쿠 게임 하기
			break;

		case PLAY_REDO:					// 2. 게임 다시 하기(방금 한 게임을 다시 하기)
			if (fileNums < 1 || fileNums > MAX_FILENUMBER) {
				printf("진행중인 게임이 없습니다.\n");
				Sleep(1000);
			}
			else
				playGame();				// 스도쿠 게임 하기
			break;

		case SHOW_SOLUTION:				// 3. 정답 보기(방금 한 게임의 정답 보기)
			if (fileNums < 1 || fileNums > MAX_FILENUMBER) {
				printf("진행중인 게임이 없습니다.\n");
				Sleep(1000);
			}
			else {
				if (!showSolution())	// 화면에 정답 표시
					printf("퍼즐 정답을 표시할 수 없습니다.\n");
			}
			break;

		case EXIT_GAME:					// 4. 종료(프로그램 종료하기)
			exit = true;
			break;

		default:
			break;
		}
	}

	if (fileNums >= 1 && fileNums <= MAX_FILENUMBER)
		WriteFileNo();					// 마지막에 한 스도쿠 게임의 숫자를 파일에 저장

	return 0;
}

// 마지막에 한 스도쿠 게임의 숫자를 파일에서 읽기
bool ReadFileNo() {
	char temp[5] = "";
	int no;
	FILE* fpFileNo;			// 마지막에 한 스도쿠 게임의 숫자를 파일(sudokuFileNo.txt)에 읽기위한 파일 포인터

	fpFileNo = fopen("sudokuFileNo.txt", "r");
	if (fpFileNo == NULL)
		return false;

	fgets(temp, 5, fpFileNo);
	no = atoi(temp);		// 문자를 숫자로 변경
	if (no >= 0)
		fileNums = no;
	else
		fileNums = 0;		// 게임의 숫자가 0보다 작을 경우는 초기값(0)으로 지정

	fclose(fpFileNo);
	return true;
}

// 마지막에 한 스도쿠 게임의 숫자를 파일에 쓰기
bool WriteFileNo() {
	FILE* fpFileNo;			// 마지막에 한 스도쿠 게임의 숫자를 파일(sudokuFileNo.txt)에 쓰기위한 파일 포인터

	fpFileNo = fopen("sudokuFileNo.txt", "w");
	if (fpFileNo == NULL)
		return false;

	fprintf(fpFileNo, "%d", fileNums);
	fclose(fpFileNo);
	return true;
}

// 화면에 메인 메뉴를 표시하고 선택한 메뉴 받아오기
int printMenu() {
	int menu = 0;
	char str[MAXCHAR] = "";

	printf("  스도쿠 메뉴 선택하기 \n\n");
	printf("  1. 게임 하기         \n");
	printf("  2. 게임 다시 하기    \n");
	printf("  3. 정답 보기         \n");
	printf("  4. 종료              \n\n");

	while (true) {
		scanf("%d", &menu);
		gets(str);	// gets 함수를 사용할 때 enter라는 입력변수를 지워주기 위해서 사용함(gets 함수는 띄어쓰기가 있는 문장을 읽어들일 수 있지만 필수적으로 입력변수를 지워주어야 함)
		break;
	}
	return menu;
}

// 스도쿠 게임하기
void playGame() {
	char str[MAXCHAR] = "";						// 문자열
	char strArr[MAXWORDS][MAXCHAR] = { '\0' };	// 문자열에 포함되어 있는 단어를 저장하기 위한 배열
	int blkcount;								// 퍼즐의 빈칸의 개수
	int wordscount;								// 문자열의 단어의 개수
	bool finish = false;						// 게임종료 판별

	system("cls");						// 콘솔 화면 지우기

	if (!Read(&blkcount, false))		// 스도쿠 게임: 파일(sudoku%03d.txt) => 변수(int number[LENGTH][LENGTH]), 빈칸의 개수도 받아옴
		return 0;
	//printf("blkcount = %d\n", blkcount);

	if (!Read(0, true))					// 스도쿠 게임 정답: 파일(sudokuSol%03d.txt) => 변수(int number_temp[LENGTH][LENGTH])
		return 0;

	setBlank();							// 빈칸을 문자로 지정해서 변수(char blank[LENGTH][LENGTH][5])에 저장(예: aa, ab, ..., ii)
	printSudoku(false);					// 화면에 스도쿠 게임 표시

	while (true) {
		if (finish)
			printf("퍼즐을 종료하시려면 'exit'를 입력해주세요.\n");
		else {
			printf("퍼즐의 위치문자와 숫자를 입력해주세요. (예: aa 1)\n");
			printf("퍼즐을 종료하시려면 'exit'를 입력해주세요.\n");
		}

		gets(str);												// 문자열 받아오기
		removeDuplicateSpace(str);								// 문자열에서 단어 사이에 공백 하나만 남기고 모든 공백 제거
		wordscount = countWords(str);							// 문자열에서 단어의 개수 파악
		spliteString(str, strArr);								// 문자열에서 공백을 기준으로 분리하여 문자열 배열에 저장
		//printf("%s, 단어 개수 : %d\n", str, wordscount);
		if (wordscount == 1) {									// 단어개수 == 1이면 'exit' 여부 파악 후 1. 게임 하기 또는 2. 게임 다시 하기 종료
			CharLowerBuffA(strArr[0], strlen(strArr[0]));		// 대소문자 구분하지 않고 'exit'인지 파악하기 위함
			if (strcmp("exit", strArr[0]) == 0)
				break;
			else
				printf("형식에 맞지 않습니다. 다시 입력해주세요.\n");
		}
		else if (!finish && wordscount == 2) {					// 단어개수 == 2이면 빈칸에 지정된 문자인지? 빈칸의 정답인지? 파악
			int x, y, answer;

			answer = atoi(strArr[1]);							// 문자를 숫자로 변경
			if (answer >= 1 && answer <= 9) {					// 1 ~ 9 숫자인지 파악
				if (findPositon(&strArr[0], &x, &y)) {			// 빈칸에 지정된 문자로부터 빈칸의 위치 파악
					//printf("findPositon = %d, %d\n", x, y);
					//printf("number_temp[%d][%d] = %d, answer = %d\n", x, y, number_temp[x][y], answer);
					if (number[x][y] == 0) {					// 퍼즐의 빈칸인지 파악
						if (number_temp[x][y] == answer) {		// 정답인지 파악
							printf("정답입니다.");
							number[x][y] = answer;

							// 스도쿠 화면 다시 표시
							system("cls");
							printSudoku(false);

							blkcount--;
							if (blkcount == 0) {				// 빈칸의 개수가 0이면 퍼즐 완성
								finish = true;
								printf("퍼즐을 모두 완성하셨습니다. 축하합니다!!\n");
							}
						}
						else
							printf("정답이 아닙니다. 다시 입력해주세요.\n");
					}
					else
						printf("퍼즐의 위치가 맞지 않습니다. 다시 입력해주세요.\n");
				}
				else
					printf("퍼즐의 위치를 찾을 수 없습니다. 다시 입력해주세요.\n");
			}
			else
				printf("수의 범위(1부터 9까지 정수)를 벗어났습니다. 다시 입력해주세요.\n");
		}
	}
}

// 스도쿠 게임 파일(sudoku%03d.txt) => 변수(int number[LENGTH][LENGTH]), 빈칸의 개수 받아오기
// 스도쿠 게임 정답 파일(sudokuSol%03d.txt) => 변수(int number_temp[LENGTH][LENGTH])
bool Read(int* blk, bool solution) {	// solution = true일 경우 정답 파일(sudokuSol%03d.txt)을 읽고, solution = false일 경우 게임 파일(sudoku%03d.txt)을 읽고 빈칸의 개수를 blk 변수에 저장
	int no;								// 0 ~ 9 숫자로 변경하기 위한 변수
	int size = LENGTH;					// 9 x 9 퍼즐
	char fileName[MAXCHAR] = "";		// 파일 이름을 위한 변수
	FILE* fp;							// 스도쿠 게임 파일(sudoku%03d.txt), 스도쿠 게임 정답 파일(sudokuSol%03d.txt)을 읽기위한 파일 포인터

	if (!solution)						// 스도쿠 게임 파일일 경우 빈칸의 개수 0으로 초기화
		*blk = 0;

	// 스도쿠 게임 또는 정답 파일 오픈
	if (solution)
		sprintf(fileName, "sudokuSol%03d.txt", fileNums);
	else
		sprintf(fileName, "sudoku%03d.txt", fileNums);

	fp = fopen(fileName, "r");
	if (fp == NULL) {
		printf("파일을 열 수 없습니다.\n");
		return false;
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size + 1; j++) {	// 줄바꿈 처리(j < size + 1)
			no = fgetc(fp);						// 파일에서 문자 1개 읽기				
			no = getDigit(no);					// 0 ~ 9 숫자로 변경
			if (no < 0)							// 줄바꿈 처리
				break;

			if (solution)
				number_temp[i][j] = no;			// 정답은 number_temp 변수에 저장
			else
				number[i][j] = no;				// 게임은 number 변수에 저장

			if (!solution) {					// 게임일 경우 빈칸 개수 검사
				if (no == 0)
					*blk = *blk + 1;
			}
		}
	}

	fclose(fp);
	return true;
}

// 0 ~ 9 숫자로 변경
int getDigit(int no) {
	if (no >= '0' && no <= '9')		// 퍼즐 숫자(0 ~ 9)
		no = no - '0';
	else
		no = -1;					// 줄바꿈 처리를 위한 부분

	return no;
}

// 빈칸을 문자로 지정해서 변수(char blank[LENGTH][LENGTH][5])에 저장(예: aa, ab, ..., ii)
// 9 x 9 퍼즐을 3 x 3 퍼즐로 나누면 9개의 3 x 3 퍼즐이 생김
// 9개의 3 x 3 퍼즐의 순서를 왼쪽에서 오른쪽으로, 위에서 아래로 정해서 a, b, ..., i까지 첫 번째 문자 지정
// 각각의 3 x 3 퍼즐에서 빈칸의 개수에 따라 a, b, ..., i까지 두 번째 문자 지정
// 두 문자를 합쳐서 빈칸의 문자로 지정
void setBlank() {
	int count;					// 각각의 3 x 3 퍼즐에서 빈칸의 개수
	int temp;
	char blankname1[5] = "";	// 첫 번째 문자를 위한 변수
	char blankname2[5] = "";	// 두 번째 문자를 위한 변수

	// 변수 초기화
	for (int i = 0; i < LENGTH; i++) {
		for (int j = 0; j < LENGTH; j++)
			blank[i][j][0] = '\0';
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			count = 0;
			for (int k = 0; k < 3; k++) {
				for (int l = 0; l < 3; l++) {
					if (number[j * 3 + k][i * 3 + l] == 0) {				// 빈칸인 경우
						temp = 'a' + i + j * 3;								// 첫 번째 문자 지정							
						blankname1[0] = (char)temp;
						blankname1[1] = '\0';
						temp = 'a' + count;									// 두 번째 문자 지정
						blankname2[0] = (char)temp;
						blankname2[1] = '\0';
						//printf("(%d, %d) = %c %c\n", i * 3 + k, j * 3 + l, blankname1[0], blankname2[0]);
						strcat(blankname1, blankname2);						// 두 문자를 합침
						//printf("(%d, %d) = %s\n", i * 3 + k, j * 3 + l, blankname1);
						strcpy(blank[j * 3 + k][i * 3 + l], blankname1);	// 빈칸에 지정된 문자를 변수(char blank[LENGTH][LENGTH][5])에 저장
						count++;
					}
				}
			}
		}
	}
}

// 화면에 스도쿠 게임 표시
void printSudoku(bool solution) {
	printf("┌───────────┬───────────┬───────────┐ \n");
	for (int i = 0; i < LENGTH; i++) {
		for (int j = 0; j < LENGTH; j++) {
			if (j % ((LENGTH) / 3) == 0) printf("│  ");
			if (solution) {		// 스도쿠 정답 표시					
				if (number[i][j] != 0) {				// 숫자는 초록색으로 표시
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), GREEN);
					printf(" %d ", number_temp[i][j]);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
				}
				else
					printf(" %d ", number_temp[i][j]);	// 빈칸의 정답(숫자)은 흰색으로 표시
			}
			else {			// 스도쿠 게임 표시
				if (number[i][j] != 0) {				// 숫자 표시
					if (blank[i][j][0] == '\0')
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), GREEN);	// 숫자는 초록색으로 표시
					else
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);	// 빈칸의 정답(숫자)은 흰색으로 표시

					printf(" %d ", number[i][j]);

					if (blank[i][j][0] == '\0')
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);	// 콘솔 텍스트 색상을 초기값 흰색으로 변경
				}
				else
					printf("%s ", blank[i][j]);			// 빈칸의 문자는 흰색으로 표시
			}
		}
		printf("│ ");
		if (i % ((LENGTH) / 3) == 2 && i != (LENGTH)-1) printf("\n├───────────┼───────────┼───────────┤ ");
		printf("\n");
	}
	printf("└───────────┴───────────┴───────────┘ \n");
}

// 문자열에서 단어 사이에 공백 하나만 남기고 모든 공백 제거
void removeDuplicateSpace(char* str) {
	int i, j;
	int strLength;

	strLength = strlen(str);

	for (i = 0; i < strLength; i++) {
		if (i == 0) {											// 문자열의 처음 문자일 경우
			if (*(str + i) == ' ') {							// 처음 문자가 공백일 경우
				for (j = i; j < (strLength - 1); j++) {			// 두 번째 문자부터 마지막 문자까지 한 문자씩 앞으로 이동하여 처음 문자의 공백 제거
					*(str + j) = *(str + j + 1);
				}
				*(str + j) = '\0';								// 단어의 마지막임을 표시
				strLength--;									// 1개의 공백을 제거하였으므로 문자수 1개 감소
			}
		}
		else if (i == (strLength - 1)) {						// 문자열의 마지막 문자일 경우
			if (*(str + i) == ' ') {							// 마지막 문자가 공백일 경우
				*(str + i) = '\0';								// 단어의 마지막임을 표시하여 공백 제거
				strLength--;									// 1개의 공백을 제거하였으므로 문자수 1개 감소
			}
		}
		else {												// 문자열의 처음 또는 마지막 문자가 아닐 경우
			if ((*(str + i) == ' ') && *(str + i + 1) == ' ') {	// 공백이 연이어 있을 경우
				for (j = i; j < (strLength - 1); j++) {			// 한 문자씩 앞으로 이동하여 공백 제거
					*(str + j) = *(str + j + 1);
				}
				*(str + j) = '\0';								// 단어의 마지막임을 표시
				strLength--;									// 1개의 공백을 제거하였으므로 문자수 1개 감소
			}
		}
	}
}

// 문자열에서 단어의 개수 파악
// 문자열에서 영문자 또는 숫자만으로 되어있는 단어의 개수 파악
int countWords(char* str) {
	int wordCount = 0;			// 단어의 개수
	bool isNewWord = false;		// 새로운 단어 여부

	for (int i = 0; i < strlen(str); i++) {
		if (isalnum(*(str + i)) != 0) {									// 영문자 또는 숫자인지 판별
			isNewWord = true;
			for (; isalnum(*(str + i)) != 0 && i < strlen(str); i++) {	// 영문자 또는 숫자가 아닐 때까지 문자의 위치 증가
			}
		}
		if (isNewWord) {
			wordCount++;
			isNewWord = false;
		}
	}

	return wordCount;
}

// 문자열에서 공백을 기준으로 분리하여 문자열 배열에 저장
void spliteString(char* str, char strArr[][MAXCHAR]) {
	int a = 0, b = 0;
	for (int i = 0; str[i] != '\0'; i++) {
		if (isalnum(*(str + i)) != 0) {							// 영문자 또는 숫자인지 판별
			while (true) {
				if (*(str + i) == ' ' || *(str + i) == '\0') {	// 공백 또는 마지막 문자일 경우
					strArr[b][a] = '\0';						// 마지막 문자임을 표시
					break;
				}
				strArr[b][a] = *(str + i);						// 문자열 배열에 단어의 문자를 저장
				a++;
				i++;
			}
			b++;												// 단어 수 증가
			a = 0;												// 단어의 문자 위치 0으로 초기화
		}
	}
	strArr[b][a] = '\0';										// 문자열 끝에 도달하면 마지막 단어의 마지막에 '\0'문자 추가
}

// 퍼즐의 빈칸에 지정된 문자로부터 빈칸의 위치 파악
bool findPositon(char* strblank, int* x, int* y) {
	for (int i = 0; i < LENGTH; i++) {
		for (int j = 0; j < LENGTH; j++) {
			if (strcmp(strblank, blank[i][j]) == 0) {	// 문자가 변수(char blank[LENGTH][LENGTH][5])에 저장된 문자와 같으면 행렬의 위치 저장
				*x = i;
				*y = j;
				return true;
			}
		}
	}
	return false;
}

// 화면에 정답 표시
bool showSolution() {
	char str[MAXCHAR] = "";						// 문자열
	char strArr[MAXWORDS][MAXCHAR] = { '\0' };	// 문자열에 포함되어 있는 단어를 저장하기 위한 배열
	int blkcount;								// 퍼즐의 빈칸의 개수
	int wordscount;								// 문자열의 단어의 개수

	if (!Read(&blkcount, false))							// 스도쿠 게임: 파일(sudoku%03d.txt) => 변수(int number[LENGTH][LENGTH]), 빈칸의 개수도 받아옴
		return false;

	if (!Read(0, true))										// 스도쿠 게임 정답: 파일(sudokuSol%03d.txt) => 변수(int number_temp[LENGTH][LENGTH])
		return false;

	system("cls");											// 콘솔 화면 지우기
	printSudoku(true);										// 화면에 스도쿠 정답 표시

	while (true) {
		printf("정답보기를 종료하시려면 'exit'를 입력해주세요.\n");

		gets(str);											// 문자열 받아오기
		removeDuplicateSpace(str);							// 문자열에서 단어 사이에 공백 하나만 남기고 모든 공백 제거
		wordscount = countWords(str);						// 문자열에서 단어의 개수 계산
		spliteString(str, strArr);							// 문자열에서 공백을 기준으로 분리하여 문자열 배열에 저장

		//printf("str = %s, wordscount = %d\n", str, wordscount);
		if (wordscount == 1) {								// 단어개수 == 1이면 'exit' 여부 파악 후 3. 정답 보기 종료
			CharLowerBuffA(strArr[0], strlen(strArr[0]));	// 대소문자 구분하지 않고 'exit'인지 파악하기 위함
			if (strcmp("exit", strArr[0]) == 0)
				break;
			else
				printf("형식에 맞지 않습니다. 다시 입력해주세요.\n");
		}
		else
			printf("형식에 맞지 않습니다. 다시 입력해주세요.\n");
	}
	return true;
}