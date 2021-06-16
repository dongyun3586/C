#include<stdio.h>
#include<math.h>

#define rangex 100 //���̸� ��� �� �� �ִ� x�� ���� ����(-rangex, rangex)
#define rangey 100 //���̸� ��� �� �� �ִ� y�� ���� ����(-rangey, rangey)

//polynomial�� ��ǥ��� ���� �� ��(x,y)�� �޾Ƽ� �Լ� f(x,y)�� ��ȣ�� �˷��ִ� �Լ��̴�
int polynomial(double arr[][3], double x, double y);

int main() {
	//term�� ���� ������,  sign�� �ε���� ��ȣ��,  lattice�� �ε���� ������ �����ϴ� �������� ������ �����ϴ� �����̴�
	int term, sign = 1, lattice = 0;
	//DISTANCE�� ������ ������ ������ ��Ÿ����. �� ���� �۰��Ҽ��� ���̸� ���Ҷ� ��Ȯ���� ������ ���̴�
	double DISTANCE = 1;
	//surface�� �ε���� ������Ű�� �κ��� ���̸� ����
	double surface;

	//�������� ���� �Է¹ޱ�
	printf("�ε���� ������ ���Ҷ� ���Ǵ� ������ ������ ������?\n������ �������� ������ ��Ȯ�� ��������.");
	scanf("%lf", &DISTANCE);

	//�ε���� ���� ������ �Է¹ޱ�
	printf("f(x,y)>0�� �����̴�\n���� ������?");
	scanf_s("%d", &term);

	//poly�� 10 by 3 ����̴�. 1���� ���� �������, 2���� ���� x�� ��������, 3���� ���� y�� �������� �����Ѵ�
	double poly[10][3] = { 0 };
	double pcoe, px, py;

	//pcoe(���� ���), px(x�� ����), py(y�� ����)�� �޾Ƽ� poly�� �����ϱ�
	for (int i = 0; i < term; i++) {
		printf("%d ��° ���� ����� x, y�� ������?", i + 1);
		scanf_s("%lf %lf %lf", &pcoe, &px, &py);
		poly[i][0] = pcoe;
		poly[i][1] = px;
		poly[i][2] = py;
	}

	//�ε���� ������ x�� y�� ������ �Ѿ ���, ���̰� ��Ȯ�� �������� ������, �� ������ ��ĵ�Ѵ�.
	int rangecheck = -1;
	//x = -rangex�϶� �� �� ���� üũ�ϱ�
	for (int i = -rangey; i <= rangey; i++) {
		rangecheck = polynomial(poly, -rangex, i);
		if (rangecheck == 1) {
			printf("���Ϸ��� �ε���� ������ ����� �� �ִ� ���� ���� �����մϴ�");
			return 0;
		}
	}
	//x = rangex�϶� �� �� ���� üũ�ϱ�
	for (int i = -rangey; i <= rangey; i++) {
		rangecheck = polynomial(poly, rangex, i);
		if (rangecheck == 1) {
			printf("���Ϸ��� �ε���� ������ ����� �� �ִ� ���� ���� �����մϴ�");
			return 0;
		}
	}
	//y = -rangey�϶� �� �� ���� üũ�ϱ�
	for (int i = -rangex; i <= rangex; i++) {
		rangecheck = polynomial(poly, i, -rangey);
		if (rangecheck == 1) {
			printf("���Ϸ��� �ε���� ������ ����� �� �ִ� ���� ���� �����մϴ�");
			return 0;
		}
	}
	//y = rangey�϶� �� �� ���� üũ�ϱ�
	for (int i = -rangex; i <= rangex; i++) {
		rangecheck = polynomial(poly, i, rangey);
		if (rangecheck == 1) {
			printf("���Ϸ��� �ε���� ������ ����� �� �ִ� ���� ���� �����մϴ�");
			return 0;
		}
	}

	/*���� ������ ����ϱ⿡�� ������ ������ ��ȿ�� ���̸� ������ 1�� ������ ��ĵ�Ͽ�
	��ȿ�� ������ �����ϴ� ���簢���� ���Ѵ� : (xminusend, xplusend)*(yminusend, yplusend) */
	int xminusend = -1, xplusend = 1, yminusend = -1, yplusend = 1;
	for (int i = -rangex; i <= rangex; i++) {
		for (int j = -rangey; j <= rangey; j++) { //-rangex <= x <= rangex, -rangey <= y <= rangey ���� ���� ��� �������� ��ĵ�Ѵ�
			if (polynomial(poly, i, j) == 1) {
				//�ش��ϴ� ������ xminusend�� yminusend���� ������, �� ���� ������ ������ �����Ѵ�
				if (i < xminusend)
					xminusend = i;
				if (j < yminusend)
					yminusend = j;
				//�ش��ϴ� ������ xplusend�� yplusend���� ũ��, �� ���� ������ ������ �����Ѵ�
				if (i > xplusend)
					xplusend = i;
				if (j > yplusend)
					yplusend = j;
			}
		}
	}

	//�־��� x�� y�� �������� �ε���� ������Ű�� �������� ���� ����
	for (double x = xminusend - 1; x <= xplusend + 1; x += DISTANCE) {
		for (double y = yminusend - 1; y <= yplusend + 1; y += DISTANCE) {
			if (polynomial(poly, x, y) == 1)
				lattice++;//(x, y) ���� �ε���� �����Ҷ�, �������� ������ ����
		}
	}
	surface = (double)lattice * pow(DISTANCE, 2);//���� lattice�� �̿��Ͽ� �ε���� ���̸� ����ϱ�
	printf("%lf", surface);//surface�� ���

	return 0;
}



int polynomial(double arr[][3], double x, double y) {
	int sign = 1;
	double function = 0;//function�� f(x,y)�� ���� ����
	//�� ���� ���� ����ؼ� function�� ���Ѵ�
	for (int i = 0; i < 3; i++)
		function += arr[i][0] * pow(x, arr[i][1]) * pow(y, arr[i][2]);
	if (function < 0)
		sign = -1;
	return sign;//f(x,y)�� ��ȣ�� �ѱ��
}