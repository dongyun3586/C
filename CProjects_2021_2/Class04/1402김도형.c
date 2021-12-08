#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<memory.h>
#include<Windows.h>
#include<math.h>

#define EXPCNT 1.7142135
#define WIDTH 7
#define Simulater_cnt 500

#define max(a,b)(a>b?a:b)
#define min(a,b)(a<b?a:b)

#define oo 0x7fffffff
#define plyup -8
#define plydown -7
#define plyright -6
#define plyleft -5
#define comup -4
#define comdown -3
#define comright -2
#define comleft -1
#define player 0
#define com 1

//상수들 정의 

typedef long long ll;
typedef double db;

typedef struct ab {
	int list[120], index, move;
	int chk;
	ll win, cnt, overwhelm;
	struct ab* next[120];
}node;
//MCTS 트리 노드 구조체 

ll all = 0;

db UTC(ll win, ll cnt);
void board_set();
int Tree(node* now, int role);
int MCTS();
int simulate(int role);
int shortest_path(int x, int y, int type);
int check_ps(int wallnum);
void parse_child(node* now, int type);
void show_board(int show_type);
void make_wall(int wallnum, int cases);
void free_tree(node* now);
void play_game();
void menu();
void show_notice();
int comx, comy, plyx, plyy;
short map[40][40];
int chkk[101];
int se, turn;

//게임에 사용될 함수들 및 변수들 정의  

int main()
{
	while (1)menu();
	//메뉴 화면 표시 
	return 0;
}

void show_notice()
{
	//게임 플레이 방법 소개 화면 함수 
	system("cls");
	printf("***** 게임 소개 *****\n");
	printf(" 쿼리도는 Mirko Marchesi에 의해 디자인된 게임으로 각 플레이어는 먼저 판의 다른 쪽에 도달해야 합니다.\n\n");
	printf(" 각 플레이어는 자신의 턴에 상하좌우로 움직이거나 벽을 설치해 상대방의 움직임을 방해할수 있습니다.\n\n");
	printf(" 벽은 각 플레이어가 반드시 반대편에 도달할수 있도록 설치되어야만 합니다.\n\n");
	printf(" 각 플레이어는 게임 도중 기권할수 있습니다.\n\n");
	printf(" 자세한 게임 방법은 https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=nextx500&logNo=221143487077 등을 참고하십시오.\n\n");
	printf(" * 본 게임은 원래 쿼리도 게임의 축소판으로 7*7 판을 사용하며, 사용가능한 벽의 개수에 제한이 없고, 각 플레이어는 서로를 뛰어넘을수 없습니다.\n\n");
	printf(" * 서로가 겹쳐진 상태에서는 한 플레이어의 말만이 표시됩니다.\n\n");
	printf(" * 본 게임은 사용자와 AI 대전을 지원합니다.\n\n");
	system("pause");
}

void menu()
{
	int command;
	//메뉴 화면 표시 함수 
	system("cls");
	printf("\n");
	printf("    ■■■■     ■       ■  ■■■■   ■■■■    ■■■■ ■■■        ■■■■\n");
	printf("  ■       ■    ■       ■ ■       ■ ■     ■      ■    ■     ■   ■        ■\n");
	printf("  ■       ■    ■       ■ ■       ■ ■      ■     ■    ■      ■  ■        ■\n");
	printf("  ■       ■    ■       ■ ■       ■ ■      ■     ■    ■       ■ ■        ■\n");
	printf("  ■       ■    ■       ■ ■       ■ ■■■■       ■    ■       ■ ■        ■\n");
	printf("  ■     ■■■  ■       ■ ■       ■ ■   ■        ■    ■      ■  ■        ■\n");
	printf("  ■     ■■ ■ ■       ■ ■       ■ ■    ■       ■    ■     ■   ■        ■\n");
	printf("   ■■■■■  ■ ■■■■     ■■■■  ■     ■■ ■■■■ ■■■        ■■■■\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t mini version...\n\n\n");
	printf("| 게임 방법 및 게임 설명 :1\n| 게임 시작:2\n| 게임 종료:3\n-->");
	scanf("%d", &command);
	//수행할 명령 입력 
	if (command == 1) {
		show_notice();
		//게임 방법 및 게임 설명 보여주기 
	}
	else if (command == 2) {
		play_game();
		//게임 시작하기 
	}
	else if (command == 3)exit(0);
	//게임 종료 
	else {
		printf("잘못된 입력입니다."); Sleep(2000); return;
		//다시 입력 받기 
	}
}

