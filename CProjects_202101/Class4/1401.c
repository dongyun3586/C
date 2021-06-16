#include <stdio.h>
#include <math.h>

double coeff[1001] = { 0 }; // 함수의 계수를 입력받을 배열 선언
double dlu[1001] = { 0 }; // 도함수의 계수를 배열로 선언
int off = 2; // 전원의 종료여부를 결정하는 전역 변수

void check(int n); // 입력한 도함수를 다시 한 번 출력해주는 함수
void derive(int n); // 도함수를 계산해주는 함수
void sol(int n); // 도함수의 값이 0이 되는 값을 찾아주는 함수
int power(int off); // 전원의 종료여부를 결정해주는 함수

int main() {
	int n = 0; // 몇 차 인지 입력받는 변수
	printf("                  ******* 도함수 계산기 ********\n\n");
	printf("      도함수 계산기를 이용해서 함수의 도함수를 마음껏 구해보세요!\n");
	while (off != 0) { // off가 0이면 반복을 멈추고 종료된다.
		printf("몇차 함수인지 입력해 주세요. 함수의 최고차항의 차수는 0이상 3차 이하여야 합니다. ");
		scanf("%d", &n);  //n차 다항식 입력
		if (n > 3 || n < 0) {
			while (!(n == 0 || n == 1 || n == 2 || n == 3)) { // n이 0, 1, 2, 3이 아닐땐 계속 입력받음
				printf("\n함수의 최고차항의 차수는 0이상 3차 이하여야 합니다. 다시 입력해주세요. ");
				scanf("%d", &n); // 함수의 최고차항의 차수 다시 입력받음
			}
		}
		printf("\n최고차항부터 상수항까지의 계수를 입력해주세요(항이 없다면 0 입력). ");
		for (int i = n; i >= 0; i--) {
			scanf("%lf", &coeff[i]); // 배열에다가 계수 하나씩 입력받음
		}
		printf("\n입력한 함수는 \u03A5 = ");
		check(n); // check 함수에서 입력값 다시 한 번 확인
		printf("\n도함수는 \u03A5\' = ");
		derive(n);// derive 함수에서 도함수를 계산
		printf("\n도함수를 0이 되게 하는 \u03C7값은 ");
		sol(n); // sol 함수에서 도함수가 0이 되게 하는 값을 계산
		printf("계산기를 종료하시겠습니까? 종료: 0, 다른 함수 계산: 1\n"); // 또 다른 계산을 반복할지 물어봄
		power(off);
	}
}
void check(int n) {
	for (int i = n; i >= 1; i--) {
		printf("%.2lf\u03C7^%d + ", coeff[i], i); // 입력한 함수가 맞는지 다시 한 번 확인
	}
	printf("%.2lf 입니다. \n", coeff[0]);
}
void derive(int n) {
	for (int i = n; i >= 0; i--) {
		dlu[i] = coeff[i] * i;  //배열에 도함수의 차수 입력     
	}
	switch (n) { // 차수에 따라 도함수 계산 분리
	case 3: // 3차일 때 도함수 구하기
		printf("%.2lf\u03C7^%d + ", dlu[n], n - 1); //nx^3을 미분하면, 3nx^2가 나온다.
		printf("%.2lf\u03C7 + ", dlu[n - 1]); //nx^2을 미분하면, 2nx가 나온다.
		printf("%.2lf 입니다. \n", dlu[1]); // 1차 다항식을 미분하면 x의 계수가 나온다.
		break;
	case 2: // 2차일 때 도함수 구하기
		printf("%.2lf\u03C7 + ", dlu[n]); //nx^n을 미분하면, n^2x^n-1
		printf("%.2lf 입니다. \n", dlu[n - 1]);  // 1차 다항식을 미분하면 x의 계수가 나온다.
		break;
	case 1:  // 1차일 때 도함수 구하기
		printf("%.2lf 입니다. \n", dlu[1]); // 1차 다항식은 미분하면 x의 계수가 나온다.
		break;
	default: // 상수항일 때 도함수 구하기
		printf("0 입니다. \n"); // 0차 다항식은 상수항. 미분하면 0이다.
		break;
	}
}
void sol(int n) {
	double D = (dlu[2] * dlu[2]) - 4 * dlu[1] * dlu[3];
	switch (n) {
	case 0:
		printf("모든 실수입니다. \n"); // y=0 만족하는 x는 모든 실수!
		break;
	case 1:
		printf("모든 실수입니다. \n"); // y=a 만족하는 x는 모든 실수!
		break;
	case 2:
		printf("%.2lf입니다. \n", -dlu[2] / dlu[1]); // y=ax+b 만족하는 x는 -b/a
		break;
	case 3: // 도함수는 이차함수인데, 이 때는 판별식의 범위에 따라 근이 나뉜다.
		if (D > 0) { // D>0이면 두 실근 존재한다.
			printf("%.2lf과 ", (-dlu[2] + sqrt(D)) / (2 * dlu[3])); // 이차방정식의 근의 공식 사용
			printf("%.2lf입니다. \n", (-dlu[2] - sqrt(D)) / (2 * dlu[3]));
		}
		else if (D < 0) { // D<0이면 두 허근 존재한다.
			printf("허수근입니다.\n"); // 이차방정식의 근의 공식 사용, 이 때 D<0이므로 -D로 넣어준뒤 허수단위 i를 붙여준다.
			printf("%.2lf\u0069 + (%.2lf)과 ", (-dlu[2] + sqrt(-D)) / 2 * dlu[3], -dlu[2] / (2 * dlu[3])); // 이차방정식의 근의 공식 사용
			printf("%.2lf\u0069 - (%.2lf)입니다. \n", (-dlu[2] + sqrt(-D)) / 2 * dlu[3], -dlu[2] / (2 * dlu[3]));
		}
		else // D=0이면 중근이 하나 존재한다.
			printf("%.2lf입니다.(중근) \n", -dlu[2] / (2 * dlu[3])); // D=0이므로 sqrt안의 항이 사라진다. 
		break;
	}
}
int power() {
	scanf("%d", &off); // 전원을 끌지 결정
	if (off == 0)
		return 0;
	else
		return 1;
}
