#include <stdio.h>

#define MAX_COUNT        5   /* 친구 등록 가능한 최대 수 */

typedef char NAME_TYPE[14];
enum menu { INSERT = 1, SHOW, EXIT };

/* 친구를 추가하는 함수 : 성공하면 1을 반환하고 실패하면 0을 반환 함 */
int AddFriend(NAME_TYPE* p_name, unsigned short int* p_age, float* p_height, float* p_weight, int count)
{
    if (count < MAX_COUNT) {  /* 입력 가능한 최대 수를 넘었는지 체크 */
        printf("\n새로운 친구 정보를 입력하세요\n");
        printf("1. 이름 : ");
        rewind(stdin);	// 표준 입력 버퍼에 있는 모든 입력값 제거
        gets(p_name[count]);
        printf("2. 나이 : ");
        scanf("%d", p_age + count); /* age 배열의 count 위치에 나이 입력 */
        printf("3. 키 : ");
        scanf("%f", p_height + count); /* height 배열의 count 위치에 키 입력 */
        printf("4. 몸무게 : ");
        scanf("%f", p_weight + count); /* weight 배열의 count 위치에 몸무게 입력 */
        printf("입력을 완료했습니다. \n\n");
        return 1;  /* 친구 추가 성공 */
    }
    else {
        /* 입력 가능한 최대 수를 넘었을 때 오류 상태 출력 */
        printf("최대 인원을 초과하여 입력을 할 수 없습니다. \n");
        printf("최대 %d명까지만 관리 가능합니다. \n\n", MAX_COUNT);
    }
    return 0;  /* 친구 추가 실패 */
}

/* 등록된 친구를 출력하는 함수 */
void ShowFriendList(NAME_TYPE* p_name, unsigned short int* p_age, float* p_height, float* p_weight, int count)
{
    int i;
    if (count > 0) { /* 등록된 친구가 있으면 그 수만큼 반복하면서 친구 정보 출력 */
        printf("\n등록된 친구 목록\n");
        printf("     이름       나이   키     몸무게\n");
        printf("=======================================\n");
        for (i = 0; i < count; i++)
            printf("%-14s, %3d, %6.2f, %6.2f\n", *(p_name + i), *(p_age + i), *(p_height + i), *(p_weight + i));
        printf("=======================================\n\n");
    }
    else {  /* 등록된 친구가 없으면 오류 상태 출력 */
        printf("\n등록된 친구가 없습니다.\n\n");
    }
}

int main()
{
    enum menu choice;
    NAME_TYPE name[MAX_COUNT];          /* 친구 이름을 저장할 배열 */
    unsigned short int age[MAX_COUNT];  /* 친구 나이를 저장할 배열 */
    float height[MAX_COUNT];            /* 친구 키를 저장할 배열 */
    float weight[MAX_COUNT];            /* 친구 몸무게를 저장할 배열 */
    int count = 0, num;                 /* count : 등록된 친구 수  */

    while (1) {                         /* 무한 루프 : 사용자가 3을 누르면 break 문으로 종료 시킴 */
        printf("[번호 선택] 친구 추가=1, 친구 목록 보기=2, 종료=3 : ");
        scanf("%d", &choice);  /* 사용자에게 번호를 입력 받음 */

        switch (choice)
        {
        case INSERT:
            if (AddFriend(name, age, height, weight, count)) count++;
            break;
        case SHOW:
            ShowFriendList(name, age, height, weight, count);
            break;
        case EXIT:
            goto EXIT;
        default:
            printf("1~3 번호만 선택할 수 있습니다!!\n\n");
        }
    }
EXIT:
    return 0;
}