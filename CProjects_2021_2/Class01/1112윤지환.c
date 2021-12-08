#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int sch[18][11];//��� ������. �� ���� ���� ��� 3 2 1 8 10 9 7 6 5 4 ��� �̳��� 3���� 2��, 1���� 8��, 10���� 9��, 7���� 6��, 5���� 4������ ����ϰ� ��.
int day = 0;//�� n���� ���

struct A {
    char team[20];//�� �̸�
    char park[5];//Ȩ ����
    int win;//�� ��
    int draw;//�� ��
    int lose;//���º� ��
    float rate;//�·�
    int relativerecord[11];//��� ����-������ �ʿ� relativerecord[i]�� i��° ���� ���� �¸��� Ƚ��
    int relativescore[11];//��� ����- ������ �ʿ�
};
struct A s[11] = { {""},{"KIA Ÿ�̰���","����"},{"�λ� ���","���"},{"�Ե� ���̾���","����"},{"NC ���̳뽺","â��"},{"SSG ������","����"},{"LG Ʈ����","���"},{"Ű�� �������","��ô"},{"��ȭ �̱۽�","����"},{"�Ｚ ���̿���","�뱸"},{"KT ����","����"} };

void input();
void pennantrace();//���� ���� ����
void set(int num);
void game(int teamA, int teamB);//�� ��� ����
int overtime(int r);//���º��϶� ������
int score(int r);//��⿡�� ���� ��ȯ
void sort();//���� ���� ���� ����
void swap(int teamA, int teamB);
void pennantraceresult();//���Խ��� ��� ���
void tiebreaker();//1���� ���� �϶� Ÿ�̺극��Ŀ
void tie(int a);//�������� �����϶� ���� ���ϱ�
void postseason();//����Ʈ ���� ��� ����
void postseasongame(int teamA, int teamB, int* win, int* draw, int* lose);//����Ʈ���𿡼��� ���� ����. game �Լ��� ����ϳ� ��� ����,���� ���� ����� �ʿ䰡 ���� ���� ����
int wildcard(int teamA, int teamB);//���ϵ� ī�� ������
int playoff(int teamA, int teamB);//���÷��̿���,�÷��̿��� ����
int KS(int teamA, int teamB);//�ѱ��ø���
void postseasonresult(int winner, int playoffwinner);//���� ����

int main() {
    srand(time(NULL));
    input();
    pennantrace();
    sort();
    pennantraceresult();
    postseason();
    return 0;
}

void input() {
    FILE* fp;
    fp = fopen("schedule.txt", "r");
    for (int i = 0; i < 18; i++)
        for (int j = 0; j < 11; j++)
            fscanf(fp, "%d", &sch[i][j]);//���� �ؽ�Ʈ���Ϸ� ������ �� ��� �������� ������ ��. �ʹ� ��� ���� ������
    fclose(fp);
}

void pennantrace() {
    printf("[KBO ���� ���� ����]\n\n");
    Sleep(1000);
    set(3);//3����
    set(3);//3����
    set(2);//2����
    for (int i = 1; i <= 10; i++)
        s[i].rate = (float)s[i].win / ((float)s[i].win + (float)s[i].lose);//�·�=��/(��+��)
}

void set(int num) {
    int a, b;
    for (int i = 0; i < 18; i++) {
        for (int k = 1; k <= num; k++) {//num ����
            day++;
            printf("[��%d ���]\n", day);
            for (int j = 1; j <= 5; j++) {//�Ϸ翡 ������ 5���
                a = sch[i][j * 2 - 1];
                b = sch[i][j * 2];
                game(a, b);
            }
            printf("\n\n");
        }
    }
}

