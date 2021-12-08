#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NLEN    20 //최대 이름 길이
#define MAX_SUBJECT 8 //과목 수
typedef struct {//학생 구조체 정의
    char name[MAX_NLEN + 1];//이름
    int num; //번호
    int scores[MAX_SUBJECT];//성적
}Student;


const char* stitles[MAX_SUBJECT] = { "국어", "영어", "수학", "물리", "화학", "생물", "지학", "정보" };//시험과목명


Student** stues;
int max_student;

void Initialize();//학생 데이터 초기화
void Run();
void Exit();//종료하기 전에 할당한 메모리 해제
int main(void)
{
    int grade;
    int class;
    printf("********광주과학고등학교 성적 처리 프로그램을 이용해주셔서 감사합니다********\n");
    printf("학년 반을 입력해 주십시오. ");
    scanf("%d %d", &grade, &class); //학년 반 입력받기
    printf("%d학년 %d반 학생 성적 입력\n", grade, class);
    Initialize();//학생 데이터 초기화
    Run();
    Exit();//종료하기 전에 할당한 메모리 해제
    return 0;
}


void Initialize()
{
    int i = 0;
    int s = 0;

    printf("반 학생 수는 몇 명인가요? ");
    scanf("%d", &max_student);
    stues = (Student**)malloc(sizeof(Student*) * max_student);//동적 배열 메모리 할당
    memset(stues, 0, sizeof(Student*) * max_student);//메모리 초기화
}

int SelectMenu();//메뉴 출력 및 선택
void AddStudent();//학생 데이터 입력
void RemoveStudent();//학생 데이터 삭제
void FindStudent();//학생 검색
void ListStudent();//목록 보기
void Instruction();//사용 설명서
void Run()
{
    int key = 0;
    while ((key = SelectMenu()) != 0)//선택한 메뉴가 0이 아니면 반복
    {
        switch (key)//선택한 키에 따라 기능 수행
        {
        case 1: AddStudent(); break;
        case 2: RemoveStudent(); break;
        case 3: FindStudent(); break;
        case 4: ListStudent(); break;
        case 5: Instruction(); break;
        default: printf("잘못 선택하였습니다.\n"); break;
        }
    }
    printf("프로그램 종료\n");
}

int SelectMenu()
{
    int key = 0;
    printf("0. 종료\n1. 학생 데이터 입력\n2. 학생 데이터 삭제\n3. 학생 검색\n4. 목록 보기\n5. 사용 설명서\n");
    printf("*****************************\n");
    scanf("%d", &key);
    return key;
}

int IsAvailNum(int num);//유효한 번호인지 판별
int IsAvailScore(int score);//유효한 성적인지 판별
void AddStudent()
{
    int num = 0;
    Student* stu = 0;
    int sum = 0;
    double avg;


    printf("추가할 학생 번호(1~%d): ", max_student);
    scanf("%d", &num);

    if (IsAvailNum(num) == 0)//유효한 번호가 아닐 때
    {
        printf("범위를 벗어난 학생 번호입니다.\n");
        return;
    }

    if (stues[num - 1])//학생 데이터가 있다면
    {
        printf("이미 추가하였습니다\n");
        return;
    }


    stu = (Student*)malloc(sizeof(Student));//학생 구조체 동적 메모리 할당
    stues[num - 1] = stu;//할당한 메모리 주소를 배열에 설정    
    stu->num = num;
    printf("이름: ");
    scanf("%s", stu->name, sizeof(stu->name));

    for (int s = 0; s < MAX_SUBJECT; s++)
    {
        printf("%s 성적: ", stitles[s]);
        scanf("%d", stu->scores + s);
        if (IsAvailScore(stu->scores[s]) == 0)//유효한 성적이 아닐 때
        {
            stu->scores[s] = -1;
            printf("입력한 성적이 유효하지 않아서 %s 성적은 입력 처리하지 않았습니다.\n", stitles[s]);
        }
        sum += (stu->scores[s]);
    }
    avg = ((double)sum / MAX_SUBJECT);
    printf("평균: %.3If\n", avg);//평균

}
int IsAvailNum(int num)
{
    return (num >= 1) && (num <= max_student);
}
int IsAvailScore(int score)
{
    return (score >= 0) && (score <= 100);
}

void RemoveStudent()
{
    int num = 0;

    printf("삭제할 학생 번호(1~%d): ", max_student);
    scanf("%d", &num);

    if (IsAvailNum(num) == 0)//유효한 번호가 아닐 때
    {
        printf("범위를 벗어난 학생 번호입니다.\n");
        return;
    }

    if (stues[num - 1] == 0)//학생 데이터가 없을 때
    {
        printf("데이터가 없습니다.\n");
        return;
    }

    free(stues[num - 1]);//메모리 해제
    stues[num - 1] = 0;

    printf("삭제하였습니다.\n");
}
void ViewStuData(Student* stu);
void FindStudent()
{
    int num = 0;

    printf("검색할 학생 번호(1~%d): ", max_student);
    scanf("%d", &num);

    if (IsAvailNum(num) == 0)//유효한 번호가 아닐 때
    {
        printf("범위를 벗어난 학생 번호입니다.\n");
        return;
    }

    if (stues[num - 1] == 0)//학생 데이터가 없을 때
    {
        printf("데이터가 없습니다.\n");
        return;
    }
    ViewStuData(stues[num - 1]);
}
void ViewStuData(Student* stu)
{
    int sum = 0;
    double avg;
    printf("%4d %10s ", stu->num, stu->name);
    for (int s = 0; s < MAX_SUBJECT; s++)
    {
        printf("%4d ", stu->scores[s]);
        sum += (stu->scores[s]);
    }
    avg = ((double)sum / MAX_SUBJECT);
    printf("  %.3If", avg);
    printf("\n\n");
    if (avg >= 0 && avg < 20) printf("******당신의 성적은?******\n             가\n");
    if (avg >= 20 && avg < 40) printf("******당신의 성적은?******\n            양\n");
    if (avg >= 40 && avg < 60) printf("******당신의 성적은?******\n            미\n");
    if (avg >= 60 && avg < 80) printf("******당신의 성적은?******\n            우\n");
    if (avg >= 80 && avg < 100) printf("******당신의 성적은?******\n           수\n");
}
void ListStudent(Student* stu) {

    printf("%4s %10s ", "번호", "이름");
    for (int s = 0; s < MAX_SUBJECT; s++)
    {
        printf("%4s ", stitles[s]);
    }
    printf("  평균");
    printf("        성적이 -1인 곳은 미입력\n");
    for (int i = 0; i < max_student; i++)
    {
        if (stues[i])
        {
            ViewStuData(stues[i]);
        }
    }
}
void Instruction() {
    printf("광주과학고등학교 학생 성적 프로그램에 오신 것을 환영합니다!\n");
    printf("성적은 절대평가 방식으로 처리되며, 과목들의 점수 평균에 따라 수, 우, 미, 양, 가 5개의 성적으로 나뉘어집니다.\n");
    printf("0~20점: 가\n");
    printf("20~40점: 양\n");
    printf("40~60점: 미\n");
    printf("60~80점: 우\n");
    printf("80~100점: 수\n");
}
void Exit()
{

    for (int i = 0; i < max_student; i++)
    {
        if (stues[i])
        {
            free(stues[i]);
        }
    }
    free(stues);
}
