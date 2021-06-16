#include <stdio.h>
#include <windows.h>
#include <time.h>
int start2[5] = { 0,0,0,0,0 };
int goldNumber[5] = { 0,0,0,0,0 };
int kanNumber[40] = { 0 };//각 칸의 소유자를 나타냄
int kanOwner[40] = { 0 };//각 칸의 지어진 건축물을 나타냄
int kanPrice[40] = { 0,50000,0,80000,80000,200000,100000,0,100000,120000,0,140000,0,160000,160000,200000,180000,0,180000,200000,0,220000,0,240000,240000,500000,260000,260000,300000,280000,0,300000,450000,320000,320000,0,350000,350000,150000,1000000 };
int kanFee[40][8] = { {0},{2000,12000,92000,102000,252000,262000,342000,352000},{0},{4000,24000,184000,204000,454000,474000,634000,654000},{4000,24000,184000,204000,454000,474000,634000,654000},{300000,300000,300000,300000,300000,300000,300000,300000},{6000,36000,276000,306000,556000,586000,823000,853000},{0}, {6000,36000,276000,306000,556000,586000,823000,853000},{8000,48000.308000,348000,608000,648000,908000,948000},{0},{10000,60000,460000,510000,760000,810000,1210000,1260000},{0},{12000,72000,512000,572000,912000,972000,1412000,1472000},{12000,72000,512000,572000,912000,972000,1412000,1472000},{300000,300000,300000,300000,300000,300000,300000,300000},{14000,84000,514000,584000,964000,1034000,1464000,1534000},{0},{14000,84000,514000,584000,964000,1034000,1464000,1534000},{16000,96000,566000,646000,1016000,1096000,1566000,1646000},{0},{18000,108000,718000,808000,1068000,1158000,1768000,1858000},{0},{20000,120000,770000,870000,1120000,1220000,1870000,1970000},{20000,120000,770000,870000,1120000,1220000,1870000,1970000},{600000,600000,600000,600000,600000,600000,600000,600000},{22000,132000,822000,932000,1172000,1282000,1972000,2082000},{22000,132000,822000,932000,1172000,1282000,1972000,2082000},{250000},{24000,144000,874000,994000,1224000,1344000,2074000,2194000},{200000},{26000,156000,926000,1056000,1296000,1426000,2196000,2326000},{400000,400000,400000,400000,400000,400000,400000,400000},{28000,178000,1028000,1178000,1428000,1578000,2428000,2578000},{28000,178000,1028000,1178000,1428000,1578000,2428000,2578000},{0},{35000,205000,1135000,1305000,1535000,1705000,2635000,2805000},{35000,205000,1135000,1305000,1535000,1705000,2635000,2805000 },{150000},{2000000,2000000,2000000,2000000,2000000,2000000,2000000,2000000} };
int kanBuildingFee[40][3] = { {0},{50000,150000,200000},{0},{50000,150000,200000},{50000,150000,200000},{0,0,0},{50000,150000,200000},{0,0,0},{50000,150000,200000},{50000,150000,200000},{0,0,0},{100000,300000,500000},{0,0,0},{100000,300000,500000},{100000,300000,500000},{0,0,0},{100000,300000,500000},{0,0,0},{100000,300000,500000},{100000,300000,500000},{0},{150000,450000,750000},{0},{150000,450000,750000},{150000,450000,750000},{0,0,0},{150000,450000,750000},{150000,450000,750000},{0,0,0},{150000,450000,750000},{0,0,0},{200000,600000,1000000},{0,0,0},{200000,600000,1000000},{200000,600000,1000000},{0,0,0},{200000,600000,1000000},{200000,600000,1000000},{0,0,0},{0,0,0} };
char Goldkey[16][300] = { {"병원에서 건강검진을 받았습니다.(5만원을 은행에 납부합니다."},{"복권에 당첨되셨습니다.(은행에서 20만원을 받습니다."},{"폭풍을 만났습니다.(무인도로 가세요)"},{"관광여행으로 제주도로 가세요.(제주도 소유주에게 통행료를 지불합니다. 출발지를 지날시 월급을 받습니다."}, {"과속운전을 하셨습니다.(벌금 5만원을 내세요.)"},{"해외유학 : 학교등록금을 내세요.(10만원이 지불됩니다.)"},{"노후연금 : 노후연금으로 5만원을 받습니다."},{"이사 : 뒤로 세 칸 이동합니다."},{"고속도로 : 출발지로 곧바로 가게됩니다."},{"우승 : 자동차 경주에서 챔피언이 되셨습니다.(상금 10만원을 받습니다.)"},{"항공여행 : 콩코드 여객기를 타고 타이베이로 가십시오(콩코드 여객기 소유주에게 통행료를 지불합니다. 출발지를 지날시 월급을 받습니다."},{"유람선 여행(퀸 엘리자베스 호를 타고 베이징으로 가세요(출발지를 지날시 월급을 받습니다.)"},{"노벨평화상을 수상했습니다. 30만원을 받습니다."},{"우주여행 초청장을 받았습니다. 우주정거장을 갑니다.(출발지를 지날시 월급을 받습니다."},{"관광여행 : 세계의 중심 서울로 갑니다.(주인이 있을시 통헹료를 냅니다.)"},{"사회복지기금 배당 : 사회복지기금접수처로 가세요.(출발지를 지날시 월급을 받습니다.)"} };
struct p1 {
    int money;
    int kan;
    int turn;
    int space;
    int out;
};
struct p2 {
    int money;
    int kan;
    int turn;
    int space;
    int out;
};
struct p3 {
    int money;
    int kan;
    int turn;
    int space;
    int out;
};
struct p4 {
    int money;
    int kan;
    int turn;
    int space;
    int out;
};

int muindo() {
    srand(time(NULL));
    int b = rand() % 36;
    if (b == 0) return 2;
    else if (b == 1) return 4;
    else if (b == 2) return 6;
    else if (b == 3) return 8;
    else if (b == 4) return 10;
    else if (b == 5) return 12;
    else return 0;
}
void resetmnt() {
    system("cls");
    int n = 49;
    while (n) { printf("\n"); n--; }
    int m = 189;
    while (m) { printf(" "); m--; }
}
void start(struct p1* p1, struct p2* p2, struct p3* p3, struct p4* p4, int player) {
    if (player == 1) start2[1] = 1;
    else if (player == 2) start2[2] = 1;
    else if (player == 3) start2[3] = 1;
    else if (player == 4) start2[4] = 1;
    printf("출발지를 지났습니다.\n월급을 받습니다.\n");
}

void Goldenkey(struct p1* p1, struct p2* p2, struct p3* p3, struct p4* p4, int player) {
    srand(time(NULL));
    int b = rand() % 16;
    if (b == 0) {
        printf("%s\n", Goldkey[b]);
        if (player == 1) p1->money -= 50000;
        else if (player == 2) p2->money -= 50000;
        else if (player == 3) p3->money -= 50000;
        else if (player == 4) p4->money -= 50000;
    }
    else if (b == 1) {
        printf("%s\n", Goldkey[b]);
        if (player == 1) p1->money += 200000;
        else if (player == 2) p2->money += 200000;
        else if (player == 3) p3->money += 200000;
        else if (player == 4) p4->money += 200000;
    }
    else if (b == 2) {
        printf("%s\n", Goldkey[b]);
        if (player == 1) p1->kan = 10;
        else if (player == 2) p2->kan = 10;
        else if (player == 3) p3->kan = 10;
        else if (player == 4) p4->kan = 10;
    }
    else if (b == 3) {
        printf("%s\n", Goldkey[b]);
        if (player == 1) {
            if (p1->kan > 5)  start(&p1, &p2, &p3, &p4, 1);
            p1->kan = 5;
            if (kanNumber[5] != 0 && kanNumber[5] != 1) {
                if (kanNumber[5] == 2) {
                    printf("제주도는 플레이어 2의 땅입니다. 통행료를 지불합니다.\n");
                    p1->money -= kanFee[5][0];
                    p2->money += kanFee[5][0];
                    printf("현재 소지금은 플레이어 1은 %d원 플레이어 2는 %d원 입니다.", p1->money, p2->money);
                }
                else if (kanNumber[5] == 3) {
                    printf("제주도는 플레이어 3의 땅입니다. 통행료를 지불합니다.\n");
                    p1->money -= kanFee[5][0];
                    p3->money += kanFee[5][0];
                    printf("현재 소지금은 플레이어 1은 %d원 플레이어 3는 %d원 입니다.", p1->money, p3->money);
                }
                else if (kanNumber[5] == 4) {
                    printf("제주도는 플레이어 4의 땅입니다. 통행료를 지불합니다.\n");
                    p1->money -= kanFee[5][0];
                    p4->money += kanFee[5][0];
                    printf("현재 소지금은 플레이어 1은 %d원 플레이어 4는 %d원 입니다.", p1->money, p4->money);
                }
            }
        }
        else if (player == 2) {
            if (p2->kan > 5) start(&p1, &p2, &p3, &p4, 2);
            p2->kan = 5;
            if (kanNumber[5] != 0 && kanNumber[5] != 2) {
                if (kanNumber[5] == 1) {
                    printf("제주도는 플레이어 1의 땅입니다. 통행료를 지불합니다.\n");
                    p2->money -= kanFee[5][0];
                    p1->money += kanFee[5][0];
                    printf("현재 소지금은 플레이어 1은 %d원 플레이어 2는 %d원 입니다.", p1->money, p2->money);
                }
                else if (kanNumber[5] == 3) {
                    printf("제주도는 플레이어 3의 땅입니다. 통행료를 지불합니다.\n");
                    p2->money -= kanFee[5][0];
                    p3->money += kanFee[5][0];
                    printf("현재 소지금은 플레이어 2은 %d원 플레이어 3는 %d원 입니다.", p2->money, p3->money);
                }
                else if (kanNumber[5] == 4) {
                    printf("제주도는 플레이어 4의 땅입니다. 통행료를 지불합니다.\n");
                    p2->money -= kanFee[5][0];
                    p4->money += kanFee[5][0];
                    printf("현재 소지금은 플레이어 2은 %d원 플레이어 4는 %d원 입니다.", p2->money, p4->money);
                }
            }
        }
        else if (player == 3) {
            if (p3->kan > 5) start(&p1, &p2, &p3, &p4, 3);
            p3->kan = 5;
            if (kanNumber[5] != 0 && kanNumber[5] != 2) {
                if (kanNumber[5] == 1) {
                    printf("제주도는 플레이어 1의 땅입니다. 통행료를 지불합니다.\n");
                    p3->money -= kanFee[5][0];
                    p1->money += kanFee[5][0];
                    printf("현재 소지금은 플레이어 1은 %d원 플레이어 3는 %d원 입니다.", p1->money, p3->money);
                }
                else if (kanNumber[5] == 2) {
                    printf("제주도는 플레이어 2의 땅입니다. 통행료를 지불합니다.\n");
                    p3->money -= kanFee[5][0];
                    p2->money += kanFee[5][0];
                    printf("현재 소지금은 플레이어 2은 %d원 플레이어 3는 %d원 입니다.", p2->money, p3->money);
                }
                else if (kanNumber[5] == 4) {
                    printf("제주도는 플레이어 4의 땅입니다. 통행료를 지불합니다.\n");
                    p3->money -= kanFee[5][0];
                    p4->money += kanFee[5][0];
                    printf("현재 소지금은 플레이어 3은 %d원 플레이어 4는 %d원 입니다.", p3->money, p4->money);
                }
            }
        }
        else if (player == 4) {
            if (p4->kan > 5) start(&p1, &p2, &p3, &p4, 4);
            p4->kan = 5;
            if (kanNumber[5] != 0 && kanNumber[5] != 2) {
                if (kanNumber[5] == 1) {
                    printf("제주도는 플레이어 1의 땅입니다. 통행료를 지불합니다.\n");
                    p4->money -= kanFee[5][0];
                    p1->money += kanFee[5][0];
                    printf("현재 소지금은 플레이어 1은 %d원 플레이어 4는 %d원 입니다.", p1->money, p4->money);
                }
                else if (kanNumber[5] == 3) {
                    printf("제주도는 플레이어 3의 땅입니다. 통행료를 지불합니다.\n");
                    p4->money -= kanFee[5][0];
                    p3->money += kanFee[5][0];
                    printf("현재 소지금은 플레이어 3은 %d원 플레이어 4는 %d원 입니다.", p3->money, p4->money);
                }
                else if (kanNumber[5] == 2) {
                    printf("제주도는 플레이어 2의 땅입니다. 통행료를 지불합니다.\n");
                    p4->money -= kanFee[5][0];
                    p2->money += kanFee[5][0];
                    printf("현재 소지금은 플레이어 2은 %d원 플레이어 4는 %d원 입니다.", p2->money, p4->money);
                }
            }
        }
    }
    else if (b == 4) {
        printf("%s\n", Goldkey[b]);
        if (player == 1) p1->money += 50000;
        else if (player == 2) p2->money += 50000;
        else if (player == 3) p3->money += 50000;
        else if (player == 4) p4->money += 50000;
    }
    else if (b == 5) {
        printf("%s\n", Goldkey[b]);
        if (player == 1) p1->money -= 100000;
        else if (player == 2) p2->money -= 100000;
        else if (player == 3) p3->money -= 100000;
        else if (player == 4) p4->money -= 100000;
    }
    else if (b == 6) {
        printf("%s\n", Goldkey[b]);
        if (player == 1) p1->money += 50000;
        else if (player == 2) p2->money += 50000;
        else if (player == 3) p3->money += 50000;
        else if (player == 4) p4->money += 50000;
    }
    else if (b == 7) {
        printf("%s\n", Goldkey[b]);
        if (player == 1) p1->kan -= 3;
        else if (player == 2) p2->kan -= 3;
        else if (player == 3) p3->kan -= 3;
        else if (player == 4) p4->kan -= 3;
    }
    else if (b == 8) {
        printf("%s\n", Goldkey[b]);
        if (player == 1) {
            p1->kan = 0;
            start(&p1, &p2, &p3, &p4, 1);
        }
        else if (player == 2) {
            p2->kan = 0;
            start(&p1, &p2, &p3, &p4, 2);
        }
        else if (player == 3) {
            p3->kan = 0;
            start(&p1, &p2, &p3, &p4, 3);
        }
        else if (player == 4) {
            p4->kan = 0;
            start(&p1, &p2, &p3, &p4, 4);
        }
    }
    else if (b == 9) {
        printf("%s\n", Goldkey[b]);
        if (player == 1) p1->money += 100000;
        else if (player == 2) p2->money += 100000;
        else if (player == 3) p3->money += 100000;
        else if (player == 4) p4->money += 100000;
    }
    else if (b == 10) {
        printf("%s\n", Goldkey[b]);
        if (player == 1) {
            if (p1->kan > 15) start(&p1, &p2, &p3, &p4, 1);
            p1->kan = 1;
            p1->money += 200000;
            if (kanNumber[1] == 2) {
                printf("플레이어 2의 토지에 걸렸습니다. 통행료가 부가됩니다.\n");
                p1->money -= kanFee[1][kanOwner[1]];
                p2->money += kanFee[1][kanOwner[1]];
                printf("플레이어 1의 소지금은 %d원 플레이어 2의 소지금은 %d원 입니다.\n", p1->money, p2->money);
            }
            else if (kanNumber[1] == 3) {
                printf("플레이어 3의 토지에 걸렸습니다. 통행료가 부가됩니다.\n");
                p1->money -= kanFee[1][kanOwner[1]];
                p3->money += kanFee[1][kanOwner[1]];
                printf("플레이어 1의 소지금은 %d원 플레이어 3의 소지금은 %d원 입니다.\n", p1->money, p3->money);
            }
            else if (kanNumber[1] == 4) {
                printf("플레이어 4의 토지에 걸렸습니다. 통행료가 부가됩니다.\n");
                p1->money -= kanFee[1][kanOwner[1]];
                p4->money += kanFee[1][kanOwner[1]];
                printf("플레이어 1의 소지금은 %d원 플레이어 4의 소지금은 %d원 입니다.\n", p1->money, p4->money);
            }
        }
        else  if (player == 2) {
            if (p2->kan > 15) start(&p1, &p2, &p3, &p4, 2);
            p2->kan = 1;
            p2->money += 200000;
            if (kanNumber[1] == 1) {
                printf("플레이어 1의 토지에 걸렸습니다. 통행료가 부가됩니다.\n");
                p2->money -= kanFee[1][kanOwner[1]];
                p1->money += kanFee[1][kanOwner[1]];
                printf("플레이어 1의 소지금은 %d원 플레이어 2의 소지금은 %d원 입니다.\n", p1->money, p2->money);
            }
            else if (kanNumber[1] == 3) {
                printf("플레이어 3의 토지에 걸렸습니다. 통행료가 부가됩니다.\n");
                p2->money -= kanFee[1][kanOwner[1]];
                p3->money += kanFee[1][kanOwner[1]];
                printf("플레이어 2의 소지금은 %d원 플레이어 3의 소지금은 %d원 입니다.\n", p2->money, p3->money);
            }
            else if (kanNumber[1] == 4) {
                printf("플레이어 4의 토지에 걸렸습니다. 통행료가 부가됩니다.\n");
                p2->money -= kanFee[1][kanOwner[1]];
                p4->money += kanFee[1][kanOwner[1]];
                printf("플레이어 2의 소지금은 %d원 플레이어 4의 소지금은 %d원 입니다.\n", p2->money, p4->money);
            }
        }
        else if (player == 3) {
            if (p3->kan > 15) start(&p1, &p2, &p3, &p4, 3);
            p3->kan = 1;
            p3->money += 200000;
            if (kanNumber[1] == 2) {
                printf("플레이어 2의 토지에 걸렸습니다. 통행료가 부가됩니다.\n");
                p3->money -= kanFee[1][kanOwner[1]];
                p2->money += kanFee[1][kanOwner[1]];
                printf("플레이어 1의 소지금은 %d원 플레이어 3의 소지금은 %d원 입니다.\n", p1->money, p3->money);
            }
            else if (kanNumber[1] == 1) {
                printf("플레이어 1의 토지에 걸렸습니다. 통행료가 부가됩니다.\n");
                p3->money -= kanFee[1][kanOwner[1]];
                p1->money += kanFee[1][kanOwner[1]];
                printf("플레이어 1의 소지금은 %d원 플레이어 3의 소지금은 %d원 입니다.\n", p1->money, p3->money);
            }
            else if (kanNumber[1] == 4) {
                printf("플레이어 4의 토지에 걸렸습니다. 통행료가 부가됩니다.\n");
                p3->money -= kanFee[1][kanOwner[1]];
                p4->money += kanFee[1][kanOwner[1]];
                printf("플레이어 3의 소지금은 %d원 플레이어 4의 소지금은 %d원 입니다.\n", p3->money, p4->money);
            }
        }
        else if (player == 4) {
            if (p4->kan > 15) start(&p1, &p2, &p3, &p4, 4);
            p4->kan = 1;
            p4->money += 200000;
            if (kanNumber[1] == 2) {
                printf("플레이어 2의 토지에 걸렸습니다. 통행료가 부가됩니다.\n");
                p4->money -= kanFee[1][kanOwner[1]];
                p2->money += kanFee[1][kanOwner[1]];
                printf("플레이어 2의 소지금은 %d원 플레이어 4의 소지금은 %d원 입니다.\n", p2->money, p4->money);
            }
            else if (kanNumber[1] == 3) {
                printf("플레이어 3의 토지에 걸렸습니다. 통행료가 부가됩니다.\n");
                p4->money -= kanFee[1][kanOwner[1]];
                p3->money += kanFee[1][kanOwner[1]];
                printf("플레이어 3의 소지금은 %d원 플레이어 4의 소지금은 %d원 입니다.\n", p3->money, p4->money);
            }
            else if (kanNumber[1] == 1) {
                printf("플레이어 1의 토지에 걸렸습니다. 통행료가 부가됩니다.\n");
                p4->money -= kanFee[1][kanOwner[1]];
                p1->money += kanFee[1][kanOwner[1]];
                printf("플레이어 1의 소지금은 %d원 플레이어 4의 소지금은 %d원 입니다.\n", p1->money, p4->money);
            }
        }
    }
    else if (b == 11) {
        printf("%s\n", Goldkey[b]);
        if (player == 1) {
            if (p1->kan > 28) start(&p1, &p2, &p3, &p4, 11);
            p1->kan = 3;
            p1->money += 200000;
            if (kanNumber[3] == 2) {
                printf("플레이어 2의 토지에 걸렸습니다. 통행료가 부가됩니다.\n");
                p1->money -= kanFee[3][kanOwner[3]];
                p2->money += kanFee[3][kanOwner[3]];
                printf("플레이어 1의 소지금은 %d원 플레이어 2의 소지금은 %d원 입니다.\n", p1->money, p2->money);
            }
            else if (kanNumber[3] == 3) {
                printf("플레이어 3의 토지에 걸렸습니다. 통행료가 부가됩니다.\n");
                p1->money -= kanFee[3][kanOwner[3]];
                p3->money += kanFee[3][kanOwner[3]];
                printf("플레이어 1의 소지금은 %d원 플레이어 3의 소지금은 %d원 입니다.\n", p1->money, p3->money);
            }
            else if (kanNumber[3] == 4) {
                printf("플레이어 4의 토지에 걸렸습니다. 통행료가 부가됩니다.\n");
                p1->money -= kanFee[3][kanOwner[3]];
                p4->money += kanFee[3][kanOwner[3]];
                printf("플레이어 1의 소지금은 %d원 플레이어 4의 소지금은 %d원 입니다.\n", p1->money, p4->money);
            }
        }
        else  if (player == 2) {
            if (p2->kan > 28) start(&p1, &p2, &p3, &p4, 2);
            p2->kan = 3;
            p2->money += 200000;
            if (kanNumber[3] == 1) {
                printf("플레이어 1의 토지에 걸렸습니다. 통행료가 부가됩니다.\n");
                p2->money -= kanFee[3][kanOwner[3]];
                p1->money += kanFee[3][kanOwner[3]];
                printf("플레이어 1의 소지금은 %d원 플레이어 2의 소지금은 %d원 입니다.\n", p1->money, p2->money);
            }
            else if (kanNumber[3] == 3) {
                printf("플레이어 3의 토지에 걸렸습니다. 통행료가 부가됩니다.\n");
                p2->money -= kanFee[3][kanOwner[3]];
                p3->money += kanFee[3][kanOwner[3]];
                printf("플레이어 2의 소지금은 %d원 플레이어 3의 소지금은 %d원 입니다.\n", p2->money, p3->money);
            }
            else if (kanNumber[3] == 4) {
                printf("플레이어 4의 토지에 걸렸습니다. 통행료가 부가됩니다.\n");
                p2->money -= kanFee[3][kanOwner[3]];
                p4->money += kanFee[3][kanOwner[3]];
                printf("플레이어 2의 소지금은 %d원 플레이어 4의 소지금은 %d원 입니다.\n", p2->money, p4->money);
            }
        }
        else if (player == 3) {
            if (p3->kan > 28) start(&p1, &p2, &p3, &p4, 3);
            p3->kan = 3;
            p3->money += 200000;
            if (kanNumber[3] == 2) {
                printf("플레이어 2의 토지에 걸렸습니다. 통행료가 부가됩니다.\n");
                p3->money -= kanFee[3][kanOwner[3]];
                p2->money += kanFee[3][kanOwner[3]];
                printf("플레이어 1의 소지금은 %d원 플레이어 3의 소지금은 %d원 입니다.\n", p1->money, p3->money);
            }
            else if (kanNumber[3] == 1) {
                printf("플레이어 1의 토지에 걸렸습니다. 통행료가 부가됩니다.\n");
                p3->money -= kanFee[3][kanOwner[3]];
                p1->money += kanFee[3][kanOwner[3]];
                printf("플레이어 1의 소지금은 %d원 플레이어 3의 소지금은 %d원 입니다.\n", p1->money, p3->money);
            }
            else if (kanNumber[3] == 4) {
                printf("플레이어 4의 토지에 걸렸습니다. 통행료가 부가됩니다.\n");
                p3->money -= kanFee[3][kanOwner[3]];
                p4->money += kanFee[3][kanOwner[3]];
                printf("플레이어 3의 소지금은 %d원 플레이어 4의 소지금은 %d원 입니다.\n", p3->money, p4->money);
            }
        }
        else if (player == 4) {
            if (p4->kan > 28) start(&p1, &p2, &p3, &p4, 4);
            p4->kan = 3;
            p4->money += 200000;
            if (kanNumber[3] == 2) {
                printf("플레이어 2의 토지에 걸렸습니다. 통행료가 부가됩니다.\n");
                p4->money -= kanFee[3][kanOwner[3]];
                p2->money += kanFee[3][kanOwner[3]];
                printf("플레이어 2의 소지금은 %d원 플레이어 4의 소지금은 %d원 입니다.\n", p2->money, p4->money);
            }
            else if (kanNumber[3] == 3) {
                printf("플레이어 3의 토지에 걸렸습니다. 통행료가 부가됩니다.\n");
                p4->money -= kanFee[3][kanOwner[3]];
                p3->money += kanFee[3][kanOwner[3]];
                printf("플레이어 3의 소지금은 %d원 플레이어 4의 소지금은 %d원 입니다.\n", p3->money, p4->money);
            }
            else if (kanNumber[3] == 1) {
                printf("플레이어 1의 토지에 걸렸습니다. 통행료가 부가됩니다.\n");
                p4->money -= kanFee[3][kanOwner[3]];
                p1->money += kanFee[3][kanOwner[3]];
                printf("플레이어 1의 소지금은 %d원 플레이어 4의 소지금은 %d원 입니다.\n", p1->money, p4->money);
            }
        }
    }
    else if (b == 12) {
        printf("%s", Goldkey[12]);
        if (player == 1) p1->money += 300000;
        else if (player == 2) p2->money += 300000;
        else if (player == 3) p3->money += 300000;
        else if (player == 4) p4->money += 300000;
    }
    else if (b == 13) {
        printf("%s\n", Goldkey[13]);
        if (player == 1) {
            if (p1->kan > 30) start(&p1, &p2, &p3, &p4, 1);
            p1->kan = 30;
        }
        else if (player == 2) {
            if (p2->kan > 30) start(&p1, &p2, &p3, &p4, 2);
            p2->kan = 30;
        }
        else if (player == 3) {
            if (p3->kan > 30) start(&p1, &p2, &p3, &p4, 3);
            p3->kan = 30;
        }
        else if (player == 4) {
            if (p4->kan > 30) start(&p1, &p2, &p3, &p4, 4);
            p4->kan = 30;
        }
    }
    else if (b == 14) {
        printf("%s\n", Goldkey[b]);
        if (player == 1) {
            p1->kan = 39;
            if (kanNumber[39] == 2) {
                printf("플레이어 2의 토지에 걸렸습니다. 통행료가 부가됩니다.\n");
                p1->money -= kanFee[39][kanOwner[39]];
                p2->money += kanFee[39][kanOwner[39]];
                printf("플레이어 1의 소지금은 %d원 플레이어 2의 소지금은 %d원 입니다.\n", p1->money, p2->money);
            }
            else if (kanNumber[39] == 3) {
                printf("플레이어 3의 토지에 걸렸습니다. 통행료가 부가됩니다.\n");
                p1->money -= kanFee[39][kanOwner[39]];
                p3->money += kanFee[39][kanOwner[39]];
                printf("플레이어 1의 소지금은 %d원 플레이어 3의 소지금은 %d원 입니다.\n", p1->money, p3->money);
            }
            else if (kanNumber[39] == 4) {
                printf("플레이어 4의 토지에 걸렸습니다. 통행료가 부가됩니다.\n");
                p1->money -= kanFee[39][kanOwner[39]];
                p4->money += kanFee[39][kanOwner[39]];
                printf("플레이어 1의 소지금은 %d원 플레이어 4의 소지금은 %d원 입니다.\n", p1->money, p4->money);
            }
        }
        else  if (player == 2) {
            p2->kan = 39;
            if (kanNumber[39] == 1) {
                printf("플레이어 1의 토지에 걸렸습니다. 통행료가 부가됩니다.\n");
                p2->money -= kanFee[39][kanOwner[39]];
                p1->money += kanFee[39][kanOwner[39]];
                printf("플레이어 1의 소지금은 %d원 플레이어 2의 소지금은 %d원 입니다.\n", p1->money, p2->money);
            }
            else if (kanNumber[39] == 3) {
                printf("플레이어 3의 토지에 걸렸습니다. 통행료가 부가됩니다.\n");
                p2->money -= kanFee[39][kanOwner[39]];
                p3->money += kanFee[39][kanOwner[39]];
                printf("플레이어 2의 소지금은 %d원 플레이어 3의 소지금은 %d원 입니다.\n", p2->money, p3->money);
            }
            else if (kanNumber[39] == 4) {
                printf("플레이어 4의 토지에 걸렸습니다. 통행료가 부가됩니다.\n");
                p2->money -= kanFee[39][kanOwner[39]];
                p4->money += kanFee[39][kanOwner[39]];
                printf("플레이어 2의 소지금은 %d원 플레이어 4의 소지금은 %d원 입니다.\n", p2->money, p4->money);
            }
        }
        else if (player == 3) {
            p3->kan = 39;
            if (kanNumber[39] == 2) {
                printf("플레이어 2의 토지에 걸렸습니다. 통행료가 부가됩니다.\n");
                p3->money -= kanFee[39][kanOwner[39]];
                p2->money += kanFee[39][kanOwner[39]];
                printf("플레이어 1의 소지금은 %d원 플레이어 3의 소지금은 %d원 입니다.\n", p1->money, p3->money);
            }
            else if (kanNumber[39] == 1) {
                printf("플레이어 1의 토지에 걸렸습니다. 통행료가 부가됩니다.\n");
                p3->money -= kanFee[39][kanOwner[39]];
                p1->money += kanFee[39][kanOwner[39]];
                printf("플레이어 1의 소지금은 %d원 플레이어 3의 소지금은 %d원 입니다.\n", p1->money, p3->money);
            }
            else if (kanNumber[39] == 4) {
                printf("플레이어 4의 토지에 걸렸습니다. 통행료가 부가됩니다.\n");
                p3->money -= kanFee[39][kanOwner[39]];
                p4->money += kanFee[39][kanOwner[39]];
                printf("플레이어 3의 소지금은 %d원 플레이어 4의 소지금은 %d원 입니다.\n", p3->money, p4->money);
            }
        }
        else if (player == 4) {
            p4->kan = 39;
            if (kanNumber[39] == 2) {
                printf("플레이어 2의 토지에 걸렸습니다. 통행료가 부가됩니다.\n");
                p4->money -= kanFee[39][kanOwner[39]];
                p2->money += kanFee[39][kanOwner[39]];
                printf("플레이어 2의 소지금은 %d원 플레이어 4의 소지금은 %d원 입니다.\n", p2->money, p4->money);
            }
            else if (kanNumber[39] == 3) {
                printf("플레이어 3의 토지에 걸렸습니다. 통행료가 부가됩니다.\n");
                p4->money -= kanFee[39][kanOwner[39]];
                p3->money += kanFee[39][kanOwner[39]];
                printf("플레이어 3의 소지금은 %d원 플레이어 4의 소지금은 %d원 입니다.\n", p3->money, p4->money);
            }
            else if (kanNumber[39] == 1) {
                printf("플레이어 1의 토지에 걸렸습니다. 통행료가 부가됩니다.\n");
                p4->money -= kanFee[39][kanOwner[39]];
                p1->money += kanFee[39][kanOwner[39]];
                printf("플레이어 1의 소지금은 %d원 플레이어 4의 소지금은 %d원 입니다.\n", p1->money, p4->money);
            }
        }
    }
    else if (b == 15) {
        printf("%s\n", Goldkey[15]);
        if (player == 1) {
            if (p1->kan > 20) start(&p1, &p2, &p3, &p4, 1);
            p1->kan = 20;
        }
        else if (player == 2) {
            if (p2->kan > 20) start(&p1, &p2, &p3, &p4, 2);
            p2->kan = 20;
        }
        else if (player == 3) {
            if (p3->kan > 20) start(&p1, &p2, &p3, &p4, 3);
            p3->kan = 20;
        }
        else if (player == 4) {
            if (p4->kan > 20) start(&p1, &p2, &p3, &p4, 4);
            p4->kan = 20;
        }

    }
}

