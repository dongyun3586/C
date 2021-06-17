#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
void findtwo(double ma, double mb); // 두 수중 최댓값과 최솟값을 출력하는 함수입니다.
void findthree(double ma, double mb, double mc); // 세수중 최댓값과 최솟값을 출력하는 함수입니다.
void findfour(double ma, double mb, double mc, double md); // 네수중 최댓값과 최솟값을 출력하는 함수입니다. 
int main() {
	int n; // 차수
	double d, alp, bet, ya = 0, yb = 0, yc = 0, yd = 0, ra, rb; // 프로그램중 사용되는 변수들
	double xa, xb, xc, xd; // 최종적으로 값을 비교할 변수입니다.
	printf("다항함수의 최댓값, 최솟값을 구하는 프로그램입니다.\n\n"); // 프로그램에 대한 소개입니다.
	printf("x값의 범위는 a<= x <=b 입니다. a, b 값을 입력해주세요: "); // x값의 범위를 입력합니다.
	scanf("%lf %lf", &ra, &rb);
	printf("\n몇차 다항식 입니까? (차수는 최대 3차입니다.): "); // 함수의 차수를 입력합니다.
	scanf("%d", &n);
	double cef[4];
	double cef1[4] = { 0 };
	double xx[4];
	printf("\n최고차항의 계수부터 상수항 까지 공백을 넣어 차례대로 값을 입력해주세요. "); // 다항함수의 항들의 계수를 입력하는 방식으로 다항함수를 입력한다.
	for (int b = n; b >= 0; b--)
		scanf("%lf", &cef[b]);
	for (int c = n - 1; c >= 0; c--) {
		cef1[c] = (double)((c + 1.0) * cef[c + 1]); // 각 항마다 미분을 한뒤의 계수를 또다른 배열에 입력하는 과정입니다.
	}
	if (n == 3) { // 3차다항식일때의 과정입니다.
		d = (double)(cef1[1] * cef1[1] - 4 * cef1[0] * cef1[2]); // 미분을 하면 이차식이 나오는데, 그이차식의 판별식D의 값입니다.
		if (d >= 0) { // 이차식의 해가 존재할때, 즉 극값이 존재할때의 과정입니다.
			alp = (-cef1[1] + sqrt(d)) / (2 * cef1[2]);
			bet = (-cef1[1] - sqrt(d)) / (2 * cef1[2]);  // alp, bet 는 이차식의 두 해입니다.
			if (ra > alp || alp > rb)
				alp = ra;
			if (ra > bet || bet > rb) // alp, bet 값이 입력한 범위에 존재하지 않을때는 alp, bet 값을 ra, rb 값으로 바꿔 소거해주는 과정입니다.
				bet = ra;
			for (int j = 0; j < n + 1; j++) { // 각항의 계수가 1일때의 값을 xx[j] 라는 배열에 입력하는 과정입니다. 
				xx[j] = 1;
				for (int k = 0; k < j; k++)
					xx[j] *= alp;
			}
			for (int q = 0; q < n + 1; q++) { // 이제 각항의 계수가 1일때의 값에 계수값을 곱하여 최종적인 함숫값을 구합니다. 이과정을 극값 2번, 입력한 범위 2번으로 총 4번 반복합니다. 
				ya = ya + (cef[q]) * xx[q];
				xa = ya;
			}
			for (int j = 0; j < n + 1; j++) {
				xx[j] = 1;
				for (int k = 0; k < j; k++)
					xx[j] *= bet;
			}
			for (int q = 0; q < n + 1; q++) {
				yb = yb + (cef[q]) * xx[q];
				xb = yb;
			}
			for (int j = 0; j < n + 1; j++) {
				xx[j] = 1;
				for (int k = 0; k < j; k++)
					xx[j] *= ra;
			}
			for (int q = 0; q < n + 1; q++) {
				yc = yc + (cef[q]) * xx[q];
				xc = yc;
			}
			for (int j = 0; j < n + 1; j++) {
				xx[j] = 1;
				for (int k = 0; k < j; k++)
					xx[j] *= rb;
			}
			for (int q = 0; q < n + 1; q++) {
				yd = yd + (cef[q]) * xx[q];
				xd = yd;
			}
			findfour(xa, xb, xc, xd); // 구한 4개의 함숫값중 정의한 함수를 이용해 최대, 최소값을 출력합니다. 
		}
		else {// 이차식의 해가 존재하지 않을때의 과정으로 이때는 ra, rb의 함숫값들만 비교하면 됩니다. 
			for (int j = 0; j < n + 1; j++) {
				xx[j] = 1;
				for (int k = 0; k < j; k++)
					xx[j] *= ra;
			}
			for (int q = 0; q < n + 1; q++) {
				ya = ya + (cef[q]) * xx[q];
				xa = ya;
			}
			for (int j = 0; j < n + 1; j++) {
				xx[j] = 1;
				for (int k = 0; k < j; k++)
					xx[j] *= rb;
			}
			for (int q = 0; q < n + 1; q++) {
				yb = yb + (cef[q]) * xx[q];
				xb = yb;
			}
			findtwo(xa, xb);// 함숫값 2개중 최대, 최소를 출력합니다.
		}
	}
	if (n == 2) {// 이차함수일때의 과정입니다.
		d = -cef1[0] / cef1[1]; // 이차식을 미분하면 일차식이 나오는데 그때 극값을 갖도록 하는 값, d를 설정합니다.
		if (ra > d || d > rb) // d가 사용자가 입력한 범위에 위치하지 않을때 d값을 최대, 최소를 구할때 고려하지 못하도록 d값을 ra값으로 바꿉니다.
			d = ra;
		for (int j = 0; j < n + 1; j++) {// 3차식일때처럼 d, ra, rb일때의 함숫값을 구해줍니다.
			xx[j] = 1;
			for (int k = 0; k < j; k++)
				xx[j] *= ra;
		}
		for (int q = 0; q < n + 1; q++) {
			ya = ya + (cef[q]) * xx[q];
			xa = ya;
		}
		for (int j = 0; j < n + 1; j++) {
			xx[j] = 1;
			for (int k = 0; k < j; k++)
				xx[j] *= rb;
		}
		for (int q = 0; q < n + 1; q++) {
			yb = yb + (cef[q]) * xx[q];
			xb = yb;
		}
		for (int j = 0; j < n + 1; j++) {
			xx[j] = 1;
			for (int k = 0; k < j; k++)
				xx[j] *= d;
		}
		for (int q = 0; q < n + 1; q++) {
			yc = yc + (cef[q]) * xx[q];
			xc = yc;
		}
		findthree(xa, xb, xc);// 세 함숫값중 최대, 최소를 출력합니다.
	}
	if (n == 1) {// 일차함수일때 입니다. 일차함수는 극값이 존재하지 않으므로 바로 ra,rb 일때의 함숫값을 구해줍니다.
		for (int j = 0; j < n + 1; j++) {
			xx[j] = 1;
			for (int k = 0; k < j; k++)
				xx[j] *= ra;
		}
		for (int q = 0; q < n + 1; q++) {
			ya = ya + (cef[q]) * xx[q];
			xa = ya;
		}
		for (int j = 0; j < n + 1; j++) {
			xx[j] = 1;
			for (int k = 0; k < j; k++)
				xx[j] *= rb;
		}
		for (int q = 0; q < n + 1; q++) {
			yb = yb + (cef[q]) * xx[q];
			xb = yb;
		}
		findtwo(xa, xb);// 두함숫값중 최대, 최솟값을 출력합니다.
	}
}
void findtwo(double ma, double mb)// 두 수중 최댓값과 최솟값을 출력하는 함수입니다.
{
	if (ma >= mb) {
		printf("최댓값: %lf", ma);
		printf("\n최솟값: %lf", mb);
	}
	else {
		printf("최댓값: %lf", mb);
		printf("\n최솟값: %lf", ma);
	}
}
void findthree(double ma, double mb, double mc) //  세수중 최댓값과 최솟값을 출력하는 함수입니다.
{
	double max, min;
	if (ma >= mb)
	{
		max = ma;
		min = mb;
	}
	else {
		max = mb;
		min = ma;
	}
	if (mc > max)
		max = mc;
	if (mc < min)
		min = mc;
	printf("최댓값: %lf", max);
	printf("\n최솟값: %lf", min);
}
void findfour(double ma, double mb, double mc, double md) //  네수중 최댓값과 최솟값을 출력하는 함수입니다. 
{
	double max, min;
	if (ma >= mb) {
		max = ma;
		min = mb;
	}
	else {
		max = mb;
		min = ma;
	}
	if (mc > max)
		max = mc;
	if (mc < min)
		min = mc;
	if (md > max)
		max = md;
	if (md < min)
		min = md;
	printf("최댓값: %lf", max);
	printf("\n최솟값: %lf", min);
}