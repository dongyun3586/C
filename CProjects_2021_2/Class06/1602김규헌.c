#include<stdio.h>
#include<stdlib.h>//난수 생성하기 위해
#include<time.h>//난수 생성하기 위해
#include<windows.h>//system("cls"), 즉 화면 지우는 함수를 사용하기 위해
typedef struct { //구조체 사용 Arr:자리배치할 사람 키 random: 자리위치, name:자리배치 할 사람 이름
    int Arr;
    int random;
    char name[40];

}Project;
void swap(int* a, int* b) {//swap함수 pointer 사용
    int tempp;
    tempp = *a;
    *a = *b;
    *b = tempp;
}
int main() {
    Project b[100];
    int width, length; //가로 세로
    int number;//명 수 
    int temp, Data = 0;
    srand(time(NULL));//자리 위치 랜덤
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    printf("■                                                                                        ■\n");
    printf("■                                                                                        ■\n");
    printf("■                                                                                        ■\n");
    printf("■                                                                                        ■\n");
    printf("■                                                                                        ■\n");
    printf("■                              키를 고려한 자리배치 프로그램                             ■\n");
    printf("■                                                                                        ■\n");
    printf("■                                      규칙                                              ■\n");
    printf("■                                                                                        ■\n");
    printf("■                          1. 자리 배치할 인원을 입력한다.                               ■\n");
    printf("■                          2. 가로와 세로에 배치할 인원을 입력한다.                      ■\n");
    printf("■                          3. 자리 배치할 사람의 이름과 키를 입력한다.                   ■\n");
    printf("■                                                                                        ■\n");
    printf("■                                                                                        ■\n");
    printf("■                                                                                        ■\n");
    printf("■                                                                                        ■\n");
    printf("■                                                                                        ■\n");
    printf("■                                                                                        ■\n");
    printf("■                                                                                        ■\n");
    printf("■                                                                                        ■\n");
    printf("■                                                                                        ■\n");
    printf("■                                                                                        ■\n");
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    Sleep(2000);//2초동안 유지
    system("cls");//화면 없애기 
    printf("몇 명을 배치할 것인가요?\n");
    scanf("%d", &number);
    printf("가로와 세로 몇 명씩 배치할 것인가요?\n");
    scanf("%d %d", &width, &length);
    printf("사람이름과 키를 입력해주세요.\n");
    printf(" 이름   키\n");
    for (int i = 0; i < number; i++) {
        scanf("%s", &b[i].name);//이름 입력
        scanf("%d", &b[i].Arr);//키 입력
    }
    system("cls");
    //중복없이 자리위치를 배부하는 코드, 자리는 0~인원수-1까지 총 인원수 만큼 있다. 
    for (int i = 0; i < number; i++) {         //하나씩 비교
        b[i].random = rand() % number;
        for (int j = 0; j < i; j++) {            //같은 수는 무효화
            if (b[j].random == b[i].random) {
                i--;
                break;
            }
        }
    }
    //자리 즉 random에 들어있는 값이 클수록 뒤에 위치한다. 하지만 앞사람이 자신보다 클 때 자리를 바꿔주는 코드이다. 
    for (int i = 0; i < number; i++) {
        for (int j = 1; j < number; j++) {
            if (b[i].random % width == b[j].random % width) {
                if (b[i].Arr > b[j].Arr && b[i].random < b[j].random) {
                    swap(&b[i].random, &b[j].random);
                }
                if (b[i].Arr < b[j].Arr && b[i].random > b[j].random) {
                    swap(&b[i].random, &b[j].random);
                }
            }
        }
    }
    //아까 코드를 한 번 더 써준다. 왜냐하면 1번으로는 정렬이 제대로 되지 않기 때문이다. 
    for (int i = 0; i < number; i++) {
        for (int j = 1; j < number; j++) {
            if (b[i].random % width == b[j].random % width) {
                if (b[i].Arr > b[j].Arr && b[i].random < b[j].random) {
                    swap(&b[i].random, &b[j].random);
                }
                if (b[i].Arr < b[j].Arr && b[i].random > b[j].random) {
                    swap(&b[i].random, &b[j].random);
                }
            }
        }
    }
    //자리값 즉 random 안에 있는 값이 0인 것부터 출력을 하여 자리를 차례대로 출력한다. 
    while (Data != number) {
        for (int i = 0; i < number; i++) {
            for (int j = 0; j < number; j++) {
                if (b[j].random == i) {
                    printf("%s ", b[j].name);
                    printf("(%d) ", b[j].Arr);
                    Data++;
                    if (Data % width == 0) {
                        printf("\n\n");
                    }
                }
            }
        }
    }

    return 0;
}