#include <stdio.h>
#include <math.h>
#define l 0.5/1000
#define b 8.22/1000
#define p 1.013*100000
#define g 9.8
#define rho 886
#define volt 400
#define d 0.00767
#define pi 3.141592653589793238462643383279
#define q0 0.00000000000000000016021773349

void scientific_notation(double n);

double velocity(double t);

double visocosity(double eta);

double radius(double vf, double eta);

double mass(double r);

double charge(double vf, double vr, double m);

double errorrate(double q);

double mean(double Arr[], int n);

int main() {

	printf("***이 프로그램은 밀리컨의 기름방울 실험을 통해 전자의 기본 전하량을 구하는 프로그램 입니다.***\n\n");
	printf("실험을 몇번 진행하셨나요? (최대 100회) : ");
	int n;
	double Arr[100] = { 0 };
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		printf("\n========================================================");
		printf("\n실험 %d\n\n", i + 1);
		double tf, tr, eta;
		printf("전기장이 없을 때 기름방울이 단위격자를 지나는데 몇 초가 걸렸나요? ");
		scanf("%lf", &tf);
		printf("전기장이 있을 때 기름방울이 단위격자를 지나는데 몇 초가 걸렸나요? ");
		scanf("%lf", &tr);
		printf("공기의 점성은 얼마인가요? ");
		scanf("%lf", &eta);
		double vf = velocity(tf);
		double vr = velocity(tr);
		eta = visocosity(eta);
		double r = radius(vf, eta);
		double m = mass(r);
		double q = charge(vf, vr, m);
		double e = errorrate(q);
		printf("\n실험 %d 결과\n", i + 1);
		printf("종단속도: ");
		scientific_notation(vf);
		printf("\n상승속도: ");
		scientific_notation(vr);
		printf("\n기름방울의 반지름: ");
		scientific_notation(r);
		printf("\n기름방울의 질량: ");
		scientific_notation(m);
		printf("\n기름방울의 전하량: ");
		scientific_notation(q);
		printf("\n실험의 오차율: %.3f%%", e);
		printf("\n");
		Arr[i] = q;
	}
	printf("\n========================================================");
	printf("\n실험 결과\n\n");
	printf("\n전자의 평균 전하량: ");
	scientific_notation(mean(Arr, n));
	printf("\n오차율: %.3f%%\n", errorrate(mean(Arr, n)));

	return 0;
}

void scientific_notation(double n) {
	int m = 0;
	while (1) {
		if (n < 1) {
			m--;
			n *= 10;
		}
		else if (n >= 10) {
			m++;
			n /= 10;
		}
		else if (n >= 1 && n < 10)
			break;
	}
	printf("%.3lf * 10^%d", n, m);
}

double velocity(double t) {
	double v = l / t;
	return v;
}

double visocosity(double eta) {
	double vis = eta / 100000;
	return vis;
}

double radius(double vf, double eta) {
	double r = sqrt(pow(b / (2 * p), 2) + ((9 * eta * vf) / (2 * g * rho))) - (b / (2 * p));
	return r;
}

double mass(double r) {
	double m = (4 / 3) * pi * pow(r, 3) * rho;
	return m;
}

double charge(double vf, double vr, double m) {
	double q = (m * g * (vf + vr)) / (vf * (volt / d));
	return q;
}

double errorrate(double q) {
	double e = (q0 - q) / q0;
	if (e < 0)
		e *= -1;
	e *= 100;
	return e;
}

double mean(double Arr[], int n) {
	double m = 0;
	for (int i = 0; i < n; i++)
		m += Arr[i];
	return m / n;
}