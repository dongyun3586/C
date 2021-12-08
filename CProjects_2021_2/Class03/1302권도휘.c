/*
* �ּ� ���� �ڵ带 ¥�� ���̶� �� ���α׷��� �� �ּ� �ޱ��� ����� ����Ͽ����ϴ�.
�̹����� switch ~ case�� �� ��ĥ�� ���Ұ� �ݴ��� goto�� �� �� ����߽��ϴ�. do ~ while���� �ξ� �� �������̶� �Ǵ��߽��ϴ�.
define������ �ణ �峭(?)�� �ư��.
�� �ڵ� �ð�: �� 12�ð� ����?
����� ���̺귯��: stdbool.h -> true�� false ���� �����ϱ� ������ �׷��� ���� ������ ����.
*/

#pragma region Predefinition

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_INPUT 256 // malloc() ���� �����ҽ��ϴ�.

/*
* ü�� ���� ��ȣȭ�ϱ�
ü������ '�� ���� �������� ����'�� �����ϴ� �ึ���� �ֱ� ������, �Ϻη� �� ������ ���� ���� ���ڸ� ����Ͽ����ϴ�.
P1�� �ҹ���, P2�� �빮���̸�, �ڿ� ���ڰ� ���� ���� ���� ü�� �⺸ ǥ������� ���̴� ���� ���ڸ� �����Խ��ϴ�.
�ڿ� ���ڰ� ���� ���, �ִ��� ���ĺ������� �̿��� ���ĺ��� ������ϴ�.
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

// Control Block(0x01 ~ 0x20)�� Box Drawings�� ��ü�Ǵ� ������ �̿���, ĭ�� �׸��� �� ����߽��ϴ�.
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

// �̿��� define���� ���� ���϶�� �� �̴ϴ�.
#define NEW_POSITION(_posName, _y, _x) {(_posName).x = (_x); (_posName).y = (_y);}
// ���� ��å���� ��ϴ�.
#define POS(_location) _location.y][_location.x
#define END_CASE { return NOT_LEGITIMATE; break; }

#define BOARD_SIZE 8
#define LINE_SIZE 9 // ���ڿ����� '\0' ��� ������

// typedef, enum, struct�� ����� ����ü ����
typedef enum player { NA = 0, P1, P2 };
typedef enum flag { ERROR = -4, NOT_YOURS, ALREADY_PLACED, NOT_LEGITIMATE, LEGITIMATE, KILL, FIRST_MOVE, SECOND_MOVE, EN_PASSANT, PROMOTION, CASTLING };

typedef char str[MAX_INPUT]; // ���ڿ�
typedef char Line[LINE_SIZE]; // ü���� ���η� �� ��
typedef Line Board[BOARD_SIZE]; // ü���� ��ü
typedef struct { int y; int x; } Position; // ü���ǿ����� ��ġ

// ���� ���� ����
Position start, dest; // ���۰� �� ��ġ
Board board; // ���� �÷����ϴ� ü����
str playerName1, playerName2; // �÷��̾��� �̸�
int turn, gameOver = 0; // ���� �ϼ�, ���ӿ��� ����
char deadPiece; // ������ ���� ü����

#pragma endregion
#pragma region Basic Functions
int abs(int num) { return num < 0 ? -num : num; } // ���� �Լ�
int sign(int num) { return num == 0 ? 0 : abs(num) / num; } // ��ȣ �Լ�
int abs_max(int a, int b) { return abs(a) > abs(b) ? abs(a) : abs(b); } // ������ �ִ� �Լ�
int abs_min(int a, int b) { return abs(a) < abs(b) ? abs(a) : abs(b); } // ������ �ּڰ� �Լ�
int whose_turn() { return turn % 2 + 1; } // ���� ������ �������� �м� (1, 2 �� �ϳ�)

// �� �Ǻ�
int team(char c) {
	if ('A' <= c && c <= 'Z') return P2;
	if ('a' <= c && c <= 'z') return P1;
	return 0;
}

int is_enemy(char startPiece, char endPiece) { return team(startPiece) != team(endPiece) && team(endPiece) ? 1 : 0; } // �� ��ġ�� ���� ������ ������ �Ǻ�

#pragma endregion
#pragma region Board Graphics

// �� �ٲٱ�
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

// ü���� �ʱ�ȭ
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

// �� ���
void print_line(Line line, int line_number) {
	for (int i = 0; i < LINE_SIZE; i++) {
		PRINT_BOX(BOX_28);

		// ü�� ���� ���¿� ������� ������ ���� ����ϱ�
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

// �׵θ� ���
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

// ü���� ��ü ���
void print_board(Board board) {
	str name;
	if (turn % 2) strcpy(name, playerName2);
	else strcpy(name, playerName1);
	printf("\n%d��, %s�� �����Դϴ�.\n", turn / 2 + 1, name);
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

// Position ����ü �ʱ�ȭ
void set_position(Position dest, int* src) {
	dest.y = src[0]; dest.x = src[1];
}

// ���, ��, ���� ���� ���⿡ �Ʊ��� �ִ��� �Ǻ�
int is_clear(Board board, Position start, int x_offset, int y_offset, int distance) {
	int x = start.x, y = start.y, cnt = 0;
	while (cnt++ < distance - 1 && !(x >> 3) && !(y >> 3)) {
		x += x_offset; y += y_offset;
		if (x < 0 || x > 7 || y < 0 || y > 7) return 1;
		if (team(board[y][x])) return 0;
	}
	return 1;
}

// �� ������ ���� �÷��� ��ȯ, �ึ�� �� ��ü
int raise_event(Board board, Position start, Position end) {
	char startPiece = board[POS(start)], endPiece = board[POS(end)], enPassantPiece = board[start.y][end.x];
	int dx = end.x - start.x, dy = end.y - start.y;
	int startTeam = team(startPiece), endTeam = team(endPiece);
	int allClear = is_clear(board, start, sign(dx), sign(dy), abs_max(dx, dy));
	int legitMove;

	// ��ó�� 1: �ڽ��� ���� �ƴϰų�, �ڽ��� ���� �ִ� ��Ҹ� ������ ��� ����ó��
	if (whose_turn() != startTeam) return NOT_YOURS;
	if (startTeam == endTeam) return ALREADY_PLACED;

	// ��ó�� 2: �ʹݿ� �̵��� ���� ���¸� ��ȭ��Ű��
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
	int standardMove = is_enemy(startPiece, endPiece) ? KILL : legitMove; // ���� ���ŵǾ����� KILL, �׷��� ������ legitmove ��ȯ

	// ��ó�� 3: �Ϻ� ���� Ư�� �ึ�� �����ϱ�: ���Ļ�, ����, ĳ����
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

	// �ึ�� ����
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

// ü���� �̵�
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

// ü���� ���� �޽��� ���
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
		strcpy(deadPieceName, "ŷ"); gameOver = 2 - turn % 2; break; // gameOver ������ �����Ͽ� ���� �޽��� ��� ����
	case P1_QUEEN:
	case P2_QUEEN:
		strcpy(deadPieceName, "��"); break;
	case P1_PAWN0:
	case P2_PAWN0:
	case P1_PAWN1:
	case P2_PAWN1:
	case P1_PAWN:
	case P2_PAWN:
		strcpy(deadPieceName, "��"); break;
	case P1_BISHOP:
	case P2_BISHOP:
		strcpy(deadPieceName, "���"); break;
	case P1_ROOK0:
	case P2_ROOK0:
	case P1_ROOK:
	case P2_ROOK:
		strcpy(deadPieceName, "��"); break;
	case P1_KNIGHT:
	case P2_KNIGHT:
		strcpy(deadPieceName, "����Ʈ"); break;
	}
	printf("%s�� %s ���!\n", turn % 2 ? playerName2 : playerName1, deadPieceName);
}

#pragma endregion
#pragma region Inputs

// getc + rewind
void input_char(char* buffer) {
	*buffer = getc(stdin);
	rewind(stdin);
}

// gets + rewind, Python�� input() ������ �� �ְ� �;���
void ask(char* message, char* buffer) {
	printf("%s ", message);
	gets(buffer, MAX_INPUT);
	rewind(stdin);
}

// Y/N ���� �޽��� ���
int yes_or_no(char answer) {
	switch (answer) {
	case 'Y':
	case 'y':
		return 1;
	default:
		return 0;
	}
}

// ü�� �Է�
void get_chess_input() {
	str control;
	print_board(board);
	ask("������ ���� ��ġ�� ���ּ��� (��: f2) :", control);
	NEW_POSITION(start, 8 + '0' - control[1], control[0] - 'a');
	ask("���� ���������� ���ּ��� : ", control);
	NEW_POSITION(dest, 8 + '0' - control[1], control[0] - 'a');
	printf("\n\n");
}

#pragma endregion

// ���� �Լ�.
int main(void) {
	str buffer; int status; str deadPieceName;
	printf("This is chess game!\nPress Enter to start.\n");
	input_char(buffer);

	ask("�����Ͻ� ������ �̸��� �����ּ��� (�ҹ��� ���� ����) :", playerName1);
	ask("�İ��Ͻ� ������ �̸��� �����ּ��� (�빮�� ���� ����) :", playerName2);
	printf("�׷� �����ϰڽ��ϴ�.\n\n");

	initiate_board(board);

	while (!gameOver) {
	input:
		get_chess_input();
		int status = move(board, start, dest);
		// printf("status: %d", status); // ����׿�

		// ��ó��: �߸��� �Է��� ��� ����ó��, ��õ� �޽��� ���
		if (status < 0) {
			switch (status) {
			case ERROR:
				printf("���� �߸��� �� �����ϴ�."); break;
			case NOT_YOURS:
				printf("�ڱ� ���� ���� �����̽� �� �ֽ��ϴ�."); break;
			case ALREADY_PLACED:
			case NOT_LEGITIMATE:
				printf("�������δ� �̵��� �� �����ϴ�."); break;
			default:
				printf("�� switch case © �� �� �߸�����? -������-");
			}
			printf("\n"); goto input;
		}

		// ���� status�� ���� ���ϴ� �޽��� ���
		switch (status) {
		case KILL:
			kill(board, dest, false); break;
		case PROMOTION:
			int promotionDone = 0; promo:
			ask("��� ������ ���θ���� ������ �˷��ּ���. ��: Q B R N", buffer);
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
	// �¸� �޽��� ��� ���� ����
	printf("\n\n\n%s �¸�!", gameOver == 1 ? playerName1 : playerName2); return 0;
}
