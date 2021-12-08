#include <stdio.h>
#include <math.h>
#define MAX_NAME_LEN    20
#define MAX_ACC_LEN 10
struct _BankAcc {                      //고객 정보 담을 구조체
    char name[MAX_NAME_LEN];          //고객 이름
    char account[MAX_ACC_LEN];        //고객 통장번호 
    int balance;                      //고객 저금액
    float total;                        //고객 저금액 + 이자
};
typedef struct _BankAcc BankAcc;
BankAcc baccs[3];                     //각 고객에 대한 정보 묶을 배열   

void input_accs();                    //고객 정보 입력
void run();                           //선택한 1,2,3,4에 따른 결과
float interest(BankAcc* d1);            //이자 계산 함수
int year = 0;               //저금한 날짜로부터 몇 년이 지났는지 묻기

int main()
{
    input_accs();
    run();
    return 0;
}
void input_accs() //고객 정보 입력
{
    int i = 0;
    for (i = 0; i < 3; i++) //고객 3명에 대한 정보 입력
    {
        printf("사용자%d의 이름:", i + 1);
        scanf("%s", baccs[i].name, MAX_NAME_LEN);
        printf("사용자%d의 계좌:", i + 1);
        scanf("%s", baccs[i].account, MAX_ACC_LEN);
        printf("사용자%d의 저금액:", i + 1);
        scanf("%d", &baccs[i].balance);
    }
}

int select_menu();        //1,2,3 중 선택
void show_balance();      //고객 정보 선택
void save();              //저축 금액 설정
void draw();              //인출 금액 설정
void run()                //선택한 1,2,3,4에 따른 결과
{
    int key;          //선택한 1,2,3,4를 저장할 변수설정
    while (1)
    {
        key = select_menu();
        if (key == 4)
            break;
        switch (key) {
        case 1: show_balance(); break;
        case 2: save(); break;
        case 3: draw(); break;
        default:
            printf("잘못된 숫자를 입력하였습니다.\n");
            break;
        }
    }
}
int select_menu()          //1,2,3,4 중 선택
{
    int key = 0;
    printf("메뉴를 선택하세요. <잔액조회(1), 저축(2), 인출(3), 종료(4)>:");
    scanf("%d", &key);
    return key;
}
void show_balance()     //금액 보여주기
{
    printf("몇 년이 지났나요?");    //이자 쌓이도록 년도 묻기
    scanf("%d", &year);
    int num = 0;
    printf("사용자 번호를 선택하세요.(1~3):");
    scanf("%d", &num);
    if ((num < 1) || (num > 3))
    {
        printf("잘못 선택하였습니다.\n");
        return;
    }
    printf("%s님의 계좌번호: %s입니다.\n", baccs[num - 1].name, baccs[num - 1].account);
    printf("%s님의 저금액:%d 입니다.\n", baccs[num - 1].name, baccs[num - 1].balance);
    interest(&baccs[num - 1]);
    printf("%s님의 총금액:%f 입니다.\n", baccs[num - 1].name, baccs[num - 1].total);
}
void save() //저축금액 설정
{
    int num = 0;
    int value = 0;
    printf("사용자 번호를 선택하세요.(1~3):");
    scanf("%d", &num);
    if ((num < 1) || (num > 3))
    {
        printf("잘못 선택하였습니다.\n");
        return;
    }
    printf("%s님의 저축 금액 입력:", baccs[num - 1].name);
    scanf("%d", &value);
    baccs[num - 1].balance += value;
}
void draw()         //인출금액 설정
{
    int num = 0;
    int value = 0;         //출력할 금액
    printf("사용자 번호를 선택하세요.(1~3):");
    scanf("%d", &num);
    interest(&baccs[num - 1]);
    if ((num < 1) || (num > 3))
    {
        printf("잘못 선택하였습니다.\n");
        return;
    }
    printf("%s님의 인출 금액 입력:", baccs[num - 1].name);
    scanf("%d", &value);

    if (value > baccs[num - 1].total)
    {
        printf("잔액이 부족합니다.\n");
    }
    else
    {
        baccs[num - 1].balance -= value;
    }
    printf("%s님의 잔액:%d 입니다.\n", baccs[num - 1].name, baccs[num - 1].balance);
}

float interest(BankAcc* d1) //이자 계산 함수
{
    d1->total = pow(1.01, year) * (d1->balance);
    return  (d1->total);
}