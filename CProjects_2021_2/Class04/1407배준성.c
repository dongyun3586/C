#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_NAME 20
typedef struct //������ ����ü ���� ����, ��͵�
{
    char* name;
    int price;
    int grade;
    int num;
}goods;
int setgoods(goods* d)
{
    d->price = (rand() % 10 + 1) * 1000; // �� �ڷ� �����̳� �ݾ� ��͵��� �������� ��ġ�Ѵ� .
    d->num = rand() % 20 + 1;
    int namelen = rand() % (MAX_NAME - 1) + 1;
    d->name = calloc(namelen, sizeof(char));// ������ ��ü ���� ���� ����Ʈ ������ 0���� ��ȯ�ϰ� �����ϱ�
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

    // printf("ǰ��: %20s : %d���  // ����: %5d��  ����: %2d�� ���� \n",d->name, d->grade, d->price, d->num);

}
int main()
{
    int a, b, c, d, j, l, f, q, p = 0;
    int pri, nim, grad;
    int pric = 0;
    int n = 101; // �� ������
    char newgood[20]; // ����ü �迭
    goods* good = malloc(sizeof(goods) * (n + 20));
    memset(good, 0, sizeof(goods) * (n + 20));
    for (int i = 0; i < n; i++)
    {
        setgoods(&good[i]);
    }

    while (1) {
        printf("\n--------------������ ���� ���� ȯ���մϴ�-------------- \n\n");
        printf("---���� ������� ���̳���?---\n");
        printf(" 1. ������ �緯 �Խ��ϴ�.\n 2. ������ �ȱ� ���� �Խ��ϴ�\n 3. �ƴմϴ�.\n ���:");
        scanf("%d", &a);
        if (a != 1 && a != 2)
        {
            printf("�ȳ��� ������"); // �ٷ� ��
            exit(0);
        }
        if (a == 1) // ���� �� ��
        {
            printf("������ ���� �޴��� ���ðڽ��ϱ�?(yes: 1):"); // �� ���� �״�� ���� �� �ٽ� ó������
            scanf("%d", &b);
            if (b != 1)
                continue;
            else
            {
                while (1) {
                    printf("������ ����Դϴ�.\n");
                    /* goods* good = malloc(sizeof(goods)*n);
                     memset(good, 0, sizeof(goods) * n);
                     for(int i=0; i<n; i++)
                     {
                         printf("%4d��° ��ǰ  : ",i+1);
                         setgoods(&good[i]);
                     } */
                    for (int k = 0; k < n; k++)
                    {
                        printf("%3d ��° ��ǰ :", k + 1);
                        printf("ǰ��: %20s : %d���  // ����: %5d��  ����: %2d�� ���� \n", good[k].name, good[k].grade, good[k].price, good[k].num);
                    }
                    printf("\n ���Ͻô� ��ǰ ��ȣ�� ������ : ");
                    scanf("%d", &j);
                    printf("%d��° ������ �� �� �����Ͻðڽ��ϱ�? (���� ����: %d) : ", j, good[j - 1].num);
                    scanf("%d", &c);
                    p += c;           // ���� ���
                    pric += c * (good[j - 1].price); //���� ���
                    good[j - 1].num -= c;
                    free(good);
                    printf("�����Ͻ� ���� �� : %d�� \n", p);
                    printf("���� �� �ݾ� : %d�� \n", pric);
                    printf("�����մϴ�. ��� �̿��Ͻðڽ��ϱ�? (yes = 1): ");
                    scanf("%d", &d);
                    pric = 0, p = 0;  // ��� �������� �� ����
                    if (d != 1)
                        break;
                    else
                    {
                        continue;

                    }
                }

            }

        }
        if (a == 2) //������ �� ��
        {
            printf("���� ����� ���� �帮�ڽ��ϴ� \n");
            for (int k = 0; k < n; k++)
            {
                printf("%3d ��° ��ǰ :", k + 1);
                printf("ǰ��: %20s : %d���  // ����: %5d��  ����: %2d�� ���� \n", good[k].name, good[k].grade, good[k].price, good[k].num);
            }
            printf("\n\n\n���� ������ �� ������ �Ȱ� �ͽ��ϴ�.: 1 \n  �ƴմϴ�.: 2 \n"); // �Ȱ��� ���Ǹ� �� �� �ִ�
            scanf("%d", &l);
            if (l == 1)
            {
                printf("\n�ȷ��� ������ ��ȣ:");
                scanf("%d", &f);
                printf("\n �Ǹ��� �� ��:");
                scanf("%d", &q);
                printf("���� ���Ͻô� �ݾ��� ������ �ּ��� (����� �츮 ������ %d ��° ������ %d���� �Ȱ� �ֽ��ϴ�.) : ", f, good[f - 1].price);
                // �� �̻��� �ݾ��� ���� �ʰڴٴ� �ǹ�
                scanf("%d", &pri);
                if (pri <= good[f].price) {

                    good[f - 1].num += q;
                    for (int k = 0; k < n; k++)
                    {
                        printf("%3d ��° ��ǰ :", k + 1);
                        printf("ǰ��: %20s : %d���  // ����: %5d��  ����: %2d�� ���� \n", good[k].name, good[k].grade, good[k].price, good[k].num);
                    } printf("\n\n�ٲ� ��ǰ ����Դϴ�");
                    printf("\n�Ǹ� �Ϸ�Ǿ����ϴ�. �ٲ���� ��ǰ ����� ���� ��Ƚ��ϴ�.\n");
                    printf("\n ������ �ݾ�: %d��", pri * q);
                    printf("\n�����մϴ�.");
                    free(good);
                }
                else
                    printf("���Ͻô� ���� �帮�⿣ ���� �ʹ� Ů�ϴ� �˼��մϴ�.\n"); // ������ ���⿡ ����
                continue; //�ٽ� ó������
            }


        }








    }
}

