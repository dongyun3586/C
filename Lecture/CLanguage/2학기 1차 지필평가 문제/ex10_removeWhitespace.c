#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100 // Maximum string size

// �Էµ� ���ڿ��� ��/�� ���� ����
void removeLeadingSpace(char* str);
void removeTrailingSpace(char* str);

int main()
{
    char str[MAX_SIZE];
    printf("���ڿ� �Է�: ");
    gets(str);

    printf("�Էµ� ���ڿ�: '%s'\n", str);
    removeLeadingSpace(str);
    printf("���� ���� ����: '%s'\n", str);
    removeTrailingSpace(str);
    printf("���� ���� ����: '%s'\n", str);

    return 0;
}

// �� removeLeadingSpace( ) ����� ���� �Լ� [8��]
void removeLeadingSpace(char* str) {
#pragma region ���1
    //int index = 0, i;
    //// ������ �ƴ� ���� ���� ��ġ ã��
    //while (str[index] == ' ')
    //    index++;
    //// ���� ���� ����
    //for (i = 0; str[i + index] != '\0'; i++)
    //    str[i] = str[i + index];
    //str[i] = '\0'; // ���ڿ� �������� NULL ���� ����
#pragma endregion

#pragma region ���2
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] != ' ') {
            strcpy(&str[0], &str[i]);
            break;
        }

#pragma endregion
}

// �� removeTrailingSpace( ) ����� ���� �Լ� [8��]
void removeTrailingSpace(char* str) {
#pragma region ���1
    /*int index = -1;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != ' ')
            index = i;
    }
    str[index + 1] = '\0';*/
#pragma endregion

#pragma region ���2
    int index = -1;
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] != ' ') index = i;
    str[index + 1] = '\0';
#pragma endregion
}