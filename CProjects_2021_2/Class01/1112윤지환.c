#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int sch[18][11];//경기 스케줄. 한 줄이 예를 들어 3 2 1 8 10 9 7 6 5 4 라면 이날은 3번과 2번, 1번과 8번, 10번과 9번, 7번과 6번, 5번과 4번팀이 경기하게 됨.
int day = 0;//제 n차전 경기

struct A {
    char team[20];//팀 이름
    char park[5];//홈 구장
    int win;//승 수
    int draw;//패 수
    int lose;//무승부 수
    float rate;//승률
    int relativerecord[11];//상대 전적-동률시 필요 relativerecord[i]는 i번째 팀을 상대로 승리한 횟수
    int relativescore[11];//상대 득점- 동률시 필요
};
struct A s[11] = { {""},{"KIA 타이거즈","광주"},{"두산 베어스","잠실"},{"롯데 자이언츠","사직"},{"NC 다이노스","창원"},{"SSG 랜더스","문학"},{"LG 트윈스","잠실"},{"키움 히어로즈","고척"},{"한화 이글스","대전"},{"삼성 라이온즈","대구"},{"KT 위즈","수원"} };

void input();
void pennantrace();//정규 시즌 진행
void set(int num);
void game(int teamA, int teamB);//각 경기 진행
int overtime(int r);//무승부일때 연장전
int score(int r);//경기에서 점수 반환
void sort();//정규 시즌 순위 정렬
void swap(int teamA, int teamB);
void pennantraceresult();//정규시즌 결과 출력
void tiebreaker();//1위가 동률 일때 타이브레이커
void tie(int a);//나머지가 동률일때 순위 정하기
void postseason();//포스트 시즌 경기 진행
void postseasongame(int teamA, int teamB, int* win, int* draw, int* lose);//포스트시즌에서의 게임 진행. game 함수와 비슷하나 상대 전적,득점 등을 계산할 필요가 없어 따로 만듦
int wildcard(int teamA, int teamB);//와일드 카드 결정전
int playoff(int teamA, int teamB);//준플레이오프,플레이오프 진행
int KS(int teamA, int teamB);//한국시리즈
void postseasonresult(int winner, int playoffwinner);//최종 순위

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
            fscanf(fp, "%d", &sch[i][j]);//따로 텍스트파일로 정리해 둔 경기 스케줄을 가지고 옴. 너무 길어 따로 빼놓음
    fclose(fp);
}

void pennantrace() {
    printf("[KBO 리그 정규 시즌]\n\n");
    Sleep(1000);
    set(3);//3연전
    set(3);//3연전
    set(2);//2연전
    for (int i = 1; i <= 10; i++)
        s[i].rate = (float)s[i].win / ((float)s[i].win + (float)s[i].lose);//승률=승/(승+패)
}

void set(int num) {
    int a, b;
    for (int i = 0; i < 18; i++) {
        for (int k = 1; k <= num; k++) {//num 연전
            day++;
            printf("[제%d 경기]\n", day);
            for (int j = 1; j <= 5; j++) {//하루에 열리는 5경기
                a = sch[i][j * 2 - 1];
                b = sch[i][j * 2];
                game(a, b);
            }
            printf("\n\n");
        }
    }
}

void game(int teamA, int teamB) {//경기 결과에 대한 함수
    int a = score(rand() % 100);//a팀의 점수
    int b = score(rand() % 100);//b팀의 점수
    printf("<%s>\n%-15s vs %15s\n", s[teamB].park, s[teamA].team, s[teamB].team);
    if (a == b) {//동점일 때 무승부를 줄이기 위해 점수를 추가함
        a += overtime(rand() % 100);
        b += overtime(rand() % 100);
    }
    if (a > b) {//a팀 승리
        printf("%2d : %2d  %15s 승리!\n\n", a, b, s[teamA].team);
        s[teamA].win++;
        s[teamB].lose++;
        s[teamA].relativerecord[teamB]++;
    }
    else if (a < b) {//b팀 승리
        printf("%2d : %2d  %15s 승리!\n\n", a, b, s[teamB].team);
        s[teamA].lose++;
        s[teamB].win++;
        s[teamB].relativerecord[teamA]++;
    }
    else if (a == b) {//점수 추가해도 무승부일때
        printf("%2d : %2d  무승부\n\n", a, b);
        s[teamA].draw++;
        s[teamB].draw++;
    }
    s[teamA].relativescore[teamB] += a;
    s[teamB].relativescore[teamA] += b;
}

