#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define W 119 // 号狽徹 貢 唖 徹左球税 焼什徹 坪球
void PrintStartBoard();//獣拙 鉢檎 窒径
void PlayGame();//惟績 獣拙
void GameRule();//惟績 穴 竺誤
void PrintPicture();//鉢詞妊 益顕 窒径
void gotoxy(int x, int y); //鷺稽益拭辞 魚紳 戚疑 敗呪
void GameOver();//惟績 神獄
void CleanPicture();//鉢詞妊 益顕 走酔奄
int main() {
    PrintStartBoard();
    while (1) {
        if (_kbhit())
        {
            if (_getch() == W) {
                system("cls");//W 刊牽檎 鉢檎 乞砧 走酔壱 惟績 獣拙
                PlayGame();
                return 0;
                exit(1); // 覗稽益轡 曽戟
            }
        }
    }
}
void PrintStartBoard() {
    printf("＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝\n");
    printf("＝                                                                                                                    ＝\n");
    printf("＝  ＝  ＝  ＝        ＝＝           ＝       ＝＝＝＝＝＝＝    ＝＝＝＝     ＝ ＝        ＝        ＝＝＝＝＝＝＝    ＝\n");
    printf("＝  ＝  ＝  ＝      ＝    ＝       ＝  ＝     ＝                ＝           ＝ ＝        ＝        ＝                ＝\n");
    printf("＝  ＝＝＝  ＝＝    ＝    ＝     ＝      ＝   ＝                ＝           ＝ ＝      ＝  ＝      ＝                ＝\n");
    printf("＝  ＝  ＝  ＝        ＝＝           ＝       ＝                ＝           ＝ ＝    ＝      ＝    ＝＝＝＝＝＝＝    ＝\n");
    printf("＝  ＝＝＝  ＝                   ＝＝＝＝＝   ＝＝＝＝＝＝＝    ＝＝＝＝   ＝＝ ＝  ＝          ＝  ＝                ＝\n");
    printf("＝                 ＝＝＝＝＝                                   ＝           ＝ ＝                  ＝                ＝\n");
    printf("＝  ＝                           ＝＝＝＝＝         ＝          ＝           ＝ ＝                  ＝＝＝＝＝＝＝    ＝\n");
    printf("＝  ＝                ＝＝               ＝         ＝          ＝           ＝ ＝  ＝＝＝＝＝＝＝                    ＝\n");
    printf("＝  ＝              ＝    ＝             ＝   ＝＝＝＝＝＝＝    ＝＝＝＝     ＝ ＝                                    ＝\n");
    printf("＝  ＝＝＝＝＝      ＝    ＝             ＝                                  ＝ ＝                  ＝＝＝＝＝＝＝    ＝\n");
    printf("＝                    ＝＝                                                                                            ＝\n");
    printf("＝                                                                                                                    ＝\n");
    printf("＝                                                                                                                    ＝\n");
    printf("＝                                                                                                                    ＝\n");
    printf("＝                                                                                                                    ＝\n");
    printf("＝                                                                                                                    ＝\n");
    printf("＝                                                                                                                    ＝\n");
    printf("＝                                                                                                                    ＝\n");
    printf("＝                                                                                                                    ＝\n");
    printf("＝                                             PRESS W TO START!!!                =                                   ＝\n");
    printf("＝                                                                                                                    ＝\n");
    printf("＝                                                                                                                    ＝\n");
    printf("＝                                                                                                                    ＝\n");
    printf("＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝\n");
}
void gotoxy(int x, int y)

