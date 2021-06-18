#include<stdio.h>
#include<stdlib.h>  //rand(), srand() 
#include<time.h>  // time()
#include<windows.h>  // COORD, SetConsoleCursorPosition, SetConsoleTextAttribute

void gotoxy(int x, int y);  // ��ǥ �̵�
void color(int color_number);  // ���� ���� �ٲٱ�

int main() {

	int length; //��ٸ� ������ ��

	int map[10][100] = {  //��ٸ� ������ 10, ���� �ִ� 100���� ����
	{0},
	{0}
	};

	int row = sizeof(map) / sizeof(map[0]); //��ٸ� ���� �� 

	srand(time(NULL));

	printf("��� ���� �Է��ϼ���: ");
	scanf("%d", &length);

	// ��ٸ� ��ȣ ���
	for (int i = 1; i <= length; i++) {

		if (i <= 10)
			printf("   %d", i);

		else if (i >= 10)  //������� 10�� �þ�� ��ĭ�� ���ܼ� �� �ٷ� ���� ���ڰ� �ֵ��� ��
			printf("  %d", i);
		// 100���ʹ� �迭�� �Ѿ�� ������ 100���̼� ��ٸ�Ÿ�⸦ �� �ϵ� ���� �� ���ƿ�
	}
	printf("\n");

	// ��ٸ� �����
	for (int i = 1; i < row - 1; i++) {  //�� ù �����ٰ� ������ �������� 1�� ������ �ʵ��� ��

		for (int j = 1; j < length; j++) {
			map[i][j] = rand() % 2;

			if (map[i][j - 1] == 1 && map[i][j] == 1)  //�������� �ð� ������ �ʵ��� ��
				map[i][j] = 0;  // 1�� 0���� �ٲ���
		}
	}

	// ��ٸ� ���
	for (int i = 0; i < row; i++) {

		for (int j = 0; j < length; j++) {

			if (map[i][j] == 1)
				printf("%c%c%c%c", 6, 6, 6, 23); //�ƽ�Ű�ڵ� -, -, -, ��

			if (map[i][j] == 0)
				printf("   %c", 5); // �ƽ�Ű�ڵ� ��

		}
		printf("\n");
	}


	int result[100] = { 0 };  //��, ��÷ ����� �ִ� �迭

	result[rand() % length] = 1;  // result �迭 �� �ϳ��� 1(��÷)�� ������ ��

	// ����� ���
	for (int i = 0; i < length; i++) {

		if (result[i] == 0)
			printf("  ��");

		else if (result[i] == 1)
			printf(" ��÷");
	}

	int jul = 0, temp = 0;  //��ٸ� �������� ������ ��, ��� ����� �� ���� ��

	// ��ٸ� �������� �� ��� ���
	for (int k = 1; k <= length; k++) {

		// ��ٸ� ������ �� �Է¹ޱ�
		printf("\n\n���° �ٿ��� ���������?: ");
		scanf("%d", &jul);
		temp = jul;
		jul--;  //�迭 0���� �����ϴϱ� 1 ����

		color(k);  //���� ���� �ٲٱ�. ���� ������ ������ ������ �ٲ�� ��

		for (int i = 0; i < row; i++) {

			for (int j = 1; j <= 10; j++) {

				// ��ǥ �̵�
				gotoxy(jul, i);

				// ���ο� ����� ��ٸ� ��� �����
				if (map[i][jul] == 0) {

					printf("   %c", 5);
					Sleep(50);  //��ٸ���
				}

				else if (map[i][jul] == 1) {

					printf("%c%c%c%c", 6, 6, 6, 23);
					Sleep(200);  //��ٸ���
				}

				//������ ���� �������� �Ǵ��ϱ�

				if (map[i][jul] == 0 && map[i][jul + 1] == 1) {

					jul++;

					gotoxy(jul, i);

					if (map[i][jul] == 0) {
						printf("   %c", 5);
						Sleep(50);  //��ٸ���
					}

					else if (map[i][jul] == 1) {
						printf("%c%c%c%c", 6, 6, 6, 23);
						Sleep(200);  //��ٸ���
					}

					break;
				}

				else if (map[i][jul] == 1) {

					jul--;

					break;
				}
			}
		}

		for (int h = 0; h <= 5 * k; h++) {

			printf("\n");
		}

		color(15);  // 15�� �Ͼ��

		// ��� ���
		if (result[jul] == 0)
			printf("%d��° ���� ����� ���Դϴ�~\n", temp);

		else if (result[jul] == 1)
			printf("%d��° ���� ����� ��÷�Դϴ�!\n", temp);
	}

	return 0;
}

// ��ǥ �̵�
void gotoxy(int x, int y) {

	COORD Pos;

	Pos.X = 4 * x;  // %c%c%c%c�� ����ϱ� ������ 4�� ������� �˸��� �ڸ��� ��
	Pos.Y = 2 + y;  // ��� �� �Է� �ٰ� ��ȣ ��� ���� �����ؼ� 2�� ������

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);

}

// ���� ���� �ٲٱ�
void color(int color_number) {

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_number);
};