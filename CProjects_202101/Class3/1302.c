#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

char capitalize(char alphabet) {
	if (alphabet >= 'a' && alphabet <= 'z') {
		return alphabet - 'a' + 'A';
	}
	else {
		return alphabet;
	}
}

char base64character(int num) {
	num %= 64;
	if (num >= 0 && num < 26) {
		return 'A' + num;
	}
	else if (num >= 26 && num < 52) {
		return 'a' + num - 26;
	}
	else if (num >= 52 && num < 62) {
		return '0' + num - 52;
	}
	else if (num == 62) {
		return '+';
	}
	else if (num == 63) {
		return '/';
	}
}

char* toBase64(int numToBase64, int min_length) {
	char base64num[256] = { 0, };
	int cnt = 0;
	while (numToBase64 != 0 || cnt < min_length) {
		base64num[cnt++] = base64character(numToBase64);
		numToBase64 /= 64;
	}
	base64num[cnt] = 0;
	return base64num;
}

int charToBase10(char chr) {
	if (chr >= '0' && chr <= '9') {
		return chr - '0' + 52;
	}
	else if (chr >= 'A' && chr <= 'Z') {
		return chr - 'A';
	}
	else if (chr >= 'a' && chr <= 'z') {
		return chr - 'a' + 26;
	}
	else if (chr = '+') {
		return 62;
	}
	else { return 63; }
}

int toBase10(char* base64Number) {

}

int is_in_correct_charRange(char chr) {
	if (chr >= '0' && chr <= '9' || chr >= 'A' && chr <= 'Z' || chr >= 'a' && chr <= 'z' || chr == '+' || chr == '/') {
		return 1;
	}
	else {
		return 0;
	}
}

void printBase64Num(char* base64num) {
	for (int i = 0; base64num[i] != 0; i++) {
		printf("%c", base64num[i++]);
	}
}

int mainScreen() {
	int selection = 0;
	printf("Welcome to GeneralBzop1's Encoder Program!\n");
	printf("What will you do?\n");
	printf("1. Encrypt letters\n");
	printf("2. Decrypt letters\n");
	scanf("%d", &selection);
	if (selection == 1 || selection == 2) {
		return selection;
	}
	return 0;
}

int yesOrNo(char* confirmationMessage) {
	char selection = 0;
	printf("%s", confirmationMessage);
	printf(" (Y/N) ");
	scanf("%c", &selection);
	return capitalize(selection) == 'Y';
}

void setYourKeys(int* key) {
	printf("Input your encryption key. e.g. ad 0f A1: ");
	scanf("%02X %02X %02X", key, key + 1, key + 2);
}

void setKeysRandomly(int* key) {
	key[0] = 0;
	key[1] = 0;
	while (key[0] == 0 || key[1] == 0) {
		srand(time(NULL));
		key[0] = rand() % 256;
		key[1] = rand() % 256;
	}
	key[2] = rand() % 256;
}

void encodingSection() {
	int plainMessageSet = 0;
	int key[3] = { 0, };
	char message[257] = { 0, };
	char crypt[1025] = { 0, };
	while (!plainMessageSet) {
		printf("Write message here. Max 256 chars.\nMessage: ");
		scanf("%[^\n]%*c", message);
		plainMessageSet = yesOrNo("Are you sure?");
	}
	int keySet = 0;
	while (!keySet) {
		if (yesOrNo("Do you want to set your own key?")) {
			setYourKeys(key);
		}
		else {
			setKeysRandomly(key);
		}
		printf("Your encryption key is %02X %02X %02X.\n", key[0], key[1], key[2]);
		keySet = yesOrNo("continue?");
	}
	for (int i = 0; i < 256; i++) {
		char* encrypted = toBase64(message[i] * message[i] * key[0] + message[i] * key[1] + key[2], 4);
		strcat(crypt, encrypted);
		for (int j = 0; j < 3; j++) {
			key[j] ^= encrypted[j] ^ i;
		}
	}
	printf("your encrypted crypt: %s", crypt);
}

/*int round(double a) {
	return (int)a + (a - (int)a < 0.5);
}*/

double solveQuadraticEquation(long long int a, long long int b, long long int c) {
	if (a) {
		return (-b + (sqrt(b * b - 4 * a * c))) / (2 * a);
	}
	else { return -c / b; }
}

void decodingSection() {
	int cryptMessageSet = 0;
	long long int key[3] = { 0, };
	char message[257] = { 0, };
	char crypt[1025] = { 0, };
	int keySet = 0;
	int cryptCode;
	while (!cryptMessageSet) {
		printf("Write crypt here.\nCrypt: ");
		scanf("%[^\n]%*c", crypt);
		cryptMessageSet = yesOrNo("Is this right?");
	}
	while (!keySet) {
		setYourKeys(key);
		printf("Your encryption key is %02X %02X %02X.\n", key[0], key[1], key[2]);
		keySet = yesOrNo("continue?");
	}
	printf("your encrypted message: ");
	for (int i = 0; i < 256; i++) {
		cryptCode = 0;
		for (int j = 0; j < 4; j++) {
			cryptCode *= 64;
			cryptCode += charToBase10(crypt[i * 4 + j]);
		}
		printf("%X %d ", (int)round(solveQuadraticEquation(key[0], key[1], key[2] - cryptCode)), cryptCode);
		for (int j = 0; j < 3; j++) {
			key[j] ^= crypt[i * 4 + j] ^ i;
		}
	}
}

int main() {
	int mainScreenChoice = 0;
	while (!mainScreenChoice) {
		mainScreenChoice = mainScreen();
	}
	if (mainScreenChoice % 2) {
		encodingSection();
	}
	else {
		decodingSection();
	}
}
