#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int main()
{
    int k, w;
    printf("�ȳ��ϼ��� ���� �߱� ���α׷��Դϴ�.\n");
    printf("���� �߱� �Ͻðڽ��ϱ�?\n");
    printf("1.�� 2.�ƴϿ�\n");
    scanf("%d", &k);
    if (k == 2) {
        printf("�ȳ����輼��\n");
        return 0;
    }
    system("cls"); //����â���� ������ �ִ� ������� ������� �Ѵ�. 
    printf("������ �����ϼ���\n");
    printf("1.���� 2.����� 3.�ſ� �����\n");
    scanf("%d", &w);
    srand(time(NULL));
    if (w == 1) {
        int n[4], a[4], b, s, count = 0;

        n[0] = rand() % 10;
        while (1)
        {
            n[1] = rand() % 10;
            if (n[1] != n[0])
            {
                break;
            }
        }
        while (1)
        {
            n[2] = rand() % 10;
            if ((n[2] != n[0]) && (n[2] != n[1])) // ���ھ߱����� ��ġ�� ���ڰ� ������ �ϱ� ���� ����̴�. 
            {
                break;
            }
        }
        while (1)
        {
            n[3] = rand() % 10;
            if ((n[3] != n[0]) && (n[3] != n[1]) && (n[3] != n[2]))
            {
                break;
            }
        }
        if (k == 1) {
            printf("�׷� �����ϰڽ��ϴ�.\n");
            system("cls");
            while (1)
            {
                b = 0, s = 0;
                printf("���� �ٸ� 0~9������ ���� 4���� �Է��ϼ���.");
                for (int i = 0; i <= 3; i++)
                {
                    scanf("%d", &a[i]);
                    if (a[i] == n[i])
                    {
                        s++;
                    }
                    for (int j = 0; j <= 3; j++)
                    {
                        if (a[i] == n[j])
                        {
                            b++;
                        }
                    }
                }
                b -= s;
                count++;
                printf("%d ball,%d strike\n", b, s);
                printf("%d�� �߽��ϴ�.\n", count);
                if (count > 8) {
                    printf("����� ���� �̱� �� �����ϴ�. ������ �����ϼ���.\n");
                    printf("������ %d %d %d %d�Դϴ�.", n[0], n[1], n[2], n[3]);
                    break;
                }
                if (b == 0 && s == 0)
                {
                    printf("out!!!\n");
                }
                if (s == 4)
                {
                    printf("�����Դϴ�. ��� �� �ȶ��ϳ׿�!\n");
                    break;
                }
            }
        }
    }
    else if (w == 2) {
        int n[5], a[5], b, s, count = 0;

        n[0] = rand() % 10;
        while (1)
        {
            n[1] = rand() % 10;
            if (n[1] != n[0])
            {
                break;
            }
        }
        while (1)
        {
            n[2] = rand() % 10;
            if ((n[2] != n[0]) && (n[2] != n[1]))
            {
                break;
            }
        }
        while (1)
        {
            n[3] = rand() % 10;
            if ((n[3] != n[0]) && (n[3] != n[1]) && (n[3] != n[2]))
            {
                break;
            }
        }
        while (1)
        {
            n[4] = rand() % 10;
            if ((n[4] != n[0]) && (n[4] != n[1]) && (n[4] != n[2]) && (n[4] != n[3]))
            {
                break;
            }
        }
        if (k == 1) {
            printf("�׷� �����ϰڽ��ϴ�.\n");
            system("cls");
            while (1)
            {
                b = 0, s = 0;
                printf("���� �ٸ� 0~9������ ���� 5���� �Է��ϼ���.");
                for (int i = 0; i <= 4; i++)
                {
                    scanf("%d", &a[i]);
                    if (a[i] == n[i])
                    {
                        s++;
                    }
                    for (int j = 0; j <= 4; j++)
                    {
                        if (a[i] == n[j])
                        {
                            b++;
                        }
                    }
                }
                b -= s;
                count++;
                printf("%d ball,%d strike\n", b, s);
                printf("%d�� �߽��ϴ�.\n", count);
                if (count > 11) {
                    printf("����� ���� �̱� �� �����ϴ�. ������ �����ϼ���.\n");
                    printf("������ %d %d %d %d %d�Դϴ�.", n[0], n[1], n[2], n[3], n[4]);
                    break;
                }
                if (b == 0 && s == 0)
                {
                    printf("out!!!\n");
                }
                if (s == 5)
                {
                    printf("�����Դϴ�. ��� �� �ȶ��ϳ׿�!\n");
                    break;
                }
            }
        }
    }
    else {
        int n[5], a[5], b, s, count = 0;

        n[0] = rand() % 10;
        while (1)
        {
            n[1] = rand() % 10;
            if (n[1] != n[0])
            {
                break;
            }
        }
        while (1)
        {
            n[2] = rand() % 10;
            if ((n[2] != n[0]) && (n[2] != n[1]))
            {
                break;
            }
        }
        while (1)
        {
            n[3] = rand() % 10;
            if ((n[3] != n[0]) && (n[3] != n[1]) && (n[3] != n[2]))
            {
                break;
            }
        }
        while (1)
        {
            n[4] = rand() % 10;
            if ((n[4] != n[0]) && (n[4] != n[1]) && (n[4] != n[2]) && (n[4] != n[3]))
            {
                break;
            }
        }
        while (1)
        {
            n[5] = rand() % 10;
            if ((n[5] != n[0]) && (n[5] != n[1]) && (n[5] != n[2]) && (n[5] != n[3]) && (n[5] != n[4]))
            {
                break;
            }
        }

        if (k == 1) {
            printf("�׷� �����ϰڽ��ϴ�.\n");
            system("cls");
            while (1)
            {
                b = 0, s = 0;
                printf("���� �ٸ� 0~9������ ���� 6���� �Է��ϼ���.");
                for (int i = 0; i <= 5; i++)
                {
                    scanf("%d", &a[i]);
                    if (a[i] == n[i])
                    {
                        s++;
                    }
                    for (int j = 0; j <= 5; j++)
                    {
                        if (a[i] == n[j])
                        {
                            b++;
                        }
                    }
                }
                b -= s;
                count++;
                printf("%d ball,%d strike\n", b, s);
                printf("%d�� �߽��ϴ�.\n", count);
                if (count > 14) {
                    printf("����� ���� �̱� �� �����ϴ�. ������ �����ϼ���.\n");
                    printf("������ %d %d %d %d %d %d�Դϴ�.", n[0], n[1], n[2], n[3], n[4], n[5]);
                    break;
                }
                if (b == 0 && s == 0)
                {
                    printf("out!!!\n");
                }
                if (s == 6)
                {
                    printf("�����Դϴ�. ��� �� �ȶ��ϳ׿�!\n");
                    break;
                }
            }
        }
        return 0;
    }
}