void play_game()
{
	system("cls");
	printf("랜덤 선공 선택 중...");
	//랜덤으로 선공 선택  
	Sleep(1000);
	system("cls");
	srand(time(NULL));
	turn = rand() % 2;
	printf("%s 선\n", turn == com ? "컴퓨터" : "플레이어");
	//결과 표시  
	system("pause");
	system("cls");
	board_set();
	//보드 초기화  
	while (1)
	{
		show_board(0);
		system("pause");
		if (turn == com) {
			//컴퓨터 턴일시 MCTS 알고리즘으로 벽 생성 또는 이동을 선택하고 이동 
			make_wall(MCTS(), 1);
			if (shortest_path(comx, comy, com) == oo || shortest_path(plyx, plyy, player) == oo) {
				printf("기권승"); exit(0);
			}
			//만약 선택된 것이 불가능한 경우일시(원래는 불가능한데 어떻게 해도 이기지 못한다면 이러한 수를 반환할수 있다.) 기권을 선언  
		}
		else {
			printf("말 이동은 1/벽 생성은 2 를 눌러주십시오/기권은 3을 눌러주십시오:");
			// 명령 안내  
			int cases; scanf("%d", &cases);
			if (cases == 1) {
				//이동 선택시 가능한 이동 방향 표시  
				int i = 0;
				int pos[4][2] = { -2,0,2,0,0,2,0,-2 };
				int cases[4] = { plyup,plydown,plyright,plyleft };
				char* types[4] = { "전진","후진","우측 이동","좌측 이동" };
				for (i = 0; i < 4; i++) {
					if (plyx + pos[i][0] >= 1 && plyx + pos[i][0] < WIDTH * 2 && plyy + pos[i][1] >= 1 && plyy + pos[i][1] < WIDTH * 2 && map[plyx + pos[i][0] / 2][plyy + pos[i][1] / 2] == 0) {
						printf("%s을 위해서는 %d를 입력하십시오\n", types[i], i);
					}
				}
				int direction; scanf("%d", &direction); make_wall(cases[direction], 1);
			}
			else if (cases == 2) {
				//벽 생성 선택시 입력 받고 싶은 벽과 위치 입력  
				printf("세로 벽을 만들고 싶다면 1을 가로 벽을 만들고 싶다면 2을 입력해주십시오:");
				int wallstyle, wallx, wally, wallnum;
				scanf("%d", &wallstyle);
				if (wallstyle == 1) {
					show_board(1);
					printf("벽은 길이가 2 입니다. 벽의 위쪽이 시작될 행과 열을 입력해주십시오:");
					scanf("%d %d", &wallx, &wally);
				}
				if (wallstyle == 2) {
					show_board(2);
					printf("벽은 길이가 2입니다. 벽의 왼쪽이 시작될 행과 열을 입력해주십시오:");
					scanf("%d %d", &wallx, &wally);
				}
				wallnum = (wallx - 1) * (WIDTH - 1) + (wally)+(wallstyle == 1 ? ((WIDTH - 1) * (WIDTH - 1)) : 0);
				//불가능한 경우들에는 불가능을 안내하고 다시 입력 받음  
				if (!check_ps(wallnum)) {
					printf("불가능한 입력입니다. 다시 입력해주시기 바랍니다.");
					Sleep(2000); continue;
				}
				make_wall(wallnum, 1);
				if (shortest_path(comx, comy, com) == oo || shortest_path(plyx, plyy, player) == oo) {
					make_wall(wallnum, 0);
					printf("불가능한 입력입니다. 상대방이 판의 끝으로 도달할 길은 존재해야 합니다. 다시 입력해주시기 바랍니다.");
					Sleep(2000); continue;
				}
			}
			else if (cases == 3) {
				//기권 선언시 패배를 표시  
				printf("YOU LOSE!!!!!\n");
				system("pause");
				break;
			}
			else {
				//다른 입력시 다시 입력 받음  
				printf("잘못된 입력입니다. 다시 입력하십시오."); Sleep(1000); continue;
			}
		}
		if (comx == WIDTH * 2 - 1 || plyx == 1) {
			//승패 결정시 보드를 보여주며 승패를 출력  
			show_board(0);
			if (turn == player)printf("YOU WIN!!!!!\n");
			else printf("YOU LOSE!!!!!\n");
			system("pause");
			return;
		}
		system("cls");
		//턴 변경  
		turn = 1 - turn;
	}
}