int overtime(int r) {//무승부일 떄 점수 추가
    int sum = 0;
    int p[6] = { 20,30,20,15,10,5 };//i점이 추가될 확률은 p[i]%
    for (int i = 0; i <= 5; i++) {
        sum += p[i];
        if (r <= sum)
            return i;
    }
    return 0;
}

int score(int r) {//점수를 반환해줌
    int sum = 0;
    int p[30] = { 7,7,8,10,13,10,8,7,5,4,4,3,3,2,2,2,1,1,1,1,1 };//각 점수의 확률. 점수가 i일 확률은 p[i]%임
    for (int i = 0; i <= 20; i++) {
        sum += p[i];
        if (r <= sum)
            return i;
    }
    return 0;
}

void sort() {//1위부터 10위까지 승률에 따라 정렬
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
    for (int i = 1; i <= 10; i++) {//팀 순위를 바꿈에 따라 상대 득점 전적도 바꿔야함
        s[i].relativerecord[0] = s[i].relativerecord[teamA];
        s[i].relativerecord[teamA] = s[i].relativerecord[teamB];
        s[i].relativerecord[teamB] = s[i].relativerecord[0];
        s[i].relativescore[0] = s[i].relativescore[teamA];
        s[i].relativescore[teamA] = s[i].relativescore[teamB];
        s[i].relativescore[teamB] = s[i].relativescore[0];
    }
    s[0] = s[teamA];//팀의 순위를 바꿈
    s[teamA] = s[teamB];
    s[teamB] = s[0];
}

void pennantraceresult() {
    if (s[1].rate == s[2].rate) {//정규시즌 1 2위 동률일 때
        if (s[2].rate != s[3].rate) {
            Sleep(2000);
            tiebreaker();//타이브레이커 경기
        }
    }
    else {//나머지가 동률 일때
        for (int i = 2; i < 10; i++)
            if (s[i].rate == s[i + 1].rate)
                tie(i);
    }

    Sleep(2000);
    printf("[KBO 리그 정규시즌 순위]\n");
    for (int i = 1; i <= 10; i++)
        printf("%2d위 %-15s %3d승 %3d무 %3d패 승률 %.3f\n", i, s[i].team, s[i].win, s[i].draw, s[i].lose, s[i].rate);
    printf("\n\n");
}

void tiebreaker() {//정규시즌 1 2위의 승률이 동률일때
    int a = score(rand() % 100);
    int b = score(rand() % 100);
    printf("[정규시즌 1위 결정전]\n");
    Sleep(1000);
    printf("%-15s vs %15s\n", s[1].team, s[2].team);
    while (a == b) {//정규시즌 경기와 달리 승부가 결정될 때 까지 경기
        a += overtime(rand() % 100);
        b += overtime(rand() % 100);
        if (a != b)
            break;
    }
    if (a > b)
        printf("%2d : %2d  %15s 승리!\n\n", a, b, s[1].team);
    else if (a < b) {
        printf("%2d : %2d  %15s 승리!\n\n", a, b, s[2].team);
        swap(1, 2);
    }
}

