#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
void findtwo(double ma, double mb); // �� ���� �ִ񰪰� �ּڰ��� ����ϴ� �Լ��Դϴ�.
void findthree(double ma, double mb, double mc); // ������ �ִ񰪰� �ּڰ��� ����ϴ� �Լ��Դϴ�.
void findfour(double ma, double mb, double mc, double md); // �׼��� �ִ񰪰� �ּڰ��� ����ϴ� �Լ��Դϴ�. 
int main() {
	int n; // ����
	double d, alp, bet, ya = 0, yb = 0, yc = 0, yd = 0, ra, rb; // ���α׷��� ���Ǵ� ������
	double xa, xb, xc, xd; // ���������� ���� ���� �����Դϴ�.
	printf("�����Լ��� �ִ�, �ּڰ��� ���ϴ� ���α׷��Դϴ�.\n\n"); // ���α׷��� ���� �Ұ��Դϴ�.
	printf("x���� ������ a<= x <=b �Դϴ�. a, b ���� �Է����ּ���: "); // x���� ������ �Է��մϴ�.
	scanf("%lf %lf", &ra, &rb);
	printf("\n���� ���׽� �Դϱ�? (������ �ִ� 3���Դϴ�.): "); // �Լ��� ������ �Է��մϴ�.
	scanf("%d", &n);
	double cef[4];
	double cef1[4] = { 0 };
	double xx[4];
	printf("\n�ְ������� ������� ����� ���� ������ �־� ���ʴ�� ���� �Է����ּ���. "); // �����Լ��� �׵��� ����� �Է��ϴ� ������� �����Լ��� �Է��Ѵ�.
	for (int b = n; b >= 0; b--)
		scanf("%lf", &cef[b]);
	for (int c = n - 1; c >= 0; c--) {
		cef1[c] = (double)((c + 1.0) * cef[c + 1]); // �� �׸��� �̺��� �ѵ��� ����� �Ǵٸ� �迭�� �Է��ϴ� �����Դϴ�.
	}
	if (n == 3) { // 3�����׽��϶��� �����Դϴ�.
		d = (double)(cef1[1] * cef1[1] - 4 * cef1[0] * cef1[2]); // �̺��� �ϸ� �������� �����µ�, ���������� �Ǻ���D�� ���Դϴ�.
		if (d >= 0) { // �������� �ذ� �����Ҷ�, �� �ذ��� �����Ҷ��� �����Դϴ�.
			alp = (-cef1[1] + sqrt(d)) / (2 * cef1[2]);
			bet = (-cef1[1] - sqrt(d)) / (2 * cef1[2]);  // alp, bet �� �������� �� ���Դϴ�.
			if (ra > alp || alp > rb)
				alp = ra;
			if (ra > bet || bet > rb) // alp, bet ���� �Է��� ������ �������� �������� alp, bet ���� ra, rb ������ �ٲ� �Ұ����ִ� �����Դϴ�.
				bet = ra;
			for (int j = 0; j < n + 1; j++) { // ������ ����� 1�϶��� ���� xx[j] ��� �迭�� �Է��ϴ� �����Դϴ�. 
				xx[j] = 1;
				for (int k = 0; k < j; k++)
					xx[j] *= alp;
			}
			for (int q = 0; q < n + 1; q++) { // ���� ������ ����� 1�϶��� ���� ������� ���Ͽ� �������� �Լ����� ���մϴ�. �̰����� �ذ� 2��, �Է��� ���� 2������ �� 4�� �ݺ��մϴ�. 
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
			findfour(xa, xb, xc, xd); // ���� 4���� �Լ����� ������ �Լ��� �̿��� �ִ�, �ּҰ��� ����մϴ�. 
		}
		else {// �������� �ذ� �������� �������� �������� �̶��� ra, rb�� �Լ����鸸 ���ϸ� �˴ϴ�. 
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
			findtwo(xa, xb);// �Լ��� 2���� �ִ�, �ּҸ� ����մϴ�.
		}
	}
	if (n == 2) {// �����Լ��϶��� �����Դϴ�.
		d = -cef1[0] / cef1[1]; // �������� �̺��ϸ� �������� �����µ� �׶� �ذ��� ������ �ϴ� ��, d�� �����մϴ�.
		if (ra > d || d > rb) // d�� ����ڰ� �Է��� ������ ��ġ���� ������ d���� �ִ�, �ּҸ� ���Ҷ� ������� ���ϵ��� d���� ra������ �ٲߴϴ�.
			d = ra;
		for (int j = 0; j < n + 1; j++) {// 3�����϶�ó�� d, ra, rb�϶��� �Լ����� �����ݴϴ�.
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
		findthree(xa, xb, xc);// �� �Լ����� �ִ�, �ּҸ� ����մϴ�.
	}
	if (n == 1) {// �����Լ��϶� �Դϴ�. �����Լ��� �ذ��� �������� �����Ƿ� �ٷ� ra,rb �϶��� �Լ����� �����ݴϴ�.
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
		findtwo(xa, xb);// ���Լ����� �ִ�, �ּڰ��� ����մϴ�.
	}
}
void findtwo(double ma, double mb)// �� ���� �ִ񰪰� �ּڰ��� ����ϴ� �Լ��Դϴ�.
{
	if (ma >= mb) {
		printf("�ִ�: %lf", ma);
		printf("\n�ּڰ�: %lf", mb);
	}
	else {
		printf("�ִ�: %lf", mb);
		printf("\n�ּڰ�: %lf", ma);
	}
}
void findthree(double ma, double mb, double mc) //  ������ �ִ񰪰� �ּڰ��� ����ϴ� �Լ��Դϴ�.
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
	printf("�ִ�: %lf", max);
	printf("\n�ּڰ�: %lf", min);
}
void findfour(double ma, double mb, double mc, double md) //  �׼��� �ִ񰪰� �ּڰ��� ����ϴ� �Լ��Դϴ�. 
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
	printf("�ִ�: %lf", max);
	printf("\n�ּڰ�: %lf", min);
}