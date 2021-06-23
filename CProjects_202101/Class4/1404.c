#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
void mainpage();
void newpatient();
void hospitalroom();
void patientinformation();
void whattodo();
void x();
int main() {
    printf("환자 관리 시스템\n");
    mainpage();
    return 0;
}
char mem[1001][1001];
char disease[1001][1001];
char medicine[1001][1001];
int arr[6];
int count = 1;
void mainpage() {
    while (1) {
        int a;
        printf("1.새로운 환자 기록 2.입원실 현황 3.환자 정보 4.해야할일 5.환자 제거\n");
        scanf("%d", &a);
        switch (a) {
        case 1:
            system("cls");
            newpatient();
            break;
        case 2:
            system("cls");
            hospitalroom();
            break;
        case 3:
            system("cls");
            patientinformation();
            break;
        case 4:
            system("cls");
            whattodo();
            break;

        case 5:
            system("cls");
            x();
            break;
        default:
            printf("다시 입력해주세요\n");
            break;
        }
    }
}
void newpatient() {
    if (count == 7) {
        printf("더이상 남은 자리가 없습니다.");
        printf("\n\n");
        int t;
        printf("\n1. 메인화면으로 돌아가기\n");
    back:
        scanf("%d", &t);
        if (t == 1) {
            system("cls");
        }
        else {
            printf("\n메인화면으로 돌아가려면 1을 눌러주세요\n");
            goto back;
        }

    }

    else {
        int a;
        for (int i = 1; i < 7; i++) {
            if (arr[i] == 0) {
                a = i;
                break;
            }
        }
        printf("띄워쓰기 하면 안됩니다\n");
        printf("환자이름 : ");
        scanf("%s", mem[a]);
        printf("병명 : ");
        scanf("%s", disease[a]);
        printf("필요한 치료 : ");
        scanf("%s", medicine[a]);
        printf("이 환자의 환자번호는 %d 번입니다.", a);
        arr[a] = 1;
        count++;
        int t;
        printf("\n\n1.메인화면으로 돌아가기");
    end:
        scanf("%d", &t);
        if (t == 1) {
            system("cls");
            return 0;
        }
        else {
            printf("\n메인화면으로 돌아갈려면 1을 눌러주세요");
            goto end;
        }

    }
}
void hospitalroom() {
    printf("입원실 현황은 다음과 같습니다.");
    for (int i = 1; i <= 6; i++) {
        if (arr[i] == 1) {
            printf("\n%d번 침대 : %s", i, mem[i]);
        }
        else {
            printf("\n%d번 침대 : 비어있음", i);
        }
        printf("\n");
    }
    int t;
    printf("\n\n1. 메인화면으로 돌아가기\n");
back:
    scanf("%d", &t);
    if (t == 1) {
        system("cls");
    }
    else {
        printf("\n메인화면으로 돌아가려면 1을 눌러주세요\n");
        goto back;
    }

}
void patientinformation() {
    int x;
    printf("몇번 환자의 정보를 확인하시겠습니까?");
    scanf("%d", &x);
    if (arr[x] == 0) {
        printf("\n다시 입력해 주세요");
        printf("\n몇번 환자의 정보를 확인하시겠습니까?");
        scanf("%d", &x);
    }
    printf("\n환자번호 : %d", x);
    printf("\n환자이름 : %s", mem[x]);
    printf("\n병명 : %s", disease[x]);
    printf("\n필요한 치료 : %s", medicine[x]);
    int t;
    printf("\n1. 메인화면으로 돌아가기\n");
back:
    scanf("%d", &t);
    if (t == 1) {
        system("cls");
    }
    else {
        printf("\n메인화면으로 돌아가려면 1을 눌러주세요\n");
        goto back;
    }

}
void whattodo() {
    printf("오늘의 할일\n");
    for (int i = 1; i <= 6; i++) {
        if (arr[i] == 1) {
            printf("%d번환자 %s %s\n", i, mem[i], medicine[i]);
        }

    }
    int t;
    printf("\n1. 메인화면으로 돌아가기\n");
back:
    scanf("%d", &t);
    if (t == 1) {
        system("cls");
    }
    else {
        printf("\n메인화면으로 돌아가려면 1을 눌러주세요\n");
        goto back;
    }

}
void x() {
    int r;
    printf("몇번 환자를 제거하시겠습니까?\n");
    scanf("%d", &r);
    arr[r] = 0;
    count--;
    printf("%d번 환자 %s님을 제거하였습니다.", r, mem[r]);
    int t;
    printf("\n1. 메인화면으로 돌아가기\n");
back:
    scanf("%d", &t);
    if (t == 1) {
        system("cls");
    }
    else {
        printf("\n메인화면으로 돌아가려면 1을 눌러주세요\n");
        goto back;
    }

}
