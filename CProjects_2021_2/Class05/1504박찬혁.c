#include<stdio.h>

void set(char array[31][31]);
void print(char array[31][31]);
void process(int X, int Y, int count, char horse);
void move(int n, int x, int y, int count, char horse);
int check(int count1, int count2);
void end();

char arr[31][31];//윷놀이 판
char* yuut[] = { "OOOX(도)","OOXX(개)","OXXX(걸)","XXXX(윷)","OOOO(모)" }; //윷

int x1 = 30, y1 = 30, x2 = 30, y2 = 30;// 각각 팀1,팀2의 x,y 좌표
int counta = 0, countb = 0;//각각 팀1과 팀2의 도착한 말의 개수
int p;//p가 1일 때 도, p가 2일 때 개.. p가 5일 때 모 등
char k[2];// 윷놀이 판이 연속적으로 뜨는 것을 막기 위해 만든 엔터키를 받는 배열

int main() {
	printf("찬혁이의 신나고~ 재밌는~ 윷!놀!이!\n총 2팀이고 팀1이 선공이며 각 팀당 말은 4개입니다. enter 키를 눌러 시작해주세요.\n");
	fgets(k, 2, stdin);// 시작 화면에 바로 윷놀이 판이 뜨는 걸 방지하기 위해

	set(arr);//arr 초기화

	while (1)
	{
		process(x1, y1, counta, '1');
		process(x2, y2, countb, '2');

		if (check(counta, countb))
			break;
	}

	end();

	return 0;
}

void set(char array[31][31]) { // 말이 없는 기본적이 윷놀이판 만드는 함수
	for (int i = 0; i < 31; i++)//2차원 배열의 행, 열이 31인 이유 : 윷놀이판 가로,세로 영역 개수는 각각 6개, 대각선 영역 개수는 7개(자세한 건 보고서에 나온 그림을 참고해주세요)
		for (int j = 0; j < 31; j++)
			arr[i][j] = ' '; //배열 초기화의 개념

	for (int i = 0; i < 6; i++) {
		array[0][6 * i] = 'O'; // 가로 부분
		array[30][6 * i] = 'O'; //가로 부분 
		array[6 * i][0] = '0';  //세로 부분
		array[6 * i][30] = '0'; //세로 부분
	}

	for (int i = 0; i < 7; i++) { // 대각선 
		array[5 * i][5 * i] = 'O'; // 우하향
		array[5 * i][30 - 5 * i] = 'O'; // 좌하향
	}
}

void print(char array[31][31]) { // 윷놀이판 출력 함수
	for (int i = 0; i < 31; i++) {
		for (int j = 0; j < 31; j++)
			printf("%c", *(array[i] + j));
		printf("\n");
	}
}

void process(int X, int Y, int count, char horse) { // 윷놀이의 진행과정이 드러나 있는 함수
	srand(time(NULL));
	p = rand() % 5 + 1;
	printf("팀 %c : %s\n", horse, yuut[p - 1]);// 각 팀에 얼만큼 말이 이동할지 보여준다.
	move(p, X, Y, count, horse);
	print(arr);

	if (p == 4 || p == 5) {
		printf("한 번 더~ enter 키를 입력하세요\n");
		fgets(k, 2, stdin);
		if (horse == '1')
			process(x1, y1, counta, '1');
		else process(x2, y2, countb, '2');
	}
	else {
		printf("다음 팀 차례~ enter 키를 입력하세요\n");
		fgets(k, 2, stdin);
	}
}

void move(int n, int x, int y, int count, char horse) {// 말을 이동시키는 함수(보고서의 윷놀이판 좌표 그림을 참고해주세요)
	arr[x][y] = 'O';// 이동하기 전의 말의 위치를 윷놀이판의 'O'으로 바꾸어놓는다.

	if (x == y == 30) {//홈 // 홈이 제일 먼저 나온 이유는 좌하향과 겹쳐서 홈이 제일 먼저 출발해야 하기 때문
		x = 30 - n * 6, y = 30;
	}
	else if (x == y && x != 30) {//우하향 //우하향이 좌하향보다 먼저 나온 이유:좌하향은 (15,15)에서 우하향으로 꺾이기 때문 
		if (x + n * 5 > 30)//말이 홈에 도착한 경우
			count++, x = 30, y = 30;
		else x += n * 5, y += n * 5;
	}
	else if (x + y == 30) {//좌하향 //좌하향이 가로,세로보다 먼저 ㅏ온 이유 : 맨 오른쪽 세로가 (6,30)에서 좌하향으로 꺾이기 때문
		if (x + n * 5 > 30)
			y = (n - (30 - x) / 5) * 6, x = 30;
		else x += n * 5, y -= n * 5;
	}
	else if (y == 30) {// 맨 오른쪽 세로
		if (x - 6 * n < 0)
			y = 30 - (n - (x / 6)) * 6, x = 0;
		else x -= 6 * n;
	}
	else if (x == 0) {//맨 위쪽 가로
		if (y - 6 * n < 0)
			x = (n - y / 6) * 6, y = 0;
		else y -= n * 6;
	}
	else if (y == 0) {//맨 왼쪽 세로
		if (x + n * 6 > 30)
			y = (n - (30 - x) / 6) * 6, x = 30;
		else x += 6 * n;
	}
	else if (x == 30) {//맨 왼쪽 가로
		if (y + 6 * n > 30)
			count++, y = 30;
		else y += 6 * n;
	}

	arr[x][y] = horse;//도착한 곳에 말을 놔둔다

	if (horse == '1')//다음번에 말을 이동시키기 위해 현재 말의 좌표를 저장
		x1 = x, y1 = y;
	else x2 = x, y2 = y;
}

int check(int count1, int count2) {//도착한 말의 개수가 4일 때 0이 아닌 값을 반환하는 함수
	if (count1 == 4 && count2 == 4)//동점
		return 3;
	else if (count1 == 4)//팀1이 이긴 경우
		return 2;
	else if (count2 == 4)//팀2가 이긴 경우
		return 1;
	else return 0;
}

void end() {   // 승리를 판정해주는 함수
	if (check(counta, countb) == 3)// 동점
		printf("동점!!\n\n 게임을 이용해주셔서 감사합니다.안뇽~");
	else if (check(counta, countb) == 2)//팀1의 승리
		printf("팀1이 승리했습니다. 축하드려요\n\n 게임을 이용해주셔서 감사합니다. 안뇽~");
	else if (check(counta, countb) == 1)//팀2의 승리
		printf("팀2이 승리했습니다. 축하드려요\n\n 게임을 이용해주셔서 감사합니다. 안뇽~");
}