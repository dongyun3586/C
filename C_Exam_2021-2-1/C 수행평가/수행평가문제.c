#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXWORDS 10
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

    //Microsoft   Google   Facebook  Apple  Amazon
    printf("*** 1�г� 0�� 0�� �ۡۡ� ***\n");
    printf("���ڿ� �Է� : ");
    gets(str);

    n = countWords(str);                            // ���ڿ� ���� �ܾ��� ���� ���ϱ�
    // �Էµ� �ܾ ���� ��� ó�� �ڵ� �߰�

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

// ���ڿ����� ���ĺ����� �����ϴ� �ܾ�(���ӵ� ���ڿ�)�� ���� ��ȯ
int countWords(char* str) {
    int wordCount = 0, isNewWord = 1;



    return wordCount;
}

// �ܾ� ���̿� ���� �ϳ��� ����� ����
void removeDuplicateSpace(char* str) {
    
}

// ���ڿ��� ������ �������� �и��Ͽ� ���ڿ� �迭�� ����
void spliteString(char* str, char strArr[][20]) {
    int a = 0, b = 0;
    
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
    
}