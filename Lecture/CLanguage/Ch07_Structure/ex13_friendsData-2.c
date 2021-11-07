#include <stdio.h>
#define MAX_COUNT        5   /* 친구 등록 가능한 최대 수 */

// 1. 구조체 정의
typedef struct People
{
    char name[14];            /* 이름 */
    unsigned short int age;    /* 나이 */
    float height;              /* 키 */
    float weight;              /* 몸무게 */
} Person;

enum menu { INSERT = 1, SHOW, EXIT } choice;

int AddFriend(Person* p, int count);
void ShowFriendList(Person* p, int count);

int main()
{
    Person friends[MAX_COUNT];  /* 친구 정보를 저장할 배열 */
    int count = 0, num;         /* count : 등록된 친구 수  */

    while (1) {
        printf("[번호 선택] 친구 추가=1, 친구 목록 보기=2, 종료=3 : ");
        scanf("%d", &choice);  /* 사용자에게 번호를 입력 받음 */

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
            printf("1~3 번호만 선택할 수 있습니다!!\n\n");
            break;
        }
    }

    return 0;
}

int AddFriend(Person* p, int count)
{
    if (count < MAX_COUNT) {  /* 입력 가능한 최대 수를 넘었는지 체크 */
        p = p + count; /* friends 배열의 count 위치로 주소 이동 */
        printf("\n새로운 친구 정보를 입력하세요\n");
        printf("1. 이름 : ");
        rewind(stdin);	// 표준 입력 버퍼에 있는 모든 입력값 제거
        gets(p->name);
        printf("2. 나이 : ");
        scanf("%d", &p->age); /* 구조체의 age 항목에 입력*/
        printf("3. 키 : ");
        scanf("%f", &p->height); /* 구조체의 height 항목에 입력 */
        printf("4. 몸무게 : ");
        scanf("%f", &p->weight); /* 구조체의 weight 항목에 입력 */
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

void ShowFriendList(Person* p, int count)
{
    int i;
    if (count > 0) { /* 등록된 친구가 있으면 그 수만큼 반복하면서 친구 정보 출력 */
        printf("\n등록된 친구 목록\n");
        printf("     이름       나이   키     몸무게\n");
        printf("=======================================\n");
        for (i = 0; i < count; i++) {
            //printf("%-14s, %3d, %6.2f, %6.2f\n", p->name, p->age, p->height, p->weight);
            //p++;  /* 다음 위치에 있는 친구 정보로 주소 이동 */
            printf("%-14s, %3d, %6.2f, %6.2f\n", p[i].name, p[i].age, p[i].height, p[i].weight);
        }
        printf("=======================================\n\n");
    }
    else {  /* 등록된 친구가 없으면 오류 상태 출력 */
        printf("\n등록된 친구가 없습니다.\n\n");
    }
}