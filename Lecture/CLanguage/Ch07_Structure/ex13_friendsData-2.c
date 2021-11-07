#include <stdio.h>
#define MAX_COUNT        5   /* ģ�� ��� ������ �ִ� �� */

// 1. ����ü ����
typedef struct People
{
    char name[14];            /* �̸� */
    unsigned short int age;    /* ���� */
    float height;              /* Ű */
    float weight;              /* ������ */
} Person;

enum menu { INSERT = 1, SHOW, EXIT } choice;

int AddFriend(Person* p, int count);
void ShowFriendList(Person* p, int count);

int main()
{
    Person friends[MAX_COUNT];  /* ģ�� ������ ������ �迭 */
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
    if (count < MAX_COUNT) {  /* �Է� ������ �ִ� ���� �Ѿ����� üũ */
        p = p + count; /* friends �迭�� count ��ġ�� �ּ� �̵� */
        printf("\n���ο� ģ�� ������ �Է��ϼ���\n");
        printf("1. �̸� : ");
        rewind(stdin);	// ǥ�� �Է� ���ۿ� �ִ� ��� �Է°� ����
        gets(p->name);
        printf("2. ���� : ");
        scanf("%d", &p->age); /* ����ü�� age �׸� �Է�*/
        printf("3. Ű : ");
        scanf("%f", &p->height); /* ����ü�� height �׸� �Է� */
        printf("4. ������ : ");
        scanf("%f", &p->weight); /* ����ü�� weight �׸� �Է� */
        printf("�Է��� �Ϸ��߽��ϴ�. \n\n");
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
        printf("     �̸�       ����   Ű     ������\n");
        printf("=======================================\n");
        for (i = 0; i < count; i++) {
            //printf("%-14s, %3d, %6.2f, %6.2f\n", p->name, p->age, p->height, p->weight);
            //p++;  /* ���� ��ġ�� �ִ� ģ�� ������ �ּ� �̵� */
            printf("%-14s, %3d, %6.2f, %6.2f\n", p[i].name, p[i].age, p[i].height, p[i].weight);
        }
        printf("=======================================\n\n");
    }
    else {  /* ��ϵ� ģ���� ������ ���� ���� ��� */
        printf("\n��ϵ� ģ���� �����ϴ�.\n\n");
    }
}