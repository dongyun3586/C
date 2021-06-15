#include <stdio.h>
#include<windows.h>//    -> system("cls");
char name[100] = { 0, };
int age, year, month, day;

int checking(int a) {
    if (a == 1) {
        for (int i = 0; i <= 3; i++) {
            printf(".");
            Sleep(1000);
        }

        printf("이 설문조사는 광주과학고등학교 1학년 1반 반장 심윤섭이 만든 설문조사 입니다.");
        Sleep(4000);
        system("cls");

        printf("성실하게 임하시면 자신의 성향을 완벽하게 알 수 있으실 겁니다!");
        Sleep(4000);
        system("cls");

        //이름값 입력받고 출력하기
        printf("먼저 이름을 입력해주세요\n");
        scanf("%s", &name);
        printf("%s", name);

        for (int i = 0; i < 3; i++) {
            printf(".");
            Sleep(1000);
        }

        printf("멋진 이름이네요!\n");
        Sleep(2000);// 1000=1초
        system("cls");

        //나이 입력받기
        printf("나이는 어떻게 되시나요?\n");
        scanf("%d", &age);
        year = 2022 - age;
        if (year == 2005) {
            printf("오! % d세면", age);
            for (int i = 0; i < 3; i++) {
                printf(".");
                Sleep(1000);
            }
            printf("저랑 동갑이시네요!신기하네요!\n");
        }

        else {
            printf("오! %d 세면", age);
            for (int i = 0; i < 3; i++) {
                printf(".");
                Sleep(1000);
            }
            printf("%d 년생이시군요!\n", year);
        }
        Sleep(2000);
        system("cls");

        //몇월인지 물어보고 계절 말해주기
        printf("몇월 에 태어나셨나요?\n");
        scanf("%d", &month);

        switch (month) {
        case 12:
        case 1:
        case 2:
            for (int i = 0; i < 3; i++) {
                Sleep(1000);
                printf(".");
            }
            printf("겨울에 태어나셨군요!");
            break;

        case 3:
        case 4:
        case 5:
            for (int i = 0; i < 3; i++) {
                printf(".");
                Sleep(1000);
            }
            printf("봄에 태어나셨군요!");
            break;

        case 6:
        case 7:
        case 8:
            for (int i = 0; i < 3; i++) {
                printf(".");
                Sleep(1000);
            }
            printf("여름에 태어나셨군요!");
            break;

        case 9:
        case 10:
        case 11:
            for (int i = 0; i < 3; i++) {
                printf(".");
                Sleep(1000);
            }
            printf("가을에 태어나셨군요!");
            break;
        }
        Sleep(2000);
        system("cls");

        //몇일에 태어났는지 물어보고 농담하기
        printf("몇일에 태어나셨나요?\n");
        scanf("%d", &day);
        if (day == 13) {
            printf("ㅎㄷㄷ 설마 금요일에 태어난 것은 아니시죠? ㅋㅋㅋㅋ!\n");
        }
        else {
            printf("그렇군요!\n");
        }
        Sleep(2000);
        system("cls");
        //태어난날 물어보고 설문 시작하기
        printf("그럼");
        for (int i = 0; i < 3; i++) {
            printf(".");
            Sleep(1000);
        }
        printf("%s 님은 %d년 %d월 %d일 생 맞으신거죠?", name, year, month, day);
        Sleep(2000);
        system("cls");

        printf("이제 바로 설문조사 시작할께요!!!");
        Sleep(2000);
        system("cls");
        printf("설문조사는 총 4개의 문제로 구성되어 있습니다.");
        for (int i = 0; i < 3; i++) {
            printf(".");
            Sleep(1000);
        }
        printf("문제를 천천히 읽어보시고 보기 1과 보기2 중 자신과 더 맞는 숫자를 입력해주시기 바랍니다.");
        Sleep(5000);
        system("cls");
        return 0;
    }
    if (a == 2) {
        return 1;
    }
}
int main()
{   //변수선언
    system("color F0"); //화면 색깔 바꿔줌
    int ans;
    printf("설문조사에 응하시겠습니까?? \n 1. 예. 2. 아니오");
    scanf("%d", &ans);
    if (checking(ans) == 1) {
        return 0;
    }
    //여기서 수를 저장해야함. 1이라하면 I를 저장하고 반대면 E를 저장함
    int Q1_1 = 0, Q1_2 = 0, Q1_3 = 0;
    printf("1_1번 \n 당신은\n1.친구들과 같이 노는것을 즐긴다.\n2.집에 혼자 있는 것을 즐긴다.\n");
    scanf("%d", &Q1_1);
    Sleep(500);

    printf("1_2번 \n 당신은 다른 사람들에게 자신을 소개하는 것을 어려워 합니다.\n1.아니오\n2.예\n");
    scanf("%d", &Q1_2);
    Sleep(500);

    printf("1_3번 \n 보통 대화를 먼저 시작하지 않습니다.\n1.아니오\n2.예\n");
    scanf("%d", &Q1_3);
    Sleep(500);

    if ((Q1_1 + Q1_2 + Q1_3) <= 4) {
        name[1] = 'I';
        name[2] = '0'; //쓰레기 값 없애주기 위함
    }
    else {
        name[2] = 'E';
        name[1] = '0';
    }
    Sleep(2000);
    system("cls");

    // 아래도 위와 같은 방법으로 진행한다.
    int Q2_1 = 0, Q2_2 = 0, Q2_3 = 0;
    printf("2_1번 \n 당신은\n1.감각적인 사람이다.\n2.직관적인 사람이다.\n");
    scanf("%d", &Q2_1);
    Sleep(500);

    printf("2_2번 \n자신의 행동이 다른 사람들에게 어떠한 영향을 주는 지에 대해 거의 걱정하지 않습니다.\n1.아니오\n2.예\n");
    scanf("%d", &Q2_2);
    Sleep(500);

    printf("2_3번 \n본인이 창의적이기보다 현실적인 사람이라고 생각합니다.\n1.아니오\n2.예\n");
    scanf("%d", &Q2_3);
    Sleep(500);

    if ((Q2_1 + Q2_2 + Q2_3) <= 4) {
        name[3] = 'S';
        name[4] = '0';
    }
    else {
        name[4] = 'N';
        name[3] = '0';
    }
    Sleep(2000);
    system("cls");

    int Q3_1 = 0, Q3_2 = 0, Q3_3 = 0;
    printf("3_1번 \n 당신은\n1.진실과 사실이 더 중요하다.\n2.가족 친구 관계가 더 중요하다.\n");
    scanf("%d", &Q3_1);
    Sleep(500);

    printf("3_2번 \n논쟁에서 이기는 것이 상대방을 불쾌하지 않도록 하는 것보다 더 중요합니다.\n1.예\n2.아니오\n");
    scanf("%d", &Q3_2);
    Sleep(500);

    printf("3_3번 \n토론 시 사람들의 민감한 반응보다 보다 진실을 더 중요시해야 합니다.\n1.예\n2.아니오\n");
    scanf("%d", &Q3_3);
    Sleep(500);

    if ((Q3_1 + Q3_2 + Q3_3) <= 4) {
        name[5] = 'T';
        name[6] = '0';
    }
    else {
        name[6] = 'F';
        name[5] = '0';
    }
    Sleep(2000);
    system("cls");

    int Q4_1 = 0, Q4_2 = 0, Q4_3 = 0;
    printf("4번 \n 당신은 계획을 세울때\n1.철저하게 미리 계획을 세운다\n2.상황에 따라 계획을 유연하게 수정해간다.");
    scanf("%d", &Q4_1);
    Sleep(500);

    printf("4_2번 \n업무 스타일이 체계적이고 조직적이라기 보다는 그때 그때 몰아서 처리하는 편입니다.\n1.아니오\n2.예\n");
    scanf("%d", &Q4_2);
    Sleep(500);

    printf("4_3번 \n보통 여행 계획은 철저하게 세우는 편입니다.\n1.예\n2.아니오\n");
    scanf("%d", &Q4_3);
    Sleep(500);

    if ((Q4_1 + Q4_2 + Q4_3) <= 4) {
        name[7] = 'P';
        name[8] = '0';
    }
    else {
        name[8] = 'J';
        name[7] = '0';
    }
    Sleep(2000);
    system("cls");

    //마지막 출력할때 위의 4개의 변수를 모두 모아서 한번에 출력해야함 예) ENTP와 같이 출력
    //2^4가지 경우의 수 고려해서 각자 설명 추가해서 적음

    for (int i = 1; i <= 8; i++) {
        if (name[i] != '0') {
            printf("당신의 MBTI 는 %c 입니다", name[i]);
        }
    }
}