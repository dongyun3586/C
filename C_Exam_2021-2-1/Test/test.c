#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXWORDS 20
#define MAXCHAR 20

int countWords(char* str);
void removeDuplicateSpace(char* str);
void spliteString(char* str, char strArr[][20]);
void printStringArray(char strArr[][MAXCHAR], int n);
void sortStringArray(char strArr[][MAXCHAR], int n);

int main()
{
    char str[400] = "";
    char strArr[MAXWORDS][MAXCHAR];

    //Samsung     Microsoft    Google   Facebook  Apple Amazon
    printf("���ڿ� �Է� : ");
    gets(str);

    int n = countWords(str);                    // ���ڿ� ���� �ܾ��� ���� ���ϱ�
    removeDuplicateSpace(str);                  // �ܾ�� �ܾ� ������ �ߺ��Ǵ� ���� ����
    printf("���� ���� �� ���ڿ� : %s\n", str);
    spliteString(str, strArr);                  // ���ڿ� ���� �ܾ���� ���ڿ� �迭�� �����ϱ�
    printf("���� �� ���ڿ� �迭 : ");
    printStringArray(strArr, n);                   // ���ڿ� �迭�� �ܾ�� ���
    sortStringArray(strArr, n);                    // ���ڿ� �迭�� �ܾ�� ����
    printf("���� �� ���ڿ� �迭 : ");
    printStringArray(strArr, n);                   // ���ڿ� �迭�� �ܾ�� ���

    return 0;
}

// �־��� ���ڿ����� ���ĺ����� �����ϴ� ���ӵ� ���ڿ��� ���� ��ȯ
int countWords(char* str) {
    int wordCount = 0, isNewWord = 1;
    for (int i = 0; str[i] != '\0'; i++) {
        if (isalpha(str[i])) {
            if (isNewWord) {
                wordCount++;
                isNewWord = 0;
            }
        }
        else {
            isNewWord = 1;
        }

        /*if (isalpha(str[i]) && isNewWord) {
            wordCount++;
            isNewWord = 0;
        }
        else if (!isalpha(str[i])) {
            isNewWord = 1;
        }*/
    }
    return wordCount;
}

// ���ڿ� �߰��� �� �� �̻��� ���ӵ� ������ �ִ� ��� �ϳ��� ����� ����
void removeDuplicateSpace(char* str) {
    int start, end;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ') {
            start = i;
            for (end = i; str[end] == ' '; end++);
            if (end - start > 1)
                strcpy(str + start + 1, str + end);
            //strcpy(&str[start + 1], &str[end]);
        }
    }
}

// ���ڿ��� ������ �������� �и��Ͽ� ���ڿ� �迭�� ����
void spliteString(char* str, char strArr[][20]) {
    int a = 0, b = 0;
    for (int i = 0; str[i] != '\0'; i++)          // for (int i = 0; i <= (strlen(str)); i++)
    {
        if (str[i] != ' ')    // if (str[i] == ' ' || str[i] == '\0')
        {
            strArr[a][b] = str[i];
            b++;
        }
        else
        {
            strArr[a][b] = '\0';
            a++;        // ���� �ܾ�
            b = 0;      // ���� �ܾ ���� �迭�� ������ �ε����� 0���� �ʱ�ȭ
        }
    }
    strArr[a][b] = '\0';
}

// ���ڿ� �迭�� ����� ��� ��� ���
void printStringArray(char strArr[][MAXCHAR], int n) {
    for (int i = 0; i < n; i++)
        printf("%s ", strArr[i]);
    printf("\n");
}

// ���ڿ� �迭�� ����� ��ҵ��� ASCII CODE ������� ����
void sortStringArray(char(*strArr)[MAXCHAR], int n) {
    char t[MAXCHAR];
    char* temp=t;
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