void game(int teamA, int teamB) {//��� ����� ���� �Լ�
    int a = score(rand() % 100);//a���� ����
    int b = score(rand() % 100);//b���� ����
    printf("<%s>\n%-15s vs %15s\n", s[teamB].park, s[teamA].team, s[teamB].team);
    if (a == b) {//������ �� ���ºθ� ���̱� ���� ������ �߰���
        a += overtime(rand() % 100);
        b += overtime(rand() % 100);
    }
    if (a > b) {//a�� �¸�
        printf("%2d : %2d  %15s �¸�!\n\n", a, b, s[teamA].team);
        s[teamA].win++;
        s[teamB].lose++;
        s[teamA].relativerecord[teamB]++;
    }
    else if (a < b) {//b�� �¸�
        printf("%2d : %2d  %15s �¸�!\n\n", a, b, s[teamB].team);
        s[teamA].lose++;
        s[teamB].win++;
        s[teamB].relativerecord[teamA]++;
    }
    else if (a == b) {//���� �߰��ص� ���º��϶�
        printf("%2d : %2d  ���º�\n\n", a, b);
        s[teamA].draw++;
        s[teamB].draw++;
    }
    s[teamA].relativescore[teamB] += a;
    s[teamB].relativescore[teamA] += b;
}

int overtime(int r) {//���º��� �� ���� �߰�
    int sum = 0;
    int p[6] = { 20,30,20,15,10,5 };//i���� �߰��� Ȯ���� p[i]%
    for (int i = 0; i <= 5; i++) {
        sum += p[i];
        if (r <= sum)
            return i;
    }
    return 0;
}

int score(int r) {//������ ��ȯ����
    int sum = 0;
    int p[30] = { 7,7,8,10,13,10,8,7,5,4,4,3,3,2,2,2,1,1,1,1,1 };//�� ������ Ȯ��. ������ i�� Ȯ���� p[i]%��
    for (int i = 0; i <= 20; i++) {
        sum += p[i];
        if (r <= sum)
            return i;
    }
    return 0;
}

void sort() {//1������ 10������ �·��� ���� ����
    for (int i = 10; i > 1; i--) {
        for (int j = 1; j < i; j++)
        {
            if (s[j].rate < s[j + 1].rate)
            {
                swap(j, j + 1);
            }
        }
    }
}

void swap(int teamA, int teamB) {
    for (int i = 1; i <= 10; i++) {//�� ������ �ٲ޿� ���� ��� ���� ������ �ٲ����
        s[i].relativerecord[0] = s[i].relativerecord[teamA];
        s[i].relativerecord[teamA] = s[i].relativerecord[teamB];
        s[i].relativerecord[teamB] = s[i].relativerecord[0];
        s[i].relativescore[0] = s[i].relativescore[teamA];
        s[i].relativescore[teamA] = s[i].relativescore[teamB];
        s[i].relativescore[teamB] = s[i].relativescore[0];
    }
    s[0] = s[teamA];//���� ������ �ٲ�
    s[teamA] = s[teamB];
    s[teamB] = s[0];
}

void pennantraceresult() {
    if (s[1].rate == s[2].rate) {//���Խ��� 1 2�� ������ ��
        if (s[2].rate != s[3].rate) {
            Sleep(2000);
            tiebreaker();//Ÿ�̺극��Ŀ ���
        }
    }
    else {//�������� ���� �϶�
        for (int i = 2; i < 10; i++)
            if (s[i].rate == s[i + 1].rate)
                tie(i);
    }

    Sleep(2000);
    printf("[KBO ���� ���Խ��� ����]\n");
    for (int i = 1; i <= 10; i++)
        printf("%2d�� %-15s %3d�� %3d�� %3d�� �·� %.3f\n", i, s[i].team, s[i].win, s[i].draw, s[i].lose, s[i].rate);
    printf("\n\n");
}

void tiebreaker() {//���Խ��� 1 2���� �·��� �����϶�
    int a = score(rand() % 100);
    int b = score(rand() % 100);
    printf("[���Խ��� 1�� ������]\n");
    Sleep(1000);
    printf("%-15s vs %15s\n", s[1].team, s[2].team);
    while (a == b) {//���Խ��� ���� �޸� �ºΰ� ������ �� ���� ���
        a += overtime(rand() % 100);
        b += overtime(rand() % 100);
        if (a != b)
            break;
    }
    if (a > b)
        printf("%2d : %2d  %15s �¸�!\n\n", a, b, s[1].team);
    else if (a < b) {
        printf("%2d : %2d  %15s �¸�!\n\n", a, b, s[2].team);
        swap(1, 2);
    }
}

