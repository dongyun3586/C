#include <stdio.h>
///����Ʈ�� ����
///made by ����

int f, a, b, s1, s2, m, n, end = 1, T, wid, len; ///wid, len: ���μ��� �ʵ�ũ��

char notice[50][50] = {                             ///���� �̵��ϴ� ����
     {'9','8','9','1','9'},
     {'7','9','9','9','2'},
     {'9','9','H','9','9'},
     {'6','9','9','9','3'},
     {'9','5','9','4','9'}
},

field[50][50] = {                                ///field x,y ��ǥ
    {'9', '1', '2', '3', '4', '5', '6', '7', '8'}
};


int main() {
    start();
    while (end) {
        asking();
        if (end) print();
    }
    printf("\n�����ϼ̽��ϴ�.\n");                 ///���α׷� �����Ʈ
}

void start() { //���Ժ�. �ʵ带 �ȳ��ϰ� ���� ��ǥ�� �޾ƿ´�.
    printf("�� ������ ����Ʈ�� �����Դϴ�. \n���� 7�� ���Դϴ�");
    printf("\n\n(�ִ� 8X8)�ʵ��� ����, ���� : ");
    scanf("%d %d", &wid, &len);

    makefield();

    printf("\n\n�̵��� ����� �� ���⿡ ���� ������ ���ڴ� ������ �����ϴ�.");
    printf("\n");
    for (int j = 0; j <= 5; j++) {
        for (int i = 0; i <= 5; i++) {
            if (notice[j][i] == '9') {
                printf(" ");
            }
            else {
                printf("%c", notice[j][i]);
            }
        }
        printf("\n");
    }
    print();
    setup();
}

void setup() {
    printf("\n���� ������ ��ǥ�� �����ϼ���. A B : ");
    scanf("%d %d", &s1, &s2);
    if (s1 > wid || s2 > len || s1 == 0 || s2 == 0) {
        printf("\n�߸��� ���� ��ǥ�Դϴ�. ��ǥ�� 1~%d, 1~%d ������ ������ �Է����ּ���.\n", wid, len);
        setup();
    }
    else {
        change(s1, s2);
        print();
        printf("\n�����մϴ�.\a\a\a\n");
    }
}

void makefield() {       ///���μ��� �Է¹��� ���� ���� �ʵ带 ������
    int p = 0;
    for (int q = 1; q <= 9; q++) {
        field[q][p] = field[p][q];
    }
    for (p = 1; p <= wid; p++) {
        for (int q = 1; q <= len; q++) {
            field[q][p] = '0';
        }
    }
}

void print() {           ///�ʵ� �԰� ũ�⿡ ���� �迭�� ������ִ� ����
    printf("\a\n");
    for (int j = 0; j < len + 1; j++) {
        for (int i = 0; i < wid + 1; i++) {
            if (field[j][i] == '9') {
                printf("   ");
            }
            else {
                printf("%3c", field[j][i]);
            }
        }
        printf("\n");
    }

}

void asking() {                          /// �� �� �ִ� ĭ�� ����, ������ �޴´�. ���� ��������� ������ �����ش�.
    field[s2][s1] = '9';               ///�̹� ���� ĭ ���̻� ����Ʈ���� �ʰ� ����
    if (field[s2 - 1][s1 - 2] == '0' || field[s2 - 2][s1 - 1] == '0' || field[s2 - 1][s1 + 2] == '0' || field[s2 - 2][s1 + 1] == '0' || field[s2 + 1][s1 - 2] == '0' || field[s2 + 2][s1 - 1] == '0' || field[s2 + 2][s1 + 1] == '0' || field[s2 + 1][s1 + 2] == '0') { //�� ���� �����Ѱ�?
        printf("\n�̵��� ������ ���ڸ� �Է��ϼ���. A : ");
        scanf("%d", &m);

        switch (m)
        {
        case 1:
            s1 = s1 + 1;
            s2 = s2 - 2;
            if (field[s2][s1] != '0') {                   ///�Է¹��� ��ġ�� �̵� ������ ��ġ('0')�ΰ�?
                printf("�̵� �Ұ����� ĭ�Դϴ�.\n");
                s1 = s1 - 1;
                s2 = s2 + 2;
                field[s2][s1] = '7';
                break;
            }
            break;

        case 2:
            s1 = s1 + 2;
            s2 = s2 - 1;
            if (field[s2][s1] != '0') {
                printf("�̵� �Ұ����� ĭ�Դϴ�.\n");
                s1 = s1 - 2;
                s2 = s2 + 1;
                field[s2][s1] = '7';
                break;
            }
            break;

        case 3:
            s1 = s1 + 2;
            s2 = s2 + 1;
            if (field[s2][s1] != '0') {
                printf("�̵� �Ұ����� ĭ�Դϴ�.\n");
                s1 = s1 - 2;
                s2 = s2 - 1;
                field[s2][s1] = '7';
                break;
            }
            break;

        case 4:
            s1 = s1 + 1;
            s2 = s2 + 2;
            if (field[s2][s1] != '0') {
                printf("�̵� �Ұ����� ĭ�Դϴ�.\n");
                s1 = s1 - 1;
                s2 = s2 - 2;
                field[s2][s1] = '7';
                break;
            }
            break;
        case 5:
            s1 = s1 - 1;
            s2 = s2 + 2;
            if (field[s2][s1] != '0') {
                printf("�̵� �Ұ����� ĭ�Դϴ�.\n");
                s1 = s1 + 1;
                s2 = s2 - 2;
                field[s2][s1] = '7';
                break;
            }
            break;
        case 6:
            s1 = s1 - 2;
            s2 = s2 + 1;
            if (field[s2][s1] != '0') {
                printf("�̵� �Ұ����� ĭ�Դϴ�.\n");
                s1 = s1 + 2;
                s2 = s2 - 1;
                field[s2][s1] = '7';
                break;
            }
            break;
        case 7:
            s1 = s1 - 2;
            s2 = s2 - 1;
            if (field[s2][s1] != '0') {
                printf("�̵� �Ұ����� ĭ�Դϴ�.\n");
                s1 = s1 + 2;
                s2 = s2 + 1;
                field[s2][s1] = '7';
                break;
            }
            break;
        case 8:
            s1 = s1 - 1;
            s2 = s2 - 2;
            if (field[s2][s1] != '0') {
                printf("�̵� �Ұ����� ĭ�Դϴ�.\n");
                s1 = s1 + 1;
                s2 = s2 + 2;
                field[s2][s1] = '7';
                break;
            }
            break;
        default:
            printf("\n�Է� ����. 1~8������ ���ڸ� �Է����ּ���");
        }
    }
    else {
        if (checkwin()) {
            printf("\n�̰���ϴ�! �����մϴ� \n");
            end = 0;
        }
        else {
            printf("\n�����ϴ�.\a\n");
            end = 0;
        }
    }

    if (field[s2][s1] == '0') {          ///�̵���ġ üũ
        change(s1, s2);
    }
}

int change(int p, int q) {           ///����� ���� ��, ��������� ������ �����ش�.
    field[q][p] = '7';
}

int checkwin() {                     ///�¸��� ���, �й��Ѱ�� �Ǵ�
    for (int u = 0; u < 50; u++) {
        for (int t = 0; t < 50; t++) {
            if (field[u][t] == '0') {
                return 0;
            }
        }
    }
    return 1;
}
