#include<stdio.h>
#include<math.h>                             // double pow( double base, double exponent );

int countDigitsOfNumber(int num);            // num의 자릿수 n 구하기
int checkArmstrongNumber(int num, int n);    // num이 암스트롱 넘버인지 체크(맞으면 1, 틀리면 0 반환)
int reversNumber(int num);                   // num의 숫자 뒤집기 => 153 → 351
void printArmstrongNumber(int num, int n);   // 각 자리를 n제곱한 숫자들의 덧셈 형태로 출력하기

int main() {
	int a = 1, b = 1000000, n;
	printf("1~1000000 사이의 암스트롱수\n\n");

	// a ~ b 사이의 암스트롱 넘버 출력하기
	for (int i = a; i <= b; i++) {
		n = log10(i) + 1;
		if (checkArmstrongNumber(i, n)) {
			printArmstrongNumber(i, n);
		}
	}
	return 0;
}

// num이 암스트롱 넘버인지 체크(맞으면 1, 틀리면 0 반환)
int checkArmstrongNumber(int num, int n) {
	int sum = 0, temp = num;
	while (temp != 0) {
		sum += pow(temp % 10, n);
		temp /= 10;
	}
	if (num == sum) 
		return 1;
	else 
		return 0;
}

// 각 자리를 n제곱한 숫자들의 덧셈 형태로 출력하기
void printArmstrongNumber(int num, int n) {
	printf("%7d = ", num);
	for (int i = n - 1; i >= 0; i--) {
		printf("%d", (int)pow((num % (int)pow(10, i + 1) - num % (int)pow(10, i)) / (int)pow(10, i), n));
		if (i != 0)
			printf(" + ");
	}
	printf("\n");
}