#include <stdio.h>
#include <stdlib.h>
#include <string.h> 


int main() {

    printf("분자식을 입력해주세요\n");
    // 원소 기호와 원자량 저장 배열
    float molearr[118] = { 0, };
    char molearrn[118][2] = { 0, };

    //원소 기호 지정하기 
    *(*(molearrn + 0)) = 'H';
    *(*(molearrn + 1)) = 'H';
    *(*(molearrn + 1) + 1) = 'e';
    *(*(molearrn + 2)) = 'L';
    *(*(molearrn + 2) + 1) = 'i';
    *(*(molearrn + 3)) = 'B';
    *(*(molearrn + 3) + 1) = 'e';
    *(*(molearrn + 4)) = 'B';
    *(*(molearrn + 5)) = 'C';
    *(*(molearrn + 6)) = 'N';
    *(*(molearrn + 7)) = 'O';
    *(*(molearrn + 8)) = 'F';
    *(*(molearrn + 9)) = 'N';
    *(*(molearrn + 9) + 1) = 'e';
    *(*(molearrn + 10)) = 'N';
    *(*(molearrn + 10) + 1) = 'a';
    *(*(molearrn + 11)) = 'M';
    *(*(molearrn + 11) + 1) = 'g';
    *(*(molearrn + 12)) = 'A';
    *(*(molearrn + 12) + 1) = 'l';
    *(*(molearrn + 13)) = 'S';
    *(*(molearrn + 13) + 1) = 'i';
    *(*(molearrn + 14)) = 'P';
    *(*(molearrn + 15)) = 'S';
    *(*(molearrn + 16)) = 'C';
    *(*(molearrn + 16) + 1) = 'l';
    *(*(molearrn + 17)) = 'A';
    *(*(molearrn + 17) + 1) = 'r';
    *(*(molearrn + 18)) = 'K';
    *(*(molearrn + 19)) = 'C';
    *(*(molearrn + 19) + 1) = 'a';
    *(*(molearrn + 20)) = 'S';
    *(*(molearrn + 20) + 1) = 'c';
    *(*(molearrn + 21)) = 'T';
    *(*(molearrn + 21) + 1) = 'i';
    *(*(molearrn + 22)) = 'V';
    *(*(molearrn + 23)) = 'C';
    *(*(molearrn + 23) + 1) = 'r';
    *(*(molearrn + 24)) = 'M';
    *(*(molearrn + 24) + 1) = 'n';
    *(*(molearrn + 25)) = 'F';
    *(*(molearrn + 25) + 1) = 'e';
    *(*(molearrn + 26)) = 'C';
    *(*(molearrn + 26) + 1) = 'o';
    *(*(molearrn + 27)) = 'N';
    *(*(molearrn + 27) + 1) = 'i';
    *(*(molearrn + 28)) = 'C';
    *(*(molearrn + 28) + 1) = 'u';
    *(*(molearrn + 29)) = 'Z';
    *(*(molearrn + 29) + 1) = 'n';
    *(*(molearrn + 30)) = 'G';
    *(*(molearrn + 30) + 1) = 'a';
    *(*(molearrn + 31)) = 'G';
    *(*(molearrn + 31) + 1) = 'e';
    *(*(molearrn + 32)) = 'A';
    *(*(molearrn + 32) + 1) = 's';
    *(*(molearrn + 33)) = 'S';
    *(*(molearrn + 33) + 1) = 'e';
    *(*(molearrn + 34)) = 'B';
    *(*(molearrn + 34) + 1) = 'r';
    *(*(molearrn + 35)) = 'r';
    *(*(molearrn + 35) + 1) = 'r';
    *(*(molearrn + 36)) = 'R';
    *(*(molearrn + 36) + 1) = 'b';
    *(*(molearrn + 37)) = 'S';
    *(*(molearrn + 37) + 1) = 'r';
    *(*(molearrn + 38)) = 'Y';
    *(*(molearrn + 39)) = 'Z';
    *(*(molearrn + 39) + 1) = 'r';
    *(*(molearrn + 40)) = 'N';
    *(*(molearrn + 40) + 1) = 'b';
    *(*(molearrn + 41)) = 'M';
    *(*(molearrn + 41) + 1) = 'o';
    *(*(molearrn + 42)) = 'T';
    *(*(molearrn + 42) + 1) = 'c';
    *(*(molearrn + 43)) = 'R';
    *(*(molearrn + 43) + 1) = 'u';
    *(*(molearrn + 44)) = 'R';
    *(*(molearrn + 44) + 1) = 'h';
    *(*(molearrn + 45)) = 'P';
    *(*(molearrn + 45) + 1) = 'd';
    *(*(molearrn + 46)) = 'A';
    *(*(molearrn + 46) + 1) = 'g';
    *(*(molearrn + 47)) = 'C';
    *(*(molearrn + 47) + 1) = 'd';
    *(*(molearrn + 48)) = 'I';
    *(*(molearrn + 48) + 1) = 'n';
    *(*(molearrn + 49)) = 'S';
    *(*(molearrn + 49) + 1) = 'n';
    *(*(molearrn + 50)) = 'S';
    *(*(molearrn + 50) + 1) = 'b';
    *(*(molearrn + 51)) = 'T';
    *(*(molearrn + 51) + 1) = 'e';
    *(*(molearrn + 52)) = 'I';
    *(*(molearrn + 53)) = 'X';
    *(*(molearrn + 53) + 1) = 'e';
    *(*(molearrn + 54)) = 'C';
    *(*(molearrn + 54) + 1) = 's';
    *(*(molearrn + 55)) = 'B';
    *(*(molearrn + 55) + 1) = 'a';
    *(*(molearrn + 56)) = 'L';
    *(*(molearrn + 56) + 1) = 'a';
    *(*(molearrn + 57)) = 'C';
    *(*(molearrn + 57) + 1) = 'e';
    *(*(molearrn + 58)) = 'P';
    *(*(molearrn + 58) + 1) = 'r';
    *(*(molearrn + 59)) = 'N';
    *(*(molearrn + 59) + 1) = 'd';
    *(*(molearrn + 60)) = 'P';
    *(*(molearrn + 60) + 1) = 'm';
    *(*(molearrn + 61)) = 'S';
    *(*(molearrn + 61) + 1) = 'm';
    *(*(molearrn + 62)) = 'E';
    *(*(molearrn + 62) + 1) = 'u';
    *(*(molearrn + 63)) = 'G';
    *(*(molearrn + 63) + 1) = 'd';
    *(*(molearrn + 64)) = 'T';
    *(*(molearrn + 64) + 1) = 'b';
    *(*(molearrn + 65)) = 'D';
    *(*(molearrn + 65) + 1) = 'y';
    *(*(molearrn + 66)) = 'H';
    *(*(molearrn + 66) + 1) = 'o';
    *(*(molearrn + 67)) = 'E';
    *(*(molearrn + 67) + 1) = 'r';
    *(*(molearrn + 68)) = 'T';
    *(*(molearrn + 68) + 1) = 'm';
    *(*(molearrn + 69)) = 'Y';
    *(*(molearrn + 69) + 1) = 'b';
    *(*(molearrn + 70)) = 'L';
    *(*(molearrn + 70) + 1) = 'u';
    *(*(molearrn + 71)) = 'H';
    *(*(molearrn + 71) + 1) = 'f';
    *(*(molearrn + 72)) = 'T';
    *(*(molearrn + 72) + 1) = 'a';
    *(*(molearrn + 73)) = 'W';
    *(*(molearrn + 74)) = 'R';
    *(*(molearrn + 74) + 1) = 'e';
    *(*(molearrn + 75)) = 'O';
    *(*(molearrn + 75) + 1) = 's';
    *(*(molearrn + 76)) = 'I';
    *(*(molearrn + 76) + 1) = 'r';
    *(*(molearrn + 77)) = 'P';
    *(*(molearrn + 77) + 1) = 't';
    *(*(molearrn + 78)) = 'A';
    *(*(molearrn + 78) + 1) = 'u';
    *(*(molearrn + 79)) = 'H';
    *(*(molearrn + 79) + 1) = 'g';
    *(*(molearrn + 80)) = 'T';
    *(*(molearrn + 80) + 1) = 'l';
    *(*(molearrn + 81)) = 'P';
    *(*(molearrn + 81) + 1) = 'b';
    *(*(molearrn + 82)) = 'B';
    *(*(molearrn + 82) + 1) = 'i';
    *(*(molearrn + 83)) = 'P';
    *(*(molearrn + 83) + 1) = 'o';
    *(*(molearrn + 84)) = 'A';
    *(*(molearrn + 84) + 1) = 't';
    *(*(molearrn + 85)) = 'R';
    *(*(molearrn + 85) + 1) = 'n';
    *(*(molearrn + 86)) = 'F';
    *(*(molearrn + 86) + 1) = 'r';
    *(*(molearrn + 87)) = 'R';
    *(*(molearrn + 87) + 1) = 'a';
    *(*(molearrn + 88)) = 'A';
    *(*(molearrn + 88) + 1) = 'c';
    *(*(molearrn + 89)) = 'T';
    *(*(molearrn + 89) + 1) = 'h';
    *(*(molearrn + 90)) = 'P';
    *(*(molearrn + 90) + 1) = 'a';
    *(*(molearrn + 91)) = 'U';
    *(*(molearrn + 92)) = 'N';
    *(*(molearrn + 92) + 1) = 'p';
    *(*(molearrn + 93)) = 'P';
    *(*(molearrn + 93) + 1) = 'u';
    *(*(molearrn + 94)) = 'A';
    *(*(molearrn + 94) + 1) = 'm';
    *(*(molearrn + 95)) = 'C';
    *(*(molearrn + 95) + 1) = 'm';
    *(*(molearrn + 96)) = 'B';
    *(*(molearrn + 96) + 1) = 'k';
    *(*(molearrn + 97)) = 'C';
    *(*(molearrn + 97) + 1) = 'f';
    *(*(molearrn + 98)) = 'E';
    *(*(molearrn + 98) + 1) = 's';
    *(*(molearrn + 99)) = 'F';
    *(*(molearrn + 99) + 1) = 'm';
    *(*(molearrn + 100)) = 'M';
    *(*(molearrn + 100) + 1) = 'd';
    *(*(molearrn + 101)) = 'N';
    *(*(molearrn + 116) + 1) = 'o';
    *(*(molearrn + 102)) = 'L';
    *(*(molearrn + 102) + 1) = 'r';
    *(*(molearrn + 103)) = 'R';
    *(*(molearrn + 103) + 1) = 'f';
    *(*(molearrn + 104)) = 'D';
    *(*(molearrn + 104) + 1) = 'b';
    *(*(molearrn + 105)) = 'S';
    *(*(molearrn + 105) + 1) = 'g';
    *(*(molearrn + 106)) = 'B';
    *(*(molearrn + 106) + 1) = 'h';
    *(*(molearrn + 107)) = 'H';
    *(*(molearrn + 107) + 1) = 's';
    *(*(molearrn + 108)) = 'M';
    *(*(molearrn + 108) + 1) = 't';
    *(*(molearrn + 109)) = 'D';
    *(*(molearrn + 109) + 1) = 's';
    *(*(molearrn + 110)) = 'R';
    *(*(molearrn + 110) + 1) = 'g';
    *(*(molearrn + 111)) = 'C';
    *(*(molearrn + 111) + 1) = 'n';
    *(*(molearrn + 112)) = 'N';
    *(*(molearrn + 112) + 1) = 'h';
    *(*(molearrn + 113)) = 'F';
    *(*(molearrn + 113) + 1) = 'l';
    *(*(molearrn + 114)) = 'M';
    *(*(molearrn + 114) + 1) = 'c';
    *(*(molearrn + 115)) = 'L';
    *(*(molearrn + 115) + 1) = 'v';
    *(*(molearrn + 116)) = 'T';
    *(*(molearrn + 116) + 1) = 's';
    *(*(molearrn + 117)) = 'O';
    *(*(molearrn + 117) + 1) = 'g';

    // 원자량 지정하기
    *(molearr + 0) = 1.008;
    *(molearr + 1) = 4.003;
    *(molearr + 2) = 6.941;
    *(molearr + 3) = 9.012;
    *(molearr + 4) = 10.81;
    *(molearr + 5) = 12.01;
    *(molearr + 6) = 14.01;
    *(molearr + 7) = 16.00;
    *(molearr + 8) = 19.00;
    *(molearr + 9) = 20.18;
    *(molearr + 10) = 22.99;
    *(molearr + 11) = 24.31;
    *(molearr + 12) = 26.98;
    *(molearr + 13) = 28.09;
    *(molearr + 14) = 30.97;
    *(molearr + 15) = 32.07;
    *(molearr + 16) = 35.45;
    *(molearr + 17) = 39.95;
    *(molearr + 18) = 39.10;
    *(molearr + 19) = 40.08;
    *(molearr + 20) = 44.96;
    *(molearr + 21) = 47.88;
    *(molearr + 22) = 50.94;
    *(molearr + 23) = 52.00;
    *(molearr + 24) = 54.94;
    *(molearr + 25) = 55.85;
    *(molearr + 26) = 58.93;
    *(molearr + 27) = 58.69;
    *(molearr + 28) = 63.55;
    *(molearr + 29) = 65.38;
    *(molearr + 30) = 69.72;
    *(molearr + 31) = 72.59;
    *(molearr + 32) = 74.92;
    *(molearr + 33) = 78.96;
    *(molearr + 34) = 79.90;
    *(molearr + 35) = 83.80;
    *(molearr + 36) = 85.47;
    *(molearr + 37) = 87.62;
    *(molearr + 38) = 88.91;
    *(molearr + 39) = 91.22;
    *(molearr + 40) = 92.91;
    *(molearr + 41) = 95.94;
    *(molearr + 42) = 98.00;
    *(molearr + 43) = 101.1;
    *(molearr + 44) = 102.9;
    *(molearr + 45) = 106.4;
    *(molearr + 46) = 107.9;
    *(molearr + 47) = 112.4;
    *(molearr + 48) = 114.8;
    *(molearr + 49) = 118.7;
    *(molearr + 50) = 121.8;
    *(molearr + 51) = 127.6;
    *(molearr + 52) = 126.9;
    *(molearr + 53) = 131.3;
    *(molearr + 54) = 132.9;
    *(molearr + 55) = 137.3;
    *(molearr + 56) = 138.9;
    *(molearr + 57) = 140.1;
    *(molearr + 58) = 140.9;
    *(molearr + 59) = 144.2;
    *(molearr + 60) = 145.0;
    *(molearr + 61) = 150.4;
    *(molearr + 62) = 152.0;
    *(molearr + 63) = 157.3;
    *(molearr + 64) = 158.9;
    *(molearr + 65) = 162.5;
    *(molearr + 66) = 164.9;
    *(molearr + 67) = 167.3;
    *(molearr + 68) = 168.9;
    *(molearr + 69) = 173.0;
    *(molearr + 70) = 175.0;
    *(molearr + 71) = 178.5;
    *(molearr + 72) = 180.9;
    *(molearr + 73) = 183.9;
    *(molearr + 74) = 186.2;
    *(molearr + 75) = 190.2;
    *(molearr + 76) = 192.2;
    *(molearr + 77) = 195.1;
    *(molearr + 78) = 197.0;
    *(molearr + 79) = 200.6;
    *(molearr + 80) = 204.4;
    *(molearr + 81) = 207.2;
    *(molearr + 82) = 209.0;
    *(molearr + 83) = 209;
    *(molearr + 84) = 210;
    *(molearr + 85) = 222;
    *(molearr + 86) = 223;
    *(molearr + 87) = 226;
    *(molearr + 88) = 227;
    *(molearr + 89) = 232.0;
    *(molearr + 90) = 231;
    *(molearr + 91) = 238.0;
    *(molearr + 92) = 237;
    *(molearr + 93) = 244;
    *(molearr + 94) = 243;
    *(molearr + 95) = 247;
    *(molearr + 96) = 247;
    *(molearr + 97) = 251;
    *(molearr + 98) = 252;
    *(molearr + 99) = 257;
    *(molearr + 100) = 258;
    *(molearr + 101) = 259;
    *(molearr + 102) = 260;
    *(molearr + 103) = 261;
    *(molearr + 104) = 262;
    *(molearr + 105) = 263;
    *(molearr + 106) = 264;
    *(molearr + 107) = 265;
    *(molearr + 108) = 268;
    *(molearr + 109) = 271;
    *(molearr + 110) = 272;
    *(molearr + 111) = 285;
    *(molearr + 112) = 284;
    *(molearr + 113) = 289;
    *(molearr + 114) = 288;
    *(molearr + 115) = 293;
    *(molearr + 116) = 294;
    *(molearr + 117) = 294;

    // 입력 받기
    char compound[50] = "\0";
    fgets(compound, 50, stdin);

    // 화학식 끝에 원소 개수가 없을 시 1 첨가 ex) H2O -> H2O1
    int k = 0;
    for (int i = 0; compound[i] != '\0'; i++) {
        k = i;
    }
    if (compound[k - 1] >= 'A' && compound[k - 1] <= 'z') {
        compound[k] = '1';
        compound[k + 1] = '\0';
    }
    //대문자 2개가 연달아 올때 ex) HCl의 경우
    for (int i = 0; compound[i] != '\0'; i++) {
        if (compound[i] <= 'Z' && compound[i] >= 'A' && compound[i + 1] <= 'Z' && compound[i + 1] >= 'A') {
            for (int j = k; j >= i; j--) {
                compound[j + 2] = compound[j + 1];
            }
            compound[i + 1] = '1';
        }
    }

    // 화학식량 계산 과정
    float sum = 0;
    for (int i = 0; compound[i] != '\0'; i++) {
        if (*(compound + i) <= '9' && *(compound + i) >= '1' && i == 2) {

            for (int j = 0; j < 118; j++) {
                if (*(*(molearrn + j)) == compound[0] && *(*(molearrn + j) + 1) == compound[1]) {
                    sum = (float)molearr[j] * ((int)compound[2] - 48);
                    strcpy(compound, (compound + i + 1));
                    i = 0;
                }
            }
        }

        if (*(compound + i) <= '9' && *(compound + i) >= '1' && i == 1) {

            for (int j = 0; j < 118; j++) {
                if (*(*(molearrn + j)) == compound[0] && *(*(molearrn + j) + 1) == 0) {
                    sum += (float)molearr[j] * ((int)compound[1] - 48);
                    strcpy(compound, (compound + i + 1));
                    i = 0;
                }
            }

        }
    }
    printf("%.3f", sum);
}