void tie(int a) {//동률일 때
    Sleep(1000);
    printf("<동률 규정>\n%-15s vs %15s\n상대전적 %2d승 : %2d승\n\n", s[a].team, s[a + 1].team, s[a].relativerecord[a + 1], s[a + 1].relativerecord[a]);
    if (s[a].relativerecord[a + 1] < s[a + 1].relativerecord[a]) {//상대 전적 비교
        swap(a, a + 1);
    }
    else if (s[a].relativerecord[a + 1] == s[a + 1].relativerecord[a]) {//상대 전적 동률 시 상대 득점 비교
        printf("상대득점 %3d점 : %3d점\n\n", s[a].relativescore[a + 1], s[a + 1].relativescore[a]);
        if (s[a].relativescore[a + 1] < s[a + 1].relativescore[a])
            swap(a, a + 1);
    }
    printf("%-15s %2d위\n%-15s %2d위\n\n", s[a].team, a, s[a + 1].team, a + 1);
}

void postseason() {
    Sleep(2000);
    printf("[KBO 포스트시즌]\n\n");
    printf("한국시리즈       ┌───────┐\n");//포스트시즌 대진표
    printf("                 │     %s\n", s[1].team);
    printf("                 │\n");
    printf("PO           ┌───────┐\n");
    printf("             │     %s\n", s[2].team);
    printf("             │\n");
    printf("준PO    ┌───────┐\n");
    printf("        │     %s\n", s[3].team);
    printf("        │\n");
    printf("WC  ┌───────┐\n");
    printf("    │     %s\n", s[4].team);
    printf("    │\n");
    printf("   %s\n\n\n", s[5].team);
    Sleep(2000);
    printf("[KBO 와일드카드 결정전]\n%s vs %s\n\n", s[4].team, s[5].team);
    Sleep(1000);
    int winner = wildcard(4, 5);//winner=다음라운드 진출자
    Sleep(1000);
    printf("%s 준플레이오프 진출!\n\n\n\n", s[winner].team);
    Sleep(2000);
    printf("[KBO 준플레이오프]\n%s vs %s\n\n", s[3].team, s[winner].team);
    Sleep(1000);
    winner = playoff(3, winner);
    Sleep(1000);
    printf("%s 플레이오프 진출!\n\n\n\n", s[winner].team);
    Sleep(2000);
    printf("[KBO 플레이오프]\n%s vs %s\n\n", s[2].team, s[winner].team);
    Sleep(1000);
    winner = playoff(2, winner);
    int playoffwinner = winner;
    Sleep(1000);
    printf("%s 한국시리즈 진출!\n\n\n\n", s[winner].team);
    Sleep(2000);
    printf("[KBO 한국시리즈]\n%s vs %s\n\n", s[1].team, s[winner].team);
    Sleep(1000);
    winner = KS(1, winner);
    Sleep(1000);
    printf("%s 한국시리즈 우승!\n\n\n", s[winner].team);
    postseasonresult(winner, playoffwinner);
    Sleep(2000);
    printf("[KBO 리그 최종 순위]\n");
    for (int i = 1; i <= 10; i++)
        printf("%2d위 %-15s\n", i, s[i].team);
    printf("\n\n");
    if (strcmp(s[1].team, "KIA 타이거즈") == 0)//기아 우승시 로고 출력
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
    //1등-한국시리즈 우승팀 2등-한국시리즈 준우승팀 나머지-성적순
    if (winner == playoffwinner) {//업셋우승 한 경우
        s[0] = s[winner];
        for (int i = winner; i >= 2; i--)
            s[i] = s[i - 1];
        s[1] = s[0];
    }
    else {//정규시즌 1위가 우승한 경우
        s[0] = s[playoffwinner];
        for (int i = playoffwinner; i > 2; i--)
            s[i] = s[i - 1];
        s[2] = s[0];
    }
}

