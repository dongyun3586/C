#include<stdio.h>
#include<math.h>

int main_ex06_quadraticEquation() {
	double a, b, c, dis;	// 계수(coefficient)와 판별식(Discriminant)의 결과 저장 변수
	scanf("%lf %lf %lf", &a, &b, &c);	// double형의 실수를 출력할 때는 "%lf" 또는 "%f"를 모두 사용할 수 있다. 하지만 입력을 받을 때는 반드시 "%lf"를 사용해야 한다.

	if (a == 0)
		printf("방정식의 근은 %f 입니다.", -c / b);
	else {
		dis = b * b - 4.0 * a * c;
		if (dis >= 0) {
			printf("방정식의 근은 %f입니다.\n", (-b + sqrt(dis)) / (2.0 * a));
			printf("방정식의 근은 %f입니다.\n", (-b - sqrt(dis)) / (2.0 * a));
		}
		else
			printf("실근이 존재하지 않습니다. \n");
	}

	return 0;
}