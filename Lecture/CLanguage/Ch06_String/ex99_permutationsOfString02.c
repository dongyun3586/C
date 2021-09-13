#include <stdio.h>
#include <string.h>

int visited[3] = { 0 };

void charPermu(char* str, int length)
{
    for (int i = 0; i < length; i++) {
        visited[i] = 1;
        for (int j = 0; j < length; j++) {
            if (visited[j]) continue;
            visited[j] = 1;
            for (int k = 0; k < length; k++) {
                if (visited[k]) continue;
                visited[k] = 1;
                printf("%c%c%c ", str[i], str[j], str[k]);
                visited[k] = 0;
            }
            visited[j] = 0;
        }
        visited[i] = 0;
    }

}

int main()
{
    char* str = "abc";
    charPermu(str, strlen(str));
    return 0;
}