void game(struct p1* p1, struct p2* p2, struct p3* p3, struct p4* p4, int player) {
    int kan = 0;
    if (player == 1) kan = p1->kan;
    else if (player == 2) kan = p2->kan;
    else if (player == 3) kan = p3->kan;
    else if (player == 4) kan = p4->kan;
    if (kan >= 40) {
        printf("출발점을 지났습니다. 월급으로 20만원을 받습니다.\n");
        if (player == 1) {
            p1->money += 200000;
            p1->kan -= 40;
            kan -= 40;
        }
        else if (player == 2) {
            p2->money += 200000;
            p2->kan -= 40;
            kan -= 40;
        }
        else if (player == 3) {
            p3->money += 200000;
            p3->kan -= 40;
            kan -= 40;
        }
        else if (player == 4) {
            p4->money += 200000;
            p4->kan -= 40;
            kan -= 40;
        }
    }
    if (kanNumber[kan] == 0 && kan != 0 && kan != 2 && kan != 7 && kan != 10 && kan != 12 && kan != 17 && kan != 20 && kan != 22 && kan != 30 && kan != 35 && kan != 38) {
        printf("구매하실 수 있는 토지입니다.\n 가격은 %d원입니다.\n 구매하시겠습니까? 구매를 원하시면 1번, 원하지 않으시면 다른 키를 눌러주세요\n", kanPrice[kan]);
        int k;
        scanf("%d", &k);
        if (k == 1) {
            if (player == 1) {
                kanNumber[kan] = 1;
                p1->money -= kanPrice[kan];
                printf("땅을 성공적으로 구매했습니다. 현재 소지 금액은 %d원입니다.\n", p1->money);
            }
            else if (player == 2) {
                kanNumber[kan] = 2;
                p2->money -= kanPrice[kan];
                printf("땅을 성공적으로 구매했습니다. 현재 소지 금액은 %d원입니다.\n", p2->money);
            }
            else if (player == 3) {
                kanNumber[kan] = 3;
                p3->money -= kanPrice[kan];
                printf("땅을 성공적으로 구매했습니다. 현재 소지 금액은 %d원입니다.\n", p3->money);
            }
            else if (player == 4) {
                kanNumber[kan] = 4;
                p4->money -= kanPrice[kan];
                printf("땅을 성공적으로 구매했습니다. 현재 소지 금액은 %d원입니다.\n", p4->money);
            }
        }
        else {
            if (player == 1) {
                printf("땅을 구매하지 않았습니다. 현재 소지 금액은 %d원입니다.\n", p1->money);
            }
            else if (player == 2) {
                printf("땅을 구매하지 않았습니다. 현재 소지 금액은 %d원입니다.\n", p2->money);
            }
            else if (player == 3) {
                printf("땅을 구매하지 않았습니다. 현재 소지 금액은 %d원입니다.\n", p3->money);
            }
            else if (player == 4) {
                printf("땅을 구매하지 않았습니다. 현재 소지 금액은 %d원입니다.\n", p4->money);
            }
        }
    }
    else if (kanNumber[kan] == 1) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        printf("현재 소지금액은 %d원 입니다.\n", p1->money);
        if (player == 1) {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
            printf("자신의 땅입니다.\n");
            if (kanOwner[kan] == 7) {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
                printf("이미 최대로 건설되어 있습니다.\n");
            }
            else if (kanOwner[kan] == 3) {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
                printf("추가로 호텔을 건설할 수 있습니다.\n호텔가격은 %d원 입니다.\n호텔을 건설하시길 원한다면 1번,건설하고 싶지 않으시면 다른 키를 눌러주세요\n", kanBuildingFee[kan][2]);
                char k;
                scanf("%c", &k);
                if (k == '1') {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                    p1->money -= kanBuildingFee[kan][2];
                    printf("호텔을 건설하였습니다. 현재소지 금액은 %d원 입니다.", p1->money);
                    kanOwner[kan] = 7;
                }
                else {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                    printf("건물을 건설하지 않았습니다. 현재 소지 금액은 %d원 입니다.", p1->money);//건물 구매 가격,건물에 따른 토지료 정하기
                }
            }
            else if (kanOwner[kan] == 5) {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
                printf("추가로 빌딩을 건설할 수 있습니다.\n빌딩가격은 %d원 입니다.\n빌딩을 건설하시길 원한다면 1번, 건설하고 싶지 않으시다면 다른 키를 눌러주세요\n", kanBuildingFee[kan][1]);
                char k;
                scanf("%c", &k);
                if (k == '1') {
                    p1->money -= kanBuildingFee[kan][1];
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                    printf("빌딩을 건설하였습니다. 현재소지 금액은 %d원 입니다.", p1->money);
                    kanOwner[kan] = 7;
                }
                else {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                    printf("건물을 건설하지 않았습니다. 현재 소지 금액은 %d원 입니다.", p1->money);//건물 구매 가격,건물에 따른 토지료 정하기
                }
            }
            else if (kanOwner[kan] == 6) {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
                printf("추가로 주택을 건설할 수 있습니다.\n주택가격은 %d원 입니다.\n주택을 건설하시길 원한다면 1번, 건설하고 싶지 않으시다면 다른 키를 눌러주세요\n", kanBuildingFee[kan][0]);
                char k;
                scanf("%c", &k);
                if (k == '1') {
                    p1->money -= kanBuildingFee[kan][0];
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                    printf("주택을 건설하였습니다. 현재소지 금액은 %d원 입니다.", p1->money);
                    kanOwner[kan] = 7;
                }
                else {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                    printf("건물을 건설하지 않았습니다. 현재 소지 금액은 %d원 입니다.", p1->money);//건물 구매 가격,건물에 따른 토지료 정하기
                }
            }
            else if (kanOwner[kan] == 4) {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
                printf("추가로 주택과 빌딩을 건설할 수 있습니다.\n주택가격은 %d원 입니다. 빌딩가격은 %d원 입니다.\n주택만을 건설하시길 원한다면 1번, 빌딩만을 건설하시길 원한다면 2번, 주택과 빌딩을 건설하시길 원한다면 3번, 건설하고 싶지 않으시다면 다른 키를 눌러주세요\n", kanBuildingFee[kan][0], kanBuildingFee[kan][1]);
                char k;
                scanf("%c", &k);
                if (k == '1') {
                    p1->money -= kanBuildingFee[kan][0];
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                    printf("주택을 건설하였습니다. 현재소지 금액은 %d원 입니다.", p1->money);
                    kanOwner[kan] = 5;
                }
                else if (k == '2') {
                    p1->money -= kanBuildingFee[kan][1];
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                    printf("빌딩을 건설하였습니다. 현재소지 금액은 %d원 입니다.", p1->money);
                    kanOwner[kan] = 6;
                }
                else if (k == '3') {
                    p1->money -= kanBuildingFee[kan][1];
                    p1->money -= kanBuildingFee[kan][0];
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                    printf("주택과 빌딩을 건설하였습니다. 현재소지 금액은 %d원입니다.", p1->money);
                    kanOwner[kan] = 7;
                }
                else {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                    printf("건물을 건설하지 않았습니다. 현재 소지 금액은 %d 원입니다.", p1->money);//건물 구매 가격,건물에 따른 토지료 정하기
                }
            }
            else if (kanOwner[kan] == 2) {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
                printf("추가로 주택과 호텔을 건설하실 수 있습니다. 주택의 가격은 %d원 입니다. 호텔의 가격은 %d원 입니다. \n주택만을 건설하시고 싶으시면 1번,호텔만을 건설하고 싶으시면 2번, 주택과 호텔을 건설하고 싶으시면 3번, 건설하고 싶지 않으시면 다른 키를 눌러주세요\n", kanBuildingFee[kan][0], kanBuildingFee[kan][2]);
                char k;
                scanf("%c", &k);
                if (k == '1') {
                    p1->money -= kanBuildingFee[kan][0];
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                    printf("주택을 건설하였습니다. 현재소지 금액은 %d원 입니다.", p1->money);
                    kanOwner[kan] = 3;
                }
                else if (k == '2') {
                    p1->money -= kanBuildingFee[kan][2];
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                    printf("호텔을 건설하였습니다. 현재소지 금액은 %d원 입니다.", p1->money);
                    kanOwner[kan] = 6;
                }
                else if (k == '3') {
                    p1->money -= kanBuildingFee[kan][0];
                    p1->money -= kanBuildingFee[kan][2];
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                    printf("주택을 건설하였습니다. 현재소지 금액은 %d원 입니다.", p1->money);
                    kanOwner[kan] = 7;
                }
                else {
                    printf("건물을 건설하지 않았습니다. 현재소지 금액은 %d원 입니다.", p1->money);
                }
            }
            else if (kanOwner[kan] == 1) {
                printf("추가로 빌딩과 호텔을 건설하실 수 있습니다. 빌딩의 가격은 %d원 입니다. 호텔의 가격은 %d원 입니다. \n빌딩만을 구매하고 싶으시면 1번, 호텔만을 구매하고 싶으시면 2번, 빌딩과 호텔을 구매하고 싶으시면 3번, 구매하고 싶지 않으시면 다른 키를 눌러주세요\n", kanBuildingFee[kan][1], kanBuildingFee[kan][2]);
                char k;
                scanf("%c", &k);
                if (k == '1') {
                    p1->money -= kanBuildingFee[kan][1];
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                    printf("빌딩을 건설하였습니다. 현재소지 금액은 %d원 입니다.", p1->money);
                    kanOwner[kan] = 3;
                }
                else if (k == '2') {
                    p1->money -= kanBuildingFee[kan][2];
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                    printf("호텔을 건설하였습니다. 현재소지 금액은 %d원 입니다.", p1->money);
                    kanOwner[kan] = 5;
                }
                else if (k == '3') {
                    p1->money -= kanBuildingFee[kan][1];
                    p1->money -= kanBuildingFee[kan][2];
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                    printf("빌딩과 호텔을 건설하였습니다. 현재소지 금액은 %d원 입니다.", p1->money);
                    kanOwner[kan] = 7;
                }
                else {
                    printf("건물을 건설하지 않았습니다. 현재소지 금액은 %d원 입니다.", p1->money);
                }
            }
            else {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
                printf("주택, 빌딩, 호텔을 건설하실 수 있습니다. 주택의 가격은 %d원 입니다. 빌딩의 가격은 %d원 입니다. 호텔의 가격은 %d원 입니다\n", kanBuildingFee[kan][0], kanBuildingFee[kan][1], kanBuildingFee[kan][2]);
                printf("주택만을 건설하시고 싶으시면 1번, 빌딩만을 건설하시고 싶으시면 2번, 호텔만을 건설하시고 싶으시면 3번, 주택과 빌딩을 건설하시고 싶으시면 4번, 주택과 호텔을 건설하시고 싶으시면 5번, 빌딩과 호텔을 건설하시고 싶으시면 6번,주택과 빌딩과 호텔을 건설하시고 싶으시면 7번, 건설하시고 싶지 않으시면 다른 키를 눌러주세요");
                char k;
                scanf("%c", &k);
                if (k == '1') {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                    p1->money -= kanBuildingFee[kan][0];
                    printf("주택을 건설하셨습니다. 현재소지 금액은 %d원 입니다.", p1->money);
                    kanOwner[kan] = 1;
                }
                else if (k == '2') {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                    p1->money -= kanBuildingFee[kan][1];
                    printf("빌딩을 건설하셨습니다. 현재소지 금액은 %d원 입니다.", p1->money);
                    kanOwner[kan] = 2;
                }
                else if (k == '3') {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                    p1->money -= kanBuildingFee[kan][2];
                    printf("호텔을 건설하셨습니다. 현재소지 금액은 %d원 입니다.", p1->money);
                    kanOwner[kan] = 3;
                }
                else if (k == '4') {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                    p1->money -= kanBuildingFee[kan][0];
                    p1->money -= kanBuildingFee[kan][1];
                    printf("주택과 빌딩을 건설하셨습니다. 현재소지 금액은 %d원 입니다.", p1->money);
                    kanOwner[kan] = 4;
                }
                else if (k == '5') {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                    p1->money -= kanBuildingFee[kan][0];
                    p1->money -= kanBuildingFee[kan][2];
                    printf("주택과 호텔을 건설하셨습니다. 현재소지 금액은 %d원 입니다.", p1->money);
                    kanOwner[kan] = 5;
                }
                else if (k == '6') {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                    p1->money -= kanBuildingFee[kan][1];
                    p1->money -= kanBuildingFee[kan][2];
                    printf("빌딩과 호텔을 건설하셨습니다. 현재소지 금액은 %d원 입니다.", p1->money);
                    kanOwner[kan] = 6;
                }
                else if (k == '7') {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                    p1->money -= kanBuildingFee[kan][0];
                    p1->money -= kanBuildingFee[kan][1];
                    p1->money -= kanBuildingFee[kan][2];
                    printf("주택과 빌딩과 호텔을 건설하셨습니다. 현재소지 금액은 %d원 입니다.", p1->money);
                    kanOwner[kan] = 7;
                }
                else {
                    printf("건물을 건설하지 않았습니다. 현재소지 금액은 %d원 입니다.", p1->money);
                }
            }
            printf("\n");
        }
        else if (player == 2) {
            printf("플레이어1의 땅에 걸렸습니다. 통행료가 지불됩니다.\n");
            p2->money -= kanFee[kan][kanOwner[kan]];
            p1->money += kanFee[kan][kanOwner[kan]];
            printf("플레이어 1의 소지금은 %d원\n플레이어 2의 소지금은 %d원 입니다.\n", p1->money, p2->money);
        }
        else if (player == 3) {
            printf("플레이어1의 땅에 걸렸습니다. 통행료가 지불됩니다.\n");
            p3->money -= kanFee[kan][kanOwner[kan]];
            p1->money += kanFee[kan][kanOwner[kan]];
            printf("플레이어 1의 소지금은 %d원\n플레이어 3의 소지금은 %d원 입니다.\n", p1->money, p3->money);
        }
        else if (player == 4) {
            printf("플레이어1의 땅에 걸렸습니다. 통행료가 지불됩니다.\n");
            p4->money -= kanFee[kan][kanOwner[kan]];
            p1->money += kanFee[kan][kanOwner[kan]];
            printf("플레이어 1의 소지금은 %d원\n플레이어 4의 소지금은 %d원 입니다.\n", p1->money, p4->money);
        }
    }
    else if (kanNumber[kan] == 2) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        printf("현재 소지금액은 %d원 입니다.\n", p1->money);
        if (player == 2) {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
            printf("자신의 땅입니다.\n");
            if (kanOwner[kan] == 7) {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
                printf("이미 최대로 건설되어 있습니다.\n");
            }
            else if (kanOwner[kan] == 3) {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
                printf("추가로 호텔을 건설할 수 있습니다.\n호텔가격은 %d원 입니다.\n호텔을 건설하시길 원한다면 1번,건설하고 싶지 않으시면 다른 키를 눌러주세요\n", kanBuildingFee[kan][2]);
                char k;
                scanf("%c", &k);
                if (k == '1') {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                    p1->money -= kanBuildingFee[kan][2];
                    printf("호텔을 건설하였습니다. 현재소지 금액은 %d원 입니다.", p1->money);
                    kanOwner[kan] = 7;
                }
                else {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                    printf("건물을 건설하지 않았습니다. 현재 소지 금액은 %d원 입니다.", p1->money);//건물 구매 가격,건물에 따른 토지료 정하기
                }
            }
            else if (kanOwner[kan] == 5) {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
                printf("추가로 빌딩을 건설할 수 있습니다.\n빌딩가격은 %d원 입니다.\n빌딩을 건설하시길 원한다면 1번, 건설하고 싶지 않으시다면 다른 키를 눌러주세요\n", kanBuildingFee[kan][1]);
                char k;
                scanf("%c", &k);
                if (k == '1') {
                    p1->money -= kanBuildingFee[kan][1];
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                    printf("빌딩을 건설하였습니다. 현재소지 금액은 %d원 입니다.", p1->money);
                    kanOwner[kan] = 7;
                }
                else {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                    printf("건물을 건설하지 않았습니다. 현재 소지 금액은 %d원 입니다.", p1->money);//건물 구매 가격,건물에 따른 토지료 정하기
                }
            }
            else if (kanOwner[kan] == 6) {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
                printf("추가로 주택을 건설할 수 있습니다.\n주택가격은 %d원 입니다.\n주택을 건설하시길 원한다면 1번, 건설하고 싶지 않으시다면 다른 키를 눌러주세요\n", kanBuildingFee[kan][0]);
                char k;
                scanf("%c", &k);
                if (k == '1') {
                    p1->money -= kanBuildingFee[kan][0];
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                    printf("주택을 건설하였습니다. 현재소지 금액은 %d원 입니다.", p1->money);
                    kanOwner[kan] = 7;
                }
                else {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                    printf("건물을 건설하지 않았습니다. 현재 소지 금액은 %d원 입니다.", p1->money);//건물 구매 가격,건물에 따른 토지료 정하기
                }
            }
            else if (kanOwner[kan] == 4) {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
                printf("추가로 주택과 빌딩을 건설할 수 있습니다.\n주택가격은 %d원 입니다. 빌딩가격은 %d원 입니다.\n주택만을 건설하시길 원한다면 1번, 빌딩만을 건설하시길 원한다면 2번, 주택과 빌딩을 건설하시길 원한다면 3번, 건설하고 싶지 않으시다면 다른 키를 눌러주세요\n", kanBuildingFee[kan][0], kanBuildingFee[kan][1]);
                char k;
                scanf("%c", &k);
                if (k == '1') {
                    p1->money -= kanBuildingFee[kan][0];
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                    printf("주택을 건설하였습니다. 현재소지 금액은 %d원 입니다.", p1->money);
                    kanOwner[kan] = 5;
                }
                else if (k == '2') {
                    p1->money -= kanBuildingFee[kan][1];
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                    printf("빌딩을 건설하였습니다. 현재소지 금액은 %d원 입니다.", p1->money);
                    kanOwner[kan] = 6;
                }
                else if (k == '3') {
                    p1->money -= kanBuildingFee[kan][1];
                    p1->money -= kanBuildingFee[kan][0];
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                    printf("주택과 빌딩을 건설하였습니다. 현재소지 금액은 %d원입니다.", p1->money);
                    kanOwner[kan] = 7;
                }
                else {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                    printf("건물을 건설하지 않았습니다. 현재 소지 금액은 %d 원입니다.", p1->money);//건물 구매 가격,건물에 따른 토지료 정하기
                }
            }
            else if (kanOwner[kan] == 2) {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
                printf("추가로 주택과 호텔을 건설하실 수 있습니다. 주택의 가격은 %d원 입니다. 호텔의 가격은 %d원 입니다. \n주택만을 건설하시고 싶으시면 1번,호텔만을 건설하고 싶으시면 2번, 주택과 호텔을 건설하고 싶으시면 3번, 건설하고 싶지 않으시면 다른 키를 눌러주세요\n", kanBuildingFee[kan][0], kanBuildingFee[kan][2]);
                char k;
                scanf("%c", &k);
                if (k == '1') {
                    p2->money -= kanBuildingFee[kan][0];
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                    printf("주택을 건설하였습니다. 현재소지 금액은 %d원 입니다.", p2->money);
                    kanOwner[kan] = 3;
                }
                else if (k == '2') {
                    p2->money -= kanBuildingFee[kan][2];
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                    printf("호텔을 건설하였습니다. 현재소지 금액은 %d원 입니다.", p2->money);
                    kanOwner[kan] = 6;
                }
                else if (k == '3') {
                    p2->money -= kanBuildingFee[kan][0];
                    p2->money -= kanBuildingFee[kan][2];
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                    printf("주택을 건설하였습니다. 현재소지 금액은 %d원 입니다.", p2->money);
                    kanOwner[kan] = 7;
                }
                else {
                    printf("건물을 건설하지 않았습니다. 현재소지 금액은 %d원 입니다.", p2->money);
                }
            }
            else if (kanOwner[kan] == 1) {
                printf("추가로 빌딩과 호텔을 건설하실 수 있습니다. 빌딩의 가격은 %d원 입니다. 호텔의 가격은 %d원 입니다. \n빌딩만을 구매하고 싶으시면 1번, 호텔만을 구매하고 싶으시면 2번, 빌딩과 호텔을 구매하고 싶으시면 3번, 구매하고 싶지 않으시면 다른 키를 눌러주세요\n", kanBuildingFee[kan][1], kanBuildingFee[kan][2]);
                char k;
                scanf("%c", &k);
                if (k == '1') {
                    p2->money -= kanBuildingFee[kan][1];
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                    printf("빌딩을 건설하였습니다. 현재소지 금액은 %d원 입니다.", p2->money);
                    kanOwner[kan] = 3;
                }
                else if (k == '2') {
                    p2->money -= kanBuildingFee[kan][2];
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                    printf("호텔을 건설하였습니다. 현재소지 금액은 %d원 입니다.", p2->money);
                    kanOwner[kan] = 5;
                }
                else if (k == '3') {
                    p2->money -= kanBuildingFee[kan][1];
                    p2->money -= kanBuildingFee[kan][2];
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                    printf("빌딩과 호텔을 건설하였습니다. 현재소지 금액은 %d원 입니다.", p2->money);
                    kanOwner[kan] = 7;
                }
                else {
                    printf("건물을 건설하지 않았습니다. 현재소지 금액은 %d원 입니다.", p2->money);
                }
            }
            else {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
                printf("주택, 빌딩, 호텔을 건설하실 수 있습니다. 주택의 가격은 %d원 입니다. 빌딩의 가격은 %d원 입니다. 호텔의 가격은 %d원 입니다\n", kanBuildingFee[kan][0], kanBuildingFee[kan][1], kanBuildingFee[kan][2]);
                printf("주택만을 건설하시고 싶으시면 1번, 빌딩만을 건설하시고 싶으시면 2번, 호텔만을 건설하시고 싶으시면 3번, 주택과 빌딩을 건설하시고 싶으시면 4번, 주택과 호텔을 건설하시고 싶으시면 5번, 빌딩과 호텔을 건설하시고 싶으시면 6번,주택과 빌딩과 호텔을 건설하시고 싶으시면 7번, 건설하시고 싶지 않으시면 다른 키를 눌러주세요");
                char k;
                scanf("%c", &k);
                if (k == '1') {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                    p2->money -= kanBuildingFee[kan][0];
                    printf("주택을 건설하셨습니다. 현재소지 금액은 %d원 입니다.", p2->money);
                    kanOwner[kan] = 1;
                }
                else if (k == '2') {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                    p2->money -= kanBuildingFee[kan][1];
                    printf("빌딩을 건설하셨습니다. 현재소지 금액은 %d원 입니다.", p2->money);
                    kanOwner[kan] = 2;
                }
                else if (k == '3') {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                    p2->money -= kanBuildingFee[kan][2];
                    printf("호텔을 건설하셨습니다. 현재소지 금액은 %d원 입니다.", p2->money);
                    kanOwner[kan] = 3;
                }
                else if (k == '4') {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                    p2->money -= kanBuildingFee[kan][0];
                    p2->money -= kanBuildingFee[kan][1];
                    printf("주택과 빌딩을 건설하셨습니다. 현재소지 금액은 %d원 입니다.", p2->money);
                    kanOwner[kan] = 4;
                }
                else if (k == '5') {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                    p2->money -= kanBuildingFee[kan][0];
                    p2->money -= kanBuildingFee[kan][2];
                    printf("주택과 호텔을 건설하셨습니다. 현재소지 금액은 %d원 입니다.", p2->money);
                    kanOwner[kan] = 5;
                }
                else if (k == '6') {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                    p2->money -= kanBuildingFee[kan][1];
                    p2->money -= kanBuildingFee[kan][2];
                    printf("빌딩과 호텔을 건설하셨습니다. 현재소지 금액은 %d원 입니다.", p2->money);
                    kanOwner[kan] = 6;
                }
                else if (k == '7') {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                    p2->money -= kanBuildingFee[kan][0];
                    p2->money -= kanBuildingFee[kan][1];
                    p2->money -= kanBuildingFee[kan][2];
                    printf("주택과 빌딩과 호텔을 건설하셨습니다. 현재소지 금액은 %d원 입니다.", p2->money);
                    kanOwner[kan] = 7;
                }
                else printf("건물을 건설하지 않았습니다. 현재소지 금액은 %d원 입니다.", p2->money);
            }
            printf("\n");
        }
        else if (player == 1) {
            printf("플레이어2의 땅에 걸렸습니다. 통행료가 지불됩니다.\n");
            p1->money -= kanFee[kan][kanOwner[kan]];
            p2->money += kanFee[kan][kanOwner[kan]];
            printf("플레이어 1의 소지금은 %d원\n플레이어 2의 소지금은 %d원 입니다.\n", p1->money, p2->money);
        }
        else if (player == 3) {
            printf("플레이어2의 땅에 걸렸습니다. 통행료가 지불됩니다.\n");
            p3->money -= kanFee[kan][kanOwner[kan]];
            p2->money += kanFee[kan][kanOwner[kan]];
            printf("플레이어 2의 소지금은 %d원\n플레이어 3의 소지금은 %d원 입니다.\n", p2->money, p3->money);
        }
        else if (player == 4) {
            printf("플레이어2의 땅에 걸렸습니다. 통행료가 지불됩니다.\n");
            p4->money -= kanFee[kan][kanOwner[kan]];
            p2->money += kanFee[kan][kanOwner[kan]];
            printf("플레이어 2의 소지금은 %d원\n플레이어 4의 소지금은 %d원 입니다.\n", p2->money, p4->money);
        }
    }
    else if (kanNumber[kan] == 3) {
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            printf("현재 소지금액은 %d원 입니다.\n", p3->money);
            if (player == 3) {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                printf("자신의 땅입니다.\n");
                if (kanOwner[kan] == 7) {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
                    printf("이미 최대로 건설되어 있습니다.\n");
                }
                else if (kanOwner[kan] == 3) {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
                    printf("추가로 호텔을 건설할 수 있습니다.\n호텔가격은 %d원 입니다.\n호텔을 건설하시길 원한다면 1번,건설하고 싶지 않으시면 다른 키를 눌러주세요\n", kanBuildingFee[kan][2]);
                    char k;
                    scanf("%c", &k);
                    if (k == '1') {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                        p3->money -= kanBuildingFee[kan][2];
                        printf("호텔을 건설하였습니다. 현재소지 금액은 %d원 입니다.", p3->money);
                        kanOwner[kan] = 7;
                    }
                    else {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                        printf("건물을 건설하지 않았습니다. 현재 소지 금액은 %d원 입니다.", p3->money);//건물 구매 가격,건물에 따른 토지료 정하기
                    }
                }
                else if (kanOwner[kan] == 5) {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
                    printf("추가로 빌딩을 건설할 수 있습니다.\n빌딩가격은 %d원 입니다.\n빌딩을 건설하시길 원한다면 1번, 건설하고 싶지 않으시다면 다른 키를 눌러주세요\n", kanBuildingFee[kan][1]);
                    char k;
                    scanf("%c", &k);
                    if (k == '1') {
                        p3->money -= kanBuildingFee[kan][1];
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                        printf("빌딩을 건설하였습니다. 현재소지 금액은 %d원 입니다.", p3->money);
                        kanOwner[kan] = 7;
                    }
                    else {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                        printf("건물을 건설하지 않았습니다. 현재 소지 금액은 %d원 입니다.", p3->money);//건물 구매 가격,건물에 따른 토지료 정하기
                    }
                }
                else if (kanOwner[kan] == 6) {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
                    printf("추가로 주택을 건설할 수 있습니다.\n주택가격은 %d원 입니다.\n주택을 건설하시길 원한다면 1번, 건설하고 싶지 않으시다면 다른 키를 눌러주세요\n", kanBuildingFee[kan][0]);
                    char k;
                    scanf("%c", &k);
                    if (k == '1') {
                        p3->money -= kanBuildingFee[kan][0];
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                        printf("주택을 건설하였습니다. 현재소지 금액은 %d원 입니다.", p3->money);
                        kanOwner[kan] = 7;
                    }
                    else {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                        printf("건물을 건설하지 않았습니다. 현재 소지 금액은 %d원 입니다.", p3->money);//건물 구매 가격,건물에 따른 토지료 정하기
                    }
                }
                else if (kanOwner[kan] == 4) {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
                    printf("추가로 주택과 빌딩을 건설할 수 있습니다.\n주택가격은 %d원 입니다. 빌딩가격은 %d원 입니다.\n주택만을 건설하시길 원한다면 1번, 빌딩만을 건설하시길 원한다면 2번, 주택과 빌딩을 건설하시길 원한다면 3번, 건설하고 싶지 않으시다면 다른 키를 눌러주세요\n", kanBuildingFee[kan][0], kanBuildingFee[kan][1]);
                    char k;
                    scanf("%c", &k);
                    if (k == '1') {
                        p3->money -= kanBuildingFee[kan][0];
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                        printf("주택을 건설하였습니다. 현재소지 금액은 %d원 입니다.", p3->money);
                        kanOwner[kan] = 5;
                    }
                    else if (k == '2') {
                        p3->money -= kanBuildingFee[kan][1];
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                        printf("빌딩을 건설하였습니다. 현재소지 금액은 %d원 입니다.", p3->money);
                        kanOwner[kan] = 6;
                    }
                    else if (k == '3') {
                        p3->money -= kanBuildingFee[kan][1];
                        p3->money -= kanBuildingFee[kan][0];
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                        printf("주택과 빌딩을 건설하였습니다. 현재소지 금액은 %d원입니다.", p3->money);
                        kanOwner[kan] = 7;
                    }
                    else {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                        printf("건물을 건설하지 않았습니다. 현재 소지 금액은 %d 원입니다.", p3->money);//건물 구매 가격,건물에 따른 토지료 정하기
                    }
                }
                else if (kanOwner[kan] == 2) {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
                    printf("추가로 주택과 호텔을 건설하실 수 있습니다. 주택의 가격은 %d원 입니다. 호텔의 가격은 %d원 입니다. \n주택만을 건설하시고 싶으시면 1번,호텔만을 건설하고 싶으시면 2번, 주택과 호텔을 건설하고 싶으시면 3번, 건설하고 싶지 않으시면 다른 키를 눌러주세요\n", kanBuildingFee[kan][0], kanBuildingFee[kan][2]);
                    char k;
                    scanf("%c", &k);
                    if (k == '1') {
                        p3->money -= kanBuildingFee[kan][0];
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                        printf("주택을 건설하였습니다. 현재소지 금액은 %d원 입니다.", p3->money);
                        kanOwner[kan] = 3;
                    }
                    else if (k == '2') {
                        p3->money -= kanBuildingFee[kan][2];
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                        printf("호텔을 건설하였습니다. 현재소지 금액은 %d원 입니다.", p3->money);
                        kanOwner[kan] = 6;
                    }
                    else if (k == '3') {
                        p3->money -= kanBuildingFee[kan][0];
                        p3->money -= kanBuildingFee[kan][2];
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                        printf("주택을 건설하였습니다. 현재소지 금액은 %d원 입니다.", p3->money);
                        kanOwner[kan] = 7;
                    }
                    else {
                        printf("건물을 건설하지 않았습니다. 현재소지 금액은 %d원 입니다.", p3->money);
                    }
                }
                else if (kanOwner[kan] == 1) {
                    printf("추가로 빌딩과 호텔을 건설하실 수 있습니다. 빌딩의 가격은 %d원 입니다. 호텔의 가격은 %d원 입니다. \n빌딩만을 구매하고 싶으시면 1번, 호텔만을 구매하고 싶으시면 2번, 빌딩과 호텔을 구매하고 싶으시면 3번, 구매하고 싶지 않으시면 다른 키를 눌러주세요\n", kanBuildingFee[kan][1], kanBuildingFee[kan][2]);
                    char k;
                    scanf("%c", &k);
                    if (k == '1') {
                        p3->money -= kanBuildingFee[kan][1];
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                        printf("빌딩을 건설하였습니다. 현재소지 금액은 %d원 입니다.", p3->money);
                        kanOwner[kan] = 3;
                    }
                    else if (k == '2') {
                        p3->money -= kanBuildingFee[kan][2];
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                        printf("호텔을 건설하였습니다. 현재소지 금액은 %d원 입니다.", p3->money);
                        kanOwner[kan] = 5;
                    }
                    else if (k == '3') {
                        p3->money -= kanBuildingFee[kan][1];
                        p3->money -= kanBuildingFee[kan][2];
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                        printf("빌딩과 호텔을 건설하였습니다. 현재소지 금액은 %d원 입니다.", p3->money);
                        kanOwner[kan] = 7;
                    }
                    else {
                        printf("건물을 건설하지 않았습니다. 현재소지 금액은 %d원 입니다.", p3->money);
                    }
                }
                else {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
                    printf("주택, 빌딩, 호텔을 건설하실 수 있습니다. 주택의 가격은 %d원 입니다. 빌딩의 가격은 %d원 입니다. 호텔의 가격은 %d원 입니다\n", kanBuildingFee[kan][0], kanBuildingFee[kan][1], kanBuildingFee[kan][2]);
                    printf("주택만을 건설하시고 싶으시면 1번, 빌딩만을 건설하시고 싶으시면 2번, 호텔만을 건설하시고 싶으시면 3번, 주택과 빌딩을 건설하시고 싶으시면 4번, 주택과 호텔을 건설하시고 싶으시면 5번, 빌딩과 호텔을 건설하시고 싶으시면 6번,주택과 빌딩과 호텔을 건설하시고 싶으시면 7번, 건설하시고 싶지 않으시면 다른 키를 눌러주세요");
                    char k;
                    scanf("%c", &k);
                    if (k == '1') {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                        p3->money -= kanBuildingFee[kan][0];
                        printf("주택을 건설하셨습니다. 현재소지 금액은 %d원 입니다.", p3->money);
                        kanOwner[kan] = 1;
                    }
                    else if (k == '2') {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                        p3->money -= kanBuildingFee[kan][1];
                        printf("빌딩을 건설하셨습니다. 현재소지 금액은 %d원 입니다.", p3->money);
                        kanOwner[kan] = 2;
                    }
                    else if (k == '3') {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                        p3->money -= kanBuildingFee[kan][2];
                        printf("호텔을 건설하셨습니다. 현재소지 금액은 %d원 입니다.", p3->money);
                        kanOwner[kan] = 3;
                    }
                    else if (k == '4') {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                        p3->money -= kanBuildingFee[kan][0];
                        p3->money -= kanBuildingFee[kan][1];
                        printf("주택과 빌딩을 건설하셨습니다. 현재소지 금액은 %d원 입니다.", p3->money);
                        kanOwner[kan] = 4;
                    }
                    else if (k == '5') {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                        p3->money -= kanBuildingFee[kan][0];
                        p3->money -= kanBuildingFee[kan][2];
                        printf("주택과 호텔을 건설하셨습니다. 현재소지 금액은 %d원 입니다.", p3->money);
                        kanOwner[kan] = 5;
                    }
                    else if (k == '6') {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                        p3->money -= kanBuildingFee[kan][1];
                        p3->money -= kanBuildingFee[kan][2];
                        printf("빌딩과 호텔을 건설하셨습니다. 현재소지 금액은 %d원 입니다.", p3->money);
                        kanOwner[kan] = 6;
                    }
                    else if (k == '7') {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                        p3->money -= kanBuildingFee[kan][0];
                        p3->money -= kanBuildingFee[kan][1];
                        p3->money -= kanBuildingFee[kan][2];
                        printf("주택과 빌딩과 호텔을 건설하셨습니다. 현재소지 금액은 %d원 입니다.", p3->money);
                        kanOwner[kan] = 7;
                    }
                    else printf("건물을 건설하지 않았습니다. 현재소지 금액은 %d원 입니다.", p3->money);
                }
                printf("\n");
            }
            else if (player == 1) {
                printf("플레이어3의 땅에 걸렸습니다. 통행료가 지불됩니다.\n");
                p1->money -= kanFee[kan][kanOwner[kan]];
                p3->money += kanFee[kan][kanOwner[kan]];
                printf("플레이어 1의 소지금은 %d원\n플레이어 3의 소지금은 %d원 입니다.\n", p1->money, p3->money);
            }
            else if (player == 2) {
                printf("플레이어3의 땅에 걸렸습니다. 통행료가 지불됩니다.\n");
                p2->money -= kanFee[kan][kanOwner[kan]];
                p3->money += kanFee[kan][kanOwner[kan]];
                printf("플레이어 2의 소지금은 %d원\n플레이어 3의 소지금은 %d원 입니다.\n", p2->money, p3->money);
            }
            else if (player == 4) {
                printf("플레이어3의 땅에 걸렸습니다. 통행료가 지불됩니다.\n");
                p4->money -= kanFee[kan][kanOwner[kan]];
                p3->money += kanFee[kan][kanOwner[kan]];
                printf("플레이어 3의 소지금은 %d원\n플레이어 4의 소지금은 %d원 입니다.\n", p3->money, p4->money);
            }
        }
    }
    else if (kanNumber[kan] == 4) {
        {
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                printf("현재 소지금액은 %d원 입니다.\n", p4->money);
                if (player == 4) {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                    printf("자신의 땅입니다.\n");
                    if (kanOwner[kan] == 7) {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
                        printf("이미 최대로 건설되어 있습니다.\n");
                    }
                    else if (kanOwner[kan] == 3) {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
                        printf("추가로 호텔을 건설할 수 있습니다.\n호텔가격은 %d원 입니다.\n호텔을 건설하시길 원한다면 1번,건설하고 싶지 않으시면 다른 키를 눌러주세요\n", kanBuildingFee[kan][2]);
                        char k;
                        scanf("%c", &k);
                        if (k == '1') {
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                            p4->money -= kanBuildingFee[kan][2];
                            printf("호텔을 건설하였습니다. 현재소지 금액은 %d원 입니다.", p4->money);
                            kanOwner[kan] = 7;
                        }
                        else {
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                            printf("건물을 건설하지 않았습니다. 현재 소지 금액은 %d원 입니다.", p4->money);//건물 구매 가격,건물에 따른 토지료 정하기
                        }
                    }
                    else if (kanOwner[kan] == 5) {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
                        printf("추가로 빌딩을 건설할 수 있습니다.\n빌딩가격은 %d원 입니다.\n빌딩을 건설하시길 원한다면 1번, 건설하고 싶지 않으시다면 다른 키를 눌러주세요\n", kanBuildingFee[kan][1]);
                        char k;
                        scanf("%c", &k);
                        if (k == '1') {
                            p4->money -= kanBuildingFee[kan][1];
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                            printf("빌딩을 건설하였습니다. 현재소지 금액은 %d원 입니다.", p4->money);
                            kanOwner[kan] = 7;
                        }
                        else {
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                            printf("건물을 건설하지 않았습니다. 현재 소지 금액은 %d원 입니다.", p4->money);//건물 구매 가격,건물에 따른 토지료 정하기
                        }
                    }
                    else if (kanOwner[kan] == 6) {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
                        printf("추가로 주택을 건설할 수 있습니다.\n주택가격은 %d원 입니다.\n주택을 건설하시길 원한다면 1번, 건설하고 싶지 않으시다면 다른 키를 눌러주세요\n", kanBuildingFee[kan][0]);
                        char k;
                        scanf("%c", &k);
                        if (k == '1') {
                            p4->money -= kanBuildingFee[kan][0];
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                            printf("주택을 건설하였습니다. 현재소지 금액은 %d원 입니다.", p4->money);
                            kanOwner[kan] = 7;
                        }
                        else {
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                            printf("건물을 건설하지 않았습니다. 현재 소지 금액은 %d원 입니다.", p4->money);//건물 구매 가격,건물에 따른 토지료 정하기
                        }
                    }
                    else if (kanOwner[kan] == 4) {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
                        printf("추가로 주택과 빌딩을 건설할 수 있습니다.\n주택가격은 %d원 입니다. 빌딩가격은 %d원 입니다.\n주택만을 건설하시길 원한다면 1번, 빌딩만을 건설하시길 원한다면 2번, 주택과 빌딩을 건설하시길 원한다면 3번, 건설하고 싶지 않으시다면 다른 키를 눌러주세요\n", kanBuildingFee[kan][0], kanBuildingFee[kan][1]);
                        char k;
                        scanf("%c", &k);
                        if (k == '1') {
                            p4->money -= kanBuildingFee[kan][0];
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                            printf("주택을 건설하였습니다. 현재소지 금액은 %d원 입니다.", p4->money);
                            kanOwner[kan] = 5;
                        }
                        else if (k == '2') {
                            p4->money -= kanBuildingFee[kan][1];
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                            printf("빌딩을 건설하였습니다. 현재소지 금액은 %d원 입니다.", p4->money);
                            kanOwner[kan] = 6;
                        }
                        else if (k == '3') {
                            p4->money -= kanBuildingFee[kan][1];
                            p4->money -= kanBuildingFee[kan][0];
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                            printf("주택과 빌딩을 건설하였습니다. 현재소지 금액은 %d원입니다.", p4->money);
                            kanOwner[kan] = 7;
                        }
                        else {
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                            printf("건물을 건설하지 않았습니다. 현재 소지 금액은 %d 원입니다.", p4->money);//건물 구매 가격,건물에 따른 토지료 정하기
                        }
                    }
                    else if (kanOwner[kan] == 2) {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
                        printf("추가로 주택과 호텔을 건설하실 수 있습니다. 주택의 가격은 %d원 입니다. 호텔의 가격은 %d원 입니다. \n주택만을 건설하시고 싶으시면 1번,호텔만을 건설하고 싶으시면 2번, 주택과 호텔을 건설하고 싶으시면 3번, 건설하고 싶지 않으시면 다른 키를 눌러주세요\n", kanBuildingFee[kan][0], kanBuildingFee[kan][2]);
                        char k;
                        scanf("%c", &k);
                        if (k == '1') {
                            p4->money -= kanBuildingFee[kan][0];
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                            printf("주택을 건설하였습니다. 현재소지 금액은 %d원 입니다.", p4->money);
                            kanOwner[kan] = 3;
                        }
                        else if (k == '2') {
                            p4->money -= kanBuildingFee[kan][2];
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                            printf("호텔을 건설하였습니다. 현재소지 금액은 %d원 입니다.", p4->money);
                            kanOwner[kan] = 6;
                        }
                        else if (k == '3') {
                            p4->money -= kanBuildingFee[kan][0];
                            p4->money -= kanBuildingFee[kan][2];
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                            printf("주택을 건설하였습니다. 현재소지 금액은 %d원 입니다.", p4->money);
                            kanOwner[kan] = 7;
                        }
                        else {
                            printf("건물을 건설하지 않았습니다. 현재소지 금액은 %d원 입니다.", p4->money);
                        }
                    }
                    else if (kanOwner[kan] == 1) {
                        printf("추가로 빌딩과 호텔을 건설하실 수 있습니다. 빌딩의 가격은 %d원 입니다. 호텔의 가격은 %d원 입니다. \n빌딩만을 구매하고 싶으시면 1번, 호텔만을 구매하고 싶으시면 2번, 빌딩과 호텔을 구매하고 싶으시면 3번, 구매하고 싶지 않으시면 다른 키를 눌러주세요\n", kanBuildingFee[kan][1], kanBuildingFee[kan][2]);
                        char k;
                        scanf("%c", &k);
                        if (k == '1') {
                            p4->money -= kanBuildingFee[kan][1];
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                            printf("빌딩을 건설하였습니다. 현재소지 금액은 %d원 입니다.", p4->money);
                            kanOwner[kan] = 3;
                        }
                        else if (k == '2') {
                            p4->money -= kanBuildingFee[kan][2];
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                            printf("호텔을 건설하였습니다. 현재소지 금액은 %d원 입니다.", p4->money);
                            kanOwner[kan] = 5;
                        }
                        else if (k == '3') {
                            p4->money -= kanBuildingFee[kan][1];
                            p4->money -= kanBuildingFee[kan][2];
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                            printf("빌딩과 호텔을 건설하였습니다. 현재소지 금액은 %d원 입니다.", p4->money);
                            kanOwner[kan] = 7;
                        }
                        else {
                            printf("건물을 건설하지 않았습니다. 현재소지 금액은 %d원 입니다.", p4->money);
                        }
                    }
                    else {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
                        printf("주택, 빌딩, 호텔을 건설하실 수 있습니다. 주택의 가격은 %d원 입니다. 빌딩의 가격은 %d원 입니다. 호텔의 가격은 %d원 입니다\n", kanBuildingFee[kan][0], kanBuildingFee[kan][1], kanBuildingFee[kan][2]);
                        printf("주택만을 건설하시고 싶으시면 1번, 빌딩만을 건설하시고 싶으시면 2번, 호텔만을 건설하시고 싶으시면 3번, 주택과 빌딩을 건설하시고 싶으시면 4번, 주택과 호텔을 건설하시고 싶으시면 5번, 빌딩과 호텔을 건설하시고 싶으시면 6번,주택과 빌딩과 호텔을 건설하시고 싶으시면 7번, 건설하시고 싶지 않으시면 다른 키를 눌러주세요");
                        char k;
                        scanf("%c", &k);
                        if (k == '1') {
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                            p4->money -= kanBuildingFee[kan][0];
                            printf("주택을 건설하셨습니다. 현재소지 금액은 %d원 입니다.", p4->money);
                            kanOwner[kan] = 1;
                        }
                        else if (k == '2') {
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                            p4->money -= kanBuildingFee[kan][1];
                            printf("빌딩을 건설하셨습니다. 현재소지 금액은 %d원 입니다.", p4->money);
                            kanOwner[kan] = 2;
                        }
                        else if (k == '3') {
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                            p4->money -= kanBuildingFee[kan][2];
                            printf("호텔을 건설하셨습니다. 현재소지 금액은 %d원 입니다.", p4->money);
                            kanOwner[kan] = 3;
                        }
                        else if (k == '4') {
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                            p4->money -= kanBuildingFee[kan][0];
                            p4->money -= kanBuildingFee[kan][1];
                            printf("주택과 빌딩을 건설하셨습니다. 현재소지 금액은 %d원 입니다.", p4->money);
                            kanOwner[kan] = 4;
                        }
                        else if (k == '5') {
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                            p4->money -= kanBuildingFee[kan][0];
                            p4->money -= kanBuildingFee[kan][2];
                            printf("주택과 호텔을 건설하셨습니다. 현재소지 금액은 %d원 입니다.", p4->money);
                            kanOwner[kan] = 5;
                        }
                        else if (k == '6') {
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                            p4->money -= kanBuildingFee[kan][1];
                            p4->money -= kanBuildingFee[kan][2];
                            printf("빌딩과 호텔을 건설하셨습니다. 현재소지 금액은 %d원 입니다.", p4->money);
                            kanOwner[kan] = 6;
                        }
                        else if (k == '7') {
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                            p4->money -= kanBuildingFee[kan][0];
                            p4->money -= kanBuildingFee[kan][1];
                            p4->money -= kanBuildingFee[kan][2];
                            printf("주택과 빌딩과 호텔을 건설하셨습니다. 현재소지 금액은 %d원 입니다.", p4->money);
                            kanOwner[kan] = 7;
                        }
                        else printf("건물을 건설하지 않았습니다. 현재소지 금액은 %d원 입니다.", p4->money);
                    }
                    printf("\n");
                }
                else if (player == 1) {
                    printf("플레이어4의 땅에 걸렸습니다. 통행료가 지불됩니다.\n");
                    p1->money -= kanFee[kan][kanOwner[kan]];
                    p4->money += kanFee[kan][kanOwner[kan]];
                    printf("플레이어 1의 소지금은 %d원\n플레이어 4의 소지금은 %d원 입니다.\n", p1->money, p4->money);
                }
                else if (player == 2) {
                    printf("플레이어4의 땅에 걸렸습니다. 통행료가 지불됩니다.\n");
                    p2->money -= kanFee[kan][kanOwner[kan]];
                    p4->money += kanFee[kan][kanOwner[kan]];
                    printf("플레이어 2의 소지금은 %d원\n플레이어 4의 소지금은 %d원 입니다.\n", p2->money, p4->money);
                }
                else if (player == 3) {
                    printf("플레이어4의 땅에 걸렸습니다. 통행료가 지불됩니다.\n");
                    p3->money -= kanFee[kan][kanOwner[kan]];
                    p4->money += kanFee[kan][kanOwner[kan]];
                    printf("플레이어 3의 소지금은 %d원\n플레이어 4의 소지금은 %d원 입니다.\n", p3->money, p4->money);
                }
            }
        }
    }
    else if (kan == 10) {
        printf("무인도에 오셨습니다.\n세턴이 지나거나 더블이 나올시 탈출하실 수 있습니다.\n");
        if (player == 1) p1->turn++;
        else if (player == 2) p2->turn++;
        else if (player == 3) p3->turn++;
        else if (player == 4) p4->turn++;
    }
    else if (kan == 20) {
        printf("사회복지기금 접수처에 걸리셨습니다.\n지금까지 접수된 사회복지기금을 수령하실 수 있습니다.\n");
        if (player == 1) p1->money += kanFee[20][0];
        else if (player == 2) p2->money += kanFee[20][0];
        else if (player == 3) p3->money += kanFee[20][0];
        else if (player == 4) p4->money += kanFee[20][0];
        kanFee[20][0] = 0;
    }
    else if (kan == 30) {
        printf("우주정거장에 걸리셨습니다.\n컬럼비아호 주인이 있을시 통행료를 내고 우주비행을 하실 수 있습니다.\n");
        if (player == 1) {
            if (kanNumber[32] == 2) {
                printf("컬럼비아호의 주인이 있습니다. 통행료를 지불합니다.\n");
                p1->money -= 200000;
                p2->money += 200000;
                printf("플레이어1의 소지금은 %d원 플레이어 2의 소지금은 %d원 입니다.\n", p1->money, p2->money);
            }
            else if (kanNumber[32] == 3) {
                printf("컬럼비아호의 주인이 있습니다. 통행료를 지불합니다.\n");
                p1->money -= 200000;
                p3->money += 200000;
                printf("플레이어1의 소지금은 %d원 플레이어 3의 소지금은 %d원 입니다.\n", p1->money, p3->money);
            }
            else if (kanNumber[32] == 4) {
                printf("컬럼비아호의 주인이 있습니다. 통행료를 지불합니다.\n");
                p1->money -= 200000;
                p4->money += 200000;
                printf("플레이어1의 소지금은 %d원 플레이어 4의 소지금은 %d원 입니다.\n", p1->money, p4->money);
            }
            p1->space = 1;
        }
        else if (player == 2) {
            if (kanNumber[32] == 1) {
                printf("컬럼비아호의 주인이 있습니다. 통행료를 지불합니다.\n");
                p2->money -= 200000;
                p1->money += 200000;
                printf("플레이어1의 소지금은 %d원 플레이어 2의 소지금은 %d원 입니다.\n", p1->money, p2->money);
            }
            else if (kanNumber[32] == 3) {
                printf("컬럼비아호의 주인이 있습니다. 통행료를 지불합니다.\n");
                p2->money -= 200000;
                p3->money += 200000;
                printf("플레이어2의 소지금은 %d원 플레이어 3의 소지금은 %d원 입니다.\n", p2->money, p3->money);
            }
            else if (kanNumber[32] == 4) {
                printf("컬럼비아호의 주인이 있습니다. 통행료를 지불합니다.\n");
                p2->money -= 200000;
                p4->money += 200000;
                printf("플레이어2의 소지금은 %d원 플레이어 4의 소지금은 %d원 입니다.\n", p2->money, p4->money);
            }
            p2->space = 1;
        }
        else if (player == 3) {
            if (kanNumber[32] == 2) {
                printf("컬럼비아호의 주인이 있습니다. 통행료를 지불합니다.\n");
                p3->money -= 200000;
                p2->money += 200000;
                printf("플레이어2의 소지금은 %d원 플레이어 3의 소지금은 %d원 입니다.\n", p2->money, p3->money);
            }
            else if (kanNumber[32] == 1) {
                printf("컬럼비아호의 주인이 있습니다. 통행료를 지불합니다.\n");
                p3->money -= 200000;
                p1->money += 200000;
                printf("플레이어1의 소지금은 %d원 플레이어 3의 소지금은 %d원 입니다.\n", p1->money, p3->money);
            }
            else if (kanNumber[32] == 4) {
                printf("컬럼비아호의 주인이 있습니다. 통행료를 지불합니다.\n");
                p3->money -= 200000;
                p4->money += 200000;
                printf("플레이어1의 소지금은 %d원 플레이어 3의 소지금은 %d원 입니다.\n", p1->money, p3->money);
            }
            p3->space = 1;
        }
        else if (player == 4) {
            if (kanNumber[32] == 2) {
                printf("컬럼비아호의 주인이 있습니다. 통행료를 지불합니다.\n");
                p4->money -= 200000;
                p2->money += 200000;
                printf("플레이어2의 소지금은 %d원 플레이어 4의 소지금은 %d원 입니다.\n", p2->money, p4->money);
            }
            else if (kanNumber[32] == 3) {
                printf("컬럼비아호의 주인이 있습니다. 통행료를 지불합니다.\n");
                p4->money -= 200000;
                p3->money += 200000;
                printf("플레이어3의 소지금은 %d원 플레이어 4의 소지금은 %d원 입니다.\n", p3->money, p4->money);
            }
            else if (kanNumber[32] == 1) {
                printf("컬럼비아호의 주인이 있습니다. 통행료를 지불합니다.\n");
                p4->money -= 200000;
                p1->money += 200000;
                printf("플레이어1의 소지금은 %d원 플레이어 4의 소지금은 %d원 입니다.\n", p1->money, p4->money);
            }
            p4->space = 1;
        }
    }
    else if (kan == 38) {
        printf("사회복지기금 접수처에 걸리셨습니다. 15만원을 접수합니다.\n");
        if (player == 1) p1->money -= 150000;
        else if (player == 2) p2->money -= 150000;
        else if (player == 3) p3->money -= 150000;
        else if (player == 4) p4->money -= 150000;
        kanFee[20][0] += 150000;
    }
    else if (kan == 2 || kan == 7 || kan == 12 || kan == 17 || kan == 22 || kan == 35) {
        printf("황금열쇠 칸에 도착하셨습니다.\n황금열쇠를 하나 뽑습니다.\n");
        if (player == 1) goldNumber[1] = 1;
        else if (player == 2) goldNumber[2] = 1;
        else if (player == 3) goldNumber[3] = 1;
        else if (player == 4) goldNumber[4] = 1;
    }
}
int dice() {
    srand(time(NULL));
    int a = rand();
    int b;
    b = a % 36;
    if (b == 0) return 2;
    else if (b <= 2) return 3;
    else if (b <= 5) return 4;
    else if (b <= 9) return 5;
    else if (b <= 14) return 6;
    else if (b <= 20) return 7;
    else if (b <= 25) return 8;
    else if (b <= 29) return 9;
    else if (b <= 32) return 10;
    else if (b <= 34) return 11;
    else if (b <= 35) return 12;
    else {
        printf("오류가 발생했습니다.\n주사위를 다시돌리겠습니다.");
        return -1;
    }
}

