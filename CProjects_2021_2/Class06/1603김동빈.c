#include<stdio.h>
#include<stdlib.h> // 陪熱 婦溼 rand(), srand() л熱 餌辨
#include<time.h> // time() л熱 餌辨
#include<Windows.h> // 夔樂璽 л熱 system("cls") 餌辨
#include<conio.h> // 酈爾萄 л熱 _kbhit(), _getch() 餌辨
#include<string.h> // 僥濠翮 л熱strcmp л熱 餌辨

// �飛� 撲薑 婦溼
int Start(); // 衛濛 �飛� 轎溘 л熱
int Rule(); // 敘罌 �飛� 轎溘 л熱
int Plate(); // 啪歜 っ 轎溘 л熱
int P1(); // 2檣辨 霞ч
int P2(); // 1檣辨 霞ч
int Choose(); // �飛� 摹鷗

 // 啪歜 婦溼
int Rand(); // 輿餌嬪 掉葬朝 л熱
int IsFourCard(int a, int b, int c, int d, int e); // 嫡擎 熱 醞 4偃 檜鼻檜 偽擎雖 っ欽ж朝 л熱
int IsFullHouse(int a, int b, int c, int d, int e); // 嫡擎 熱 醞 3偃, 2偃陛 陝陝 偽擎雖 っ欽ж朝 л熱
int IsSStraight(int a, int b, int c, int d, int e); // 碟擎 熱 醞 4偃 檜鼻檜 翱樓и雖 っ欽ж朝 л熱
int IsLStraight(int a, int b, int c, int d, int e); // 嫡擎 熱 5偃陛 翱樓и雖 っ欽ж朝 л熱

