#include<stdio.h>
#include<math.h>
#define _CRT_SECURE_NO_WARNINGS
float g = 9.8;
void first();
void second();
void third();
void fourth();

int main()

{
	printf("1. ��ġ������ --> �������\n");
	printf("2. ������� --> ź��������\n");
	printf("3, ��ġ������ --> ź��������\n");  // ���ϰ� ���� ������ ���ϱ� 
	printf("4. ������� --> ��ġ������\n");
	printf("0�� �Է��ϸ� ���α׷��� ����ȴ�.\n");
	int n;
	while (1)
	{
		printf("\n������ ��ȣ�� ���ÿ� : ");
		scanf("%d", &n);
		printf("\n");
		if (n == 1)
		{
			first();
		}
		else if (n == 2)
		{
			second();
		}
		else if (n == 3)
		{
			third();
		}
		else if (n == 4)
		{
			fourth();
		}
		else if (n == 0)  // 0�� �Է¹޾����� ���α׷��� �����.
		{
			printf("***������ ����Ǿ����ϴ�***\n");
			return 0;
		}
		else {
			printf("�߸��� ��ȣ�� ������ϴ�.");  //0,1,2,3,4 �� �ƴ� �ٸ� ������ �����ϸ� �ٽ� �����϶�� ���. 
		}
	}
}
void first() // ��ġ�������� ��������� ��ȯ�ϴ� �Լ� 
{
	float h;
	float vmax;
	float f;
	printf("***��ü�� ������ �������� �������� �ְ�ӵ��� ���غ���***\n\n");
	printf("��ü�� �ְ����� �� m�ΰ�?\n");
	scanf("%f", &h);
	f = 2 * g * h;
	vmax = sqrt(f);
	printf("***��ü�� �ְ�ӵ��� %f m/s�Դϴ�.***\n\n", vmax);

}
void second()  // ��������� ź���������� ��ȯ�ϴ� �Լ�.
{
	float m, v;
	float k;
	float f;
	float x;
	printf("***��ü�� �ӵ� v�� ���ö�� �ε����� ���ö�� �ִ�� ����� ���̸� ���غ���***\n\n");
	printf("��ü�� ���Դ� �� kg�ΰ�?\n");
	scanf("%f", &m);
	printf("ó�� ��ü�� �ӵ� �� m/s �ΰ�?\n");
	scanf("%f", &v);
	printf("���ö�� ź�������?\n");
	scanf("%f", &k);
	f = m * v / k;
	x = sqrt(f);
	printf("***���ö�� �ִ�� ����� ���̴� %f m �Դϴ�.***\n", x);

}
void third() //��ġ�������� ź���������� �ٲ� �Լ� 
{
	float h, m, k;
	float f;
	float x;
	printf("***��ü�� h���̿��� ���������ϰ��� ���ö�� �ε����� ���ö�� �ִ�� ����� ���̸� ���غ���***\n\n");
	printf("��ü�� ���Դ� �� kg�ΰ�?\n");
	scanf("%f", &m);
	printf("��ü�� ���� �� m �ΰ�?\n");
	scanf("%f", &h);
	printf("���ö�� ź�������?\n");
	scanf("%f", &k);
	f = 2 * m * h * g / k;

	x = sqrt(f);
	printf("***���ö�� �ִ�� ����� ���̴� %f m�Դϴ�.***\n", x);

}
void fourth() // ��������� ��ġ�������� ��ȯ�Ǵ� �Լ� 
{
	float v;
	float h;
	printf("***��ü�� ���󿡼� ������������ ������ �ְ����� ���̸� ���غ���***\n\n");
	printf("��ü�� �ӵ��� �� m/s�ΰ�?\n");
	scanf("%f", &v);
	h = v * v / (2 * g);

	printf("***��ü�� �ְ����� ���̴� %f m �Դϴ�.***\n", h);

}