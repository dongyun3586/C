#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void Support(int a);//플레이어 행동 입력받는 함수, 공격 스킬 등 실행



int LP = 0;//경험치 초기 값, 몬스터를 잡으면서 경험치 획득
int HealthPoint = 10;//플레이어 초기 체력, 힐 레벨업 포션 등으로 늘릴 수 있음
int PlayerAction;//플레이어 행동 입력받는 변수
int ManaPoint = 20;//플레이어 초기 마나, 스킬 사용에 중요함
int NormalAttack = 2;//플레이어 기본 공격력
int MopHP;//몬스터의 체력, 일반 몹과 보스의 체력이 다름
int Level = LP / 9;//레벨=경험치/9

int main() {
    srand(time(NULL));

    printf("Welcome Player\n");


    Support(1);//플레이어 스킬 설명
    HealthPoint = 10 + Level;//레벨이 오를 때마다 체력 1씩 증가//프로그램 구동 확인 후 수정 
    while (Level < 10) {
    FAIL:
        int Encounter = rand() % 6;//랜덤한 상황 연출
        if (Encounter == 0) {//해골과 조우, 전투
            //Fight With Skeleton, Give 9LP if win
            printf("Encountered Skeleton Choose Your Action\n\n");
            MopHP = 20;
            while (MopHP > 0) {
                int Action = rand() % 10;  //몬스터의 무작위적인 행동 유도->while문 돌 때 마다 변함 
                printf("Press 2:Normal Attack 3:Skill 1 4:Skill 2 5:Skill 3 ");
                scanf("%d", &PlayerAction);
                if (Action == 0 && PlayerAction != 5) {//해골이 도망가는 것을 막지 못함(에측 필요)->전투 지속 중 몬스터 도망가면 큰 손해 
                    printf("Enemy Runned\n\n");
                    goto FAIL;
                }
                else if (Action == 0 && PlayerAction == 5) {//해골 도망 저지 성공
                    Support(PlayerAction);
                    printf("My HP : %d My MP : %d Enemy HP : %d\n\n", HealthPoint, ManaPoint, MopHP);
                }
                else if ((Action == 1 || Action == 2) && (PlayerAction == 2 || PlayerAction == 4)) {//해골이 플레이어 공격 방어 성공
                    printf("Enemy Guarded\n\n");
                    printf("My HP : %d My MP : %d Enemy HP : %d\n\n", HealthPoint, ManaPoint, MopHP);
                }

                else if ((Action == 1 && Action == 2) && (PlayerAction != 2 && PlayerAction != 4)) {//해골이 플레이어 공격 방어 시도하지만 플레이어가 공격하지 않음 
                    Support(PlayerAction);
                    printf("My HP : %d My MP : %d Enemy HP : %d\n\n", HealthPoint, ManaPoint, MopHP);

                }
                else if (Action > 2) {//플레이어와 해골이 공격,스킬 주고 받음
                    Support(PlayerAction);
                    HealthPoint -= 1;
                    printf("My HP : %d My MP : %d Enemy HP : %d\n\n", HealthPoint, ManaPoint, MopHP);
                }
                if (HealthPoint == 0) {//플레이어가 체력이 떨어져 죽음
                    goto EXIT;
                }

            }
            printf("VICTORY\n");//전투 승리
            Level += 1; HealthPoint += 1;//레벨, 체력 상승
        }
        else if (Encounter == 1) {//좀비와 전투, 해골과 메커니즘 동일
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
        else if (Encounter == 2) {//거미와 전투, 메커니즘 동일
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
            printf("Picked Mana Potion! MP+3\n\n");//마나포션 획득, 마나 증가
            ManaPoint += 1;
        }
        else if (Encounter == 4) {
            printf("Picked Health Potion! HP+3\n\n");//체력 포션 획득, 체력 증가
            HealthPoint += 1;
        }
        else if (Encounter == 5) {//서브퀘스트, 놓치지 않고 거미 10마리 연속으로 잡아야 함 성공시 10레벨 한번에 달성 
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
    int Challenge;//보스 도전 여부 입력받는 변수
    printf("You achieved 10 Level. Wanna Challenge Boss? 1-Y 2-N : ");
    scanf("%d", &Challenge);
    if (Challenge == 2) {
        printf("Encountered Spider Choose your Action\n\n");
        MopHP = 20;
        while (MopHP > 0) {//보스에 도전하지 않고 레벨을 올리다가 도전할 수 있음->스펙을 보스만큼 높여서 잡는 플레이 가능
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
        while (MopHP > 0) {//보스 도전
            int Action = rand() % 10;
            printf("Press 2:Normal Attack 3:Skill 1 4:Skill 2 5:Skill 3 ");
            scanf("%d", &PlayerAction);
            if (Action == 0) {
                printf("Boss Healed\n\n");//보스는 도망 대신 힐 사용
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
    printf("You CLEARED!!\n");//게임 클리어 성공
    goto END;

EXIT:
    printf("YOU DIED\n");//게임 실패
END:
    return 0;
}
void Support(int PlayerAction) {

    if (PlayerAction == 1)
    {
        printf("HP:4 MP:20\nSkill 1-Heal 1 point Cost : 3MP\nSkill 2-Give 2 damage Cost : 2MP\nSkill 3-Enemy can't run for one Turn Cost : 4MP\n");
    }
    if (PlayerAction == 2) {//일반공격, 마나 사용 안함
        printf("You Attacked\n");
        MopHP -= 3;
    }
    if (PlayerAction == 3) {//체력 채워줌, 마나 사용
        if (ManaPoint < 3) { printf("LACKED MANA\n"); }
        printf("You Healed\n");
        HealthPoint += 4;
        ManaPoint -= 3;
    }
    if (PlayerAction == 4) {//일반공격보다 센 스킬, 마나 사용
        if (ManaPoint < 2) { printf("LACKED MANA\n"); }
        printf("You used Attack Skill\n");
        MopHP -= 6;
        ManaPoint -= 2;
    }
    if (PlayerAction == 5) {//적 속박하여 도망 저지, 마나 사용량 큼->서브 퀘스트, 초반 레벨업에서 중요하게 작용 
        if (ManaPoint < 4) { printf("LACKED MANA\n"); }
        printf("Enemy Can't Run\n");
        ManaPoint -= 4;
    }
}//프로젝트 시연해보도록 하겠습니다. 1 번째 시연은 기본값 그대로, 2 번째 시연은 클리어를 위해 스탯 조정 후 하겠습니다.




