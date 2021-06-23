#include <stdio.h>
#include <stdbool.h>								// bool 변수
#include <stdlib.h>									// rand(), srand() 관련 헤더
#include <time.h>									// time() 관련 헤더

// 자리 행과 열 최소, 최대 개수
#define MIN_ROW			1
#define MIN_COLUMN		1
#define MAX_ROW			100
#define MAX_COLUMN		100

int nRow, nColumn;									// 자리 행과 열 개수
int nMaxStudentCnt;									// 전체 학생수
bool bSeat[MAX_ROW][MAX_COLUMN] = { {0, 0}, };		// 자리배정 유무
int nSeat[MAX_ROW][MAX_COLUMN] = { {0, 0}, };		// 각 자리의 출석번호

int InputStudentSeat();								// 자리수와 학생수 입력받기
int InputFixedSeat();								// 전체자리의 10% 이내에 대해서 고정자리 입력 받기
int CheckFixedSeatStudentNo(int nStudentNo);		// 고정자리의 출석번호 유무 검사(고정자리의 출석번호이면 1, 고정자리의 출석번호가 아니면 0)
int CountDigitsOfNumber(int nNumber);				// 수의 자릿수 구하기
int PrintSeat();									// 자리배정 출력하기

int main() {
	int i;
	int nRowTemp, nColumnTemp;

	int nFixedSeatCnt;				// 고정자리 개수
	bool bFixedStudentNo;			// 고정자리 여부

	printf("*** 1학년 5반 6번 서지운 ***\n");
	printf("*** %d * %d 사이의 자리배정 프로그램 ***\n", MAX_ROW, MAX_COLUMN);

	// 자리수와 학생수 입력받기
	InputStudentSeat();

	// 전체자리의 10% 이내에 대해서 고정자리 지정
	nFixedSeatCnt = InputFixedSeat();

	// 자리배정
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

	// 자리배정 출력하기
	PrintSeat();

	return 0;
}

// 자리수와 학생수 입력받기
int InputStudentSeat()
{
	// 자리수 입력받기
	printf("_ 행 * _ 열의 자리 배정을 원하십니까?\n");

	while (1)
	{
		scanf("%d %d", &nRow, &nColumn);
		if (nRow < MIN_ROW || nRow > MAX_ROW ||
			nColumn < MIN_COLUMN || nColumn > MAX_COLUMN) {
			printf("입력 범위를 벗어났습니다. 다시 입력해주세요.\n");
		}
		else
		{
			break;
		}
	}

	// 학생수 입력받기
	printf("자리배정 받을 학생수를 입력해주세요.\n");

	while (1)
	{
		scanf("%d", &nMaxStudentCnt);
		if (nMaxStudentCnt <= 0 || nMaxStudentCnt > (nRow * nColumn)) {
			printf("학생수가 1명보다 작거나 자리수보다 많습니다. 다시 입력해주세요.\n");
		}
		else
		{
			break;
		}
	}

	return 0;
}

// 전체자리의 10% 이내에 대해서 고정자리 입력 받기
int InputFixedSeat()
{
	int i;
	int nMaxSeatCnt;				// 전체 자리수
	int nMaxFixedSeatCnt;			// 최대 고정자리 수(전체 자리수의 10%)
	int nFixedSeatCnt;				// 원하는 고정자리 수
	int nFixedStudentNo;			// 고정자리에 할당된 출석번호
	int nFixedRow, nFixedColumn;	// 고정자리의 행, 열

	// 전체자리의 10% 이내에 대해서 고정자리 지정
	nFixedSeatCnt = 0;
	nMaxSeatCnt = nRow * nColumn;
	nMaxFixedSeatCnt = (int)(nMaxSeatCnt * 0.1);
	//printf("nMaxSeatCnt = %d, nMaxFixedSeatCnt = %d\n", nMaxSeatCnt, nMaxFixedSeatCnt);

	printf("전체자리의 10%% 이내(최대 %d 자리)에서 고정자리 지정이 가능합니다.\n", nMaxFixedSeatCnt);
	printf("고정자리을 지정하시겠습니까?\n지정하시려면 1, 지정하지 않으시려면 0을 입력해주세요.\n");

	while (1)
	{
		scanf("%d", &nFixedSeatCnt);
		if (nFixedSeatCnt != 0 && nFixedSeatCnt != 1) {
			printf("입력범위를 벗어났습니다. 다시 입력해주세요.\n");
		}
		else
		{
			break;
		}
	}

	// 고정자리 입력받기
	if (nFixedSeatCnt == 1) {
		printf("지정하고 싶은 자리수를 입력해주세요.\n");
		while (1)
		{
			scanf("%d", &nFixedSeatCnt);
			if (nFixedSeatCnt < 0 || nFixedSeatCnt > nMaxFixedSeatCnt || nFixedSeatCnt > nMaxStudentCnt) {
				printf("지정자리수의 범위를 벗어났습니다. 다시 입력해주세요.\n");
			}
			else
			{
				break;
			}
		}

		for (i = 0; i < nFixedSeatCnt; i++) {
			printf("고정자리를 원하는 출석번호를 입력해주세요.\n");
			while (1)
			{
				scanf("%d", &nFixedStudentNo);
				if (nFixedStudentNo <= 0 || nFixedStudentNo > nMaxStudentCnt) {
					printf("출석번호의 범위를 벗어났습니다. 다시 입력해주세요.\n");
				}
				else
				{
					break;
				}
			}

			printf("고정자리를 원하는 행과 열을 입력해주세요.\n");
			while (1)
			{
				scanf("%d %d", &nFixedRow, &nFixedColumn);
				if (nFixedRow < MIN_ROW || nFixedRow > nRow ||
					nFixedColumn < MIN_COLUMN || nFixedColumn > nColumn) {
					printf("원하는 자리의 행과 열을 다시 입력해주세요.\n");
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

// 고정자리의 출석번호 유무 검사(고정자리의 출석번호이면 1, 고정자리의 출석번호가 아니면 0)
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

// 수의 자릿수 구하기
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

// 자리배정 출력하기
int PrintSeat()
{
	int i, j, k;
	int nStudentNoCnt;
	int nNumberCnt;

	nStudentNoCnt = CountDigitsOfNumber(nMaxStudentCnt);	// 학생수의 자리수

	printf("완성된 자리배치표입니다.\n");

	for (i = 0; i < nRow; i++) {
		for (j = 0; j < nColumn; j++) {
			//printf("[%d][%d] = %d ", i + 1, j + 1, nSeat[i][j]);

			// 출석번호 출력하는 부분
			if (nSeat[i][j] == 0) {
				nNumberCnt = 1;			// 자리수가 학생수보다 많아서 비여있는 좌석('0'으로 표시하므로 숫자의 자리수는 1)
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