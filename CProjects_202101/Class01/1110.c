#include <stdio.h>
#include<windows.h>//    -> system("cls");
char name[100] = { 0, };
int age, year, month, day;

int checking(int a) {
    if (a == 1) {
        for (int i = 0; i <= 3; i++) {
            printf(".");
            Sleep(1000);
        }

        printf("�� ��������� ���ְ��а���б� 1�г� 1�� ���� �������� ���� �������� �Դϴ�.");
        Sleep(4000);
        system("cls");

        printf("�����ϰ� ���Ͻø� �ڽ��� ������ �Ϻ��ϰ� �� �� ������ �̴ϴ�!");
        Sleep(4000);
        system("cls");

        //�̸��� �Է¹ް� ����ϱ�
        printf("���� �̸��� �Է����ּ���\n");
        scanf("%s", &name);
        printf("%s", name);

        for (int i = 0; i < 3; i++) {
            printf(".");
            Sleep(1000);
        }

        printf("���� �̸��̳׿�!\n");
        Sleep(2000);// 1000=1��
        system("cls");

        //���� �Է¹ޱ�
        printf("���̴� ��� �ǽó���?\n");
        scanf("%d", &age);
        year = 2022 - age;
        if (year == 2005) {
            printf("��! % d����", age);
            for (int i = 0; i < 3; i++) {
                printf(".");
                Sleep(1000);
            }
            printf("���� �����̽ó׿�!�ű��ϳ׿�!\n");
        }

        else {
            printf("��! %d ����", age);
            for (int i = 0; i < 3; i++) {
                printf(".");
                Sleep(1000);
            }
            printf("%d ����̽ñ���!\n", year);
        }
        Sleep(2000);
        system("cls");

        //������� ����� ���� �����ֱ�
        printf("��� �� �¾�̳���?\n");
        scanf("%d", &month);

        switch (month) {
        case 12:
        case 1:
        case 2:
            for (int i = 0; i < 3; i++) {
                Sleep(1000);
                printf(".");
            }
            printf("�ܿ￡ �¾�̱���!");
            break;

        case 3:
        case 4:
        case 5:
            for (int i = 0; i < 3; i++) {
                printf(".");
                Sleep(1000);
            }
            printf("���� �¾�̱���!");
            break;

        case 6:
        case 7:
        case 8:
            for (int i = 0; i < 3; i++) {
                printf(".");
                Sleep(1000);
            }
            printf("������ �¾�̱���!");
            break;

        case 9:
        case 10:
        case 11:
            for (int i = 0; i < 3; i++) {
                printf(".");
                Sleep(1000);
            }
            printf("������ �¾�̱���!");
            break;
        }
        Sleep(2000);
        system("cls");

        //���Ͽ� �¾���� ����� ����ϱ�
        printf("���Ͽ� �¾�̳���?\n");
        scanf("%d", &day);
        if (day == 13) {
            printf("������ ���� �ݿ��Ͽ� �¾ ���� �ƴϽ���? ��������!\n");
        }
        else {
            printf("�׷�����!\n");
        }
        Sleep(2000);
        system("cls");
        //�¾�� ����� ���� �����ϱ�
        printf("�׷�");
        for (int i = 0; i < 3; i++) {
            printf(".");
            Sleep(1000);
        }
        printf("%s ���� %d�� %d�� %d�� �� �����Ű���?", name, year, month, day);
        Sleep(2000);
        system("cls");

        printf("���� �ٷ� �������� �����Ҳ���!!!");
        Sleep(2000);
        system("cls");
        printf("��������� �� 4���� ������ �����Ǿ� �ֽ��ϴ�.");
        for (int i = 0; i < 3; i++) {
            printf(".");
            Sleep(1000);
        }
        printf("������ õõ�� �о�ð� ���� 1�� ����2 �� �ڽŰ� �� �´� ���ڸ� �Է����ֽñ� �ٶ��ϴ�.");
        Sleep(5000);
        system("cls");
        return 0;
    }
    if (a == 2) {
        return 1;
    }
}
int main()
{   //��������
    system("color F0"); //ȭ�� ���� �ٲ���
    int ans;
    printf("�������翡 ���Ͻðڽ��ϱ�?? \n 1. ��. 2. �ƴϿ�");
    scanf("%d", &ans);
    if (checking(ans) == 1) {
        return 0;
    }
    //���⼭ ���� �����ؾ���. 1�̶��ϸ� I�� �����ϰ� �ݴ�� E�� ������
    int Q1_1 = 0, Q1_2 = 0, Q1_3 = 0;
    printf("1_1�� \n �����\n1.ģ����� ���� ��°��� ����.\n2.���� ȥ�� �ִ� ���� ����.\n");
    scanf("%d", &Q1_1);
    Sleep(500);

    printf("1_2�� \n ����� �ٸ� ����鿡�� �ڽ��� �Ұ��ϴ� ���� ����� �մϴ�.\n1.�ƴϿ�\n2.��\n");
    scanf("%d", &Q1_2);
    Sleep(500);

    printf("1_3�� \n ���� ��ȭ�� ���� �������� �ʽ��ϴ�.\n1.�ƴϿ�\n2.��\n");
    scanf("%d", &Q1_3);
    Sleep(500);

    if ((Q1_1 + Q1_2 + Q1_3) <= 4) {
        name[1] = 'I';
        name[2] = '0'; //������ �� �����ֱ� ����
    }
    else {
        name[2] = 'E';
        name[1] = '0';
    }
    Sleep(2000);
    system("cls");

    // �Ʒ��� ���� ���� ������� �����Ѵ�.
    int Q2_1 = 0, Q2_2 = 0, Q2_3 = 0;
    printf("2_1�� \n �����\n1.�������� ����̴�.\n2.�������� ����̴�.\n");
    scanf("%d", &Q2_1);
    Sleep(500);

    printf("2_2�� \n�ڽ��� �ൿ�� �ٸ� ����鿡�� ��� ������ �ִ� ���� ���� ���� �������� �ʽ��ϴ�.\n1.�ƴϿ�\n2.��\n");
    scanf("%d", &Q2_2);
    Sleep(500);

    printf("2_3�� \n������ â�����̱⺸�� �������� ����̶�� �����մϴ�.\n1.�ƴϿ�\n2.��\n");
    scanf("%d", &Q2_3);
    Sleep(500);

    if ((Q2_1 + Q2_2 + Q2_3) <= 4) {
        name[3] = 'S';
        name[4] = '0';
    }
    else {
        name[4] = 'N';
        name[3] = '0';
    }
    Sleep(2000);
    system("cls");

    int Q3_1 = 0, Q3_2 = 0, Q3_3 = 0;
    printf("3_1�� \n �����\n1.���ǰ� ����� �� �߿��ϴ�.\n2.���� ģ�� ���谡 �� �߿��ϴ�.\n");
    scanf("%d", &Q3_1);
    Sleep(500);

    printf("3_2�� \n���￡�� �̱�� ���� ������ �������� �ʵ��� �ϴ� �ͺ��� �� �߿��մϴ�.\n1.��\n2.�ƴϿ�\n");
    scanf("%d", &Q3_2);
    Sleep(500);

    printf("3_3�� \n��� �� ������� �ΰ��� �������� ���� ������ �� �߿���ؾ� �մϴ�.\n1.��\n2.�ƴϿ�\n");
    scanf("%d", &Q3_3);
    Sleep(500);

    if ((Q3_1 + Q3_2 + Q3_3) <= 4) {
        name[5] = 'T';
        name[6] = '0';
    }
    else {
        name[6] = 'F';
        name[5] = '0';
    }
    Sleep(2000);
    system("cls");

    int Q4_1 = 0, Q4_2 = 0, Q4_3 = 0;
    printf("4�� \n ����� ��ȹ�� ���ﶧ\n1.ö���ϰ� �̸� ��ȹ�� �����\n2.��Ȳ�� ���� ��ȹ�� �����ϰ� �����ذ���.");
    scanf("%d", &Q4_1);
    Sleep(500);

    printf("4_2�� \n���� ��Ÿ���� ü�����̰� �������̶�� ���ٴ� �׶� �׶� ���Ƽ� ó���ϴ� ���Դϴ�.\n1.�ƴϿ�\n2.��\n");
    scanf("%d", &Q4_2);
    Sleep(500);

    printf("4_3�� \n���� ���� ��ȹ�� ö���ϰ� ����� ���Դϴ�.\n1.��\n2.�ƴϿ�\n");
    scanf("%d", &Q4_3);
    Sleep(500);

    if ((Q4_1 + Q4_2 + Q4_3) <= 4) {
        name[7] = 'P';
        name[8] = '0';
    }
    else {
        name[8] = 'J';
        name[7] = '0';
    }
    Sleep(2000);
    system("cls");

    //������ ����Ҷ� ���� 4���� ������ ��� ��Ƽ� �ѹ��� ����ؾ��� ��) ENTP�� ���� ���
    //2^4���� ����� �� ����ؼ� ���� ���� �߰��ؼ� ����

    for (int i = 1; i <= 8; i++) {
        if (name[i] != '0') {
            printf("����� MBTI �� %c �Դϴ�", name[i]);
        }
    }
}