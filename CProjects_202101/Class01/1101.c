#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
int check369(int n) {  //���ڿ� 3, 6, 9�� ������ Ȯ�� + 3, 6, 9�� ������ ������ ����
    int len;
    int n1;
    n1 = n;
    int count = 0;
    // �ڸ��� Ȯ��
    for (int i = 1; n > 0; i++) {
        n = n / 10;
        len = i;
    }
    int arr[10] = { 0 , };
    // �� �ڸ��� ���ڸ� �迭�� �Է�
    for (int i = 0; i < len; i++) {
        arr[i] = n1 % 10;
        n1 = n1 / 10;
    }
    // 3, 6, 9 ������ Ȯ��
    for (int i = 0; i < len; i++) {
        if (arr[i] == 3 || arr[i] == 6 || arr[i] == 9) {
            count++;
        }
    }
    return count;
}
void game369(int n, int gg) { // 369 ���� �����ִ� ���α׷�
    int i = 1;
    int m = 0;
    int arrx[2] = { 1, };
    srand(time(NULL)); // ���̵� '��'���� ���
    if (gg == 1) { // ���̵� ���� ��� 
        for (; i <= n; ) {
            // ��ǻ�� �Է� ����
            if (i % 2 == 1) {
                if (check369(i) > 0) { // 3, 6, 9 �� ������ 0�� ����ϴ� ���
                    for (int j = 0; j < check369(i); j++) {
                        Sleep(200);
                        printf("0 ");
                    }
                    printf("\n");
                }
                else if (check369(i) == 0) { // 3, 6, 9 �� ������ �״�� ������ ���
                    Sleep(500);
                    printf("%d\n", i);
                }
                i++;
            }
            // ����� �Է� ����
            if (i % 2 == 0) {
                if (check369(i) > 0) {
                    if (check369(i) > 0) {
                        for (int j = 0; j < check369(i); j++) {
                            scanf("%d", &arrx[j]);
                        }
                    }
                    if (arrx[check369(i) - 1] != 0) {
                        printf("Ʋ�Ƚ��ϴ�, �Ƿ��� �÷��� ������");
                        return;
                    }
                }
                else if (check369(i) == 0) { // Ʋ�� ���
                    scanf("%d", &m);
                    if (m != i) {
                        printf("Ʋ�Ƚ��ϴ�, �Ƿ��� �÷�������");
                        return;
                    }
                }
                i++;
            }
            // ������ ���� ��� ��� ��
            if (i == 501) {
                printf("you win, ���� ���Ͻô� ����");
                return;
            }
        }
    }
    int loose = 0;
    while (loose <= 50) { // ���Ͱ� �� ����
        loose = rand() % 99 + 1;
    }
    if (gg == 2) { // ���̵� ��
        for (; i <= n; ) {
            // �� �ڵ�� ����
            if (i % 2 == 1) {
                if (check369(i) > 0) {
                    for (int j = 0; j < check369(i); j++) {
                        Sleep(200);
                        printf("0 ");
                    }
                    printf("\n");
                }
                else if (check369(i) == 0) {
                    Sleep(500);
                    printf("%d\n", i);
                }
                i++;
            }
            if (i % 2 == 0) {
                if (check369(i) > 0) {
                    if (check369(i) > 0) {
                        for (int j = 0; j < check369(i); j++) {
                            scanf("%d", &arrx[j]);
                        }
                    }
                    if (arrx[check369(i) - 1] != 0) {
                        printf("Ʋ�Ƚ��ϴ�, �Ƿ��� �÷��� ������");
                        return;
                    }
                }
                else if (check369(i) == 0) {
                    scanf("%d", &m);
                    if (m != i) {
                        printf("Ʋ�Ƚ��ϴ�, �Ƿ��� �÷�������");
                        return;
                    }
                }
                i++;
            }
            if (i == loose) { // ���Ͱ� �� ���ڿ� ����
                printf("you win, ���� ���Ͻô� ����");
                return;
            }
        }
    }
}
int main()
{
back:
    // ���� ����
    printf("� ���� �� ���ΰ���\n");
    printf("1. Ŀ�� ����\n2. ������ �\n3. 369 ����\n");
    int choose;
    scanf("%d", &choose);
    system("cls");
    // Ŀ�� ���� ���� ����
    if (choose == 1) {
        // ���� ����
        printf("         Ŀ�� ���� ���帳�ϴ�..        \n");
        Sleep(1000);
        printf("         ������ ���� ���� �� ���� �̸� ȹ���� ������ ���� ���� �Է��Ͽ� �ּ���. ex) A  A  A 0 B  B  B 0\n");
        Sleep(1000);
        printf("         �� ���� �̸� ���̰� 2�̻� ���� ���� �̸� ������ ���帱 �� �����ϴ�.. \n");
        Sleep(1000);
        printf("         �̸��� �� ���� ���� �Է����ּ��� \n");
        Sleep(1000);
        printf("         ���� ȹ���� �Է��ϰ� ���� '0'�� �Է� ���ּ���!!! \n");
        // ���� ���� Ȯ��
        printf("��� �����Ұ��� ����??\n");
        printf("�� 1. , �ƴϿ� 2.\n");
        int con;
        scanf("%d", &con);
        system("cls");
        if (con == 2) {
            goto back;
            system("cls");// consoleâ ������ 
        }
        // ���� ����
        char name[100] = { 0, };
        char name1[100] = { 0 , };
        int arr[100];
        int arr1[100];
        int arr2[100];
        int n;
        int n1;
        int m;
        // �θ��� �̸� �Է� �ޱ� 
        printf("\n\n\n");
        printf("         �ε���....\n");
        Sleep(5000);
        printf("         �κ��� �̸��� �Է� ���ּ���...\n");
        printf("       ��> : ");
        scanf("%s %s", &name, &name1);
        // �θ� �̸� ȹ�� �迭 2���� �Է� �ޱ�
        printf("         ȹ���� �Է� ���ּ���\n");
        for (int i = 0; ; i++)
        {
            scanf("%d", &arr[i]);
            if (arr[i] == 0)
            {
                n = i;
                break;
            }
        }
        for (int i = 0; ; i++)
        {
            scanf("%d", &arr1[i]);
            if (arr1[i] == 0)
            {
                n1 = i;
                break;
            }
        }
        // �� �迭�� ���� �� �迭�� ��ġ��
        for (int i = 0; i <= n; i++)
        {
            if (i <= n)
            {
                arr2[2 * i] = arr[i];
            }
            if (i <= n1)
            {
                arr2[2 * i + 1] = arr1[i];
            }
        }
        // �̸� ���� ����ϱ�
        m = n + n1;
        while (m > 2)
        {
            for (int i = 0; i < m; i++)
            {
                arr2[i] = (arr2[i] + arr2[i + 1]) % 10;
            }
            m--;
        }
        // ���� ���� ����ϱ�
        printf("\n\n\n");
        printf("         �ε� ��.....\n");
        Sleep(5000);
        system("cls");
        printf("         %s�� �� %s���� �̸� ���� ������ %d�� �Դϴ�.", name, name1, arr2[0] * 10 + arr2[1]);
    }
    // ������ � ���ֱ�
    else if (choose == 2) {
        srand(time(NULL));
        int ranum;
        ranum = rand() % 101;
        printf("����� �̸��� �Է��ϼ���\n");
        char yourname[100] = { 0 , };
        scanf("%s", yourname);
        if (ranum >= 90) {
            printf("����� ������ ��� %d���Դϴ�. \n������ ���� �� �ɰſ���. ����ϴ� ����� �ִٸ� ����غ����� ", ranum);
        }
        else if (ranum >= 80) {
            printf(" ����� ������ ��� %d���Դϴ�. \n ������ ��� ���� ���̿���, ������ �����̸� �������� ���� �����?", ranum);
        }
        else if (ranum >= 70) {
            printf(" ����� ������ ��� %d���Դϴ�. \n ������ ��� ���� ���Դϴ�, ��ó ���Ǳ⿡ ��������, �ٴڿ� ������ �������� �־��", ranum);
        }
        else {
            printf(" ����� ������ ��� %d���Դϴ�. \n ������ �ൿ�� �����Ͻð� ���� �� ���� �ٴϼ���", ranum);
        }
    }
    // 3, 6, 9�� ����
    else if (choose == 3) {
        printf("3 6 9 ������ �ϰ� �ͽ��ϱ�? \n");
        printf("1. ��, 2. �ƴϿ�");
        int choose1;
        scanf("%d", &choose1);
        system("cls");
        printf("3�Ǵ� 6 �Ǵ� 9�� ������ŭ 0�� ���Ἥ �Է����ּ���");
        if (choose1 == 2) {
            goto back;
        }
        printf("���̵��� ������\n 1. �� 2. ��\n");
        int hardless;
        scanf("%d", &hardless);
        system("cls");
        int uu = 500;
        game369(uu, hardless);
    }
    else {
        goto back;
    }
}