#include<stdio.h>

int mbti(int n);	//mbti���� ���� �Լ�
int survey1(int n);	//�������� E,I ���� �Լ� 
int survey2(int n);	//�������� S,N ���� �Լ� 
int survey3(int n);	//�������� T,F ���� �Լ� 
int survey4(int n);	//�������� P,J ���� �Լ� 
int scank(); //���� ���� ���� �Է½� ������ �߰� ���ִ� �Լ�
int dep();	//���� ���� ���� �Է½� ������ �߰� ���ִ� �Լ�	


int main()
{
	int g;

	g = 0;
	int n = 0;
	int mbti_1 = mbti(n);
	printf("�ٸ� ����� mbti�� �˻� �Ͻðڽ��ϱ�? (�����÷��� 1�� ���� �ּ���) > ");

	scanf("%d", &g);



	while (g != 1) {
		int g;
		g = 0;
		int n = 0;
		int mbti_1 = mbti(n);
		printf("�ٸ� ����� mbti�� �˻� �Ͻðڽ��ϱ�? (�����÷��� 1�� ���� �ּ���) > ");

		scanf("%d", &g);

		if (g == 1) {
			return 0;
		}
	}
}


int mbti(int n) {
	//���α׷� �Ұ�
	printf("\n����� ���������� �˻����ִ� ���α׷� �Դϴ�.\n");
	printf("�� ���׿� ���� ���� �Է��ϰ� Enter�� �����ּ���.\n");
	printf("�� ������ ���� ���� ���ڷθ� �Է����ּ���\n");
	printf("1:�����׷����ʴ� 2:�׷����ʴ� 3:�����̴� 4:�׷��� 5:�ſ�׷���\n\n");

	//���� ��� ���
	int ser1 = survey1(n);
	int ser2 = survey2(n);
	int ser3 = survey3(n);
	int ser4 = survey4(n);
	printf("\n����� mbti������ ");
	if (ser1 > 12.5)
		printf("I");
	else
		printf("E");

	if (ser2 > 12.5)
		printf("S");
	else
		printf("N");

	if (ser3 > 12.5)
		printf("T");
	else
		printf("F");

	if (ser4 > 12.5)
		printf("P");
	else
		printf("J");

	printf(" �Դϴ�.\n\n");
}
int scank()
{
	int n = 0;
	scanf("%d", &n);
	if (n > 5 || n < 1)
	{
		printf("[error] 1~5�� �߿����� �������ּ���. > ");

		return 0;
	}
	else
		return n;
}

int dep()
{
	int nfromscan = scank();
	if (nfromscan == 0)
		dep();
	else
		return nfromscan;
}


int survey1(int n)
{
	//���ڰ� 12.5���� Ŭ ��� I
	int sum = 0;
	printf("���� ���� ��ȭ�� ���� �������� �ʴ´� > ");
	sum += dep();
	printf("���� �ָ�޴� �Ͽ��� ������ ���� > ");
	sum += dep();
	printf("����ִ� å�̳� ���� ������ �米 ������ �� ���� > ");
	sum += dep();
	printf("�濡 ����� ���� �� ���, ���� �߾Ӻ��ٴ� ���� �����̿� �ڸ��մϴ�. > ");
	sum += dep();
	printf("�ٸ�����鿡�� �ڽ��� �Ұ��ϴ� ���� ����� �մϴ�. > ");
	sum += dep();
	return sum;

}

int survey2(int n)
{
	//���ڰ� 12.5���� Ŭ��� S
	int sum = 0;
	printf("\n������ â�����̱⺸�� �������� ����̶�� �����մϴ�. > ");
	sum += dep();
	printf("����� ���̵�� ������ ����ϴ� ���� �����ϴ�. > ");
	sum += dep();;
	printf("���� ���� ����� ��ǿ� ������ �δ� ������ �ֽ��ϴ�. > ");
	sum += dep();
	printf("�ڽ��� �ൿ�� �ٸ� ����鿡�� ��� ������ �ִ� ���� ���� ���� �������� �ʽ��ϴ�. > ");
	sum += dep();
	printf("�ٸ� ������� ������ �ൿ�� ������ �ִ� ���� ������� �ʽ��ϴ�. > ");
	sum += dep();
}

int survey3(int n)
{
	//���ڰ� 12.5���� Ŭ��� T
	int sum = 0;
	printf("\n�߿��� ������ ������ �� �� �Ϲ������� �������� ���� �߿��մϴ�. > ");
	sum += dep();
	printf("���￡�� �̱�� ���� ������ �������� �ʵ��� �ϴ� �ͺ��� �߿��մϴ�. > ");
	sum += dep();
	printf("��� �� ������� �ΰ��� �������� ���� ������ �� �߿���ؾ� �մϴ�. > ");
	sum += dep();
	printf("���� �ٸ� ������� ������ �����ϱⰡ ��ƽ��ϴ�. > ");
	sum += dep();
	printf("����� ������ ȭ���� ���� ���� �����ϴ�. > ");
	sum += dep();
}
int survey4(int n)
{
	//���ڰ� 12.5���� Ŭ��� P
	int sum = 0;
	printf("\n���Ǳ�� �̸� ��ȹ�ϱ� ���ٴ� ���������� �����Դϴ�. > ");
	sum += dep();
	printf("��ü���� ��ȹ�� ���� �ð��� �����⺸�ٴ� �ټ� ���������� �����Դϴ�. > ");
	sum += dep();
	printf("���� ��Ÿ���� ü�����̰� �������̶�⺸�ٴ� �׶��׶� ���Ƽ� ó���ϴ� ���Դϴ�. > ");
	sum += dep();
	printf("���� ������ ���ڸ��� ���� �ʽ��ϴ�. > ");
	sum += dep();
	printf("�ð��� ������ ������ ���� �̿�� ������ �ֽ��ϴ�. > ");
	sum += dep();
}