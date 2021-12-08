#include <stdio.h>
#include <stdlib.h>          //srand()
#include <time.h>            //time_t
#include <string.h>          //strlen()

typedef struct {              //입력 정보를 저장하는 구조체
    int lettercnt;           //입력한 문자의 개수
    unsigned int timechai;   //입력하는 데 걸린 시간
    int corrcnt;             //알맞게 입력한 문자의 개수
    int wordcnt;             //입력한 단어의 개수
}Result;

float findmax(float a, float b);                 //더 큰 수를 반환해주는 함수
void getinput(void);                            //입력 받는 함수(형식을 고른다)
char* difinput(void);                           //난이도를 입력받는 함수
void letters(void);                             //글자 입력을 받는 함수
void words(char* difficulty);                   //단어 입력을 받는 함수
void sentences(char* difficulty);               //난이도 입력을 받는 함수
void addtolist(char* difficulty);               //단어/문장을 리스트에 추가하는 함수
int countwords(char* str);                      //문자열에서 단어의 개수를 구하는 함수
void printresult(Result* r);                    //결과 출력 함수
enum choice { letter = 1, word, sentence, add, EXIT };   //형식 선택 경우
float newrecord;                                //최고기록 저장 변수

int main() {
    printf("***(영어)타자 연습 프로그램***\n");

    //입력 받는 함수로 이동
    getinput();

    return 0;
}

float findmax(float a, float b) {
    //만약 a가 b보다 크면 a를 반환하고, 아닐 경우에는 b를 반환한다.
    return a > b ? a : b;
}

void getinput(void) {
    //enum으로 입력받기 위해서 변수를 선언한다.
    enum choice input;

    //다른 함수에서 초과해서 입력 받았을 경우에 제대로 된 값을 입력받지 못하기 때문에 입력 버퍼를 비운다.
    rewind(stdin);

    printf("1. letters\n");
    printf("2. words\n");
    printf("3. sentences\n");
    printf("4. add\n");         //단어 또는 문자 추가
    printf("5. exit\n");
    printf("다음 중 선택하세요 : ");

    //선택지를 입력받지만, 1~4가 아니라면 다시 입력받는다.
    while (1) {
        scanf("%d", &input);
        if (input > 5 || input < 1) {
            printf("다시 입력하세요 : ");
            scanf("%d", &input);
        }
        else
            break;
    }

    //enum을 사용해서 switch case 문을 보기 쉽게 만들어 준다.
    //입력받은 값에 따라 실행 함수로 이동한다.
    switch (input) {
    case letter: letters(); break;
        //아래의 세 경우에는 난이도도 입력받는다.
    case word: words(difinput()); break;
    case sentence: sentences(difinput()); break;
    case add: addtolist(difinput()); break;
    case EXIT: break;
    }
}

char* difinput(void) {
    //getinput()에서와 같은 이유로 입력 버퍼를 비운다.
    rewind(stdin);

    //지역 변수로 문자열을 선언할 경우 함수에서 나갈 때 변수가 사라진다. 그렇기 때문에 동적 할당을 하여 heap 메모리에 저장을 해야 없어지지 않는다.
    char* input = (char*)malloc(sizeof(char) * 15);
    printf("난이도를 선택하세요(easy,intermediate,hard) : ");

    //범위를 만족할 때까지 입력받는다.
    while (1) {
        scanf("%s", input);
        if (strcmp(input, "easy") != 0 && strcmp(input, "intermediate") != 0 && strcmp(input, "hard") != 0) {
            printf("다시 입력하세요 : ");
            scanf("%s", input);
        }
        else
            break;
    }

    //입력된 난이도를 반환해준다.
    return input;
}

