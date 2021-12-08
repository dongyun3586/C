#include<stdio.h>
#include<stdlib.h>  //rand(), srand() 
#include<time.h>  // time()
#include<windows.h>  // COORD, SetConsoleCursorPosition, SetConsoleTextAttribute

#define length 17
#define row 10

void gotoxy(int x, int y);  // ��ǥ �̵�
void color(int color_number);  // ���� ���� �ٲٱ�
void makesadari(int arr[row][length]);
void printsadari(int arr[row][length], int i, int j, int n);

int main() {
	int map[row][length] = {  //��ٸ� ������ 10, ���� �ִ� 100���� ����
	{0},
	{0}
	};

	char* stuNum[] = { "����", "����", "����", "����", "�ÿ�", "����", "����", "����", "����", "����", "����", "����", "����", "����", "����", "����", "����" };

	// �л� �̸� ���
	printf(" ");
	for (int i = 0; i < length; i++) {
		printf(" %s", *(stuNum + i));
	}
	printf("\n");
	// ��ٸ� �����
	makesadari(map);

	// ��ٸ� ���
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < length; j++) {
			printsadari(map, i, j, 0);
		}
		printf("\n");
	}

	int result[100] = { 0 };  //��� �迭
	for (int i = 0; i < length; i++)  //�迭 �ʱ�ȭ
		result[i] = i + 1;

	srand(time(NULL));
	for (int i = 0; i < 30; i++) {    // �����۾��� 30�� �ݺ��ϱ�
		int randNum1 = rand() % length;    // 1~��� �� ������ ������ ���� �߻��Ѵ�.
		int randNum2 = rand() % length;
		int temp;

		temp = result[randNum1];
		result[randNum1] = result[randNum2];
		result[randNum2] = temp;
	}

	// ����� ���
	for (int i = 0; i < length; i++)
		printf("%5d", result[i]);

	int jul = 0, temp = 0;  //��ٸ� �������� ������ ��, ��� ����� �� ���� ��

	// ��ٸ� �������� �� ��� ���
	for (int k = 1; k <= length; k++) {

		// ��ٸ� ������ �� �Է¹ޱ�
		printf("\n\n   ���° �ٿ��� ���������? ��ü ����� ������ 0�� �Է��ϼ���. : ");
		scanf("%d", &jul);
		temp = jul;
		jul--;  //�迭 0���� �����ϴϱ� 1 ����

		//�ѹ��� ��� ���
		if (temp == 0) {
			for (int h = 0; h < length; h++) {
				int track = h;
				for (int i = 0; i < row; i++) {
					for (int j = 1; j <= row; j++) {
						//���� �������� �Ǵ��ϱ�
						if (map[i][track] == 0 && map[i][track + 1] == 1) {
							track++;
							break;
						}
						else if (map[i][track] == 1) {
							track--;
							break;
						}
					}
				}
				printf("   %s: %2d�� �ڸ�\n", *(stuNum + h), result[track]);
			}
			break;
		}

		//�ϳ��� ��������
		else {
			color(k);  //���� ���� �ٲٱ�. ���� ������ ������ ������ �ٲ�� ��

			for (int i = 0; i < row; i++) {
				for (int j = 0; j < row; j++) {
					gotoxy(jul, i - 1); //��ǥ �̵�
					printsadari(map, i, jul, 50); // ���ο� ����� ��ٸ� �����

					if (map[i][jul] == 0 && map[i][jul + 1] == 1) { //������ ���� �������� �Ǵ��ϱ�
						jul++;
						gotoxy(jul, i - 1);
						printsadari(map, i, jul, 50);
						break;
					}

					else if (map[i][jul] == 1) {
						jul--;
						break;
					}
				}
			}
		}
		for (int h = 0; h <= 5 * k; h++) {
			printf("\n");
		}
		color(15);  // 15�� �Ͼ��
		// ��� ���
		printf("   %s�� �ڸ��� %d~\n", *(stuNum + temp - 1), result[jul]);
	}
	return 0;
}

// ��ǥ �̵�
void gotoxy(int x, int y) {
	COORD Pos;
	Pos.X = 5 * x;  // %c%c%c%c�� ����ϱ� ������ 5�� ������� �˸��� �ڸ��� ��
	Pos.Y = 2 + y;  // ��� �� �Է� �ٰ� ��ȣ ��� ���� ����ؼ� 2�� ������
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
// ���� ���� �ٲٱ�
void color(int color_number) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_number);
};

void makesadari(int arr[row][length]) {
	srand(time(NULL));

	for (int i = 1; i < row - 1; i++) {
		for (int j = 1; j < length; j++) {
			arr[i][j] = rand() % 2;

			if (arr[i][j - 1] == 1 && arr[i][j] == 1)  //�������� �ð� ������ �ʵ��� ��
				arr[i][j] = 0;  // 1�� 0���� �ٲ���
		}
	}

}

void printsadari(int arr[row][length], int i, int j, int n) {
	if (arr[i][j] == 1) {
		printf("%c%c%c%c%c", 6, 6, 6, 6, 23); //�ƽ�Ű�ڵ� -, -, -, ��
		Sleep(n * 10);
	}

	if (arr[i][j] == 0) {
		printf("%5c", 5); // �ƽ�Ű�ڵ� ��
		Sleep(n);
	}
}