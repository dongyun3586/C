#include<stdio.h>
#include<math.h>	

int countDigitsOfNumber(int num);
int checkArmstrongNumber(int num, int n);
int reversNumber(int num);
void printArmstrongNumber(int num, int n);

int main() {
	int a = 1, b = 1000000, digits, count = 0;
	printf("*** 1학년 1반 20번 홍길동 ***\n");
	printf("*** 1~1000000 사이의 암스트롱수 ***\n");

	for (int i = a; i <= b; i++) {
		digits = countDigitsOfNumber(i);
		if (checkArmstrongNumber(i, digits)) {
			printArmstrongNumber(i, digits);
			count++;
		}
	}

	printf("\n%d~%d 사이의 암스트롱수는 %d 개\n", a, b, count);
	return 0;
}

// num의 자릿수 n 구하기
int countDigitsOfNumber(int num) {
	/*int n = 0;
	while (num != 0) {
		num /= 10;
		n++;
	}
	return n;*/
	return log10(num) + 1;
}

// num이 암스트롱 넘버인지 체크(맞으면 1, 틀리면 0 반환)
int checkArmstrongNumber(int num, int n) {
	int sum = 0, originalNum, remainder;

	// num의 자릿수를 n 제곱한 합 sum 구하기
	for (originalNum = num; originalNum != 0; originalNum /= 10) {
		remainder = originalNum % 10;
		sum += pow(remainder % 10, n);
	}

	// 암스트롱 넘버 유무 리턴
	return (sum == num) ? 1 : 0;
}

// num의 각 자리 숫자 뒤집기
int reversNumber(int num) {
	int rev = 0, remainder;

	while (num != 0) {
		remainder = num % 10;
		rev = rev * 10 + remainder;
		num /= 10;
	}
	return rev;
}

// abc = a*a*a + b*b*b + c*c*c의 형태로 출력하기
void printArmstrongNumber(int num, int n) {
	printf("%6d = ", num);
	num = reversNumber(num);
	while (num != 0) {
		printf("%d ", (int)pow(num % 10, n));
		num /= 10;
		if (num != 0) printf("+ ");
	}
	printf("\n");
}

