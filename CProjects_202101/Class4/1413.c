#include<stdio.h>
#include<windows.h>  // ��� ��� ����� ���� ���
#include<math.h>    //pow, sqrt ���
void cardano_formula(double arr[], double flag);    // ī���ٳ� �ع� ��� �Լ�(3�� �Լ� ���) 
double* enter_coefficients(double arr[]); //��� �Է� �Լ�
void quadratic_function(double arr[], double flag, double arr1[]);  //���� �Լ� ��� �Լ�
void print_function(double arr[]);  //3�� �Լ� ��� �Լ�
int main()
{
	double coefficient[1001] = { 0 }, c1, c2, result, tmp;
	char ch;
	int n = 0; // switch~case ������ ���, ó�� ����� ����� Ȯ���ϱ� ���� 0���� �ʱ�ȭ
	printf("[3�� �Լ��� �Ǳ� ��� ���α׷�(��, ��� ����� �Ҽ� ��°�ڸ����� ���)]\n\ny=ax^3+bx^2+cx+d\n");
	enter_coefficients(coefficient);//��� �Է� �Լ�
	int chk = 0;  // ���α׷� ����� �ʿ�
	while (1)
	{
		if (n != 0)  // ó�� ����� ����� Ȯ���ϱ� ���� �ʿ�
			system("cls");  // ��� ��� ����
		printf("\n��ȣŰ�� ������ �ش� ����� ����˴ϴ�.\n0. ����\n1. ��� ���Է�\n2. ��Ģ����(+, -, x, %%)\n3. y=0�� �� x�� ��(�������� ��)\n4. x=k�� �� �Լ����� ��ȣ\n5. y=mx+n���� ������ ��ǥ\n6. x������ m��ŭ, y������ n��ŭ �����̵��� �Լ�\n\n");
		scanf("%d", &n);
		switch (n)
		{
		case 0:  // ���α׷� ����
			printf("���α׷��� �����մϴ�.");
			chk = 1; //while�� �����ϱ� ���� �ʿ�
			break;
		case 1:     // ��� ���Է�
			enter_coefficients(coefficient);//��� �Է� �Լ�
			break;
#pragma region
		case 2:   //��Ģ����(+, -, x, %)
			printf("� ������ �Ͻðڽ��ϱ�?(+, -, x, %%)");
			scanf("%c %c", &tmp, &ch);
			printf("�����ϰ� ���� �� ���� �Է��ϼ���.");
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
		case 3:   //y=0�� �� x�� ��(�������� ��)
			cardano_formula(coefficient, 0);// ī���ٳ� �ع� ��� �Լ�(3�� �Լ� ���) 
			break;
		case 4:   //x=k�� �� �Լ����� ��ȣ
			double y1, k;
			printf("k ���� �Է��ϼ���.");
			scanf("%lf", &k);
			y1 = coefficient[0] * pow(k, 3) + coefficient[1] * pow(k, 2) + coefficient[2] * k + coefficient[3];  //�Լ���
			if (y1 > 0)
				printf("y = %.2f > 0, ���\n", y1);
			else if (y1 == 0)
				printf("y = 0\n");
			else
				printf("y = %.2f < 0, ����\n", y1);
			break;
		case 5:   //y=mx+n���� ������ ��ǥ
			double m1, n1;
			printf("m, n�� �Է��ϼ���.");
			scanf("%lf %lf", &m1, &n1);
			double coefficient_mn[] = { coefficient[0], coefficient[1], coefficient[2] - m1, coefficient[3] - n1 };//�����Լ� - �����Լ� = 0 �� ���� �������� ���
			cardano_formula(coefficient_mn, 1);// ī���ٳ� �ع� ��� �Լ�(3�� �Լ� ���) 
			break;
		case 6:   //x������ m��ŭ, y������ n��ŭ �����̵��� �Լ�
			double x, y;
			printf("�󸶸�ŭ �����̵� �ұ��?[����: m n]");
			scanf("%lf %lf", &x, &y);
			double coefficients_mn[] = { coefficient[0], -3 * coefficient[0] * x + coefficient[1], 3 * coefficient[0] * x * x - 2 * coefficient[1] * x + coefficient[2], -coefficient[0] * pow(x, 3) + coefficient[1] * x * x - coefficient[2] * x + coefficient[3] + y };//�����̵��� �Լ� ���
			print_function(coefficients_mn);//3�� �Լ� ��� �Լ�
			break;
		default: //0~6 �̿�
			break;
		}
		if (chk) //���α׷� �����ϱ� ���� �ʿ�
			break;
		printf("\n");
		system("pause");  // '����Ϸ��� �ƹ� Ű�� �����ʽÿ�...' ���
	}
	return 0;
}
void print_function(double arr[])  // 3�� �Լ� ��� �Լ�
{
	if (arr[0] == 1)
		printf("y = x^3 ");
	else if (arr[0] == -1)
		printf("y = -x^3 ");
	else
		printf("y = %.2fx^3 ", arr[0]);  // x^3�� ���
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
		}  // x^2�� ���
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
		}  // x�� ���
	}
	if (arr[3] > 0)
		printf("+ %.2f ", arr[3]);
	else if (arr[3] < 0)
		printf(" %.2f ", arr[3]);  //  ����� ���
}
double* enter_coefficients(double arr[])  // ��� �Է� �Լ�
{
	while (1)
	{
		printf("����� �Է��ϼ���.\n");
		for (int i = 0; i < 4; i++)
			scanf("%lf", &arr[i]);
		if (arr[0] != 0)//3�� �Լ��� ��
		{
			print_function(arr);//3�� �Լ� ��� �Լ�
			return arr;
		}
		else
			printf("a�� 0�� �ƴմϴ�.\n"); //3�� �Լ��� �ƴ� ��
	}
}
void cardano_formula(double arr[], double flag)  // ī���ٳ� �ع� ��� �Լ�(3�� �Լ� ���)
{
	double arr2[] = { arr[1] / arr[0], arr[2] / arr[0], arr[3] / arr[0] }; // ī���ٳ� �ع��� ����ϱ� ���ؼ��� x^3�� ����� 1�̾����.
	double p, q, a, b, x1, t;
	p = arr2[1] - pow(arr2[0], 2) / 3;  //ī������ �ع����� ���Ǵ� p
	q = 2.0 / 27.0 * pow(arr2[0], 3.0) - arr2[0] * arr2[1] / 3 + arr2[2];  //ī������ �ع����� ���Ǵ� q
	printf("// p = %.2f, q = %.2f //\n", p, q);//p, q���
	t = q * q / 4 + p * p * p / 27; // ��Ʈ �ȿ��� ���� ��
	if (t >= 0) // �Ǽ�ü�迡��, ��Ʈ ���� ���� ������ �� ����
	{
		double a1 = -q / 2.0 + sqrt(t), b1 = -q / 2.0 - sqrt(t); // ���������� �ϱ� �� ��
		if (a1 >= 0)
			a = pow(a1, 1 / 3.0);
		else
			a = -pow(-a1, 1 / 3.0);
		if (b1 >= 0)
			b = pow(b1, 1 / 3.0);
		else
			b = -pow(-b1, 1 / 3.0); // ���� 3������ ���� ���� ����, ��� ��� �����ѵ� pow �Լ������� �Ұ���. ���� ����, ��� ��츦 ���� pow �Լ����� ����� ������� �� ������ ��쿡�� �������� ������� -1�� ������.
		printf("// a(����) = %.2f, b(��Ÿ) = %.2f //\n", a, b);//ī������ �ع����� ���Ǵ� ����, ��Ÿ�� a, b�� ��ü
		x1 = a + b - arr2[0] / 3; // ��
		printf("[�Լ��� ��]\nx = %.2f", x1);
		if (flag) // case 5������ y�� ���� �Բ� ����ؾ���.
			printf("  y = %.2f", arr[0] * pow(x1, 3) + arr[1] * x1 * x1 + arr[2] * x1 + arr[3]); // x = x1�϶� y�� ���
		double arr1[] = { arr2[0] + x1, arr2[0] * x1 + arr2[1] + x1 * x1 }; // �ʱ� �������� x-x1���� ������ 2���Լ��� ������� ���� ����� �����ϴ� �迭(�������� ����� �׻� 1�̹Ƿ� ����) - �������� �̿�
		quadratic_function(arr1, flag, arr); // ���� �Լ� ��� �Լ�
	}
	else if (q == 0 && t < 0)  // �Ǽ� ü�迡�� ��Ʈ ���� ���� ������ �� ������, ī������ �ع����� x�� ���� �� a, b(����, ��Ÿ)�� ���ϹǷ� q=0�̶�� t<0�̴��� ���ϸ鼭 ��� �κ��� ���Ǿ� �Ǽ����� ������ �� ����.
	{
		x1 = -arr2[0] / 3;
		printf("[�Լ��� ��]\nx = %.2f", x1);
		if (flag)
			printf("  y = %.2f", arr[0] * pow(x1, 3) + arr[1] * x1 * x1 + arr[2] * x1 + arr[3]); // x = x1�϶� �Լ���
		double arr1[] = { arr2[0] + x1, arr2[0] * x1 + arr2[1] + x1 * x1 }; // 3�� �Լ��� x-x1 ���� ������ 2�� �Լ��� ������ ���� ��� �Է�(��, �������� ����� �׻� 1�̹Ƿ� ����) - �������� �̿�
		quadratic_function(arr1, flag, arr); // ���� �Լ� ��� �Լ�
	}
	else
		printf("�� �� ��� ����� �����ϴ�."); // �� 2���� ��찡 �ƴϸ� ����� ���´�.
}
void quadratic_function(double arr[], double flag, double arr1[]) //���� �Լ� ��� �Լ�
{
	double dis, x2, x3;
	dis = arr[0] * arr[0] - 4.0 * arr[1];  // �־��� 2�� �Լ��� ����� ����ϴ� �Ǻ���
	if (dis >= 0) // �Ǻ����� ���� 0���� ũ�ų� ������ �Ǳ��� ���´�.
	{
		x2 = (-arr[0] + sqrt(dis)) / 2;
		x3 = (-arr[0] - sqrt(dis)) / 2;
		printf("\nx = %.2lf", x2);
		if (flag)
			printf("  y = %.2f", arr1[0] * pow(x2, 3) + arr1[1] * x2 * x2 + arr1[2] * x2 + arr1[3]);
		printf("\nx = %.2lf", x3);
		if (flag)
			printf("  y = %.2f", arr1[0] * pow(x3, 3) + arr1[1] * x3 * x3 + arr1[2] * x3 + arr1[3]);  // case 5������ �Լ����� �Բ� ����ؾ� ��.
	}
	else // �Ǻ����� ���� 0���� ������ ����� ���´�.
		printf("\n������ �� ���� ����Դϴ�.");
}