void gotoxy(int x, int y) { // 夔樂璽縑憮 醴憮曖 謝ル 滲唳擊 嬪и л熱
    COORD Pos;
    Pos.X = x;
    Pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

int main() {
    Start();
    Choose();
}

int Start() {
    printf("﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥\n");
    printf("﹥                                                                                                        ﹥\n");
    printf("﹥                                                                                                        ﹥\n");
    printf("﹥                                                                                                        ﹥\n");
    printf("﹥                                                                                                        ﹥\n");
    printf("﹥                                                                                                        ﹥\n");
    printf("﹥                    ﹥      ﹥                                 ﹥                                       ﹥\n");
    printf("﹥                     ﹥    ﹥                                  ﹥                                       ﹥\n");
    printf("﹥                      ﹥  ﹥       ﹥﹥﹥                      ﹥              ﹥                       ﹥\n");
    printf("﹥                        ﹥               ﹥        ﹥﹥﹥      ﹥ ﹥﹥      ﹥﹥﹥﹥                    ﹥\n");
    printf("﹥                        ﹥         ﹥﹥﹥﹥       ﹥           ﹥﹥  ﹥        ﹥                       ﹥\n");
    printf("﹥                        ﹥        ﹥     ﹥       ﹥           ﹥    ﹥        ﹥                       ﹥\n");
    printf("﹥                        ﹥         ﹥﹥﹥﹥        ﹥﹥﹥      ﹥    ﹥         ﹥﹥                    ﹥\n");
    printf("﹥                                                                                                        ﹥\n");
    printf("﹥                                                                                                        ﹥\n");
    printf("﹥                                                                                                        ﹥\n");
    printf("﹥                                                                                                        ﹥\n");
    printf("﹥                                                                                                        ﹥\n");
    printf("﹥                                           2: 敘罌  3: 啪歜っ                                           ﹥\n");
    printf("﹥                                              4: 1檣辨 衛濛                                             ﹥\n");
    printf("﹥                                              5: 2檣辨 衛濛                                             ﹥\n");
    printf("﹥                                                                                                        ﹥\n");
    printf("﹥                                                                                                        ﹥\n");
    printf("﹥                              (敘罌擊 窕 檗橫爾衛堅 衛濛п輿衛望 夥奧棲棻)                              ﹥\n");
    printf("﹥                                                                                                        ﹥\n");
    printf("﹥                                                                                                        ﹥\n");
    printf("﹥                                                                                             1603 梯翕綴﹥\n");
    printf("﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥\n");
}

int Choose() {
    while (1) {
        if (_kbhit()) { // _kbhit(): ゎ模縑 0, 酈爾萄蒂 援腦賊 1
            switch (_getch()) { // _getch(): 餌辨濠陛 援艇 濠っ曖 嬴蝶酈 囀萄 奩��
            case 49: // 49: 1曖 嬴蝶酈囀萄
                system("cls"); // 夔樂璽 檜瞪曖 �飛� 薯剪
                Start();
                break;
            case 50: // 50: 2曖 嬴蝶酈囀萄
                system("cls");
                Rule();
                break;
            case 51: // 51: 3曖 嬴蝶酈囀萄
                system("cls");
                Plate();
                break;
            case 52: // 51: 3曖 嬴蝶酈囀萄
                system("cls");
                P1();
                break;
            case 53: // 52: 4曖 嬴蝶酈囀萄
                system("cls");
                P2();
                break;
            }
        }
    }
}

int Rule() {
    printf("﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥\n");
    printf("﹥                                                                                                        ﹥\n");
    printf("﹥                                                                                                        ﹥\n");
    printf("﹥                                                                                                        ﹥\n");
    printf("﹥                                                   敘罌                                                 ﹥\n");
    printf("﹥                                                                                                        ﹥\n");
    printf("﹥                     跡ル: 12廓曖 離滔翕寰 12蘊擊 瓣錶 賅萇 蘊 璋濠 м檜 渦 贖 薹檜 蝓葬                ﹥\n");
    printf("﹥                                                                                                        ﹥\n");
    printf("﹥                                                                                                        ﹥\n");
    printf("﹥                                           и 離滔 翕寰曖 霞ч                                          ﹥\n");
    printf("﹥                                 1. 輿餌嬪 5偃(A, B, C, D, E)蒂 掉萼棻                                  ﹥\n");
    printf("﹥           2. 檜醞 棻衛 掉葬堅 輿餌嬪 檜葷擊 scanf ⑽衝戲煎 翱殖嬴 殮溘ж堅 釭該雖朝 爾婦и棻.          ﹥\n");
    printf("﹥                         (蕨: ACD(縛攪) -> A, C, D 棻衛 掉葡, 0 -> 棻衛 掉葬晦 謙猿)                    ﹥\n");
    printf("﹥                         3. и 離滔 翕寰 譆渠 2廓梱雖 渦 掉萵 熱 氈棻(評塭憮 識 3廓)                    ﹥\n");
    printf("﹥          4. 檜溢啪 掉溥憮 橢擎 5偃曖 輿餌嬪 高戲煎 '啪歜 っ'曖 12 蘊 醞 鼠褻勒 и 蘊虜擊 瓣遴棻        ﹥\n");
    printf("﹥                            (Sun Total, Bonus, Total擎 濠翕戲煎 瓣錶雖朝 蘊檜棻)                        ﹥\n");
    printf("﹥                     5. и 蘊擊 瓣辦賊 濠褐曖 離滔陛 部釭堅 鼻渠縑啪 離滔陛 剩橫除棻                    ﹥\n");
    printf("﹥                                                                                                        ﹥\n");
    printf("﹥                     瓣遴 蘊擎 檜�釋� 離滔縑 夥羚 熱 橈堅 瓣辦雖 彊擎 棻艇 蘊擊 瓣遴棻                  ﹥\n");
    printf("﹥                                                                                                        ﹥\n");
    printf("﹥                      賅萇 餌塋檜 12 離滔翕寰 12 偃曖 蘊擊 賅舒 瓣辦賊 啪歜 謙猿                        ﹥\n");
    printf("﹥                                                                                                        ﹥\n");
    printf("﹥                                                                                                        ﹥\n");
    printf("﹥                                          1: 籀擠戲煎  3: 啪歜っ                                        ﹥\n");
    printf("﹥                                              4: 1檣辨 衛濛                                             ﹥\n");
    printf("﹥                                              5: 2檣辨 衛濛                                             ﹥\n");
    printf("﹥                                                                                                        ﹥\n");
    printf("﹥                                                                                                        ﹥\n");
    printf("﹥                                                                                                        ﹥\n");
    printf("﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥\n");
}

int Plate() {
    printf("﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥\n");
    printf("﹥                                                                                                        ﹥\n");
    printf("﹥   灰收收收收收收收收收收收有收收收收有收收收收汐                      灰收收收收收收收收收收收有收收收收有收收收收汐                                 ﹥\n");
    printf("﹥   弛   Aces    弛    弛    弛 釭螞 1菟曖 м        弛   Choice  弛    弛    弛  璋濠菟曖 м(褻勒X)             ﹥\n");
    printf("﹥   曳收收收收收收收收收收收朱收收收收朱收收收收朽 (蕨: 1 1 1 2 3 -> 3) 曳收收收收收收收收收收收朱收收收收朱收收收收朽  (蕨: 3 4 4 6 6 -> 18)          ﹥\n");
    printf("﹥   弛   Duces   弛    弛    弛 釭螞 2菟曖 м        弛4 of a Kind弛    早    弛  啻 璋濠陛 偽擊 陽, 璋濠 м     ﹥\n");
    printf("﹥   曳收收收收收收收收收收收朱收收收收朱收收收收朽 (蕨: 1 2 2 2 2 -> 8) 曳收收收收收收收收收收收朱收收收收朱收收收收朽  (蕨: 4 5 5 5 5 -> 24)          ﹥\n");
    printf("﹥   弛   Threes  弛    弛    弛 釭螞 3菟曖 м        弛 Full House弛    弛    弛  撢, 萃檜 陝陝 偽擊 陽, м      ﹥\n");
    printf("﹥   曳收收收收收收收收收收收朱收收收收朱收收收收朽 (蕨: 1 2 2 4 5 -> 0) 曳收收收收收收收收收收收朱收收收收朱收收收收朽  (蕨: 3 3 3 6 6 -> 24)          ﹥\n");
    printf("﹥   弛   Fours   弛    弛    弛 釭螞 4菟曖 м        弛 S.Straight弛    弛    弛  啻 璋濠陛 翱樓衛, 堅薑 15薄    ﹥\n");
    printf("﹥   曳收收收收收收收收收收收朱收收收收朱收收收收朽                      曳收收收收收收收收收收收托收收收收朱收收收收朽  (蕨: 1 2 3 4 6 -> 15)          ﹥\n");
    printf("﹥   弛   Fives   弛    弛    弛 釭螞 5菟曖 м        弛 L.Straight弛    弛    弛  賅萇 璋濠陛 翱樓衛, 堅薑 30薄  ﹥\n");
    printf("﹥   曳收收收收收收收收收收收朱收收收收朱收收收收朽                      曳收收收收收收收收收收收朱收收收收朱收收收收朽  (蕨: 2 3 4 5 6 -> 30)          ﹥\n");
    printf("﹥   弛   Sixes   弛    弛    弛 釭螞 6菟曖 м        弛   Yacht   弛    弛    弛  賅萇 璋濠陛 偽擊衛, 堅薑 50薄  ﹥\n");
    printf("﹥   曲收收收收收收收收收收收朴收收收收朴收收收收旭                      曲收收收收收收收收收收收朴收收收收朴收收收收旭  (蕨: 1 1 1 1 1 -> 50)          ﹥\n");
    printf("﹥   灰收收收收收收收收收收收有收收收收有收收收收汐                      灰收收收收收收收收收收收有收收收收有收收收收汐                                 ﹥\n");
    printf("﹥   弛 Sub Total 弛    弛    弛 嬪 罹撓 蘊菟曖 м    弛   Total   弛    弛    弛  翮舒 蘊菟曖 識м               ﹥\n");
    printf("﹥   曳收收收收收收收收收收收朱收收收收朱收收收收朽                      曲收收收收收收收收收收收朴收收收收朴收收收收旭                                 ﹥\n");
    printf("﹥   弛   Bonus   弛    弛    弛 Sub Total >= 63檜賊 +35                                                      ﹥\n");
    printf("﹥   曲收收收收收收收收收收收朴收收收收朴收收收收旭 斜溢雖 彊戲賊 +0                                                             ﹥\n");
    printf("﹥                                                                                                        ﹥\n");
    printf("﹥       (4 of a Kind, Full House, S.Straight, L.straight, Yacht 陝陝 褻勒 碳虜褶衛 瓣辦溥ж賊 0薄)       ﹥\n");
    printf("﹥                                                                                                        ﹥\n");
    printf("﹥                                                                                                        ﹥\n");
    printf("﹥                                          1: 籀擠戲煎  2: 敘罌                                          ﹥\n");
    printf("﹥                                              4: 1檣辨 衛濛                                             ﹥\n");
    printf("﹥                                              5: 2檣辨 衛濛                                             ﹥\n");
    printf("﹥                                                                                                        ﹥\n");
    printf("﹥                                                                                                        ﹥\n");
    printf("﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥\n");
}

int P1() {
    srand((unsigned int)time(NULL));
    int Aces = 0, Duces = 0, Threes = 0, Fours = 0, Fives = 0, Sixes = 0, Choice = 0, Four_Kind = 0, Full_House = 0, S_Straight = 0, L_Straight = 0, Yacht = 0;
    int used[13] = { 0, }; //  檜嘐 餌辨и 蘊曖 廓�ㄧ� 盪濰
    for (int k = 0; k < 13; k++) {
        int dice[5];
        char re[5] = "FFFF";
        for (int i = 0; i < 5; i++)
            dice[i] = Rand();
        int Sub_Total = Aces + Duces + Threes + Fours + Fives + Sixes;
        int Bonus = (Sub_Total >= 63) ? 35 : 0; // Sub_Total 高檜 63 檜鼻檜賊 +35, 嘐虜檜賊 +0
        int Total = Sub_Total + Choice + Four_Kind + Full_House + S_Straight + L_Straight + Yacht + Bonus;
        if (k == 12) { //12廓簞 離滔陛 部釭賊 轎溘腎朝 �飛� & 1檣辨 啪歜 謙猿
            system("cls");
            printf("﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥\n");
            printf("﹥                                                                                                        ﹥\n");
            printf("﹥                                                 啪歜 謙猿 !                                            ﹥\n");
            printf("﹥                                                                                                        ﹥\n");
            printf("﹥   灰收收收收收收收收收收收有收收收收汐   灰收收收收收收收收收收收有收收收收汐                                                              ﹥\n");
            printf("﹥  1弛   Aces    弛 %2d 弛 7 弛   Choice  弛 %2d 弛                                                              ﹥\n", Aces, Choice);
            printf("﹥   曳收收收收收收收收收收收朱收收收收朽   曳收收收收收收收收收收收朱收收收收朽                                                              ﹥\n");
            printf("﹥  2弛   Duces   弛 %2d 弛 8 弛4 of a Kind弛 %2d 早                                                              ﹥\n", Duces, Four_Kind);
            printf("﹥   曳收收收收收收收收收收收朱收收收收朽   曳收收收收收收收收收收收朱收收收收朽                                                              ﹥\n");
            printf("﹥  3弛   Threes  弛 %2d 弛 9 弛 Full House弛 %2d 弛                            識薄                              ﹥\n", Threes, Full_House);
            printf("﹥   曳收收收收收收收收收收收朱收收收收朽   曳收收收收收收收收收收收朱收收收收朽                                                              ﹥\n");
            printf("﹥  4弛   Fours   弛 %2d 弛 10弛 S.Straight弛 %2d 弛                           %3d 薄                             ﹥\n", Fours, S_Straight, Total);
            printf("﹥   曳收收收收收收收收收收收朱收收收收朽   曳收收收收收收收收收收收托收收收收朽                                                              ﹥\n");
            printf("﹥  5弛   Fives   弛 %2d 弛 11弛 L.Straight弛 %2d 弛                                                              ﹥\n", Fives, L_Straight);
            printf("﹥   曳收收收收收收收收收收收朱收收收收朽   曳收收收收收收收收收收收朱收收收收朽                                                              ﹥\n");
            printf("﹥  6弛   Sixes   弛 %2d 弛 12弛   Yacht   弛 %2d 弛                                                              ﹥\n", Sixes, Yacht);
            printf("﹥   曲收收收收收收收收收收收朴收收收收旭   曲收收收收收收收收收收收朴收收收收旭                                                              ﹥\n");
            printf("﹥   灰收收收收收收收收收收收有收收收收汐   灰收收收收收收收收收收收有收收收收汐                                                              ﹥\n");
            printf("﹥   弛 Sub Total 弛 %3d弛   弛   Total   弛 %3d弛                                                              ﹥\n", Sub_Total, Total);
            printf("﹥   曳收收收收收收收收收收收朱收收收收朽   曲收收收收收收收收收收收朴收收收收旭                                                              ﹥\n");
            printf("﹥   弛   Bonus   弛 +%2d弛                                                                                   ﹥\n", Bonus);
            printf("﹥   曲收收收收收收收收收收收朴收收收收旭                                                                                   ﹥\n");
            printf("﹥                                                                                                        ﹥\n");
            printf("﹥                                               1: 籀擠戲煎                                              ﹥\n");
            printf("﹥                                            2: 敘罌  3: 啪歜っ                                          ﹥\n");
            printf("﹥                                              4: 1檣辨 衛濛                                             ﹥\n");
            printf("﹥                                              5: 2檣辨 衛濛                                             ﹥\n");
            printf("﹥                                                                                                        ﹥\n");
            printf("﹥                                                                                                        ﹥\n");
            printf("﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥\n");
            break;
        }
        system("cls");
        printf("﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥\n");
        printf("﹥                                                                                                        ﹥\n");
        printf("﹥   灰收收收收收收收收收收收有收收收收汐   灰收收收收收收收收收收收有收收收收汐                                                              ﹥\n");
        printf("﹥  1弛   Aces    弛 %2d 弛 7 弛   Choice  弛 %2d 弛                                                              ﹥\n", Aces, Choice);
        printf("﹥   曳收收收收收收收收收收收朱收收收收朽   曳收收收收收收收收收收收朱收收收收朽                                                              ﹥\n");
        printf("﹥  2弛   Duces   弛 %2d 弛 8 弛4 of a Kind弛 %2d 早                                                              ﹥\n", Duces, Four_Kind);
        printf("﹥   曳收收收收收收收收收收收朱收收收收朽   曳收收收收收收收收收收收朱收收收收朽                                                              ﹥\n");
        printf("﹥  3弛   Threes  弛 %2d 弛 9 弛 Full House弛 %2d 弛                        渡褐曖 輿餌嬪                         ﹥\n", Threes, Full_House);
        printf("﹥   曳收收收收收收收收收收收朱收收收收朽   曳收收收收收收收收收收收朱收收收收朽                                                              ﹥\n");
        printf("﹥  4弛   Fours   弛 %2d 弛 10弛 S.Straight弛 %2d 弛                A      B      C      D      E                 ﹥\n", Fours, S_Straight);
        printf("﹥   曳收收收收收收收收收收收朱收收收收朽   曳收收收收收收收收收收收托收收收收朽                                                              ﹥\n");
        printf("﹥  5弛   Fives   弛 %2d 弛 11弛 L.Straight弛 %2d 弛                %d      %d      %d      %d      %d                 ﹥\n", Fives, L_Straight, dice[0], dice[1], dice[2], dice[3], dice[4]);
        printf("﹥   曳收收收收收收收收收收收朱收收收收朽   曳收收收收收收收收收收收朱收收收收朽                                                              ﹥\n");
        printf("﹥  6弛   Sixes   弛 %2d 弛 12弛   Yacht   弛 %2d 弛                                                              ﹥\n", Sixes, Yacht);
        printf("﹥   曲收收收收收收收收收收收朴收收收收旭   曲收收收收收收收收收收收朴收收收收旭                                                              ﹥\n");
        printf("﹥   灰收收收收收收收收收收收有收收收收汐   灰收收收收收收收收收收收有收收收收汐                                                              ﹥\n");
        printf("﹥   弛 Sub Total 弛 %3d弛   弛   Total   弛 %3d弛                                                              ﹥\n", Sub_Total, Total);
        printf("﹥   曳收收收收收收收收收收收朱收收收收朽   曲收收收收收收收收收收收朴收收收收旭                                                              ﹥\n");
        printf("﹥   弛   Bonus   弛 +%2d弛                                                                                   ﹥\n", Bonus);
        printf("﹥   曲收收收收收收收收收收收朴收收收收旭                                                                                   ﹥\n");
        printf("﹥                                                                                                        ﹥\n");
        printf("﹥                                                                                                        ﹥\n");
        printf("﹥           離滔: %2d / 12             夥紱堅 談擎 輿餌嬪 :                                               ﹥\n", k + 1);
        printf("﹥                                                                                                        ﹥\n");
        printf("﹥                                                                                                        ﹥\n");
        printf("﹥                                                                                                        ﹥\n");
        printf("﹥                                                                                                        ﹥\n");
        printf("﹥                                                                                                        ﹥\n");
        printf("﹥                                                                                                        ﹥\n");
        printf("﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥\n");
        for (int j = 0; j < 2; j++) { // 棻衛 掉葬晦 褒ч(譆渠 2��)
            gotoxy(60, 22);
            scanf("%s", re); // re朝 棻衛 掉葬堅 談擎 輿餌嬪 檜葷擊 盪濰п 場擎 僥濠翮
            if (!(strcmp(re, "0"))) {
                char re[5] = "FFFF";
                break; // 棻衛 掉葬堅 談擎 re縑 0檜 殮溘 嫡戲賊 棻衛 掉葬晦 驍轎
            }
            for (int i = 0; i < 5; i++) { //re縑 A, B, C, D, E陛 氈朝雖 奩犒ж貊 switch-case煎 碟戮, 氈戲賊 棻衛 掉葡
                switch (re[i]) {
                case 'A':
                    dice[0] = Rand();
                    gotoxy(60, 11);
                    printf("%d", dice[0]);
                    break;
                case 'B':
                    dice[1] = Rand();
                    gotoxy(67, 11);
                    printf("%d", dice[1]);
                    break;
                case 'C':
                    dice[2] = Rand();
                    gotoxy(74, 11);
                    printf("%d", dice[2]);
                    break;
                case 'D':
                    dice[3] = Rand();
                    gotoxy(81, 11);
                    printf("%d", dice[3]);
                    break;
                case 'E':
                    dice[4] = Rand();
                    gotoxy(88, 11);
                    printf("%d", dice[4]);
                    break;
                }
            }
            gotoxy(60, 22);
            printf("     ");
            char re[5] = "FFFF";
        }
        int num;
        while (1) { //  蘊 殮溘 & 殮溘嫡擎 蘊 廓�ㄟ� 檜瞪婁 醞犒檣雖 っ滌
            int flag = 0; //  flag陛 0檜賊 啗樓 霞ч, 1檜賊 營殮溘
            gotoxy(39, 24);
            printf("瓣辦堅 談擎 蘊擊 摹鷗ж褊衛螃:        ");
            gotoxy(70, 24);
            scanf("%d", &num); // 夥紱堅 談擎 蘊曖 廓�� 殮溘
            for (int n = 0; n < 12; n++) {
                if (used[n] == num)
                    flag++;
            }
            if (!flag)
                break;
            gotoxy(39, 26);
            printf("檜嘐 瓣辦剪釭 橈朝 蘊殮棲棻");
        }
        switch (num) { // 殮溘и 蘊曖 高 盪濰
        case 1:
            for (int m = 0; m < 5; m++) { // 1檜 氈朝虜躑 Aces縑 渦л
                if (dice[m] == 1)
                    Aces += dice[m];
            }
            used[k] = 1;
            break;
        case 2:
            for (int m = 0; m < 5; m++) { // 2陛 氈朝虜躑 Duces縑 渦л
                if (dice[m] == 2)
                    Duces += dice[m];
            }
            used[k] = 2;
            break;
        case 3:
            for (int m = 0; m < 5; m++) { // 3檜 氈朝虜躑 Threes縑 渦л
                if (dice[m] == 3)
                    Threes += dice[m];
            }
            used[k] = 3;
            break;
        case 4:
            for (int m = 0; m < 5; m++) { // 4陛 氈朝虜躑 Fours縑 渦л
                if (dice[m] == 4)
                    Fours += dice[m];
            }
            used[k] = 4;
            break;
        case 5:
            for (int m = 0; m < 5; m++) { // 5陛 氈朝虜躑 Fives縑 渦л
                if (dice[m] == 5)
                    Fives += dice[m];
            }
            used[k] = 5;
            break;
        case 6:
            for (int m = 0; m < 5; m++) { // 6檜 氈朝虜躑 Sixes縑 渦л
                if (dice[m] == 6)
                    Sixes += dice[m];
            }
            used[k] = 6;
            break;
        case 7:
            for (int m = 0; m < 5; m++) // 嫡擎 熱蒂 賅舒 渦л
                Choice += dice[m];
            used[k] = 7;
            break;
        case 8:
            if (IsFourCard(dice[0], dice[1], dice[2], dice[3], dice[4])) { // 啻偃 檜鼻檜 偽擎雖 っ滌, 虜褶ж賊 賅舒 渦л, 嬴棲賊 0薄
                for (int m = 0; m < 5; m++)
                    Four_Kind += dice[m];
            }
            used[k] = 8;
            break;
        case 9:
            if (IsFullHouse(dice[0], dice[1], dice[2], dice[3], dice[4])) { // 3偃, 2偃 陝陝 偽擎雖 っ滌, 虜褶ж賊 賅舒 渦л, 嬴棲賊 0薄
                for (int m = 0; m < 5; m++)
                    Full_House += dice[m];
            }
            used[k] = 9;
            break;
        case 10:
            if (IsSStraight(dice[0], dice[1], dice[2], dice[3], dice[4])) // 啻偃 檜鼻檜 翱樓и雖 っ滌, 虜褶ж賊 15薄, 嬴棲賊 0薄
                S_Straight = 15;
            used[k] = 10;
            break;
        case 11:
            if (IsLStraight(dice[0], dice[1], dice[2], dice[3], dice[4])) { // 5偃 賅舒 翱樓и雖 っ滌, 虜褶ж賊 30薄, 嬴棲賊 0薄
                L_Straight = 30;
            }
            used[k] = 11;
            break;
        case 12:
            if (dice[0] == dice[1] && dice[1] == dice[2] && dice[2] == dice[3] && dice[3] == dice[4]) // 5偃 賅舒 偽擎雖 っ滌, 虜褶ж賊 50薄, 嬴棲賊 0薄
                Yacht = 50;
            used[k] = 12;
            break;
        default:
            gotoxy(39, 26);
            printf("檜嘐 瓣辦剪釭 橈朝 蘊殮棲棻");
        }
    }
}

int P2() {
    srand((unsigned int)time(NULL));
    int Aces1 = 0, Duces1 = 0, Threes1 = 0, Fours1 = 0, Fives1 = 0, Sixes1 = 0, Choice1 = 0, Four_Kind1 = 0, Full_House1 = 0, S_Straight1 = 0, L_Straight1 = 0, Yacht1 = 0;
    int Aces2 = 0, Duces2 = 0, Threes2 = 0, Fours2 = 0, Fives2 = 0, Sixes2 = 0, Choice2 = 0, Four_Kind2 = 0, Full_House2 = 0, S_Straight2 = 0, L_Straight2 = 0, Yacht2 = 0;
    int used1[13] = { 0, }; //  檜嘐 餌辨и 蘊曖 廓�ㄧ� 盪濰
    int used2[13] = { 0, };
    for (int k = 0; k < 13; k++) {
        int dice[5];
        char re[5] = "FFFF";
        char Re[5] = "FFFF";
        for (int i = 0; i < 5; i++)
            dice[i] = Rand();
        int Sub_Total1 = Aces1 + Duces1 + Threes1 + Fours1 + Fives1 + Sixes1;
        int Bonus1 = (Sub_Total1 >= 63) ? 35 : 0; // Sub_Total 高檜 63 檜鼻檜賊 +35, 嘐虜檜賊 +0
        int Total1 = Sub_Total1 + Choice1 + Four_Kind1 + Full_House1 + S_Straight1 + L_Straight1 + Yacht1 + Bonus1;
        int Sub_Total2 = Aces2 + Duces2 + Threes2 + Fours2 + Fives2 + Sixes2;
        int Bonus2 = (Sub_Total2 >= 63) ? 35 : 0; // Sub_Total 高檜 63 檜鼻檜賊 +35, 嘐虜檜賊 +0
        int Total2 = Sub_Total2 + Choice2 + Four_Kind2 + Full_House2 + S_Straight2 + L_Straight2 + Yacht2 + Bonus2;
        if (k == 12) { //12廓簞 離滔陛 部釭賊 轎溘腎朝 �飛� & 2檣辨 啪歜 謙猿
            if (Total1 != Total2) {
                system("cls");
                printf("﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥\n");
                printf("﹥                                                                                                        ﹥\n");
                printf("﹥                                                 啪歜 謙猿 !                                            ﹥\n");
                printf("﹥                                                                                                        ﹥\n");
                printf("﹥   灰收收收收收收收收收收收有收收收收有收收收收汐   灰收收收收收收收收收收收有收收收收有收收收收汐                                                    ﹥\n");
                printf("﹥  1弛   Aces    弛 %2d 弛 %2d 弛 7 弛   Choice  弛 %2d 弛 %2d 弛                                                    ﹥\n", Aces1, Aces2, Choice1, Choice2);
                printf("﹥   曳收收收收收收收收收收收朱收收收收朱收收收收朽   曳收收收收收收收收收收收朱收收收收朱收收收收朽                                                    ﹥\n");
                printf("﹥  2弛   Duces   弛 %2d 弛 %2d 弛 8 弛4 of a Kind弛 %2d 早 %2d 弛                                                    ﹥\n", Duces1, Duces2, Four_Kind1, Four_Kind2);
                printf("﹥   曳收收收收收收收收收收收朱收收收收朱收收收收朽   曳收收收收收收收收收收收朱收收收收朱收收收收朽                                                    ﹥\n");
                printf("﹥  3弛   Threes  弛 %2d 弛 %2d 弛 9 弛 Full House弛 %2d 弛 %2d 弛                            識薄                    ﹥\n", Threes1, Threes2, Full_House1, Full_House2);
                printf("﹥   曳收收收收收收收收收收收朱收收收收朱收收收收朽   曳收收收收收收收收收收收朱收收收收朱收收收收朽                                                    ﹥\n");
                printf("﹥  4弛   Fours   弛 %2d 弛 %2d 弛 10弛 S.Straight弛 %2d 弛 %2d 弛                      %3d 薄  ||  %3d 薄            ﹥\n", Fours1, Fours2, S_Straight1, S_Straight2, Total1, Total2);
                printf("﹥   曳收收收收收收收收收收收朱收收收收朱收收收收朽   曳收收收收收收收收收收收朱收收收收托收收收收朽                                                    ﹥\n");
                printf("﹥  5弛   Fives   弛 %2d 弛 %2d 弛 11弛 L.Straight弛 %2d 弛 %2d 弛                           P%d 蝓葬                  ﹥\n", Fives1, Fives2, L_Straight1, L_Straight2, (Total1 > Total2) ? 1 : 2);
                printf("﹥   曳收收收收收收收收收收收朱收收收收朱收收收收朽   曳收收收收收收收收收收收朱收收收收朱收收收收朽                                                    ﹥\n");
                printf("﹥  6弛   Sixes   弛 %2d 弛 %2d 弛 12弛   Yacht   弛 %2d 弛 %2d 弛                                                    ﹥\n", Sixes1, Sixes2, Yacht1, Yacht2);
                printf("﹥   曲收收收收收收收收收收收朴收收收收朴收收收收旭   曲收收收收收收收收收收收朴收收收收朴收收收收旭                                                    ﹥\n");
                printf("﹥   灰收收收收收收收收收收收有收收收收有收收收收汐   灰收收收收收收收收收收收有收收收收有收收收收汐                                                    ﹥\n");
                printf("﹥   弛 Sub Total 弛 %3d弛 %3d弛   弛   Total   弛 %3d弛 %3d弛                                                    ﹥\n", Sub_Total1, Sub_Total2, Total1, Total2);
                printf("﹥   曳收收收收收收收收收收收朱收收收收朱收收收收朽   曲收收收收收收收收收收收朴收收收收朴收收收收旭                                                    ﹥\n");
                printf("﹥   弛   Bonus   弛 +%2d弛 +%2d弛                                                                              ﹥\n", Bonus1, Bonus2);
                printf("﹥   曲收收收收收收收收收收收朴收收收收朴收收收收旭                                                                              ﹥\n");
                printf("﹥                                                                                                        ﹥\n");
                printf("﹥                                               1: 籀擠戲煎                                              ﹥\n");
                printf("﹥                                            2: 敘罌  3: 啪歜っ                                          ﹥\n");
                printf("﹥                                              4: 1檣辨 衛濛                                             ﹥\n");
                printf("﹥                                              5: 2檣辨 衛濛                                             ﹥\n");
                printf("﹥                                                                                                        ﹥\n");
                printf("﹥                                                                                                        ﹥\n");
                printf("﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥\n");
                break;
            }
            system("cls");
            printf("﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥\n");
            printf("﹥                                                                                                        ﹥\n");
            printf("﹥                                                 啪歜 謙猿 !                                            ﹥\n");
            printf("﹥                                                                                                        ﹥\n");
            printf("﹥   灰收收收收收收收收收收收有收收收收有收收收收汐   灰收收收收收收收收收收收有收收收收有收收收收汐                                                    ﹥\n");
            printf("﹥  1弛   Aces    弛 %2d 弛 %2d 弛 7 弛   Choice  弛 %2d 弛 %2d 弛                                                    ﹥\n", Aces1, Aces2, Choice1, Choice2);
            printf("﹥   曳收收收收收收收收收收收朱收收收收朱收收收收朽   曳收收收收收收收收收收收朱收收收收朱收收收收朽                                                    ﹥\n");
            printf("﹥  2弛   Duces   弛 %2d 弛 %2d 弛 8 弛4 of a Kind弛 %2d 早 %2d 弛                                                    ﹥\n", Duces1, Duces2, Four_Kind1, Four_Kind2);
            printf("﹥   曳收收收收收收收收收收收朱收收收收朱收收收收朽   曳收收收收收收收收收收收朱收收收收朱收收收收朽                                                    ﹥\n");
            printf("﹥  3弛   Threes  弛 %2d 弛 %2d 弛 9 弛 Full House弛 %2d 弛 %2d 弛                            識薄                    ﹥\n", Threes1, Threes2, Full_House1, Full_House2);
            printf("﹥   曳收收收收收收收收收收收朱收收收收朱收收收收朽   曳收收收收收收收收收收收朱收收收收朱收收收收朽                                                    ﹥\n");
            printf("﹥  4弛   Fours   弛 %2d 弛 %2d 弛 10弛 S.Straight弛 %2d 弛 %2d 弛                     %3d 薄  ||  %3d 薄             ﹥\n", Fours1, Fours2, S_Straight1, S_Straight2, Total1, Total2);
            printf("﹥   曳收收收收收收收收收收收朱收收收收朱收收收收朽   曳收收收收收收收收收收收朱收收收收托收收收收朽                                                    ﹥\n");
            printf("﹥  5弛   Fives   弛 %2d 弛 %2d 弛 11弛 L.Straight弛 %2d 弛 %2d 弛                           鼠蝓睡                   ﹥\n", Fives1, Fives2, L_Straight1, L_Straight2);
            printf("﹥   曳收收收收收收收收收收收朱收收收收朱收收收收朽   曳收收收收收收收收收收收朱收收收收朱收收收收朽                                                    ﹥\n");
            printf("﹥  6弛   Sixes   弛 %2d 弛 %2d 弛 12弛   Yacht   弛 %2d 弛 %2d 弛                                                    ﹥\n", Sixes1, Sixes2, Yacht1, Yacht2);
            printf("﹥   曲收收收收收收收收收收收朴收收收收朴收收收收旭   曲收收收收收收收收收收收朴收收收收朴收收收收旭                                                    ﹥\n");
            printf("﹥   灰收收收收收收收收收收收有收收收收有收收收收汐   灰收收收收收收收收收收收有收收收收有收收收收汐                                                    ﹥\n");
            printf("﹥   弛 Sub Total 弛 %3d弛 %3d弛   弛   Total   弛 %3d弛 %3d弛                                                    ﹥\n", Sub_Total1, Sub_Total2, Total1, Total2);
            printf("﹥   曳收收收收收收收收收收收朱收收收收朱收收收收朽   曲收收收收收收收收收收收朴收收收收朴收收收收旭                                                    ﹥\n");
            printf("﹥   弛   Bonus   弛 +%2d弛 +%2d弛                                                                              ﹥\n", Bonus1, Bonus2);
            printf("﹥   曲收收收收收收收收收收收朴收收收收朴收收收收旭                                                                              ﹥\n");
            printf("﹥                                                                                                        ﹥\n");
            printf("﹥                                               1: 籀擠戲煎                                              ﹥\n");
            printf("﹥                                            2: 敘罌  3: 啪歜っ                                          ﹥\n");
            printf("﹥                                              4: 1檣辨 衛濛                                             ﹥\n");
            printf("﹥                                              5: 2檣辨 衛濛                                             ﹥\n");
            printf("﹥                                                                                                        ﹥\n");
            printf("﹥                                                                                                        ﹥\n");
            printf("﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥\n");
            break;
        }
        // P1離滔
        system("cls");
        printf("﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥\n");
        printf("﹥                                                                                                        ﹥\n");
        printf("﹥   灰收收收收收收收收收收收有收收收收有收收收收汐   灰收收收收收收收收收收收有收收收收有收收收收汐                                                    ﹥\n");
        printf("﹥  1弛   Aces    弛 %2d 弛 %2d 弛 7 弛   Choice  弛 %2d 弛 %2d 弛                                                    ﹥\n", Aces1, Aces2, Choice1, Choice2);
        printf("﹥   曳收收收收收收收收收收收朱收收收收朱收收收收朽   曳收收收收收收收收收收收朱收收收收朱收收收收朽                                                    ﹥\n");
        printf("﹥  2弛   Duces   弛 %2d 弛 %2d 弛 8 弛4 of a Kind弛 %2d 早 %2d 弛                渡褐曖 輿餌嬪                       ﹥\n", Duces1, Duces2, Four_Kind1, Four_Kind2);
        printf("﹥   曳收收收收收收收收收收收朱收收收收朱收收收收朽   曳收收收收收收收收收收收朱收收收收朱收收收收朽                                                    ﹥\n");
        printf("﹥  3弛   Threes  弛 %2d 弛 %2d 弛 9 弛 Full House弛 %2d 弛 %2d 弛        A      B      C      D      E               ﹥\n", Threes1, Threes2, Full_House1, Full_House2);
        printf("﹥   曳收收收收收收收收收收收朱收收收收朱收收收收朽   曳收收收收收收收收收收收朱收收收收朱收收收收朽                                                    ﹥\n");
        printf("﹥  4弛   Fours   弛 %2d 弛 %2d 弛 10弛 S.Straight弛 %2d 弛 %2d 弛        %d      %d      %d      %d      %d               ﹥\n", Fives1, Fives2, S_Straight1, S_Straight2, dice[0], dice[1], dice[2], dice[3], dice[4]);
        printf("﹥   曳收收收收收收收收收收收朱收收收收朱收收收收朽   曳收收收收收收收收收收收朱收收收收托收收收收朽                                                    ﹥\n");
        printf("﹥  5弛   Fives   弛 %2d 弛 %2d 弛 11弛 L.Straight弛 %2d 弛 %2d 弛                                                    ﹥\n", Fives1, Fives2, L_Straight1, L_Straight2);
        printf("﹥   曳收收收收收收收收收收收朱收收收收朱收收收收朽   曳收收收收收收收收收收收朱收收收收朱收收收收朽                                                    ﹥\n");
        printf("﹥  6弛   Sixes   弛 %2d 弛 %2d 弛 12弛   Yacht   弛 %2d 弛 %2d 弛                                                    ﹥\n", Sixes1, Sixes2, Yacht1, Yacht2);
        printf("﹥   曲收收收收收收收收收收收朴收收收收朴收收收收旭   曲收收收收收收收收收收收朴收收收收朴收收收收旭                                                    ﹥\n");
        printf("﹥   灰收收收收收收收收收收收有收收收收有收收收收汐   灰收收收收收收收收收收收有收收收收有收收收收汐                                                    ﹥\n");
        printf("﹥   弛 Sub Total 弛 %3d弛 %3d弛   弛   Total   弛 %3d弛 %3d弛                                                    ﹥\n", Sub_Total1, Sub_Total2, Total1, Total2);
        printf("﹥   曳收收收收收收收收收收收朱收收收收朱收收收收朽   曲收收收收收收收收收收收朴收收收收朴收收收收旭                                                    ﹥\n");
        printf("﹥   弛   Bonus   弛 +%2d弛 +%2d弛                                                                              ﹥\n", Bonus1, Bonus2);
        printf("﹥   曲收收收收收收收收收收收朴收收收收朴收收收收旭                                                                              ﹥\n");
        printf("﹥                                                                                                        ﹥\n");
        printf("﹥                                                                                                        ﹥\n");
        printf("﹥           離滔: %2d / 12  (P1 離滔)  夥紱堅 談擎 輿餌嬪 :                                               ﹥\n", k + 1);
        printf("﹥                                                                                                        ﹥\n");
        printf("﹥                                                                                                        ﹥\n");
        printf("﹥                                                                                                        ﹥\n");
        printf("﹥                                                                                                        ﹥\n");
        printf("﹥                                                                                                        ﹥\n");
        printf("﹥                                                                                                        ﹥\n");
        printf("﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥\n");
        for (int j = 0; j < 2; j++) { // 棻衛 掉葬晦 褒ч(譆渠 2��)
            gotoxy(60, 22);
            scanf("%s", re); // re朝 棻衛 掉葬堅 談擎 輿餌嬪 檜葷擊 盪濰п 場擎 僥濠翮
            if (!(strcmp(re, "0"))) {
                char re[5] = "FFFF";
                break; // 棻衛 掉葬堅 談擎 re縑 0檜 殮溘 嫡戲賊 棻衛 掉葬晦 驍轎
            }
            for (int i = 0; i < 5; i++) { //re縑 A, B, C, D, E陛 氈朝雖 奩犒ж貊 switch-case煎 碟戮, 氈戲賊 棻衛 掉葡
                switch (re[i]) {
                case 'A':
                    dice[0] = Rand();
                    gotoxy(62, 9);
                    printf("%d", dice[0]);
                    break;
                case 'B':
                    dice[1] = Rand();
                    gotoxy(69, 9);
                    printf("%d", dice[1]);
                    break;
                case 'C':
                    dice[2] = Rand();
                    gotoxy(76, 9);
                    printf("%d", dice[2]);
                    break;
                case 'D':
                    dice[3] = Rand();
                    gotoxy(83, 9);
                    printf("%d", dice[3]);
                    break;
                case 'E':
                    dice[4] = Rand();
                    gotoxy(90, 9);
                    printf("%d", dice[4]);
                    break;
                }
            }
            gotoxy(60, 22);
            printf("     ");
            char re[5] = "FFFF";
        }
        int num;
        while (1) { //  蘊 殮溘 & 殮溘嫡擎 蘊 廓�ㄟ� 檜瞪婁 醞犒檣雖 っ滌
            int flag = 0; //  flag陛 0檜賊 啗樓 霞ч, 1檜賊 營殮溘
            gotoxy(39, 24);
            printf("瓣辦堅 談擎 蘊擊 摹鷗ж褊衛螃:        ");
            gotoxy(70, 24);
            scanf("%d", &num); // 夥紱堅 談擎 蘊曖 廓�� 殮溘
            for (int n = 0; n < 12; n++) {
                if (used1[n] == num)
                    flag++;
            }
            if (!flag)
                break;
            gotoxy(39, 26);
            printf("檜嘐 瓣辦剪釭 橈朝 蘊殮棲棻");
        }
        switch (num) { // 殮溘и 蘊曖 高 盪濰
        case 1:
            for (int m = 0; m < 5; m++) { // 1檜 氈朝虜躑 Aces縑 渦л
                if (dice[m] == 1)
                    Aces1 += dice[m];
            }
            used1[k] = 1;
            break;
        case 2:
            for (int m = 0; m < 5; m++) { // 2陛 氈朝虜躑 Duces縑 渦л
                if (dice[m] == 2)
                    Duces1 += dice[m];
            }
            used1[k] = 2;
            break;
        case 3:
            for (int m = 0; m < 5; m++) { // 3檜 氈朝虜躑 Threes縑 渦л
                if (dice[m] == 3)
                    Threes1 += dice[m];
            }
            used1[k] = 3;
            break;
        case 4:
            for (int m = 0; m < 5; m++) { // 4陛 氈朝虜躑 Fours縑 渦л
                if (dice[m] == 4)
                    Fours1 += dice[m];
            }
            used1[k] = 4;
            break;
        case 5:
            for (int m = 0; m < 5; m++) { // 5陛 氈朝虜躑 Fives縑 渦л
                if (dice[m] == 5)
                    Fives1 += dice[m];
            }
            used1[k] = 5;
            break;
        case 6:
            for (int m = 0; m < 5; m++) { // 6檜 氈朝虜躑 Sixes縑 渦л
                if (dice[m] == 6)
                    Sixes1 += dice[m];
            }
            used1[k] = 6;
            break;
        case 7:
            for (int m = 0; m < 5; m++) // 嫡擎 熱蒂 賅舒 渦л
                Choice1 += dice[m];
            used1[k] = 7;
            break;
        case 8:
            if (IsFourCard(dice[0], dice[1], dice[2], dice[3], dice[4])) { // 啻偃 檜鼻檜 偽擎雖 っ滌, 虜褶ж賊 賅舒 渦л, 嬴棲賊 0薄
                for (int m = 0; m < 5; m++)
                    Four_Kind1 += dice[m];
            }
            used1[k] = 8;
            break;
        case 9:
            if (IsFullHouse(dice[0], dice[1], dice[2], dice[3], dice[4])) { // 3偃, 2偃 陝陝 偽擎雖 っ滌, 虜褶ж賊 賅舒 渦л, 嬴棲賊 0薄
                for (int m = 0; m < 5; m++)
                    Full_House1 += dice[m];
            }
            used1[k] = 9;
            break;
        case 10:
            if (IsSStraight(dice[0], dice[1], dice[2], dice[3], dice[4])) // 啻偃 檜鼻檜 翱樓и雖 っ滌, 虜褶ж賊 15薄, 嬴棲賊 0薄
                S_Straight1 = 15;
            used1[k] = 10;
            break;
        case 11:
            if (IsLStraight(dice[0], dice[1], dice[2], dice[3], dice[4])) { // 5偃 賅舒 翱樓и雖 っ滌, 虜褶ж賊 30薄, 嬴棲賊 0薄
                L_Straight1 = 30;
            }
            used1[k] = 11;
            break;
        case 12:
            if (dice[0] == dice[1] && dice[1] == dice[2] && dice[2] == dice[3] && dice[3] == dice[4]) // 5偃 賅舒 偽擎雖 っ滌, 虜褶ж賊 50薄, 嬴棲賊 0薄
                Yacht1 = 50;
            used1[k] = 12;
            break;
        default:
            gotoxy(39, 26);
            printf("檜嘐 瓣辦剪釭 橈朝 蘊殮棲棻");
        }

        // P2離滔
        for (int i = 0; i < 5; i++)
            dice[i] = Rand();
        Sub_Total1 = Aces1 + Duces1 + Threes1 + Fours1 + Fives1 + Sixes1;
        Bonus1 = (Sub_Total1 >= 63) ? 35 : 0; // Sub_Total 高檜 63 檜鼻檜賊 +35, 嘐虜檜賊 +0
        Total1 = Sub_Total1 + Choice1 + Four_Kind1 + Full_House1 + S_Straight1 + L_Straight1 + Yacht1 + Bonus1;
        Sub_Total2 = Aces2 + Duces2 + Threes2 + Fours2 + Fives2 + Sixes2;
        Bonus2 = (Sub_Total2 >= 63) ? 35 : 0; // Sub_Total 高檜 63 檜鼻檜賊 +35, 嘐虜檜賊 +0
        Total2 = Sub_Total2 + Choice2 + Four_Kind2 + Full_House2 + S_Straight2 + L_Straight2 + Yacht2 + Bonus2;
        system("cls");
        printf("﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥\n");
        printf("﹥                                                                                                        ﹥\n");
        printf("﹥   灰收收收收收收收收收收收有收收收收有收收收收汐   灰收收收收收收收收收收收有收收收收有收收收收汐                                                    ﹥\n");
        printf("﹥  1弛   Aces    弛 %2d 弛 %2d 弛 7 弛   Choice  弛 %2d 弛 %2d 弛                                                    ﹥\n", Aces1, Aces2, Choice1, Choice2);
        printf("﹥   曳收收收收收收收收收收收朱收收收收朱收收收收朽   曳收收收收收收收收收收收朱收收收收朱收收收收朽                                                    ﹥\n");
        printf("﹥  2弛   Duces   弛 %2d 弛 %2d 弛 8 弛4 of a Kind弛 %2d 早 %2d 弛                渡褐曖 輿餌嬪                       ﹥\n", Duces1, Duces2, Four_Kind1, Four_Kind2);
        printf("﹥   曳收收收收收收收收收收收朱收收收收朱收收收收朽   曳收收收收收收收收收收收朱收收收收朱收收收收朽                                                    ﹥\n");
        printf("﹥  3弛   Threes  弛 %2d 弛 %2d 弛 9 弛 Full House弛 %2d 弛 %2d 弛        A      B      C      D      E               ﹥\n", Threes1, Threes2, Full_House1, Full_House2);
        printf("﹥   曳收收收收收收收收收收收朱收收收收朱收收收收朽   曳收收收收收收收收收收收朱收收收收朱收收收收朽                                                    ﹥\n");
        printf("﹥  4弛   Fours   弛 %2d 弛 %2d 弛 10弛 S.Straight弛 %2d 弛 %2d 弛        %d      %d      %d      %d      %d               ﹥\n", Fives1, Fives2, S_Straight1, S_Straight2, dice[0], dice[1], dice[2], dice[3], dice[4]);
        printf("﹥   曳收收收收收收收收收收收朱收收收收朱收收收收朽   曳收收收收收收收收收收收朱收收收收托收收收收朽                                                    ﹥\n");
        printf("﹥  5弛   Fives   弛 %2d 弛 %2d 弛 11弛 L.Straight弛 %2d 弛 %2d 弛                                                    ﹥\n", Fives1, Fives2, L_Straight1, L_Straight2);
        printf("﹥   曳收收收收收收收收收收收朱收收收收朱收收收收朽   曳收收收收收收收收收收收朱收收收收朱收收收收朽                                                    ﹥\n");
        printf("﹥  6弛   Sixes   弛 %2d 弛 %2d 弛 12弛   Yacht   弛 %2d 弛 %2d 弛                                                    ﹥\n", Sixes1, Sixes2, Yacht1, Yacht2);
        printf("﹥   曲收收收收收收收收收收收朴收收收收朴收收收收旭   曲收收收收收收收收收收收朴收收收收朴收收收收旭                                                    ﹥\n");
        printf("﹥   灰收收收收收收收收收收收有收收收收有收收收收汐   灰收收收收收收收收收收收有收收收收有收收收收汐                                                    ﹥\n");
        printf("﹥   弛 Sub Total 弛 %3d弛 %3d弛   弛   Total   弛 %3d弛 %3d弛                                                    ﹥\n", Sub_Total1, Sub_Total2, Total1, Total2);
        printf("﹥   曳收收收收收收收收收收收朱收收收收朱收收收收朽   曲收收收收收收收收收收收朴收收收收朴收收收收旭                                                    ﹥\n");
        printf("﹥   弛   Bonus   弛 +%2d弛 +%2d弛                                                                              ﹥\n", Bonus1, Bonus2);
        printf("﹥   曲收收收收收收收收收收收朴收收收收朴收收收收旭                                                                              ﹥\n");
        printf("﹥                                                                                                        ﹥\n");
        printf("﹥                                                                                                        ﹥\n");
        printf("﹥           離滔: %2d / 12  (P2 離滔)  夥紱堅 談擎 輿餌嬪 :                                               ﹥\n", k + 1);
        printf("﹥                                                                                                        ﹥\n");
        printf("﹥                                                                                                        ﹥\n");
        printf("﹥                                                                                                        ﹥\n");
        printf("﹥                                                                                                        ﹥\n");
        printf("﹥                                                                                                        ﹥\n");
        printf("﹥                                                                                                        ﹥\n");
        printf("﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥\n");
        for (int j = 0; j < 2; j++) { // 棻衛 掉葬晦 褒ч(譆渠 2��)
            gotoxy(60, 22);
            scanf("%s", Re); // Re朝 棻衛 掉葬堅 談擎 輿餌嬪 檜葷擊 盪濰п 場擎 僥濠翮
            if (!(strcmp(Re, "0"))) {
                char re[5] = "FFFF";
                break; // 棻衛 掉葬堅 談擎 Re縑 0檜 殮溘 嫡戲賊 棻衛 掉葬晦 驍轎
            }
            for (int i = 0; i < 5; i++) { //Re縑 A, B, C, D, E陛 氈朝雖 奩犒ж貊 switch-case煎 碟戮, 氈戲賊 棻衛 掉葡
                switch (Re[i]) {
                case 'A':
                    dice[0] = Rand();
                    gotoxy(62, 9);
                    printf("%d", dice[0]);
                    break;
                case 'B':
                    dice[1] = Rand();
                    gotoxy(69, 9);
                    printf("%d", dice[1]);
                    break;
                case 'C':
                    dice[2] = Rand();
                    gotoxy(76, 9);
                    printf("%d", dice[2]);
                    break;
                case 'D':
                    dice[3] = Rand();
                    gotoxy(83, 9);
                    printf("%d", dice[3]);
                    break;
                case 'E':
                    dice[4] = Rand();
                    gotoxy(90, 9);
                    printf("%d", dice[4]);
                    break;
                }
            }
            gotoxy(60, 22);
            printf("     ");
            char Re[5] = "FFFF";
        }
        while (1) { //  蘊 殮溘 & 殮溘嫡擎 蘊 廓�ㄟ� 檜瞪婁 醞犒檣雖 っ滌
            int flag = 0; //  flag陛 0檜賊 啗樓 霞ч, 1檜賊 營殮溘
            gotoxy(39, 24);
            printf("瓣辦堅 談擎 蘊擊 摹鷗ж褊衛螃:        ");
            gotoxy(70, 24);
            scanf("%d", &num); // 夥紱堅 談擎 蘊曖 廓�� 殮溘
            for (int n = 0; n < 12; n++) {
                if (used2[n] == num)
                    flag++;
            }
            if (!flag)
                break;
            gotoxy(39, 26);
            printf("檜嘐 瓣辦剪釭 橈朝 蘊殮棲棻");
        }
        switch (num) { // 殮溘и 蘊曖 高 盪濰
        case 1:
            for (int m = 0; m < 5; m++) { // 1檜 氈朝虜躑 Aces縑 渦л
                if (dice[m] == 1)
                    Aces2 += dice[m];
            }
            used2[k] = 1;
            break;
        case 2:
            for (int m = 0; m < 5; m++) { // 2陛 氈朝虜躑 Duces縑 渦л
                if (dice[m] == 2)
                    Duces2 += dice[m];
            }
            used2[k] = 2;
            break;
        case 3:
            for (int m = 0; m < 5; m++) { // 3檜 氈朝虜躑 Threes縑 渦л
                if (dice[m] == 3)
                    Threes2 += dice[m];
            }
            used2[k] = 3;
            break;
        case 4:
            for (int m = 0; m < 5; m++) { // 4陛 氈朝虜躑 Fours縑 渦л
                if (dice[m] == 4)
                    Fours2 += dice[m];
            }
            used2[k] = 4;
            break;
        case 5:
            for (int m = 0; m < 5; m++) { // 5陛 氈朝虜躑 Fives縑 渦л
                if (dice[m] == 5)
                    Fives2 += dice[m];
            }
            used2[k] = 5;
            break;
        case 6:
            for (int m = 0; m < 5; m++) { // 6檜 氈朝虜躑 Sixes縑 渦л
                if (dice[m] == 6)
                    Sixes2 += dice[m];
            }
            used2[k] = 6;
            break;
        case 7:
            for (int m = 0; m < 5; m++) // 嫡擎 熱蒂 賅舒 渦л
                Choice2 += dice[m];
            used2[k] = 7;
            break;
        case 8:
            if (IsFourCard(dice[0], dice[1], dice[2], dice[3], dice[4])) { // 啻偃 檜鼻檜 偽擎雖 っ滌, 虜褶ж賊 賅舒 渦л, 嬴棲賊 0薄
                for (int m = 0; m < 5; m++)
                    Four_Kind2 += dice[m];
            }
            used2[k] = 8;
            break;
        case 9:
            if (IsFullHouse(dice[0], dice[1], dice[2], dice[3], dice[4])) { // 3偃, 2偃 陝陝 偽擎雖 っ滌, 虜褶ж賊 賅舒 渦л, 嬴棲賊 0薄
                for (int m = 0; m < 5; m++)
                    Full_House2 += dice[m];
            }
            used2[k] = 9;
            break;
        case 10:
            if (IsSStraight(dice[0], dice[1], dice[2], dice[3], dice[4])) // 啻偃 檜鼻檜 翱樓и雖 っ滌, 虜褶ж賊 15薄, 嬴棲賊 0薄
                S_Straight2 = 15;
            used2[k] = 10;
            break;
        case 11:
            if (IsLStraight(dice[0], dice[1], dice[2], dice[3], dice[4])) { // 5偃 賅舒 翱樓и雖 っ滌, 虜褶ж賊 30薄, 嬴棲賊 0薄
                L_Straight2 = 30;
            }
            used2[k] = 11;
            break;
        case 12:
            if (dice[0] == dice[1] && dice[1] == dice[2] && dice[2] == dice[3] && dice[3] == dice[4]) // 5偃 賅舒 偽擎雖 っ滌, 虜褶ж賊 50薄, 嬴棲賊 0薄
                Yacht2 = 50;
            used2[k] = 12;
            break;
        default:
            gotoxy(39, 26);
            printf("檜嘐 瓣辦剪釭 橈朝 蘊殮棲棻");
        }
    }
}

int Rand() {
    int a = 7;
    while (!(a > 0 && a < 7)) { //0~32767 高醞 1~6虜 髦葬堅 斜醞 ж釭 蹺繩
        a = rand();
    }
}

int IsFourCard(int a, int b, int c, int d, int e) {
    int count = 0; //罹晦憮睡攪 a, b, c, d, e 醞 4偃 檜鼻檜 偽擎雖 霜蕾 っ滌(5陛雖 ж萄囀註), 虜褶ж賊 count++
    if (a == b && b == c && c == d)
        count++;
    if (a == b && b == d && d == e)
        count++;
    if (a == b && b == d && d == e)
        count++;
    if (a == c && c == d && d == e)
        count++;
    if (b == c && c == d && d == e)
        count++;
    return count;
}

int IsFullHouse(int a, int b, int c, int d, int e) {
    int count = 0; // 罹晦憮睡攪 2偃, 3偃陛 翕衛縑 陝陝 偽擎雖 霜蕾 っ滌(10陛雖 ж萄囀註), 虜褶ж賊 count++
    if (a == b && c == d && d == e)
        count++;
    if (a == c && b == d && d == e)
        count++;
    if (a == d && b == c && c == e)
        count++;
    if (a == e && b == c && c == d)
        count++;
    if (b == c && a == d && d == e)
        count++;
    if (b == d && a == c && c == e)
        count++;
    if (b == e && a == c && c == d)
        count++;
    if (c == d && a == b && b == e)
        count++;
    if (c == e && a == b && b == d)
        count++;
    if (d == e && a == b && b == c)
        count++;
    return count;
}

int IsSStraight(int a, int b, int c, int d, int e) { // 1,2,3,4,5,6 曖 偃熱蒂 陝陝 撮橫 1,2,3,4 / 2,3,4,5 / 3,4,5,6 誰檜 襄營и雖 っ滌
    int one = 0, two = 0, three = 0, four = 0, five = 0, six = 0;
    switch (a) {
    case 1:
        one++;
        break;
    case 2:
        two++;
        break;
    case 3:
        three++;
        break;
    case 4:
        four++;
        break;
    case 5:
        five++;
        break;
    case 6:
        six++;
        break;
    }
    switch (b) {
    case 1:
        one++;
        break;
    case 2:
        two++;
        break;
    case 3:
        three++;
        break;
    case 4:
        four++;
        break;
    case 5:
        five++;
        break;
    case 6:
        six++;
        break;
    }
    switch (c) {
    case 1:
        one++;
        break;
    case 2:
        two++;
        break;
    case 3:
        three++;
        break;
    case 4:
        four++;
        break;
    case 5:
        five++;
        break;
    case 6:
        six++;
        break;
    }
    switch (d) {
    case 1:
        one++;
        break;
    case 2:
        two++;
        break;
    case 3:
        three++;
        break;
    case 4:
        four++;
        break;
    case 5:
        five++;
        break;
    case 6:
        six++;
        break;
    }
    switch (e) {
    case 1:
        one++;
        break;
    case 2:
        two++;
        break;
    case 3:
        three++;
        break;
    case 4:
        four++;
        break;
    case 5:
        five++;
        break;
    case 6:
        six++;
        break;
    }
    return (one > 0 && two > 0 && three > 0 && four > 0 || two > 0 && three > 0 && four > 0 && five > 0 || three > 0 && four > 0 || five > 0 && six > 0);
}

int IsLStraight(int a, int b, int c, int d, int e) { // 1,2,3,4,5,6 曖 偃熱蒂 陝陝 撮橫 1,2,3,4,5 / 2,3,4,5,6 誰檜 襄營и雖 っ滌
    int one = 0, two = 0, three = 0, four = 0, five = 0, six = 0;
    switch (a) {
    case 1:
        one++;
        break;
    case 2:
        two++;
        break;
    case 3:
        three++;
        break;
    case 4:
        four++;
        break;
    case 5:
        five++;
        break;
    case 6:
        six++;
        break;
    }
    switch (b) {
    case 1:
        one++;
        break;
    case 2:
        two++;
        break;
    case 3:
        three++;
        break;
    case 4:
        four++;
        break;
    case 5:
        five++;
        break;
    case 6:
        six++;
        break;
    }
    switch (c) {
    case 1:
        one++;
        break;
    case 2:
        two++;
        break;
    case 3:
        three++;
        break;
    case 4:
        four++;
        break;
    case 5:
        five++;
        break;
    case 6:
        six++;
        break;
    }
    switch (d) {
    case 1:
        one++;
        break;
    case 2:
        two++;
        break;
    case 3:
        three++;
        break;
    case 4:
        four++;
        break;
    case 5:
        five++;
        break;
    case 6:
        six++;
        break;
    }
    switch (e) {
    case 1:
        one++;
        break;
    case 2:
        two++;
        break;
    case 3:
        three++;
        break;
    case 4:
        four++;
        break;
    case 5:
        five++;
        break;
    case 6:
        six++;
        break;
    }
    return (one > 0 && two > 0 && three > 0 && four > 0 && five > 0 || two > 0 && three > 0 && four > 0 && five > 0 && six > 0) ? 1 : 0;
}