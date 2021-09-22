#include <stdio.h>
#include <string.h>
#include <ctype.h>

void encrypt(char* cipher, int shift);
void decrypt(char* cipher, int shift);

void main()
{
    char cipher[50];
    int shift = 3;

    printf("문자열을 입력하시오: ");
    fgets(cipher, 50, stdin);
    printf("평  문: %s", cipher);
    encrypt(cipher, shift);
    printf("암호문: %s", cipher);
    decrypt(cipher, shift);
    printf("평  문: %s", cipher);

    return 0;
}

void encrypt(char* cipher, int shift) {
    for (int i = 0; cipher[i] != '\0'; i++) {
        if (isupper(cipher[i])) {
            cipher[i] += shift;
            if (cipher[i] > 'Z')
                cipher[i] -= 26;
        }
        else if (islower(cipher[i])) {
            cipher[i] += shift;
            if (cipher[i] > 'z')
                cipher[i] -= 26;
        }
    }
}

void decrypt(char* cipher, int shift) {
    for (int i = 0; cipher[i] != '\0'; i++) {
        if (isupper(cipher[i])) {
            cipher[i] -= shift;
            if (cipher[i] < 'A')
                cipher[i] += 26;
        }
        else if (islower(cipher[i])) {
            cipher[i] -= shift;
            if (cipher[i] < 'a')
                cipher[i] += 26;
        }
    }
}