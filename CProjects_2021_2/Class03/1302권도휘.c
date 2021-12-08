/*
* 주석 없이 코드를 짜는 편이라 선 프로그래밍 후 주석 달기의 방식을 사용하였습니다.
이번에는 switch ~ case를 좀 떡칠해 놓았고 금단의 goto도 두 번 사용했습니다. do ~ while보다 훨씬 더 직관적이라 판단했습니다.
define문으로 약간 장난(?)도 쳤고요.
총 코딩 시간: 한 12시간 정도?
사용한 라이브러리: stdbool.h -> true나 false 등을 구현하기 좋은데 그렇게 많이 쓰이진 않음.
*/

#pragma region Predefinition

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_INPUT 256 // malloc() 쓰기 귀찮았습니다.

/*
* 체스 말을 기호화하기
체스에서 '한 번도 움직이지 않음'을 만족하는 행마법이 있기 때문에, 일부러 한 종류에 여러 가지 문자를 배당하였습니다.
P1은 소문자, P2는 대문자이며, 뒤에 숫자가 붙지 않은 말은 체스 기보 표기법에서 쓰이는 약어에서 문자를 가져왔습니다.
뒤에 숫자가 붙은 경우, 최대한 알파벳상으로 이웃한 알파벳을 골랐습니다.
*/
#define P2_PAWN   'P'
#define P2_PAWN0  'O'
#define P2_PAWN1  'T'
#define P2_KING   'K'
#define P2_KING0  'J'
#define P2_QUEEN  'Q'
#define P2_BISHOP 'B'
#define P2_ROOK   'R'
#define P2_ROOK0  'S'
#define P2_KNIGHT 'N'
#define P1_PAWN   'p'
#define P1_PAWN0  'o'
#define P1_PAWN1  't'
#define P1_KING   'k'
#define P1_KING0  'j'
#define P1_QUEEN  'q'
#define P1_BISHOP 'b'
#define P1_ROOK   'r'
#define P1_ROOK0  's'
#define P1_KNIGHT 'n'
#define BLANK  ' '

// Control Block(0x01 ~ 0x20)이 Box Drawings로 교체되는 현상을 이용해, 칸을 그리는 데 사용했습니다.
#define BOX_26   0x01
#define BOX_24   0x02
#define BOX_68   0x03
#define BOX_48   0x04
#define BOX_28   0x05
#define BOX_46   0x06
#define BOX_2468 0x10
#define BOX_468  0x15
#define BOX_246  0x16
#define BOX_248  0x17
#define BOX_268  0x19
#define PRINT_BOX(_boxcode) printf("%c", (_boxcode))

// 이외의 define문은 전부 편하라고 쓴 겁니다.
#define NEW_POSITION(_posName, _y, _x) {(_posName).x = (_x); (_posName).y = (_y);}
// 뭔가 죄책감이 듭니다.
#define POS(_location) _location.y][_location.x
#define END_CASE { return NOT_LEGITIMATE; break; }

#define BOARD_SIZE 8
#define LINE_SIZE 9 // 문자열에서 '\0' 사용 때문에

// typedef, enum, struct를 사용한 구조체 정의
typedef enum player { NA = 0, P1, P2 };
typedef enum flag { ERROR = -4, NOT_YOURS, ALREADY_PLACED, NOT_LEGITIMATE, LEGITIMATE, KILL, FIRST_MOVE, SECOND_MOVE, EN_PASSANT, PROMOTION, CASTLING };

typedef char str[MAX_INPUT]; // 문자열
typedef char Line[LINE_SIZE]; // 체스의 가로로 한 줄
typedef Line Board[BOARD_SIZE]; // 체스판 전체
typedef struct { int y; int x; } Position; // 체스판에서의 위치

// 전역 변수 정의
Position start, dest; // 시작과 끝 위치
Board board; // 현재 플레이하는 체스판
str playerName1, playerName2; // 플레이어의 이름
int turn, gameOver = 0; // 각각 턴수, 게임오버 여부
char deadPiece; // 직전에 없앤 체스말

#pragma endregion
#pragma region Basic Functions
int abs(int num) { return num < 0 ? -num : num; } // 절댓값 함수
int sign(int num) { return num == 0 ? 0 : abs(num) / num; } // 기호 함수
int abs_max(int a, int b) { return abs(a) > abs(b) ? abs(a) : abs(b); } // 절댓값의 최댓값 함수
int abs_min(int a, int b) { return abs(a) < abs(b) ? abs(a) : abs(b); } // 절댓값의 최솟값 함수
int whose_turn() { return turn % 2 + 1; } // 현재 누구의 차례인지 분석 (1, 2 중 하나)

