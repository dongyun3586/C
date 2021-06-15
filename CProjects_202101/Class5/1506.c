#include <stdio.h>
#include <stdbool.h>								// bool ����
#include <stdlib.h>									// rand(), srand() ���� ���
#include <time.h>									// time() ���� ���

// �ڸ� ��� �� �ּ�, �ִ� ����
#define MIN_ROW			1
#define MIN_COLUMN		1
#define MAX_ROW			100
#define MAX_COLUMN		100

int nRow, nColumn;									// �ڸ� ��� �� ����
int nMaxStudentCnt;									// ��ü �л���
bool bSeat[MAX_ROW][MAX_COLUMN] = { {0, 0}, };		// �ڸ����� ����
int nSeat[MAX_ROW][MAX_COLUMN] = { {0, 0}, };		// �� �ڸ��� �⼮��ȣ

int InputStudentSeat();								// �ڸ����� �л��� �Է¹ޱ�
int InputFixedSeat();								// ��ü�ڸ��� 10% �̳��� ���ؼ� �����ڸ� �Է� �ޱ�
int CheckFixedSeatStudentNo(int nStudentNo);		// �����ڸ��� �⼮��ȣ ���� �˻�(�����ڸ��� �⼮��ȣ�̸� 1, �����ڸ��� �⼮��ȣ�� �ƴϸ� 0)
int CountDigitsOfNumber(int nNumber);				// ���� �ڸ��� ���ϱ�
int PrintSeat();									// �ڸ����� ����ϱ�

int main() {
	int i;
	int nRowTemp, nColumnTemp;

	int nFixedSeatCnt;				// �����ڸ� ����
	bool bFixedStudentNo;			// �����ڸ� ����

	printf("*** 1�г� 5�� 6�� ������ ***\n");
	printf("*** %d * %d ������ �ڸ����� ���α׷� ***\n", MAX_ROW, MAX_COLUMN);

	// �ڸ����� �л��� �Է¹ޱ�
	InputStudentSeat();

	// ��ü�ڸ��� 10% �̳��� ���ؼ� �����ڸ� ����
	nFixedSeatCnt = InputFixedSeat();

	// �ڸ�����
	srand((unsigned)time(NULL));

	for (i = 0; i < nMaxStudentCnt; i++) {

		bFixedStudentNo = false;
		if (nFixedSeatCnt > 0) {
			if (CheckFixedSeatStudentNo(i + 1)) {
				bFixedStudentNo = true;
			}
		}

		if (!bFixedStudentNo) {
			while (1)
			{
				nRowTemp = rand() % nRow;
				nColumnTemp = rand() % nColumn;

				if (!bSeat[nRowTemp][nColumnTemp])
				{
					bSeat[nRowTemp][nColumnTemp] = true;
					nSeat[nRowTemp][nColumnTemp] = i + 1;
					break;
				}
			}
		}
	}

	// �ڸ����� ����ϱ�
	PrintSeat();

	return 0;
}

// �ڸ����� �л��� �Է¹ޱ�
int InputStudentSeat()
{
	// �ڸ��� �Է¹ޱ�
	printf("_ �� * _ ���� �ڸ� ������ ���Ͻʴϱ�?\n");

	while (1)
	{
		scanf("%d %d", &nRow, &nColumn);
		if (nRow < MIN_ROW || nRow > MAX_ROW ||
			nColumn < MIN_COLUMN || nColumn > MAX_COLUMN) {
			printf("�Է� ������ ������ϴ�. �ٽ� �Է����ּ���.\n");
		}
		else
		{
			break;
		}
	}

	// �л��� �Է¹ޱ�
	printf("�ڸ����� ���� �л����� �Է����ּ���.\n");

	while (1)
	{
		scanf("%d", &nMaxStudentCnt);
		if (nMaxStudentCnt <= 0 || nMaxStudentCnt > (nRow * nColumn)) {
			printf("�л����� 1���� �۰ų� �ڸ������� �����ϴ�. �ٽ� �Է����ּ���.\n");
		}
		else
		{
			break;
		}
	}

	return 0;
}

