#include <stdio.h>
#define MAX_COUNT 7   /* ���� ��� ������ �ִ� �� */

// ����ü ����
typedef struct
{
    char day[100];
    char plan[500];
    int year;
    int month;
    int date;
} Planner;

enum menu { PLUS = 1, LIST, EXIT } choice;

int AddPlan(Planner* p, int count);
void ShowPlanList(Planner* p, int count);

int main()
{
    // ����ü �迭 ����
    Planner plans[MAX_COUNT];
    int count = 0;         /* count : ��ϵ� ���� ��  */

    while (1)
    {
        printf("[����ǥ] ���ο� ���� �߰� = 1, �Էµ� ���� ��� ���� = 2, ���� = 3 : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case PLUS:
            if (AddPlan(plans, count) == 1)
                count++;
            break;
        case LIST:
            ShowPlanList(plans, count);
            break;
        case EXIT:
            exit(0);
        default:
            printf("1 ~ 3 ��ȣ�� ������ �� �ֽ��ϴ�. �ٽ� �Է��� �ּ���\n\n");
            break;
        }
    }

    return 0;
}

int AddPlan(Planner* p, int count)
{
    if (count < MAX_COUNT)
    {
        // ���� ���� �Է¹ޱ�
        printf("\n���ο� ���� ������ �Է��ϼ���\n");
        printf("1. ���� : ");
        scanf("%d", &p[count].year);
        printf("2. �� : ");
        scanf("%d", &p[count].month);
        printf("3. ��¥ : ");
        scanf("%d", &p[count].date);

        printf("4. ���� : ");
        rewind(stdin);
        gets(p[count].day);
        printf("5. ���� : ");
        rewind(stdin);
        gets(p[count].plan);

        printf("�Է��� �Ϸ��߽��ϴ�. \n\n");
        return 1;
    }

    else
    {
        /* �Է� ������ �ִ� ���� �Ѿ��� �� ���� ���� ��� */
        printf("�ִ� �Է� ������ ���� ���� �ʰ��Ͽ� �Է��� �� �� �����ϴ�. \n");
        printf("�ִ� %d�ϱ����� �Է� �����մϴ�. \n\n", MAX_COUNT);
    }

    return 0;  /* ���� �߰� ���� */
}

void ShowPlanList(Planner* p, int count)
{
    int i;
    if (count > 0)
    { /* ��ϵ� ������ ������ �� ����ŭ �ݺ��ϸ鼭 ���� ���� ��� */
        printf("\n��ϵ� ���� ���\n");
        printf("  ����    ��   ��¥     ����                   ����                     \n");
        printf("=============================================================================\n");
        for (i = 0; i < count; i++)
        {
            // ���� ���� ���
            printf("  %4d    %2d   %2d     %s        %s            \n", (p[i].year), (p[i].month), (p[i].date), (p[i].day), (p[i].plan));
        }
        printf("=============================================================================\n\n");
    }

    else
    {  /* ��ϵ� ������ ������ ���� ���� ��� */
        printf("\n��ϵ� ������ �����ϴ�.\n\n");
    }
}