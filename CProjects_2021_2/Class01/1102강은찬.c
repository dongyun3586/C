#include <stdio.h>
#include <stdlib.h>
#include <windows.h>                //Sleep, system 함수를 사용하기 위해 필요한 헤더파일

char num[10];          //수를 배열로 입력받는다.
int n, R;
char R_number[50] = { 0 };
char* p = R_number;                  //포인터 이용

void explain();
void input();
int change10(char nun[10], int n);                   //10진수로 변환
void changeR(int num, int R, char p[50]);               //입력받은 진수로 변환
void output(int R, char p[50]);

int main()
{
    explain();                                      //프로그램에 대한 설명을 하는 함수를 실행
    input();
    printf("수 : %s\n", num);
    printf("현재 진법 : %d\n", n);
    printf("10진수 : %d\n", change10(num, n));
    changeR(change10(num, n), R, p);
    output(R, p);
    return 0;
}

void explain()
{
    printf("안녕하세요 수를 다른 진법으로 바꿔드립니다!\n");
    Sleep(1000);                                 //1초 기다리기
    printf("수는 8자리, 진법은 16진법까지 가능합니다.\n");
    Sleep(2000);                                                 //2초 기다리기
    system("cls");
}

void input()
{
    printf("수와 현재 진법을 입력하세요\n");
    scanf("%s %d", &num, &n);

    printf("무슨 진법으로 바꿀까요?\n");
    scanf("%d", &R);                                  //R은 바꿀 진법이다.
    system("cls");
}

int change10(char num[10], int n)
{
    int number = 0;
    int i = 1, d = strlen(num) - 1;

    while (d >= 0)
    {
        if (num[d] >= 48 && num[d] <= 57)            //입력이 숫자일때
        {
            number += (num[d] - 48) * i;
        }
        else                                   //입력이 대문자 알파벳 일때
        {
            number += (num[d] - 55) * i;
        }
        i = i * n;
        d--;
    }

    return number;
}

void changeR(int num, int R, char p[50])                      //입력받은 수를 R진법으로 바꿔 주는 함수이다.
{
    int i = 0;

    while (1)
    {
        if (num % R < 10)                 //입력이 숫자일때
        {
            p[i] = 48 + num % R;              //배열로 저장하기 때문에 숫자일 경우 0의 아스키코드인 48을 더해준다.
        }
        else                                 //입력이 대문자 알파벳 일때
        {
            p[i] = 55 + num % R;             //배열로 저장하기 때문에 알파벳일 경우 A의 아스키코드인 65에서 A의 값인 10을 빼준 55를 더해준다.
        }
        i++;
        num = num / R;
        if (num == 0)
        {
            break;
        }
    }
}

void output(int R, char p[50])          //진법을 전환한 수를 출력해주는 함수이다.
{
    printf("%d진수 : ", R);
    int len = strlen(p);
    for (int i = len - 1; i >= 0; i--)
    {
        printf("%c", p[i]);
    }
    printf("\n\n");
}          //총 101줄