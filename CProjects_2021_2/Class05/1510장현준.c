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
void music_forward();   //���� ���� ���
void music_backward();  //���� ���� ���
void music_find();      //���� ã��
void music_stop();      //���� ����
char* music_file();      //���� �̸� ���

int main(void)
{
    int answer, i;
    while (1)
    {
        printf("���� ������ �ִ� ���� ����Դϴ�.\n");
        char(*fp)[100] = music_file();
        for (i = 2; i < cnt; i++)
        {
            printf("%d��° ����:%s\n", i - 1, fp[i]);
        }
        printf("1. ���� ã��\n2. ���� ����\n3. ���� ���� ���\n4. ���� ���� ���\n5.���Ǹ�\n6. �ݺ����\n");
        if (re)
        {
            printf("�ݺ���� on\n");
        }
        else
        {
            printf("�ݺ���� off\n");
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
                printf("%d��° ����:%s\n", i - 1, fp[i]);
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
        system("cls");      //�ܼ�â �����
        printf("%s�� ������Դϴ�.\n", now_play);
    }
}

void music_forward()
{
    int i = 0;
    char(*fp)[100] = music_file();
    char fname[100] = "D:\\Music_Test\\";       //���ϰ��
    int T = 0;
    for (i = 2; i < cnt; i++)
    {
        printf("%d��° ����:%s\n", i - 1, fp[i]);
    }
    if (re)
    {
        printf("�ݺ���� on\n");
    }
    else
    {
        printf("�ݺ���� off\n");
    }
    wchar_t filepath[100];      //���� ���� ���߱�
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
        printf("������ ���Դϴ�.\n");
        strcpy(fname + 14, fp[10]);
        mbstowcs(filepath, fname, strlen(fname) + 1);
        PlaySound(filepath, NULL, SND_ASYNC);
    }
}

void music_backward()
{
    int i = 0;
    char(*fp)[100] = music_file();
    char fname[100] = "D:\\Music_Test\\";       //���ϰ��
    int T = 0;
    for (i = 2; i < cnt; i++)
    {
        printf("%d��° ����:%s\n", i - 1, fp[i]);
    }
    if (re)
    {
        printf("�ݺ���� on\n");
    }
    else
    {
        printf("�ݺ���� off\n");
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
        printf("ù ���Դϴ�.\n");

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
    char fname[100] = "D:\\Music_Test\\";       //���ϰ��
    printf("������ �뷡�� ġ����\n");
    getchar();
    gets(fname + 14);
    fname[strlen(fname)] = '.';
    fname[strlen(fname)] = 'w';
    fname[strlen(fname)] = 'a';
    fname[strlen(fname)] = 'v';
    strcpy(now_play, fname + 14);
    printf("%s�� ����մϴ�.\n", fname + 14);
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
    printf("���α׷��� �����߽��ϴ�.");
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
    flag = _findfirst("D:\\Music_Test\\*.*", &fd);        //���ϰ��
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