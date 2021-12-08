#include <stdio.h>
#define MAX_COUNT 7   /* 일정 등록 가능한 최대 수 */

// 구조체 정의
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
    // 구조체 배열 선언
    Planner plans[MAX_COUNT];
    int count = 0;         /* count : 등록된 일정 수  */

    while (1)
    {
        printf("[일정표] 새로운 일정 추가 = 1, 입력된 일정 목록 보기 = 2, 종료 = 3 : ");
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
            printf("1 ~ 3 번호만 선택할 수 있습니다. 다시 입력해 주세요\n\n");
            break;
        }
    }

    return 0;
}

int AddPlan(Planner* p, int count)
{
    if (count < MAX_COUNT)
    {
        // 일정 정보 입력받기
        printf("\n새로운 일정 정보를 입력하세요\n");
        printf("1. 연도 : ");
        scanf("%d", &p[count].year);
        printf("2. 달 : ");
        scanf("%d", &p[count].month);
        printf("3. 날짜 : ");
        scanf("%d", &p[count].date);

        printf("4. 요일 : ");
        rewind(stdin);
        gets(p[count].day);
        printf("5. 일정 : ");
        rewind(stdin);
        gets(p[count].plan);

        printf("입력을 완료했습니다. \n\n");
        return 1;
    }

    else
    {
        /* 입력 가능한 최대 수를 넘었을 때 오류 상태 출력 */
        printf("최대 입력 가능한 일정 수을 초과하여 입력을 할 수 없습니다. \n");
        printf("최대 %d일까지만 입력 가능합니다. \n\n", MAX_COUNT);
    }

    return 0;  /* 일정 추가 실패 */
}

void ShowPlanList(Planner* p, int count)
{
    int i;
    if (count > 0)
    { /* 등록된 일정이 있으면 그 수만큼 반복하면서 일정 정보 출력 */
        printf("\n등록된 일정 목록\n");
        printf("  연도    달   날짜     요일                   일정                     \n");
        printf("=============================================================================\n");
        for (i = 0; i < count; i++)
        {
            // 일정 정보 출력
            printf("  %4d    %2d   %2d     %s        %s            \n", (p[i].year), (p[i].month), (p[i].date), (p[i].day), (p[i].plan));
        }
        printf("=============================================================================\n\n");
    }

    else
    {  /* 등록된 일정이 없으면 오류 상태 출력 */
        printf("\n등록된 일정이 없습니다.\n\n");
    }
}