#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>

int main()
{

    char q[20][100] = { "밥그릇에 발을 올린다. ","물그릇을 빤히 쳐다본다.","심심해한다.","손톱이 가려운지 자꾸 꾹꾹이를 해댄다.","빈 화장실 안에 앉아 나를 쳐다본다.","추워한다.","애교를 부리며 예쁜 짓을 한다.","다리에 몸을 비벼댄다.","사냥 준비자세를 취한다. ","택배박스 옆에서 얼쩡거린다." };
    char a[20][100] = { "사료","물","오뎅꼬치","스크래쳐","모래","햇빛","츄르","엉덩이","생쥐","박스" }; // 질문과 답변
    char name[10];
    char ans[10];
    char answer[10];
    char c[20][100] = { "YES", "NO" };
    char Start;
    int i, n, sum = 0;
    int nTmp = 10;
    int index[20] = { 0,1,2,3,4,5,6,7,8,9 }; //랜덤으로 질문을 뽑아내기 위한 배열.
    srand(time(NULL));

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);        //글자 색을 바꾸는 함수
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n                                                    슬기로운 집사생활!\n\n\n");
    printf("                                           ▶게임을 시작하려면 s를 누르시오.");
    scanf("%c", &Start);
    if (Start == 115) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);         //글자 색을 바꾸는 함수
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\\    /\\\n");
        printf(" )  ( ')\n");
        printf("(  /  )\n");
        printf(" \\(__)|");
        printf("\n\n\n한가로운 어느 날, 길을 걷고있던 당신의 품으로 고양이 한 마리가 달려들었다.");
        _sleep(3000);
        printf(" \n\n깜짝 놀란 당신이 뒷걸음질을 쳐봤지만, 품에 안긴 고양이는 내려갈 생각이 없어보였다.\n\n");
        _sleep(3000);
        printf("Q. 품에 갑자기 달려든 한 고양이. 데려갈 것인가?   YES  /  NO    ");
        scanf("%s", answer);
        if (strcmp(answer, c[0]) == 0) { // 답변이 YES 일 때
            printf("\n고양이가 당신을 향해 애교를 부린다! 우선 고양이의 이름을 짓도록 하자.\n\n");
            _sleep(3000);
        }
        else {// 답변이 YES 가 아닐 때
            printf("\n사실 선택권 따위는 없었다. 고양이에게 간택을 당한 이상 데려가야만 한다. \n\n이렇게 된 거 고양이의 이름부터 지어주도록 하자.\n\n");
            _sleep(3000);
        }

        printf("고양이의 이름을 입력하시오.");
        scanf("%s", name);
        printf("\n\n\n\n\n\n\n당신의 고양이 이름: %s", name);
        printf("\n\n게임 룰:\n\n%s(이)가 원하는 것이 무작위적으로 나온다.", name);
        _sleep(3000);
        printf(" \n\n만약 %s(이)가 원하는 것을 주지 못할 시 점수가 깎이고, 5초 내에 원하는 것을 입력하지 않을 시 점수가 깎인다.", name);
        _sleep(3000);
        printf(" \n\n마지막까지 열심히 키운다면 %s(이)가 어떤 포상을 줄 지 모르니 멋진 집사가 되어보자! \n\n", name);
        _sleep(3000);
        printf("주변에서 이용할 수 있는 것들: ");
        for (i = 0; i < 10; i++) { // 답변의 종류 출력하기
            printf("%s   ", a[i]);
        }
        _sleep(3000);
        printf("\n\n\n슬기로운 집사생활 START!\n\n");

        for (i = 9; i >= 0; i--) {
            n = rand() % 10;
            nTmp = index[i];
            index[i] = index[n];
            index[n] = nTmp; // 질문의 종류를 섞어서 무작위로 질문이 나오게 만들기
        }

        for (int j = 0; j < 10; j++) {
            _sleep(1000);//다음 질문까지 카운트다운
            printf("3\n");
            _sleep(1000);
            printf("2\n");
            _sleep(1000);
            printf("1\n");
            _sleep(1000);
            printf("\nQ.%s(이)가 %s \n무엇을 해줄까?:", name, q[index[j]]); //%s로 문자열을 불러 index[i]로 섞은 숫자를 질문의 이차원 배열 안에 넣어 질문 꺼내기 
            clock_t start = clock();//지금 시간을 시작 시간으로 설정
            scanf("%s", ans);


            if (strcmp(ans, a[index[j]]) == 0) {//답이 맞았을 때
                if ((clock() - start) / CLOCKS_PER_SEC > 5.0) { //답은 맞았지만 시간이 5초를 넘겼을 때
                    printf("겨우 바친 서비스가 너무 늦었나보다. %s(이)가 집사를 쳐다보지도 않는다. \n\n", name);
                    sum -= 10;


                }
                else {//답도 맞았고 시간도 5초를 넘기지 않았을 때
                    printf("빙고! %s(이)가 골골송을 부른다. 만족스럽나보다. \n\n", name);
                    sum += 10;
                }
            }
            else {//답이 틀렸을 때
                printf("%s(이)가 당신의 손을 때린다. 마음에 들지 않나보다. \n\n", name);
                sum -= 10;

            }

        }

        _sleep(1000);
        if (sum == 0) { printf("\n%s(이)가 당신을 밟고 지나간다! 아무리 봐도 제대로 된 집사가 되기 위해서는 더 노력해야겠다. \n\n", name); }

        else if (sum >= 10 && sum <= 30) { printf("\n%s(이)가 죽은 생쥐를 물고왔다. 그래도 집사라고 고마운 마음이 조금은 있나보다.\n\n", name); }

        else if (sum >= 40 && sum < 70) { printf("\n%s(이)가 잃어버렸던 머리끈을 물어다줬다! 꽤 아끼던 머리끈을 찾았다.\n\n", name); }

        else if (sum >= 70 && sum <= 90) { printf("\n%s(이)가 틈새로 들어간 휴대폰을 물어다줬다! 손이 닿지 않아 포기하려던 찰나였다.\n\n", name); }

        else if (sum == 100) { printf("\n%s(이)가 오만원을 물어다줬다! 집사가 돈이 궁한 건 어떻게 알았는지, 기특한 고양이다. \n\n", name); }

        _sleep(1000);

        printf("\n완벽한 집사가 되기까지: %d % 완료!\n\n\n\n", sum);
    }
}