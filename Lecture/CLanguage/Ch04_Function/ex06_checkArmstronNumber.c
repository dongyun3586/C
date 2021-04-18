#include<stdio.h>
#include<math.h>

int checkArmstrongNumber(int);
int reversNumber(int);
void printArmstrongNumber(int);

int main() {
	int a, b;

	printf("암스트롱 정수 범위(양의 정수 두 개): ");
	scanf("%d %d", &a, &b);

	// a~b 사이의 암스트롱 넘버 출력하기
	for (int i = a; i <= b; i++) {
		if (checkArmstrongNumber(i)) {
			printf("%5d = ", i);
			printArmstrongNumber(reversNumber(i));
		}
	}
	return 0;
}

// num이 암스트롱 넘버인지 체크(맞으면 1, 틀리면 0 반환)
int checkArmstrongNumber(int num) {
	int sum = 0, originalNum, n = 0, remainder;

	// num의 자릿수 n 구하기
	for (originalNum = num; originalNum != 0; n++) {
		originalNum /= 10;
	}

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
void printArmstrongNumber(int num) {
	while (num != 0) {
		printf("%d ", (int)pow(num % 10, 3));
		num /= 10;
		if (num != 0) printf("+ ");
	}
	printf("\n");
}

