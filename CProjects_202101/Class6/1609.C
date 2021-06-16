
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


void scanword_1(int n1, char ko_1[100][100], char en_1[100][100]); // 1 level 단어를 입력받는 함수
void scanword_2(int n2, char ko_2[100][100], char en_2[100][100]); // 2 level   ~~~
void scanword_3(int n3, char ko_3[100][100], char en_3[100][100]); // 3 level   ~~~

// 각각 1, 2, 3, 단계의 퀴즈인 함수
int quize_1(int n1, int score, char ko_1[100][100], char en_1[100][100], char ans_1[100][100]);
int quize_2(int n2, int score, char ko_2[100][100], char en_2[100][100], char ans_2[100][100]);
int quize_3(int n3, int score, char ko_3[100][100], char en_3[100][100], char ans_3[100][100]);

// 각 레벨의 단어를 랜덤하게 섞어주는 함수. 단, 중복은 없다.
void rand_1(int a[100], int n1);
void rand_2(int a[100], int n2);
void rand_3(int a[100], int n3);


int main()
{
    // 변수 선언
    char ko_1[100][100], ko_2[100][100], ko_3[100][100]; // ko_i는 i 난이도의 단어의 한글 뜻
    char en_1[100][100], en_2[100][100], en_3[100][100]; // en_i는 i 난이도의 영어
    int n1 = 0, n2 = 0, n3 = 0;                                // ni는 i 난이도의 단어 개수


    // 게임에 대한 간단한 안내 멘트
    printf("*** 단어의 세계에 오신 것을 환영합니다. 단어 마스터로의 여정을 시작해 봅시다!! ***\n");
    printf("게임 시작 전에 단어를 먼저 입력해 주세요\n\n");


    // 단어 입력
    // 1. 단어 수 입력
    printf("먼저, 각 레벨의 단어수를 알려주세요\n");
    printf("단어의 레벨은 3까지 있어요. 1레벨 단어는 몇 개 인가요?");
    scanf("%d", &n1);
    printf("2레벨은 몇 개 인가요? ");
    scanf("%d", &n2);
    printf("3레벨은 몇 개 인가요? ");
    scanf("%d", &n3);
    // 2. 레벨별 단어 입력
    scanword_1(n1, ko_1, en_1);
    printf("\n");
    scanword_2(n2, ko_2, en_2);
    printf("\n");
    scanword_3(n3, ko_3, en_3);
    printf("\n");


    // 단어 게임 시작
    char ans_1[100][100], ans_2[100][100], ans_3[100][100];
    int score = 0;

    if (quize_1(n1, score, ko_1, en_1, ans_1))
    {
        // 1단계를 통과했다면 2단계 진행
        if (quize_2(n2, score, ko_2, en_2, ans_2))
        {
            //  2단계를 통과했다면 3단계 진행
            if (quize_3(n3, score, ko_3, en_3, ans_3))
            {
                // 축하멘트
                printf("\n\n");
                printf(" *         *         *         *\n");
                printf("***       ***       ***       ***\n");
                printf("****     *****     *****     ****\n");
                printf("*****   *******   *******   *****\n");
                printf("****** ********* ********* ******\n");
                printf("*********************************\n");
                printf("*********************************\n");
            }
        }
    }


    return 0;
}


void scanword_1(int n1, char ko_1[100][100], char en_1[100][100])
{
    printf("좋아요, 1단계부터 입력을 해주세요\n");
    for (int i = 0; i < n1; i++)
    {
        printf("한글 : ");
        scanf("%s", ko_1[i]);
        printf("영어 : ");
        scanf("%s", en_1[i]);
    }
}
void scanword_2(int n2, char ko_2[100][100], char en_2[100][100])
{
    printf("다음으론 2단계\n");
    for (int i = 0; i < n2; i++)
    {
        printf("한글 : ");
        scanf("%s", ko_2[i]);
        printf("영어 : ");
        scanf("%s", en_2[i]);
    }
}
void scanword_3(int n3, char ko_3[100][100], char en_3[100][100])
{
    printf("마지막 3단계!\n");
    for (int i = 0; i < n3; i++)
    {
        printf("한글 : ");
        scanf("%s", ko_3[i]);
        printf("영어 : ");
        scanf("%s", en_3[i]);
    }
}



