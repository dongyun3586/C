#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

#define e 2.71828 //�ڿ���� ����

int main()
{
    char choice[5];//ȸ�� ������ �� ���ڿ� �Է�
    float volt = 0;
    float res = 0;
    float induct = 0;
    float cap = 0;
    float i = 0;
    float time = 0;
    const char* A = "r"; //���� ���ڿ� ����
    const char* B = "rl"; //���� ���ڿ� ����
    const char* C = "rc"; //���� ���ڿ� ����
    printf("ȸ�� �м�");
    Sleep(2000);//2�ʰ� ��ٸ�
    system("cls");//��µ� ���� ����
    printf("���� ������ ȸ�θ� �м��Ͻǰǰ���?\n\n");
    Sleep(1000);//1�ʰ� ��ٸ�
    while (1)//�ݺ�
    {
        printf("r, rl, rc ȸ�� �� �ϳ��� �����ϼ���\n");
        scanf("%s", choice);//�Է� �ޱ�
        for (int i = 0; choice[i] != 0; i++)
            choice[i] = tolower(choice[i]);//�빮���� ��� �ҹ��ڷ� ��ȯ
        if (!strcmp(choice, A) || !strcmp(choice, B) || !strcmp(choice, C))//r, rl, rc �߿� ������ �ʾҴٸ� ���α׷��� �������� �Ѵ�
            break;
    }

    if (strcmp(choice, A) == 0)//r ȸ��
    {
        printf("\n���׸� �����ϴ� r ȸ���� �м�\n\n������ ������ �Է����ּ���\n");
        printf("���� (V) : ");//���а� �Է�
        scanf("%f", &volt);
        printf("���� (��) : ");//���װ� �Է�
        scanf("%f", &res);
        i = volt / res;//���� ���Ŀ� ����
        printf("\n�� ȸ���� ������ : %.3f A\n", i);//�������� �Ҽ��� �Ʒ� ��° �ڸ����� ���
    }
    else if (strcmp(choice, B) == 0)//rlȸ��
    {
        printf("\n���װ� �����Ⱑ �����ϴ� rl ȸ���� �м�\n\n������ ���װ� �δ��Ͻ��� �Է����ּ���\n");
        printf("���� (V) : ");//������ �Է�
        scanf("%f", &volt);
        printf("���� (��) : ");//���װ� �Է�
        scanf("%f", &res);
        printf("�δ��Ͻ� (H) : ");//�δ��Ͻ��� �Է�
        scanf("%f", &induct);
        float taw = -1 * res / induct;//������ ���Ŀ� ����
        float co = volt / res;//�ʱ� ������ �����ֱ�
        printf("\n�� rlȸ���� ������ �ð��� ���� ���� : %.3f*(1-exp(%.3f*t))\n\n\n", co, taw);//rlȸ���� �ð��� ���� ������ ��Ÿ���ֱ�
        printf("     ����\n");
        printf("      ��\n");
        printf("      ��\n");
        printf("      ��\n");
        printf("%.3f ��                                                                                 ��\n", co);
        printf("      ��                                                          ��\n");
        printf("      ��                                         ��\n");
        printf("      ��                              ��\n");
        printf("      ��                      ��\n");
        printf("      ��                 ��\n");
        printf("      ��             ��\n");
        printf("      ��         ��\n");
        printf("      ��      ��\n");
        printf("      ��    ��\n");
        printf("      ��  ��\n");
        printf("      �� �� \n");
        printf("      ����\n");
        printf("      �������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������� �ð�\n");//�׷��� �׸���
        while (1)//�ð��� �־��־��� ���� ������ �����ֱ�
        {
            printf("�ð��� �Է��ϼ��� (���� : -1)\n");
            rewind(stdin);//�Է¹��� ����
            scanf("%f", &time);
            if (time < 0)
                break;
            float taw_t = taw * time;
            float time_i = co * (1 - pow(e, taw_t));//�ð��� ���� ������ ���
            printf("�ð� %.3f�� �� ���� : %.3f A\n", time, time_i);
        }
    }
    else if (strcmp(choice, C) == 0)//rcȸ��
    {
        printf("\n���װ� �����Ⱑ �����ϴ� rc ȸ���� �м�\n\n����, ����, �������� ����뷮�� �Է����ּ���\n");
        printf("���� (V) : ");//���а� �Է�
        scanf("%f", &volt);
        printf("���� (��) : ");//���װ� �Է�
        scanf("%f", &res);
        printf("�������� ���� �뷮 (F) : ");//����뷮 �� �Է�
        scanf("%f", &cap);
        float taw = -1 / (res * cap);//rcȸ�� ������ ���Ŀ� ����
        float co = volt / res;//�ʱ������� ���Ŀ� ����
        printf("\n�� rlȸ���� ������ �ð��� ���� ���� : %.3f*exp(%.3f*t)\n", co, taw);//�ð��� ���� ������ ���Ŀ� �����ؼ� ���
        printf("     ����\n");
        printf("      ��\n");
        printf("      ��\n");
        printf("      ��\n");
        printf("      ��\n");
        printf("%.3f ����\n", co);
        printf("      �� ��\n");
        printf("      ��   ��\n");
        printf("      ��      ��\n");
        printf("      ��          ��\n");
        printf("      ��              ��\n");
        printf("      ��                   ��\n");
        printf("      ��                           ��\n");
        printf("      ��                                           ��\n");
        printf("      ��                                                                             ��\n");
        printf("      �������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������� �ð�\n");//�ð��� ���� ���� �׷���
        while (1)
        {
            printf("�ð��� �Է��ϼ��� (���� : -1)\n");//�ð��� �Է����־��� ���� ���� ����ϱ�
            rewind(stdin);
            scanf("%f", &time);
            if (time < 0)
                break;
            float taw_t = taw * time;
            float time_i = co * pow(e, taw_t);//�ð��� ���� ������ ���
            printf("�ð� %.3f�� �� ���� : %.3f A\n", time, time_i);
        }
    }
}
