#include <stdio.h>
#include <string.h>     // strcmp()

void bSort(char** words, int n);
void printWords(char** words, int n);
int bsearch(char* word, char** words, int n);

int main()
{
    char* words[] = { "Amazon", "Apple", "Facebook", "Google", "Microsoft" };
    char findStr[20];

    int n = sizeof(words) / sizeof(char*);

    printf("검색할 문자열 입력: ");
    scanf("%s", findStr);

    //bSort(words, n);
    printWords(words, n);   // Amazon Apple Facebook Google Microsoft

    int index;
    index = bsearch(findStr, words, n);
    if ((index = bsearch(findStr, words, n)) >= 0) {
        printf("%s은 %d번째에 위치함.\n", words[index], index + 1);
    }

    return 0;
}

void bSort(char** words, int n) {
    char* temp;
    for (int i = 1; i < n; i++)
        for (int j = 0; j < n - i; j++)
            if (strcmp(words[j], words[j + 1]) > 0) {
                temp = words[j];
                words[j] = words[j + 1];
                words[j + 1] = temp;
            }
}

void printWords(char** words, int n) {
    for (int i = 0; i < n; i++)
        printf("%s ", words[i]);
    printf("\n");
}

int bsearch(char* word, char** words, int n)
{
    int result;
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if ((result = strcmp(word, words[mid])) < 0)    // str1 < str2 인 경우
            high = mid - 1;
        else if (result > 0)
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}

