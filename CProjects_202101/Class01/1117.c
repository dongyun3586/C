#include <stdio.h>
#include <string.h>

char s[15];//�����1���� �Է¹޴� �ܾ�
char s2[15];//�����2���� �Է¹޴� �ܾ�
char name1[30];
char name2[30];
char sword[15];//�����2�� �Է��� �� ���̴� ��ĭ
char sword2[15];//�����1�� �Է��� �� ���̴� ��ĭ
int i = 0;
int length;//�����1 �ܾ��� ����
int length2;//�����2 �ܾ��� ����
char user;//�����1�� ���߰��� �ϴ� ����
char user2;//�����2�� ���߰��� �ϴ� ����
int scnt = 0;//�����1�� �õ�Ƚ���� ��Ÿ���� ����
int scnt2 = 0;//�����2�� �õ�Ƚ���� ��Ÿ���� ����

int main() {

    printf("    <<��� �����Դϴ�.>>\n");
    printf("����� 1�� �̸��� �Է��Ͻÿ� : ");
    scanf("%s", name1);

    printf("\n����� 2�� �̸��� �Է��Ͻÿ� : ");
    scanf("%s", name2);

    printf("\n����� 1�� ������ �Է��ϼ��� : ");
    printf("\n ������ 15���� ���Ͽ��� �մϴ�.");
    scanf("%s", s);//���ڿ� s�� �Է¹޴´�.

    length = strlen(s);//�Էµ� ���� ���� ����.

    for (i = 0; i < length; i++)
        sword[i] = '_';

    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n�����1�� ������ �½��ϴ�.\n");

    while (1) {
        printf("\n���ڸ� �Է��ϼ���. ");
        scanf("%c", &user);

        for (i = 0; i < length; i++) {

            if (s[i] == user) {
                sword[i] = user;
            }
        }
        scnt++;
        printf("%s\n", sword);

        if (strcmp(s, sword) == 0) {//�� ���ڿ�(����� 1�� �Է��� ���ڿ��� �����2�� �Է��� ���ڿ�)�� ������ ���߱�
            break;
        }
    }

    printf("%d�� ���� ������ϴ�.", scnt / 2);


    printf("\n\n\n ù��° ������ �������ϴ�.");
    printf("\n �����2�� ������ �Է��ϼ���.");
    printf("\n ������ 15���� ���Ͽ��� �մϴ�.");

    scanf("%s", s2);


    length2 = strlen(s2);//�Էµ� ���� ���� ����.

    for (i = 0; i < length2; i++)
        sword2[i] = '_';

    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n�����2�� ������ �½��ϴ�.\n");

    while (1) {
        printf("\n���ڸ� �Է��ϼ���. ");
        scanf("%c", &user2);

        for (i = 0; i < length2; i++) {

            if (s2[i] == user2) {
                sword2[i] = user2;
            }
        }
        scnt2++;
        printf("%s\n", sword2);

        if (strcmp(s2, sword2) == 0) {//�� ���ڿ�(����� 1�� �Է��� ���ڿ��� �����2�� �Է��� ���ڿ�)�� ������ ���߱�
            break;
        }
    }

    printf("%d�� ���� ������ϴ�.", scnt2 / 2);

    if (scnt == scnt2) {
        printf("\n\n���ϵ帳�ϴ�. ���º��Դϴ�.");
    }
    if (scnt < scnt2) {
        printf("\n\n���ϵ帳�ϴ�. %s�� �¸��Դϴ�.", name2);
    }
    if (scnt > scnt2) {
        printf("\n\n���ϵ帳�ϴ�. %s�� �¸��Դϴ�.", name1);
    }
}