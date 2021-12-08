#include <stdio.h>
#include <math.h>
#define MAX_NAME_LEN    20
#define MAX_ACC_LEN 10
struct _BankAcc {                      //�� ���� ���� ����ü
    char name[MAX_NAME_LEN];          //�� �̸�
    char account[MAX_ACC_LEN];        //�� �����ȣ 
    int balance;                      //�� ���ݾ�
    float total;                        //�� ���ݾ� + ����
};
typedef struct _BankAcc BankAcc;
BankAcc baccs[3];                     //�� ���� ���� ���� ���� �迭   

void input_accs();                    //�� ���� �Է�
void run();                           //������ 1,2,3,4�� ���� ���
float interest(BankAcc* d1);            //���� ��� �Լ�
int year = 0;               //������ ��¥�κ��� �� ���� �������� ����

int main()
{
    input_accs();
    run();
    return 0;
}
void input_accs() //�� ���� �Է�
{
    int i = 0;
    for (i = 0; i < 3; i++) //�� 3�� ���� ���� �Է�
    {
        printf("�����%d�� �̸�:", i + 1);
        scanf("%s", baccs[i].name, MAX_NAME_LEN);
        printf("�����%d�� ����:", i + 1);
        scanf("%s", baccs[i].account, MAX_ACC_LEN);
        printf("�����%d�� ���ݾ�:", i + 1);
        scanf("%d", &baccs[i].balance);
    }
}

int select_menu();        //1,2,3 �� ����
void show_balance();      //�� ���� ����
void save();              //���� �ݾ� ����
void draw();              //���� �ݾ� ����
void run()                //������ 1,2,3,4�� ���� ���
{
    int key;          //������ 1,2,3,4�� ������ ��������
    while (1)
    {
        key = select_menu();
        if (key == 4)
            break;
        switch (key) {
        case 1: show_balance(); break;
        case 2: save(); break;
        case 3: draw(); break;
        default:
            printf("�߸��� ���ڸ� �Է��Ͽ����ϴ�.\n");
            break;
        }
    }
}
int select_menu()          //1,2,3,4 �� ����
{
    int key = 0;
    printf("�޴��� �����ϼ���. <�ܾ���ȸ(1), ����(2), ����(3), ����(4)>:");
    scanf("%d", &key);
    return key;
}
void show_balance()     //�ݾ� �����ֱ�
{
    printf("�� ���� ��������?");    //���� ���̵��� �⵵ ����
    scanf("%d", &year);
    int num = 0;
    printf("����� ��ȣ�� �����ϼ���.(1~3):");
    scanf("%d", &num);
    if ((num < 1) || (num > 3))
    {
        printf("�߸� �����Ͽ����ϴ�.\n");
        return;
    }
    printf("%s���� ���¹�ȣ: %s�Դϴ�.\n", baccs[num - 1].name, baccs[num - 1].account);
    printf("%s���� ���ݾ�:%d �Դϴ�.\n", baccs[num - 1].name, baccs[num - 1].balance);
    interest(&baccs[num - 1]);
    printf("%s���� �ѱݾ�:%f �Դϴ�.\n", baccs[num - 1].name, baccs[num - 1].total);
}
void save() //����ݾ� ����
{
    int num = 0;
    int value = 0;
    printf("����� ��ȣ�� �����ϼ���.(1~3):");
    scanf("%d", &num);
    if ((num < 1) || (num > 3))
    {
        printf("�߸� �����Ͽ����ϴ�.\n");
        return;
    }
    printf("%s���� ���� �ݾ� �Է�:", baccs[num - 1].name);
    scanf("%d", &value);
    baccs[num - 1].balance += value;
}
void draw()         //����ݾ� ����
{
    int num = 0;
    int value = 0;         //����� �ݾ�
    printf("����� ��ȣ�� �����ϼ���.(1~3):");
    scanf("%d", &num);
    interest(&baccs[num - 1]);
    if ((num < 1) || (num > 3))
    {
        printf("�߸� �����Ͽ����ϴ�.\n");
        return;
    }
    printf("%s���� ���� �ݾ� �Է�:", baccs[num - 1].name);
    scanf("%d", &value);

    if (value > baccs[num - 1].total)
    {
        printf("�ܾ��� �����մϴ�.\n");
    }
    else
    {
        baccs[num - 1].balance -= value;
    }
    printf("%s���� �ܾ�:%d �Դϴ�.\n", baccs[num - 1].name, baccs[num - 1].balance);
}

float interest(BankAcc* d1) //���� ��� �Լ�
{
    d1->total = pow(1.01, year) * (d1->balance);
    return  (d1->total);
}