void letters(void) {
    int n;               //글자의 개수
    char* let;           //글자 배열을 저장할 문자열
    time_t t1, t2;        //시간 차이를 구하기 위해 시간 변수 2개 선언
    printf("입력할 글자의 개수 : ");
    scanf("%d", &n);

    //글자의 개수에는 띄어쓰기(공백)도 포함시킨다.
    n = 2 * n - 1;

    //결과 출력 함수로 보낼 구조체 포인터 선언 및 동적 할당
    Result* r = (Result*)malloc(sizeof(Result));
    r->corrcnt = n;
    r->lettercnt = n;
    r->wordcnt = 0;

    //랜덤 문자를 받아줄 배열 동적 할당
    let = (char*)malloc(sizeof(char) * n);

    printf("\n");
    srand((unsigned int)time(NULL));
    //글자-공백-글자 순으로 문자열을 만들고 출력한다.(문자로 시작하고 문자로 끝난다.)
    for (int i = 0; i < n; i++) {
        if (i % 2 != 0)
            let[i] = ' ';
        else
            let[i] = rand() % 26 + 97;
        printf("%c", let[i]);
    }
    printf("\n");

    //입력 버퍼를 비운다.
    rewind(stdin);

    //시작 시간=t1
    t1 = (unsigned int)time(NULL);
    for (int i = 0; i < n; i++) {
        //잘못된 글자를 입력할 때마다 corrcnt에서 1씩 뺀다.
        if (getchar() != let[i])
            (r->corrcnt)--;
    }
    t2 = (unsigned int)time(NULL);
    //입력이 끝난 시간=t2
    //difftime으로 t1,t2의 시간 차이를 구한다.
    r->timechai = difftime(t2, t1);

    //결과 출력
    printresult(r);

    //메모리 해제
    free(r);
    free(let);
}

void words(char* difficulty) {
    FILE* fp;
    int n;
    char w[500], filename[25], getword[50], word[50];
    time_t t1, t2;
    printf("입력할 단어의 횟수: ");
    scanf("%d", &n);

    //결과 출력 함수로 보낼 구조체 포인터 선언 및 동적 할당
    Result* r = (Result*)malloc(sizeof(Result));
    r->wordcnt = n;

    strcpy(filename, difficulty);
    strcpy(filename + strlen(difficulty), "words.txt");
    filename[strlen(difficulty) + 13] = '\0';

    //파일 열기에 실패했을 경우에 함수 마지막 부분으로 이동
    if ((fp = fopen(filename, "r")) == NULL) {
        printf("Failed to open the %s file. Please check if you have the file.\n", filename);
        goto endwords;
    }

    //단어들을 공백과 함께 하나의 문자열로 합친다.
    int index = 0;
    for (int i = 0; i < n; i++) {
        //파일에서 임의의 줄에 있는 문자열을 추출하는 방법
        //첫줄부터 마지막 줄까지 교체할지 안할지 랜덤으로 정해준다.
        srand((unsigned int)time(NULL));
        int cnt = 1;
        while (fgets(getword, 200, fp) != NULL)
        {
            cnt++;
            if (rand() % (cnt++) == 0)
                strcpy(word, getword);
        }

        //'\n'이 포함되기 때문에 strlen보다 하나 적게 입력한다.
        r->lettercnt += strlen(word) - 1;
        for (int j = 0; j < strlen(word) - 1; j++) {
            w[index++] = word[j];
        }
        w[index++] = ' ';
    }
    //띄어쓰기(공백)도 lettercnt에 포함시킨다.
    r->lettercnt += r->wordcnt - 1;
    //corrcnt에 lettercnt 값을 넣고 틀릴때 마다 1씩 뺀다.
    r->corrcnt = r->lettercnt;

    //문자열을 출력한다.
    printf("\n");
    for (int i = 0; i < r->lettercnt; i++) {
        printf("%c", w[i]);
    }
    printf("\n");

    //입력 버퍼를 비운다.
    rewind(stdin);

    //시작 시간=t1
    t1 = (unsigned int)time(NULL);
    for (int i = 0; i < r->lettercnt; i++) {
        //만들어준 문자열과 다른 값 입력시 corrcnt에서 1씩 뺀다.
        if (getchar() != w[i])
            (r->corrcnt)--;
    }
    //입력 완료 시간=t2, difftime으로 시간 차이를 구해준다.
    t2 = (unsigned int)time(NULL);
    r->timechai = difftime(t2, t1);

    //결과 출력
    printresult(r);
endwords:
    //메모리 해제
    free(r);
    free(difficulty);
}

