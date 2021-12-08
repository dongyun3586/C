#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define MAXTEAM 10000 // �ִ�� ������ ���� ����� ��
#define MAXPLAYER 100 // �ִ�� �Է� ������ �÷��̾� ��
#define MAXPLAYERNAME 100 // ���� �̸� �ִ� ���ڼ�
#define NOG 82 // number of games - NBA �ѽ��� ����: 82���
#define NOS 127 // number of shots - NBA �Ѱ�� ��� ���� �õ� Ƚ��: 127ȸ

typedef struct // ������ ������ ������ �����ϴ� ����ü
{
    int backnum;
    char name[MAXPLAYERNAME];
    char position;
    int offence;
    int defence;
} playerset;

int combination(int n, int r) { // n���� ���� ���� r���� �̴� ����� ���� ���ϴ� �Լ�(���п����� ����)
    if (n == r || r == 0)
        return 1;
    else
        return combination(n - 1, r - 1) + combination(n - 1, r);
}

void numberofcase(int* pos, int* noc, int n, playerset* player) { //�����Ǻ� ���� ��, �������� �������� ������ ��� ���� ����� ���� ���� �Լ�
    for (int i = 0; i < n; i++) {
        if (player[i].position == 'G')
            *pos += 1;
        if (player[i].position == 'F')
            *(pos + 1) += 1;
        if (player[i].position == 'C')
            *(pos + 2) += 1;
    }
    *noc = combination(pos[0], 2) * combination(pos[1], 2) * combination(pos[2], 1);
}

