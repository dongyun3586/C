#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
int main() {
    int comBall[4], userBall[4];
    //AI ���� ���� �迭, ����� ���� ���� �迭 ����
    int i, j, yes = 0;
    int menu = 0, count = 1;
    //menu: case�� �� �� �ʿ��� ����, count: ���° �õ����� ���� ����
    int strike = 0, ball = 0;
    //��Ʈ����ũ, ��
    int cowpoint = 0;
    //���ڸ� ��ȸ �ȿ� ���� Ƚ�� 
    int level;
    //���� ���� Ƚ�� ���� ����
    do {
        yes = 0;
        srand(time(NULL)); //����
    again:;
        for (i = 0; i < 4; i++) {
            comBall[i] = rand() % 9 + 1;
            //AI�� ���� ���� ����
        }
        if (comBall[0] == comBall[1] || comBall[0] == comBall[2] || comBall[0] == comBall[3] || comBall[1] == comBall[2] || comBall[1] == comBall[3] || comBall[2] == comBall[3]) {
            goto again;
            //�ڸ����� ���� ���� �ȵȴ�
        }
    start:;
        printf("****** ���ھ߱����� ******\n\n");
        printf("====== �޴� ======\n\n");
        printf("1. ���Ӽ���(3�ڸ���)\t2.���Ӽ���(4�ڸ���)\t3. ���ӽ���(3�ڸ���)\t4.���ӽ���(4�ڸ���)\t5. �׸��ϱ�\n\n");
        //1~5 �߿��� ����
        printf("��ȣ�� �����ϼ���\n");
        scanf("%d", &menu);
        switch (menu) {
        case 1:
            printf("****** ���� ******\n");
            printf("1. 1���� 9������ ���� �� 3���� ������.\n");
            printf("2. ���ڿ� ��ġ�� ���ÿ� ������ strike, ���ڸ� �°� ��ġ�� �ٸ��� ball�Դϴ�.\n");
            printf("3. ��ȸ�� �� 6���Դϴ�. ���� 6�� �ȿ� ���� �� 100���� ������ ���޵ǰ�, ������ ���� �� 50���� ������ ���޵˴ϴ�.\n");
            printf("4. �� ����Ʈ�� �׿��� ����ġ�� �ٲ�� �Ǵ�, ������ �������ּ���!\n");
            printf("�׷� ����� �����!\n\n");
            goto start;
            break;
        case 2: printf("****** ���� ******\n");
            printf("1. 1���� 9������ ���� �� 4���� ������.\n");
            printf("2. ���ڿ� ��ġ�� ���ÿ� ������ strike, ���ڸ� �°� ��ġ�� �ٸ��� ball�Դϴ�.\n");
            printf("3. ��ȸ�� �� 9���Դϴ�. ���� 9�� �ȿ� ���� �� 140���� ������ ���޵ǰ�, ������ ���� �� 70���� ������ ���޵˴ϴ�.\n");
            printf("4. �� ����Ʈ�� �׿��� ����ġ�� �ٲ�� �Ǵ�, ������ �������ּ���!\n");
            printf("�׷� ����� �����!\n\n");
            goto start;
            break;
        case 3:
            //3�ڸ� �� ���ھ߱� ���� ����
            while (strike != 3) {
                printf("%d��° �õ�\n", count);
                printf("���� 3���� �Է��ϼ���\n");
                scanf("%d %d %d", &userBall[0], &userBall[1], &userBall[2]);
                count++;
                if (userBall[0] < 1 || userBall[0] > 9 || userBall[1] < 1 || userBall[1] > 9 || userBall[2] < 1 || userBall[2] > 9)
                    //�ڸ����� 1~9�� �ڿ����� �Է°���
                {
                    printf("���� ���� ���ڸ� �Է��Ͻø� �ȵ˴ϴ�.\n");
                    count--;
                    continue;
                }
                else if (userBall[0] == userBall[1] || userBall[0] == userBall[2] || userBall[1] == userBall[2]) {
                    //�ڸ����� �ߺ��Ǹ� �ȵȴ�.
                    printf("�ߺ��� ���ڸ� �Է��Ͻø� �ȵ˴ϴ�.\n");
                    count--;
                    continue;
                }
                ball = 0;
                strike = 0;
                for (i = 0; i < 3; i++) {
                    for (j = 0; j < 3; j++) {
                        if (comBall[i] == userBall[j]) {
                            if (i == j) {
                                strike++;
                                //��ġ�� �ڸ����� ��� ��ġ�ϸ� ��Ʈ����ũ
                            }
                            else if (i != j) {
                                //�ڸ����� �°� ��ġ�� �ٸ��� ��
                                ball++;
                            }
                        }
                    }
                }
                if (strike != 3 && count == 7)
                    //6��° �õ����� ���ڸ� ������ ���ϸ� �й�
                {
                    printf("�ƽ��׿�~\n\n");
                    printf("������ %d%d%d�����ϴ�\n", comBall[0], comBall[1], comBall[2]);
                    cowpoint += 50;
                    printf("����: %d��\n\n", cowpoint);
                    level = cowpoint / 100;
                    printf("����� ���� �߱� ������ Lvl. %d�Դϴ�.\n\n", level);
                    if (1 <= level && level < 2) printf("�̱� A ����Դϴ�.\n");
                    if (2 <= level && level < 4) printf("���� A ����Դϴ�.\n");
                    if (4 <= level && level < 7) printf("Ʈ���� A ����Դϴ�.\n");
                    if (level >= 7) printf("�����մϴ�! ���� ��ŵ� ���ھ߱� �����������Դϴ�.\n");
                    break;
                }
                if (strike == 0 && ball == 0) {
                    printf("��ġ�ϴ� �ڸ����� �����ϴ�.\n"); //0�� 0��Ʈ����ũ�� ���
                }
                printf("%d�� %d��Ʈ����ũ�Դϴ�\n", ball, strike);
            }
            if (strike == 3) {
                printf("�� �Ͻó׿�~\n");
                printf("����� ����ñ���.\n\n");
                cowpoint += 100;
                printf("����: %d��\n\n", cowpoint);
                level = cowpoint / 100;
                printf("����� ���� �߱� ������ Lvl. %d�Դϴ�.\n\n", level);
                if (1 <= level && level < 2) printf("�̱� A ����Դϴ�.\n");
                if (2 <= level && level < 4) printf("���� A ����Դϴ�.\n");
                if (4 <= level && level < 7) printf("Ʈ���� A ����Դϴ�.\n");
                if (level >= 7) printf("�����մϴ�! ���� ��ŵ� ���ھ߱� �����������Դϴ�.\n");
            }
            printf("�ٽ� �Ͻðڽ��ϱ�?\n");
            printf("�ٽ� �Ͻ÷��� 1��, �׸��ν÷��� �ƹ� Ű�� �����ּ���\n");
            scanf("%d", &yes);
            ball = 0;
            strike = 0;
            count = 1;
            if (yes != 1) {
                break;
            }
        case 4:
            //4�ڸ��� ���ھ߱� ����
            while (strike != 4) {
                printf("%d��° �õ�\n", count);
                printf("���� 4���� �Է��ϼ���\n");
                scanf("%d %d %d %d", &userBall[0], &userBall[1], &userBall[2], &userBall[3]);
                count++;
                if (userBall[0] < 1 || userBall[0] > 9 || userBall[1] < 1 || userBall[1] > 9 || userBall[2] < 1 || userBall[2] > 9 || userBall[3] < 1 || userBall[3]>9) {
                    printf("���� ���� ���ڸ� �Է��Ͻø� �ȵ˴ϴ�.\n");
                    count--;
                    continue;
                }
                else if (userBall[0] == userBall[1] || userBall[0] == userBall[2] || userBall[0] == userBall[3] || userBall[1] == userBall[2] || userBall[1] == userBall[3] || userBall[2] == userBall[3]) {
                    printf("�ߺ��� ���ڸ� �Է��Ͻø� �ȵ˴ϴ�.\n");
                    count--;
                    continue;
                }
                ball = 0;
                strike = 0;
                for (i = 0; i < 4; i++) {
                    for (j = 0; j < 4; j++) {
                        if (comBall[i] == userBall[j]) {
                            if (i == j) {
                                strike++;
                            }
                            else if (i != j) {
                                ball++;
                            }
                        }
                    }
                }
                if (strike != 4 && count == 10) {
                    printf("�ƽ��׿�~\n\n");
                    printf("������ %d%d%d%d�����ϴ�\n", comBall[0], comBall[1], comBall[2], comBall[3]);
                    cowpoint += 70;
                    printf("����: %d��\n\n", cowpoint);
                    level = cowpoint / 100;
                    printf("����� ���� �߱� ������ Lvl. %d�Դϴ�.\n\n", level);
                    if (1 <= level && level < 2) printf("�̱� A ����Դϴ�.\n");
                    if (2 <= level && level < 4) printf("���� A ����Դϴ�.\n");
                    if (4 <= level && level < 7) printf("Ʈ���� A ����Դϴ�.\n");
                    if (level >= 7) printf("�����մϴ�! ���� ��ŵ� ���ھ߱� �����������Դϴ�.\n");
                    break;
                }
                if (strike == 0 && ball == 0) {
                    printf("no match\n");
                }
                printf("%d�� %d��Ʈ����ũ�Դϴ�\n", ball, strike);
            }
            if (strike == 4) {
                printf("�� �Ͻó׿�~\n");
                printf("����� ����ñ���.\n\n");
                cowpoint += 100;
                printf("����: %d��\n\n", cowpoint);
                level = cowpoint / 100;
                printf("����� ���� �߱� ������ Lvl. %d�Դϴ�.\n\n", level);
                if (1 <= level && level < 2) printf("�̱� A ����Դϴ�.\n");
                if (2 <= level && level < 4) printf("���� A ����Դϴ�.\n");
                if (4 <= level && level < 7) printf("Ʈ���� A ����Դϴ�.\n");
                if (level >= 7) printf("�����մϴ�! ���� ��ŵ� ���ھ߱� �����������Դϴ�.\n");
            }
            printf("�ٽ� �Ͻðڽ��ϱ�?\n");
            printf("�ٽ� �Ͻ÷��� 1��, �׸��ν÷��� �ƹ� Ű�� �����ּ���\n");
            scanf("%d", &yes);
            ball = 0;
            strike = 0;
            count = 1;
            if (yes != 1) {
                //1���� ������ ������ ���� ���� 
                break;
            }
        case 5:
            //������ �ٷ� ���� �� ����
            printf("������ �����մϴ�.\n");
            break;
        default:
            //�̻��� Ű�� ������ ���
            printf("�߸� �Է��ϼ̽��ϴ�. ���α׷��� ����˴ϴ�.\n");
            break;
        }
    } while (yes == 1);
}

































