int quize_1(int n1, int score, char ko_1[100][100], char en_1[100][100], char ans_1[100][100])
{
    int a[100];
    printf("그럼 1단계부터 시작!\n");
    printf("다음 단어의 뜻을 맞춰봐요\n");

    rand_1(a, n1);

    for (int i = 0; i < n1; i++) {
        printf("\n레벨 : 1\n");
        printf("스코어 : %d\n", score);
        printf("%s : ", ko_1[a[i]]);

        scanf("%s", ans_1[i]);

        if (strcmp(en_1[a[i]], ans_1[i]))
        {
            printf("땡!\n\n");
        }
        else {
            printf("정답!\n\n");
            score++;
        }

    }
    if (n1 == score)
    {
        printf("1단계를 모두 맞췄어요!\n");
        printf("그럼 다음 레벨로 고!\n");
        return 1;
    }
    else {
        printf("아쉽네요, 다음에 다시 도전!");
        return 0;
    }
}

int quize_2(int n2, int score, char ko_2[100][100], char en_2[100][100], char ans_2[100][100])
{
    int a[100];
    score = 0;
    printf("벌써 2단계!\n");
    printf("좀 더 힘내서 화이팅~\n");

    rand_2(a, n2);

    for (int i = 0; i < n2; i++) {
        printf("\n레벨 : 2\n");
        printf("스코어 : %d\n", score);
        printf("%s : ", ko_2[a[i]]);

        scanf("%s", ans_2[i]);

        if (strcmp(en_2[a[i]], ans_2[i]))
        {
            printf("땡!\n");
        }
        else {
            printf("정답!\n");
            score++;
        }

    }
    if (n2 == score)
    {
        printf("2단계를 모두 맞췄어요!\n");
        printf("그럼 다음 레벨로 고!\n");
        return 1;
    }
    else {
        printf("아쉽네요, 다음에 다시 도전!");
        return 0;
    }
}
int quize_3(int n3, int score, char ko_3[100][100], char en_3[100][100], char ans_3[100][100])
{
    int a[100];
    score = 0;
    printf("드디어 3단계!!!\n");
    printf("고지가 코앞이에요, 화이팅~\n");

    rand_3(a, n3);

    for (int i = 0; i < n3; i++) {
        printf("\n레벨 : 3\n");
        printf("스코어 : %d\n", score);
        printf("%s : ", ko_3[a[i]]);

        scanf("%s", ans_3[i]);

        if (strcmp(en_3[a[i]], ans_3[i]))
        {
            printf("땡!\n");
        }
        else {
            printf("정답!\n");
            score++;
        }

    }
    if (n3 == score)
    {
        printf("3단계를 모두 맞췄어요!\n");
        printf("축하드려요 단어 마스터가 되었어요!!\n");
        return 1;
    }
    else {
        printf("아쉽네요, 다음에 다시 도전!");
        return 0;
    }
}


void rand_1(int a[100], int n1)
{
    srand(time(NULL));

    for (int i = 0; i < n1; i++)
    {
        a[i] = rand() % n1;

        for (int j = 0; j < i; j++)
        {
            if (a[j] == a[i])
            {
                i--;
                break;
            }
        }
    }
}
void rand_2(int a[100], int n2)
{
    srand(time(NULL));

    for (int i = 0; i < n2; i++)
    {
        a[i] = rand() % n2;

        for (int j = 0; j < i; j++)
        {
            if (a[j] == a[i])
            {
                i--;
                break;
            }
        }
    }
}
void rand_3(int a[100], int n3)
{
    srand(time(NULL));

    for (int i = 0; i < n3; i++)
    {
        a[i] = rand() % n3;

        for (int j = 0; j < i; j++)
        {
            if (a[j] == a[i])
            {
                i--;
                break;
            }
        }
    }
}
