#include <stdio.h>
#include <time.h>
#include <Windows.h>
//gotoxy �Լ��� ����ϱ� ���� �˻��� ���� ã�� �������

void gotoxy(int x, int y);
//�ڸ�ǥ�� ����� �� ��ȣ�� ���ڰ� ��µ� ��ġ�� �����ϴ� �Լ�

void printSeat(int row, int column);
//��� ��, �л� ���� �Է¹޾� ������ �迭�� �л����� ��ȣ�� ���� �����ϰ� �� ��ȣ�� ���� ����ϴ� �Լ�

int main(void) {
	srand(time(NULL)); //�л����� �ڸ��� ���� �� ������ ���
	int row, column, student;
	// ��, ��, �л����� ���� ��Ÿ���� ����

	printf("*** 1210 ������ ����������Ʈ ������***\n\n\n");
	printf("�ڸ���ġ ���α׷�\n\n");

	printf("���� ���� �Է��ϼ��� : ");
	scanf("%d", &row);//�� �Է�

	printf("���� ���� �Է��ϼ��� : ");
	scanf("%d", &column);//�� �Է�

	printf("�л� ���� �Է��ϼ��� : ");
	scanf("%d", &student);//�л��� �Է�


	printSeat(row, column, student);  // �Է¹��� ���� ���� �ڸ��� ��ġ�ϰ� �ڸ�ǥ�� ���


	return 0;  //main�Լ� ����
}

void gotoxy(int x, int y)  // �迭�� ����ϴ� ����� �˻��ϴ� ã�� �Լ��Դϴ�.

{

	COORD pos = { x,y };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

}

void printSeat(int row, int column, int student)
{

	// ������ �迭 ����� �ʱ�ȭ
	int sit[20][20] = { 0 };

	// �迭�� ������� �л����� ��ȣ�� ä���(�л������� �ڸ����� ������ 0�� ä������)

	for (int i = 0; i < column; i++) //�� �࿡ ��� ��ȣ�� ä������ ���� ���� �Ѿ��
	{

		for (int j = 0; j < row; j++) //�� �࿡ ���ؼ� ���� ���̸�ŭ �ݺ� 
		{

			while (j + row * i < student) //�ڸ��� ������� �л����� ��ȣ�� ä���
			{
				sit[j][i] = j + row * i + 1;
				break;
			}

		}

	}
	int a, b, temp = 0; // ��� ���� ���� a, b�� �� ��ġ�� �迭�� ����� ���� �ٲ� �� ����ϴ� ���� temp

	for (int i = 0; i < column; i++) //�࿡ ���� �ݺ��� ������ ���� �Ѿ��.
	{
		for (int j = 0; j < row; j++) //�� �࿡ ���ؼ� ���� ���̸�ŭ
		{
			a = rand() % row;
			b = rand() % column;  //������ ��� ���� ��´�

			temp = sit[j][i];  //sit[i][j]�� ���� temp�� ����

			sit[j][i] = sit[a][b];
			sit[a][b] = temp;  //sit[i][j]�� sit[a][b]�� ���� �ٲ۴�
		}
	}



	gotoxy(2 * column + 7, 8);//�ڸ�ǥ�� ����� ��ġ�� ����� �����ϰ� ���
	printf("<�ڸ�ǥ>");


	for (int i = 1; i <= column; i++) //�࿡ ���� for���� ������ ���� ���� �Ѿ
	{
		for (int j = 1; j <= row; j++) // ���� ���̸�ŭ �ݺ�
		{
			gotoxy(j * 4 + 6, i * 2 + 8);
			printf("%3d", sit[j - 1][i - 1]);  //�� ��� ���� ���� ��ġ�� �����ϰ� ���
		}
	}


}