#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int main()
{
    int k, w;
    printf("안녕하세요 숫자 야구 프로그램입니다.\n");
    printf("숫자 야구 하시겠습니까?\n");
    printf("1.예 2.아니오\n");
    scanf("%d", &k);
    if (k == 2) {
        printf("안녕히계세요\n");
        return 0;
    }
    system("cls"); //실행창에서 기존에 있던 내용들을 사라지게 한다. 
    printf("레벨을 선택하세요\n");
    printf("1.보통 2.어려움 3.매우 어려움\n");
    scanf("%d", &w);
    srand(time(NULL));
    if (w == 1) {
        int n[4], a[4], b, s, count = 0;

        n[0] = rand() % 10;
        while (1)
        {
            n[1] = rand() % 10;
            if (n[1] != n[0])
            {
                break;
            }
        }
        while (1)
        {
            n[2] = rand() % 10;
            if ((n[2] != n[0]) && (n[2] != n[1])) // 숫자야구에서 겹치는 숫자가 없도록 하기 위한 방법이다. 
            {
                break;
            }
        }
        while (1)
        {
            n[3] = rand() % 10;
            if ((n[3] != n[0]) && (n[3] != n[1]) && (n[3] != n[2]))
            {
                break;
            }
        }
        if (k == 1) {
            printf("그럼 시작하겠습니다.\n");
            system("cls");
            while (1)
            {
                b = 0, s = 0;
                printf("서로 다른 0~9사이의 숫자 4개를 입력하세요.");
                for (int i = 0; i <= 3; i++)
                {
                    scanf("%d", &a[i]);
                    if (a[i] == n[i])
                    {
                        s++;
                    }
                    for (int j = 0; j <= 3; j++)
                    {
                        if (a[i] == n[j])
                        {
                            b++;
                        }
                    }
                }
                b -= s;
                count++;
                printf("%d ball,%d strike\n", b, s);
                printf("%d번 했습니다.\n", count);
                if (count > 8) {
                    printf("당신은 저를 이길 수 없습니다. 다음에 도전하세요.\n");
                    printf("정답은 %d %d %d %d입니다.", n[0], n[1], n[2], n[3]);
                    break;
                }
                if (b == 0 && s == 0)
                {
                    printf("out!!!\n");
                }
                if (s == 4)
                {
                    printf("정답입니다. 당신 참 똑똑하네요!\n");
                    break;
                }
            }
        }
    }
    else if (w == 2) {
        int n[5], a[5], b, s, count = 0;

        n[0] = rand() % 10;
        while (1)
        {
            n[1] = rand() % 10;
            if (n[1] != n[0])
            {
                break;
            }
        }
        while (1)
        {
            n[2] = rand() % 10;
            if ((n[2] != n[0]) && (n[2] != n[1]))
            {
                break;
            }
        }
        while (1)
        {
            n[3] = rand() % 10;
            if ((n[3] != n[0]) && (n[3] != n[1]) && (n[3] != n[2]))
            {
                break;
            }
        }
        while (1)
        {
            n[4] = rand() % 10;
            if ((n[4] != n[0]) && (n[4] != n[1]) && (n[4] != n[2]) && (n[4] != n[3]))
            {
                break;
            }
        }
        if (k == 1) {
            printf("그럼 시작하겠습니다.\n");
            system("cls");
            while (1)
            {
                b = 0, s = 0;
                printf("서로 다른 0~9사이의 숫자 5개를 입력하세요.");
                for (int i = 0; i <= 4; i++)
                {
                    scanf("%d", &a[i]);
                    if (a[i] == n[i])
                    {
                        s++;
                    }
                    for (int j = 0; j <= 4; j++)
                    {
                        if (a[i] == n[j])
                        {
                            b++;
                        }
                    }
                }
                b -= s;
                count++;
                printf("%d ball,%d strike\n", b, s);
                printf("%d번 했습니다.\n", count);
                if (count > 11) {
                    printf("당신은 저를 이길 수 없습니다. 다음에 도전하세요.\n");
                    printf("정답은 %d %d %d %d %d입니다.", n[0], n[1], n[2], n[3], n[4]);
                    break;
                }
                if (b == 0 && s == 0)
                {
                    printf("out!!!\n");
                }
                if (s == 5)
                {
                    printf("정답입니다. 당신 참 똑똑하네요!\n");
                    break;
                }
            }
        }
    }
    else {
        int n[5], a[5], b, s, count = 0;

        n[0] = rand() % 10;
        while (1)
        {
            n[1] = rand() % 10;
            if (n[1] != n[0])
            {
                break;
            }
        }
        while (1)
        {
            n[2] = rand() % 10;
            if ((n[2] != n[0]) && (n[2] != n[1]))
            {
                break;
            }
        }
        while (1)
        {
            n[3] = rand() % 10;
            if ((n[3] != n[0]) && (n[3] != n[1]) && (n[3] != n[2]))
            {
                break;
            }
        }
        while (1)
        {
            n[4] = rand() % 10;
            if ((n[4] != n[0]) && (n[4] != n[1]) && (n[4] != n[2]) && (n[4] != n[3]))
            {
                break;
            }
        }
        while (1)
        {
            n[5] = rand() % 10;
            if ((n[5] != n[0]) && (n[5] != n[1]) && (n[5] != n[2]) && (n[5] != n[3]) && (n[5] != n[4]))
            {
                break;
            }
        }

        if (k == 1) {
            printf("그럼 시작하겠습니다.\n");
            system("cls");
            while (1)
            {
                b = 0, s = 0;
                printf("서로 다른 0~9사이의 숫자 6개를 입력하세요.");
                for (int i = 0; i <= 5; i++)
                {
                    scanf("%d", &a[i]);
                    if (a[i] == n[i])
                    {
                        s++;
                    }
                    for (int j = 0; j <= 5; j++)
                    {
                        if (a[i] == n[j])
                        {
                            b++;
                        }
                    }
                }
                b -= s;
                count++;
                printf("%d ball,%d strike\n", b, s);
                printf("%d번 했습니다.\n", count);
                if (count > 14) {
                    printf("당신은 저를 이길 수 없습니다. 다음에 도전하세요.\n");
                    printf("정답은 %d %d %d %d %d %d입니다.", n[0], n[1], n[2], n[3], n[4], n[5]);
                    break;
                }
                if (b == 0 && s == 0)
                {
                    printf("out!!!\n");
                }
                if (s == 6)
                {
                    printf("정답입니다. 당신 참 똑똑하네요!\n");
                    break;
                }
            }
        }
        return 0;
    }
}