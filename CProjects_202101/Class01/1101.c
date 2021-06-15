#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
int check369(int n) {  //숫자에 3, 6, 9가 들어가는지 확인 + 3, 6, 9의 숫자의 개수를 리턴
    int len;
    int n1;
    n1 = n;
    int count = 0;
    // 자리수 확인
    for (int i = 1; n > 0; i++) {
        n = n / 10;
        len = i;
    }
    int arr[10] = { 0 , };
    // 각 자리의 숫자를 배열에 입력
    for (int i = 0; i < len; i++) {
        arr[i] = n1 % 10;
        n1 = n1 / 10;
    }
    // 3, 6, 9 개수를 확인
    for (int i = 0; i < len; i++) {
        if (arr[i] == 3 || arr[i] == 6 || arr[i] == 9) {
            count++;
        }
    }
    return count;
}
void game369(int n, int gg) { // 369 실행 시켜주는 프로그램
    int i = 1;
    int m = 0;
    int arrx[2] = { 1, };
    srand(time(NULL)); // 난이도 '하'에서 사용
    if (gg == 1) { // 난이도 상의 경우 
        for (; i <= n; ) {
            // 컴퓨터 입력 차례
            if (i % 2 == 1) {
                if (check369(i) > 0) { // 3, 6, 9 가 있을때 0을 출력하는 경우
                    for (int j = 0; j < check369(i); j++) {
                        Sleep(200);
                        printf("0 ");
                    }
                    printf("\n");
                }
                else if (check369(i) == 0) { // 3, 6, 9 가 없을떄 그대로 역할을 출력
                    Sleep(500);
                    printf("%d\n", i);
                }
                i++;
            }
            // 사람의 입력 차례
            if (i % 2 == 0) {
                if (check369(i) > 0) {
                    if (check369(i) > 0) {
                        for (int j = 0; j < check369(i); j++) {
                            scanf("%d", &arrx[j]);
                        }
                    }
                    if (arrx[check369(i) - 1] != 0) {
                        printf("틀렸습니다, 실력을 늘려서 오세요");
                        return;
                    }
                }
                else if (check369(i) == 0) { // 틀린 경우
                    scanf("%d", &m);
                    if (m != i) {
                        printf("틀렸습니다, 실력을 늘려오세요");
                        return;
                    }
                }
                i++;
            }
            // 끝까지 갔을 경우 사람 승
            if (i == 501) {
                printf("you win, 정말 잘하시는 군요");
                return;
            }
        }
    }
    int loose = 0;
    while (loose <= 50) { // 컴터가 질 숫자
        loose = rand() % 99 + 1;
    }
    if (gg == 2) { // 난이도 하
        for (; i <= n; ) {
            // 위 코드와 동일
            if (i % 2 == 1) {
                if (check369(i) > 0) {
                    for (int j = 0; j < check369(i); j++) {
                        Sleep(200);
                        printf("0 ");
                    }
                    printf("\n");
                }
                else if (check369(i) == 0) {
                    Sleep(500);
                    printf("%d\n", i);
                }
                i++;
            }
            if (i % 2 == 0) {
                if (check369(i) > 0) {
                    if (check369(i) > 0) {
                        for (int j = 0; j < check369(i); j++) {
                            scanf("%d", &arrx[j]);
                        }
                    }
                    if (arrx[check369(i) - 1] != 0) {
                        printf("틀렸습니다, 실력을 늘려서 오세요");
                        return;
                    }
                }
                else if (check369(i) == 0) {
                    scanf("%d", &m);
                    if (m != i) {
                        printf("틀렸습니다, 실력을 늘려오세요");
                        return;
                    }
                }
                i++;
            }
            if (i == loose) { // 컴터가 질 숫자에 도착
                printf("you win, 정말 잘하시는 군요");
                return;
            }
        }
    }
}
int main()
{
back:
    // 게임 선택
    printf("어떤 것을 할 것인가요\n");
    printf("1. 커플 궁합\n2. 오늘의 운세\n3. 369 게임\n");
    int choose;
    scanf("%d", &choose);
    system("cls");
    // 커플 궁합 게임 실행
    if (choose == 1) {
        // 게임 설명
        printf("         커플 궁합 봐드립니다..        \n");
        Sleep(1000);
        printf("         궁합을 보고 싶은 두 분의 이름 획수를 다음과 같이 각각 입력하여 주세요. ex) A  A  A 0 B  B  B 0\n");
        Sleep(1000);
        printf("         두 분의 이름 길이가 2이상 차이 나면 이름 궁합을 봐드릴 수 없습니다.. \n");
        Sleep(1000);
        printf("         이름이 긴 분을 먼저 입력해주세요 \n");
        Sleep(1000);
        printf("         각각 획수를 입력하고 끝에 '0'을 입력 해주세요!!! \n");
        // 진행 여부 확인
        printf("계속 진행할것인 가요??\n");
        printf("예 1. , 아니요 2.\n");
        int con;
        scanf("%d", &con);
        system("cls");
        if (con == 2) {
            goto back;
            system("cls");// console창 깨끗이 
        }
        // 변수 선언
        char name[100] = { 0, };
        char name1[100] = { 0 , };
        int arr[100];
        int arr1[100];
        int arr2[100];
        int n;
        int n1;
        int m;
        // 두명의 이름 입력 받기 
        printf("\n\n\n");
        printf("         로딩중....\n");
        Sleep(5000);
        printf("         두분의 이름을 입력 해주세요...\n");
        printf("       ㅡ> : ");
        scanf("%s %s", &name, &name1);
        // 두명 이름 획수 배열 2개로 입력 받기
        printf("         획수를 입력 해주세요\n");
        for (int i = 0; ; i++)
        {
            scanf("%d", &arr[i]);
            if (arr[i] == 0)
            {
                n = i;
                break;
            }
        }
        for (int i = 0; ; i++)
        {
            scanf("%d", &arr1[i]);
            if (arr1[i] == 0)
            {
                n1 = i;
                break;
            }
        }
        // 두 배열의 값을 한 배열로 합치기
        for (int i = 0; i <= n; i++)
        {
            if (i <= n)
            {
                arr2[2 * i] = arr[i];
            }
            if (i <= n1)
            {
                arr2[2 * i + 1] = arr1[i];
            }
        }
        // 이름 궁합 계산하기
        m = n + n1;
        while (m > 2)
        {
            for (int i = 0; i < m; i++)
            {
                arr2[i] = (arr2[i] + arr2[i + 1]) % 10;
            }
            m--;
        }
        // 궁합 점수 출력하기
        printf("\n\n\n");
        printf("         로딩 중.....\n");
        Sleep(5000);
        system("cls");
        printf("         %s님 과 %s님의 이름 궁합 점수는 %d점 입니다.", name, name1, arr2[0] * 10 + arr2[1]);
    }
    // 오늘의 운세 봐주기
    else if (choose == 2) {
        srand(time(NULL));
        int ranum;
        ranum = rand() % 101;
        printf("당신의 이름을 입력하세요\n");
        char yourname[100] = { 0 , };
        scanf("%s", yourname);
        if (ranum >= 90) {
            printf("당신의 오늘의 운세는 %d점입니다. \n오늘은 모든게 잘 될거에요. 사랑하는 사람이 있다면 고백해보세요 ", ranum);
        }
        else if (ranum >= 80) {
            printf(" 당신의 오늘의 운세는 %d점입니다. \n 오늘의 운세는 좋은 편이에요, 가족과 나들이를 떠나보는 것은 어떤가요?", ranum);
        }
        else if (ranum >= 70) {
            printf(" 당신의 오늘의 운세는 %d점입니다. \n 오늘의 운세는 좋은 편입니다, 근처 자판기에 가보세요, 바닥에 동전이 있을수도 있어요", ranum);
        }
        else {
            printf(" 당신의 오늘의 운세는 %d점입니다. \n 오늘은 행동을 조심하시고 땅을 잘 보고 다니세요", ranum);
        }
    }
    // 3, 6, 9를 실행
    else if (choose == 3) {
        printf("3 6 9 게임을 하고 싶습니까? \n");
        printf("1. 예, 2. 아니요");
        int choose1;
        scanf("%d", &choose1);
        system("cls");
        printf("3또는 6 또는 9의 개수만큼 0을 띄어써서 입력해주세요");
        if (choose1 == 2) {
            goto back;
        }
        printf("난이도를 고르세요\n 1. 상 2. 하\n");
        int hardless;
        scanf("%d", &hardless);
        system("cls");
        int uu = 500;
        game369(uu, hardless);
    }
    else {
        goto back;
    }
}