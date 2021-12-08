#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <io.h>
#include <conio.h>
#pragma comment (lib, "winmm.lib")
#include <mmsystem.h>;

int cnt = 0;
int re = 0;
char now_play[100] = { '\0' };
void music_forward();   //다음 음악 재생
void music_backward();  //이전 음악 재생
void music_find();      //음악 찾기
void music_stop();      //음악 정지
char* music_file();      //음악 이름 출력

int main(void)
{
    int answer, i;
    while (1)
    {
        printf("현재 폴더에 있는 음악 목록입니다.\n");
        char(*fp)[100] = music_file();
        for (i = 2; i < cnt; i++)
        {
            printf("%d번째 파일:%s\n", i - 1, fp[i]);
        }
        printf("1. 음악 찾기\n2. 음악 정지\n3. 이전 음악 재생\n4. 다음 음악 재생\n5.음악명\n6. 반복재생\n");
        if (re)
        {
            printf("반복재생 on\n");
        }
        else
        {
            printf("반복재생 off\n");
        }
        scanf("%d", &answer);
        switch (answer)
        {
        case 1:
            music_find();
            break;
        case 2:
            music_stop();
            exit(0);
            break;
        case 3:
            music_backward();
            break;
        case 4:
            music_forward();
            break;
        case 5:
            strcpy(fp, music_file());
            for (i = 2; i < cnt; i++)
            {
                printf("%d번째 파일:%s\n", i - 1, fp[i]);
            }
            printf("\n");
            break;
        case 6:
            if (re)
            {
                re--;
            }
            else
            {
                re++;
            }
            break;
        default:
            break;
        }
        system("cls");      //콘솔창 지우기
        printf("%s를 재생중입니다.\n", now_play);
    }
}

void music_forward()
{
    int i = 0;
    char(*fp)[100] = music_file();
    char fname[100] = "D:\\Music_Test\\";       //파일경로
    int T = 0;
    for (i = 2; i < cnt; i++)
    {
        printf("%d번째 파일:%s\n", i - 1, fp[i]);
    }
    if (re)
    {
        printf("반복재생 on\n");
    }
    else
    {
        printf("반복재생 off\n");
    }
    wchar_t filepath[100];      //변수 형식 맞추기
    for (i = 2; i < cnt; i++)
    {
        if (strcmp(now_play, fp[i + 2]) == 0)
        {
            strcpy(fname + 14, fp[i + 3]);
            mbstowcs(filepath, fname, strlen(fname) + 1);
            T++;
            if (re)
            {
                PlaySound(filepath, NULL, SND_ASYNC | SND_LOOP);
            }
            else
            {
                PlaySound(filepath, NULL, SND_ASYNC);
            }
            strcpy(now_play, fname + 14);
            break;
        }
    }
    if (!T)
    {
        printf("마지막 곡입니다.\n");
        strcpy(fname + 14, fp[10]);
        mbstowcs(filepath, fname, strlen(fname) + 1);
        PlaySound(filepath, NULL, SND_ASYNC);
    }
}

void music_backward()
{
    int i = 0;
    char(*fp)[100] = music_file();
    char fname[100] = "D:\\Music_Test\\";       //파일경로
    int T = 0;
    for (i = 2; i < cnt; i++)
    {
        printf("%d번째 파일:%s\n", i - 1, fp[i]);
    }
    if (re)
    {
        printf("반복재생 on\n");
    }
    else
    {
        printf("반복재생 off\n");
    }
    wchar_t filepath[100];
    for (i = 2; i < cnt; i++)
    {
        if (strcmp(now_play, fp[i + 2]) == 0)
        {
            strcpy(fname + 14, fp[i + 1]);
            mbstowcs(filepath, fname, strlen(fname) + 1);
            T++;
            if (re)
            {
                PlaySound(filepath, NULL, SND_ASYNC | SND_LOOP);
            }
            else
            {
                PlaySound(filepath, NULL, SND_ASYNC);
            }
            strcpy(now_play, fname + 14);
            break;
        }
    }
    if (!T)
    {
        printf("첫 곡입니다.\n");

        strcpy(fname + 14, now_play);
        mbstowcs(filepath, fname, strlen(fname) + 1);
        if (re)
        {
            PlaySound(filepath, NULL, SND_ASYNC | SND_LOOP);
        }
        else
        {
            PlaySound(filepath, NULL, SND_ASYNC);
        }
    }
}

void music_find()
{
    char fname[100] = "D:\\Music_Test\\";       //파일경로
    printf("듣고싶은 노래를 치세요\n");
    getchar();
    gets(fname + 14);
    fname[strlen(fname)] = '.';
    fname[strlen(fname)] = 'w';
    fname[strlen(fname)] = 'a';
    fname[strlen(fname)] = 'v';
    strcpy(now_play, fname + 14);
    printf("%s를 재생합니다.\n", fname + 14);
    wchar_t filepath[100];
    mbstowcs(filepath, fname, strlen(fname) + 1);
    if (re)
    {
        PlaySound(filepath, NULL, SND_ASYNC | SND_LOOP);
    }
    else
    {
        PlaySound(filepath, NULL, SND_ASYNC);
    }
}

void music_stop()
{
    PlaySound(NULL, 0, 0);
    Sleep(1000);
    printf("프로그램을 종료했습니다.");
    return 0;
}

char* music_file()
{
    struct _finddata_t fd;
    long flag;
    int result = 1;
    char filename[100][100] = { '\0' };
    char(*fp)[100] = filename;
    int i;
    cnt = 0;
    flag = _findfirst("D:\\Music_Test\\*.*", &fd);        //파일경로
    if (flag == -1)
    {
        printf("error\n");
        return 0;
    }
    while (result != -1)
    {
        strcpy(*(fp + cnt), fd.name);
        cnt++;
        result = _findnext(flag, &fd);
    }
    _findclose(flag);
    return fp;
}