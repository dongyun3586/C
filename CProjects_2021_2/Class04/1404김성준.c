#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>



typedef struct dal {
    int speed;
    int space[60];
}dal;

void help();
void game(int* cash);
void g(dal a, dal b, dal c);
void printcardresult(int a);
int cardresult(int a, int b);
void sutgame(int* cash);

void printstring(dal a, dal b, dal c) {
    printf("������ 1: ");
    for (int i = 0; i < 60; i++) {
        if (a.space[i] == 0) {
            printf(" ");
        }
        else {
            printf("0");
        }
    }
    printf("\n");
    printf("������ 2: ");
    for (int i = 0; i < 60; i++) {
        if (b.space[i] == 0) {
            printf(" ");
        }
        else {
            printf("0");
        }
    }
    printf("\n");
    printf("������ 3: ");
    for (int i = 0; i < 60; i++) {
        if (c.space[i] == 0) {
            printf(" ");
        }
        else {
            printf("0");
        }
    }
    printf("\n");
}



int main() {
    int a;//�޴� ����
    int cash = 0;
    cash += 1000000;
    while (1) {
        system("cls");
        printf("������\n\n");
        printf("���� ���� �ݾ� : %d\n\n", cash);
        printf("1.������\n2.����\n3.����\n4.��������\n\n");
        printf("�޴� ����: ");
        scanf("%d", &a);
        switch (a) {
        case 1:
            system("cls");
            if (cash == 0) {
                printf("���� ������ ������ �����Ͻ� �� �����ϴ�.");
                Sleep(2000);
                break;
            }
            game(&cash);
            break;
        case 2:
            system("cls");
            sutgame(&cash);
            break;
        case 3:
            system("cls");
            help();
            break;
        case 4:
            system("cls");
            printf("���� ����");
            return 0;
            break;
        }
    }
}


void game(int* cash) {
    system("cls");
    printf("������ ���ӿ� ���� ���� ȯ���մϴ� ������� 100000���Դϴ� �����̵��� ������ �����ּ���!");
    printf("\n������ 1, ������ 2, ������ 3");
    printf("\n����� ������? : ");
    int x;
    scanf("%d", &x);
    printf("\n2�� �� �����մϴ�");
    Sleep(2000);
    system("cls");
    dal a;
    dal b;
    dal c;
    srand(time(NULL));
    int peed[3] = { 0,0,0 };
    for (int i = 0; i < 3; i++) {
        peed[i] = rand() % 5 + 1;
        for (int j = 0; j < i; j++) {
            if (peed[i] == peed[j]) {
                i--;
            }
        }
    }
    for (int i = 0; i < 60; i++) {
        a.space[i] = 0;
    }
    for (int i = 0; i < 60; i++) {
        b.space[i] = 0;
    }
    for (int i = 0; i < 60; i++) {
        c.space[i] = 0;
    }

    a.speed = peed[0];
    b.speed = peed[1];
    c.speed = peed[2];

    g(a, b, c);

    if (a.speed > b.speed && a.speed > c.speed) {
        printf("1�� �����̰� �̱�");
        if (x == 1) {
            printf("\n�̰���ϴ�.\n100000�� ������ϴ�.");
            (*cash) += 100000;
        }
        else {
            printf("\n����� 100000�� �Ҿ����ϴ�.");
            (*cash) -= 100000;
        }
    }
    else if (b.speed > a.speed && b.speed > c.speed) {
        printf("2�� �����̰� �̱�");
        if (x == 2) {
            printf("\n�̰���ϴ�.\n100000�� ������ϴ�.");
            (*cash) += 100000;
        }
        else {
            printf("\n����� 100000�� �Ҿ����ϴ�.");
            (*cash) -= 100000;
        }
    }
    else {
        printf("3�� �����̰� �̱�");
        if (x == 2) {
            printf("\n�̰���ϴ�.\n100000�� ������ϴ�.");
            (*cash) += 100000;
        }
        else {
            printf("\n����� 100000�� �Ҿ����ϴ�.");
            (*cash) -= 100000;
        }
    }
    Sleep(2000);
    return;

}

