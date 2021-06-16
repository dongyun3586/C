#include<stdio.h>

int molecule_check(char arr[], char a1);
int centercheck(int at1, int at2, int n1, int n2);
int bondcheck(int center);
int VSEPR(int n1, int n2, int a1, int a2);

int main()
{
	int n1, n2;
	char a1[3], a2[3];

	char arr[][3] = { "H","He","Li",
		"Be","B","C","N","O","F","Ne",
		"Na","Mg","Al","Si","P","S","Cl","Ar",
		"K","Ca","Sc","Ti","V","Cr","Mn","Fe","Co","Ni","Cu","Zn","Ga","Ge","As","Se","Br","Kr",
		"Rb","Sr","Y","Zr","Nb","Mo","Tc","Ru","Rh","Pd","Ag","Cd","In","Sn","Sb","Te","I","Xe" };

	printf("�˰����ϴ� ���ڽ��� �Է��Ͻÿ�(�� ������ ���ڷ� �̷���� ����)\n");
	printf("���� ���� ���� ����(ex:H 1 O 2ó�� �Է��Ͻÿ�):");
	scanf("%s %d %s %d", &a1, &n1, &a2, &n2);

	int at1 = molecule_check(arr, a1);
	int at2 = molecule_check(arr, a2);
	int centa = centercheck(at1, at2, n1, n2);
	int centarms = bondcheck(centa);

	printf("%s%d%s%d�� VSEPR������ ������ �����ϴ�\n\n", a1, n1, a2, n2);

	int VSEPR(centarms, n1, centa);
}

int molecule_check(char arr[], char atom)
{
	int a;
	for (int i = 0; i < 54; i++)
	{
		if (arr[i] == atom)
		{
			a = i++;
		}
	}
	return a;
}

int centercheck(int at1, int at2, int n1, int n2)
{
	if (n1 > n2)
		return at2;

	else if (n1 == n2)
	{
		if (at1 > at2)
			return at1;
		return at2;
	}

	else if (n1 < n2)
		return at1;
}

int bondcheck(int center)
{
	int num;

	if (center <= 2 && center != 2)
	{
		{
			num = center;
		}
		return num;
	}

	else if (center >= 3 && center % 10 > 4 && center % 10 != 8)
	{
		{
			num = 8 - center % 10;
		}
		return num;
	}

	return center % 10;
}

int VSEPR(int arm, int n1, int n)
{
	if ((n % 10 - arm * 2) / 2 + n1 == 4 && n % 10 - arm == 0)
		printf("���� ����: ���ü��");

	else if ((n % 10 - arm * 2) / 2 + n1 == 4 && n % 10 - arm == 2)
		printf("���� ����: ������");

	else if ((n % 10 - arm * 2) / 2 + n1 == 3 && n % 10 - arm == 0)
		printf("���� ����: ���ﰢ��");

	else if ((n % 10 - arm * 2) / 2 + n1 == 4 && n % 10 - arm == 2)
		printf("���� ����: ������");

	else if ((n % 10 - arm * 2) / 2 + n1 == 4 && n % 10 - arm == 1)
		printf("���� ����: �ﰢ�Ƕ�̵���");
}

