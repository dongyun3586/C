#include <stdio.h>
#include <windows.h>
#include <time.h>

enum Difficulty { EASY = 1, NORMAL, HARD, EXPERT, END };//���̵� ������ ���� ����ü
int arr[9][9][2] = { 0 };                             //������ �� �迭 arr[9][9][0], ������ 0 �Ǻ��� ���� arr[9][9][1] ����
int mistake = 0, game = 0;                              //mistake ���� �� �Ǽ��� Ƚ��, game �¸��� ���� Ƚ��

void BasicArray();                                    //�⺻���� ������ �迭 ����
void ExchangeRow();                                   //�ೢ�� ��ȯ
void ExchangeColumn();                                //������ ��ȯ
void ExchangeNum();                                   //���ڳ��� �ڸ� ��ȯ
void PrintArray();                                    //������ ���� ���
void AddBlank(int n);                                 //�⺻���� ������ �迭�� 0 �߰�(�÷����ϴ� ����� ä�� ĭ)

int main() {


	int d, x, y, n, num = 0;                             //d : ���̵� ������ ���� scanf���� �޴� ����, x, y : �Է¹޴� ���� ��ǥ, num : 0���� �ٲٴ� ������ ����
	int numArr[9][9] = { 0 };                          //arr �ʱ�ȭ
	enum Difficulty difficulty;                        //���̵��� ���� EASY=1, NORMAL=2, HARD=3, EXPERT=4�� �����ϱ� ���� ����ü

start:                                                 //�������� goto������ ���ƿͼ� ���� �ٽ� ����

	srand(time(NULL));                                 //���� ���� ��� ���� srand(time(NULL))
	BasicArray(0);                                     //�⺻���� �迭 ����
	for (int i = 0; i < 15; i++) {
		ExchangeRow(0);                                //��, ��, ���ڳ��� �ڸ��� ��ȯ�� �迭�� ����
		ExchangeColumn(0);
		ExchangeNum(0);
	}

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			numArr[i][j] = arr[i][j][0];              //arr�� �ִ� ���ڵ��� numArr�� ����
		}
	}

	printf("**************������**************\n");
	printf("\n   ���̵��� �����ϼ���.\n   1.����\n   2.����\n   3.�����\n   4.������\n   5.����\n\n ���̵� : ");
	scanf("%d", &d);                                  //���̵� �Է¹ޱ�
	difficulty = d;                                   //���̵��� ����ü�� �̿��� switch case������ num �� ���� ����
	switch (difficulty) {                             //5���� �� ��� ���� ����
	case EASY:
		num = rand() % 8 + 5;
		break;
	case NORMAL:
		num = rand() % 8 + 13;
		break;
	case HARD: num = rand() % 8 + 21;
		break;
	case EXPERT: num = rand() % 8 + 29;
		break;
	case END:
		return 0;
	}

	AddBlank(num);                                     //AddBlank 0�߰� �Լ�(0�� ���� : ����ڰ� ä���־�� �ϴ� ���� ĭ)
	system("cls");                                     //������ ���̵� ��µǾ� �ִ� ȭ�� û��
	printf("\n\n\n\n\n     ������ ���� ���� �� ......");
	Sleep(1000);
	system("cls");
	PrintArray(0);                                     //�ϼ��� ������ ���� ���

	while (1) {
		printf("\n\n��ǥ x, y, ���� �Է� (��, ���� ���� ���κ��� ��ǥ=(1, 1)) : ");
		scanf("%d %d %d", &x, &y, &n);                 //��ǥ �Է¹��� �� �� ��ǥ�� ���� ä�� ���� �Է�
		if (arr[y - 1][x - 1][0] == 0) {               //�ش� ��ǥ�� �ִ� ���� 0���� �ƴ��� �Ǻ�
			if (n == numArr[y - 1][x - 1]) {           //�ش� ��ǥ�� �ִ� ���� �Է��� ���� ��ġ�ϴ��� �Ǻ�
				arr[y - 1][x - 1][0] = n;              //��ġ�� ��� arr�� �� ���� �� num���� 1����
				num--;
			}
			else {
				printf("\nƲ�Ƚ��ϴ�. ");              //�ش� ��ǥ�� �ִ� ���� ��ġ���� ���� ���
				mistake++;                             //�Ǽ� Ƚ�� 1ȸ �߰�
				Sleep(500);
			}
		}
		else {
			printf("\n�ش� ��ǥ�� ���� 0�� �ƴմϴ�. ");//�ش� ��ǥ�� ���� 0�� �ƴ� ���
			Sleep(500);
		}
		system("cls");                                  //ȭ�� û��
		PrintArray(0);                                  //�ٲ� �迭 ���
		if (num == 0) {
			goto END;                                   //num�� 0�� ���� ��� �ݺ��� ���� goto
		}
	}
