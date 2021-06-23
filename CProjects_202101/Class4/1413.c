#include<stdio.h>
#include<windows.h>  // 출력 결과 지우기 위해 사용
#include<math.h>    //pow, sqrt 사용
void cardano_formula(double arr[], double flag);    // 카르다노 해법 계산 함수(3차 함수 계산) 
double* enter_coefficients(double arr[]); //계수 입력 함수
void quadratic_function(double arr[], double flag, double arr1[]);  //이차 함수 계산 함수
void print_function(double arr[]);  //3차 함수 출력 함수
int main()
{
	double coefficient[1001] = { 0 }, c1, c2, result, tmp;
	char ch;
	int n = 0; // switch~case 문에서 사용, 처음 계수의 출력을 확인하기 위해 0으로 초기화
	printf("[3차 함수의 실근 계산 프로그램(단, 모든 계산은 소수 둘째자리까지 출력)]\n\ny=ax^3+bx^2+cx+d\n");
	enter_coefficients(coefficient);//계수 입력 함수
	int chk = 0;  // 프로그램 종료시 필요
	while (1)
	{
		if (n != 0)  // 처음 계수의 출력을 확인하기 위해 필요
			system("cls");  // 출력 기록 삭제
		printf("\n번호키를 누르면 해당 계산이 진행됩니다.\n0. 종료\n1. 계수 재입력\n2. 사칙연산(+, -, x, %%)\n3. y=0일 때 x의 값(방정식의 근)\n4. x=k일 때 함수값과 부호\n5. y=mx+n과의 교점의 좌표\n6. x축으로 m만큼, y축으로 n만큼 평행이동한 함수\n\n");
		scanf("%d", &n);
		switch (n)
		{
		case 0:  // 프로그램 종료
			printf("프로그램을 종료합니다.");
			chk = 1; //while문 종료하기 위해 필요
			break;
		case 1:     // 계수 재입력
			enter_coefficients(coefficient);//계수 입력 함수
			break;
#pragma region
		case 2:   //사칙연산(+, -, x, %)
			printf("어떤 연산을 하시겠습니까?(+, -, x, %%)");
			scanf("%c %c", &tmp, &ch);
			printf("연산하고 싶은 두 수를 입력하세요.");
			scanf("%lf %lf", &c1, &c2);
			if (ch == '+')
			{
				result = c1 + c2;
				printf("%.2f + %.2f = %.2f", c1, c2, result);
			}
			else if (ch == '-')
			{
				result = c1 - c2;
				printf("%.2f - %.2f = %.2f", c1, c2, result);
			}
			else if (ch == 'x')
			{
				result = c1 * c2;
				printf("%.2f x %.2f = %.2f", c1, c2, result);
			}
			else if (ch == '%')
			{
				result = c1 / c2;
				printf("%.2f / %.2f = %.2f", c1, c2, result);
			}
			break;
#pragma endregion
		case 3:   //y=0일 때 x의 값(방정식의 근)
			cardano_formula(coefficient, 0);// 카르다노 해법 계산 함수(3차 함수 계산) 
			break;
		case 4:   //x=k일 때 함수값과 부호
			double y1, k;
			printf("k 값을 입력하세요.");
			scanf("%lf", &k);
			y1 = coefficient[0] * pow(k, 3) + coefficient[1] * pow(k, 2) + coefficient[2] * k + coefficient[3];  //함수값
			if (y1 > 0)
				printf("y = %.2f > 0, 양수\n", y1);
			else if (y1 == 0)
				printf("y = 0\n");
			else
				printf("y = %.2f < 0, 음수\n", y1);
			break;
		case 5:   //y=mx+n과의 교점의 좌표
			double m1, n1;
			printf("m, n을 입력하세요.");
			scanf("%lf %lf", &m1, &n1);
			double coefficient_mn[] = { coefficient[0], coefficient[1], coefficient[2] - m1, coefficient[3] - n1 };//삼차함수 - 일차함수 = 0 일 때의 방정식의 계수
			cardano_formula(coefficient_mn, 1);// 카르다노 해법 계산 함수(3차 함수 계산) 
			break;
		case 6:   //x축으로 m만큼, y축으로 n만큼 평행이동한 함수
			double x, y;
			printf("얼마만큼 평행이동 할까요?[형식: m n]");
			scanf("%lf %lf", &x, &y);
			double coefficients_mn[] = { coefficient[0], -3 * coefficient[0] * x + coefficient[1], 3 * coefficient[0] * x * x - 2 * coefficient[1] * x + coefficient[2], -coefficient[0] * pow(x, 3) + coefficient[1] * x * x - coefficient[2] * x + coefficient[3] + y };//평행이동한 함수 계수
			print_function(coefficients_mn);//3차 함수 출력 함수
			break;
		default: //0~6 이외
			break;
		}
		if (chk) //프로그램 종료하기 위해 필요
			break;
		printf("\n");
		system("pause");  // '계속하려면 아무 키나 누르십시오...' 출력
	}
	return 0;
}
void print_function(double arr[])  // 3차 함수 출력 함수
{
	if (arr[0] == 1)
		printf("y = x^3 ");
	else if (arr[0] == -1)
		printf("y = -x^3 ");
	else
		printf("y = %.2fx^3 ", arr[0]);  // x^3항 출력
	for (int i = 1; i < 3; i++)
	{
		if (i == 1)
		{
			if (arr[i] > 0 && arr[i] != 1)
				printf(" + %.2fx^%d ", arr[i], 2);
			else if (arr[i] < 0 && arr[i] != -1)
				printf("- %.2fx^%d ", -arr[i], 2);
			else if (arr[i] == 1)
				printf(" x^%d ", 2);
			else if (arr[i] == -1)
				printf(" - x^%d ", 2);
		}  // x^2항 출력
		else
		{
			if (arr[i] > 0 && arr[i] != 1)
				printf(" + %.2fx ", arr[i]);
			else if (arr[i] < 0 && arr[i] != -1)
				printf("- %.2fx ", -arr[i]);
			else if (arr[i] == 1)
				printf(" x ");
			else if (arr[i] == -1)
				printf(" - x^ ");
		}  // x항 출력
	}
	if (arr[3] > 0)
		printf("+ %.2f ", arr[3]);
	else if (arr[3] < 0)
		printf(" %.2f ", arr[3]);  //  상수항 출력
}
double* enter_coefficients(double arr[])  // 계수 입력 함수
{
	while (1)
	{
		printf("계수를 입력하세요.\n");
		for (int i = 0; i < 4; i++)
			scanf("%lf", &arr[i]);
		if (arr[0] != 0)//3차 함수일 때
		{
			print_function(arr);//3차 함수 출력 함수
			return arr;
		}
		else
			printf("a는 0이 아닙니다.\n"); //3차 함수가 아닐 때
	}
}
void cardano_formula(double arr[], double flag)  // 카르다노 해법 계산 함수(3차 함수 계산)
{
	double arr2[] = { arr[1] / arr[0], arr[2] / arr[0], arr[3] / arr[0] }; // 카르다노 해법을 사용하기 위해서는 x^3의 계수가 1이어야함.
	double p, q, a, b, x1, t;
	p = arr2[1] - pow(arr2[0], 2) / 3;  //카르나도 해법에서 사용되는 p
	q = 2.0 / 27.0 * pow(arr2[0], 3.0) - arr2[0] * arr2[1] / 3 + arr2[2];  //카르나도 해법에서 사용되는 q
	printf("// p = %.2f, q = %.2f //\n", p, q);//p, q출력
	t = q * q / 4 + p * p * p / 27; // 루트 안에서 계산될 수
	if (t >= 0) // 실수체계에서, 루트 안의 수는 음수일 수 없음
	{
		double a1 = -q / 2.0 + sqrt(t), b1 = -q / 2.0 - sqrt(t); // 세제곱근을 하기 전 수
		if (a1 >= 0)
			a = pow(a1, 1 / 3.0);
		else
			a = -pow(-a1, 1 / 3.0);
		if (b1 >= 0)
			b = pow(b1, 1 / 3.0);
		else
			b = -pow(-b1, 1 / 3.0); // 원래 3제곱근 안의 수는 음수, 양수 모두 가능한데 pow 함수에서는 불가능. 따라서 음수, 양수 경우를 나눠 pow 함수에서 양수를 만들어준 뒤 음수인 경우에는 마지막에 결과값에 -1을 곱해줌.
		printf("// a(알파) = %.2f, b(베타) = %.2f //\n", a, b);//카르나도 해법에서 사용되는 알파, 베타를 a, b로 대체
		x1 = a + b - arr2[0] / 3; // 근
		printf("[함수의 해]\nx = %.2f", x1);
		if (flag) // case 5에서는 y의 값도 함께 출력해야함.
			printf("  y = %.2f", arr[0] * pow(x1, 3) + arr[1] * x1 * x1 + arr[2] * x1 + arr[3]); // x = x1일때 y값 출력
		double arr1[] = { arr2[0] + x1, arr2[0] * x1 + arr2[1] + x1 * x1 }; // 초기 삼차식을 x-x1으로 나누어 2차함수로 만들었을 때의 계수를 저장하는 배열(이차항의 계수는 항상 1이므로 생략) - 조립제법 이용
		quadratic_function(arr1, flag, arr); // 이차 함수 계산 함수
	}
	else if (q == 0 && t < 0)  // 실수 체계에서 루트 안의 수가 음수일 수 없지만, 카르나도 해법에서 x를 구할 때 a, b(알파, 베타)를 더하므로 q=0이라면 t<0이더라도 합하면서 허수 부분이 상쇄되어 실수근이 존재할 수 있음.
	{
		x1 = -arr2[0] / 3;
		printf("[함수의 해]\nx = %.2f", x1);
		if (flag)
			printf("  y = %.2f", arr[0] * pow(x1, 3) + arr[1] * x1 * x1 + arr[2] * x1 + arr[3]); // x = x1일때 함수값
		double arr1[] = { arr2[0] + x1, arr2[0] * x1 + arr2[1] + x1 * x1 }; // 3차 함수를 x-x1 으로 나누어 2차 함수를 구했을 때의 계수 입력(단, 이차항의 계수는 항상 1이므로 생략) - 조립제법 이용
		quadratic_function(arr1, flag, arr); // 이차 함수 계산 함수
	}
	else
		printf("세 근 모두 허근을 갖습니다."); // 위 2가지 경우가 아니면 허근을 갖는다.
}
void quadratic_function(double arr[], double flag, double arr1[]) //이차 함수 계산 함수
{
	double dis, x2, x3;
	dis = arr[0] * arr[0] - 4.0 * arr[1];  // 주어진 2차 함수의 계수로 계산하는 판별식
	if (dis >= 0) // 판별식의 값이 0보다 크거나 같으면 실근을 갖는다.
	{
		x2 = (-arr[0] + sqrt(dis)) / 2;
		x3 = (-arr[0] - sqrt(dis)) / 2;
		printf("\nx = %.2lf", x2);
		if (flag)
			printf("  y = %.2f", arr1[0] * pow(x2, 3) + arr1[1] * x2 * x2 + arr1[2] * x2 + arr1[3]);
		printf("\nx = %.2lf", x3);
		if (flag)
			printf("  y = %.2f", arr1[0] * pow(x3, 3) + arr1[1] * x3 * x3 + arr1[2] * x3 + arr1[3]);  // case 5에서는 함수값도 함께 출력해야 됨.
	}
	else // 판별식의 값이 0보다 작으면 허근을 갖는다.
		printf("\n나머지 두 근은 허근입니다.");
}