void postseasongame(int teamA, int teamB, int* win, int* draw, int* lose) {
    //정규시즌의 경기와 같은 원리 상대 득점, 전적등을 따로 반환할 필요가 없어 따로 만듬
    int a = score(rand() % 100);
    int b = score(rand() % 100);
    printf("<%s>\n%-15s vs %15s\n", s[teamB].park, s[teamA].team, s[teamB].team);
    if (a == b) {
        a += overtime(rand() % 100);
        b += overtime(rand() % 100);
    }
    if (a > b) {
        printf("%2d : %2d  %15s 승리!\n\n", a, b, s[teamA].team);
        (*win)++;
    }
    else if (a < b) {
        printf("%2d : %2d  %15s 승리!\n\n", a, b, s[teamB].team);
        (*lose)++;
    }
    else if (a == b) {
        printf("%2d : %2d  무승부\n\n", a, b);
        (*draw)++;
    }
    Sleep(600);
}

int wildcard(int teamA, int teamB) {
    int win = 0, draw = 0, lose = 0;//정규시즌 4위팀의 승 무 패
    printf("와일드 카드 결정전 제 1경기\n");
    postseasongame(teamB, teamA, &lose, &draw, &win);
    if (win == 1 || draw == 1)//1승 또는 1무- 정규시즌 4위팀 승리
        return teamA;
    printf("와일드 카드 결정전 제 2경기\n");
    postseasongame(teamB, teamA, &lose, &draw, &win);
    if (lose == 2)//2패시 정규시즌 5위팀 승리
        return teamB;
    return teamA;//1무 1패 또는 1승 1패-정규시즌 4위팀 승리

}

int playoff(int teamA, int teamB) {//준플레이오프와 플레이오프. 진행방식이 동일해서 하나로 묶음
    int win = 0, draw = 0, lose = 0, i = 1;//상위팀(teamA)의 승 무 패
    for (int x = 1; x <= 2; x++) {//1~2차전
        if (teamA == 3)
            printf("준");
        printf("플레이오프 제 %d경기\n", i++);
        postseasongame(teamB, teamA, &lose, &draw, &win);
    }
    for (int x = 1; x <= 2; x++) {//3~4차전
        if (teamA == 3)
            printf("준");
        printf("플레이오프 제 %d경기\n", i++);
        postseasongame(teamA, teamB, &win, &draw, &lose);
        if (win == 3)
            return teamA;
        if (lose == 3)
            return teamB;
    }
    if (teamA == 3)
        printf("준");
    printf("플레이오프 제 %d경기\n", i++);//5차전
    postseasongame(teamB, teamA, &lose, &draw, &win);
    while (win == lose) {//5차전 까지 승부가 나지 않을 때
        if (teamA == 3)
            printf("준");
        printf("플레이오프 제 %d경기\n", i++);
        postseasongame(teamB, teamA, &lose, &draw, &win);
    }
    if (win > lose)
        return teamA;
    else if (lose > win)
        return teamB;
}

int KS(int teamA, int teamB) {
    int win = 0, draw = 0, lose = 0, i = 1;

    for (int x = 1; x <= 2; x++) {//1~2차전. 정규시즌 1위팀 홈구장
        printf("한국시리즈 제 %d경기\n", i++);
        postseasongame(teamB, teamA, &lose, &draw, &win);
    }
    for (int x = 1; x <= 2; x++) {//3~4차전. 플레이오프 승리팀 홈구장
        printf("한국시리즈 제 %d경기\n", i++);
        postseasongame(teamA, teamB, &win, &draw, &lose);
    }
    for (int x = 1; x <= 3; x++) {//5~7차전. 정규시즌 1위팀 홈구장
        if (win == 4)
            return teamA;
        if (lose == 4)
            return teamB;//네번째 경기부터 시리즈가 끝날 수 있음
        printf("한국시리즈 제 %d경기\n", i++);
        postseasongame(teamB, teamA, &lose, &draw, &win);
    }
    while (win == lose) {//7차전까지 승부가 결정나지 않았을 때
        printf("한국시리즈 제 %d경기\n", i++);
        postseasongame(teamB, teamA, &lose, &draw, &win);
    }
    if (win > lose)
        return teamA;
    else if (lose > win)
        return teamB;
}
