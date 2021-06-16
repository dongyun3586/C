#include <stdio.h>
#pragma region 함수 정의
int addition(float arr[], int length);              //덧셈 함수
int multiplication(float arr[], int length);        //곱셈 함수
int division(float arr[], int length);              //나눗셈 함수
float pi(int n);                                    //원주율 계산 함수
float pow(float a, int n);                          //거듭제곱 계산 함수
int checkTriangle(float a, float b, float c);       //삼각형 검사 함수
float max(float a, float b, float c);               //최댓값 도출 함수
float absoluteValue(float a);                       //절대값 함수
float sqrt(float a);                                //제곱근 함수
float Integral(int arr[], int n, float a, float b);//방정식 적분 함수
int factorial(int n);                               //팩토리얼 함수
int combination(int n, int r);                      //조합 함수
int permutation(int n, int r);                      //순열 함수
int FibonacciSequence(int n);                       //피보나치 수열 함수
int i = 1;
#pragma endregion
#pragma region 메인함수(main_function)
int main() {
	for (i; i > 0; i++)     //무한 반복문
	{
		int num = 0;
		printf("1.덧셈 연산\n2.곱셈 연산\n3.나눗셈 연산\n4.원 계산\n5.삼각형의 넓이 계산\n6.간단한 방정식 정적분\n7.제곱근 구하기\n8.이차방정식의 근 구하기\n9.거듭제곱 구하기\n10.팩토리얼 계산\n11.순열과 조합 계산\n12.피보나치 수열\n13.원주율 계산\n14.종료");
		printf("\n원하는 숫자를 입력하시오. ");
		scanf("%d", &num);

		switch (num) {             //스위치 케이스문
		case 1: {                  //덧셈 연산, 배열 이용
			float arr[100] = { 0 }, num = 0;
			int length = 0;
			printf("\n*** 덧셈 연산 ***\n숫자를 그만 입력하고 싶다면 0을 입력하시오.\n\n");
			for (int i = 0; i < 100; i++) {
				printf("\n숫자를 입력하시오.");
				scanf("%f", &num);
				if (num == 0)
					break;
				length++;
				arr[i] = num;
			}
			addition(arr, length);
			break;

		}
		case 2: {                      //곱셈 연산, 배열 이용
			float arr[100] = { 0 }, num = 0;
			int length = 0;
			printf("\n*** 곱셈 연산 ***\n숫자를 그만 입력하고 싶다면 1을 누르시오.\n\n");
			for (int i = 0; i < 100; i++) {
				printf("\n숫자를 입력하시오.");
				scanf("%f", &num);
				if (num == 1)
					break;
				length++;
				arr[i] = num;
			}
			multiplication(arr, length);
			break;

		}
		case 3: {                        //나눗셈 연산
			float arr[100] = { 0 }, num = 0;
			int length = 0;
			printf("\n*** 나눗셈 연산 ***\n숫자를 그만 입력하고 싶다면 1을 누르시오.\n\n");
			for (int i = 0; i < 100; i++) {
				printf("\n숫자를 입력하시오.");
				scanf("%f", &num);
				if (num == 1)
					break;
				length++;
				arr[i] = num;
			}
			division(arr, length);
			break;

		}
		case 4: {                //원의 면적 계산 (원의 면적) = (원주율)*(반지름)^2 이용
			float diameter, surface, a = pi(250000);
			printf("\n***원의 계산***\n원의 반지름을 입력 ");
			scanf("%f", &diameter);
			surface = a * pow(diameter, 2);
			printf("원의 넓이 = %.4f\n\n", surface);
			break;
		}
		case 5: {                  //삼각형의 세 변의 길이를 통해 삼각형의 넓이 계산, 헤론의 공식 이용
			float a, b, c, w, x, y, z;
			double d = 0, surface;
			printf("\n***삼각형의 넓이 계산***\n삼각형의 세 변의 길이 입력 ");
			scanf("%f %f %f", &a, &b, &c);
			w = a + b + c, x = a + b - c, y = c + a - b, z = b + c - a;
			d = w * x * y * z;
			if (checkTriangle(a, b, c) == 1)
				surface = sqrt(d) / 4.00;
			else {
				printf("\n삼각형이 아닙니다.");
			}
			printf("\n삼각형의 넓이 = %.2f\n\n", surface);
			break;
		}
		case 6: {                         //간단한 다항방정식으로 정적분
			int n = 0, arr[100] = { 0 };
			float a, b, c;
			printf("\n***간단한 적분***\n적분할 방정식의 차수를 입력하시오. ");
			scanf("%d", &n);
			printf("\n적분할 방정식의 계수를 입력하시오.");
			for (int i = 0; i <= n; i++) {
				printf("\n%d차항의 계수 : ", i);
				scanf("%d", &arr[i]);
			}
			printf("\n적분할 다항식 : ");
			for (int i = n; i > 0; i--) {
				printf(" %dx^%d + ", arr[i], i);
			}
			printf("%d", arr[0]);
			printf("\n정적분 범위 입력 : ");
			scanf("%f %f", &a, &b);
			c = Integral(arr, n, a, b);
			printf("\n정적분 값 : %.2f\n\n", c);
			break;
		}
		case 7: {                                 //제곱근 계산, 범위를 주어 구했기 때문에 살짝 부정확할 가능성 존재
			float a, b;
			printf("\n***제곱근 구하기***\n수를 입력하시오 ");
			scanf("%f", &a);
			b = sqrt(a);
			printf("\n%.2f의 제곱근 = %.2f\n\n", a, b);
			break;
		}
		case 8: {                                  //이차방정식의 근 구하기, 이차방정식의 근의 공식 이용
			float a, b, c, Discriminant, result1, result2;
			printf("\n***이차방정식 근 구하기***\n이차방정식 : ax^2 + bx^1 + c = 0\n");
			printf("계수를 입력하시오. ");
			scanf("%f %f %f", &a, &b, &c);
			Discriminant = pow(b, 2) - 4 * a * c;
			if (Discriminant > 0) {
				result1 = (-b + sqrt(Discriminant)) / (2 * a);
				result2 = (-b - sqrt(Discriminant)) / (2 * a);
				printf("\n이차방정식의 두 근 : %.3f, %.3f\n\n", result1, result2);
			}
			else if (Discriminant == 0) {
				printf("\n이차방정식의 중근 : %.3f\n\n", -b / (2 * a));
			}
			else {
				printf("\n이차방정식의 실근이 없다.\n\n");
			}
			break;
		}
		case 9: {                                     //거듭 제곱 구하기, 반복문 이용
			float a, c;
			int n;
			printf("\n***거듭제곱 구하기***\n밑과 지수 입력 ");
			scanf("%f %d", &a, &n);
			c = pow(a, n);
			printf("\n거듭제곱 = %.3f\n\n", c);
			break;
		}
		case 10: {                                       //팩토리얼 계산, 반복문 이용
			int a;
			printf("\n***팩토리얼 계산하기***\n숫자를 입력하시오.");
			scanf("%d", &a);
			printf("\n%d! = %d\n\n", a, factorial(a));
			break;
		}
		case 11: {                                         //순열, 조합 계산, 팩토리얼 이용
			int n, r;
			printf("\n***순열과 조합 계산하기***\n숫자를 입력하시오. ");
			scanf("%d %d", &n, &r);
			printf("\n순열 %d P %d = %d\n조합 %d C %d = %d\n\n", n, r, permutation(n, r), n, r, combination(n, r));
			break;
		}
		case 12: {                                          //피보나치 수열, for문 이용
			int n, a;
			printf("\n***피보나치 수열 계산***\n숫자를 입력하시오. ");
			scanf("%d", &n);
			a = FibonacciSequence(n);
			printf("\n피보나치 수열의 %d번째 숫자 = %d\n\n", n, a);
			break;
		}
		case 13: {                                          //원주율 계산, 테일러 급수 이용
			float a;
			printf("\n***원주율 계산하기***\n");
			a = pi(300000);
			printf("원주율 = %.9f\n", a);
			break;
		}
		case 14: i = 0;
		default:return 0;

		}

	}
}
#pragma endregion
#pragma region 함수 정리
int addition(float arr[], int length) {
	float sum = 0;
	for (int i = 0; i < length; i++) {
		sum += arr[i];
	}
	for (int i = 0; i < length - 1; i++) {
		printf("%.4f + ", arr[i]);
	}
	printf("%.5f = %.5f\n\n", arr[length - 1], sum);
	return 0;
}
int multiplication(float arr[], int length) {
	float result = 1;
	for (int i = 0; i < length; i++)
		result *= arr[i];
	for (int i = 0; i < length - 1; i++) {
		printf("%.4f * ", arr[i]);
	}
	printf("%.5f = %.5f\n\n", arr[length - 1], result);
	return 0;
}
int division(float arr[], int length) {
	float result = 1;
	for (int i = 0; i < length; i++)
		result = result / arr[i];
	printf("%.4f\n\n", result);
	return 0;
}
float pi(int n) {
	float sum = 0;
	for (int i = 1; i <= n; i++) {
		if (i % 2 == 1) {
			sum += 1.00 / (2 * i - 1);
		}
		else {
			sum -= 1.00 / (2 * i - 1);
		}
	}
	return 4 * sum;
}
float pow(float a, int n) {
	float b = 1;
	for (int i = 0; i < n; i++) {
		b *= a;
	}
	return b;
}
int checkTriangle(float a, float b, float c) {
	if (max(a, b, c) < a + b + c / 2)
		return 1;
	else return 0;
}
float max(float a, float b, float c) {
	if (a >= b && a >= c)
		return a;
	else if (b >= c)
		return b;
	else return c;
}
float absoluteValue(float a) {
	if (a >= 0)
		return a;
	else return -a;
}
float sqrt(float a) {
	float t = 0;
	if (a >= 0) {
		while (1)
		{
			if (0.999 * a <= pow(t, 2) && pow(t, 2) <= 1.001 * a)
				break;
			t = t + 0.001;
		}
		return t;
	}
	else return 0;
}
float Integral(int arr[], int n, float a, float b) {
	float sum = 0;
	for (int i = 0; i <= n; i++) {
		sum += (float)arr[i] * (pow(b, i + 1) - pow(a, i + 1)) / (i + 1);
	}
	return sum;
}
int factorial(int n) {
	int a = 1;
	for (int i = 0; i < n; i++) {
		a *= i + 1;
	}
	return a;
}
int combination(int n, int r) {
	int a;
	a = factorial(n) / (factorial(n - r) * factorial(r));
	return a;
}
int permutation(int n, int r) {
	int a;
	a = factorial(n) / factorial(n - r);
	return a;
}
int FibonacciSequence(int n) {
	int a = 0, b = 1, c;
	printf("피보나치 수열 : %d ", b);
	for (int i = 0; i < n - 1; i++) {
		c = b;
		b = a + b;
		a = c;
		printf("%d ", b);
	}
	return b;
}
#pragma endregion