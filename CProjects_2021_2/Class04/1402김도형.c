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

//����� ���� 

typedef long long ll;
typedef double db;

typedef struct ab {
	int list[120], index, move;
	int chk;
	ll win, cnt, overwhelm;
	struct ab* next[120];
}node;
//MCTS Ʈ�� ��� ����ü 

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

//���ӿ� ���� �Լ��� �� ������ ����  

int main()
{
	while (1)menu();
	//�޴� ȭ�� ǥ�� 
	return 0;
}

void show_notice()
{
	//���� �÷��� ��� �Ұ� ȭ�� �Լ� 
	system("cls");
	printf("***** ���� �Ұ� *****\n");
	printf(" �������� Mirko Marchesi�� ���� �����ε� �������� �� �÷��̾�� ���� ���� �ٸ� �ʿ� �����ؾ� �մϴ�.\n\n");
	printf(" �� �÷��̾�� �ڽ��� �Ͽ� �����¿�� �����̰ų� ���� ��ġ�� ������ �������� �����Ҽ� �ֽ��ϴ�.\n\n");
	printf(" ���� �� �÷��̾ �ݵ�� �ݴ��� �����Ҽ� �ֵ��� ��ġ�Ǿ�߸� �մϴ�.\n\n");
	printf(" �� �÷��̾�� ���� ���� ����Ҽ� �ֽ��ϴ�.\n\n");
	printf(" �ڼ��� ���� ����� https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=nextx500&logNo=221143487077 ���� �����Ͻʽÿ�.\n\n");
	printf(" * �� ������ ���� ������ ������ ��������� 7*7 ���� ����ϸ�, ��밡���� ���� ������ ������ ����, �� �÷��̾�� ���θ� �پ������ �����ϴ�.\n\n");
	printf(" * ���ΰ� ������ ���¿����� �� �÷��̾��� ������ ǥ�õ˴ϴ�.\n\n");
	printf(" * �� ������ ����ڿ� AI ������ �����մϴ�.\n\n");
	system("pause");
}

void menu()
{
	int command;
	//�޴� ȭ�� ǥ�� �Լ� 
	system("cls");
	printf("\n");
	printf("    �����     ��       ��  �����   �����    ����� ����        �����\n");
	printf("  ��       ��    ��       �� ��       �� ��     ��      ��    ��     ��   ��        ��\n");
	printf("  ��       ��    ��       �� ��       �� ��      ��     ��    ��      ��  ��        ��\n");
	printf("  ��       ��    ��       �� ��       �� ��      ��     ��    ��       �� ��        ��\n");
	printf("  ��       ��    ��       �� ��       �� �����       ��    ��       �� ��        ��\n");
	printf("  ��     ����  ��       �� ��       �� ��   ��        ��    ��      ��  ��        ��\n");
	printf("  ��     ��� �� ��       �� ��       �� ��    ��       ��    ��     ��   ��        ��\n");
	printf("   ������  �� �����     �����  ��     ��� ����� ����        �����\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t mini version...\n\n\n");
	printf("| ���� ��� �� ���� ���� :1\n| ���� ����:2\n| ���� ����:3\n-->");
	scanf("%d", &command);
	//������ ��� �Է� 
	if (command == 1) {
		show_notice();
		//���� ��� �� ���� ���� �����ֱ� 
	}
	else if (command == 2) {
		play_game();
		//���� �����ϱ� 
	}
	else if (command == 3)exit(0);
	//���� ���� 
	else {
		printf("�߸��� �Է��Դϴ�."); Sleep(2000); return;
		//�ٽ� �Է� �ޱ� 
	}
}

