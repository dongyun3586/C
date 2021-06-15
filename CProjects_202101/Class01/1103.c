#include <stdio.h>
///나이트의 여행
///made by 고성윤

int f, a, b, s1, s2, m, n, end = 1, T, wid, len; ///wid, len: 가로세로 필드크기

char notice[50][50] = {                             ///말이 이동하는 방향
     {'9','8','9','1','9'},
     {'7','9','9','9','2'},
     {'9','9','H','9','9'},
     {'6','9','9','9','3'},
     {'9','5','9','4','9'}
},

field[50][50] = {                                ///field x,y 좌표
    {'9', '1', '2', '3', '4', '5', '6', '7', '8'}
};


int main() {
    start();
    while (end) {
        asking();
        if (end) print();
    }
    printf("\n수고하셨습니다.\n");                 ///프로그램 종료멘트
}

void start() { //도입부. 필드를 안내하고 시작 좌표를 받아온다.
    printf("이 게임은 나이트의 여행입니다. \n숫자 7은 말입니다");
    printf("\n\n(최대 8X8)필드의 가로, 세로 : ");
    scanf("%d %d", &wid, &len);

    makefield();

    printf("\n\n이동을 명령할 때 방향에 따라 기입할 숫자는 다음과 같습니다.");
    printf("\n");
    for (int j = 0; j <= 5; j++) {
        for (int i = 0; i <= 5; i++) {
            if (notice[j][i] == '9') {
                printf(" ");
            }
            else {
                printf("%c", notice[j][i]);
            }
        }
        printf("\n");
    }
    print();
    setup();
}

void setup() {
    printf("\n시작 지점의 좌표를 선택하세요. A B : ");
    scanf("%d %d", &s1, &s2);
    if (s1 > wid || s2 > len || s1 == 0 || s2 == 0) {
        printf("\n잘못된 시작 좌표입니다. 좌표를 1~%d, 1~%d 범위의 값으로 입력해주세요.\n", wid, len);
        setup();
    }
    else {
        change(s1, s2);
        print();
        printf("\n시작합니다.\a\a\a\n");
    }
}

void makefield() {       ///가로세로 입력받은 값을 토대로 필드를 생성함
    int p = 0;
    for (int q = 1; q <= 9; q++) {
        field[q][p] = field[p][q];
    }
    for (p = 1; p <= wid; p++) {
        for (int q = 1; q <= len; q++) {
            field[q][p] = '0';
        }
    }
}

void print() {           ///필드 규격 크기에 맞춰 배열을 출력해주는 역할
    printf("\a\n");
    for (int j = 0; j < len + 1; j++) {
        for (int i = 0; i < wid + 1; i++) {
            if (field[j][i] == '9') {
                printf("   ");
            }
            else {
                printf("%3c", field[j][i]);
            }
        }
        printf("\n");
    }

}

void asking() {                          /// 갈 수 있는 칸에 대해, 선택을 받는다. 또한 변경사항을 수정해 보여준다.
    field[s2][s1] = '9';               ///이미 갔던 칸 더이상 프린트되지 않게 설정
    if (field[s2 - 1][s1 - 2] == '0' || field[s2 - 2][s1 - 1] == '0' || field[s2 - 1][s1 + 2] == '0' || field[s2 - 2][s1 + 1] == '0' || field[s2 + 1][s1 - 2] == '0' || field[s2 + 2][s1 - 1] == '0' || field[s2 + 2][s1 + 1] == '0' || field[s2 + 1][s1 + 2] == '0') { //더 진행 가능한가?
        printf("\n이동할 방향의 숫자를 입력하세요. A : ");
        scanf("%d", &m);

        switch (m)
        {
        case 1:
            s1 = s1 + 1;
            s2 = s2 - 2;
            if (field[s2][s1] != '0') {                   ///입력받은 위치가 이동 가능한 위치('0')인가?
                printf("이동 불가능한 칸입니다.\n");
                s1 = s1 - 1;
                s2 = s2 + 2;
                field[s2][s1] = '7';
                break;
            }
            break;

        case 2:
            s1 = s1 + 2;
            s2 = s2 - 1;
            if (field[s2][s1] != '0') {
                printf("이동 불가능한 칸입니다.\n");
                s1 = s1 - 2;
                s2 = s2 + 1;
                field[s2][s1] = '7';
                break;
            }
            break;

        case 3:
            s1 = s1 + 2;
            s2 = s2 + 1;
            if (field[s2][s1] != '0') {
                printf("이동 불가능한 칸입니다.\n");
                s1 = s1 - 2;
                s2 = s2 - 1;
                field[s2][s1] = '7';
                break;
            }
            break;

        case 4:
            s1 = s1 + 1;
            s2 = s2 + 2;
            if (field[s2][s1] != '0') {
                printf("이동 불가능한 칸입니다.\n");
                s1 = s1 - 1;
                s2 = s2 - 2;
                field[s2][s1] = '7';
                break;
            }
            break;
        case 5:
            s1 = s1 - 1;
            s2 = s2 + 2;
            if (field[s2][s1] != '0') {
                printf("이동 불가능한 칸입니다.\n");
                s1 = s1 + 1;
                s2 = s2 - 2;
                field[s2][s1] = '7';
                break;
            }
            break;
        case 6:
            s1 = s1 - 2;
            s2 = s2 + 1;
            if (field[s2][s1] != '0') {
                printf("이동 불가능한 칸입니다.\n");
                s1 = s1 + 2;
                s2 = s2 - 1;
                field[s2][s1] = '7';
                break;
            }
            break;
        case 7:
            s1 = s1 - 2;
            s2 = s2 - 1;
            if (field[s2][s1] != '0') {
                printf("이동 불가능한 칸입니다.\n");
                s1 = s1 + 2;
                s2 = s2 + 1;
                field[s2][s1] = '7';
                break;
            }
            break;
        case 8:
            s1 = s1 - 1;
            s2 = s2 - 2;
            if (field[s2][s1] != '0') {
                printf("이동 불가능한 칸입니다.\n");
                s1 = s1 + 1;
                s2 = s2 + 2;
                field[s2][s1] = '7';
                break;
            }
            break;
        default:
            printf("\n입력 오류. 1~8사이의 숫자를 입력해주세요");
        }
    }
    else {
        if (checkwin()) {
            printf("\n이겼습니다! 축하합니다 \n");
            end = 0;
        }
        else {
            printf("\n졌습니다.\a\n");
            end = 0;
        }
    }

    if (field[s2][s1] == '0') {          ///이동위치 체크
        change(s1, s2);
    }
}

int change(int p, int q) {           ///대답을 얻은 후, 변경사항을 수정해 보여준다.
    field[q][p] = '7';
}

int checkwin() {                     ///승리한 경우, 패배한경우 판단
    for (int u = 0; u < 50; u++) {
        for (int t = 0; t < 50; t++) {
            if (field[u][t] == '0') {
                return 0;
            }
        }
    }
    return 1;
}
