#include <stdio.h>
#pragma region �Լ� ����
int addition(float arr[], int length);              //���� �Լ�
int multiplication(float arr[], int length);        //���� �Լ�
int division(float arr[], int length);              //������ �Լ�
float pi(int n);                                    //������ ��� �Լ�
float pow(float a, int n);                          //�ŵ����� ��� �Լ�
int checkTriangle(float a, float b, float c);       //�ﰢ�� �˻� �Լ�
float max(float a, float b, float c);               //�ִ� ���� �Լ�
float absoluteValue(float a);                       //���밪 �Լ�
float sqrt(float a);                                //������ �Լ�
float Integral(int arr[], int n, float a, float b);//������ ���� �Լ�
int factorial(int n);                               //���丮�� �Լ�
int combination(int n, int r);                      //���� �Լ�
int permutation(int n, int r);                      //���� �Լ�
int FibonacciSequence(int n);                       //�Ǻ���ġ ���� �Լ�
int i = 1;
#pragma endregion
#pragma region �����Լ�(main_function)
int main() {
	for (i; i > 0; i++)     //���� �ݺ���
	{
		int num = 0;
		printf("1.���� ����\n2.���� ����\n3.������ ����\n4.�� ���\n5.�ﰢ���� ���� ���\n6.������ ������ ������\n7.������ ���ϱ�\n8.������������ �� ���ϱ�\n9.�ŵ����� ���ϱ�\n10.���丮�� ���\n11.������ ���� ���\n12.�Ǻ���ġ ����\n13.������ ���\n14.����");
		printf("\n���ϴ� ���ڸ� �Է��Ͻÿ�. ");
		scanf("%d", &num);

		switch (num) {             //����ġ ���̽���
		case 1: {                  //���� ����, �迭 �̿�
			float arr[100] = { 0 }, num = 0;
			int length = 0;
			printf("\n*** ���� ���� ***\n���ڸ� �׸� �Է��ϰ� �ʹٸ� 0�� �Է��Ͻÿ�.\n\n");
			for (int i = 0; i < 100; i++) {
				printf("\n���ڸ� �Է��Ͻÿ�.");
				scanf("%f", &num);
				if (num == 0)
					break;
				length++;
				arr[i] = num;
			}
			addition(arr, length);
			break;

		}
		case 2: {                      //���� ����, �迭 �̿�
			float arr[100] = { 0 }, num = 0;
			int length = 0;
			printf("\n*** ���� ���� ***\n���ڸ� �׸� �Է��ϰ� �ʹٸ� 1�� �����ÿ�.\n\n");
			for (int i = 0; i < 100; i++) {
				printf("\n���ڸ� �Է��Ͻÿ�.");
				scanf("%f", &num);
				if (num == 1)
					break;
				length++;
				arr[i] = num;
			}
			multiplication(arr, length);
			break;

		}
		case 3: {                        //������ ����
			float arr[100] = { 0 }, num = 0;
			int length = 0;
			printf("\n*** ������ ���� ***\n���ڸ� �׸� �Է��ϰ� �ʹٸ� 1�� �����ÿ�.\n\n");
			for (int i = 0; i < 100; i++) {
				printf("\n���ڸ� �Է��Ͻÿ�.");
				scanf("%f", &num);
				if (num == 1)
					break;
				length++;
				arr[i] = num;
			}
			division(arr, length);
			break;

		}
		case 4: {                //���� ���� ��� (���� ����) = (������)*(������)^2 �̿�
			float diameter, surface, a = pi(250000);
			printf("\n***���� ���***\n���� �������� �Է� ");
			scanf("%f", &diameter);
			surface = a * pow(diameter, 2);
			printf("���� ���� = %.4f\n\n", surface);
			break;
		}
		case 5: {                  //�ﰢ���� �� ���� ���̸� ���� �ﰢ���� ���� ���, ����� ���� �̿�
			float a, b, c, w, x, y, z;
			double d = 0, surface;
			printf("\n***�ﰢ���� ���� ���***\n�ﰢ���� �� ���� ���� �Է� ");
			scanf("%f %f %f", &a, &b, &c);
			w = a + b + c, x = a + b - c, y = c + a - b, z = b + c - a;
			d = w * x * y * z;
			if (checkTriangle(a, b, c) == 1)
				surface = sqrt(d) / 4.00;
			else {
				printf("\n�ﰢ���� �ƴմϴ�.");
			}
			printf("\n�ﰢ���� ���� = %.2f\n\n", surface);
			break;
		}
		case 6: {                         //������ ���׹��������� ������
			int n = 0, arr[100] = { 0 };
			float a, b, c;
			printf("\n***������ ����***\n������ �������� ������ �Է��Ͻÿ�. ");
			scanf("%d", &n);
			printf("\n������ �������� ����� �Է��Ͻÿ�.");
			for (int i = 0; i <= n; i++) {
				printf("\n%d������ ��� : ", i);
				scanf("%d", &arr[i]);
			}
			printf("\n������ ���׽� : ");
			for (int i = n; i > 0; i--) {
				printf(" %dx^%d + ", arr[i], i);
			}
			printf("%d", arr[0]);
			printf("\n������ ���� �Է� : ");
			scanf("%f %f", &a, &b);
			c = Integral(arr, n, a, b);
			printf("\n������ �� : %.2f\n\n", c);
			break;
		}
		case 7: {                                 //������ ���, ������ �־� ���߱� ������ ��¦ ����Ȯ�� ���ɼ� ����
			float a, b;
			printf("\n***������ ���ϱ�***\n���� �Է��Ͻÿ� ");
			scanf("%f", &a);
			b = sqrt(a);
			printf("\n%.2f�� ������ = %.2f\n\n", a, b);
			break;
		}
		case 8: {                                  //������������ �� ���ϱ�, ������������ ���� ���� �̿�
			float a, b, c, Discriminant, result1, result2;
			printf("\n***���������� �� ���ϱ�***\n���������� : ax^2 + bx^1 + c = 0\n");
			printf("����� �Է��Ͻÿ�. ");
			scanf("%f %f %f", &a, &b, &c);
			Discriminant = pow(b, 2) - 4 * a * c;
			if (Discriminant > 0) {
				result1 = (-b + sqrt(Discriminant)) / (2 * a);
				result2 = (-b - sqrt(Discriminant)) / (2 * a);
				printf("\n������������ �� �� : %.3f, %.3f\n\n", result1, result2);
			}
			else if (Discriminant == 0) {
				printf("\n������������ �߱� : %.3f\n\n", -b / (2 * a));
			}
			else {
				printf("\n������������ �Ǳ��� ����.\n\n");
			}
			break;
		}
		case 9: {                                     //�ŵ� ���� ���ϱ�, �ݺ��� �̿�
			float a, c;
			int n;
			printf("\n***�ŵ����� ���ϱ�***\n�ذ� ���� �Է� ");
			scanf("%f %d", &a, &n);
			c = pow(a, n);
			printf("\n�ŵ����� = %.3f\n\n", c);
			break;
		}
		case 10: {                                       //���丮�� ���, �ݺ��� �̿�
			int a;
			printf("\n***���丮�� ����ϱ�***\n���ڸ� �Է��Ͻÿ�.");
			scanf("%d", &a);
			printf("\n%d! = %d\n\n", a, factorial(a));
			break;
		}
		case 11: {                                         //����, ���� ���, ���丮�� �̿�
			int n, r;
			printf("\n***������ ���� ����ϱ�***\n���ڸ� �Է��Ͻÿ�. ");
			scanf("%d %d", &n, &r);
			printf("\n���� %d P %d = %d\n���� %d C %d = %d\n\n", n, r, permutation(n, r), n, r, combination(n, r));
			break;
		}
		case 12: {                                          //�Ǻ���ġ ����, for�� �̿�
			int n, a;
			printf("\n***�Ǻ���ġ ���� ���***\n���ڸ� �Է��Ͻÿ�. ");
			scanf("%d", &n);
			a = FibonacciSequence(n);
			printf("\n�Ǻ���ġ ������ %d��° ���� = %d\n\n", n, a);
			break;
		}
		case 13: {                                          //������ ���, ���Ϸ� �޼� �̿�
			float a;
			printf("\n***������ ����ϱ�***\n");
			a = pi(300000);
			printf("������ = %.9f\n", a);
			break;
		}
		case 14: i = 0;
		default:return 0;

		}

	}
}
#pragma endregion
#pragma region �Լ� ����
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
	printf("�Ǻ���ġ ���� : %d ", b);
	for (int i = 0; i < n - 1; i++) {
		c = b;
		b = a + b;
		a = c;
		printf("%d ", b);
	}
	return b;
}
#pragma endregion