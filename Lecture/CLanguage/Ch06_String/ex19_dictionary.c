#include <stdio.h>
#include <string.h>

#define WORDS 5

void main()
{
    char dic[WORDS][2][30] = {
        {"computer", "��ǻ��"},
        {"language", "���"},
        {"dictionary", "����"},
        {"android", "�ΰ��� ����� �� �κ�"},
        {"array", "�迭"}
    };
    char word[30];
    printf("�ܾ �Է��Ͻÿ�: ");
    scanf("%s", word);

    for (int i = 0; i < WORDS; i++) {
        if (strcmp(dic[i][0], word) == 0) {
            printf("%s: %s\n", word, dic[i][1]);
            return 0;
        }
    }
    printf("%s�� ������ �����ϴ�.\n", word);

    return 0;
}