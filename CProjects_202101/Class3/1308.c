#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
int main() {
    int comBall[4], userBall[4];
    //AI 랜덤 숫자 배열, 사용자 랜덤 숫자 배열 지정
    int i, j, yes = 0;
    int menu = 0, count = 1;
    //menu: case를 고를 때 필요한 변수, count: 몇번째 시도인지 세는 변수
    int strike = 0, ball = 0;
    //스트라이크, 볼
    int cowpoint = 0;
    //숫자를 기회 안에 맞춘 횟수 
    int level;
    //게임 진행 횟수 세는 변수
    do {
        yes = 0;
        srand(time(NULL)); //난수
    again:;
        for (i = 0; i < 4; i++) {
            comBall[i] = rand() % 9 + 1;
            //AI가 랜덤 숫자 생성
        }
        if (comBall[0] == comBall[1] || comBall[0] == comBall[2] || comBall[0] == comBall[3] || comBall[1] == comBall[2] || comBall[1] == comBall[3] || comBall[2] == comBall[3]) {
            goto again;
            //자릿수가 같을 때는 안된다
        }
    start:;
        printf("****** 숫자야구게임 ******\n\n");
        printf("====== 메뉴 ======\n\n");
        printf("1. 게임설명(3자리수)\t2.게임설명(4자리수)\t3. 게임시작(3자리수)\t4.게임시작(4자리수)\t5. 그만하기\n\n");
        //1~5 중에서 선택
        printf("번호를 선택하세요\n");
        scanf("%d", &menu);
        switch (menu) {
        case 1:
            printf("****** 설명서 ******\n");
            printf("1. 1부터 9까지의 숫자 중 3개를 고르세요.\n");
            printf("2. 숫자와 위치가 동시에 맞으면 strike, 숫자만 맞고 위치가 다르면 ball입니다.\n");
            printf("3. 기회는 총 6번입니다. 만약 6번 안에 맞출 시 100점의 점수가 지급되고, 맞추지 못할 시 50점의 점수가 지급됩니다.\n");
            printf("4. 이 포인트는 쌓여서 경험치로 바뀌게 되니, 열심히 참여해주세요!\n");
            printf("그럼 행운을 빌어요!\n\n");
            goto start;
            break;
        case 2: printf("****** 설명서 ******\n");
            printf("1. 1부터 9까지의 숫자 중 4개를 고르세요.\n");
            printf("2. 숫자와 위치가 동시에 맞으면 strike, 숫자만 맞고 위치가 다르면 ball입니다.\n");
            printf("3. 기회는 총 9번입니다. 만약 9번 안에 맞출 시 140점의 점수가 지급되고, 맞추지 못할 시 70점의 점수가 지급됩니다.\n");
            printf("4. 이 포인트는 쌓여서 경험치로 바뀌게 되니, 열심히 참여해주세요!\n");
            printf("그럼 행운을 빌어요!\n\n");
            goto start;
            break;
        case 3:
            //3자리 수 숫자야구 게임 시작
            while (strike != 3) {
                printf("%d번째 시도\n", count);
                printf("숫자 3개를 입력하세요\n");
                scanf("%d %d %d", &userBall[0], &userBall[1], &userBall[2]);
                count++;
                if (userBall[0] < 1 || userBall[0] > 9 || userBall[1] < 1 || userBall[1] > 9 || userBall[2] < 1 || userBall[2] > 9)
                    //자릿수는 1~9의 자연수만 입력가능
                {
                    printf("범위 외의 숫자를 입력하시면 안됩니다.\n");
                    count--;
                    continue;
                }
                else if (userBall[0] == userBall[1] || userBall[0] == userBall[2] || userBall[1] == userBall[2]) {
                    //자릿수가 중복되면 안된다.
                    printf("중복된 숫자를 입력하시면 안됩니다.\n");
                    count--;
                    continue;
                }
                ball = 0;
                strike = 0;
                for (i = 0; i < 3; i++) {
                    for (j = 0; j < 3; j++) {
                        if (comBall[i] == userBall[j]) {
                            if (i == j) {
                                strike++;
                                //위치와 자릿수가 모두 일치하면 스트라이크
                            }
                            else if (i != j) {
                                //자릿수만 맞고 위치가 다르면 볼
                                ball++;
                            }
                        }
                    }
                }
                if (strike != 3 && count == 7)
                    //6번째 시도까지 숫자를 맞추지 못하면 패배
                {
                    printf("아쉽네요~\n\n");
                    printf("정답은 %d%d%d였습니다\n", comBall[0], comBall[1], comBall[2]);
                    cowpoint += 50;
                    printf("점수: %d점\n\n", cowpoint);
                    level = cowpoint / 100;
                    printf("당신의 숫자 야구 레벨은 Lvl. %d입니다.\n\n", level);
                    if (1 <= level && level < 2) printf("싱글 A 등급입니다.\n");
                    if (2 <= level && level < 4) printf("더블 A 등급입니다.\n");
                    if (4 <= level && level < 7) printf("트리플 A 등급입니다.\n");
                    if (level >= 7) printf("축하합니다! 이제 당신도 숫자야구 메이저리거입니다.\n");
                    break;
                }
                if (strike == 0 && ball == 0) {
                    printf("일치하는 자릿수가 없습니다.\n"); //0볼 0스트라이크일 경우
                }
                printf("%d볼 %d스트라이크입니다\n", ball, strike);
            }
            if (strike == 3) {
                printf("좀 하시네요~\n");
                printf("재야의 고수시군요.\n\n");
                cowpoint += 100;
                printf("점수: %d점\n\n", cowpoint);
                level = cowpoint / 100;
                printf("당신의 숫자 야구 레벨은 Lvl. %d입니다.\n\n", level);
                if (1 <= level && level < 2) printf("싱글 A 등급입니다.\n");
                if (2 <= level && level < 4) printf("더블 A 등급입니다.\n");
                if (4 <= level && level < 7) printf("트리플 A 등급입니다.\n");
                if (level >= 7) printf("축하합니다! 이제 당신도 숫자야구 메이저리거입니다.\n");
            }
            printf("다시 하시겠습니까?\n");
            printf("다시 하시려면 1번, 그만두시려면 아무 키나 눌러주세요\n");
            scanf("%d", &yes);
            ball = 0;
            strike = 0;
            count = 1;
            if (yes != 1) {
                break;
            }
        case 4:
            //4자리수 숫자야구 시작
            while (strike != 4) {
                printf("%d번째 시도\n", count);
                printf("숫자 4개를 입력하세요\n");
                scanf("%d %d %d %d", &userBall[0], &userBall[1], &userBall[2], &userBall[3]);
                count++;
                if (userBall[0] < 1 || userBall[0] > 9 || userBall[1] < 1 || userBall[1] > 9 || userBall[2] < 1 || userBall[2] > 9 || userBall[3] < 1 || userBall[3]>9) {
                    printf("범위 외의 숫자를 입력하시면 안됩니다.\n");
                    count--;
                    continue;
                }
                else if (userBall[0] == userBall[1] || userBall[0] == userBall[2] || userBall[0] == userBall[3] || userBall[1] == userBall[2] || userBall[1] == userBall[3] || userBall[2] == userBall[3]) {
                    printf("중복된 숫자를 입력하시면 안됩니다.\n");
                    count--;
                    continue;
                }
                ball = 0;
                strike = 0;
                for (i = 0; i < 4; i++) {
                    for (j = 0; j < 4; j++) {
                        if (comBall[i] == userBall[j]) {
                            if (i == j) {
                                strike++;
                            }
                            else if (i != j) {
                                ball++;
                            }
                        }
                    }
                }
                if (strike != 4 && count == 10) {
                    printf("아쉽네요~\n\n");
                    printf("정답은 %d%d%d%d였습니다\n", comBall[0], comBall[1], comBall[2], comBall[3]);
                    cowpoint += 70;
                    printf("점수: %d점\n\n", cowpoint);
                    level = cowpoint / 100;
                    printf("당신의 숫자 야구 레벨은 Lvl. %d입니다.\n\n", level);
                    if (1 <= level && level < 2) printf("싱글 A 등급입니다.\n");
                    if (2 <= level && level < 4) printf("더블 A 등급입니다.\n");
                    if (4 <= level && level < 7) printf("트리플 A 등급입니다.\n");
                    if (level >= 7) printf("축하합니다! 이제 당신도 숫자야구 메이저리거입니다.\n");
                    break;
                }
                if (strike == 0 && ball == 0) {
                    printf("no match\n");
                }
                printf("%d볼 %d스트라이크입니다\n", ball, strike);
            }
            if (strike == 4) {
                printf("좀 하시네요~\n");
                printf("재야의 고수시군요.\n\n");
                cowpoint += 100;
                printf("점수: %d점\n\n", cowpoint);
                level = cowpoint / 100;
                printf("당신의 숫자 야구 레벨은 Lvl. %d입니다.\n\n", level);
                if (1 <= level && level < 2) printf("싱글 A 등급입니다.\n");
                if (2 <= level && level < 4) printf("더블 A 등급입니다.\n");
                if (4 <= level && level < 7) printf("트리플 A 등급입니다.\n");
                if (level >= 7) printf("축하합니다! 이제 당신도 숫자야구 메이저리거입니다.\n");
            }
            printf("다시 하시겠습니까?\n");
            printf("다시 하시려면 1번, 그만두시려면 아무 키나 눌러주세요\n");
            scanf("%d", &yes);
            ball = 0;
            strike = 0;
            count = 1;
            if (yes != 1) {
                //1번을 누르지 않으면 게임 종료 
                break;
            }
        case 5:
            //게임을 바로 끝낼 수 있음
            printf("게임을 종료합니다.\n");
            break;
        default:
            //이상한 키를 눌렀을 경우
            printf("잘못 입력하셨습니다. 프로그램이 종료됩니다.\n");
            break;
        }
    } while (yes == 1);
}

































































