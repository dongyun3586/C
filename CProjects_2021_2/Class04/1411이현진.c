#include <Windows.h>
#include <stdio.h>
#define MAX_COUNT 5   /* ģ�� ��� ������ �ִ� �� */
#include<math.h> //�ݿø��ϴ� �Լ��� floor�Լ��� ����ϱ� ���� �� ��������� ����ϰ� �Ǿ���.

// 1. ����ü ����
typedef struct {
    char name[50];
    char subject[50];
    int point;
    float score;
    float average;
    float student; //�� �л���
    float pyo; //ǥ������
    int grade; //����
}Person;

float z;
void Zscore(Person* p)
{
    z = (float)(((p->score) - (p->average)) / (p->pyo)); //z������ ���� (������-���)/ǥ������
    printf("����� z������ %.4f�̸�, ", z);
}

enum menu { INSERT = 1, SHOW, EXIT } choice;

int AddFriend(Person* p, int count);
void ShowFriendList(Person* p, int count);

int main()
{
    // 2. ����ü �迭 ����
    Person friends[MAX_COUNT];
    int count = 0, num;         /* count : ��ϵ� ģ�� ��  */


    while (1) {
        printf("[��ȣ ����] ģ�� �߰�=1, ģ�� ��� ����=2, ����=3 : ");
        scanf("%d", &choice);  /* ����ڿ��� ��ȣ�� �Է� ���� */

        switch (choice)
        {
        case INSERT:
            if (AddFriend(friends, count) == 1) count++;
            break;
        case SHOW:
            ShowFriendList(friends, count);
            break;
        case EXIT:
            exit(0);
        default:
            printf("1~3 ��ȣ�� ������ �� �ֽ��ϴ�!!\n\n");
            break;
        }
    }

    return 0;
}
int AddFriend(Person* p, int count)
{
    int number;
    if (count < MAX_COUNT) {
        // 3. ģ�� ���� �Է¹ޱ�
        printf("\n���ο� ģ�� ������ �Է��ϼ���\n");
        printf("1. �̸� : ");
        scanf("%s", p[count].name);

        printf("%d. ����� ���� : ", count + 1);
        scanf("%s %d", (p[count].subject), &(p[count].point));
        printf("%d. ������ ������� ǥ������ �л���", count + 1);
        scanf(" %f %f %f %f", &(p[count].score), &(p[count].average), &(p[count].pyo), &(p[count].student));
        Zscore(p);

        float temp = floor(z * 100) / 100;   //z�Լ��� �Ҽ� ù° �ڸ� ���� �ݿø� �Ѱ� 

        //printf("<<%f>>\n", temp);


        float arr100[61] = { 0.0013, 0.0019, 0.0026, 0.0035, 0.0047, 0.0062, 0.0082, 0.0107, 0.0139, 0.0179, 0.0228, 0.0287, 0.0359, 0.0446, 0.0548, 0.0668, 0.0808, 0.0968, 0.1151, 0.1357, 0.1587, 0.1841, 0.2119, 0.2420, 0.2743, 0.3085, 0.3446, 0.3821, 0.4207, 0.4602, 0.5, 0.5398, 0.5793, 0.6179, 0.6554, 0.6915, 0.7257, 0.7580, 0.7881, 0.8159, 0.8413, 0.8643, 0.8849, 0.9032, 0.9192, 0.9332, 0.9452, 0.9554, 0.9641, 0.9713, 0.9772, 0.9821, 0.9861, 0.9893, 0.9918, 0.9938, 0.9953, 0.9965, 0.9974, 0.9981, 0.9987 };

        int temppp = 10 * (3 - temp);     //Z������ 3.0���� 0.1�� �����ϱ⿡ �迭�� ������� �ʾƼ� Z������ �迭�� �ִٰ� �����ϰ� �� ��ġ�� arr100 �迭�� ��ġ�� �����Ͽ� ���� ������� ������ �Ѵ�. �׷��� ��ġ�� ��Ÿ���� ������ ���� temppp�� ����Ͽ���. 
        //printf("<<%d>>", temppp);
        printf("�� %0.0f�� �� %d���Դϴ�.", p[count].student, (int)(arr100[temppp] * 100));

        int grade = (int)(arr100[temppp] * 100);
        p[count].grade = grade; //������ ����� �뷫������ �˱� ���ؼ� A-�� B+ ����� ���� 20%�� ���߰� �ٸ� ����� 15%�� ���Ͽ����ϴ�. 
        if (0 <= grade && grade <= 15)
            printf("\n������ A+�Դϴ�.\n");
        else if (15 <= grade && grade < 30)
            printf("\n������ A0�Դϴ�.\n");
        else if (30 <= grade && grade < 50)
            printf("\n������ A-�Դϴ�.\n");
        else if (50 <= grade && grade < 70)
            printf("\n������ B+�Դϴ�.\n");
        else if (70 <= grade && grade < 85)
            printf("\n������ B0�Դϴ�.\n");
        else if (85 <= grade && grade < 100)
            printf("\n������ B-�Դϴ�.\n");


        printf("\n�Է��� �Ϸ��߽��ϴ�. \n\n");
        return 1;  /* ģ�� �߰� ���� */

    }
    else {
        /* �Է� ������ �ִ� ���� �Ѿ��� �� ���� ���� ��� */
        printf("�ִ� �ο��� �ʰ��Ͽ� �Է��� �� �� �����ϴ�. \n");
        printf("�ִ� %d������� ���� �����մϴ�. \n\n", MAX_COUNT);
    }
    return 0;  /* ģ�� �߰� ���� */
}

void ShowFriendList(Person* p, int count)
{
    int i;
    if (count > 0) { /* ��ϵ� ģ���� ������ �� ����ŭ �ݺ��ϸ鼭 ģ�� ���� ��� */
        printf("\n��ϵ� ģ�� ���\n");
        printf("     �̸�       �����   ���\n");
        printf("===========================\n");
        for (i = 0; i < count; i++) {
            // 4. ģ�� ���� ���
            printf("      %s,    %s,    %d\n", &p[i].name, &p[i].subject, p[i].grade);
        }
        printf("=======================================\n\n");
    }
    else {  /* ��ϵ� ģ���� ������ ���� ���� ��� */
        printf("\n��ϵ� ģ���� �����ϴ�.\n\n");
    }

}
