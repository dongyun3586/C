#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

int checkEqualStr(char* s1, char* s2)//산 수용액과 염기 수용액을 구분하기 위한 문자열 검사 함수
{
    while (*s1 != '\0' || *s2 != '\0') {
        if (*s1 == *s2) {
            s1++;
            s2++;
        }
        else {
            return -1;
        }
    }
    return 0;
}

int main() {
    int selec;
SEL:
    printf("모드를 고르시오 1 : 부피 구하기 2 : 적정하기 3 : 종료하기\n");
    scanf("%d", &selec);//모드를 선택하기 위한 변수
    if (selec == 1) {
        char Acid[5][10] = { "HCl","CH3COOH","H3PO4","H2SO4","H2CO3" };//사용 가능한 산 수용액 5가지
        char Base[5][10] = { "NaOH", "MgOH2", "KOH", "NH3", "CaOH2" };//사용 가능한 염기 수용액 5가지
        char Aqours1[10];
        char Aqours2[10];
        int parameter;//용액 한 분자에서 해리되는 입자 수 결정
        float M1;//적정할 수용액의 농도
        float V1;//적정할 수용액의 부피
        float M2;
        float V2;
        int Base_i[5] = { 1,2,1,1,2 };//염기 수용액에서 해리되는 입자 수
        printf("필요한 용액의 부피를 구하는 모드입니다\n\n");
        printf("적정할 용액의 종류를 입력하시오 :\n");
        scanf("%s", Aqours1);
        printf("사용할 용액의 종류를 입력하시오 :\n");
        scanf("%s", Aqours2);
        printf("적정할 용액의 농도와 부피를 입력하시오 :");
        scanf("%f%f", &M1, &V1);
        printf("사용할 용액의 농도를 입력하시오 :");
        scanf("%f", &M2);
        for (int i = 0; i < 5; i++) {
            if (checkEqualStr(Aqours1, Base[i]) == 0) {//염기 수용액임을 확인
                printf("\n\n용액1은 염기성입니다\n\n");
                parameter = i;
                V2 = Base_i[parameter] * V1 * M1 / M2;//넣어야 하는 용액의 양을 구함
                printf("필요한 부피는 %.1fmL입니다\n", V2);
                goto SEL;//다시 모드를 선택할 수 있도록 goto문을 사용
            }
            else {
                printf("\n\n용액1은 산성입니다\n\n");
                for (int k = 0; k < 5;) {
                    if (checkEqualStr(Aqours2, Base[k]) == 0) {//사용하는 염기 수용액이 어떤 것인지 구함
                        parameter = k;
                        V2 = (V1 * M1) / (Base_i[parameter] * M2);//넣어야 하는 용액의 양
                        printf("필요한 부피는 %.1fmL입니다\n", V2);
                        break;
                    }
                }
                goto SEL;
            }
        }

    }
    else if (selec == 2) {
        printf("직접 적정을 하는 모드입니다\n");
        srand(time(NULL));
        int V1, M1, M2 = 0;
        float V2;
        V1 = rand() % 300 + 1;
        M1 = rand() % 5 + 1;
        printf("적정에 사용할 용액의 종류를 입력하시오 :\n");
        char Acid[5][10] = { "HCl","CH3COOH","H3PO4","H2SO4","H2CO3" };
        char Base[5][10] = { "NaOH", "MgOH2", "KOH", "NH3", "CaOH2" };
        char Aqours1[10];
        char Aqours2[10];
        int parameter;
        M2 = 1;
        int Base_i[5] = { 1,2,1,1,2 };
        scanf("%s", Aqours1);
        for (int i = 0; i < 5; i++) {
            for (int k = 0; k < 5; k++) {
                if (checkEqualStr(Aqours1, Base[k]) == 0) {

                    parameter = k;
                    V2 = (Base_i[parameter] * V1 * M1) / M2;
                    float myV = 0;

                    while (1) {//적정이 끝나면 while 문을 탈출하도록 함
                        printf("넣을 부피를 입력하시오 :\n");
                        float plus;//추가로 넣어주는 용액의 양을 담는 변수
                        scanf("%f", &plus);
                        if (myV + plus < V2) {
                            printf("\n\n아무런 변화가 없습니다. 용액을 추가하세요\n");
                            myV += plus;//지금까지 추가한 용액의 양을 저장
                            continue;
                        }
                        else if (myV + plus == V2) {
                            printf("\n적정을 완료했습니다\n");
                            goto SEL;
                        }
                        else {
                            printf("\n당량점을 지났습니다.\n");
                            printf("당량점은 %fmL였습니다\n", V2);
                            goto SEL;
                        }
                    }
                }
                else {

                    V2 = (V1 * M1) / M2;
                    float myV = 0;

                    while (1) {
                        printf("넣을 부피를 입력하시오 :\n");
                        float plus;
                        scanf("%f", &plus);
                        if (myV + plus < V2) {
                            printf("\n\n아무런 변화가 없습니다. 용액을 추가하세요\n");
                            myV += plus;
                            continue;
                        }
                        else if (myV + plus == V2) {
                            printf("\n적정을 완료했습니다\n");
                            goto SEL;
                        }
                        else {
                            printf("\n당량점을 지났습니다.\n");
                            printf("당량점은 %fmL였습니다\n", V2);
                            goto SEL;
                        }
                    }
                }
            }
        }
    }
    else { printf("종료되었습니다\n"); return 0; }
}