void print1() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
    printf("│");
}
void print2(int p1, int p2, int p3, int p4, int a) {
    if (p1 >= 40) p1 -= 40;
    if (p2 >= 40) p2 -= 40;
    if (p3 >= 40) p3 -= 40;
    if (p4 >= 40) p4 -= 40;
    if (p1 != a) {
        if (p2 != a) {
            if (p3 != a) {
                if (p4 != a) printf("          ");
                else printf("       4  ");
            }
            else {
                if (p4 != a) printf("      3   ");
                else printf("      34  ");
            }
        }
        else {
            if (p3 != a) {
                if (p4 != a) printf("   2      ");
                else printf("   2   4  ");
            }
            else {
                if (p4 != a) printf("   2  3   ");
                else printf("   2  34  ");
            }
        }
    }
    else {
        if (p2 != a) {
            if (p3 != a) {
                if (p4 != a) printf("  1       ");
                else printf("  1    4  ");
            }
            else {
                if (p4 != a) printf("  1   3   ");
                else printf("  1   34  ");
            }
        }
        else {
            if (p3 != a) {
                if (p4 != a) printf("  12      ");
                else printf("  12   4  ");
            }
            else {
                if (p4 != a) printf("  12  3   ");
                else printf("  12  34  ");
            }
        }
    }
}