// 팀 판별
int team(char c) {
	if ('A' <= c && c <= 'Z') return P2;
	if ('a' <= c && c <= 'z') return P1;
	return 0;
}

int is_enemy(char startPiece, char endPiece) { return team(startPiece) != team(endPiece) && team(endPiece) ? 1 : 0; } // 두 위치에 놓인 말들이 적인지 판별

#pragma endregion
#pragma region Board Graphics

// 팀 바꾸기
void swap_team(char* str) {
	for (char* c = str; *c; c++) {
		switch (team(*c)) {
		case P2:
			*c = tolower(*c); break;
		case P1:
			*c = toupper(*c); break;
		}
	}
}

// 체스판 초기화
void initiate_board(Board board) {
	turn = 0;
	char first_line[LINE_SIZE] = "SNBQJBNS", second_line[LINE_SIZE] = "OOOOOOOO";
	for (int i = 0; i < BOARD_SIZE; i++) {
		switch (i < 4 ? i : BOARD_SIZE - 1 - i) {
		case 0:
			strcpy(board[i], first_line);
			break;
		case 1:
			strcpy(board[i], second_line);
			break;
		default:
			strcpy(board[i], "        ");
		}
	}
	for (int i = 6; i < 8; i++) {
		swap_team(board[i]);
	}
}

// 줄 출력
void print_line(Line line, int line_number) {
	for (int i = 0; i < LINE_SIZE; i++) {
		PRINT_BOX(BOX_28);

		// 체스 말의 상태와 상관없이 동일한 말을 출력하기
		switch (line[i]) {
		case P1_PAWN0:
		case P1_PAWN1:
			printf("p"); break;
		case P2_PAWN0:
		case P2_PAWN1:
			printf("P"); break;
		case P1_KING0:
			printf("k"); break;
		case P2_KING0:
			printf("K"); break;
		case P1_ROOK0:
			printf("r"); break;
		case P2_ROOK0:
			printf("R"); break;
		default:
			printf("%c", line[i]);
		}
	}
	printf(" %d", line_number);
	printf("\n");
}

// 테두리 출력
void print_border(char start, char end, char junc) {
	PRINT_BOX(start);
	for (int i = 0; i < BOARD_SIZE - 1; i++) {
		PRINT_BOX(BOX_46);
		PRINT_BOX(junc);
	}
	PRINT_BOX(BOX_46);
	PRINT_BOX(end);
	printf("\n");
}

// 체스판 전체 출력
void print_board(Board board) {
	str name;
	if (turn % 2) strcpy(name, playerName2);
	else strcpy(name, playerName1);
	printf("\n%d수, %s의 차례입니다.\n", turn / 2 + 1, name);
	print_border(BOX_26, BOX_24, BOX_246);
	for (int i = 0; i < BOARD_SIZE - 1; i++) {
		print_line(board[i], 8 - i);
		print_border(BOX_268, BOX_248, BOX_2468);
	}
	print_line(board[7], 1);
	print_border(BOX_68, BOX_48, BOX_468);
	printf(" a b c d e f g h\n\n\n");
}

#pragma endregion
#pragma region Chess Rules

// Position 구조체 초기화
void set_position(Position dest, int* src) {
	dest.y = src[0]; dest.x = src[1];
}

// 비숍, 룩, 퀸의 진행 방향에 아군이 있는지 판별
int is_clear(Board board, Position start, int x_offset, int y_offset, int distance) {
	int x = start.x, y = start.y, cnt = 0;
	while (cnt++ < distance - 1 && !(x >> 3) && !(y >> 3)) {
		x += x_offset; y += y_offset;
		if (x < 0 || x > 7 || y < 0 || y > 7) return 1;
		if (team(board[y][x])) return 0;
	}
	return 1;
}