void tie(int a) {//������ ��
    Sleep(1000);
    printf("<���� ����>\n%-15s vs %15s\n������� %2d�� : %2d��\n\n", s[a].team, s[a + 1].team, s[a].relativerecord[a + 1], s[a + 1].relativerecord[a]);
    if (s[a].relativerecord[a + 1] < s[a + 1].relativerecord[a]) {//��� ���� ��
        swap(a, a + 1);
    }
    else if (s[a].relativerecord[a + 1] == s[a + 1].relativerecord[a]) {//��� ���� ���� �� ��� ���� ��
        printf("������ %3d�� : %3d��\n\n", s[a].relativescore[a + 1], s[a + 1].relativescore[a]);
        if (s[a].relativescore[a + 1] < s[a + 1].relativescore[a])
            swap(a, a + 1);
    }
    printf("%-15s %2d��\n%-15s %2d��\n\n", s[a].team, a, s[a + 1].team, a + 1);
}

void postseason() {
    Sleep(2000);
    printf("[KBO ����Ʈ����]\n\n");
    printf("�ѱ��ø���       ������������������\n");//����Ʈ���� ����ǥ
    printf("                 ��     %s\n", s[1].team);
    printf("                 ��\n");
    printf("PO           ������������������\n");
    printf("             ��     %s\n", s[2].team);
    printf("             ��\n");
    printf("��PO    ������������������\n");
    printf("        ��     %s\n", s[3].team);
    printf("        ��\n");
    printf("WC  ������������������\n");
    printf("    ��     %s\n", s[4].team);
    printf("    ��\n");
    printf("   %s\n\n\n", s[5].team);
    Sleep(2000);
    printf("[KBO ���ϵ�ī�� ������]\n%s vs %s\n\n", s[4].team, s[5].team);
    Sleep(1000);
    int winner = wildcard(4, 5);//winner=�������� ������
    Sleep(1000);
    printf("%s ���÷��̿��� ����!\n\n\n\n", s[winner].team);
    Sleep(2000);
    printf("[KBO ���÷��̿���]\n%s vs %s\n\n", s[3].team, s[winner].team);
    Sleep(1000);
    winner = playoff(3, winner);
    Sleep(1000);
    printf("%s �÷��̿��� ����!\n\n\n\n", s[winner].team);
    Sleep(2000);
    printf("[KBO �÷��̿���]\n%s vs %s\n\n", s[2].team, s[winner].team);
    Sleep(1000);
    winner = playoff(2, winner);
    int playoffwinner = winner;
    Sleep(1000);
    printf("%s �ѱ��ø��� ����!\n\n\n\n", s[winner].team);
    Sleep(2000);
    printf("[KBO �ѱ��ø���]\n%s vs %s\n\n", s[1].team, s[winner].team);
    Sleep(1000);
    winner = KS(1, winner);
    Sleep(1000);
    printf("%s �ѱ��ø��� ���!\n\n\n", s[winner].team);
    postseasonresult(winner, playoffwinner);
    Sleep(2000);
    printf("[KBO ���� ���� ����]\n");
    for (int i = 1; i <= 10; i++)
        printf("%2d�� %-15s\n", i, s[i].team);
    printf("\n\n");
    if (strcmp(s[1].team, "KIA Ÿ�̰���") == 0)//��� ��½� �ΰ� ���
    {
        FILE* fp = fopen("KIA TIGERS.txt", "r");
        char s[60][100] = { "" };
        for (int i = 0; i < 60; i++) {
            fgets(s[i], sizeof(s[i]), fp);
            printf("%s\n", s[i]);
        }
        fclose(fp);
    }
    printf("\n\n");
}

void postseasonresult(int winner, int playoffwinner) {
    //1��-�ѱ��ø��� ����� 2��-�ѱ��ø��� �ؿ���� ������-������
    if (winner == playoffwinner) {//���¿�� �� ���
        s[0] = s[winner];
        for (int i = winner; i >= 2; i--)
            s[i] = s[i - 1];
        s[1] = s[0];
    }
    else {//���Խ��� 1���� ����� ���
        s[0] = s[playoffwinner];
        for (int i = playoffwinner; i > 2; i--)
            s[i] = s[i - 1];
        s[2] = s[0];
    }
}

