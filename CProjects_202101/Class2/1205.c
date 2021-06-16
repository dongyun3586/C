#include<stdio.h>
#include <windows.h>
#include<math.h>

float timef(float d, float v, float c, float a, float b);

float ABS(float n) {
	if (n > 0)
		return n;
	else
		n = -n;
	return n;
}

void SetConsoleView()
{
	system("mode con:cols=100 lines=25");

}

void GotoXY(int x, int y)
{
	COORD Pos;
	Pos.X = 2 * x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

int main() {
	SetConsoleView();

	GotoXY(15, 2);
	printf("*** 1�г� 2�� 5�� ����� ***");

	GotoXY(15, 3);
	printf("�� ���α׷��� ź���浹�� ������ ���Դϴ�.");

	GotoXY(15, 4);
	printf("�ð��� �������� ª���ϴ�.������ �ּ���.");

	GotoXY(15, 5);
	printf("�ʱ� ������ �Է��Ͽ� �ֽʽÿ�.\n");

	float a, b;//�� ��ü�� ����
	float v = 0;//��ü�� �ӵ�
	float c = 0;//������ ��ü�� �ʱ� �ӵ�
	int cnt = 0;//�浹 Ƚ��
	float d = 0;//��ü ������ �Ÿ�

	GotoXY(15, 6);
	printf("�������� �ٻ簪�� �����÷���");

	GotoXY(15, 7);
	printf("10�� ¦������ ��� ������ �����ϼ���");

	GotoXY(15, 8);
	printf("��õ ��: 100 1 5 4");

	GotoXY(15, 9);
	printf("���� ���ſ� ��ü�� ����:");

	scanf("%f", &a);
	GotoXY(15, 10);
	printf("������ ������ ��ü�� ����:");

	scanf("%f", &b);
	GotoXY(15, 11);
	printf("���� ���ſ� ��ü�� �ӵ�:");

	scanf("%f", &v);
	GotoXY(15, 12);
	printf("���� ������ ��ü ������ �Ÿ�");

	scanf("%f", &d);
	if (a <= b) {
		printf("�Է��� �߸��Ǿ����ϴ�.");
	}
	else {
		while (1) {
			v = v * (float)((a - b) / (a + b)) + c * (float)((2 * b) / (a + b));//ź���浹�� ���ſ� ��ü�� �ӵ�
			c = c * (float)((b - a) / (a + b)) + v * (float)((2 * a) / (a + b));//������ ��ü�� �ӵ�
			if (c > 0) {
				c *= -1;
				cnt++;
			}
			cnt++;
			if (ABS(v) > ABS(c)) {
				break;
			}
		}
		GotoXY(15, 13);
		printf("�浹 Ƚ���� %d�� �Դϴ�", cnt);
		GotoXY(15, 14);
		printf("�ð��� %f�� ����Ͽ����ϴ�\n\n\n\n\n", timef(d, v, c, a, b));
	}
	return 0;
}

float timef(float d, float v, float c, float a, float b) {

	float time = 0;

	float k = 0;

	while (v > 0) {

		v = v * (float)((a - b) / (a + b)) + c * (float)((2 * b) / (a + b));//�浹 �ӵ� ��

		c = c * (float)((b - a) / (a + b)) + v * (float)((2 * a) / (a + b));//�浹 �ӵ� ��

		if (c < 0) {
			k = -c;//���� ƨ��� �ݴ� �������� ��ϴ� �Ϳ� ���� ����
		}

		else {
			k = c;//�׷��� �ʰ� �����ϴ� ��쿡 ���� ����
		}
		time += (float)d / (k + v);//�ð��� �Ÿ��� �ӵ��� ���� �Ͱ� ���ٶ�� ����� �� �̿��� ����.

		d *= (float)k / (k + v);//�Ÿ��� �ӵ��� ����Ͽ� ��� �����ϴ� ��,�浹 �ð� ������ �پ�꿡 ���� �Ÿ��� ����.
	}
	while (ABS(v) < ABS(c)) {

		v = v * (float)((a - b) / (a + b)) + c * (float)((2 * b) / (a + b));//���� �ӵ��� ���� 1

		c = c * (float)((b - a) / (a + b)) + v * (float)((2 * a) / (a + c));//���� �ӵ��� ���� 2

		if (c < 0) {
			k = -c;
		}
		else {
			k = c;
		}
		time += (float)d / (k - v);
		d *= (float)k / (k - v);
	}
	return time;
}