void board_set()
{
	//보드와 말들을 세팅  
	for (int i = 1; i < WIDTH * 2; i++) {
		for (int j = 1; j < WIDTH * 2; j++) {
			if (i % 2 == 1 && j % 2 == 1)map[i][j] = 1;
			else map[i][j] = 0;
		}
	}
	comx = 1; comy = WIDTH; plyx = WIDTH * 2 - 1; plyy = WIDTH;
}

void show_board(int show_type)
{
	//현재 보드 상태를 보여줌, show_type 1은 가로벽 생성, 2은 세로벽 생성을 의미, 각각의 상황에 대한 행과 열을 보여줌, 벽은 다른 색으로 보여줘 잘 보이게 함  
	system("cls");
	printf("\n");
	HANDLE hc = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hc, &csbi);
	for (int i = 1; i < WIDTH * 2; i++) {
		if ((show_type == 1 && i % 2 == 1) || (show_type == 2 && i % 2 == 0))printf("%2d   ", i / 2 + (show_type == 1 ? 1 : 0));
		else printf("     ");
		for (int j = 1; j < WIDTH * 2; j++) {
			if (i == comx && j == comy)printf("%s", "▲ ");
			else if (i == plyx && j == plyy)printf("%s", "△ ");
			else if (map[i][j] == 1)printf("%s", "□ ");
			else if (map[i][j] >= 2 && map[i][j] < (WIDTH - 1) * (WIDTH - 1) + 5) {
				SetConsoleTextAttribute(hc, 11);
				printf("%s", "― ");
				SetConsoleTextAttribute(hc, 7);
			}
			else if (map[i][j] >= (WIDTH - 1) * (WIDTH - 1) + 5) {
				SetConsoleTextAttribute(hc, 11);
				printf("%s", "|  ");
				SetConsoleTextAttribute(hc, 7);
			}

			else printf("   ");
		}
		printf("\n");
	}
	if (show_type == 0)printf("\n");
	else {
		printf("\n      ");
		if (show_type == 1)printf("  ");
		for (int i = 1; i <= WIDTH - (show_type == 1 ? 1 : 0); i++)printf("%d     ", i);
	}
	//기호를 안내  
	printf("\n\n%s : 플레이어, %s : 컴퓨터", "△", "▲");
	printf("\n");
}

void set_new_node(node* tmp)
{
	//새로 생성된 트리 노드의 값들을 초기화  
	tmp->index = 0;
	tmp->win = 0;
	tmp->cnt = 0;
	tmp->chk = 0;
	tmp->overwhelm = 0;
}