void g(dal a, dal b, dal c) {
    system("cls");
    int x = 0, y = 0, z = 0;
    printstring(a, b, c);
    while (1) {

        a.space[x] = 0;
        a.space[x + a.speed] = 1;
        x += a.speed;

        b.space[y] = 0;
        b.space[y + b.speed] = 1;
        y += b.speed;

        c.space[z] = 0;
        c.space[z + c.speed] = 1;
        z += c.speed;

        Sleep(400);
        system("cls");
        printstring(a, b, c);
        if (x > 25 || y > 25 || z > 25) {
            break;
        }
    }

}


void help() {
    printf("������ �����ϰ� �� ����ŭ �� �� �ֽ��ϴ�.");
    Sleep(2000);
    return;
}

void sutgame(int* cash) {
    //int usercard[2] = { 0,0 }; //ī������
    //int com1card[2] = { 0,0 };
    //int com2card[2] = { 0,0 };
    int card[6] = { 0,0,0,0,0,0 };//īƮ����
    int usercardresult; //ī������ 2���� ���ؼ� �� ���
    int com1cardresult;
    int com2cardresult;
    srand(time(NULL));
    for (int i = 0; i < 6; i++) {
        card[i] = rand() % 20 + 1;
        for (int j = 0; j < i; j++) {
            if (card[i] == card[j]) {
                i--;
            }
        }
    }//n�� : (n,10+n) 3�� �ﱤ 1�� �ϱ� 8�� �ȱ���
    usercardresult = cardresult(card[0], card[1]);
    com1cardresult = cardresult(card[2], card[3]);
    com2cardresult = cardresult(card[4], card[5]);
    printf("����� �д� ");
    printcardresult(usercardresult);
    printf("�����Ͻðڽ��ϱ�?\n1. ���� 2. ����\n");
    printf("���� : \n");
    int t;//������ ����
    int r;//�󸶳� �������� ����
    scanf("%d", &t);
    if (t == 1) {
        printf("�󸶳� �Žðڽ��ϱ�  :");
        scanf("%d", &r);
        if (usercardresult < com1cardresult && usercardresult < com2cardresult) {
            printf("\ncom1�� �д� ");
            printcardresult(com1cardresult);
            printf("\ncom2�� �д� ");
            printcardresult(com2cardresult);
            printf(" �Դϴ�.");
            printf("\n �̱�̽��ϴ�.!");
            printf("%d���� �����̽��ϴ�.", r);
            (*cash) += r;
            Sleep(6000);
            return;
        }
        else {
            printf("\ncom1�� �д�");
            printcardresult(com1cardresult);
            printf("\ncom2�� �д�");
            printcardresult(com2cardresult);
            if (com1cardresult < com2cardresult) {
                printf("\ncom1�� �̰���ϴ�.\n");
            }
            else {
                printf("\ncom2�� �̰���ϴ�.\n");
            }
            printf("\n���̽��ϴ�.!");
            printf("\n%d���� �����̽��ϴ�.", r);
            (*cash) -= r;
            Sleep(6000);
            return;
        }
    }
    else {
        printf("\n���̸� �����Կ� ���� 50000���� �����˴ϴ�.");
        (*cash) -= 50000;
        Sleep(3000);
        return;
    }
}