// 말 각각에 따라 플래그 반환, 행마법 그 자체
int raise_event(Board board, Position start, Position end) {
	char startPiece = board[POS(start)], endPiece = board[POS(end)], enPassantPiece = board[start.y][end.x];
	int dx = end.x - start.x, dy = end.y - start.y;
	int startTeam = team(startPiece), endTeam = team(endPiece);
	int allClear = is_clear(board, start, sign(dx), sign(dy), abs_max(dx, dy));
	int legitMove;

	// 선처리 1: 자신의 말이 아니거나, 자신의 말이 있는 장소를 선택할 경우 예외처리
	if (whose_turn() != startTeam) return NOT_YOURS;
	if (startTeam == endTeam) return ALREADY_PLACED;

	// 선처리 2: 초반에 이동한 말의 상태를 변화시키기
	switch (startPiece) {
	case P1_PAWN0:
	case P2_PAWN0:
	case P1_ROOK0:
	case P2_ROOK0:
		legitMove = FIRST_MOVE; break;
	case P1_PAWN1:
	case P2_PAWN1:
		legitMove = SECOND_MOVE; break;
	default:
		legitMove = LEGITIMATE; break;
	}
	int standardMove = is_enemy(startPiece, endPiece) ? KILL : legitMove; // 말이 제거되었으면 KILL, 그렇지 않으면 legitmove 반환

	// 선처리 3: 일부 말의 특수 행마법 구현하기: 앙파상, 진급, 캐슬링
	switch (startPiece) {
	case P1_PAWN0:
		if (dy == -2 && !dx && allClear) return legitMove;
		break;
	case P2_PAWN0:
		if (dy == 2 && !dx && allClear) return legitMove;
		break;
	case P1_PAWN:
		if (end.y == 3 && dy == -1 && abs(dx) == 1 && enPassantPiece == P2_PAWN1) return EN_PASSANT;
		if (end.y == 0) return PROMOTION;
		break;
	case P2_PAWN:
		if (end.y == 4 && dy == 1 && abs(dx) == 1 && enPassantPiece == P1_PAWN1) return EN_PASSANT;
		if (end.y == 7) return PROMOTION;
		break;
	case P1_KING0:
	case P2_KING0:
		if (abs(dx) == 2 && dy == 0 && board[start.y][dx > 0 ? 7 : 0] == (startTeam == 1 ? P1_ROOK0 : P2_ROOK0) && is_clear(board, start, sign(dx), 0, dx > 0 ? 3 : 4)) return CASTLING;
		break;
	}

	// 행마법 구현
	switch (startPiece) {
	case P1_PAWN0:
	case P1_PAWN1:
	case P1_PAWN:
		if (dy == -1) {
			if (abs(dx) == 0 && endTeam == 0) return legitMove;
			if (abs(dx) == 1 && endTeam == 2) return KILL;
		} END_CASE;
	case P2_PAWN0:
	case P2_PAWN1:
	case P2_PAWN:
		if (dy == 1) {
			if (abs(dx) == 0 && endTeam == 0) return legitMove;
			if (abs(dx) == 1 && endTeam == 1) return KILL;
		} END_CASE;
	case P1_KING0:
	case P2_KING0:
	case P1_KING:
	case P2_KING:
		if (abs(dx) <= 1 && abs(dy) <= 1) return standardMove;
		END_CASE;
	case P1_QUEEN:
	case P2_QUEEN:
		if ((!dx || !dy || abs(dx) == abs(dy)) && allClear) return standardMove;
		END_CASE;
	case P1_BISHOP:
	case P2_BISHOP:
		if (abs(dx) == abs(dy) && allClear) return standardMove;
		END_CASE;
	case P1_ROOK0:
	case P2_ROOK0:
	case P1_ROOK:
	case P2_ROOK:
		if (!dx || !dy) return standardMove;
		END_CASE;
	case P1_KNIGHT:
	case P2_KNIGHT:
		if (dx * dx + dy * dy == 5) return standardMove;
		END_CASE;
	default:
		return ERROR; break;
	}
}

// 체스말 이동
int move(Board board, Position piece, Position dest) {
	int status = raise_event(board, piece, dest);
	if (status >= 0) {
		if (status == 1) deadPiece = board[POS(dest)];
		board[POS(dest)] = board[POS(piece)];
		board[POS(piece)] = BLANK;
		turn++;
	}
	return status;
}

// 체스말 제거 메시지 출력
int kill(Board board, Position death, bool forceKill) {
	str deadPieceName;
	if (forceKill) {
		deadPiece = board[POS(death)];
		board[POS(death)] = BLANK;
	}
	switch (deadPiece) {
	case P1_KING0:
	case P2_KING0:
	case P1_KING:
	case P2_KING:
		strcpy(deadPieceName, "킹"); gameOver = 2 - turn % 2; break; // gameOver 변수를 조정하여 엔드 메시지 출력 유도
	case P1_QUEEN:
	case P2_QUEEN:
		strcpy(deadPieceName, "퀸"); break;
	case P1_PAWN0:
	case P2_PAWN0:
	case P1_PAWN1:
	case P2_PAWN1:
	case P1_PAWN:
	case P2_PAWN:
		strcpy(deadPieceName, "폰"); break;
	case P1_BISHOP:
	case P2_BISHOP:
		strcpy(deadPieceName, "비숍"); break;
	case P1_ROOK0:
	case P2_ROOK0:
	case P1_ROOK:
	case P2_ROOK:
		strcpy(deadPieceName, "룩"); break;
	case P1_KNIGHT:
	case P2_KNIGHT:
		strcpy(deadPieceName, "나이트"); break;
	}
	printf("%s의 %s 사망!\n", turn % 2 ? playerName2 : playerName1, deadPieceName);
}

