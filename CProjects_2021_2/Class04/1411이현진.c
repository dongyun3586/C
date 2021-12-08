#include <Windows.h>
#include <stdio.h>
#define MAX_COUNT 5   /* 친구 등록 가능한 최대 수 */
#include<math.h> //반올림하는 함수인 floor함수를 사용하기 위해 이 헤더파일을 사용하게 되었다.

// 1. 구조체 정의
typedef struct {
    char name[50];
    char subject[50];
    int point;
    float score;
    float average;
    float student; //총 학생수
    float pyo; //표준편차
    int grade; //석차
}Person;

float z;
void Zscore(Person* p)
{
    z = (float)(((p->score) - (p->average)) / (p->pyo)); //z점수의 정의 (원점수-평균)/표준편차
    printf("당신의 z점수는 %.4f이며, ", z);
}

enum menu { INSERT = 1, SHOW, EXIT } choice;

int AddFriend(Person* p, int count);
void ShowFriendList(Person* p, int count);

int main()
{
    // 2. 구조체 배열 선언
    Person friends[MAX_COUNT];
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
    int number;
    if (count < MAX_COUNT) {
        // 3. 친구 정보 입력받기
        printf("\n새로운 친구 정보를 입력하세요\n");
        printf("1. 이름 : ");
        scanf("%s", p[count].name);

        printf("%d. 과목명 학점 : ", count + 1);
        scanf("%s %d", (p[count].subject), &(p[count].point));
        printf("%d. 원점수 과목평균 표준편차 학생수", count + 1);
        scanf(" %f %f %f %f", &(p[count].score), &(p[count].average), &(p[count].pyo), &(p[count].student));
        Zscore(p);

        float temp = floor(z * 100) / 100;   //z함수를 소수 첫째 자리 까지 반올림 한것 

        //printf("<<%f>>\n", temp);


        float arr100[61] = { 0.0013, 0.0019, 0.0026, 0.0035, 0.0047, 0.0062, 0.0082, 0.0107, 0.0139, 0.0179, 0.0228, 0.0287, 0.0359, 0.0446, 0.0548, 0.0668, 0.0808, 0.0968, 0.1151, 0.1357, 0.1587, 0.1841, 0.2119, 0.2420, 0.2743, 0.3085, 0.3446, 0.3821, 0.4207, 0.4602, 0.5, 0.5398, 0.5793, 0.6179, 0.6554, 0.6915, 0.7257, 0.7580, 0.7881, 0.8159, 0.8413, 0.8643, 0.8849, 0.9032, 0.9192, 0.9332, 0.9452, 0.9554, 0.9641, 0.9713, 0.9772, 0.9821, 0.9861, 0.9893, 0.9918, 0.9938, 0.9953, 0.9965, 0.9974, 0.9981, 0.9987 };

        int temppp = 10 * (3 - temp);     //Z점수는 3.0부터 0.1씩 감소하기에 배열을 사용하지 않아서 Z점수가 배열이 있다고 가정하고 그 위치를 arr100 배열의 위치를 대입하여 석차 백분율을 구해햐 한다. 그래서 위치를 나타내는 임의의 변수 temppp를 사용하였다. 
        //printf("<<%d>>", temppp);
        printf("총 %0.0f명 중 %d등입니다.", p[count].student, (int)(arr100[temppp] * 100));

        int grade = (int)(arr100[temppp] * 100);
        p[count].grade = grade; //학점의 등급을 대략적으로 알기 위해서 A-와 B+ 등급을 각각 20%씩 정했고 다른 등급은 15%씩 정하였습니다. 
        if (0 <= grade && grade <= 15)
            printf("\n학점은 A+입니다.\n");
        else if (15 <= grade && grade < 30)
            printf("\n학점은 A0입니다.\n");
        else if (30 <= grade && grade < 50)
            printf("\n학점은 A-입니다.\n");
        else if (50 <= grade && grade < 70)
            printf("\n학점은 B+입니다.\n");
        else if (70 <= grade && grade < 85)
            printf("\n학점은 B0입니다.\n");
        else if (85 <= grade && grade < 100)
            printf("\n학점은 B-입니다.\n");


        printf("\n입력을 완료했습니다. \n\n");
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
        printf("     이름       과목명   등수\n");
        printf("===========================\n");
        for (i = 0; i < count; i++) {
            // 4. 친구 정보 출력
            printf("      %s,    %s,    %d\n", &p[i].name, &p[i].subject, p[i].grade);
        }
        printf("=======================================\n\n");
    }
    else {  /* 등록된 친구가 없으면 오류 상태 출력 */
        printf("\n등록된 친구가 없습니다.\n\n");
    }

}
