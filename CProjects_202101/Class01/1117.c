#include <stdio.h>
#include <string.h>

char s[15];//사용자1에게 입력받는 단어
char s2[15];//사용자2에게 입력받는 단어
char name1[30];
char name2[30];
char sword[15];//사용자2가 입력할 때 보이는 빈칸
char sword2[15];//사용자1이 입력할 때 보이는 빈칸
int i = 0;
int length;//사용자1 단어의 길이
int length2;//사용자2 단어의 길이
char user;//사용자1이 맞추고자 하는 문자
char user2;//사용자2가 맞추고자 하는 문자
int scnt = 0;//사용자1의 시도횟수를 나타내는 변수
int scnt2 = 0;//사용자2의 시도횟수를 나타내는 변수

int main() {

    printf("    <<행맨 게임입니다.>>\n");
    printf("사용자 1의 이름을 입력하시오 : ");
    scanf("%s", name1);

    printf("\n사용자 2의 이름을 입력하시오 : ");
    scanf("%s", name2);

    printf("\n사용자 1은 문제를 입력하세요 : ");
    printf("\n 문제는 15글자 이하여야 합니다.");
    scanf("%s", s);//문자열 s를 입력받는다.

    length = strlen(s);//입력된 글자 수를 센다.

    for (i = 0; i < length; i++)
        sword[i] = '_';

    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n사용자1이 문제를 냈습니다.\n");

    while (1) {
        printf("\n문자를 입력하세요. ");
        scanf("%c", &user);

        for (i = 0; i < length; i++) {

            if (s[i] == user) {
                sword[i] = user;
            }
        }
        scnt++;
        printf("%s\n", sword);

        if (strcmp(s, sword) == 0) {//두 문자열(사용자 1이 입력한 문자열과 사용자2가 입력한 문자열)이 같으면 멈추기
            break;
        }
    }

    printf("%d번 만에 맞췄습니다.", scnt / 2);


    printf("\n\n\n 첫번째 게임이 끝났습니다.");
    printf("\n 사용자2는 문제를 입력하세요.");
    printf("\n 문제는 15글자 이하여야 합니다.");

    scanf("%s", s2);


    length2 = strlen(s2);//입력된 글자 수를 센다.

    for (i = 0; i < length2; i++)
        sword2[i] = '_';

    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n사용자2가 문제를 냈습니다.\n");

    while (1) {
        printf("\n문자를 입력하세요. ");
        scanf("%c", &user2);

        for (i = 0; i < length2; i++) {

            if (s2[i] == user2) {
                sword2[i] = user2;
            }
        }
        scnt2++;
        printf("%s\n", sword2);

        if (strcmp(s2, sword2) == 0) {//두 문자열(사용자 1이 입력한 문자열과 사용자2가 입력한 문자열)이 같으면 멈추기
            break;
        }
    }

    printf("%d번 만에 맞췄습니다.", scnt2 / 2);

    if (scnt == scnt2) {
        printf("\n\n축하드립니다. 무승부입니다.");
    }
    if (scnt < scnt2) {
        printf("\n\n축하드립니다. %s의 승리입니다.", name2);
    }
    if (scnt > scnt2) {
        printf("\n\n축하드립니다. %s의 승리입니다.", name1);
    }
}