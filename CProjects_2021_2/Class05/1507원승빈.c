#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

#define e 2.71828 //자연상수 정의

int main()
{
    char choice[5];//회로 선택을 할 문자열 입력
    float volt = 0;
    float res = 0;
    float induct = 0;
    float cap = 0;
    float i = 0;
    float time = 0;
    const char* A = "r"; //비교할 문자열 정의
    const char* B = "rl"; //비교할 문자열 정의
    const char* C = "rc"; //비교할 문자열 정의
    printf("회로 분석");
    Sleep(2000);//2초간 기다림
    system("cls");//출력된 내용 삭제
    printf("무슨 종류의 회로를 분석하실건가요?\n\n");
    Sleep(1000);//1초간 기다림
    while (1)//반복
    {
        printf("r, rl, rc 회로 중 하나를 선택하세요\n");
        scanf("%s", choice);//입력 받기
        for (int i = 0; choice[i] != 0; i++)
            choice[i] = tolower(choice[i]);//대문자인 경우 소문자로 변환
        if (!strcmp(choice, A) || !strcmp(choice, B) || !strcmp(choice, C))//r, rl, rc 중에 누르지 않았다면 프로그램이 끝나도록 한다
            break;
    }

    if (strcmp(choice, A) == 0)//r 회로
    {
        printf("\n저항만 존재하는 r 회로의 분석\n\n전지와 저항을 입력해주세요\n");
        printf("전지 (V) : ");//전압값 입력
        scanf("%f", &volt);
        printf("저항 (Ω) : ");//저항값 입력
        scanf("%f", &res);
        i = volt / res;//전류 공식에 대입
        printf("\n이 회로의 전류는 : %.3f A\n", i);//전류값을 소수점 아래 셋째 자리까지 출력
    }
    else if (strcmp(choice, B) == 0)//rl회로
    {
        printf("\n저항과 유도기가 존재하는 rl 회로의 분석\n\n전지와 저항과 인덕턴스를 입력해주세요\n");
        printf("전지 (V) : ");//전류값 입력
        scanf("%f", &volt);
        printf("저항 (Ω) : ");//저항값 입력
        scanf("%f", &res);
        printf("인덕턴스 (H) : ");//인덕턴스값 입력
        scanf("%f", &induct);
        float taw = -1 * res / induct;//시정수 공식에 대입
        float co = volt / res;//초기 전류값 구해주기
        printf("\n이 rl회로의 전류의 시간에 대한 식은 : %.3f*(1-exp(%.3f*t))\n\n\n", co, taw);//rl회로의 시간에 대한 전류값 나타내주기
        printf("     전류\n");
        printf("      △\n");
        printf("      │\n");
        printf("      │\n");
        printf("%.3f │                                                                                 ●\n", co);
        printf("      │                                                          ●\n");
        printf("      │                                         ●\n");
        printf("      │                              ●\n");
        printf("      │                      ●\n");
        printf("      │                 ●\n");
        printf("      │             ●\n");
        printf("      │         ●\n");
        printf("      │      ●\n");
        printf("      │    ●\n");
        printf("      │  ●\n");
        printf("      │ ● \n");
        printf("      │●\n");
        printf("      └─────────────────────────────────────────────────────────────────────────────────────────▷ 시간\n");//그래프 그리기
        while (1)//시간을 넣어주었을 때의 전류값 구해주기
        {
            printf("시간을 입력하세요 (종료 : -1)\n");
            rewind(stdin);//입력버퍼 비우기
            scanf("%f", &time);
            if (time < 0)
                break;
            float taw_t = taw * time;
            float time_i = co * (1 - pow(e, taw_t));//시간에 따른 전류값 출력
            printf("시간 %.3f일 때 전류 : %.3f A\n", time, time_i);
        }
    }
    else if (strcmp(choice, C) == 0)//rc회로
    {
        printf("\n저항과 축전기가 존재하는 rc 회로의 분석\n\n전지, 저항, 축전기의 전기용량을 입력해주세요\n");
        printf("전지 (V) : ");//전압값 입력
        scanf("%f", &volt);
        printf("저항 (Ω) : ");//저항값 입력
        scanf("%f", &res);
        printf("축전기의 전기 용량 (F) : ");//전기용량 값 입력
        scanf("%f", &cap);
        float taw = -1 / (res * cap);//rc회로 시정수 공식에 대입
        float co = volt / res;//초기전류값 공식에 대입
        printf("\n이 rl회로의 전류의 시간에 대한 식은 : %.3f*exp(%.3f*t)\n", co, taw);//시간에 대한 전류값 공식에 대입해서 출력
        printf("     전류\n");
        printf("      △\n");
        printf("      │\n");
        printf("      │\n");
        printf("      │\n");
        printf("%.3f │●\n", co);
        printf("      │ ●\n");
        printf("      │   ●\n");
        printf("      │      ●\n");
        printf("      │          ●\n");
        printf("      │              ●\n");
        printf("      │                   ●\n");
        printf("      │                           ●\n");
        printf("      │                                           ●\n");
        printf("      │                                                                             ●\n");
        printf("      └─────────────────────────────────────────────────────────────────────────────────────────▷ 시간\n");//시간에 대한 전류 그래프
        while (1)
        {
            printf("시간을 입력하세요 (종료 : -1)\n");//시간을 입력해주었을 때의 전류 출력하기
            rewind(stdin);
            scanf("%f", &time);
            if (time < 0)
                break;
            float taw_t = taw * time;
            float time_i = co * pow(e, taw_t);//시간에 따른 전류값 출력
            printf("시간 %.3f일 때 전류 : %.3f A\n", time, time_i);
        }
    }
}
