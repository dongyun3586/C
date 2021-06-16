#include <stdio.h>

void time() //�ð��� ������ ����ϴ� �Լ�
{
	int t;
	printf("�ð���: \n");
	printf("1. 08:40\n2. 11:20\n3. 14:10\n4. 15:30\n");
	printf("������ �ð��� �������ּ���: ");
}

void num() // �ο��� ������ ����ϴ� �Լ�
{
	int n;
	printf("*4�� �̻� ���� �� 1�δ� 10% ���� ��*\n�� ��� 10000��\n");
	printf("�����Ͻ� �ο����� �������ּ���: ");
}

void seat() // �¼� ������ ����ϴ� �Լ�
{
	int arr[4][5] = { 0, }, k = 0;
	printf("�¼�: \n");
	// �¼��� ���簢�� ������� ��� 
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			arr[i][j] = k;
			printf("%3d", arr[i][j]);
			k++;
		}
		printf("\n");
	}
	printf("���ϴ� �¼��� �����ϼ���: ");

}

void printTime(int t) // ������ ������ ������ �� �ð��븦 ����ϱ� ���� �Լ�
{
	if (t == 1)
		printf("08:40");
	else if (t == 2)
		printf("11:20");
	else if (t == 3)
		printf("14:10");
	else
		printf("15:30");
}

int price(int n) // �ݾ��� ����ϴ� �Լ�
{
	int p;
	if (n >= 4)
		p = 10000 * 0.9 * n; // 4�� �̻� �����ϸ� 10% ���εǹǷ� 0.9�� ����
	else
		p = 10000 * n;
	return p;
}

void movie(int n) // ��ȭ ������ ����ϴ� �Լ�
{
	if (n == 1)
		printf("������ 3\n");
	else if (n == 2)
		printf("ũ�翤��\n");
	else if (n == 3)
		printf("�г��� ����: �� ��Ƽ����Ʈ\n");
	else if (n == 4)
		printf("����������\n");
	else
		printf("������: �͸��� Į��\n");
}


int main()
{
	int a; // ù ȭ�鿡�� ��ȭ ������ �� �Է¹޴� ����
	int t, n, s, pay; // �ð�, �ο���, �¼���ȣ, �ݾ� ����
	int A[20] = { 0, }, B[20] = { 0, }, C[20] = { 0, }, D[20] = { 0, }, E[20] = { 0, };
	int countA[20] = { 0, }, countB[20] = { 0, }, countC[20] = { 0, }, countD[20] = { 0, }, countE[20] = { 0, }; // �¼� ���ý� ��ħ ���θ� Ȯ���ϱ� ���� �� ��ȭ ���� �迭�� ����� �� ������ ���� �迭 ����.
	while (1) {
		printf("***��ȭ�������α׷�***\n\n");
		printf("�� ���� ��ȭ\n");
		printf("1. ������3\n");
		printf("2. ũ�翤��\n");
		printf("3. �г��� ����: �� ��Ƽ����Ʈ\n");
		printf("4. ����������\n");
		printf("5. ������: �͸��� Į��\n");
		printf("6. ����\n");
		printf("���ϴ� ��ȭ�� �����ϼ���: ");
		scanf("%d", &a);
		if (a == 6)
			break; // ���� ������ while���� ���������� ���α׷� �����
		movie(a);
		time();
		scanf("%d", &t);
		num();
		scanf("%d", &n);
		switch (a)
		{
		case 1:
			seat();
			for (int i = 0; i < n; i++)
			{
				scanf("%d", &A[i]); // �迭�� �¼� ��ȣ �Է¹���
				if (countA[A[i]] == 1) // ���� ���� �迭�� 1�� ������ ���ŵ� �¼��̹Ƿ� �ٸ� �¼� ���� �Է� ����
				{
					printf("%d���� �̹� ���ŵ� �¼��Դϴ� �ٸ� �¼��� �������ּ���.\n", A[i]);
					scanf("%d", &A[i]);
				}

				countA[A[i]]++; // �Էµ� �¼� ��ȣ�� ���ŵ� �¼��� �� ���̹Ƿ� �����ϱ� ���� 1�� ������
			}
			movie(a);
			printTime(t);
			printf("  %d  ", n);
			for (int i = 0; i < n; i++)
				printf("%d ", A[i]);
			break;
		case 2:
			seat();
			for (int i = 0; i < n; i++)
			{
				scanf("%d", &B[i]);
				if (countB[B[i]] == 1)
				{
					printf("%d���� �̹� ���ŵ� �¼��Դϴ� �ٸ� �¼��� �������ּ���.\n", B[i]);
					scanf("%d", &B[i]);
				}

				countB[B[i]]++;
			}
			movie(a);
			printTime(t);
			printf("  %d  ", n);
			for (int i = 0; i < n; i++)
				printf("%d ", B[i]);
			break;
		case 3:
			seat();
			for (int i = 0; i < n; i++)
			{
				scanf("%d", &C[i]);
				if (countC[C[i]] == 1)
				{
					printf("%d���� �̹� ���ŵ� �¼��Դϴ� �ٸ� �¼��� �������ּ���.\n", C[i]);
					scanf("%d", &C[i]);
				}

				countC[C[i]]++;
			}
			movie(a);
			printTime(t);
			printf("  %d  ", n);
			for (int i = 0; i < n; i++)
				printf("%d ", C[i]);
			break;
		case 4:
			seat();
			for (int i = 0; i < n; i++)
			{
				scanf("%d", &D[i]);
				if (countD[D[i]] == 1)
				{
					printf("%d���� �̹� ���ŵ� �¼��Դϴ� �ٸ� �¼��� �������ּ���.\n", D[i]);
					scanf("%d", &D[i]);
				}

				countD[D[i]]++;
			}
			movie(a);
			printTime(t);
			printf("  %d  ", n);
			for (int i = 0; i < n; i++)
				printf("%d ", D[i]);
			break;
		case 5:
			seat();
			for (int i = 0; i < n; i++)
			{
				scanf("%d", &E[i]);
				if (countE[E[i]] == 1)
				{
					printf("%d���� �̹� ���ŵ� �¼��Դϴ� �ٸ� �¼��� �������ּ���.\n", E[i]);
					scanf("%d", &E[i]);
				}

				countE[E[i]]++;
			}
			movie(a);
			printTime(t);
			printf("  %d  ", n);
			for (int i = 0; i < n; i++)
				printf("%d ", E[i]);
			break;
		}
		printf("����:%d\n", price(n));
		printf("�ش� �ݾ��� �Է����ּ���: ");
		scanf("%d", &pay);
		if (pay == price(n)) // ���� �ݾװ� �Էµ� �ݾ��� ������ ���� �Ϸ�
			printf("\n***���Ű� �Ϸ�Ǿ����ϴ�***\n\n");
		if (pay<price(n) || pay>price(n))
		{
			while (pay != price(n)) // �Էµ� �ݾװ� ���� �ݾ��� ������ ������ �ٽ� �Է� ����
			{
				printf("�ݾ��� ���� �ʽ��ϴ�.�ٽ� �Է����ּ���:");
				scanf("%d", &pay);
			}
			printf("\n***���Ű� �Ϸ�Ǿ����ϴ�***");
		}
	}
}
