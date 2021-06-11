#include<stdio.h>
#include<math.h>                             // double pow( double base, double exponent );

int countDigitsOfNumber(int num);            // num의 자릿수 n 구하기
int checkArmstrongNumber(int num, int n);    // num이 암스트롱 넘버인지 체크(맞으면 1, 틀리면 0 반환)
int reversNumber(int num);                   // num의 숫자 뒤집기 => 153 → 351
void printArmstrongNumber(int num, int n);   // 각 자리를 n제곱한 숫자들의 덧셈 형태로 출력하기

int main() {
	int a = 1, b = 1000000, n;
	printf("*** 1학년 3반 6번 박지용 ***\n");
	printf("1~1000000 사이의 암스트롱수\n\n");
	int count = 0;
	// a ~ b 사이의 암스트롱 넘버 출력하기
	for (int i = a; i <= b; i++) {
		n = countDigitsOfNumber(i);
		if (checkArmstrongNumber(i, n)) {
			printArmstrongNumber(i, n);
			count++;
		}
	}
	printf("%d", count);
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
	int tmp = num;
	int sum = 0;
	while (num != 0) {
		sum += pow(num % 10, n);
		num /= 10;
	}
	if (sum == tmp) {
		return 1;
	}
	return 0;
}

// num의 각 자리 숫자 뒤집기
int reversNumber(int num) {
	int reverse = 0;
	while (num != 0) {
		reverse *= 10;
		reverse += num % 10;
		num /= 10;
	}
	return reverse;
}

// 각 자리를 n제곱한 숫자들의 덧셈 형태로 출력하기
void printArmstrongNumber(int num, int n) {
	printf("%d = ", num);
	num = reversNumber(num);
	printf("%0.lf", pow(num % 10, n));
	num /= 10;
	for (int i = 1; i < n; i++) {
		printf("+ %0.lf", pow(num % 10, n));
		num /= 10;
	}
	printf("\n");
}