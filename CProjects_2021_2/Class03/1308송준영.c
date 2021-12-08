#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NLEN    20 //�ִ� �̸� ����
#define MAX_SUBJECT 8 //���� ��
typedef struct {//�л� ����ü ����
    char name[MAX_NLEN + 1];//�̸�
    int num; //��ȣ
    int scores[MAX_SUBJECT];//����
}Student;


const char* stitles[MAX_SUBJECT] = { "����", "����", "����", "����", "ȭ��", "����", "����", "����" };//��������


Student** stues;
int max_student;

void Initialize();//�л� ������ �ʱ�ȭ
void Run();
void Exit();//�����ϱ� ���� �Ҵ��� �޸� ����
int main(void)
{
    int grade;
    int class;
    printf("********���ְ��а���б� ���� ó�� ���α׷��� �̿����ּż� �����մϴ�********\n");
    printf("�г� ���� �Է��� �ֽʽÿ�. ");
    scanf("%d %d", &grade, &class); //�г� �� �Է¹ޱ�
    printf("%d�г� %d�� �л� ���� �Է�\n", grade, class);
    Initialize();//�л� ������ �ʱ�ȭ
    Run();
    Exit();//�����ϱ� ���� �Ҵ��� �޸� ����
    return 0;
}


void Initialize()
{
    int i = 0;
    int s = 0;

    printf("�� �л� ���� �� ���ΰ���? ");
    scanf("%d", &max_student);
    stues = (Student**)malloc(sizeof(Student*) * max_student);//���� �迭 �޸� �Ҵ�
    memset(stues, 0, sizeof(Student*) * max_student);//�޸� �ʱ�ȭ
}

int SelectMenu();//�޴� ��� �� ����
void AddStudent();//�л� ������ �Է�
void RemoveStudent();//�л� ������ ����
void FindStudent();//�л� �˻�
void ListStudent();//��� ����
void Instruction();//��� ����
void Run()
{
    int key = 0;
    while ((key = SelectMenu()) != 0)//������ �޴��� 0�� �ƴϸ� �ݺ�
    {
        switch (key)//������ Ű�� ���� ��� ����
        {
        case 1: AddStudent(); break;
        case 2: RemoveStudent(); break;
        case 3: FindStudent(); break;
        case 4: ListStudent(); break;
        case 5: Instruction(); break;
        default: printf("�߸� �����Ͽ����ϴ�.\n"); break;
        }
    }
    printf("���α׷� ����\n");
}

int SelectMenu()
{
    int key = 0;
    printf("0. ����\n1. �л� ������ �Է�\n2. �л� ������ ����\n3. �л� �˻�\n4. ��� ����\n5. ��� ����\n");
    printf("*****************************\n");
    scanf("%d", &key);
    return key;
}

int IsAvailNum(int num);//��ȿ�� ��ȣ���� �Ǻ�
int IsAvailScore(int score);//��ȿ�� �������� �Ǻ�
void AddStudent()
{
    int num = 0;
    Student* stu = 0;
    int sum = 0;
    double avg;


    printf("�߰��� �л� ��ȣ(1~%d): ", max_student);
    scanf("%d", &num);

    if (IsAvailNum(num) == 0)//��ȿ�� ��ȣ�� �ƴ� ��
    {
        printf("������ ��� �л� ��ȣ�Դϴ�.\n");
        return;
    }

    if (stues[num - 1])//�л� �����Ͱ� �ִٸ�
    {
        printf("�̹� �߰��Ͽ����ϴ�\n");
        return;
    }


    stu = (Student*)malloc(sizeof(Student));//�л� ����ü ���� �޸� �Ҵ�
    stues[num - 1] = stu;//�Ҵ��� �޸� �ּҸ� �迭�� ����    
    stu->num = num;
    printf("�̸�: ");
    scanf("%s", stu->name, sizeof(stu->name));

    for (int s = 0; s < MAX_SUBJECT; s++)
    {
        printf("%s ����: ", stitles[s]);
        scanf("%d", stu->scores + s);
        if (IsAvailScore(stu->scores[s]) == 0)//��ȿ�� ������ �ƴ� ��
        {
            stu->scores[s] = -1;
            printf("�Է��� ������ ��ȿ���� �ʾƼ� %s ������ �Է� ó������ �ʾҽ��ϴ�.\n", stitles[s]);
        }
        sum += (stu->scores[s]);
    }
    avg = ((double)sum / MAX_SUBJECT);
    printf("���: %.3If\n", avg);//���

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

    printf("������ �л� ��ȣ(1~%d): ", max_student);
    scanf("%d", &num);

    if (IsAvailNum(num) == 0)//��ȿ�� ��ȣ�� �ƴ� ��
    {
        printf("������ ��� �л� ��ȣ�Դϴ�.\n");
        return;
    }

    if (stues[num - 1] == 0)//�л� �����Ͱ� ���� ��
    {
        printf("�����Ͱ� �����ϴ�.\n");
        return;
    }

    free(stues[num - 1]);//�޸� ����
    stues[num - 1] = 0;

    printf("�����Ͽ����ϴ�.\n");
}
void ViewStuData(Student* stu);
void FindStudent()
{
    int num = 0;

    printf("�˻��� �л� ��ȣ(1~%d): ", max_student);
    scanf("%d", &num);

    if (IsAvailNum(num) == 0)//��ȿ�� ��ȣ�� �ƴ� ��
    {
        printf("������ ��� �л� ��ȣ�Դϴ�.\n");
        return;
    }

    if (stues[num - 1] == 0)//�л� �����Ͱ� ���� ��
    {
        printf("�����Ͱ� �����ϴ�.\n");
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
    if (avg >= 0 && avg < 20) printf("******����� ������?******\n             ��\n");
    if (avg >= 20 && avg < 40) printf("******����� ������?******\n            ��\n");
    if (avg >= 40 && avg < 60) printf("******����� ������?******\n            ��\n");
    if (avg >= 60 && avg < 80) printf("******����� ������?******\n            ��\n");
    if (avg >= 80 && avg < 100) printf("******����� ������?******\n           ��\n");
}
void ListStudent(Student* stu) {

    printf("%4s %10s ", "��ȣ", "�̸�");
    for (int s = 0; s < MAX_SUBJECT; s++)
    {
        printf("%4s ", stitles[s]);
    }
    printf("  ���");
    printf("        ������ -1�� ���� ���Է�\n");
    for (int i = 0; i < max_student; i++)
    {
        if (stues[i])
        {
            ViewStuData(stues[i]);
        }
    }
}
void Instruction() {
    printf("���ְ��а���б� �л� ���� ���α׷��� ���� ���� ȯ���մϴ�!\n");
    printf("������ ������ ������� ó���Ǹ�, ������� ���� ��տ� ���� ��, ��, ��, ��, �� 5���� �������� ���������ϴ�.\n");
    printf("0~20��: ��\n");
    printf("20~40��: ��\n");
    printf("40~60��: ��\n");
    printf("60~80��: ��\n");
    printf("80~100��: ��\n");
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