void parse_child(node* now, int type)
{
	//현재 노드에서 확장될수 있는 노드들을 확인하고 확장을 진행  
	int cnt = 0;
	//벽 생성 노드들  
	for (int i = 1; i <= 2 * (WIDTH - 1) * (WIDTH - 1); i++) {
		if (check_ps(i)) {
			now->list[now->index++] = i;
			now->next[now->index - 1] = (node*)malloc(sizeof(node));
			set_new_node(now->next[now->index - 1]);
		}
	}
	int pos[4][2] = { -2,0,2,0,0,2,0,-2 };
	//이동 명령 노드들  
	if (type == com) {
		int cases[4] = { comup,comdown,comright,comleft };
		for (int i = 0; i < 4; i++) {
			if (comx + pos[i][0] >= 1 && comx + pos[i][0] < WIDTH * 2 && comy + pos[i][1] >= 1 && comy + pos[i][1] < WIDTH * 2 && map[comx + pos[i][0] / 2][comy + pos[i][1] / 2] == 0) {
				now->list[now->index++] = cases[i];
				now->next[now->index - 1] = (node*)malloc(sizeof(node));
				set_new_node(now->next[now->index - 1]);
			}
		}
	}
	else {
		int cases[4] = { plyup,plydown,plyright,plyleft };
		for (int i = 0; i < 4; i++) {
			if (plyx + pos[i][0] >= 1 && plyx + pos[i][0] < WIDTH * 2 && plyy + pos[i][1] >= 1 && plyy + pos[i][1] < WIDTH * 2 && map[plyx + pos[i][0] / 2][plyy + pos[i][1] / 2] == 0) {
				now->list[now->index++] = cases[i];
				now->next[now->index - 1] = (node*)malloc(sizeof(node));
				set_new_node(now->next[now->index - 1]);
			}
		}
	}
}

int MCTS()
{
	int i, j, cntt = 0;
	//현재 상태를 의미하는 루트 노드를 생성, 자식 노드들을 생성  
	node* root = (node*)malloc(sizeof(node));
	root->win = 0; root->cnt = 0; root->index = 0;
	parse_child(root, com);
	all = 0; ll counting = 0;
	char progress[4] = { '\\','|','/','-' };
	int index = 0;
	printf("Computer turn...-");
	//총 칠십만법 MCTS 알고리즘을 진행  
	while (counting < 700000)
	{
		//만번마다 progress 상태를 표시 
		if (counting % 10000 == 0) {
			int next; double MAX = -oo; ll sum = 0;
			printf("\b");
			printf("%c", progress[index++]); index %= 4;
		}
		counting++;
		//MCTS 알고리즘 실행  
		Tree(root, player);
	}
	int next; ll MAX = -oo; ll sum = 0;
	//가장 많이 방문된 노드 확인후 선택, 리턴해줌 
	for (int i = 0; i < root->index; i++) {
		MAX = max(MAX, root->next[i]->cnt);
		if (MAX == root->next[i]->cnt) {
			next = root->list[i];
		}
	}
	//만들었던 노드들 저장 공간을 free 시켜줌 
	free_tree(root);
	return next;
}

int check_ps(int wallnum)
{
	//입력받은 명령이 가능한 명령인지를 판별  
	int walltype = 2;
	if (wallnum > (WIDTH - 1) * (WIDTH - 1)) {
		wallnum -= (WIDTH - 1) * (WIDTH - 1) + 1;
		walltype = 3;
	}
	else wallnum--;
	if (walltype == 3) {
		if (map[wallnum / (WIDTH - 1) * 2 + 1][wallnum % (WIDTH - 1) * 2 + 2] == 0 && map[wallnum / (WIDTH - 1) * 2 + 3][wallnum % (WIDTH - 1) * 2 + 2] == 0 && (map[wallnum / (WIDTH - 1) * 2 + 2][wallnum % (WIDTH - 1) * 2 + 1] != map[wallnum / (WIDTH - 1) * 2 + 2][wallnum % (WIDTH - 1) * 2 + 3] || map[wallnum / (WIDTH - 1) * 2 + 2][wallnum % (WIDTH - 1) * 2 + 3] == 0)) {
			return 1;
		}
		return 0;
	}
	else {
		if (map[wallnum / (WIDTH - 1) * 2 + 2][wallnum % (WIDTH - 1) * 2 + 1] == 0 && map[wallnum / (WIDTH - 1) * 2 + 2][wallnum % (WIDTH - 1) * 2 + 3] == 0 && (map[wallnum / (WIDTH - 1) * 2 + 1][wallnum % (WIDTH - 1) * 2 + 2] != map[wallnum / (WIDTH - 1) * 2 + 3][wallnum % (WIDTH - 1) * 2 + 2] || map[wallnum / (WIDTH - 1) * 2 + 3][wallnum % (WIDTH - 1) * 2 + 2] == 0)) {
			return 1;
		}
		return 0;
	}
}