int main() {

    playerset player[MAXPLAYER];

    printf("\n\n\t\t\t\t\t\t***�ְ��� �� ã��***\n\t\t\t\t  ***FIND ALL NBA FIRST TEAM***\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t�����Ϸ��� 1�� �Է��ϼ���.\n");


    int start; // ���α׷� ������ �� start
    scanf("%d", &start);
    if (start)
        printf("\n\n\n\n\n\t\t\t\t\t\t   [���� �Է�]\n\t\t\t\t\t\t [Player Info]\n\n\n\n\n\n\n�ĺ� ������ �� ���ΰ���?: ");
    int n; // �ĺ� ���� ���
    scanf("%d", &n);

    printf("\n\n\n\n\n\n\n\n\n\n\n�������� ������ �Է����ּ���(���ȣ|�̸�|������|���� ������(%%)|���� ������(%%))(������ G,F,C ������)\n\n");
    for (int i = 0; i < n; i++) {
        printf("player %d: ", i + 1);
        scanf("%d %s %c %d %d", &player[i].backnum, &player[i].name, &player[i].position, &player[i].offence, &player[i].defence);
    }

    int check, enter;
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n���� Ȯ��(��:1, �ƴϿ�:0)       => ");
    scanf("%d", &check);
    if (check) {
        for (int i = 0; i < n; i++) {
            printf("player %d: No.%d %s %c\n", i + 1, player[i].backnum, player[i].name, player[i].position);
        }
        printf("\n");
    }
    printf("����Ϸ��� 1�� �Է�: ");
    scanf("%d", &enter);
    if (enter)
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");

    int pos[3] = { 0 }, noc = 0; //������ �� ���� �� pos, ������ ���� ����� �� noc
    numberofcase(pos, &noc, n, player);
    printf("������ ���� �������� %d���� �Դϴ�.\n", noc);

    int Toffence[MAXTEAM][5], Tdefence[MAXTEAM][5], Tnum[MAXTEAM][5], Tbacknum[MAXTEAM][5];
    char Tname[MAXTEAM][5][MAXPLAYERNAME]; //�� ���� ���� ����

    int t = 0;
    for (int i = 0; i < pos[0]; i++) {
        for (int j = i + 1; j < pos[0]; j++) {
            for (int p = pos[0]; p < pos[0] + pos[1]; p++) {
                for (int q = p + 1; q < pos[0] + pos[1]; q++) {
                    for (int r = pos[0] + pos[1]; r < pos[0] + pos[1] + pos[2]; r++) {
                        for (int k = 0; k < 5; k++) {
                            int l = 0;
                            switch (k)
                            {
                            case 0: l = i;
                                break;
                            case 1: l = j;
                                break;
                            case 2: l = p;
                                break;
                            case 3: l = q;
                                break;
                            case 4: l = r;
                                break;
                            }
                            Toffence[t][k] = player[l].offence;
                            Tdefence[t][k] = player[l].defence;
                            Tbacknum[t][k] = player[l].backnum;
                            strcpy(Tname[t][k], player[l].name);
                            Tnum[t][k] = l;
                        }
                        t++;
                    }
                }
            }
        }
    }

    printf("\n\n\n\n\t\t\t\t\t\t   [�� Ȯ��]\n\t\t\t\t\t\t [Check Team]\n\n\n\n\n\n\n�� Ȯ��(��:1, �ƴϿ�:0)        => ");
    scanf("%d", &check);
    if (check) {
        for (t = 0; t < noc; t++) {
            printf("[��%d]\n", t + 1);
            for (int i = 0; i < 5; i++)
                printf("No.%d %s\n", Tbacknum[t][i], Tname[t][i]);
            printf("\n");
        }
    }
    printf("����Ϸ��� 1�� �Է�: ");
    scanf("%d", &enter);
    if (enter)
        printf("\n\n\n\n\n\t\t\t\t\t\t   [��� Ȯ��]\n\t\t\t\t\t\t[Check Result]\n\n\n\n\n\n\n");

    int win[MAXTEAM] = { 0 }, draw[MAXTEAM] = { 0 }, lose[MAXTEAM] = { 0 }; //�� ���� �ѽ����� ġ����� �� ��/��/�� ��
    srand(time(NULL));

    printf("�� ���� ���� ���� Ȯ��(��:1, �ƴϿ�:0)        => ");
    scanf("%d", &check);

    for (t = 0; t < noc; t++) {
        for (int i = 0; i < NOG; i++) {
            int scoreA = 0, scoreB = 0;
            for (int j = 0; j < NOS; j++) {
                if (rand() % 100 + 1 <= Toffence[t][rand() % 5])
                    scoreA++;
                if (rand() % 100 + 1 >= Tdefence[t][rand() % 5])
                    scoreB++;
            }
            if (check)
                printf("��%d %d��° ���(����:����) = %d : %d\n", t + 1, i + 1, scoreA, scoreB);
            if (scoreA - scoreB > 0)
                win[t] += 1;
            else if (scoreA - scoreB == 0)
                draw[t] += 1;
            else
                lose[t] += 1;
        }
        printf("\n");
    }
    printf("����Ϸ��� 1�� �Է�: ");
    scanf("%d", &enter);
    if (enter)
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");

    float winper[MAXTEAM] = { 0 };
    for (t = 0; t < noc; t++)
        winper[t] = (float)win[t] / (win[t] + lose[t]) * 100;

    printf("�� ���� ���� ���� Ȯ��(��:1, �ƴϿ�:0)        => ");
    scanf("%d", &check);
    for (int t = 0; t < noc; t++)
        if (check)
            printf("��%d: %d�� %d�� %d�� �·� %.2f%%\n", t + 1, win[t], draw[t], lose[t], winper[t]);
    printf("\n����Ϸ��� 1�� �Է�: ");
    scanf("%d", &enter);
    if (enter)
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");

    int bestteam = 0, bestwinper = winper[0];

    for (t = 0; t < noc; t++) {
        if (winper[t] > bestwinper) {
            bestteam = t;
            bestwinper = winper[t];
        }
    }

    printf("\t\t\t***ALL NBA FIRSTTEAM: %d(�·�: %.2f%%)***\n\n", bestteam + 1, winper[bestteam]);
    for (int i = 0; i < 5; i++) {
        printf("\n\t\t\t\t\tNo.%d %s %c\n", player[Tnum[bestteam][i]].backnum, player[Tnum[bestteam][i]].name, player[Tnum[bestteam][i]].position);
    }
    printf("\n");

    return 0;
}