void postseasongame(int teamA, int teamB, int* win, int* draw, int* lose) {
    //���Խ����� ���� ���� ���� ��� ����, �������� ���� ��ȯ�� �ʿ䰡 ���� ���� ����
    int a = score(rand() % 100);
    int b = score(rand() % 100);
    printf("<%s>\n%-15s vs %15s\n", s[teamB].park, s[teamA].team, s[teamB].team);
    if (a == b) {
        a += overtime(rand() % 100);
        b += overtime(rand() % 100);
    }
    if (a > b) {
        printf("%2d : %2d  %15s �¸�!\n\n", a, b, s[teamA].team);
        (*win)++;
    }
    else if (a < b) {
        printf("%2d : %2d  %15s �¸�!\n\n", a, b, s[teamB].team);
        (*lose)++;
    }
    else if (a == b) {
        printf("%2d : %2d  ���º�\n\n", a, b);
        (*draw)++;
    }
    Sleep(600);
}

int wildcard(int teamA, int teamB) {
    int win = 0, draw = 0, lose = 0;//���Խ��� 4������ �� �� ��
    printf("���ϵ� ī�� ������ �� 1���\n");
    postseasongame(teamB, teamA, &lose, &draw, &win);
    if (win == 1 || draw == 1)//1�� �Ǵ� 1��- ���Խ��� 4���� �¸�
        return teamA;
    printf("���ϵ� ī�� ������ �� 2���\n");
    postseasongame(teamB, teamA, &lose, &draw, &win);
    if (lose == 2)//2�н� ���Խ��� 5���� �¸�
        return teamB;
    return teamA;//1�� 1�� �Ǵ� 1�� 1��-���Խ��� 4���� �¸�

}

int playoff(int teamA, int teamB) {//���÷��̿����� �÷��̿���. �������� �����ؼ� �ϳ��� ����
    int win = 0, draw = 0, lose = 0, i = 1;//������(teamA)�� �� �� ��
    for (int x = 1; x <= 2; x++) {//1~2����
        if (teamA == 3)
            printf("��");
        printf("�÷��̿��� �� %d���\n", i++);
        postseasongame(teamB, teamA, &lose, &draw, &win);
    }
    for (int x = 1; x <= 2; x++) {//3~4����
        if (teamA == 3)
            printf("��");
        printf("�÷��̿��� �� %d���\n", i++);
        postseasongame(teamA, teamB, &win, &draw, &lose);
        if (win == 3)
            return teamA;
        if (lose == 3)
            return teamB;
    }
    if (teamA == 3)
        printf("��");
    printf("�÷��̿��� �� %d���\n", i++);//5����
    postseasongame(teamB, teamA, &lose, &draw, &win);
    while (win == lose) {//5���� ���� �ºΰ� ���� ���� ��
        if (teamA == 3)
            printf("��");
        printf("�÷��̿��� �� %d���\n", i++);
        postseasongame(teamB, teamA, &lose, &draw, &win);
    }
    if (win > lose)
        return teamA;
    else if (lose > win)
        return teamB;
}

int KS(int teamA, int teamB) {
    int win = 0, draw = 0, lose = 0, i = 1;

    for (int x = 1; x <= 2; x++) {//1~2����. ���Խ��� 1���� Ȩ����
        printf("�ѱ��ø��� �� %d���\n", i++);
        postseasongame(teamB, teamA, &lose, &draw, &win);
    }
    for (int x = 1; x <= 2; x++) {//3~4����. �÷��̿��� �¸��� Ȩ����
        printf("�ѱ��ø��� �� %d���\n", i++);
        postseasongame(teamA, teamB, &win, &draw, &lose);
    }
    for (int x = 1; x <= 3; x++) {//5~7����. ���Խ��� 1���� Ȩ����
        if (win == 4)
            return teamA;
        if (lose == 4)
            return teamB;//�׹�° ������ �ø�� ���� �� ����
        printf("�ѱ��ø��� �� %d���\n", i++);
        postseasongame(teamB, teamA, &lose, &draw, &win);
    }
    while (win == lose) {//7�������� �ºΰ� �������� �ʾ��� ��
        printf("�ѱ��ø��� �� %d���\n", i++);
        postseasongame(teamB, teamA, &lose, &draw, &win);
    }
    if (win > lose)
        return teamA;
    else if (lose > win)
        return teamB;
}
