#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h> //���� ���� ����, �ð� ����**
#include<windows.h>

#define N 25

void gotoxy(int x, int y);
void ConwayTest(int(*arr)[N]);    //�߿��� �Լ�. �� �Լ����� ���� �ܰ��� �迭�� �����.
void printConwayArray(int(*arr)[N], int repeat);    //�ܿ��� ��������� �ϴ� �Ѱ����� �Լ�
void print2DArray(int arr[][N]);      //�׳� 2�����迭 ���



int main() {

	//�迭�� ���� ����
	srand(time(NULL));
	int numArr[N][N]; //ó�� ������

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			numArr[i][j] = rand() % 2;
	}

	//�� �� �ݺ��� ������ �Է¹���
	int repeat;
	printf("\ LIFE GAME\n\n23/3\n\n�� �� �ݺ��Ͻðڽ��ϱ�?  (5 < �ݺ� Ƚ�� < 50) : ");
	scanf("%d", &repeat);
	if (repeat <= 4) {
		printf("������ ���� �ʴ� ���Դϴ�.\n���� ������ �����մϴ�.");
		return 0;
	}
	//ó�� ���
	system("cls");
	print2DArray(numArr);
	system("cls");

	printConwayArray(numArr, repeat);
	Sleep(2000);

	gotoxy(55, 55);
	printf("���� ����");
	return 0;
}

void gotoxy(int x, int y)

{

	COORD pos = { x,y };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

}

