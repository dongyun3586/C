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
    printf("ȯ�� ���� �ý���\n");
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
        printf("1.���ο� ȯ�� ��� 2.�Կ��� ��Ȳ 3.ȯ�� ���� 4.�ؾ����� 5.ȯ�� ����\n");
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
            printf("�ٽ� �Է����ּ���\n");
            break;
        }
    }
}
void newpatient() {
    if (count == 7) {
        printf("���̻� ���� �ڸ��� �����ϴ�.");
        printf("\n\n");
        int t;
        printf("\n1. ����ȭ������ ���ư���\n");
    back:
        scanf("%d", &t);
        if (t == 1) {
            system("cls");
        }
        else {
            printf("\n����ȭ������ ���ư����� 1�� �����ּ���\n");
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
        printf("������� �ϸ� �ȵ˴ϴ�\n");
        printf("ȯ���̸� : ");
        scanf("%s", mem[a]);
        printf("���� : ");
        scanf("%s", disease[a]);
        printf("�ʿ��� ġ�� : ");
        scanf("%s", medicine[a]);
        printf("�� ȯ���� ȯ�ڹ�ȣ�� %d ���Դϴ�.", a);
        arr[a] = 1;
        count++;
        int t;
        printf("\n\n1.����ȭ������ ���ư���");
    end:
        scanf("%d", &t);
        if (t == 1) {
            system("cls");
            return 0;
        }
        else {
            printf("\n����ȭ������ ���ư����� 1�� �����ּ���");
            goto end;
        }

    }
}
void hospitalroom() {
    printf("�Կ��� ��Ȳ�� ������ �����ϴ�.");
    for (int i = 1; i <= 6; i++) {
        if (arr[i] == 1) {
            printf("\n%d�� ħ�� : %s", i, mem[i]);
        }
        else {
            printf("\n%d�� ħ�� : �������", i);
        }
        printf("\n");
    }
    int t;
    printf("\n\n1. ����ȭ������ ���ư���\n");
back:
    scanf("%d", &t);
    if (t == 1) {
        system("cls");
    }
    else {
        printf("\n����ȭ������ ���ư����� 1�� �����ּ���\n");
        goto back;
    }

}
void patientinformation() {
    int x;
    printf("��� ȯ���� ������ Ȯ���Ͻðڽ��ϱ�?");
    scanf("%d", &x);
    if (arr[x] == 0) {
        printf("\n�ٽ� �Է��� �ּ���");
        printf("\n��� ȯ���� ������ Ȯ���Ͻðڽ��ϱ�?");
        scanf("%d", &x);
    }
    printf("\nȯ�ڹ�ȣ : %d", x);
    printf("\nȯ���̸� : %s", mem[x]);
    printf("\n���� : %s", disease[x]);
    printf("\n�ʿ��� ġ�� : %s", medicine[x]);
    int t;
    printf("\n1. ����ȭ������ ���ư���\n");
back:
    scanf("%d", &t);
    if (t == 1) {
        system("cls");
    }
    else {
        printf("\n����ȭ������ ���ư����� 1�� �����ּ���\n");
        goto back;
    }

}
void whattodo() {
    printf("������ ����\n");
    for (int i = 1; i <= 6; i++) {
        if (arr[i] == 1) {
            printf("%d��ȯ�� %s %s\n", i, mem[i], medicine[i]);
        }

    }
    int t;
    printf("\n1. ����ȭ������ ���ư���\n");
back:
    scanf("%d", &t);
    if (t == 1) {
        system("cls");
    }
    else {
        printf("\n����ȭ������ ���ư����� 1�� �����ּ���\n");
        goto back;
    }

}
void x() {
    int r;
    printf("��� ȯ�ڸ� �����Ͻðڽ��ϱ�?\n");
    scanf("%d", &r);
    arr[r] = 0;
    count--;
    printf("%d�� ȯ�� %s���� �����Ͽ����ϴ�.", r, mem[r]);
    int t;
    printf("\n1. ����ȭ������ ���ư���\n");
back:
    scanf("%d", &t);
    if (t == 1) {
        system("cls");
    }
    else {
        printf("\n����ȭ������ ���ư����� 1�� �����ּ���\n");
        goto back;
    }

}