void sentences(char* difficulty) {
    FILE* fp;
    char sentence[200], filename[30], getsentence[200];
    int n;
    time_t t1, t2;
    printf("입력할 문장의 횟수: ");
    scanf("%d", &n);

    //결과 출력 함수로 보낼 구조체 포인터 선언 및 동적 할당
    Result* r = (Result*)malloc(sizeof(Result));

    strcpy(filename, difficulty);
    strcpy(filename + strlen(difficulty), "sentences.txt");
    filename[strlen(difficulty) + 13] = '\0';

    //파일 열기에 실패했을 경우에 함수 마지막 부분으로 이동
    if ((fp = fopen(filename, "r")) == NULL) {
        printf("Failed to open the %s file. Please check if you have the file.\n", filename);
        goto endsentence;
    }

    //시작 시간=t1
    t1 = (unsigned int)time(NULL);
    //n개의 선정된 문자를 하나씩 출력하고 입력받는다.
    for (int i = 0; i < n; i++) {
        //첫줄부터 마지막 줄까지 교체할지 안할지 랜덤으로 정해준다.
        int cnt = 1;
        while (fgets(getsentence, 200, fp) != NULL)
        {
            srand((unsigned int)time(NULL));
            cnt++;
            if (rand() % (cnt++) == 0)
                strcpy(sentence, getsentence);
        }

        r->wordcnt += countwords(sentence);
        r->lettercnt += strlen(sentence);
        r->corrcnt += r->lettercnt;

        printf("\n%s", sentence);
        //입력 버퍼를 비운다.
        rewind(stdin);

        //다른 값 입력시 corrcnt에서 1씩 뺀다.
        for (int j = 0; j < strlen(sentence); j++) {
            if (sentence[j] != getchar()) {
                (r->corrcnt)--;
            }
        }
    }
    //입력 완료 시간=t2, difftime으로 시간 차이를 구한다.
    t2 = (unsigned int)time(NULL);
    r->timechai += difftime(t2, t1);
    fclose(fp);

    //결과 출력
    printresult(r);

endsentence:
    //메모리 해제
    free(r);
    free(difficulty);
}

void addtolist(char* difficulty) {
    int input;
    char filename[30], newlist[200];
    FILE* fp;
    //단어, 문장 중에서 선택
    printf("단어, 문장 중 무엇을 추가하시겠습니까?(단어-1,문장-2) : ");

    //올바르게 입력할 때까지 반복한다.
    while (1) {
        scanf("%d", &input);
        if (input < 1 || input>2)
            printf("다시 입력하세요: ");
        else
            break;
    }

    //단어, 문장, 난이도에 따라서 파일명 문자열을 만들어준다.
    strcpy(filename, difficulty);
    if (input == 1) {
        strcpy(filename + strlen(difficulty), "words.txt");
        filename[strlen(difficulty) + 9] = '\0';
    }
    else {
        strcpy(filename + strlen(difficulty), "sentences.txt");
        filename[strlen(difficulty) + 13] = '\0';
    }

    //추가하고 싶은 단어/문장을 입력받는다.
    printf("추가하고 싶은 단어/문장을 입력하세요: ");
    rewind(stdin);
    fgets(newlist, 50, stdin);

    //파일 열기에 실패했을 경우
    if ((fp = fopen(filename, "a")) == NULL)
        printf("Failed to open the %s file, or name is incorrect.\n", filename);
    //파일을 열었으면 입력한 단어/문장을 파일에 추가한다.
    //'\n'은 포함되어 있기 때문에 줄 넘김이 된다.
    else {
        fprintf(fp, "%s", newlist);
        if (input == 1)
            printf("단어가 추가되었습니다.\n\n");
        else
            printf("문장이 추가되었습니다.\n\n");
    }

    fclose(fp);

    //다시 입력 받는 함수로 이동
    getinput();
}

int countwords(char* str) {
    //문자열에서 단어의 개수를 반환해주는 함수이다.
    int cnt = 1;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == ' ') {
            cnt++;
        }
    }
    return cnt;
}

void printresult(Result* r) {
    //gross wpm은 한 단어를 무조건 5글자로 가정했을 때의 분당 단어 수이다.
    float gross_wpm = (float)((float)r->lettercnt / 5) / ((float)r->timechai / 60);
    float wpm = 0;

    printf("\n시간: %d초\n", r->timechai);
    printf("속도: %.1fgross wpm", gross_wpm);
    if (r->wordcnt > 0) {
        //만약 단어 수가 0보다 클때 분당 단어 수
        wpm = ((float)r->wordcnt / r->timechai) * 60;
        printf(", %.1fwpm", wpm);
    }
    //정확도 출력
    printf("\n정확도: %.1f%%\n", ((float)r->corrcnt / r->lettercnt) * 100);

    //만약 gross wpm 또는 wpm이 전의 최고기록보다 빠르다면 그 값으로 바꿔준다.
    newrecord = findmax(newrecord, findmax(gross_wpm, wpm));
    printf("최고 기록: %.1fwpm\n\n", newrecord);

    //형식 입력
    getinput();
}
