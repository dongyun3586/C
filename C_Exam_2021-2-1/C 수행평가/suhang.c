#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXWORDS 20
#define MAXCHAR 20

int countWords(char* str);
void removeDuplicateSpace(char* str);
void spliteString(char* str, char strArr[][20]);
void printStringArray(char strArr[][MAXCHAR], int n);
void sortStringArray(char(*strArr)[MAXCHAR], int n);

int main()
{
    char str[400] = "";
    char strArr[MAXWORDS][MAXCHAR];
    int n = 0;

    printf("*** 1�г� 1�� 20�� ȫ�浿 ***\n");
    //Microsoft   Google   Facebook  Apple  Amazon
    printf("���ڿ� �Է� : ");
    gets(str);

    n = countWords(str);                        // ���ڿ� ���� �ܾ��� ���� ���ϱ�
    if (n == 0) {
        printf("�Էµ� ���ڰ� �����ϴ�.\n");
        return 0;
    }
    removeDuplicateSpace(str);                      // �ܾ�� �ܾ� ������ �ߺ��Ǵ� ���� ����
    printf("���� ���� �� : %s\n", str);
    spliteString(str, strArr);                      // ���ڿ� ���� �ܾ���� ���ڿ� �迭�� �����ϱ�
    printf("���� �� : ");
    printStringArray(strArr, n);                    // ���ڿ� �迭�� �ܾ�� ���
    sortStringArray(strArr, n);                     // ���ڿ� �迭�� �ܾ�� ����
    printf("���� �� : ");
    printStringArray(strArr, n);                    // ���ڿ� �迭�� �ܾ�� ���

    return 0;
}

// �־��� ���ڿ����� ���ĺ����� �����ϴ� ���ӵ� ���ڿ��� ���� ��ȯ
int countWords(char* str) {
    int wordCount = 0, isNewWord = 1;

    // ���ڿ��� ��� ���� �˻�
    for (int i = 0; str[i] != '\0'; i++) {
        if (isalpha(str[i]) && isNewWord) {     // ���� ���ڰ� ���ĺ��̰� ���ο� �ܾ��̸�
            wordCount++;
            isNewWord = 0;
        }
        else if (!isalpha(str[i])) {            // ���� ���ڰ� ���ĺ��� �ƴϸ�
            isNewWord = 1;
        }
    }
    return wordCount;
}

// ���ڿ� �߰��� �� �� �̻��� ���ӵ� ������ �ִ� ��� �ϳ��� ����� ����
void removeDuplicateSpace(char* str) {
    int alphaIndex=0;
    // ���ڿ��� ��� ���� �˻�
    for (int i = 0; str[i] != '\0'; i++) {
        // ������ �߰��ϸ� ������ ���ĺ� ��ġ�� ã�� alphaIndex�� ����
        if (str[i] == ' ') {
            for (alphaIndex = i; str[alphaIndex] == ' '; alphaIndex++);
            // ������ 2�� �̻��̸� ���� �ϳ��� ����� ����
            if (alphaIndex - i > 1)
                strcpy(&str[i + 1], &str[alphaIndex]);
        }
    }
}

// ���ڿ��� ������ �������� �и��Ͽ� ���ڿ� �迭�� ����
void spliteString(char* str, char strArr[][20]) {
    int a = 0, b = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        
        if (str[i] != ' ')          // ������ �ƴϸ� ���� �ϳ��� ����
        {
            strArr[a][b] = str[i];
            b++;
        }
        else                        // �����̸� ���� �ܾ�� �Ѿ�� ó��
        {
            strArr[a][b] = '\0';    // ����� �ܾ��� �������� '\0'���� �߰�
            a++;                    // 2���� index ����
            b = 0;                  // �迭�� 1���� �ε����� 0���� �ʱ�ȭ
        }
    }
    strArr[a][b] = '\0';            // ���ڿ� ���� �����ϸ� ������ �ܾ��� �������� '\0'���� �߰�
}

// ���ڿ� �迭�� ����� ��� ��Ҹ� �� �ٷ� ���
void printStringArray(char strArr[][MAXCHAR], int n) {
    for (int i = 0; i < n; i++)
        printf("%s ", strArr[i]);
    printf("\n");
}

// ���ڿ� �迭�� ����� ��ҵ��� ASCII CODE ������� ����
void sortStringArray(char(*strArr)[MAXCHAR], int n) {
    char temp[MAXCHAR];
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            if (strcmp(strArr[j], strArr[j + 1]) > 0) {
                strcpy(temp, strArr[j]);
                strcpy(strArr[j], strArr[j + 1]);
                strcpy(strArr[j + 1], temp);
            }
        }
    }
}