void map(int p1, int p2, int p3, int p4) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
    printf("┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐\n");
    print1();
    printf(" 사회복지 ");
    print1();
    printf(" 부에노스 ");
    print1();
    printf(" 황금열쇠 ");
    print1();
    printf(" 상파울로 ");
    print1();
    printf("  시드니  ");
    print1();
    printf("   부산   ");
    print1();
    printf("  하와이  ");
    print1();
    printf("  리스본  ");
    print1();
    printf(" 퀸 엘리자");
    print1();
    printf(" 마드리드 ");
    print1();
    printf(" 우주여행 ");
    print1();
    printf("\n");
    print1();
    printf("기금수령처");
    print1();
    printf(" 아이레스 ");
    print1();
    printf("          ");
    print1();
    printf("          ");
    print1();
    printf("          ");
    print1();
    printf("          ");
    print1();
    printf("          ");
    print1();
    printf("          ");
    print1();
    printf("  베스 호 ");
    print1();
    printf("          ");
    print1();
    printf("          ");
    print1();
    printf("\n");
    print1();
    printf("          ");
    print1();
    printf("     %d    ", kanNumber[21]);
    print1();
    printf("          ");
    print1();
    printf("     %d    ", kanNumber[23]);
    print1();
    printf("     %d    ", kanNumber[24]);
    print1();
    printf("     %d    ", kanNumber[25]);
    print1();
    printf("     %d    ", kanNumber[26]);
    print1();
    printf("     %d    ", kanNumber[27]);
    print1();
    printf("     %d    ", kanNumber[28]);
    print1();
    printf("     %d    ", kanNumber[29]);
    print1();
    printf("          ");
    print1();
    printf("\n");
    print1();
    printf("  %4d천  ", kanFee[20][0] / 1000);
    print1();
    printf("  %4d천  ", kanNumber[21] != 0 ? kanFee[21][kanOwner[21]] / 1000 : kanPrice[21] / 1000);
    print1();
    printf("          ");
    print1();
    printf("  %4d천  ", kanNumber[23] != 0 ? kanFee[23][kanOwner[23]] / 1000 : kanPrice[23] / 1000);
    print1();
    printf("  %4d천  ", kanNumber[24] != 0 ? kanFee[24][kanOwner[24]] / 1000 : kanPrice[24] / 1000);
    print1();
    printf("  %4d천  ", kanNumber[25] != 0 ? kanFee[25][kanOwner[25]] / 1000 : kanPrice[25] / 1000);
    print1();
    printf("  %4d천  ", kanNumber[26] != 0 ? kanFee[26][kanOwner[26]] / 1000 : kanPrice[26] / 1000);
    print1();
    printf("  %4d천  ", kanNumber[27] != 0 ? kanFee[27][kanOwner[27]] / 1000 : kanPrice[27] / 1000);
    print1();
    printf("  %4d천  ", kanNumber[28] != 0 ? kanFee[28][kanOwner[28]] / 1000 : kanPrice[28] / 1000);
    print1();
    printf("  %4d천  ", kanNumber[29] != 0 ? kanFee[29][kanOwner[29]] / 1000 : kanPrice[29] / 1000);
    print1();
    printf("  %4d천  ", kanNumber[32] != 0 ? 200 : 0);
    print1();
    printf("\n");
    print1();
    printf("          ");
    print1();
    printf("  %s  ", kanOwner[21] == 0 ? "      " : kanOwner[21] == 1 ? " □   " : kanOwner[21] == 2 ? "  ○  " : kanOwner[21] == 3 ? " □○ " : kanOwner[21] == 4 ? "   ◈ " : kanOwner[21] == 5 ? " □ ◈" : kanOwner[21] == 6 ? " ○◈ " : "□○◈");
    print1();
    printf("          ");
    print1();
    printf("  %s  ", kanOwner[23] == 0 ? "      " : kanOwner[23] == 1 ? " □   " : kanOwner[23] == 2 ? "  ○  " : kanOwner[23] == 3 ? " □○ " : kanOwner[23] == 4 ? "   ◈ " : kanOwner[23] == 5 ? " □ ◈" : kanOwner[23] == 6 ? " ○◈ " : "□○◈");
    print1();
    printf("  %s  ", kanOwner[24] == 0 ? "      " : kanOwner[24] == 1 ? " □   " : kanOwner[24] == 2 ? "  ○  " : kanOwner[24] == 3 ? " □○ " : kanOwner[24] == 4 ? "   ◈ " : kanOwner[24] == 5 ? " □ ◈" : kanOwner[24] == 6 ? " ○◈ " : "□○◈");
    print1();
    printf("          ");
    print1();
    printf("  %s  ", kanOwner[26] == 0 ? "      " : kanOwner[26] == 1 ? " □   " : kanOwner[26] == 2 ? "  ○  " : kanOwner[26] == 3 ? " □○ " : kanOwner[26] == 4 ? "   ◈ " : kanOwner[26] == 5 ? " □ ◈" : kanOwner[26] == 6 ? " ○◈ " : "□○◈");
    print1();
    printf("  %s  ", kanOwner[27] == 0 ? "      " : kanOwner[27] == 1 ? " □   " : kanOwner[27] == 2 ? "  ○  " : kanOwner[27] == 3 ? " □○ " : kanOwner[27] == 4 ? "   ◈ " : kanOwner[27] == 5 ? " □ ◈" : kanOwner[27] == 6 ? " ○◈ " : "□○◈");
    print1();
    printf("  %s  ", kanOwner[28] == 0 ? "      " : kanOwner[28] == 1 ? " □   " : kanOwner[28] == 2 ? "  ○  " : kanOwner[28] == 3 ? " □○ " : kanOwner[28] == 4 ? "   ◈ " : kanOwner[28] == 5 ? " □ ◈" : kanOwner[28] == 6 ? " ○◈ " : "□○◈");
    print1();
    printf("  %s  ", kanOwner[29] == 0 ? "      " : kanOwner[29] == 1 ? " □   " : kanOwner[29] == 2 ? "  ○  " : kanOwner[29] == 3 ? " □○ " : kanOwner[29] == 4 ? "   ◈ " : kanOwner[29] == 5 ? " □ ◈" : kanOwner[29] == 6 ? " ○◈ " : "□○◈");
    print1();
    printf("          ");
    print1();
    printf("\n");
    print1();
    print2(p1, p2, p3, p4, 20);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
    print1();
    print2(p1, p2, p3, p4, 21);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
    print1();
    print2(p1, p2, p3, p4, 22);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
    print1();
    print2(p1, p2, p3, p4, 23);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
    print1();
    print2(p1, p2, p3, p4, 24);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
    print1();
    print2(p1, p2, p3, p4, 25);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
    print1();
    print2(p1, p2, p3, p4, 26);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
    print1();
    print2(p1, p2, p3, p4, 27);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
    print1();
    print2(p1, p2, p3, p4, 28);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
    print1();
    print2(p1, p2, p3, p4, 29);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
    print1();
    print2(p1, p2, p3, p4, 30);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
    print1();
    printf("\n");
    printf("├──────────┼──────────┴──────────┴──────────┴──────────┴──────────┴──────────┴──────────┴──────────┴──────────╋──────────┤\n");
    print1();
    printf("  오타와  ");
    print1();
    printf("                                                                                                  ");
    print1();
    printf("   도쿄   ");
    print1();
    printf("\n");
    printf("│          │                                                                                                  │          │\n");
    print1();
    printf("    %d     ", kanNumber[19]);
    printf("│                                                                                                  │");
    printf("    %d     ", kanNumber[31]);
    print1();
    printf("\n");
    print1();
    printf("  %4d천  ", kanNumber[19] != 0 ? kanFee[19][kanOwner[19]] / 1000 : kanPrice[19] / 1000);
    printf("│                                                                                                  │");
    printf("  %4d천  ", kanNumber[31] != 0 ? kanFee[31][kanOwner[31]] / 1000 : kanPrice[31] / 1000);
    print1();
    printf("\n");
    print1();
    printf("  %s  ", kanOwner[19] == 0 ? "      " : kanOwner[19] == 1 ? " □   " : kanOwner[19] == 2 ? "  ○  " : kanOwner[19] == 3 ? " □○ " : kanOwner[19] == 4 ? "   ◈ " : kanOwner[19] == 5 ? " □ ◈" : kanOwner[19] == 6 ? " ○◈ " : "□○◈");
    printf("│                                                                                                  │");
    printf("  %s  ", kanOwner[31] == 0 ? "      " : kanOwner[31] == 1 ? " □   " : kanOwner[31] == 2 ? "  ○  " : kanOwner[31] == 3 ? " □○ " : kanOwner[31] == 4 ? "   ◈ " : kanOwner[31] == 5 ? " □ ◈" : kanOwner[31] == 6 ? " ○◈ " : "□○◈");
    print1();
    printf("\n");
    print1();
    print2(p1, p2, p3, p4, 19);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
    printf("│                                                                                                  │");
    print2(p1, p2, p3, p4, 31);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
    print1();
    printf("\n");
    printf("├──────────┤                                                                                                  ├──────────┤\n");
    print1();
    printf("  배를린  ");
    printf("│                                                                                                  │");
    printf("컬럼비아호");
    print1();
    printf("\n");
    printf("│          │                                                                                                  │          │\n");
    print1();
    printf("    %d     ", kanNumber[18]);
    printf("│                                                                                                  │");
    printf("    %d     ", kanNumber[32]);
    print1();
    printf("\n");
    print1();
    printf("  %4d천  ", kanNumber[18] != 0 ? kanFee[18][kanOwner[18]] / 1000 : kanPrice[18] / 1000);
    printf("│                                                                                                  │");
    printf("  %4d천  ", kanNumber[32] != 0 ? kanFee[32][kanOwner[32]] / 1000 : kanPrice[32] / 1000);
    print1();
    printf("\n");
    print1();
    printf("  %s  ", kanOwner[18] == 0 ? "      " : kanOwner[18] == 1 ? " □   " : kanOwner[18] == 2 ? "  ○  " : kanOwner[18] == 3 ? " □○ " : kanOwner[18] == 4 ? "   ◈ " : kanOwner[18] == 5 ? " □ ◈" : kanOwner[18] == 6 ? " ○◈ " : "□○◈");
    printf("│                                                                                                  │");
    printf("          ");
    print1();
    printf("\n");
    print1();
    print2(p1, p2, p3, p4, 18);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
    printf("│                                                                                                  │");
    print2(p1, p2, p3, p4, 32);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
    print1();
    printf("\n");
    printf("├──────────┤                                                                                                  ├──────────┤\n");
    print1();
    printf(" 황금열쇠 ");
    printf("│                                                                                                  │");
    printf("   파리   ");
    print1();
    printf("\n");
    printf("│          │                                                                                                  │          │\n");
    print1();
    printf("          ");
    printf("│                                                                                                  │");
    printf("    %d     ", kanNumber[33]);
    print1();
    printf("\n");
    print1();
    printf("          ");
    printf("│                                                                                                  │");
    printf("  %4d천  ", kanNumber[33] != 0 ? kanFee[33][kanOwner[33]] / 1000 : kanPrice[33] / 1000);
    print1();
    printf("\n");
    print1();
    printf("          ");
    printf("│                                                                                                  │");
    printf("  %s  ", kanOwner[33] == 0 ? "      " : kanOwner[33] == 1 ? " □   " : kanOwner[33] == 2 ? "  ○  " : kanOwner[33] == 3 ? " □○ " : kanOwner[33] == 4 ? "   ◈ " : kanOwner[33] == 5 ? " □ ◈" : kanOwner[33] == 6 ? " ○◈ " : "□○◈");
    print1();
    printf("\n");
    print1();
    print2(p1, p2, p3, p4, 17);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
    printf("│                                                                                                  │");
    print2(p1, p2, p3, p4, 33);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
    print1();
    printf("\n");
    printf("├──────────┤                                                                                                  ├──────────┤\n");
    print1();
    printf("   배른   ");
    printf("│                                                                                                  │");
    printf("   로마   ");
    print1();
    printf("\n");
    printf("│          │                                                                                                  │          │\n");
    print1();
    printf("    %d     ", kanNumber[16]);
    printf("│                                                                                                  │");
    printf("    %d     ", kanNumber[34]);
    print1();
    printf("\n");
    print1();
    printf("  %4d천  ", kanNumber[16] != 0 ? kanFee[16][kanOwner[16]] / 1000 : kanPrice[16] / 1000);
    printf("│                                                                                                  │");
    printf("  %4d천  ", kanNumber[34] != 0 ? kanFee[34][kanOwner[34]] / 1000 : kanPrice[34] / 1000);
    print1();
    printf("\n");
    print1();
    printf("  %s  ", kanOwner[16] == 0 ? "      " : kanOwner[16] == 1 ? " □   " : kanOwner[16] == 2 ? "  ○  " : kanOwner[16] == 3 ? " □○ " : kanOwner[16] == 4 ? "   ◈ " : kanOwner[16] == 5 ? " □ ◈" : kanOwner[16] == 6 ? " ○◈ " : "□○◈");
    printf("│                                                                                                  │");
    printf("  %s  ", kanOwner[34] == 0 ? "      " : kanOwner[34] == 1 ? " □   " : kanOwner[34] == 2 ? "  ○  " : kanOwner[34] == 3 ? " □○ " : kanOwner[34] == 4 ? "   ◈ " : kanOwner[34] == 5 ? " □ ◈" : kanOwner[34] == 6 ? " ○◈ " : "□○◈");
    print1();
    printf("\n");
    print1();
    print2(p1, p2, p3, p4, 16);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
    printf("│                                                                                                  │");
    print2(p1, p2, p3, p4, 34);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
    print1();
    printf("\n");
    printf("├──────────┤                                                                                                  ├──────────┤\n");
    print1();
    printf("  콩코드  ");
    printf("│                                                                                                  │");
    printf(" 황금열쇠 ");
    print1();
    printf("\n");
    printf("│  여객기  │                                                                                                  │          │\n");
    print1();
    printf("    %d     ", kanNumber[15]);
    printf("│                                                                                                  │");
    printf("          ");
    print1();
    printf("\n");
    print1();
    printf("  %4d천  ", kanNumber[15] != 0 ? kanFee[15][kanOwner[15]] / 1000 : kanPrice[15] / 1000);
    printf("│                                                                                                  │");
    printf("          ");
    print1();
    printf("\n");
    print1();
    printf("          ");
    printf("│                                                                                                  │");
    printf("          ");
    print1();
    printf("\n");
    print1();
    print2(p1, p2, p3, p4, 15);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
    printf("│                                                                                                  │");
    print2(p1, p2, p3, p4, 35);
    print1();
    printf("\n");
    printf("├──────────┤                                                                                                  ├──────────┤\n");
    print1();
    printf(" 스톡홀름 ");
    printf("│                                                                                                  │");
    printf("  런던    ");
    print1();
    printf("\n");
    printf("│          │                                                                                                  │          │\n");
    print1();
    printf("    %d     ", kanNumber[14]);
    printf("│                                                                                                  │");
    printf("    %d     ", kanNumber[36]);
    print1();
    printf("\n");
    print1();
    printf("  %4d천  ", kanNumber[14] != 0 ? kanFee[14][kanOwner[14]] / 1000 : kanPrice[14] / 1000);
    printf("│                                                                                                  │");
    printf("  %4d천  ", kanNumber[36] != 0 ? kanFee[36][kanOwner[36]] / 1000 : kanPrice[36] / 1000);
    print1();
    printf("\n");
    print1();
    printf("  %s  ", kanOwner[14] == 0 ? "      " : kanOwner[14] == 1 ? " □   " : kanOwner[14] == 2 ? "  ○  " : kanOwner[14] == 3 ? " □○ " : kanOwner[14] == 4 ? "   ◈ " : kanOwner[14] == 5 ? " □ ◈" : kanOwner[14] == 6 ? " ○◈ " : "□○◈");
    printf("│                                                                                                  │");
    printf("  %s  ", kanOwner[36] == 0 ? "      " : kanOwner[36] == 1 ? " □   " : kanOwner[36] == 2 ? "  ○  " : kanOwner[36] == 3 ? " □○ " : kanOwner[36] == 4 ? "   ◈ " : kanOwner[36] == 5 ? " □ ◈" : kanOwner[36] == 6 ? " ○◈ " : "□○◈");
    print1();
    printf("\n");
    print1();
    print2(p1, p2, p3, p4, 14);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
    printf("│                                                                                                  │");
    print2(p1, p2, p3, p4, 36);
    print1();
    printf("\n");
    printf("├──────────┤                                                                                                  ├──────────┤\n");
    print1();
    printf(" 코펜하겐 ");
    printf("│                                                                                                  │");
    printf("  뉴욕    ");
    print1();
    printf("\n");
    printf("│          │                                                                                                  │          │\n");
    print1();
    printf("    %d     ", kanNumber[13]);
    printf("│                                                                                                  │");
    printf("    %d     ", kanNumber[37]);
    print1();
    printf("\n");
    print1();
    printf("  %4d천  ", kanNumber[13] != 0 ? kanFee[13][kanOwner[13]] / 1000 : kanPrice[13] / 1000);
    printf("│                                                                                                  │");
    printf("  %4d천  ", kanNumber[37] != 0 ? kanFee[37][kanOwner[37]] / 1000 : kanPrice[37] / 1000);
    print1();
    printf("\n");
    print1();
    printf("  %s  ", kanOwner[13] == 0 ? "      " : kanOwner[13] == 1 ? " □   " : kanOwner[13] == 2 ? "  ○  " : kanOwner[13] == 3 ? " □○ " : kanOwner[13] == 4 ? "   ◈ " : kanOwner[13] == 5 ? " □ ◈" : kanOwner[13] == 6 ? " ○◈ " : "□○◈");
    printf("│                                                                                                  │");
    printf("  %s  ", kanOwner[37] == 0 ? "      " : kanOwner[37] == 1 ? " □   " : kanOwner[37] == 2 ? "  ○  " : kanOwner[37] == 3 ? " □○ " : kanOwner[37] == 4 ? "   ◈ " : kanOwner[37] == 5 ? " □ ◈" : kanOwner[37] == 6 ? " ○◈ " : "□○◈");
    print1();
    printf("\n");
    print1();
    print2(p1, p2, p3, p4, 13);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
    printf("│                                                                                                  │");
    print2(p1, p2, p3, p4, 37);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
    print1();
    printf("\n");
    printf("├──────────┤                                                                                                  ├──────────┤\n");
    print1();
    printf(" 황금열쇠 ");
    printf("│                                                                                                  │");
    printf(" 사회복지 ");
    print1();
    printf("\n");
    printf("│          │                                                                                                  │기금접수처│\n");
    print1();
    printf("          ");
    printf("│                                                                                                  │");
    printf("          ");
    print1();
    printf("\n");
    print1();
    printf("          ");
    printf("│                                                                                                  │");
    printf("   150천  ");
    print1();
    printf("\n");
    print1();
    printf("          ");
    printf("│                                                                                                  │");
    printf("          ");
    print1();
    printf("\n");
    print1();
    print2(p1, p2, p3, p4, 12);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
    printf("│                                                                                                  │");
    print2(p1, p2, p3, p4, 38);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
    print1();
    printf("\n");
    printf("├──────────┤                                                                                                  ├──────────┤\n");
    print1();
    printf("  아테네  ");
    printf("│                                                                                                  │");
    printf("  서울    ");
    print1();
    printf("\n");
    printf("│          │                                                                                                  │          │\n");
    print1();
    printf("    %d     ", kanNumber[11]);
    printf("│                                                                                                  │");
    printf("    %d     ", kanNumber[39]);
    print1();
    printf("\n");
    print1();
    printf("  %4d천  ", kanNumber[11] != 0 ? kanFee[11][kanOwner[11]] / 1000 : kanPrice[11] / 1000);
    printf("│                                                                                                  │");
    printf("  %4d천  ", kanNumber[39] != 0 ? kanFee[39][kanOwner[39]] / 1000 : kanPrice[39] / 1000);
    print1();
    printf("\n");
    print1();
    printf("  %s  ", kanOwner[11] == 0 ? "      " : kanOwner[11] == 1 ? " □   " : kanOwner[11] == 2 ? "  ○  " : kanOwner[11] == 3 ? " □○ " : kanOwner[11] == 4 ? "   ◈ " : kanOwner[11] == 5 ? " □ ◈" : kanOwner[11] == 6 ? " ○◈ " : "□○◈");
    printf("│                                                                                                  │");
    printf("  %s  ", kanOwner[39] == 0 ? "      " : kanOwner[39] == 1 ? " □   " : kanOwner[39] == 2 ? "  ○  " : kanOwner[39] == 3 ? " □○ " : kanOwner[39] == 4 ? "   ◈ " : kanOwner[39] == 5 ? " □ ◈" : kanOwner[39] == 6 ? " ○◈ " : "□○◈");
    print1();
    printf("\n");
    print1();
    print2(p1, p2, p3, p4, 11);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
    printf("│                                                                                                  │");
    print2(p1, p2, p3, p4, 39);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
    print1();
    printf("\n");
    printf("├──────────┼──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────╋──────────┤\n");
    print1();
    printf("  무인도  ");
    print1();
    printf(" 이스탄불 ");
    print1();
    printf("  카이로  ");
    print1();
    printf(" 황금열쇠 ");
    print1();
    printf(" 싱가포르 ");
    print1();
    printf("  제주도  ");
    print1();
    printf("  마닐라  ");
    print1();
    printf("  베이징  ");
    print1();
    printf(" 황금열쇠 ");
    print1();
    printf(" 타이베이 ");
    print1();
    printf("  출발    ");
    print1();
    printf("\n");
    print1();
    printf("          ");
    print1();
    printf("          ");
    print1();
    printf("          ");
    print1();
    printf("          ");
    print1();
    printf("          ");
    print1();
    printf("          ");
    print1();
    printf("          ");
    print1();
    printf("          ");
    print1();
    printf("          ");
    print1();
    printf("          ");
    print1();
    printf("    <-    ");
    print1();
    printf("\n");
    print1();
    printf("          ");
    print1();
    printf("    %d     ", kanNumber[9]);
    print1();
    printf("    %d     ", kanNumber[8]);
    print1();
    printf("          ");
    print1();
    printf("    %d     ", kanNumber[6]);
    print1();
    printf("    %d     ", kanNumber[5]);
    print1();
    printf("    %d     ", kanNumber[4]);
    print1();
    printf("    %d     ", kanNumber[3]);
    print1();
    printf("          ");
    print1();
    printf("    %d     ", kanNumber[1]);
    print1();
    printf("          ");
    print1();
    printf("\n");
    print1();
    printf("          ");
    print1();
    printf("  %4d천  ", kanNumber[9] != 0 ? kanFee[9][kanOwner[9]] / 1000 : kanPrice[9] / 1000);
    print1();
    printf("  %4d천  ", kanNumber[8] != 0 ? kanFee[8][kanOwner[8]] / 1000 : kanPrice[8] / 1000);
    print1();
    printf("          ");
    print1();
    printf("  %4d천  ", kanNumber[6] != 0 ? kanFee[6][kanOwner[6]] / 1000 : kanPrice[6] / 1000);
    print1();
    printf("  %4d천  ", kanNumber[5] != 0 ? kanFee[5][kanOwner[5]] / 1000 : kanPrice[5] / 1000);
    print1();
    printf("  %4d천  ", kanNumber[4] != 0 ? kanFee[4][kanOwner[4]] / 1000 : kanPrice[4] / 1000);
    print1();
    printf("  %4d천  ", kanNumber[3] != 0 ? kanFee[3][kanOwner[3]] / 1000 : kanPrice[3] / 1000);
    print1();
    printf("          ");
    print1();
    printf("  %4d천  ", kanNumber[1] != 0 ? kanFee[1][kanOwner[1]] / 1000 : kanPrice[1] / 1000);
    print1();
    printf("   200천  ");
    print1();
    printf("\n");
    print1();
    printf("          ");
    print1();
    printf("  %s  ", kanOwner[9] == 0 ? "      " : kanOwner[9] == 1 ? " □   " : kanOwner[9] == 2 ? "  ○  " : kanOwner[9] == 3 ? " □○ " : kanOwner[9] == 4 ? "   ◈ " : kanOwner[9] == 5 ? " □ ◈" : kanOwner[9] == 6 ? " ○◈ " : "□○◈");
    print1();
    printf("  %s  ", kanOwner[8] == 0 ? "      " : kanOwner[8] == 1 ? " □   " : kanOwner[8] == 2 ? "  ○  " : kanOwner[8] == 3 ? " □○ " : kanOwner[8] == 4 ? "   ◈ " : kanOwner[8] == 5 ? " □ ◈" : kanOwner[8] == 6 ? " ○◈ " : "□○◈");
    print1();
    printf("          ");
    print1();
    printf("  %s  ", kanOwner[6] == 0 ? "      " : kanOwner[6] == 1 ? " □   " : kanOwner[6] == 2 ? "  ○  " : kanOwner[6] == 3 ? " □○ " : kanOwner[6] == 4 ? "   ◈ " : kanOwner[6] == 5 ? " □ ◈" : kanOwner[6] == 6 ? " ○◈ " : "□○◈");
    print1();
    printf("          ");
    print1();
    printf("  %s  ", kanOwner[4] == 0 ? "      " : kanOwner[4] == 1 ? " □   " : kanOwner[4] == 2 ? "  ○  " : kanOwner[4] == 3 ? " □○ " : kanOwner[4] == 4 ? "   ◈ " : kanOwner[4] == 5 ? " □ ◈" : kanOwner[4] == 6 ? " ○◈ " : "□○◈");
    print1();
    printf("  %s  ", kanOwner[3] == 0 ? "      " : kanOwner[3] == 1 ? " □   " : kanOwner[3] == 2 ? "  ○  " : kanOwner[3] == 3 ? " □○ " : kanOwner[3] == 4 ? "   ◈ " : kanOwner[3] == 5 ? " □ ◈" : kanOwner[3] == 6 ? " ○◈ " : "□○◈");
    print1();
    printf("          ");
    print1();
    printf("  %s  ", kanOwner[1] == 0 ? "      " : kanOwner[1] == 1 ? " □   " : kanOwner[1] == 2 ? "  ○  " : kanOwner[1] == 3 ? " □○ " : kanOwner[1] == 4 ? "   ◈ " : kanOwner[1] == 5 ? " □ ◈" : kanOwner[1] == 6 ? " ○◈ " : "□○◈");
    print1();
    printf("          ");
    print1();
    printf("\n");
    print1();
    print2(p1, p2, p3, p4, 10);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
    print1();
    print2(p1, p2, p3, p4, 9);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
    print1();
    print2(p1, p2, p3, p4, 8);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
    print1();
    print2(p1, p2, p3, p4, 7);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
    print1();
    print2(p1, p2, p3, p4, 6);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
    print1();
    print2(p1, p2, p3, p4, 5);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
    print1();
    print2(p1, p2, p3, p4, 4);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
    print1();
    print2(p1, p2, p3, p4, 3);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
    print1();
    print2(p1, p2, p3, p4, 2);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
    print1();
    print2(p1, p2, p3, p4, 1);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
    print1();
    print2(p1, p2, p3, p4, 0);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
    print1();
    printf("\n");
    printf("└──────────┴──────────┴──────────┴──────────┴──────────┴──────────┴──────────┴──────────┴──────────┴──────────┴──────────┘\n");
}

