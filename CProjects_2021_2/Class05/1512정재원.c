#include <stdio.h>
#include <stdlib.h>          //srand()
#include <time.h>            //time_t
#include <string.h>          //strlen()

typedef struct {              //�Է� ������ �����ϴ� ����ü
    int lettercnt;           //�Է��� ������ ����
    unsigned int timechai;   //�Է��ϴ� �� �ɸ� �ð�
    int corrcnt;             //�˸°� �Է��� ������ ����
    int wordcnt;             //�Է��� �ܾ��� ����
}Result;

float findmax(float a, float b);                 //�� ū ���� ��ȯ���ִ� �Լ�
void getinput(void);                            //�Է� �޴� �Լ�(������ ����)
char* difinput(void);                           //���̵��� �Է¹޴� �Լ�
void letters(void);                             //���� �Է��� �޴� �Լ�
void words(char* difficulty);                   //�ܾ� �Է��� �޴� �Լ�
void sentences(char* difficulty);               //���̵� �Է��� �޴� �Լ�
void addtolist(char* difficulty);               //�ܾ�/������ ����Ʈ�� �߰��ϴ� �Լ�
int countwords(char* str);                      //���ڿ����� �ܾ��� ������ ���ϴ� �Լ�
void printresult(Result* r);                    //��� ��� �Լ�
enum choice { letter = 1, word, sentence, add, EXIT };   //���� ���� ���
float newrecord;                                //�ְ��� ���� ����

int main() {
    printf("***(����)Ÿ�� ���� ���α׷�***\n");

    //�Է� �޴� �Լ��� �̵�
    getinput();

    return 0;
}

float findmax(float a, float b) {
    //���� a�� b���� ũ�� a�� ��ȯ�ϰ�, �ƴ� ��쿡�� b�� ��ȯ�Ѵ�.
    return a > b ? a : b;
}

void getinput(void) {
    //enum���� �Է¹ޱ� ���ؼ� ������ �����Ѵ�.
    enum choice input;

    //�ٸ� �Լ����� �ʰ��ؼ� �Է� �޾��� ��쿡 ����� �� ���� �Է¹��� ���ϱ� ������ �Է� ���۸� ����.
    rewind(stdin);

    printf("1. letters\n");
    printf("2. words\n");
    printf("3. sentences\n");
    printf("4. add\n");         //�ܾ� �Ǵ� ���� �߰�
    printf("5. exit\n");
    printf("���� �� �����ϼ��� : ");

    //�������� �Է¹�����, 1~4�� �ƴ϶�� �ٽ� �Է¹޴´�.
    while (1) {
        scanf("%d", &input);
        if (input > 5 || input < 1) {
            printf("�ٽ� �Է��ϼ��� : ");
            scanf("%d", &input);
        }
        else
            break;
    }

    //enum�� ����ؼ� switch case ���� ���� ���� ����� �ش�.
    //�Է¹��� ���� ���� ���� �Լ��� �̵��Ѵ�.
    switch (input) {
    case letter: letters(); break;
        //�Ʒ��� �� ��쿡�� ���̵��� �Է¹޴´�.
    case word: words(difinput()); break;
    case sentence: sentences(difinput()); break;
    case add: addtolist(difinput()); break;
    case EXIT: break;
    }
}

char* difinput(void) {
    //getinput()������ ���� ������ �Է� ���۸� ����.
    rewind(stdin);

    //���� ������ ���ڿ��� ������ ��� �Լ����� ���� �� ������ �������. �׷��� ������ ���� �Ҵ��� �Ͽ� heap �޸𸮿� ������ �ؾ� �������� �ʴ´�.
    char* input = (char*)malloc(sizeof(char) * 15);
    printf("���̵��� �����ϼ���(easy,intermediate,hard) : ");

    //������ ������ ������ �Է¹޴´�.
    while (1) {
        scanf("%s", input);
        if (strcmp(input, "easy") != 0 && strcmp(input, "intermediate") != 0 && strcmp(input, "hard") != 0) {
            printf("�ٽ� �Է��ϼ��� : ");
            scanf("%s", input);
        }
        else
            break;
    }

    //�Էµ� ���̵��� ��ȯ���ش�.
    return input;
}

