#include<stdio.h>
#include<math.h>                             // double pow( double base, double exponent );

int countDigitsOfNumber(int num);            // num의 자릿수 n 구하기
int checkArmstrongNumber(int num, int n);    // num이 암스트롱 넘버인지 체크(맞으면 1, 틀리면 0 반환)
int reversNumber(int num);                   // num의 숫자 뒤집기 => 153 → 351
void printArmstrongNumber(int num, int n);   // 각 자리를 n제곱한 숫자들의 덧셈 형태로 출력하기
void printArmstrongNumber2(int num, int n);

int main() {
	int a = 1, b = 1000000, n;
	printf("1~1000000 사이의 암스트롱수\n\n");

	// a ~ b 사이의 암스트롱 넘버 출력하기
	for (int i = a; i <= b; i++) {
		n = countDigitsOfNumber(i);		// log10(i) + 1;
		if (checkArmstrongNumber(i, n)) {
			printArmstrongNumber(i, n);
		}
	}
	return 0;
}

// num의 자릿수 n 구하기
int countDigitsOfNumber(int num) {
	int n = 0;
	while (num != 0) {
		num /= 10;
		n++;
	}
	return n;
}

// num이 암스트롱 넘버인지 체크(맞으면 1, 틀리면 0 반환)
int checkArmstrongNumber(int num, int n) {
	int temp = num, sum = 0;
	while (temp != 0) {
		sum += pow(temp % 10, n);
		temp /= 10;
	}
	return (sum == num) ? 1 : 0;
}

// num의 각 자리 숫자 뒤집기
int reversNumber(int num) {
	int reversNum = 0, r;
	while (num != 0) {
		r = num % 10;
		num /= 10;
		reversNum = reversNum * 10 + r;
	}
	return reversNum;
}

void printArmstrongNumber(int num, int n) {
	printf("%7d = ", num);
	int rev = reversNumber(num);
	for (int i = 0; i < n; i++, rev /= 10) {
		printf("%d", (int)pow(rev % 10, n));
		if (i != n - 1)
			printf(" + ");
	}
	printf("\n");
}

// 각 자리를 n제곱한 숫자들의 덧셈 형태로 출력하기
void printArmstrongNumber2(int num, int n) {
	printf("%7d = ", num);
	for (int i = n - 1; i >= 0; i--) {
		printf("%d", (int)pow((num % (int)pow(10, i + 1.0) - num % (int)pow(10, i)) / (int)pow(10, i), n));
		if (i != 0)
			printf(" + ");
	}
	printf("\n");
}