void ConwayTest(int(*arr)[N]) {

	int i, j;

	//ó�� �Է¹��� �迭 ����� ����
	int* cpyArr[N][N]; //numArr �ٲ� �� ���� ����� �迭

	//cpyArr(�� �ܰ� ���� ����)�� arr ���� (NGD)
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++) {
			cpyArr[i][j] = arr[i][j];
		}
	}

	//�׽�Ʈ : NGD

	for (i = 0; i < N; i++) {
		for (j = 1; j < N; j++) {

			if (arr[i][j] == 1) //���� ������� ��
			{
				if (i == 0 && j == 0) {   //(0,0)
					if ((int)(cpyArr[0][1] + 1) * ((int)cpyArr[1][0] + 1) * ((int)cpyArr[1][1] + 1) == 8 || (int)(cpyArr[0][1] + 1) * ((int)cpyArr[1][0] + 1) * ((int)cpyArr[1][1] + 1) == 4) {
						arr[i][j] = 1;
					}
					else
						arr[i][j] = 0;
				}
				else if (i == N - 1 && j == 0) {   // (N-1,0)
					if ((int)(cpyArr[N - 2][1] + 1) * ((int)cpyArr[N - 2][0] + 1) * ((int)cpyArr[N - 1][1] + 1) == 8 || (int)(cpyArr[N - 2][1] + 1) * ((int)cpyArr[N - 2][0] + 1) * ((int)cpyArr[N - 1][1] + 1) == 4) {
						arr[i][j] = 1;
					}
					else
						arr[i][j] = 0;
				}
				else if (i == 0 && j == N - 1) {  // (0, N-1)
					if ((int)(cpyArr[N - 2][1] + 1) * ((int)cpyArr[N - 2][0] + 1) * ((int)cpyArr[N - 1][1] + 1) == 8 || (int)(cpyArr[N - 2][1] + 1) * ((int)cpyArr[N - 2][0] + 1) * ((int)cpyArr[N - 1][1] + 1) == 4) {
						arr[i][j] = 1;
					}
					else
						arr[i][j] = 0;
				}
				else if (i == N - 1 && j == N - 1) {   // (N-1, N-1)
					if ((int)(cpyArr[N - 2][N - 1] + 1) * ((int)cpyArr[N - 1][N - 2] + 1) * ((int)cpyArr[N - 2][N - 2] + 1) == 8 || (int)(cpyArr[N - 2][N - 1] + 1) * ((int)cpyArr[N - 1][N - 2] + 1) * ((int)cpyArr[N - 2][N - 2] + 1) == 4) {
						arr[i][j] = 1;
					}
					else
						arr[i][j] = 0;
				}
				else if (i == 0) {   // ���� ��
					if (((int)cpyArr[1][j - 1] + 1) * ((int)cpyArr[1][j] + 1) * ((int)cpyArr[1][j + 1] + 1) * ((int)cpyArr[0][j - 1] + 1) * ((int)cpyArr[0][j + 1] + 1) == 8 || ((int)cpyArr[1][j - 1] + 1) * ((int)cpyArr[1][j] + 1) * ((int)cpyArr[1][j + 1] + 1) * ((int)cpyArr[0][j - 1] + 1) * ((int)cpyArr[0][j + 1] + 1) == 4)
						arr[i][j] = 1;
					else arr[i][j] = 0;
				}
				else if (i == N - 1) {   // �Ʒ��� ��
					if (((int)cpyArr[N - 2][j - 1] + 1) * ((int)cpyArr[N - 2][j] + 1) * ((int)cpyArr[N - 2][j + 1] + 1) * ((int)cpyArr[N - 1][j - 1] + 1) * ((int)cpyArr[N - 1][j + 1] + 1) == 8 || ((int)cpyArr[N - 2][j - 1] + 1) * ((int)cpyArr[N - 2][j] + 1) * ((int)cpyArr[N - 2][j + 1] + 1) * ((int)cpyArr[N - 1][j - 1] + 1) * ((int)cpyArr[N - 1][j + 1] + 1) == 4)
						arr[i][j] = 1;
					else arr[i][j] = 0;
				}
				else if (j == 0) {   // ���� ��
					if (((int)cpyArr[i - 1][0] + 1) * ((int)cpyArr[i + 1][0] + 1) * ((int)cpyArr[i - 1][1] + 1) * ((int)cpyArr[i][1] + 1) * ((int)cpyArr[i + 1][1] + 1) == 8 || ((int)cpyArr[i - 1][0] + 1) * ((int)cpyArr[i + 1][0] + 1) * ((int)cpyArr[i - 1][1] + 1) * ((int)cpyArr[i][1] + 1) * ((int)cpyArr[i + 1][1] + 1) == 4)
						arr[i][j] = 1;
					else arr[i][j] = 0;
				}
				else if (j == N - 1) {  //������ ��
					if (((int)cpyArr[i - 1][N - 1] + 1) * ((int)cpyArr[i + 1][N - 1] + 1) * ((int)cpyArr[i - 1][N - 2] + 1) * ((int)cpyArr[i][N - 2] + 1) * ((int)cpyArr[i + 1][N - 2] + 1) == 8 || ((int)cpyArr[i - 1][N - 1] + 1) * ((int)cpyArr[i + 1][N - 1] + 1) * ((int)cpyArr[i - 1][N - 2] + 1) * ((int)cpyArr[i][N - 2] + 1) * ((int)cpyArr[i + 1][N - 2] + 1) == 4)
						arr[i][j] = 1;
					else arr[i][j] = 0;
				}
				else {   // ������ = ���� ����
					if (((int)cpyArr[i - 1][j - 1] + 1) * ((int)cpyArr[i - 1][j] + 1) * ((int)cpyArr[i - 1][j + 1] + 1) * ((int)cpyArr[i][j - 1] + 1) * ((int)cpyArr[i][j + 1] + 1) * ((int)cpyArr[i + 1][j - 1] + 1) * ((int)cpyArr[i + 1][j] + 1) * ((int)cpyArr[i + 1][j + 1] + 1) == 8 || ((int)cpyArr[i - 1][j - 1] + 1) * ((int)cpyArr[i - 1][j] + 1) * ((int)cpyArr[i - 1][j + 1] + 1) * ((int)cpyArr[i][j - 1] + 1) * ((int)cpyArr[i][j + 1] + 1) * ((int)cpyArr[i + 1][j - 1] + 1) * ((int)cpyArr[i + 1][j] + 1) * ((int)cpyArr[i + 1][j + 1] + 1) == 4)
						arr[i][j] = 1;
					else arr[i][j] = 0;
				}
				break;

			}

			else if (arr[i][j] == 0) //���� �׾����� ��
			{
				if (i == 0 && j == 0) {   //(0,0)
					if ((int)(cpyArr[0][1] + 1) * ((int)cpyArr[1][0] + 1) * ((int)cpyArr[1][1] + 1) == 8) {
						arr[i][j] = 1;
					}
					else
						arr[i][j] = 0;
				}
				else if (i == N - 1 && j == 0) {   // (N-1,0)
					if ((int)(cpyArr[N - 2][1] + 1) * ((int)cpyArr[N - 2][0] + 1) * ((int)cpyArr[N - 1][1] + 1) == 8) {
						arr[i][j] = 1;
					}
					else
						arr[i][j] = 0;
				}
				else if (i == 0 && j == N - 1) {  // (0, N-1)
					if ((int)(cpyArr[N - 2][1] + 1) * ((int)cpyArr[N - 2][0] + 1) * ((int)cpyArr[N - 1][1] + 1) == 8) {
						arr[i][j] = 1;
					}
					else
						arr[i][j] = 0;
				}
				else if (i == N - 1 && j == N - 1) {   // (N-1, N-1)
					if ((int)(cpyArr[N - 2][N - 1] + 1) * ((int)cpyArr[N - 1][N - 2] + 1) * ((int)cpyArr[N - 2][N - 2] + 1) == 8) {
						arr[i][j] = 1;
					}
					else
						arr[i][j] = 0;
				}
				else if (i == 0) {   // ���� ��
					if (((int)cpyArr[1][j - 1] + 1) * ((int)cpyArr[1][j] + 1) * ((int)cpyArr[1][j + 1] + 1) * ((int)cpyArr[0][j - 1] + 1) * ((int)cpyArr[0][j + 1] + 1) == 8)
						arr[i][j] = 1;
					else arr[i][j] = 0;
				}
				else if (i == N - 1) {   // �Ʒ��� ��
					if (((int)cpyArr[N - 2][j - 1] + 1) * ((int)cpyArr[N - 2][j] + 1) * ((int)cpyArr[N - 2][j + 1] + 1) * ((int)cpyArr[N - 1][j - 1] + 1) * ((int)cpyArr[N - 1][j + 1] + 1) == 8)
						arr[i][j] = 1;
					else arr[i][j] = 0;
				}
				else if (j == 0) {   // ���� ��
					if (((int)cpyArr[i - 1][0] + 1) * ((int)cpyArr[i + 1][0] + 1) * ((int)cpyArr[i - 1][1] + 1) * ((int)cpyArr[i][1] + 1) * ((int)cpyArr[i + 1][1] + 1) == 8)
						arr[i][j] = 1;
					else arr[i][j] = 0;
				}
				else if (j == N - 1) {  //������ ��
					if (((int)cpyArr[i - 1][N - 1] + 1) * ((int)cpyArr[i + 1][N - 1] + 1) * ((int)cpyArr[i - 1][N - 2] + 1) * ((int)cpyArr[i][N - 2] + 1) * ((int)cpyArr[i + 1][N - 2] + 1) == 8)
						arr[i][j] = 1;
					else arr[i][j] = 0;
				}
				else {   // ������ = ���� ����
					if (((int)cpyArr[i - 1][j - 1] + 1) * ((int)cpyArr[i - 1][j] + 1) * ((int)cpyArr[i - 1][j + 1] + 1) * ((int)cpyArr[i][j - 1] + 1) * ((int)cpyArr[i][j + 1] + 1) * ((int)cpyArr[i + 1][j - 1] + 1) * ((int)cpyArr[i + 1][j] + 1) * ((int)cpyArr[i + 1][j + 1] + 1) == 8)
						arr[i][j] = 1;
					else arr[i][j] = 0;
				}
				break;
			}

		}
	}

	//�迭 ����ϱ�
	print2DArray(arr);

}

void printConwayArray(int(*arr)[N], int repeat) {
	//repeat�� �ݺ�
	while (repeat >= 1) {

		ConwayTest(*arr);

		//�ð� ����(0.5s)
		Sleep(500);
		repeat--;
	}

}

void print2DArray(int arr[][N]) {
	gotoxy(1, 1);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			gotoxy(2 * i + 1, j + 1);
			printf("%d ", arr[i][j]);    //�����ʹ� ���� �ٷ���. ���⼭ �ϰ��� �ϴ� ���� 2���� �迭�� �Է¹޴� ���̴�.
		}
		printf("\n");
	}
}