void letters(void) {
    int n;               //������ ����
    char* let;           //���� �迭�� ������ ���ڿ�
    time_t t1, t2;        //�ð� ���̸� ���ϱ� ���� �ð� ���� 2�� ����
    printf("�Է��� ������ ���� : ");
    scanf("%d", &n);

    //������ �������� ����(����)�� ���Խ�Ų��.
    n = 2 * n - 1;

    //��� ��� �Լ��� ���� ����ü ������ ���� �� ���� �Ҵ�
    Result* r = (Result*)malloc(sizeof(Result));
    r->corrcnt = n;
    r->lettercnt = n;
    r->wordcnt = 0;

    //���� ���ڸ� �޾��� �迭 ���� �Ҵ�
    let = (char*)malloc(sizeof(char) * n);

    printf("\n");
    srand((unsigned int)time(NULL));
    //����-����-���� ������ ���ڿ��� ����� ����Ѵ�.(���ڷ� �����ϰ� ���ڷ� ������.)
    for (int i = 0; i < n; i++) {
        if (i % 2 != 0)
            let[i] = ' ';
        else
            let[i] = rand() % 26 + 97;
        printf("%c", let[i]);
    }
    printf("\n");

    //�Է� ���۸� ����.
    rewind(stdin);

    //���� �ð�=t1
    t1 = (unsigned int)time(NULL);
    for (int i = 0; i < n; i++) {
        //�߸��� ���ڸ� �Է��� ������ corrcnt���� 1�� ����.
        if (getchar() != let[i])
            (r->corrcnt)--;
    }
    t2 = (unsigned int)time(NULL);
    //�Է��� ���� �ð�=t2
    //difftime���� t1,t2�� �ð� ���̸� ���Ѵ�.
    r->timechai = difftime(t2, t1);

    //��� ���
    printresult(r);

    //�޸� ����
    free(r);
    free(let);
}

void words(char* difficulty) {
    FILE* fp;
    int n;
    char w[500], filename[25], getword[50], word[50];
    time_t t1, t2;
    printf("�Է��� �ܾ��� Ƚ��: ");
    scanf("%d", &n);

    //��� ��� �Լ��� ���� ����ü ������ ���� �� ���� �Ҵ�
    Result* r = (Result*)malloc(sizeof(Result));
    r->wordcnt = n;

    strcpy(filename, difficulty);
    strcpy(filename + strlen(difficulty), "words.txt");
    filename[strlen(difficulty) + 13] = '\0';

    //���� ���⿡ �������� ��쿡 �Լ� ������ �κ����� �̵�
    if ((fp = fopen(filename, "r")) == NULL) {
        printf("Failed to open the %s file. Please check if you have the file.\n", filename);
        goto endwords;
    }

    //�ܾ���� ����� �Բ� �ϳ��� ���ڿ��� ��ģ��.
    int index = 0;
    for (int i = 0; i < n; i++) {
        //���Ͽ��� ������ �ٿ� �ִ� ���ڿ��� �����ϴ� ���
        //ù�ٺ��� ������ �ٱ��� ��ü���� ������ �������� �����ش�.
        srand((unsigned int)time(NULL));
        int cnt = 1;
        while (fgets(getword, 200, fp) != NULL)
        {
            cnt++;
            if (rand() % (cnt++) == 0)
                strcpy(word, getword);
        }

        //'\n'�� ���ԵǱ� ������ strlen���� �ϳ� ���� �Է��Ѵ�.
        r->lettercnt += strlen(word) - 1;
        for (int j = 0; j < strlen(word) - 1; j++) {
            w[index++] = word[j];
        }
        w[index++] = ' ';
    }
    //����(����)�� lettercnt�� ���Խ�Ų��.
    r->lettercnt += r->wordcnt - 1;
    //corrcnt�� lettercnt ���� �ְ� Ʋ���� ���� 1�� ����.
    r->corrcnt = r->lettercnt;

    //���ڿ��� ����Ѵ�.
    printf("\n");
    for (int i = 0; i < r->lettercnt; i++) {
        printf("%c", w[i]);
    }
    printf("\n");

    //�Է� ���۸� ����.
    rewind(stdin);

    //���� �ð�=t1
    t1 = (unsigned int)time(NULL);
    for (int i = 0; i < r->lettercnt; i++) {
        //������� ���ڿ��� �ٸ� �� �Է½� corrcnt���� 1�� ����.
        if (getchar() != w[i])
            (r->corrcnt)--;
    }
    //�Է� �Ϸ� �ð�=t2, difftime���� �ð� ���̸� �����ش�.
    t2 = (unsigned int)time(NULL);
    r->timechai = difftime(t2, t1);

    //��� ���
    printresult(r);
endwords:
    //�޸� ����
    free(r);
    free(difficulty);
}

