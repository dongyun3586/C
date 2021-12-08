#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define MAXTEAM 10000 // 최대로 가능한 팀의 경우의 수
#define MAXPLAYER 100 // 최대로 입력 가능한 플레이어 수
#define MAXPLAYERNAME 100 // 선수 이름 최대 글자수
#define NOG 82 // number of games - NBA 한시즌 경기수: 82경기
#define NOS 127 // number of shots - NBA 한경기 평균 슈팅 시도 횟수: 127회

typedef struct // 선수들 각각의 정보를 저장하는 구조체
{
    int backnum;
    char name[MAXPLAYERNAME];
    char position;
    int offence;
    int defence;
} playerset;

int combination(int n, int r) { // n개중 순서 없이 r개를 뽑는 경우의 수를 구하는 함수(수학에서의 조합)
    if (n == r || r == 0)
        return 1;
    else
        return combination(n - 1, r - 1) + combination(n - 1, r);
}

void numberofcase(int* pos, int* noc, int n, playerset* player) { //포지션별 선수 수, 선수들의 조합으로 가능한 모든 팀의 경우의 수를 세는 함수
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

    printf("\n\n\t\t\t\t\t\t***최고의 팀 찾기***\n\t\t\t\t  ***FIND ALL NBA FIRST TEAM***\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t시작하려면 1을 입력하세요.\n");


    int start; // 프로그램 시작할 때 start
    scanf("%d", &start);
    if (start)
        printf("\n\n\n\n\n\t\t\t\t\t\t   [선수 입력]\n\t\t\t\t\t\t [Player Info]\n\n\n\n\n\n\n후보 선수는 몇 명인가요?: ");
    int n; // 후보 선수 명수
    scanf("%d", &n);

    printf("\n\n\n\n\n\n\n\n\n\n\n선수들의 정보를 입력해주세요(등번호|이름|포지션|공격 성공률(%%)|수비 성공률(%%))(포지션 G,F,C 순으로)\n\n");
    for (int i = 0; i < n; i++) {
        printf("player %d: ", i + 1);
        scanf("%d %s %c %d %d", &player[i].backnum, &player[i].name, &player[i].position, &player[i].offence, &player[i].defence);
    }

    int check, enter;
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n선수 확인(예:1, 아니오:0)       => ");
    scanf("%d", &check);
    if (check) {
        for (int i = 0; i < n; i++) {
            printf("player %d: No.%d %s %c\n", i + 1, player[i].backnum, player[i].name, player[i].position);
        }
        printf("\n");
    }
    printf("계속하려면 1을 입력: ");
    scanf("%d", &enter);
    if (enter)
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");

    int pos[3] = { 0 }, noc = 0; //포지션 별 선수 수 pos, 가능한 팀의 경우의 수 noc
    numberofcase(pos, &noc, n, player);
    printf("가능한 팀의 가짓수는 %d가지 입니다.\n", noc);

    int Toffence[MAXTEAM][5], Tdefence[MAXTEAM][5], Tnum[MAXTEAM][5], Tbacknum[MAXTEAM][5];
    char Tname[MAXTEAM][5][MAXPLAYERNAME]; //각 팀별 선수 정보

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

    printf("\n\n\n\n\t\t\t\t\t\t   [팀 확인]\n\t\t\t\t\t\t [Check Team]\n\n\n\n\n\n\n팀 확인(예:1, 아니오:0)        => ");
    scanf("%d", &check);
    if (check) {
        for (t = 0; t < noc; t++) {
            printf("[팀%d]\n", t + 1);
            for (int i = 0; i < 5; i++)
                printf("No.%d %s\n", Tbacknum[t][i], Tname[t][i]);
            printf("\n");
        }
    }
    printf("계속하려면 1을 입력: ");
    scanf("%d", &enter);
    if (enter)
        printf("\n\n\n\n\n\t\t\t\t\t\t   [결과 확인]\n\t\t\t\t\t\t[Check Result]\n\n\n\n\n\n\n");

    int win[MAXTEAM] = { 0 }, draw[MAXTEAM] = { 0 }, lose[MAXTEAM] = { 0 }; //각 팀별 한시즌을 치루었을 때 승/패/무 수
    srand(time(NULL));

    printf("각 팀의 경기당 성적 확인(예:1, 아니오:0)        => ");
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
                printf("팀%d %d번째 경기(득점:실점) = %d : %d\n", t + 1, i + 1, scoreA, scoreB);
            if (scoreA - scoreB > 0)
                win[t] += 1;
            else if (scoreA - scoreB == 0)
                draw[t] += 1;
            else
                lose[t] += 1;
        }
        printf("\n");
    }
    printf("계속하려면 1을 입력: ");
    scanf("%d", &enter);
    if (enter)
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");

    float winper[MAXTEAM] = { 0 };
    for (t = 0; t < noc; t++)
        winper[t] = (float)win[t] / (win[t] + lose[t]) * 100;

    printf("각 팀의 최종 성적 확인(예:1, 아니오:0)        => ");
    scanf("%d", &check);
    for (int t = 0; t < noc; t++)
        if (check)
            printf("팀%d: %d승 %d무 %d패 승률 %.2f%%\n", t + 1, win[t], draw[t], lose[t], winper[t]);
    printf("\n계속하려면 1을 입력: ");
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

    printf("\t\t\t***ALL NBA FIRSTTEAM: %d(승률: %.2f%%)***\n\n", bestteam + 1, winper[bestteam]);
    for (int i = 0; i < 5; i++) {
        printf("\n\t\t\t\t\tNo.%d %s %c\n", player[Tnum[bestteam][i]].backnum, player[Tnum[bestteam][i]].name, player[Tnum[bestteam][i]].position);
    }
    printf("\n");

    return 0;
}
