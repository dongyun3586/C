#include <stdio.h>
int main() {
    FILE* fp;
    int c;

    // C���α׷����� ���� �Է� ������ �̸��� �����ϴ� __FILE__�̶�� �̸��� ���� ���� �� ��ũ�ΰ� �ִ�.
    fp = fopen(__FILE__, "r");  // open the current input file

    do {
        c = getc(fp);   // read character 
        putchar(c);     // display character
    }     while (c != EOF);  // loop until the end of file is reached

    fclose(fp);
    return 0;
}