END:
	system("cls");                                      //���� �¸�
	printf("\n\n\n\n\n            �����մϴ�!!!");
	Sleep(2000);                                        //���� �ð� ���
	game++;                                             //�¸��� ���� Ƚ�� 1ȸ �߰�
	system("cls");
	goto start;                                         //���� �ٽ� ����
}

void BasicArray() {
	for (int i = 0; i < 9; i++) {
		arr[0][i][0] = i + 1;                           //ù ���� 1 2 3 4 5 6 7 8 9�� ä���.
	}
	for (int i = 1; i < 9; i++) {                       //������ ���ڵ��� ������ ��Ģ�� �����ϵ��� ä���
		for (int j = 0; j < 9; j++) {
			arr[i][j][0] = (arr[0][j][0] + 3 * i + i / 3) % 9;
		}
	}
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (arr[i][j][0] == 0) arr[i][j][0] = 9;
		}
	}
}

void PrintArray() {
	printf("\n\n  ");
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {                    //arr ���
			printf(" %d ", arr[i][j][0]);
		}

		printf("\n  ");
	}
	printf("\n�Ǽ� : %dȸ\n�¸��� ���� : %d��", mistake, game);//�Ǽ��� Ƚ��, �¸��� ���� �� ���
}

void ExchangeRow() {
	int temp;
	srand(time(NULL));
	int a = rand() % 9;                                   //a��° ��� b��° �� ��ȯ
	int b = (a / 3) * 3;
	if (a == b) return 0;                                 //a=b�� ������ ����
	else {
		for (int i = 0; i < 9; i++) {
			temp = arr[a][i][0];
			arr[a][i][0] = arr[b][i][0];
			arr[b][i][0] = temp;
		}
	}
}

void ExchangeColumn() {
	int temp;
	srand(time(NULL));
	int a = rand() % 9;                                   //a��° ���� b��° �� ��ȯ
	int b = (a / 3) * 3;
	if (a == b)return 0;
	else {
		for (int i = 0; i < 9; i++) {
			temp = arr[i][a][0];
			arr[i][a][0] = arr[i][b][0];
			arr[i][b][0] = temp;
		}
	}
}

void ExchangeNum() {
	int temp, a, b;
	srand(time(NULL));
	while (1) {
		a = rand() % 9;                                  //a, b�� 1~9���� �� �����ϰ� ����
		b = rand() % 9;
		if (a != b) break;
	}
	int k[2];                                            //a�� b���� �ӽ÷� ������ k[2] ����
	int flag;                                            //������ �࿡�� �� �� �ִ��� �Ǻ��� ���� flag ����
	for (int i = 0; i < 9; i++) {
		flag = 0;
		for (int j = 0; j < 9; j++) {
			if ((arr[i][j][0] == a || arr[i][j][0] == b) && flag == 0) {
				k[0] = arr[i][j][0];                     //flag=0 �� ��� = a�� b ���� ���� ��ǥ�� ���� �࿡�� ó�� �� ���
				k[1] = j;                                //k[0]�� �� ���� �� k[1]�� ��ǥ ����
				flag++;                                  //flag = 1�� ����� �ٸ� a�� b ���� ���� ��ǥ�� �߰����� �� �Ǻ�
			}
			else if ((arr[i][j][0] == a || arr[i][j][0] == b) && flag == 1) {
				arr[i][k[1]][0] = arr[i][j][0];          //flag=1�� ��� 2��°�� �߰�
				arr[i][j][0] = k[0];                     //a�� b�� ���� ��ȯ
			}
		}
	}
}

void AddBlank(int n) {
	int number = 0;
	while (number != n) {
		int a = rand() % 9;
		int b = rand() % 9;
		if (arr[a][b][1] == 0) {                           //arr[a][b][1]�� 0�� ��� arr[a][b][0]�� 0�� �ƴ� ��
			arr[a][b][0] = 0;                              //arr[a][b][0]�� 0���� �����ϰ� arr[a][b][1]�� 1�� �ٲ㼭 arr[a][b][0]�� 0�� ���� ǥ���Ѵ�.
			arr[a][b][1] = 1;
			number++;                                      //�ݺ����� n������ �ݺ�
		}
	}
}