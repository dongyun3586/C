#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

int checkEqualStr(char* s1, char* s2)//�� ����װ� ���� ������� �����ϱ� ���� ���ڿ� �˻� �Լ�
{
    while (*s1 != '\0' || *s2 != '\0') {
        if (*s1 == *s2) {
            s1++;
            s2++;
        }
        else {
            return -1;
        }
    }
    return 0;
}

int main() {
    int selec;
SEL:
    printf("��带 ���ÿ� 1 : ���� ���ϱ� 2 : �����ϱ� 3 : �����ϱ�\n");
    scanf("%d", &selec);//��带 �����ϱ� ���� ����
    if (selec == 1) {
        char Acid[5][10] = { "HCl","CH3COOH","H3PO4","H2SO4","H2CO3" };//��� ������ �� ����� 5����
        char Base[5][10] = { "NaOH", "MgOH2", "KOH", "NH3", "CaOH2" };//��� ������ ���� ����� 5����
        char Aqours1[10];
        char Aqours2[10];
        int parameter;//��� �� ���ڿ��� �ظ��Ǵ� ���� �� ����
        float M1;//������ ������� ��
        float V1;//������ ������� ����
        float M2;
        float V2;
        int Base_i[5] = { 1,2,1,1,2 };//���� ����׿��� �ظ��Ǵ� ���� ��
        printf("�ʿ��� ����� ���Ǹ� ���ϴ� ����Դϴ�\n\n");
        printf("������ ����� ������ �Է��Ͻÿ� :\n");
        scanf("%s", Aqours1);
        printf("����� ����� ������ �Է��Ͻÿ� :\n");
        scanf("%s", Aqours2);
        printf("������ ����� �󵵿� ���Ǹ� �Է��Ͻÿ� :");
        scanf("%f%f", &M1, &V1);
        printf("����� ����� �󵵸� �Է��Ͻÿ� :");
        scanf("%f", &M2);
        for (int i = 0; i < 5; i++) {
            if (checkEqualStr(Aqours1, Base[i]) == 0) {//���� ��������� Ȯ��
                printf("\n\n���1�� ���⼺�Դϴ�\n\n");
                parameter = i;
                V2 = Base_i[parameter] * V1 * M1 / M2;//�־�� �ϴ� ����� ���� ����
                printf("�ʿ��� ���Ǵ� %.1fmL�Դϴ�\n", V2);
                goto SEL;//�ٽ� ��带 ������ �� �ֵ��� goto���� ���
            }
            else {
                printf("\n\n���1�� �꼺�Դϴ�\n\n");
                for (int k = 0; k < 5;) {
                    if (checkEqualStr(Aqours2, Base[k]) == 0) {//����ϴ� ���� ������� � ������ ����
                        parameter = k;
                        V2 = (V1 * M1) / (Base_i[parameter] * M2);//�־�� �ϴ� ����� ��
                        printf("�ʿ��� ���Ǵ� %.1fmL�Դϴ�\n", V2);
                        break;
                    }
                }
                goto SEL;
            }
        }

    }
    else if (selec == 2) {
        printf("���� ������ �ϴ� ����Դϴ�\n");
        srand(time(NULL));
        int V1, M1, M2 = 0;
        float V2;
        V1 = rand() % 300 + 1;
        M1 = rand() % 5 + 1;
        printf("������ ����� ����� ������ �Է��Ͻÿ� :\n");
        char Acid[5][10] = { "HCl","CH3COOH","H3PO4","H2SO4","H2CO3" };
        char Base[5][10] = { "NaOH", "MgOH2", "KOH", "NH3", "CaOH2" };
        char Aqours1[10];
        char Aqours2[10];
        int parameter;
        M2 = 1;
        int Base_i[5] = { 1,2,1,1,2 };
        scanf("%s", Aqours1);
        for (int i = 0; i < 5; i++) {
            for (int k = 0; k < 5; k++) {
                if (checkEqualStr(Aqours1, Base[k]) == 0) {

                    parameter = k;
                    V2 = (Base_i[parameter] * V1 * M1) / M2;
                    float myV = 0;

                    while (1) {//������ ������ while ���� Ż���ϵ��� ��
                        printf("���� ���Ǹ� �Է��Ͻÿ� :\n");
                        float plus;//�߰��� �־��ִ� ����� ���� ��� ����
                        scanf("%f", &plus);
                        if (myV + plus < V2) {
                            printf("\n\n�ƹ��� ��ȭ�� �����ϴ�. ����� �߰��ϼ���\n");
                            myV += plus;//���ݱ��� �߰��� ����� ���� ����
                            continue;
                        }
                        else if (myV + plus == V2) {
                            printf("\n������ �Ϸ��߽��ϴ�\n");
                            goto SEL;
                        }
                        else {
                            printf("\n�緮���� �������ϴ�.\n");
                            printf("�緮���� %fmL�����ϴ�\n", V2);
                            goto SEL;
                        }
                    }
                }
                else {

                    V2 = (V1 * M1) / M2;
                    float myV = 0;

                    while (1) {
                        printf("���� ���Ǹ� �Է��Ͻÿ� :\n");
                        float plus;
                        scanf("%f", &plus);
                        if (myV + plus < V2) {
                            printf("\n\n�ƹ��� ��ȭ�� �����ϴ�. ����� �߰��ϼ���\n");
                            myV += plus;
                            continue;
                        }
                        else if (myV + plus == V2) {
                            printf("\n������ �Ϸ��߽��ϴ�\n");
                            goto SEL;
                        }
                        else {
                            printf("\n�緮���� �������ϴ�.\n");
                            printf("�緮���� %fmL�����ϴ�\n", V2);
                            goto SEL;
                        }
                    }
                }
            }
        }
    }
    else { printf("����Ǿ����ϴ�\n"); return 0; }
}