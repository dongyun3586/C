#include <stdio.h>
int main() {
    FILE* fp;
    int c;

    // C프로그램에는 현재 입력 파일의 이름을 제공하는 __FILE__이라는 이름의 사전 정의 된 매크로가 있다.
    fp = fopen(__FILE__, "r");  // open the current input file

    do {
        c = getc(fp);   // read character 
        putchar(c);     // display character
    }     while (c != EOF);  // loop until the end of file is reached

    fclose(fp);
    return 0;
}