int cardresult(int a, int b) {
    if ((a == 3 && b == 8) || (a == 8 && b == 3))//38����
        return 1;
    else if ((a == 1 && b == 8) || (a == 8 && b == 1))//18����
        return 2;
    else if ((a == 1 && b == 3) || (a == 3 && b == 1))//13����
        return 3;
    else if ((a == 10 && b == 20) || (a == 20 && b == 10))//�嶯
        return 4;
    else if ((a == 9 && b == 19) || (a == 19 && b == 9))//����
        return 5;
    else if ((a == 8 && b == 18) || (a == 18 && b == 8))//�ȶ�
        return 6;
    else if ((a == 7 && b == 17) || (a == 17 && b == 7))//ĥ��
        return 7;
    else if ((a == 6 && b == 16) || (a == 16 && b == 6))//����
        return 8;
    else if ((a == 5 && b == 15) || (a == 15 && b == 5))//����
        return 9;
    else if ((a == 4 && b == 14) || (a == 14 && b == 4))//�綯
        return 10;
    else if ((a == 3 && b == 13) || (a == 13 && b == 3))//�ﶯ
        return 11;
    else if ((a == 2 && b == 12) || (a == 12 && b == 2))//�̶�
        return 12;
    else if ((a == 1 && b == 11) || (a == 11 && b == 1))//�϶�
        return 13;
    else if ((a % 10 == 1 && b % 10 == 2) || (a % 10 == 2 && b % 10 == 1))//�˸�
        return 14;
    else if ((a % 10 == 4 && b % 10 == 1) || (a % 10 == 1 && b % 10 == 4))//����
        return 15;
    else if ((a % 10 == 1 && b % 10 == 9) || (a % 10 == 9 && b % 10 == 1))//����
        return 16;
    else if ((a % 10 == 1 && b % 10 == 0) || (a % 10 == 0 && b % 10 == 1))//���
        return 17;
    else if ((a % 10 == 0 && b % 10 == 4) || (a % 10 == 4 && b % 10 == 0))//���
        return 18;
    else if ((a % 10 == 0 && b % 10 == 4) || (a % 10 == 4 && b % 10 == 0))//����
        return 19;
    else if ((a + b) % 10 == 9)//����
        return 20;
    else if ((a + b) % 10 == 8)//�Ȳ�
        return 21;
    else if ((a + b) % 10 == 7)//ĥ��
        return 22;
    else if ((a + b) % 10 == 6)//����
        return 23;
    else if ((a + b) % 10 == 5)//����
        return 24;
    else if ((a + b) % 10 == 4)//���
        return 25;
    else if ((a + b) % 10 == 3)//���
        return 26;
    else if ((a + b) % 10 == 2)//�̲�
        return 27;
    else if ((a + b) % 10 == 1)//�ϲ�
        return 28;
    else if ((a + b) % 10 == 0)//����
        return 29;
}


void printcardresult(int a) {
    switch (a) {
    case 1:
        printf("38�����Դϴ�.");
        break;
    case 2:
        printf("18�����Դϴ�.");
        break;
    case 3:
        printf("13�����Դϴ�.");
        break;
    case 4:
        printf("�嶯�Դϴ�.");
        break;
    case 5:
        printf("9���Դϴ�.");
        break;
    case 6:
        printf("8���Դϴ�.");
        break;
    case 7:
        printf("7���Դϴ�.");
        break;
    case 8:
        printf("6���Դϴ�.");
        break;
    case 9:
        printf("5���Դϴ�.");
        break;
    case 10:
        printf("4���Դϴ�.");
        break;
    case 11:
        printf("3���Դϴ�.");
        break;
    case 12:
        printf("2���Դϴ�.");
        break;
    case 13:
        printf("1���Դϴ�.");
        break;
    case 14:
        printf("�����Դϴ�.");
        break;
    case 15:
        printf("�����Դϴ�.");
        break;
    case 16:
        printf("����Դϴ�.");
        break;
    case 17:
        printf("����Դϴ�.");
        break;
    case 18:
        printf("�����Դϴ�.");
        break;
    case 19:
        printf("�����Դϴ�.");
        break;
    case 20:
        printf("9���Դϴ�.");
        break;
    case 21:
        printf("8���Դϴ�.");
        break;
    case 22:
        printf("7���Դϴ�.");
        break;
    case 23:
        printf("6���Դϴ�.");
        break;
    case 24:
        printf("5���Դϴ�.");
        break;
    case 25:
        printf("4���Դϴ�.");
        break;
    case 26:
        printf("3���Դϴ�.");
        break;
    case 27:
        printf("2���Դϴ�.");
        break;
    case 28:
        printf("1���Դϴ�.");
        break;
    case 29:
        printf("�����Դϴ�.");
        break;
    }

}