{

    COORD pos = { x, y / 2 };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

}
void PlayGame() {
    GameRule();
    int random;
    int score = 0;
    clock_t StartClock, EndClock;//獣娃 著舛馬澗 号狛
    float record;
    StartClock = clock();//獣拙 獣唖
    while (1) {
        srand(time(NULL));
        random = rand() % 4;//0:up, 1:down, 2:left, 3: right
        PrintPicture(random);//random 葵 蟹紳 依拭 限澗 鉢詞妊 益顕
        switch (random) {
        case 0://up
            while (1) {
                if (_kbhit())
                {
                    switch (_getch())
                    {
                    case UP:
                        goto EXIT;//限惟 喚袈生糠稽 陥製 遭楳
                    case DOWN:
                        GameOver();
                        break;
                    case LEFT:
                        GameOver();
                        break;
                    case RIGHT:
                        GameOver();
                        break;
                    }
                }
            }
            break;
        case 1://down
            while (1) {
                if (_kbhit())
                {
                    switch (_getch())
                    {
                    case UP:
                        GameOver();
                        break;
                    case DOWN:
                        goto EXIT;//限惟 喚袈生糠稽 陥製 遭楳
                    case LEFT:
                        GameOver();
                        break;
                    case RIGHT:
                        GameOver();
                        break;
                    }
                }
            }
            break;
        case 2://left
            while (1) {
                if (_kbhit())
                {
                    switch (_getch())
                    {
                    case UP:
                        GameOver();
                        break;
                    case DOWN:
                        GameOver();
                        break;
                    case LEFT:
                        goto EXIT;//限惟 喚袈生糠稽 陥製 遭楳
                    case RIGHT:
                        GameOver();
                        break;
                    }
                }
            }
            break;
        case 3://right
            while (1) {
                if (_kbhit())
                {
                    switch (_getch())
                    {
                    case UP:
                        GameOver();
                        break;
                    case DOWN:
                        GameOver();
                        break;
                    case LEFT:
                        GameOver();
                        break;
                    case RIGHT:
                        goto EXIT;//限惟 喚袈生糠稽 陥製 遭楳
                    }
                }
            }
            break;

        }
    EXIT://掻淡 鋼差庚聖 匙閃蟹亜醤 背辞 嬢多 呪 蒸戚 紫遂梅柔艦陥.
        score++;
        CleanPicture();
        gotoxy(30, 0);
        printf("%d/30噺", score);//神献楕生稽 亜辞 鉢詞妊 刊献 判呪 妊獣
        gotoxy(0, 0);//据掘 鉢詞妊 窒径 是帖稽 差瑛
        if (score == 30) break;
    }
    EndClock = clock();//曽戟 獣唖
    record = (float)(EndClock - StartClock) / CLOCKS_PER_SEC;//奄系=(曽戟 獣唖-坦製獣唖)/(段稽 発至)
    system("cls");
    printf("%.3f段 杏携柔艦陥.", record);//奄系精 実属切軒猿走 窒径
}
void GameRule() {
    printf("<GAME RULE>\n");
    printf("1. 疎著 雌舘 鉢檎拭 鉢詞妊 革 号狽 掻 廃 号狽戚 蟹辛艦陥!\n");
    printf("2. 鉢詞妊 益顕拭 限蓄嬢 号狽徹研 喚君爽獣檎 桔艦陥!\n");
    printf("3. 幻鉦 設公 刊牽檎 惟績 曽戟脊艦陥~\n");
    printf("4. 臣郊献 徹研 刊牽重陥檎 陥製 益顕戚 聡獣 蟹神壱, 郊稽 陥製 鉢檎 徹研 刊牽獣檎 桔艦陥.\n");
    printf("5. 恥 益顕精 30腰 蟹神壱, 穿採 薦企稽 刊牽重陥檎 原走厳拭 奄系戚 蟹臣 位艦陥.\n");
    printf("6. 益軍 楳錘聖 索艦陥.\n");
    Sleep(3000);//3段 走尻
    gotoxy(0, 20);
    printf("[COUNT DOWN]\n");//焼掘楕生稽 鎧形亜辞 朝錘闘陥錘 5段 獣拙
    for (int i = 5; i >= 0; i--) {
        gotoxy(0, 24);
        printf("%d", i);
        Sleep(1000);
    }
    system("cls");//穿採 走酔壱 惟績 獣拙
}
void PrintPicture(picture) {
    switch (picture) {
    case 0:
        printf("    ＝\n");
        printf("  ＝＝＝\n");
        printf("＝  ＝  ＝\n");
        printf("    ＝\n");
        printf("    ＝\n");
        break;
    case 1:
        printf("    ＝\n");
        printf("    ＝\n");
        printf("＝  ＝  ＝\n");
        printf("  ＝＝＝\n");
        printf("    ＝\n");
        break;
    case 2:
        printf("    ＝\n");
        printf("  ＝\n");
        printf("＝＝＝＝＝\n");
        printf("  ＝\n");
        printf("    ＝\n");
        break;
    case 3:
        printf("    ＝\n");
        printf("      ＝\n");
        printf("＝＝＝＝＝\n");
        printf("      ＝\n");
        printf("    ＝\n");
        break;
    }
}
void GameOver() {
    int x;
    system("cls");
    srand(time(NULL));
    x = rand() % 5;//沓棋馬惟 惟績曽戟 企紫 窒径(宿宿背辞 隔醸柔艦陥)
    switch (x) {
    case 0:
        printf("設公 刊牽写柔艦陥.. 戚杏 走榎 適遣戚虞壱 馬重 位艦猿?\nせせせせせせせせせせせせ\n");
        break;
    case 1:
        printf("設公 刊牽写革推! 企舘馬淑艦陥!!\n逐馬球形推~~~\n");
        break;
    case 2:
        printf("設公 刊牽写柔艦陥.. 凧生稽 且遇浦推!!\n");
        break;
    case 3:
        printf("設公 刊牽写柔艦陥. 廃 腰 希 獣亀馬獣檎 疏精 衣引亜 赤聖 暗拭推~~\n鉢戚特!!!\n");
        break;
    case 4:
        printf("設公 刊牽写革推.. 煽訓..... せ\n");
        break;
    }
    Sleep(2000);
    printf("＝＝＝＝＝    ＝  ＝    ＝    ＝  ＝＝＝＝＝  ＝＝＝＝＝  \n");
    printf("        ＝    ＝  ＝  ＝  ＝  ＝      ＝              ＝  \n");
    printf("        ＝    ＝  ＝  ＝  ＝  ＝    ＝  ＝    ＝＝＝＝＝  \n");
    printf("        ＝    ＝  ＝  ＝  ＝  ＝              ＝          \n");
    printf("        ＝    ＝  ＝    ＝    ＝      ＝      ＝＝＝＝＝  \n");
    printf("        ＝＝＝＝  ＝              ＝＝＝＝＝              \n");
    printf("        ＝    ＝  ＝     ＝＝＝                 ＝  ＝    \n");
    printf("        ＝    ＝  ＝     ＝  ＝       ＝        ＝  ＝    \n");
    printf("        ＝    ＝  ＝     ＝  ＝     ＝  ＝      ＝  ＝    \n");
    printf("        ＝    ＝  ＝     ＝＝＝       ＝    ＝＝＝＝＝＝＝\n");
    exit(1);
}
void CleanPicture() {
    gotoxy(0, 0);
    printf("          \n");
    printf("          \n");
    printf("          \n");
    printf("          \n");
    printf("          \n");
    Sleep(50);//走尻聖 隔嬢辞 歯稽錘 益顕戚 蟹紳 杏 巴傾戚嬢亜 溌昔馬惟 敗
    gotoxy(0, 0);
}