int Tree(node* now_node, int role)
{
	now_node->chk = 1;
	//현재 노드에서 승패가 결정되었다면 승패 리턴  
	if (role == com) {
		if (comx == WIDTH * 2 - 1) {
			now_node->cnt++; now_node->win++;
			return 0;
		}
		else if (plyx == 1) {
			now_node->cnt++;
			return 1;
		}
	}
	else if (role == player) {
		if (plyx == 1) {
			now_node->win++; now_node->cnt++;
			return 0;
		}
		else if (comx == WIDTH * 2 - 1) {
			now_node->cnt++;
			return 1;
		}
	}
	double MAXIMUM = 0.0; int k, Maxindex, Maxwallnum;
	//말단 노드이며, Simulater_cnt 이상 반복했을시 노드 확장 실행  
	if (now_node->index == 0 && now_node->cnt > Simulater_cnt) {
		parse_child(now_node, role);
	}
	//말단 노드이며 충분한 시뮬레이션이 진행되지 않았을시 시뮬레이션 진행  
	else if (now_node->index == 0) {
		now_node->cnt++;
		int ans = simulate(role);
		if (ans > 0) {
			now_node->win += ans;
			return 1 - ans;
		}
		else if (ans == -1) {
			all--;
			now_node->cnt--;
			return -1;
		}
		return 1 - ans;
	}
	//자식 노드들 중 방문되지 않았거나, 가장 Selection value가 높은 노드를 선택 
	for (k = 0; k < now_node->index; k++) {
		if (now_node->next[k]->chk == 0) {
			Maxwallnum = now_node->list[k];
			Maxindex = k; break;
		}
		else {
			MAXIMUM = max(MAXIMUM, UTC(now_node->next[k]->win, now_node->next[k]->cnt));
			if (MAXIMUM == UTC(now_node->next[k]->win, now_node->next[k]->cnt)) {
				Maxindex = k; Maxwallnum = now_node->list[k];
			}
		}
	}
	//선택된 노드로 진행 및 보드 상태 변경 
	make_wall(Maxwallnum, 1);
	se = Maxwallnum;
	int ans = Tree(now_node->next[Maxindex], 1 - role);
	// 보드 상태 정상화  
	if (ans == -1) {
		make_wall(Maxwallnum, 0);
		return -1;
	}
	now_node->cnt++; now_node->win += ans;
	make_wall(Maxwallnum, 0);
	return 1 - ans;
}

db UTC(ll win, ll cnt)
{
	//selection value 리턴  
	if (cnt == 0)cnt = all / 2;
	return (double)win / cnt + EXPCNT * (double)sqrt((double)log(all) / cnt);
}

