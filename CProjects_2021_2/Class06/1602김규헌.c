#include<stdio.h>
#include<stdlib.h>//���� �����ϱ� ����
#include<time.h>//���� �����ϱ� ����
#include<windows.h>//system("cls"), �� ȭ�� ����� �Լ��� ����ϱ� ����
typedef struct { //����ü ��� Arr:�ڸ���ġ�� ��� Ű random: �ڸ���ġ, name:�ڸ���ġ �� ��� �̸�
    int Arr;
    int random;
    char name[40];

}Project;
void swap(int* a, int* b) {//swap�Լ� pointer ���
    int tempp;
    tempp = *a;
    *a = *b;
    *b = tempp;
}
int main() {
    Project b[100];
    int width, length; //���� ����
    int number;//�� �� 
    int temp, Data = 0;
    srand(time(NULL));//�ڸ� ��ġ ����
    printf("�����������������������������������������������\n");
    printf("��                                                                                        ��\n");
    printf("��                                                                                        ��\n");
    printf("��                                                                                        ��\n");
    printf("��                                                                                        ��\n");
    printf("��                                                                                        ��\n");
    printf("��                              Ű�� ����� �ڸ���ġ ���α׷�                             ��\n");
    printf("��                                                                                        ��\n");
    printf("��                                      ��Ģ                                              ��\n");
    printf("��                                                                                        ��\n");
    printf("��                          1. �ڸ� ��ġ�� �ο��� �Է��Ѵ�.                               ��\n");
    printf("��                          2. ���ο� ���ο� ��ġ�� �ο��� �Է��Ѵ�.                      ��\n");
    printf("��                          3. �ڸ� ��ġ�� ����� �̸��� Ű�� �Է��Ѵ�.                   ��\n");
    printf("��                                                                                        ��\n");
    printf("��                                                                                        ��\n");
    printf("��                                                                                        ��\n");
    printf("��                                                                                        ��\n");
    printf("��                                                                                        ��\n");
    printf("��                                                                                        ��\n");
    printf("��                                                                                        ��\n");
    printf("��                                                                                        ��\n");
    printf("��                                                                                        ��\n");
    printf("��                                                                                        ��\n");
    printf("�����������������������������������������������\n");
    Sleep(2000);//2�ʵ��� ����
    system("cls");//ȭ�� ���ֱ� 
    printf("�� ���� ��ġ�� ���ΰ���?\n");
    scanf("%d", &number);
    printf("���ο� ���� �� �� ��ġ�� ���ΰ���?\n");
    scanf("%d %d", &width, &length);
    printf("����̸��� Ű�� �Է����ּ���.\n");
    printf(" �̸�   Ű\n");
    for (int i = 0; i < number; i++) {
        scanf("%s", &b[i].name);//�̸� �Է�
        scanf("%d", &b[i].Arr);//Ű �Է�
    }
    system("cls");
    //�ߺ����� �ڸ���ġ�� ����ϴ� �ڵ�, �ڸ��� 0~�ο���-1���� �� �ο��� ��ŭ �ִ�. 
    for (int i = 0; i < number; i++) {         //�ϳ��� ��
        b[i].random = rand() % number;
        for (int j = 0; j < i; j++) {            //���� ���� ��ȿȭ
            if (b[j].random == b[i].random) {
                i--;
                break;
            }
        }
    }
    //�ڸ� �� random�� ����ִ� ���� Ŭ���� �ڿ� ��ġ�Ѵ�. ������ �ջ���� �ڽź��� Ŭ �� �ڸ��� �ٲ��ִ� �ڵ��̴�. 
    for (int i = 0; i < number; i++) {
        for (int j = 1; j < number; j++) {
            if (b[i].random % width == b[j].random % width) {
                if (b[i].Arr > b[j].Arr && b[i].random < b[j].random) {
                    swap(&b[i].random, &b[j].random);
                }
                if (b[i].Arr < b[j].Arr && b[i].random > b[j].random) {
                    swap(&b[i].random, &b[j].random);
                }
            }
        }
    }
    //�Ʊ� �ڵ带 �� �� �� ���ش�. �ֳ��ϸ� 1�����δ� ������ ����� ���� �ʱ� �����̴�. 
    for (int i = 0; i < number; i++) {
        for (int j = 1; j < number; j++) {
            if (b[i].random % width == b[j].random % width) {
                if (b[i].Arr > b[j].Arr && b[i].random < b[j].random) {
                    swap(&b[i].random, &b[j].random);
                }
                if (b[i].Arr < b[j].Arr && b[i].random > b[j].random) {
                    swap(&b[i].random, &b[j].random);
                }
            }
        }
    }
    //�ڸ��� �� random �ȿ� �ִ� ���� 0�� �ͺ��� ����� �Ͽ� �ڸ��� ���ʴ�� ����Ѵ�. 
    while (Data != number) {
        for (int i = 0; i < number; i++) {
            for (int j = 0; j < number; j++) {
                if (b[j].random == i) {
                    printf("%s ", b[j].name);
                    printf("(%d) ", b[j].Arr);
                    Data++;
                    if (Data % width == 0) {
                        printf("\n\n");
                    }
                }
            }
        }
    }

    return 0;
}