#include<stdio.h>

enum Weather { SUNNY, CLOUD, RAIN, SNOW };

int main(void)
{
    int input;
    enum Weather wt;

    printf("������ ������ �Է��� �ּ���(SUNNY=0, CLOUD=1, RAIN=2, SNOW=3) : ");
    scanf("%d", &input);

    wt = input;

    switch (wt) {
    case SUNNY:
        printf("������ ������ ���� ���ƿ�!\n");
        break;
    case CLOUD:
        printf("������ ������ �帮�׿�!\n");
        break;
    case RAIN:
        printf("������ ������ �� �ַ��ַ� ���׿�!\n");
        break;
    case SNOW:
        printf("������ ������ �Ͼ� ���� ������!\n");
        break;
    default:
        printf("��Ȯ�� ������� �Է��� �ּ���!\n");
        break;
    }

    printf("����ü Weather�� �� ������� %d, %d, %d, %d �Դϴ�.\n", SUNNY, CLOUD, RAIN, SNOW);

    return 0;
}