void make_wall(int wallnum, int cases)
{
	//입력받은 명령을 수행(벽 색성 및 말 이동) 
	int walltype = 2;
	if (wallnum < 0) {
		if (wallnum == comup)comx += cases ? -2 : 2;
		if (wallnum == comdown)comx -= cases ? -2 : 2;
		if (wallnum == comleft)comy -= cases ? 2 : -2;
		if (wallnum == comright)comy += cases ? 2 : -2;
		if (wallnum == plyup)plyx += cases ? -2 : 2;
		if (wallnum == plydown)plyx -= cases ? -2 : 2;
		if (wallnum == plyleft)plyy -= cases ? 2 : -2;
		if (wallnum == plyright)plyy += cases ? 2 : -2;
		return;
	}
	if (wallnum > (WIDTH - 1) * (WIDTH - 1)) {
		wallnum -= (WIDTH - 1) * (WIDTH - 1) + 1;
		walltype = 3;
	}
	else wallnum--;
	if (walltype == 2) {
		map[wallnum / (WIDTH - 1) * 2 + 2][wallnum % (WIDTH - 1) * 2 + 1] = map[wallnum / (WIDTH - 1) * 2 + 2][wallnum % (WIDTH - 1) * 2 + 3] = (wallnum + 5) * cases;
	}
	else {
		map[wallnum / (WIDTH - 1) * 2 + 1][wallnum % (WIDTH - 1) * 2 + 2] = map[wallnum / (WIDTH - 1) * 2 + 3][wallnum % (WIDTH - 1) * 2 + 2] = (wallnum + (WIDTH - 1) * (WIDTH - 1) + 5) * cases;
	}
}
int simulate(int role)
{
	//현재 보드 상태에서 시뮬레이션을 수행
	// 최대 2개의 벽을 생성하며 경우에 따라 더 적은 벽을 생성하기도 함  
	chkk[se]++;
	all++;
	int queue[11], index = 0;
	int first = shortest_path(comx, comy, com) - 1, second = shortest_path(plyx, plyy, player) - 1, tmp = min(first, second);
	int checke = 1;

	int range = min(4, tmp);

	for (int i = 0; i < range - 2; i++) {
		int random = rand() % (2 * (WIDTH - 1) * (WIDTH - 1)) + 1;
		if (check_ps(random)) {
			queue[index++] = random;
			make_wall(random, 1);
		}
	}
	//랜덤으로 몇개의 벽을 생성한 후 각 말들이 반대편에 도달하기 위한 최단 거리를 확인  
	int a = shortest_path(1 - role ? plyx : comx, 1 - role ? plyy : comy, role), b = shortest_path(1 - role ? comx : plyx, 1 - role ? comy : plyy, 1 - role);

	//랜덤으로 생성하 벽이 룰을 위반한다면 해당 시뮬레이션은 무효화  
	if (a == oo || b == oo) {
		for (int i = 0; i < index; i++)make_wall(queue[i], 0);
		return -1;
	}
	//랜덤 생성 후 상태에 대한 승패 판별  
	int check = (a + (index) % 2 < b);
	for (int i = 0; i < index; i++)make_wall(queue[i], 0);
	return check;
}

int shortest_path(int x, int y, int type)
{
	//bfs를 통한 각 말들의 반대편에 도달하기 위한 최단 거리를 확인  
	int sx = x, sy = y;
	int visit[WIDTH * 2 + 1][WIDTH * 2 + 1] = { 0, };
	int queue[200][2], index = 0, now = 0;
	queue[index][0] = x; queue[index][1] = y;
	visit[x][y] = 1;
	index++;
	//bfs 수행  
	while (now < index) {
		x = queue[now][0]; y = queue[now][1];
		now++;
		if (x + 2 <= WIDTH * 2 - 1 && map[x + 1][y] == 0 && visit[x + 2][y] == 0) {
			visit[x + 2][y] = visit[x][y] + 1;
			queue[index][0] = x + 2; queue[index][1] = y;
			index++;
		}
		if (x - 2 >= 1 && map[x - 1][y] == 0 && visit[x - 2][y] == 0) {
			visit[x - 2][y] = visit[x][y] + 1;
			queue[index][0] = x - 2; queue[index][1] = y;
			index++;
		}
		if (y + 2 <= WIDTH * 2 - 1 && map[x][y + 1] == 0 && visit[x][y + 2] == 0) {
			visit[x][y + 2] = visit[x][y] + 1;
			queue[index][0] = x; queue[index][1] = y + 2;
			index++;
		}
		if (y - 2 >= 1 && map[x][y - 1] == 0 && visit[x][y - 2] == 0) {
			visit[x][y - 2] = visit[x][y] + 1;
			queue[index][0] = x; queue[index][1] = y - 2;
			index++;
		}
	}
	int Min = oo;
	for (int i = 1; i <= WIDTH * 2 - 1; i += 2) {
		if (visit[type ? WIDTH * 2 - 1 : 1][i] == 0)continue;
		Min = min(Min, visit[type ? WIDTH * 2 - 1 : 1][i]);
	}
	return Min;
}

void free_tree(node* now)
{
	//할당한 메모리들을 free 시켜줌  
	if (now->index == 0) {
		free(now);
		return;
	}
	for (int i = 0; i < now->index; i++) {
		free_tree(now->next[i]);
	}
	free(now);
}