int main(void) {
    for (int i = 0; i < 40; i++) {
        kanNumber[i] = 0;
        kanOwner[i] = 0;
    }
    int a, p = 1;
    char cp;
    struct p1 p1;
    struct p2 p2;
    struct p3 p3;
    struct p4 p4;
    p1.kan = -1;
    p2.kan = -1;
    p3.kan = -1;
    p4.kan = -1;
    p1.out = 1;
    p2.out = 1;
    p3.out = 1;
    p4.out = 1;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    printf("추억의 보드게임, 부루마블\n");
    printf("추억의 보드게임, 부루마블은 1인 제작사 1307에 의해 만들어졌습니다.\n추억의 보드게임, 부루마블의 저작권은 1307에게 있습니다.\n");
    printf("추억의 보드게임, 부루마블은 2차 창작물이며 무단 복제 및 공유를 금지합니다.\n");
    printf("추억의 보드게임, 부루마블을 만드는데 도움을 주신 백*성 학생에게 감사의 말씀을 드립니다.\n");
    printf("Copyrightⓒ2021,추억의 보드게임, 부루마블 all rights reserved by 1307\n");
    printf("아무키나 눌러주세요\n");
    scanf("%c", &cp);
    printf("이상으로 코드 수를 딱 3600줄로 만들기 위한 헛소리를 그만하겠습니다.\n재밌게 즐겨주시면 감사하고 오류 제보 및 코드 수정, 추가 내용 등이 있으시면 많이 해주세요.\n코드가 길어서인지는 모르겠으나 가끔 컴퓨터나 컴파일러 별로 건물 건설이나 파산 후 게임 승리 출력에 관한 내용에 대한 오류가 있다고 합니다.\n대부분은 버그입니다.\n\n\n\n\n");
    printf("추억의 보드게임,부루마블에 오신 것을 환영합니다.\n");
    printf("전체화면으로 플레이 해주세요\n");
    printf("몇 명이서 하실건가요?(2인~4인) : ");
    scanf("%d", &a);
    int op = 0;
    do {
        if (a == 2) {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            printf("참가자들의 기본 소지금은 680만원입니다.\n");
            p1.money = 6800000;
            p2.money = 6800000;
            p1.space = 0;
            p2.space = 0;
            p1.turn = 0;
            p2.turn = 0;
            p1.kan = 0;
            p2.kan = 0;
            p1.out = 0;
            p2.out = 0;
        }
        else if (a == 3) {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            printf("참가자들의 기본 소지금은 340만원입니다.\n");
            p1.money = 3400000;
            p2.money = 3400000;
            p3.money = 3400000;
            p1.space = 0;
            p2.space = 0;
            p3.space = 0;
            p1.turn = 0;
            p2.turn = 0;
            p3.turn = 0;
            p1.kan = 0;
            p2.kan = 0;
            p3.kan = 0;
            p1.out = 0;
            p2.out = 0;
            p3.out = 0;
        }
        else if (a == 4) {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            printf("참가자들의 기본 소지금은 340만원입니다.\n");
            p1.money = 3400000;
            p2.money = 3400000;
            p3.money = 3400000;
            p4.money = 3400000;
            p1.space = 0;
            p2.space = 0;
            p3.space = 0;
            p4.space = 0;
            p1.turn = 0;
            p2.turn = 0;
            p3.turn = 0;
            p4.turn = 0;
            p1.kan = 0;
            p2.kan = 0;
            p3.kan = 0;
            p4.kan = 0;
            p1.out = 0;
            p2.out = 0;
            p3.out = 0;
            p4.out = 0;
        }
        else {
            printf("2인에서 4인 사이를 입력해주세요.\n");
            op++;
            if (op == 10) {
                printf("말귀를 못알아듣는걸까요,숫자를 모르는걸까요\n게임을 종료합니다.");
                return 0;
            }
            scanf("%d", &a);
        }
    } while (a < 2 || a>4);
    printf("%d명으로 플레이합니다.\n", a);
    printf("게임이 시작됩니다.\n");
    while (1) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
        printf("%d번째 턴이 시작되었습니다.\n", p++);
        int q2 = 2;
        int q;
        if (a == 2) {

            if (p1.out == 0) {
                printf("현재 플레이어 1의 소지금은 %d원, 플레이어 2의 소지금은 %d원 입니다.\n", p1.money, p2.money);
                printf("확인하셨으면 아무 키나 눌러 게임을 진행해주세요\n");
                do {
                    char q1;
                    q2 = scanf("%c", &q1);
                } while (q2 != 1);
                printf("플레이어1의 차례입니다.\n");
                if (p1.space == 1) { //우주정거장에 존재시
                    int y = 30;
                    do {
                        printf("우주정거장(30)을 제외하고 원하는 칸을 입력해주세요 : ");
                        scanf("%d", &y);
                    } while (y == 30 || y >= 40);
                    p1.kan = y;
                    p1.space = 0;
                    map(p1.kan, p2.kan, p3.kan, p4.kan);
                    game(&p1, &p2, &p3, &p4, 1);
                    if (goldNumber[1] == 1) {
                        Goldenkey(&p1, &p2, &p3, &p4, 1);
                        goldNumber[1] = 0;
                        if (start2[1] == 1) {
                            printf("출발지를 지났습니다.\n월급을 받습니다.\n");
                            p1.money += 200000;
                            start2[1] = 0;
                        }
                    }
                }
                else {  //우주정거장이 아닐시
                    if (p1.turn == 0) {  //우주정거장도 무인도도 아닐시
                        do {
                            q = dice();
                        } while (q == -1);
                        printf("주사위의 수는 %d입니다.\n", q);
                        p1.kan += q;
                        map(p1.kan, p2.kan, p3.kan, p4.kan);
                        game(&p1, &p2, &p3, &p4, 1);
                        if (goldNumber[1] == 1) {
                            Goldenkey(&p1, &p2, &p3, &p4, 1);
                            goldNumber[1] = 0;
                            if (start2[1] == 1) {
                                printf("출발지를 지났습니다.\n월급을 받습니다.\n");
                                p1.money += 200000;
                                start2[1] = 0;
                            }
                        }
                    }
                    else if (p1.turn < 4) {  //무인도에 있고 세 턴을 채우지 못했을시
                        int o;
                        o = muindo();
                        if (o == 0) {
                            printf("무인도 탈출에 실패하셨습니다.\n");
                            p1.turn++;
                        }
                        else {
                            printf("더블이 나와 무인도 탈출에 성공하셨습니다.\n");
                            printf("주사위 숫자는 %d입니다\n", o);
                            p1.kan += o;
                            map(p1.kan, p2.kan, p3.kan, p4.kan);
                            game(&p1, &p2, &p3, &p4, 1);
                            if (goldNumber[1] == 1) {
                                Goldenkey(&p1, &p2, &p3, &p4, 1);
                                goldNumber[1] = 0;
                            }
                            p1.turn = 0;
                        }
                    }
                    else {
                        printf("세 턴이 지나 무인도에서 탈출하셨습니다.\n"); //무인도에서 세 턴을 채울시
                        p1.turn = 0;
                        q = dice();
                        printf("주사위의 수는 %d입니다.\n", q);
                        p1.kan += q;
                        map(p1.kan, p2.kan, p3.kan, p4.kan);
                        game(&p1, &p2, &p3, &p4, 1);
                        if (goldNumber[1] == 1) {
                            Goldenkey(&p1, &p2, &p3, &p4, 1);
                            goldNumber[1] = 0;
                        }
                    }
                }
                printf("턴을 종료하시려면 아무 키나 눌러주세요\n");
                do {
                    char q1;
                    q2 = scanf("%c", &q1);
                } while (q2 != 1);
                if (p1.money < 0) {
                    printf("플레이어 1이 파산했습니다.\n플레이어 1이 보유한 모든 토지와 건물이 사라집니다.\n");
                    p1.out = 1;
                    for (int i = 0; i < 40; i++) {
                        if (kanNumber[i] == 1) {
                            kanNumber[i] = 0;
                            kanOwner[i] = 0;
                        }
                    }
                }
            }

            else if (p1.out == 1) {
                printf("플레이어 1은 파산했습니다.\n");
                printf("턴을 넘기시려면 아무 키나 눌러주세요\n");
                do {
                    char q1;
                    q2 = scanf("%c", &q1);
                } while (q2 != 1);
                printf("플레이어 2가 승리하셨습니다.");
                break;
            }
            printf("확인하셨으면 아무 키나 눌러 게임을 진행해주세요\n");

            do {
                char q1;
                q2 = scanf("%c", &q1);
            } while (q2 != 1);
            resetmnt();

            if (p2.out == 0) {
                printf("현재 플레이어 1의 소지금은 %d원, 플레이어 2의 소지금은 %d원 입니다.\n", p1.money, p2.money);
                printf("확인하셨으면 아무 키나 눌러 게임을 진행해주세요\n");
                do {
                    char q1;
                    q2 = scanf("%c", &q1);
                } while (q2 != 1);
                printf("플레이어2의 차례입니다.\n");
                if (p2.space == 1) { //우주정거장에 존재시
                    int y = 30;
                    do {
                        printf("우주정거장을 제외하고 원하는 칸을 입력해주세요 : ");
                        scanf("%d", &y);
                    } while (y == 30 || y >= 40);
                    p2.kan = y;
                    p2.space = 0;
                    map(p1.kan, p2.kan, p3.kan, p4.kan);
                    game(&p1, &p2, &p3, &p4, 2);
                    if (goldNumber[2] == 1) {
                        Goldenkey(&p1, &p2, &p3, &p4, 2);
                        goldNumber[2] = 0;
                        if (start2[2] == 1) {
                            printf("출발지를 지났습니다.\n월급을 받습니다.\n");
                            p2.money += 200000;
                            start2[2] = 0;
                        }
                    }
                }
                else {  //우주정거장이 아닐시
                    if (p2.turn == 0) {  //우주정거장도 무인도도 아닐시
                        do {
                            q = dice();
                        } while (q == -1);
                        printf("주사위의 수는 %d입니다.\n", q);
                        p2.kan += q;
                        map(p1.kan, p2.kan, p3.kan, p4.kan);
                        game(&p1, &p2, &p3, &p4, 2);
                        if (goldNumber[2] == 1) {
                            Goldenkey(&p1, &p2, &p3, &p4, 2);
                            goldNumber[2] = 0;
                            if (start2[2] == 1) {
                                printf("출발지를 지났습니다.\n월급을 받습니다.\n");
                                p2.money += 200000;
                                start2[2] = 0;
                            }
                        }
                    }
                    else if (p2.turn < 4) {  //무인도에 있고 세 턴을 채우지 못했을시
                        int o;
                        o = muindo();
                        if (o == 0) {
                            printf("무인도 탈출에 실패하셨습니다.\n");
                            p2.turn++;
                        }
                        else {
                            printf("무인도 탈출에 성공하셨습니다.\n");
                            p2.kan += o;
                            map(p1.kan, p2.kan, p3.kan, p4.kan);
                            game(&p1, &p2, &p3, &p4, 2);
                            if (goldNumber[2] == 1) {
                                Goldenkey(&p1, &p2, &p3, &p4, 2);
                                goldNumber[2] = 0;
                                if (start2[2] == 1) {
                                    printf("출발지를 지났습니다.\n월급을 받습니다.\n");
                                    p2.money += 200000;
                                    start2[2] = 0;
                                }
                            }
                            p2.turn = 0;
                        }
                    }
                    else {
                        printf("세 턴이 지나 무인도에서 탈출하셨습니다.\n"); //무인도에서 세 턴을 채울시
                        p2.turn = 0;
                        q = dice();
                        printf("주사위의 수는 %d입니다.\n", q);
                        p2.kan += q;
                        map(p1.kan, p2.kan, p3.kan, p4.kan);
                        game(&p1, &p2, &p3, &p4, 2);
                        if (goldNumber[2] == 1) {
                            Goldenkey(&p1, &p2, &p3, &p4, 2);
                            goldNumber[2] = 0;
                            if (start2[2] == 1) {
                                printf("출발지를 지났습니다.\n월급을 받습니다.\n");
                                p2.money += 200000;
                                start2[2] = 0;
                            }
                        }
                    }
                }
                printf("턴을 종료하시려면 아무 키나 눌러주세요\n");
                do {
                    char q1;
                    q2 = scanf("%c", &q1);
                } while (q2 != 1);
                if (p2.money < 0) {
                    printf("플레이어 2이가 파산했습니다.\n플레이어 2가 보유한 모든 토지와 건물이 사라집니다.\n");
                    p2.out = 1;
                    for (int i = 0; i < 40; i++) {
                        if (kanNumber[i] == 2) {
                            kanNumber[i] = 0;
                            kanOwner[i] = 0;
                        }
                    }
                }

                printf("턴을 종료하시려면 아무 키나 눌러주세요\n");
                do {
                    char q1;
                    q2 = scanf("%c", &q1);
                } while (q2 != 1);
                resetmnt();
            }

            else if (p1.out == 2) {
                printf("플레이어 2는 파산했습니다.\n");
                printf("턴을 넘기시려면 아무 키나 눌러주세요\n");
                do {
                    char q1;
                    q2 = scanf("%c", &q1);
                } while (q2 != 1);
                printf("플레이어 1이 승리하셨습니다.");
                break;
            }

        }



        else if (a == 3) {

            if (p1.out == 0) {
                printf("현재 플레이어 1의 소지금은 %d원, 플레이어 2의 소지금은 %d원, 플레이어 3의 소지금은 %d원 입니다.\n", p1.money, p2.money, p3.money);
                printf("확인하셨으면 아무 키나 눌러 게임을 진행해주세요\n");
                do {
                    char q1;
                    q2 = scanf("%c", &q1);
                } while (q2 != 1);
                printf("플레이어1의 차례입니다.\n");
                if (p1.space == 1) { //우주정거장에 존재시
                    int y = 30;
                    do {
                        printf("우주정거장을 제외하고 원하는 칸을 입력해주세요 : ");
                        scanf("%d", &y);
                    } while (y == 30 || y >= 40);
                    p1.kan = y;
                    p1.space = 0;
                    map(p1.kan, p2.kan, p3.kan, p4.kan);
                    game(&p1, &p2, &p3, &p4, 1);
                    if (goldNumber[1] == 1) {
                        Goldenkey(&p1, &p2, &p3, &p4, 1);
                        goldNumber[1] = 0;
                        if (start2[1] == 1) {
                            printf("출발지를 지났습니다.\n월급을 받습니다.\n");
                            p1.money += 200000;
                            start2[1] = 0;
                        }
                    }
                }
                else {  //우주정거장이 아닐시
                    if (p1.turn == 0) {  //우주정거장도 무인도도 아닐시
                        do {
                            q = dice();
                        } while (q == -1);
                        printf("주사위의 수는 %d입니다.\n", q);
                        p1.kan += q;
                        map(p1.kan, p2.kan, p3.kan, p4.kan);
                        game(&p1, &p2, &p3, &p4, 1);
                        if (goldNumber[1] == 1) {
                            Goldenkey(&p1, &p2, &p3, &p4, 1);
                            goldNumber[1] = 0;
                            if (start2[1] == 1) {
                                printf("출발지를 지났습니다.\n월급을 받습니다.\n");
                                p1.money += 200000;
                                start2[1] = 0;
                            }
                        }
                    }
                    else if (p1.turn < 4) {  //무인도에 있고 세 턴을 채우지 못했을시
                        int o;
                        o = muindo();
                        if (o == 0) {
                            printf("무인도 탈출에 실패하셨습니다.\n");
                            p1.turn++;
                        }
                        else {
                            printf("무인도 탈출에 성공하셨습니다.\n");
                            p1.kan += o;
                            map(p1.kan, p2.kan, p3.kan, p4.kan);
                            game(&p1, &p2, &p3, &p4, 1);
                            if (goldNumber[1] == 1) {
                                Goldenkey(&p1, &p2, &p3, &p4, 1);
                                goldNumber[1] = 0;
                                if (start2[1] == 1) {
                                    printf("출발지를 지났습니다.\n월급을 받습니다.\n");
                                    p1.money += 200000;
                                    start2[1] = 0;
                                }
                            }
                            p1.turn = 0;
                        }
                    }
                    else {
                        printf("세 턴이 지나 무인도에서 탈출하셨습니다.\n"); //무인도에서 세 턴을 채울시
                        p1.turn = 0;
                        q = dice();
                        printf("주사위의 수는 %d입니다.\n", q);
                        p1.kan += q;
                        map(p1.kan, p2.kan, p3.kan, p4.kan);
                        game(&p1, &p2, &p3, &p4, 1);
                        if (goldNumber[1] == 1) {
                            Goldenkey(&p1, &p2, &p3, &p4, 1);
                            goldNumber[1] = 0;
                            if (start2[1] == 1) {
                                printf("출발지를 지났습니다.\n월급을 받습니다.\n");
                                p1.money += 200000;
                                start2[1] = 0;
                            }
                        }
                    }
                }
                printf("턴을 종료하시려면 아무 키나 눌러주세요\n");
                do {
                    char q1;
                    q2 = scanf("%c", &q1);
                } while (q2 != 1);
                if (p1.money < 0) {
                    printf("플레이어 1이 파산했습니다.\n플레이어 1이 보유한 모든 토지와 건물이 사라집니다.\n");
                    p1.out = 1;
                    for (int i = 0; i < 40; i++) {
                        if (kanNumber[i] == 1) {
                            kanNumber[i] = 0;
                            kanOwner[i] = 0;
                        }
                    }
                }
            }

            else if (p1.out == 1) {
                printf("플레이어 1은 파산했습니다.\n");
                printf("턴을 넘기시려면 아무 키나 눌러주세요\n");
                do {
                    char q1;
                    q2 = scanf("%c", &q1);
                } while (q2 != 1);
            }
            printf("확인하셨으면 아무 키를 눌러 게임을 진행해주세요\n");

            do {
                char q1;
                q2 = scanf("%c", &q1);
            } while (q2 != 1);
            resetmnt();

            if (p2.out == 0) {
                printf("현재 플레이어 1의 소지금은 %d원, 플레이어 2의 소지금은 %d원, 플레이어 3의 소지금은 %d원 입니다.\n", p1.money, p2.money, p3.money);
                printf("확인하셨으면 아무 키나 눌러 게임을 진행해주세요\n");
                do {
                    char q1;
                    q2 = scanf("%c", &q1);
                } while (q2 != 1);
                printf("플레이어2의 차례입니다.\n");
                if (p2.space == 1) { //우주정거장에 존재시
                    int y = 30;
                    do {
                        printf("우주정거장을 제외하고 원하는 칸을 입력해주세요 : ");
                        scanf("%d", &y);
                    } while (y == 30 || y >= 40);
                    p2.kan = y;
                    p2.space = 0;
                    map(p1.kan, p2.kan, p3.kan, p4.kan);
                    game(&p1, &p2, &p3, &p4, 2);
                    if (goldNumber[2] == 1) {
                        Goldenkey(&p1, &p2, &p3, &p4, 2);
                        goldNumber[2] = 0;
                        if (start2[2] == 1) {
                            printf("출발지를 지났습니다.\n월급을 받습니다.\n");
                            p2.money += 200000;
                            start2[2] = 0;
                        }
                    }
                }
                else {  //우주정거장이 아닐시
                    if (p2.turn == 0) {  //우주정거장도 무인도도 아닐시
                        do {
                            q = dice();
                        } while (q == -1);
                        printf("주사위의 수는 %d입니다.\n", q);
                        p2.kan += q;
                        map(p1.kan, p2.kan, p3.kan, p4.kan);
                        game(&p1, &p2, &p3, &p4, 2);
                        if (goldNumber[2] == 1) {
                            Goldenkey(&p1, &p2, &p3, &p4, 2);
                            goldNumber[2] = 0;
                            if (start2[2] == 1) {
                                printf("출발지를 지났습니다.\n월급을 받습니다.\n");
                                p2.money += 200000;
                                start2[2] = 0;
                            }
                        }
                    }
                    else if (p2.turn < 4) {  //무인도에 있고 세 턴을 채우지 못했을시
                        int o;
                        o = muindo();
                        if (o == 0) {
                            printf("무인도 탈출에 실패하셨습니다.\n");
                            p2.turn++;
                        }
                        else {
                            printf("무인도 탈출에 성공하셨습니다.\n");
                            p2.kan += o;
                            map(p1.kan, p2.kan, p3.kan, p4.kan);
                            game(&p1, &p2, &p3, &p4, 2);
                            if (goldNumber[2] == 1) {
                                Goldenkey(&p1, &p2, &p3, &p4, 2);
                                goldNumber[2] = 0;
                                if (start2[2] == 1) {
                                    printf("출발지를 지났습니다.\n월급을 받습니다.\n");
                                    p2.money += 200000;
                                    start2[2] = 0;
                                }
                            }
                            p2.turn = 0;
                        }
                    }
                    else {
                        printf("세 턴이 지나 무인도에서 탈출하셨습니다.\n"); //무인도에서 세 턴을 채울시
                        p2.turn = 0;
                        q = dice();
                        printf("주사위의 수는 %d입니다.\n", q);
                        p2.kan += q;
                        map(p1.kan, p2.kan, p3.kan, p4.kan);
                        game(&p1, &p2, &p3, &p4, 2);
                        if (goldNumber[2] == 1) {
                            Goldenkey(&p1, &p2, &p3, &p4, 2);
                            goldNumber[2] = 0;
                            if (start2[2] == 1) {
                                printf("출발지를 지났습니다.\n월급을 받습니다.\n");
                                p2.money += 200000;
                                start2[2] = 0;
                            }
                        }
                    }
                }
                printf("턴을 종료하시려면 아무 키나 눌러주세요\n");
                do {
                    char q1;
                    q2 = scanf("%c", &q1);
                } while (q2 != 1);
                if (p2.money < 0) {
                    printf("플레이어 2이가 파산했습니다.\n플레이어 2가 보유한 모든 토지와 건물이 사라집니다.\n");
                    p2.out = 1;
                    for (int i = 0; i < 40; i++) {
                        if (kanNumber[i] == 2) {
                            kanNumber[i] = 0;
                            kanOwner[i] = 0;
                        }
                    }
                }
            }

            else if (p2.out == 2) {
                printf("플레이어 2는 파산했습니다.\n");
                printf("턴을 넘기시려면 아무 키나 눌러주세요\n");
                do {
                    char q1;
                    q2 = scanf("%c", &q1);
                } while (q2 != 1);
            }

            printf("턴을 종료하시려면 아무 키나 눌러주세요\n");
            do {
                char q1;
                q2 = scanf("%c", &q1);
            } while (q2 != 1);
            resetmnt();

            if (p3.out == 0) {
                printf("현재 플레이어 1의 소지금은 %d원, 플레이어 2의 소지금은 %d원, 플레이어 3의 소지금은 %d 입니다.\n", p1.money, p2.money, p3.money);
                printf("확인하셨으면 아무 키나 눌러 게임을 진행해주세요\n");
                do {
                    char q1;
                    q2 = scanf("%c", &q1);
                } while (q2 != 1);
                printf("플레이어3의 차례입니다.\n");
                if (p3.space == 1) { //우주정거장에 존재시
                    int y = 30;
                    do {
                        printf("우주정거장을 제외하고 원하는 칸을 입력해주세요 : ");
                        scanf("%d", &y);
                    } while (y == 30 || y >= 40);
                    p3.kan = y;
                    p3.space = 0;
                    map(p1.kan, p2.kan, p3.kan, p4.kan);
                    game(&p1, &p2, &p3, &p4, 3);
                    if (goldNumber[3] == 1) {
                        Goldenkey(&p1, &p2, &p3, &p4, 3);
                        goldNumber[3] = 0;
                        if (start2[3] == 1) {
                            printf("출발지를 지났습니다.\n월급을 받습니다.\n");
                            p3.money += 200000;
                            start2[3] = 0;
                        }
                    }
                }
                else {  //우주정거장이 아닐시
                    if (p3.turn == 0) {  //우주정거장도 무인도도 아닐시
                        do {
                            q = dice();
                        } while (q == -1);
                        printf("주사위의 수는 %d입니다.\n", q);
                        p3.kan += q;
                        map(p1.kan, p2.kan, p3.kan, p4.kan);
                        game(&p1, &p2, &p3, &p4, 3);
                        if (goldNumber[3] == 1) {
                            Goldenkey(&p1, &p2, &p3, &p4, 3);
                            goldNumber[3] = 0;
                            if (start2[3] == 1) {
                                printf("출발지를 지났습니다.\n월급을 받습니다.\n");
                                p3.money += 200000;
                                start2[3] = 0;
                            }
                        }
                    }
                    else if (p3.turn < 4) {  //무인도에 있고 세 턴을 채우지 못했을시
                        int o;
                        o = muindo();
                        if (o == 0) {
                            printf("무인도 탈출에 실패하셨습니다.\n");
                            p3.turn++;
                        }
                        else {
                            printf("무인도 탈출에 성공하셨습니다.\n");
                            p3.kan += o;
                            map(p1.kan, p2.kan, p3.kan, p4.kan);
                            game(&p1, &p2, &p3, &p4, 3);
                            if (goldNumber[3] == 1) {
                                Goldenkey(&p1, &p2, &p3, &p4, 3);
                                goldNumber[3] = 0;
                                if (start2[3] == 1) {
                                    printf("출발지를 지났습니다.\n월급을 받습니다.\n");
                                    p3.money += 200000;
                                    start2[3] = 0;
                                }
                            }
                            p3.turn = 0;
                        }
                    }
                    else {
                        printf("세 턴이 지나 무인도에서 탈출하셨습니다.\n"); //무인도에서 세 턴을 채울시
                        p3.turn = 0;
                        q = dice();
                        printf("주사위의 수는 %d입니다.\n", q);
                        p3.kan += q;
                        map(p1.kan, p2.kan, p3.kan, p4.kan);
                        game(&p1, &p2, &p3, &p4, 3);
                        if (goldNumber[3] == 1) {
                            Goldenkey(&p1, &p2, &p3, &p4, 3);
                            goldNumber[3] = 0;
                            if (start2[3] == 1) {
                                printf("출발지를 지났습니다.\n월급을 받습니다.\n");
                                p3.money += 200000;
                                start2[3] = 0;
                            }
                        }
                    }
                }
                printf("턴을 종료하시려면 아무 키나 눌러주세요\n");
                do {
                    char q1;
                    q2 = scanf("%c", &q1);
                } while (q2 != 1);
                if (p3.money < 0) {
                    printf("플레이어 3가 파산했습니다.\n플레이어 3가 보유한 모든 토지와 건물이 사라집니다.\n");
                    p3.out = 1;
                    for (int i = 0; i < 40; i++) {
                        if (kanNumber[i] == 3) {
                            kanNumber[i] = 0;
                            kanOwner[i] = 0;
                        }
                    }
                }
            }

            else if (p3.out == 1) {
                printf("플레이어 3는 파산했습니다.\n");
                printf("턴을 넘기시려면 아무 키나 눌러주세요\n");
                do {
                    char q1;
                    q2 = scanf("%c", &q1);
                } while (q2 != 1);
            }
            printf("확인하셨으면 아무 키나 눌러 게임을 진행해주세요\n");

            do {
                char q1;
                q2 = scanf("%c", &q1);
            } while (q2 != 1);
            resetmnt();

            if (p1.out == 1 && p2.out == 1 && p3.out == 0) {
                printf("플레이어 3가 승리하셨습니다.");
                break;
            }

            else if (p2.out == 1 && p3.out == 1 && p1.out == 0) {
                printf("플레이어 1이 승리하셨습니다.");
                break;
            }

            else if (p1.out == 1 && p3.out == 1 && p2.out == 0) {
                printf("플레이어 2가 승리하셨습니다.");
                break;
            }

        }



        else if (a == 4) {


            if (p1.out == 0) {
                printf("현재 플레이어 1의 소지금은 %d원, 플레이어 2의 소지금은 %d원, 플레이어 3의 소지금은 %d원, 플레이어 4의 소지금은 %d 입니다.\n", p1.money, p2.money, p3.money, p4.money);
                printf("확인하셨으면 아무 키나 눌러 게임을 진행해주세요\n");
                do {
                    char q1;
                    q2 = scanf("%c", &q1);
                } while (q2 != 1);
                printf("플레이어1의 차례입니다.\n");
                if (p1.space == 1) { //우주정거장에 존재시
                    int y = 30;
                    do {
                        printf("우주정거장을 제외하고 원하는 칸을 입력해주세요 : ");
                        scanf("%d", &y);
                    } while (y == 30 || y >= 40);
                    p1.kan = y;
                    p1.space = 0;
                    map(p1.kan, p2.kan, p3.kan, p4.kan);
                    game(&p1, &p2, &p3, &p4, 1);
                    if (goldNumber[1] == 1) {
                        Goldenkey(&p1, &p2, &p3, &p4, 1);
                        goldNumber[1] = 0;
                        if (start2[1] == 1) {
                            printf("출발지를 지났습니다.\n월급을 받습니다.\n");
                            p1.money += 200000;
                            start2[1] = 0;
                        }
                    }
                }
                else {  //우주정거장이 아닐시
                    if (p1.turn == 0) {  //우주정거장도 무인도도 아닐시
                        do {
                            q = dice();
                        } while (q == -1);
                        printf("주사위의 수는 %d입니다.\n", q);
                        p1.kan += q;
                        map(p1.kan, p2.kan, p3.kan, p4.kan);
                        game(&p1, &p2, &p3, &p4, 1);
                        if (goldNumber[1] == 1) {
                            Goldenkey(&p1, &p2, &p3, &p4, 1);
                            goldNumber[1] = 0;
                            if (start2[1] == 1) {
                                printf("출발지를 지났습니다.\n월급을 받습니다.\n");
                                p1.money += 200000;
                                start2[1] = 0;
                            }
                        }
                    }
                    else if (p1.turn < 4) {  //무인도에 있고 세 턴을 채우지 못했을시
                        int o;
                        o = muindo();
                        if (o == 0) {
                            printf("무인도 탈출에 실패하셨습니다.\n");
                            p1.turn++;
                        }
                        else {
                            printf("무인도 탈출에 성공하셨습니다.\n");
                            p1.kan += o;
                            map(p1.kan, p2.kan, p3.kan, p4.kan);
                            game(&p1, &p2, &p3, &p4, 1);
                            if (goldNumber[1] == 1) {
                                Goldenkey(&p1, &p2, &p3, &p4, 1);
                                goldNumber[1] = 0;
                                if (start2[1] == 1) {
                                    printf("출발지를 지났습니다.\n월급을 받습니다.\n");
                                    p1.money += 200000;
                                    start2[1] = 0;
                                }
                            }
                            p1.turn = 0;
                        }
                    }
                    else {
                        printf("세 턴이 지나 무인도에서 탈출하셨습니다.\n"); //무인도에서 세 턴을 채울시
                        p1.turn = 0;
                        q = dice();
                        printf("주사위의 수는 %d입니다.\n", q);
                        p1.kan += q;
                        map(p1.kan, p2.kan, p3.kan, p4.kan);
                        game(&p1, &p2, &p3, &p4, 1);
                        if (goldNumber[1] == 1) {
                            Goldenkey(&p1, &p2, &p3, &p4, 1);
                            goldNumber[1] = 0;
                            if (start2[1] == 1) {
                                printf("출발지를 지났습니다.\n월급을 받습니다.\n");
                                p1.money += 200000;
                                start2[1] = 0;
                            }
                        }
                    }
                }
                printf("턴을 종료하시려면 아무 키나 눌러주세요\n");
                do {
                    char q1;
                    q2 = scanf("%c", &q1);
                } while (q2 != 1);
                if (p1.money < 0) {
                    printf("플레이어 1이 파산했습니다.\n플레이어 1이 보유한 모든 토지와 건물이 사라집니다.\n");
                    p1.out = 1;
                    for (int i = 0; i < 40; i++) {
                        if (kanNumber[i] == 1) {
                            kanNumber[i] = 0;
                            kanOwner[i] = 0;
                        }
                    }
                }
            }

            else if (p1.out == 1) {
                printf("플레이어 1은 파산했습니다.\n");
                printf("턴을 넘기시려면 아무 키나 눌러주세요\n");
                do {
                    char q1;
                    q2 = scanf("%c", &q1);
                } while (q2 != 1);
            }
            printf("확인을 하셨으면 아무 키나 눌러 게임을 진행해주세요\n");

            do {
                char q1;
                q2 = scanf("%c", &q1);
            } while (q2 != 1);
            resetmnt();

            if (p2.out == 0) {
                printf("현재 플레이어 1의 소지금은 %d원, 플레이어 2의 소지금은 %d원, 플레이어 3의 소지금은 %d원, 플레이어 4의 소지금은 %d 입니다.\n", p1.money, p2.money, p3.money, p4.money);
                printf("확인하셨으면 아무 키나 눌러 게임을 진행해주세요\n");
                do {
                    char q1;
                    q2 = scanf("%c", &q1);
                } while (q2 != 1);
                printf("플레이어2의 차례입니다.\n");
                if (p2.space == 1) { //우주정거장에 존재시
                    int y = 30;
                    do {
                        printf("우주정거장을 제외하고 원하는 칸을 입력해주세요 : ");
                        scanf("%d", &y);
                    } while (y == 30 || y >= 40);
                    p2.kan = y;
                    p2.space = 0;
                    map(p1.kan, p2.kan, p3.kan, p4.kan);
                    game(&p1, &p2, &p3, &p4, 2);
                    if (goldNumber[2] == 1) {
                        Goldenkey(&p1, &p2, &p3, &p4, 2);
                        goldNumber[2] = 0;
                        if (start2[2] == 1) {
                            printf("출발지를 지났습니다.\n월급을 받습니다.\n");
                            p2.money += 200000;
                            start2[2] = 0;
                        }
                    }
                }
                else {  //우주정거장이 아닐시
                    if (p2.turn == 0) {  //우주정거장도 무인도도 아닐시
                        do {
                            q = dice();
                        } while (q == -1);
                        printf("주사위의 수는 %d입니다.\n", q);
                        p2.kan += q;
                        map(p1.kan, p2.kan, p3.kan, p4.kan);
                        game(&p1, &p2, &p3, &p4, 2);
                        if (goldNumber[2] == 1) {
                            Goldenkey(&p1, &p2, &p3, &p4, 2);
                            goldNumber[2] = 0;
                            if (start2[2] == 1) {
                                printf("출발지를 지났습니다.\n월급을 받습니다.\n");
                                p2.money += 200000;
                                start2[2] = 0;
                            }
                        }
                    }
                    else if (p2.turn < 4) {  //무인도에 있고 세 턴을 채우지 못했을시
                        int o;
                        o = muindo();
                        if (o == 0) {
                            printf("무인도 탈출에 실패하셨습니다.\n");
                            p2.turn++;
                        }
                        else {
                            printf("무인도 탈출에 성공하셨습니다.\n");
                            p2.kan += o;
                            map(p1.kan, p2.kan, p3.kan, p4.kan);
                            game(&p1, &p2, &p3, &p4, 2);
                            if (goldNumber[2] == 1) {
                                Goldenkey(&p1, &p2, &p3, &p4, 2);
                                goldNumber[2] = 0;
                                if (start2[2] == 1) {
                                    printf("출발지를 지났습니다.\n월급을 받습니다.\n");
                                    p2.money += 200000;
                                    start2[2] = 0;
                                }
                            }
                            p2.turn = 0;
                        }
                    }
                    else {
                        printf("세 턴이 지나 무인도에서 탈출하셨습니다.\n"); //무인도에서 세 턴을 채울시
                        p2.turn = 0;
                        q = dice();
                        printf("주사위의 수는 %d입니다.\n", q);
                        p2.kan += q;
                        map(p1.kan, p2.kan, p3.kan, p4.kan);
                        game(&p1, &p2, &p3, &p4, 2);
                        if (goldNumber[2] == 1) {
                            Goldenkey(&p1, &p2, &p3, &p4, 2);
                            goldNumber[2] = 0;
                            if (start2[2] == 1) {
                                printf("출발지를 지났습니다.\n월급을 받습니다.\n");
                                p2.money += 200000;
                                start2[2] = 0;
                            }
                        }
                    }
                }
                printf("턴을 종료하시려면 아무 키나 눌러주세요\n");
                do {
                    char q1;
                    q2 = scanf("%c", &q1);
                } while (q2 != 1);
                if (p2.money < 0) {
                    printf("플레이어 2이가 파산했습니다.\n플레이어 2가 보유한 모든 토지와 건물이 사라집니다.\n");
                    p2.out = 1;
                    for (int i = 0; i < 40; i++) {
                        if (kanNumber[i] == 2) {
                            kanNumber[i] = 0;
                            kanOwner[i] = 0;
                        }
                    }
                }
            }

            else if (p2.out == 2) {
                printf("플레이어 2는 파산했습니다.\n");
                printf("턴을 넘기시려면 아무 키나 눌러주세요\n");
                do {
                    char q1;
                    q2 = scanf("%c", &q1);
                } while (q2 != 1);
            }
            printf("확인하셨으면 아무 키나 눌러 게임을 진행해주세요\n");

            do {
                char q1;
                q2 = scanf("%c", &q1);
            } while (q2 != 1);
            resetmnt();

            if (p3.out == 0) {
                printf("현재 플레이어 1의 소지금은 %d원, 플레이어 2의 소지금은 %d원, 플레이어 3의 소지금은 %d원, 플레이어 4의 소지금은 %d 입니다.\n", p1.money, p2.money, p3.money, p4.money);
                printf("확인하셨으면 아무 키나 눌러 게임을 진행해주세요\n");
                do {
                    char q1;
                    q2 = scanf("%c", &q1);
                } while (q2 != 1);
                printf("플레이어3의 차례입니다.\n");
                if (p3.space == 1) { //우주정거장에 존재시
                    int y = 30;
                    do {
                        printf("우주정거장을 제외하고 원하는 칸을 입력해주세요 : ");
                        scanf("%d", &y);
                    } while (y == 30 || y >= 40);
                    p3.kan = y;
                    p3.space = 0;
                    map(p1.kan, p2.kan, p3.kan, p4.kan);
                    game(&p1, &p2, &p3, &p4, 3);
                    if (goldNumber[3] == 1) {
                        Goldenkey(&p1, &p2, &p3, &p4, 3);
                        goldNumber[3] = 0;
                        if (start2[3] == 1) {
                            printf("출발지를 지났습니다.\n월급을 받습니다.\n");
                            p3.money += 200000;
                            start2[3] = 0;
                        }
                    }
                }
                else {  //우주정거장이 아닐시
                    if (p3.turn == 0) {  //우주정거장도 무인도도 아닐시
                        do {
                            q = dice();
                        } while (q == -1);
                        printf("주사위의 수는 %d입니다.\n", q);
                        p3.kan += q;
                        map(p1.kan, p2.kan, p3.kan, p4.kan);
                        game(&p1, &p2, &p3, &p4, 3);
                        if (goldNumber[3] == 1) {
                            Goldenkey(&p1, &p2, &p3, &p4, 3);
                            goldNumber[3] = 0;
                            if (start2[3] == 1) {
                                printf("출발지를 지났습니다.\n월급을 받습니다.\n");
                                p3.money += 200000;
                                start2[3] = 0;
                            }
                        }
                    }
                    else if (p3.turn < 4) {  //무인도에 있고 세 턴을 채우지 못했을시
                        int o;
                        o = muindo();
                        if (o == 0) {
                            printf("무인도 탈출에 실패하셨습니다.\n");
                            p3.turn++;
                        }
                        else {
                            printf("무인도 탈출에 성공하셨습니다.\n");
                            p3.kan += o;
                            map(p1.kan, p2.kan, p3.kan, p4.kan);
                            game(&p1, &p2, &p3, &p4, 3);
                            if (goldNumber[3] == 1) {
                                Goldenkey(&p1, &p2, &p3, &p4, 3);
                                goldNumber[3] = 0;
                                if (start2[3] == 1) {
                                    printf("출발지를 지났습니다.\n월급을 받습니다.\n");
                                    p3.money += 200000;
                                    start2[3] = 0;
                                }
                            }
                            p3.turn = 0;
                        }
                    }
                    else {
                        printf("세 턴이 지나 무인도에서 탈출하셨습니다.\n"); //무인도에서 세 턴을 채울시
                        p3.turn = 0;
                        q = dice();
                        printf("주사위의 수는 %d입니다.\n", q);
                        p3.kan += q;
                        map(p1.kan, p2.kan, p3.kan, p4.kan);
                        game(&p1, &p2, &p3, &p4, 3);
                        if (goldNumber[3] == 1) {
                            Goldenkey(&p1, &p2, &p3, &p4, 3);
                            goldNumber[3] = 0;
                            if (start2[3] == 1) {
                                printf("출발지를 지났습니다.\n월급을 받습니다.\n");
                                p3.money += 200000;
                                start2[3] = 0;
                            }
                        }
                    }
                }
                printf("턴을 종료하시려면 아무 키나 눌러주세요\n");
                do {
                    char q1;
                    q2 = scanf("%c", &q1);
                } while (q2 != 1);

                if (p3.money < 0) {
                    printf("플레이어 3가 파산했습니다.\n플레이어 3가 보유한 모든 토지와 건물이 사라집니다.\n");
                    p3.out = 1;
                    for (int i = 0; i < 40; i++) {
                        if (kanNumber[i] == 3) {
                            kanNumber[i] = 0;
                            kanOwner[i] = 0;
                        }
                    }
                }
            }

            else if (p3.out == 1) {
                printf("플레이어 3는 파산했습니다.\n");
                printf("턴을 넘기시려면 아무 키나 눌러주세요\n");
                do {
                    char q1;
                    q2 = scanf("%c", &q1);
                } while (q2 != 1);
            }
            printf("확인하셨으면 아무 키나 눌러 게임을 진행해주세요\n");

            do {
                char q1;
                q2 = scanf("%c", &q1);
            } while (q2 != 1);
            resetmnt();

            if (p4.out == 0) {
                printf("현재 플레이어 1의 소지금은 %d원, 플레이어 2의 소지금은 %d원, 플레이어 3의 소지금은 %d원, 플레이어 4의 소지금은 %d 입니다.\n", p1.money, p2.money, p3.money, p4.money);
                do {
                    char q1;
                    q2 = scanf("%c", &q1);
                } while (q2 != 1);
                printf("플레이어4의 차례입니다.\n");
                if (p4.space == 1) { //우주정거장에 존재시
                    int y = 30;
                    do {
                        printf("우주정거장을 제외하고 원하는 칸을 입력해주세요 : ");
                        scanf("%d", &y);
                    } while (y == 30 || y >= 40);
                    p4.kan = y;
                    p4.space = 0;
                    map(p1.kan, p2.kan, p3.kan, p4.kan);
                    game(&p1, &p2, &p3, &p4, 4);
                    if (goldNumber[4] == 1) {
                        Goldenkey(&p1, &p2, &p3, &p4, 4);
                        goldNumber[4] = 0;
                        if (start2[4] == 1) {
                            printf("출발지를 지났습니다.\n월급을 받습니다.\n");
                            p4.money += 200000;
                            start2[4] = 0;
                        }
                    }
                }
                else {  //우주정거장이 아닐시
                    if (p4.turn == 0) {  //우주정거장도 무인도도 아닐시
                        do {
                            q = dice();
                        } while (q == -1);
                        printf("주사위의 수는 %d입니다.\n", q);
                        p4.kan += q;
                        map(p1.kan, p2.kan, p3.kan, p4.kan);
                        game(&p1, &p2, &p3, &p4, 4);
                        if (goldNumber[4] == 1) {
                            Goldenkey(&p1, &p2, &p3, &p4, 4);
                            goldNumber[4] = 0;
                            if (start2[4] == 1) {
                                printf("출발지를 지났습니다.\n월급을 받습니다.\n");
                                p4.money += 200000;
                                start2[4] = 0;
                            }
                        }
                    }
                    else if (p4.turn < 4) {  //무인도에 있고 세 턴을 채우지 못했을시
                        int o;
                        o = muindo();
                        if (o == 0) {
                            printf("무인도 탈출에 실패하셨습니다.\n");
                            p4.turn++;
                        }
                        else {
                            printf("무인도 탈출에 성공하셨습니다.\n");
                            p4.kan += o;
                            map(p1.kan, p2.kan, p3.kan, p4.kan);
                            game(&p1, &p2, &p3, &p4, 4);
                            if (goldNumber[4] == 1) {
                                Goldenkey(&p1, &p2, &p3, &p4, 4);
                                goldNumber[4] = 0;
                                if (start2[4] == 1) {
                                    printf("출발지를 지났습니다.\n월급을 받습니다.\n");
                                    p4.money += 200000;
                                    start2[4] = 0;
                                }
                            }
                            p4.turn = 0;
                        }
                    }
                    else {
                        printf("세 턴이 지나 무인도에서 탈출하셨습니다.\n"); //무인도에서 세 턴을 채울시
                        p4.turn = 0;
                        q = dice();
                        printf("주사위의 수는 %d입니다.\n", q);
                        p4.kan += q;
                        map(p1.kan, p2.kan, p3.kan, p4.kan);
                        game(&p1, &p2, &p3, &p4, 4);
                        if (goldNumber[4] == 1) {
                            Goldenkey(&p1, &p2, &p3, &p4, 4);
                            goldNumber[4] = 0;
                            if (start2[4] == 1) {
                                printf("출발지를 지났습니다.\n월급을 받습니다.\n");
                                p4.money += 200000;
                                start2[4] = 0;
                            }
                        }
                    }
                }
                printf("턴을 종료하시려면 아무 키나 눌러주세요\n");
                do {
                    char q1;
                    q2 = scanf("%c", &q1);
                } while (q2 != 1);
                if (p4.money < 0) {
                    printf("플레이어 4가 파산했습니다.\n플레이어 4가 보유한 모든 토지와 건물이 사라집니다.\n");
                    p4.out = 1;
                    for (int i = 0; i < 40; i++) {
                        if (kanNumber[i] == 4) {
                            kanNumber[i] = 0;
                            kanOwner[i] = 0;
                        }
                    }
                }
            }

            else if (p4.out == 1) {
                printf("플레이어 4는 파산했습니다.\n");
                printf("턴을 넘기시려면 아무 키나 눌러주세요\n");
                do {
                    char q1;
                    q2 = scanf("%c", &q1);
                } while (q2 != 1);
            }
            printf("확인하셨으면 아무 키나 눌러 게임을 진행해주세요\n");

            do {
                char q1;
                q2 = scanf("%c", &q1);
            } while (q2 != 1);
            resetmnt();

            if (p1.out == 1 && p2.out == 1 && p3.out == 0 && p4.out == 1) {
                printf("플레이어 3가 승리하셨습니다.");
                break;
            }

            else if (p2.out == 1 && p3.out == 1 && p1.out == 0 && p4.out == 1) {
                printf("플레이어 1이 승리하셨습니다.");
                break;
            }

            else if (p1.out == 1 && p3.out == 1 && p2.out == 0 && p4.out == 1) {
                printf("플레이어 2가 승리하셨습니다.");
                break;
            }

            else if (p1.out == 1 && p3.out == 1 && p4.out == 0 && p2.out == 1) {
                printf("플레이어 4가 승리하셨습니다.");
                break;
            }

        }
    }
    return 0;
}