#pragma endregion
#pragma region Inputs

// getc + rewind
void input_char(char* buffer) {
	*buffer = getc(stdin);
	rewind(stdin);
}

// gets + rewind, Python의 input() 느낌을 좀 주고 싶었음
void ask(char* message, char* buffer) {
	printf("%s ", message);
	gets(buffer, MAX_INPUT);
	rewind(stdin);
}

// Y/N 선택 메시지 출력
int yes_or_no(char answer) {
	switch (answer) {
	case 'Y':
	case 'y':
		return 1;
	default:
		return 0;
	}
}

// 체스 입력
void get_chess_input() {
	str control;
	print_board(board);
	ask("움직일 말의 위치를 써주세요 (예: f2) :", control);
	NEW_POSITION(start, 8 + '0' - control[1], control[0] - 'a');
	ask("말의 도착지점을 써주세요 : ", control);
	NEW_POSITION(dest, 8 + '0' - control[1], control[0] - 'a');
	printf("\n\n");
}

#pragma endregion

// 메인 함수.
int main(void) {
	str buffer; int status; str deadPieceName;
	printf("This is chess game!\nPress Enter to start.\n");
	input_char(buffer);

	ask("선공하실 선수의 이름을 정해주세요 (소문자 말을 조종) :", playerName1);
	ask("후공하실 선수의 이름을 정해주세요 (대문자 말을 조종) :", playerName2);
	printf("그럼 시작하겠습니다.\n\n");

	initiate_board(board);

	while (!gameOver) {
	input:
		get_chess_input();
		int status = move(board, start, dest);
		// printf("status: %d", status); // 디버그용

		// 선처리: 잘못된 입력일 경우 예외처리, 재시도 메시지 출력
		if (status < 0) {
			switch (status) {
			case ERROR:
				printf("뭔가 잘못된 거 같습니다."); break;
			case NOT_YOURS:
				printf("자기 편의 말만 움직이실 수 있습니다."); break;
			case ALREADY_PLACED:
			case NOT_LEGITIMATE:
				printf("그쪽으로는 이동할 수 없습니다."); break;
			default:
				printf("나 switch case 짤 때 뭐 잘못했음? -개발자-");
			}
			printf("\n"); goto input;
		}

		// 이후 status에 따라 원하는 메시지 출력
		switch (status) {
		case KILL:
			kill(board, dest, false); break;
		case PROMOTION:
			int promotionDone = 0; promo:
			ask("어느 것으로 프로모션할 것인지 알려주세요. 예: Q B R N", buffer);
			char availablePromotions[] = "QBRN";
			for (char* c = availablePromotions; *c; c++) {
				if (buffer[0] == *c) {
					board[POS(dest)] = buffer[0]; promotionDone = 1; break;
				}
			}
			if (promotionDone) break;
			goto promo;
		case FIRST_MOVE:
			switch (board[POS(dest)]) {
			case P1_PAWN0:
			case P2_PAWN0:
				board[POS(dest)] += P1_PAWN1 - P1_PAWN0; break;
			case P1_KING0:
			case P2_KING0:
				board[POS(dest)] += P1_KING - P1_KING0; break;
			case P1_ROOK0:
			case P2_ROOK0:
				board[POS(dest)] += P1_ROOK - P1_ROOK0; break;
			default: break;
			} break;
		case SECOND_MOVE:
			switch (board[POS(dest)]) {
			case P1_PAWN1:
			case P2_PAWN1:
				board[POS(dest)] += P1_PAWN - P1_PAWN1; break;
			default: break;
			} break;
		case EN_PASSANT:
			Position death = { start.y, dest.x };
			kill(board, death, true); break;
		case CASTLING:
			Position rookStart = { start.y, start.x < dest.x ? 7 : 0 };
			Position rookEnd = { start.y, start.x < dest.x ? 5 : 3 };
			board[POS(rookEnd)] = board[POS(rookStart)];
			board[POS(rookStart)] = BLANK;
		}

	}
	// 승리 메시지 출력 이후 종료
	printf("\n\n\n%s 승리!", gameOver == 1 ? playerName1 : playerName2); return 0;
}
