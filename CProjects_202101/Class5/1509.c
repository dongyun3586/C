#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void multi();//��Ƽ�÷��̿� �̱��÷����� �Լ��� ��������.
void single();

int main(void)
{
    int k;
    while (1) {
        printf("�̱��÷��̴� 1, ��Ƽ�÷��̴� 2�� �Է��ϼ���.");
        scanf("%d", &k);
        if (k != 1 && k != 2)//1�Ǵ� 2�� �Էµ��� ������ �ٽ� �Է°��� �޴´�.
            printf("�ٽ� �Է��ϼ���.\n");
        else
            break;
    }
    if (k == 1)
        single();//1�� �Է��ϸ� �̱��÷���

    else if (k == 2)
        multi();//2�� �Է��ϸ� ��Ƽ�÷���
}
void single() {//�̱��Լ�
    int i, mycnt, comcnt, cnt = 0;
    while (cnt < 31)
    {
        printf("��� ���ڸ� �θ��ðڽ��ϱ�?\n");
        printf("1���� 3������ ���ڸ� �Է��ϼ���.\n");
        scanf("%d", &mycnt);
        if (1 <= mycnt && mycnt <= 3)//�ڽ��� �θ� �� �ִ� ������ ������ �ִ� 3���̴�.
        {
            printf("����� �θ� ���ڴ� : ");

            for (i = 1; i <= mycnt; i++)//1���� ī��Ʈ�� �����Ͽ� ���� �θ� ������ 1�� ���ذ�
            {
                ++cnt;//ī��Ʈ 1 ������
                printf("%d ", cnt);//ī���� ���

                if (cnt == 31) break;//�Ǵ�
            }

            if (cnt == 31) //���� ���������ڸ��� ����� ���Ϲ� Ż�� 
            {
                printf("����� �й��ϼ̽��ϴ�.\n"); break;
            }

            else printf("\n");

            srand(time(NULL));//srand seed�� �ʱ�ȭ
            comcnt = rand() % 3 + 1;//��ǻ�Ͱ� �θ��� ���� ����-3���� ���� �������� 1�� ������.

            printf("��ǻ�Ͱ� �θ� ���ڴ� : ");

            for (i = 1; i <= comcnt; i++)
            {
                ++cnt;
                printf("%d ", cnt);

                if (cnt == 31) break;//��������
            }
            if (cnt == 31)//��ǻ�Ͱ� �θ� ���ڰ� 31�� �ɋ�
            {
                printf("����� �¸��ϼ̽��ϴ�.\n"); break;
            }

            else printf("\n");

        }
        else
        {
            printf("�ٽ� �Է��ϼ���.\n");
        }
    }

    //if((com+i)>=31
  //   printf("����� �¸��ϼ̽��ϴ�.\n");
   // else
   //  printf("����� �й��ϼ̽��ϴ�.\n");

}

void multi() {
    int now, i, usercnt, cnt = 0;//�Լ� ��ü�� �ٲ��� �ٽ� �ѹ� ���� ����
    srand(time(NULL));
    now = rand() % 2 + 1;//�÷��̾� ���� ���� ���� �������� �������� ����
    printf("\n�÷��̾� %d�� ���� �����մϴ�.\n", now);
    while (1) {
        printf("\n�÷��̾� %d, ��� ���ڸ� �θ��ðڽ��ϱ�?\n", now);
    re:
        printf("1���� 3������ ���ڸ� �Է��ϼ���.\n");
        printf("���� ����:%d\n", cnt);
        scanf("%d", &usercnt);
        if (usercnt < 1 || usercnt > 3) {// ������ �θ� ���ڰ� 1�̻� 3���Ͽ��� ��
            printf("�ٽ� �Է��ϼ���.");
            goto re;// ���� 1�̸� 3�ʰ��� �θ��� �ٽ� re�� ���ư�
        }
        printf("\n�÷��̾� %d�� �θ� ���ڴ�:", now);
        for (int i = cnt + 1; i <= cnt + usercnt; i++)//���� ������ ���� ���ں��� 
            printf("%d ", i);
        cnt += usercnt;//������ �θ� ���� ī��Ʈ�� ����
        if (now == 1)
            now = 2;
        else
            now = 1;//������ �ٲ���
        if (cnt >= 31)//cnt�� 31�� ������ ���� ����
            break;
    }
    printf("\n�÷��̾� %d�� �¸��ϼ̽��ϴ�.\n", now);
}