#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_NAME 20
typedef struct //물건의 구조체 가격 수량, 희귀도
{
    char* name;
    int price;
    int grade;
    int num;
}goods;
int setgoods(goods* d)
{
    d->price = (rand() % 10 + 1) * 1000; // 이 뒤로 수량이나 금액 희귀도를 랜덤으로 배치한다 .
    d->num = rand() % 20 + 1;
    int namelen = rand() % (MAX_NAME - 1) + 1;
    d->name = calloc(namelen, sizeof(char));// 물건의 전체 량에 대한 바이트 맞춘후 0으로 전환하고 대입하기
    int i;
    for (i = 0; i < namelen; i++)
        d->name[i] = 'a' + rand() % 26;
    d->name[i] = '\0';
    if (d->price >= 7000)
        d->grade = 3;
    else if (d->price >= 4000)
        d->grade = 2;
    else
        d->grade = 1;

    // printf("품종: %20s : %d등급  // 가격: %5d원  수량: %2d개 남음 \n",d->name, d->grade, d->price, d->num);

}
int main()
{
    int a, b, c, d, j, l, f, q, p = 0;
    int pri, nim, grad;
    int pric = 0;
    int n = 101; // 쓸 변수들
    char newgood[20]; // 구조체 배열
    goods* good = malloc(sizeof(goods) * (n + 20));
    memset(good, 0, sizeof(goods) * (n + 20));
    for (int i = 0; i < n; i++)
    {
        setgoods(&good[i]);
    }

    while (1) {
        printf("\n--------------상점에 오신 것을 환영합니다-------------- \n\n");
        printf("---무슨 용건으로 오셨나요?---\n");
        printf(" 1. 물건을 사러 왔습니다.\n 2. 물건을 팔기 위해 왔습니다\n 3. 아닙니다.\n 당신:");
        scanf("%d", &a);
        if (a != 1 && a != 2)
        {
            printf("안녕히 가세요"); // 바로 끝
            exit(0);
        }
        if (a == 1) // 물건 살 때
        {
            printf("상점의 현재 메뉴를 보시겠습니까?(yes: 1):"); // 안 보면 그대로 실행 끝 다시 처음으로
            scanf("%d", &b);
            if (b != 1)
                continue;
            else
            {
                while (1) {
                    printf("상점의 목록입니다.\n");
                    /* goods* good = malloc(sizeof(goods)*n);
                     memset(good, 0, sizeof(goods) * n);
                     for(int i=0; i<n; i++)
                     {
                         printf("%4d번째 상품  : ",i+1);
                         setgoods(&good[i]);
                     } */
                    for (int k = 0; k < n; k++)
                    {
                        printf("%3d 번째 상품 :", k + 1);
                        printf("품종: %20s : %d등급  // 가격: %5d원  수량: %2d개 남음 \n", good[k].name, good[k].grade, good[k].price, good[k].num);
                    }
                    printf("\n 원하시는 상품 번호를 고르세요 : ");
                    scanf("%d", &j);
                    printf("%d번째 물건을 몇 개 구입하시겠습니까? (현재 수량: %d) : ", j, good[j - 1].num);
                    scanf("%d", &c);
                    p += c;           // 개수 계산
                    pric += c * (good[j - 1].price); //가격 계산
                    good[j - 1].num -= c;
                    free(good);
                    printf("구매하신 물건 수 : %d개 \n", p);
                    printf("내야 할 금액 : %d원 \n", pric);
                    printf("감사합니다. 계속 이용하시겠습니까? (yes = 1): ");
                    scanf("%d", &d);
                    pric = 0, p = 0;  // 계속 더해지는 것 막기
                    if (d != 1)
                        break;
                    else
                    {
                        continue;

                    }
                }

            }

        }
        if (a == 2) //물건을 팔 때
        {
            printf("상점 목록을 보여 드리겠습니다 \n");
            for (int k = 0; k < n; k++)
            {
                printf("%3d 번째 상품 :", k + 1);
                printf("품종: %20s : %d등급  // 가격: %5d원  수량: %2d개 남음 \n", good[k].name, good[k].grade, good[k].price, good[k].num);
            }
            printf("\n\n\n제가 가지고 온 물건을 팔고 싶습니다.: 1 \n  아닙니다.: 2 \n"); // 똑같은 물건만 팔 수 있다
            scanf("%d", &l);
            if (l == 1)
            {
                printf("\n팔려는 물건의 번호:");
                scanf("%d", &f);
                printf("\n 판매할 수 량:");
                scanf("%d", &q);
                printf("개당 원하시는 금액을 말씀해 주세요 (참고로 우리 상점은 %d 번째 물건을 %d원에 팔고 있습니다.) : ", f, good[f - 1].price);
                // 이 이상의 금액은 받지 않겠다는 의미
                scanf("%d", &pri);
                if (pri <= good[f].price) {

                    good[f - 1].num += q;
                    for (int k = 0; k < n; k++)
                    {
                        printf("%3d 번째 상품 :", k + 1);
                        printf("품종: %20s : %d등급  // 가격: %5d원  수량: %2d개 남음 \n", good[k].name, good[k].grade, good[k].price, good[k].num);
                    } printf("\n\n바뀐 상품 목록입니다");
                    printf("\n판매 완료되었습니다. 바뀌어진 상품 목록을 보여 드렸습니다.\n");
                    printf("\n 받으실 금액: %d원", pri * q);
                    printf("\n감사합니다.");
                    free(good);
                }
                else
                    printf("원하시는 값을 드리기엔 양이 너무 큽니다 죄송합니다.\n"); // 이익이 없기에 거절
                continue; //다시 처음부터
            }


        }








    }
}