// ��ü�ڸ��� 10% �̳��� ���ؼ� �����ڸ� �Է� �ޱ�
int InputFixedSeat()
{
	int i;
	int nMaxSeatCnt;				// ��ü �ڸ���
	int nMaxFixedSeatCnt;			// �ִ� �����ڸ� ��(��ü �ڸ����� 10%)
	int nFixedSeatCnt;				// ���ϴ� �����ڸ� ��
	int nFixedStudentNo;			// �����ڸ��� �Ҵ�� �⼮��ȣ
	int nFixedRow, nFixedColumn;	// �����ڸ��� ��, ��

	// ��ü�ڸ��� 10% �̳��� ���ؼ� �����ڸ� ����
	nFixedSeatCnt = 0;
	nMaxSeatCnt = nRow * nColumn;
	nMaxFixedSeatCnt = (int)(nMaxSeatCnt * 0.1);
	//printf("nMaxSeatCnt = %d, nMaxFixedSeatCnt = %d\n", nMaxSeatCnt, nMaxFixedSeatCnt);

	printf("��ü�ڸ��� 10%% �̳�(�ִ� %d �ڸ�)���� �����ڸ� ������ �����մϴ�.\n", nMaxFixedSeatCnt);
	printf("�����ڸ��� �����Ͻðڽ��ϱ�?\n�����Ͻ÷��� 1, �������� �����÷��� 0�� �Է����ּ���.\n");

	while (1)
	{
		scanf("%d", &nFixedSeatCnt);
		if (nFixedSeatCnt != 0 && nFixedSeatCnt != 1) {
			printf("�Է¹����� ������ϴ�. �ٽ� �Է����ּ���.\n");
		}
		else
		{
			break;
		}
	}

	// �����ڸ� �Է¹ޱ�
	if (nFixedSeatCnt == 1) {
		printf("�����ϰ� ���� �ڸ����� �Է����ּ���.\n");
		while (1)
		{
			scanf("%d", &nFixedSeatCnt);
			if (nFixedSeatCnt < 0 || nFixedSeatCnt > nMaxFixedSeatCnt || nFixedSeatCnt > nMaxStudentCnt) {
				printf("�����ڸ����� ������ ������ϴ�. �ٽ� �Է����ּ���.\n");
			}
			else
			{
				break;
			}
		}

		for (i = 0; i < nFixedSeatCnt; i++) {
			printf("�����ڸ��� ���ϴ� �⼮��ȣ�� �Է����ּ���.\n");
			while (1)
			{
				scanf("%d", &nFixedStudentNo);
				if (nFixedStudentNo <= 0 || nFixedStudentNo > nMaxStudentCnt) {
					printf("�⼮��ȣ�� ������ ������ϴ�. �ٽ� �Է����ּ���.\n");
				}
				else
				{
					break;
				}
			}

			printf("�����ڸ��� ���ϴ� ��� ���� �Է����ּ���.\n");
			while (1)
			{
				scanf("%d %d", &nFixedRow, &nFixedColumn);
				if (nFixedRow < MIN_ROW || nFixedRow > nRow ||
					nFixedColumn < MIN_COLUMN || nFixedColumn > nColumn) {
					printf("���ϴ� �ڸ��� ��� ���� �ٽ� �Է����ּ���.\n");
				}
				else
				{
					break;
				}
			}

			bSeat[nFixedRow - 1][nFixedColumn - 1] = true;
			nSeat[nFixedRow - 1][nFixedColumn - 1] = nFixedStudentNo;
		}
	}

	return nFixedSeatCnt;
}

// �����ڸ��� �⼮��ȣ ���� �˻�(�����ڸ��� �⼮��ȣ�̸� 1, �����ڸ��� �⼮��ȣ�� �ƴϸ� 0)
int CheckFixedSeatStudentNo(int nStudentNo)
{
	int i, j;

	for (i = 0; i < nRow; i++) {
		for (j = 0; j < nColumn; j++) {
			if (bSeat[i][j] && (nSeat[i][j] == nStudentNo)) {
				return 1;
			}
		}
	}

	return 0;
}

// ���� �ڸ��� ���ϱ�
int CountDigitsOfNumber(int nNumber)
{
	int nCount;
	int nLength;

	nLength = 0;
	nCount = 1;

	while (1)
	{
		if (nNumber / nCount >= 1)
		{
			nLength++;
			nCount *= 10;
		}
		else
		{
			break;
		}
	}

	return nLength;
}

// �ڸ����� ����ϱ�
int PrintSeat()
{
	int i, j, k;
	int nStudentNoCnt;
	int nNumberCnt;

	nStudentNoCnt = CountDigitsOfNumber(nMaxStudentCnt);	// �л����� �ڸ���

	printf("�ϼ��� �ڸ���ġǥ�Դϴ�.\n");

	for (i = 0; i < nRow; i++) {
		for (j = 0; j < nColumn; j++) {
			//printf("[%d][%d] = %d ", i + 1, j + 1, nSeat[i][j]);

			// �⼮��ȣ ����ϴ� �κ�
			if (nSeat[i][j] == 0) {
				nNumberCnt = 1;			// �ڸ����� �л������� ���Ƽ� ���ִ� �¼�('0'���� ǥ���ϹǷ� ������ �ڸ����� 1)
			}
			else {
				nNumberCnt = CountDigitsOfNumber(nSeat[i][j]);
			}

			for (k = 0; k < nStudentNoCnt - nNumberCnt; k++) {
				printf(" ");
			}
			printf("%d ", nSeat[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	return 0;
}