#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void Support(int a);//�÷��̾� �ൿ �Է¹޴� �Լ�, ���� ��ų �� ����



int LP = 0;//����ġ �ʱ� ��, ���͸� �����鼭 ����ġ ȹ��
int HealthPoint = 10;//�÷��̾� �ʱ� ü��, �� ������ ���� ������ �ø� �� ����
int PlayerAction;//�÷��̾� �ൿ �Է¹޴� ����
int ManaPoint = 20;//�÷��̾� �ʱ� ����, ��ų ��뿡 �߿���
int NormalAttack = 2;//�÷��̾� �⺻ ���ݷ�
int MopHP;//������ ü��, �Ϲ� ���� ������ ü���� �ٸ�
int Level = LP / 9;//����=����ġ/9

int main() {
    srand(time(NULL));

    printf("Welcome Player\n");


    Support(1);//�÷��̾� ��ų ����
    HealthPoint = 10 + Level;//������ ���� ������ ü�� 1�� ����//���α׷� ���� Ȯ�� �� ���� 
    while (Level < 10) {
    FAIL:
        int Encounter = rand() % 6;//������ ��Ȳ ����
        if (Encounter == 0) {//�ذ�� ����, ����
            //Fight With Skeleton, Give 9LP if win
            printf("Encountered Skeleton Choose Your Action\n\n");
            MopHP = 20;
            while (MopHP > 0) {
                int Action = rand() % 10;  //������ ���������� �ൿ ����->while�� �� �� ���� ���� 
                printf("Press 2:Normal Attack 3:Skill 1 4:Skill 2 5:Skill 3 ");
                scanf("%d", &PlayerAction);
                if (Action == 0 && PlayerAction != 5) {//�ذ��� �������� ���� ���� ����(���� �ʿ�)->���� ���� �� ���� �������� ū ���� 
                    printf("Enemy Runned\n\n");
                    goto FAIL;
                }
                else if (Action == 0 && PlayerAction == 5) {//�ذ� ���� ���� ����
                    Support(PlayerAction);
                    printf("My HP : %d My MP : %d Enemy HP : %d\n\n", HealthPoint, ManaPoint, MopHP);
                }
                else if ((Action == 1 || Action == 2) && (PlayerAction == 2 || PlayerAction == 4)) {//�ذ��� �÷��̾� ���� ��� ����
                    printf("Enemy Guarded\n\n");
                    printf("My HP : %d My MP : %d Enemy HP : %d\n\n", HealthPoint, ManaPoint, MopHP);
                }

                else if ((Action == 1 && Action == 2) && (PlayerAction != 2 && PlayerAction != 4)) {//�ذ��� �÷��̾� ���� ��� �õ������� �÷��̾ �������� ���� 
                    Support(PlayerAction);
                    printf("My HP : %d My MP : %d Enemy HP : %d\n\n", HealthPoint, ManaPoint, MopHP);

                }
                else if (Action > 2) {//�÷��̾�� �ذ��� ����,��ų �ְ� ����
                    Support(PlayerAction);
                    HealthPoint -= 1;
                    printf("My HP : %d My MP : %d Enemy HP : %d\n\n", HealthPoint, ManaPoint, MopHP);
                }
                if (HealthPoint == 0) {//�÷��̾ ü���� ������ ����
                    goto EXIT;
                }

            }
            printf("VICTORY\n");//���� �¸�
            Level += 1; HealthPoint += 1;//����, ü�� ���
        }
        else if (Encounter == 1) {//����� ����, �ذ�� ��Ŀ���� ����
            //Fight With Zombie, Give 9LP if win
            printf("Encountered Zombie Choose Your Action\n\n");
            MopHP = 20;
            while (MopHP > 0) {
                int Action = rand() % 10;
                printf("Press 2:Normal Attack 3:Skill 1 4:Skill 2 5:Skill 3 ");
                scanf("%d", &PlayerAction);
                if (Action == 0 && PlayerAction != 5) {
                    printf("Enemy Runned\n\n");
                    goto FAIL;
                }
                else if (Action == 0 && PlayerAction == 5) {
                    Support(PlayerAction);
                    printf("My HP : %d My MP : %d Enemy HP : %d", HealthPoint, ManaPoint, MopHP);
                }
                else if ((Action == 1 || Action == 2) && (PlayerAction == 2 || PlayerAction == 4)) {
                    printf("Enemy Guarded\n\n");
                    printf("My HP : %d My MP : %d Enemy HP : %d\n\n", HealthPoint, ManaPoint, MopHP);
                }
                else if ((Action == 1 || Action == 2) && (PlayerAction != 2 && PlayerAction != 4)) {
                    Support(PlayerAction);
                    printf("My HP : %d My MP : %d Enemy HP : %d\n\n", HealthPoint, ManaPoint, MopHP);
                }
                else if (Action > 2) {
                    Support(PlayerAction);
                    HealthPoint -= 1;
                    printf("My HP : %d My MP : %d Enemy HP : %d\n\n", HealthPoint, ManaPoint, MopHP);
                }
                if (HealthPoint == 0) {
                    goto EXIT;
                }

            }
            printf("VICTORY\n");
            Level += 1; HealthPoint += 1;
        }
        else if (Encounter == 2) {//�Ź̿� ����, ��Ŀ���� ����
            //Fight With Spider, Give 9LP if win
            printf("Encountered Spider Choose your Action\n");
            MopHP = 20;
            while (MopHP > 0) {
                int Action = rand() % 10;
                printf("Press 2:Normal Attack 3:Skill 1 4:Skill 2 5:Skill 3 ");
                scanf("%d", &PlayerAction);
                if (Action == 0 && PlayerAction != 5) {
                    printf("Enemy Runned\n\n");
                    goto FAIL;
                }
                else if (Action == 0 && PlayerAction == 5) {
                    Support(PlayerAction);
                    printf("My HP : %d My MP : %d Enemy HP : %d\n\n", HealthPoint, ManaPoint, MopHP);
                }
                else if ((Action == 1 || Action == 2) && (PlayerAction == 2 || PlayerAction == 4)) {
                    printf("Enemy Guarded\n\n");
                    printf("My HP : %d My MP : %d Enemy HP : %d\n\n", HealthPoint, ManaPoint, MopHP);
                }
                else if ((Action == 1 || Action == 2) && (PlayerAction != 2 && PlayerAction != 4)) {
                    Support(PlayerAction);
                    printf("My HP : %d My MP : %d Enemy HP : %d\n\n", HealthPoint, ManaPoint, MopHP);
                }
                else if (Action > 2) {
                    Support(PlayerAction);
                    HealthPoint -= 1;
                    printf("My HP : %d My MP : %d Enemy HP : %d\n\n", HealthPoint, ManaPoint, MopHP);
                }
                if (HealthPoint == 0) {
                    goto EXIT;
                }

            }
            printf("VICTORY\n");
            Level += 1; HealthPoint += 1;
        }
        else if (Encounter == 3) {
            printf("Picked Mana Potion! MP+3\n\n");//�������� ȹ��, ���� ����
            ManaPoint += 1;
        }
        else if (Encounter == 4) {
            printf("Picked Health Potion! HP+3\n\n");//ü�� ���� ȹ��, ü�� ����
            HealthPoint += 1;
        }
        else if (Encounter == 5) {//��������Ʈ, ��ġ�� �ʰ� �Ź� 10���� �������� ��ƾ� �� ������ 10���� �ѹ��� �޼� 
            int SubQ;
            printf("Encountered the SubQuest! Want to Permit? 1-Y 2-N :");
            scanf("%d", &SubQ);
            if (SubQ == 2) { goto FAIL; }
            else {
                printf("Permitted SubQuest\n\n");
                printf("Spiders inavaded the village. To save it, kill 10 spiders without missing\n\n");
                for (int i = 0; i < 10; i++) {
                    printf("Encountered Spider Choose your Action\n\n");
                    MopHP = 20;
                    while (MopHP > 0) {
                        int Action = rand() % 10;
                        printf("Press 2:Normal Attack 3:Skill 1 4:Skill 2 5:Skill 3 ");
                        scanf("%d", &PlayerAction);
                        if (Action == 0 && PlayerAction != 5) {
                            printf("Enemy Runned\n\n");
                            printf("You FAILED\n\n");
                            goto FAIL;
                            break;
                        }
                        else if (Action == 0 && PlayerAction == 5) {
                            Support(PlayerAction);
                            printf("My HP : %d My MP : %d Enemy HP : %d\n\n", HealthPoint, ManaPoint, MopHP);
                        }
                        else if ((Action == 1 || Action == 2) && (PlayerAction == 2 || PlayerAction == 4)) {
                            printf("Enemy Guarded\n\n");
                            printf("My HP : %d My MP : %d Enemy HP : %d\n\n", HealthPoint, ManaPoint, MopHP);
                        }
                        else if ((Action == 1 || Action == 2) && (PlayerAction != 2 && PlayerAction != 4)) {
                            Support(PlayerAction);
                            printf("My HP : %d My MP : %d Enemy HP : %d\n\n", HealthPoint, ManaPoint, MopHP);
                        }
                        else if (Action > 2) {
                            Support(PlayerAction);
                            HealthPoint -= 1;
                            printf("My HP : %d My MP : %d Enemy HP : %d\n\n", HealthPoint, ManaPoint, MopHP);
                        }
                        if (HealthPoint == 0) {
                            goto EXIT;
                        }

                    }
                    printf("VICTORY\n");
                    Level += 1; HealthPoint += 1;


                }
            }
        }
    }
SAN:
    int Challenge;//���� ���� ���� �Է¹޴� ����
    printf("You achieved 10 Level. Wanna Challenge Boss? 1-Y 2-N : ");
    scanf("%d", &Challenge);
    if (Challenge == 2) {
        printf("Encountered Spider Choose your Action\n\n");
        MopHP = 20;
        while (MopHP > 0) {//������ �������� �ʰ� ������ �ø��ٰ� ������ �� ����->������ ������ŭ ������ ��� �÷��� ����
            int Action = rand() % 10;
            printf("Press 2:Normal Attack 3:Skill 1 4:Skill 2 5:Skill 3 ");
            scanf("%d", &PlayerAction);
            if (Action == 0 && PlayerAction != 5) {
                printf("Enemy Runned\n\n");
                goto SAN;
            }
            else if (Action == 0 && PlayerAction == 5) {
                Support(PlayerAction);
                printf("My HP : %d My MP : %d Enemy HP : %d\n\n", HealthPoint, ManaPoint, MopHP);

            }
            else if ((Action == 1 || Action == 2) && (PlayerAction == 2 || PlayerAction == 4)) {
                printf("Enemy Guarded\n\n");
                printf("My HP : %d My MP : %d Enemy HP : %d\n\n", HealthPoint, ManaPoint, MopHP);
            }
            else if ((Action == 1 || Action == 2) && (PlayerAction != 2 && PlayerAction != 4)) {
                Support(PlayerAction);
                printf("My HP : %d My MP : %d Enemy HP : %d\n\n", HealthPoint, ManaPoint, MopHP);
            }
            else if (Action > 2) {
                Support(PlayerAction);
                HealthPoint -= 2;
                printf("My HP : %d My MP : %d Enemy HP : %d\n\n", HealthPoint, ManaPoint, MopHP);
            }
            if (HealthPoint == 0) {
                goto EXIT;
            }

        }
        printf("VICTORY\n\n");
        Level += 1; HealthPoint += 1;
        goto SAN;
    }
    if (Challenge == 1) {
        MopHP = 40;
        while (MopHP > 0) {//���� ����
            int Action = rand() % 10;
            printf("Press 2:Normal Attack 3:Skill 1 4:Skill 2 5:Skill 3 ");
            scanf("%d", &PlayerAction);
            if (Action == 0) {
                printf("Boss Healed\n\n");//������ ���� ��� �� ���
                MopHP += 1;
                Support(PlayerAction);
                printf("My HP : %d My MP : %d Enemy HP : %d\n\n", HealthPoint, ManaPoint, MopHP);
            }
            else if (Action == 1 || Action == 2 && PlayerAction == 2 || PlayerAction == 4) {
                printf("Enemy Guarded\n\n");
                printf("My HP : %d My MP : %d Enemy HP : %d\n\n", HealthPoint, ManaPoint, MopHP);
            }
            else if (Action == 1 && PlayerAction != 2 && PlayerAction != 4) {
                HealthPoint -= 1;
                Support(PlayerAction);
                printf("My HP : %d My MP : %d Enemy HP : %d\n\n", HealthPoint, ManaPoint, MopHP);
            }
            else {
                Support(PlayerAction);
                printf("My HP : %d My MP : %d Enemy HP : %d\n", HealthPoint, ManaPoint, MopHP);
            }
            if (HealthPoint < 0) {
                goto EXIT;
            }
        }
    }
    printf("You CLEARED!!\n");//���� Ŭ���� ����
    goto END;

EXIT:
    printf("YOU DIED\n");//���� ����
END:
    return 0;
}
void Support(int PlayerAction) {

    if (PlayerAction == 1)
    {
        printf("HP:4 MP:20\nSkill 1-Heal 1 point Cost : 3MP\nSkill 2-Give 2 damage Cost : 2MP\nSkill 3-Enemy can't run for one Turn Cost : 4MP\n");
    }
    if (PlayerAction == 2) {//�Ϲݰ���, ���� ��� ����
        printf("You Attacked\n");
        MopHP -= 3;
    }
    if (PlayerAction == 3) {//ü�� ä����, ���� ���
        if (ManaPoint < 3) { printf("LACKED MANA\n"); }
        printf("You Healed\n");
        HealthPoint += 4;
        ManaPoint -= 3;
    }
    if (PlayerAction == 4) {//�Ϲݰ��ݺ��� �� ��ų, ���� ���
        if (ManaPoint < 2) { printf("LACKED MANA\n"); }
        printf("You used Attack Skill\n");
        MopHP -= 6;
        ManaPoint -= 2;
    }
    if (PlayerAction == 5) {//�� �ӹ��Ͽ� ���� ����, ���� ��뷮 ŭ->���� ����Ʈ, �ʹ� ���������� �߿��ϰ� �ۿ� 
        if (ManaPoint < 4) { printf("LACKED MANA\n"); }
        printf("Enemy Can't Run\n");
        ManaPoint -= 4;
    }
}//������Ʈ �ÿ��غ����� �ϰڽ��ϴ�. 1 ��° �ÿ��� �⺻�� �״��, 2 ��° �ÿ��� Ŭ��� ���� ���� ���� �� �ϰڽ��ϴ�.