void sentences(char* difficulty) {
    FILE* fp;
    char sentence[200], filename[30], getsentence[200];
    int n;
    time_t t1, t2;
    printf("�Է��� ������ Ƚ��: ");
    scanf("%d", &n);

    //��� ��� �Լ��� ���� ����ü ������ ���� �� ���� �Ҵ�
    Result* r = (Result*)malloc(sizeof(Result));

    strcpy(filename, difficulty);
    strcpy(filename + strlen(difficulty), "sentences.txt");
    filename[strlen(difficulty) + 13] = '\0';

    //���� ���⿡ �������� ��쿡 �Լ� ������ �κ����� �̵�
    if ((fp = fopen(filename, "r")) == NULL) {
        printf("Failed to open the %s file. Please check if you have the file.\n", filename);
        goto endsentence;
    }

    //���� �ð�=t1
    t1 = (unsigned int)time(NULL);
    //n���� ������ ���ڸ� �ϳ��� ����ϰ� �Է¹޴´�.
    for (int i = 0; i < n; i++) {
        //ù�ٺ��� ������ �ٱ��� ��ü���� ������ �������� �����ش�.
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
        //�Է� ���۸� ����.
        rewind(stdin);

        //�ٸ� �� �Է½� corrcnt���� 1�� ����.
        for (int j = 0; j < strlen(sentence); j++) {
            if (sentence[j] != getchar()) {
                (r->corrcnt)--;
            }
        }
    }
    //�Է� �Ϸ� �ð�=t2, difftime���� �ð� ���̸� ���Ѵ�.
    t2 = (unsigned int)time(NULL);
    r->timechai += difftime(t2, t1);
    fclose(fp);

    //��� ���
    printresult(r);

endsentence:
    //�޸� ����
    free(r);
    free(difficulty);
}

void addtolist(char* difficulty) {
    int input;
    char filename[30], newlist[200];
    FILE* fp;
    //�ܾ�, ���� �߿��� ����
    printf("�ܾ�, ���� �� ������ �߰��Ͻðڽ��ϱ�?(�ܾ�-1,����-2) : ");

    //�ùٸ��� �Է��� ������ �ݺ��Ѵ�.
    while (1) {
        scanf("%d", &input);
        if (input < 1 || input>2)
            printf("�ٽ� �Է��ϼ���: ");
        else
            break;
    }

    //�ܾ�, ����, ���̵��� ���� ���ϸ� ���ڿ��� ������ش�.
    strcpy(filename, difficulty);
    if (input == 1) {
        strcpy(filename + strlen(difficulty), "words.txt");
        filename[strlen(difficulty) + 9] = '\0';
    }
    else {
        strcpy(filename + strlen(difficulty), "sentences.txt");
        filename[strlen(difficulty) + 13] = '\0';
    }

    //�߰��ϰ� ���� �ܾ�/������ �Է¹޴´�.
    printf("�߰��ϰ� ���� �ܾ�/������ �Է��ϼ���: ");
    rewind(stdin);
    fgets(newlist, 50, stdin);

    //���� ���⿡ �������� ���
    if ((fp = fopen(filename, "a")) == NULL)
        printf("Failed to open the %s file, or name is incorrect.\n", filename);
    //������ �������� �Է��� �ܾ�/������ ���Ͽ� �߰��Ѵ�.
    //'\n'�� ���ԵǾ� �ֱ� ������ �� �ѱ��� �ȴ�.
    else {
        fprintf(fp, "%s", newlist);
        if (input == 1)
            printf("�ܾ �߰��Ǿ����ϴ�.\n\n");
        else
            printf("������ �߰��Ǿ����ϴ�.\n\n");
    }

    fclose(fp);

    //�ٽ� �Է� �޴� �Լ��� �̵�
    getinput();
}

int countwords(char* str) {
    //���ڿ����� �ܾ��� ������ ��ȯ���ִ� �Լ��̴�.
    int cnt = 1;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == ' ') {
            cnt++;
        }
    }
    return cnt;
}

void printresult(Result* r) {
    //gross wpm�� �� �ܾ ������ 5���ڷ� �������� ���� �д� �ܾ� ���̴�.
    float gross_wpm = (float)((float)r->lettercnt / 5) / ((float)r->timechai / 60);
    float wpm = 0;

    printf("\n�ð�: %d��\n", r->timechai);
    printf("�ӵ�: %.1fgross wpm", gross_wpm);
    if (r->wordcnt > 0) {
        //���� �ܾ� ���� 0���� Ŭ�� �д� �ܾ� ��
        wpm = ((float)r->wordcnt / r->timechai) * 60;
        printf(", %.1fwpm", wpm);
    }
    //��Ȯ�� ���
    printf("\n��Ȯ��: %.1f%%\n", ((float)r->corrcnt / r->lettercnt) * 100);

    //���� gross wpm �Ǵ� wpm�� ���� �ְ��Ϻ��� �����ٸ� �� ������ �ٲ��ش�.
    newrecord = findmax(newrecord, findmax(gross_wpm, wpm));
    printf("�ְ� ���: %.1fwpm\n\n", newrecord);

    //���� �Է�
    getinput();
}