void play_game()
{
	system("cls");
	printf("���� ���� ���� ��...");
	//�������� ���� ����  
	Sleep(1000);
	system("cls");
	srand(time(NULL));
	turn = rand() % 2;
	printf("%s ��\n", turn == com ? "��ǻ��" : "�÷��̾�");
	//��� ǥ��  
	system("pause");
	system("cls");
	board_set();
	//���� �ʱ�ȭ  
	while (1)
	{
		show_board(0);
		system("pause");
		if (turn == com) {
			//��ǻ�� ���Ͻ� MCTS �˰������� �� ���� �Ǵ� �̵��� �����ϰ� �̵� 
			make_wall(MCTS(), 1);
			if (shortest_path(comx, comy, com) == oo || shortest_path(plyx, plyy, player) == oo) {
				printf("��ǽ�"); exit(0);
			}
			//���� ���õ� ���� �Ұ����� ����Ͻ�(������ �Ұ����ѵ� ��� �ص� �̱��� ���Ѵٸ� �̷��� ���� ��ȯ�Ҽ� �ִ�.) ����� ����  
		}
		else {
			printf("�� �̵��� 1/�� ������ 2 �� �����ֽʽÿ�/����� 3�� �����ֽʽÿ�:");
			// ��� �ȳ�  
			int cases; scanf("%d", &cases);
			if (cases == 1) {
				//�̵� ���ý� ������ �̵� ���� ǥ��  
				int i = 0;
				int pos[4][2] = { -2,0,2,0,0,2,0,-2 };
				int cases[4] = { plyup,plydown,plyright,plyleft };
				char* types[4] = { "����","����","���� �̵�","���� �̵�" };
				for (i = 0; i < 4; i++) {
					if (plyx + pos[i][0] >= 1 && plyx + pos[i][0] < WIDTH * 2 && plyy + pos[i][1] >= 1 && plyy + pos[i][1] < WIDTH * 2 && map[plyx + pos[i][0] / 2][plyy + pos[i][1] / 2] == 0) {
						printf("%s�� ���ؼ��� %d�� �Է��Ͻʽÿ�\n", types[i], i);
					}
				}
				int direction; scanf("%d", &direction); make_wall(cases[direction], 1);
			}
			else if (cases == 2) {
				//�� ���� ���ý� �Է� �ް� ���� ���� ��ġ �Է�  
				printf("���� ���� ����� �ʹٸ� 1�� ���� ���� ����� �ʹٸ� 2�� �Է����ֽʽÿ�:");
				int wallstyle, wallx, wally, wallnum;
				scanf("%d", &wallstyle);
				if (wallstyle == 1) {
					show_board(1);
					printf("���� ���̰� 2 �Դϴ�. ���� ������ ���۵� ��� ���� �Է����ֽʽÿ�:");
					scanf("%d %d", &wallx, &wally);
				}
				if (wallstyle == 2) {
					show_board(2);
					printf("���� ���̰� 2�Դϴ�. ���� ������ ���۵� ��� ���� �Է����ֽʽÿ�:");
					scanf("%d %d", &wallx, &wally);
				}
				wallnum = (wallx - 1) * (WIDTH - 1) + (wally)+(wallstyle == 1 ? ((WIDTH - 1) * (WIDTH - 1)) : 0);
				//�Ұ����� ���鿡�� �Ұ����� �ȳ��ϰ� �ٽ� �Է� ����  
				if (!check_ps(wallnum)) {
					printf("�Ұ����� �Է��Դϴ�. �ٽ� �Է����ֽñ� �ٶ��ϴ�.");
					Sleep(2000); continue;
				}
				make_wall(wallnum, 1);
				if (shortest_path(comx, comy, com) == oo || shortest_path(plyx, plyy, player) == oo) {
					make_wall(wallnum, 0);
					printf("�Ұ����� �Է��Դϴ�. ������ ���� ������ ������ ���� �����ؾ� �մϴ�. �ٽ� �Է����ֽñ� �ٶ��ϴ�.");
					Sleep(2000); continue;
				}
			}
			else if (cases == 3) {
				//��� ����� �й踦 ǥ��  
				printf("YOU LOSE!!!!!\n");
				system("pause");
				break;
			}
			else {
				//�ٸ� �Է½� �ٽ� �Է� ����  
				printf("�߸��� �Է��Դϴ�. �ٽ� �Է��Ͻʽÿ�."); Sleep(1000); continue;
			}
		}
		if (comx == WIDTH * 2 - 1 || plyx == 1) {
			//���� ������ ���带 �����ָ� ���и� ���  
			show_board(0);
			if (turn == player)printf("YOU WIN!!!!!\n");
			else printf("YOU LOSE!!!!!\n");
			system("pause");
			return;
		}
		system("cls");
		//�� ����  
		turn = 1 - turn;
	}
}

void board_set()
{
	//����� ������ ����  
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
	//���� ���� ���¸� ������, show_type 1�� ���κ� ����, 2�� ���κ� ������ �ǹ�, ������ ��Ȳ�� ���� ��� ���� ������, ���� �ٸ� ������ ������ �� ���̰� ��  
	system("cls");
	printf("\n");
	HANDLE hc = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hc, &csbi);
	for (int i = 1; i < WIDTH * 2; i++) {
		if ((show_type == 1 && i % 2 == 1) || (show_type == 2 && i % 2 == 0))printf("%2d   ", i / 2 + (show_type == 1 ? 1 : 0));
		else printf("     ");
		for (int j = 1; j < WIDTH * 2; j++) {
			if (i == comx && j == comy)printf("%s", "�� ");
			else if (i == plyx && j == plyy)printf("%s", "�� ");
			else if (map[i][j] == 1)printf("%s", "�� ");
			else if (map[i][j] >= 2 && map[i][j] < (WIDTH - 1) * (WIDTH - 1) + 5) {
				SetConsoleTextAttribute(hc, 11);
				printf("%s", "�� ");
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
	//��ȣ�� �ȳ�  
	printf("\n\n%s : �÷��̾�, %s : ��ǻ��", "��", "��");
	printf("\n");
}

void set_new_node(node* tmp)
{
	//���� ������ Ʈ�� ����� ������ �ʱ�ȭ  
	tmp->index = 0;
	tmp->win = 0;
	tmp->cnt = 0;
	tmp->chk = 0;
	tmp->overwhelm = 0;
}

void parse_child(node* now, int type)
{
	//���� ��忡�� Ȯ��ɼ� �ִ� ������ Ȯ���ϰ� Ȯ���� ����  
	int cnt = 0;
	//�� ���� ����  
	for (int i = 1; i <= 2 * (WIDTH - 1) * (WIDTH - 1); i++) {
		if (check_ps(i)) {
			now->list[now->index++] = i;
			now->next[now->index - 1] = (node*)malloc(sizeof(node));
			set_new_node(now->next[now->index - 1]);
		}
	}
	int pos[4][2] = { -2,0,2,0,0,2,0,-2 };
	//�̵� ��� ����  
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
	//���� ���¸� �ǹ��ϴ� ��Ʈ ��带 ����, �ڽ� ������ ����  
	node* root = (node*)malloc(sizeof(node));
	root->win = 0; root->cnt = 0; root->index = 0;
	parse_child(root, com);
	all = 0; ll counting = 0;
	char progress[4] = { '\\','|','/','-' };
	int index = 0;
	printf("Computer turn...-");
	//�� ĥ�ʸ��� MCTS �˰����� ����  
	while (counting < 700000)
	{
		//�������� progress ���¸� ǥ�� 
		if (counting % 10000 == 0) {
			int next; double MAX = -oo; ll sum = 0;
			printf("\b");
			printf("%c", progress[index++]); index %= 4;
		}
		counting++;
		//MCTS �˰��� ����  
		Tree(root, player);
	}
	int next; ll MAX = -oo; ll sum = 0;
	//���� ���� �湮�� ��� Ȯ���� ����, �������� 
	for (int i = 0; i < root->index; i++) {
		MAX = max(MAX, root->next[i]->cnt);
		if (MAX == root->next[i]->cnt) {
			next = root->list[i];
		}
	}
	//������� ���� ���� ������ free ������ 
	free_tree(root);
	return next;
}

int check_ps(int wallnum)
{
	//�Է¹��� ����� ������ ��������� �Ǻ�  
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
	//���� ��忡�� ���а� �����Ǿ��ٸ� ���� ����  
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
	//���� ����̸�, Simulater_cnt �̻� �ݺ������� ��� Ȯ�� ����  
	if (now_node->index == 0 && now_node->cnt > Simulater_cnt) {
		parse_child(now_node, role);
	}
	//���� ����̸� ����� �ùķ��̼��� ������� �ʾ����� �ùķ��̼� ����  
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
	//�ڽ� ���� �� �湮���� �ʾҰų�, ���� Selection value�� ���� ��带 ���� 
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
	//���õ� ���� ���� �� ���� ���� ���� 
	make_wall(Maxwallnum, 1);
	se = Maxwallnum;
	int ans = Tree(now_node->next[Maxindex], 1 - role);
	// ���� ���� ����ȭ  
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
	//selection value ����  
	if (cnt == 0)cnt = all / 2;
	return (double)win / cnt + EXPCNT * (double)sqrt((double)log(all) / cnt);
}

void make_wall(int wallnum, int cases)
{
	//�Է¹��� ����� ����(�� ���� �� �� �̵�) 
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
	//���� ���� ���¿��� �ùķ��̼��� ����
	// �ִ� 2���� ���� �����ϸ� ��쿡 ���� �� ���� ���� �����ϱ⵵ ��  
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
	//�������� ��� ���� ������ �� �� ������ �ݴ��� �����ϱ� ���� �ִ� �Ÿ��� Ȯ��  
	int a = shortest_path(1 - role ? plyx : comx, 1 - role ? plyy : comy, role), b = shortest_path(1 - role ? comx : plyx, 1 - role ? comy : plyy, 1 - role);

	//�������� ������ ���� ���� �����Ѵٸ� �ش� �ùķ��̼��� ��ȿȭ  
	if (a == oo || b == oo) {
		for (int i = 0; i < index; i++)make_wall(queue[i], 0);
		return -1;
	}
	//���� ���� �� ���¿� ���� ���� �Ǻ�  
	int check = (a + (index) % 2 < b);
	for (int i = 0; i < index; i++)make_wall(queue[i], 0);
	return check;
}

int shortest_path(int x, int y, int type)
{
	//bfs�� ���� �� ������ �ݴ��� �����ϱ� ���� �ִ� �Ÿ��� Ȯ��  
	int sx = x, sy = y;
	int visit[WIDTH * 2 + 1][WIDTH * 2 + 1] = { 0, };
	int queue[200][2], index = 0, now = 0;
	queue[index][0] = x; queue[index][1] = y;
	visit[x][y] = 1;
	index++;
	//bfs ����  
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
	//�Ҵ��� �޸𸮵��� free ������  
	if (now->index == 0) {
		free(now);
		return;
	}
	for (int i = 0; i < now->index; i++) {
		free_tree(now->next[i]);
	}
	free(now);
}
