#include<stdio.h>
#include<time.h> // clock(), clock_t, clock()�� ���α׷��� ���� �������κ��� ����� �ð��� ms ������ ����(type:long) -> max: 2147483647ms �Ǵ� �� 24.8 ��
#include<Windows.h> // system("cls"), Sleep((int)num), system("pause")

void timer(); // Ÿ�̸�
void stop_watch(); // �����ġ
void array_in(char timearray[][33], int num, int start); // timearray�� ������ ���� ���� �ִ� �Լ�
void time_count(int hour, int min, int sec); // �ð��� counting�ϴ� �Լ�
void print_time(char timearray[][33]); // ���� �ð��� ����ϴ� �Լ�

int main() {
	int input;

	while (1) {
		system("cls"); //��� ������Ʈ�� �ִ� cls��, ��ȭâ�� �ʱ�ȭ��Ŵ
		printf("Ÿ�̸Ӹ� �����Ϸ��� EnterŰ��, �����ġ�� �����Ϸ��� spaceŰ��, �����Ϸ��� EscŰ�� �����ּ���.");
		input = getch(); // getch�� ����ڰ� �Է��� Ű�� �ƽ�Ű �ڵ� ������ �ٷ� ����(���� ���� �ʿ� X)
		switch (input) {
		case 13: // Enter�� ǥ��
			timer();
			break;
		case 32: // Space�� ǥ��
			stop_watch();
			break;
		case 27:
			return;
		}
	}
}

void timer() {
	int hour = 0, min = 0, sec = 0, start, y = 1;

	system("cls");
	printf("Ÿ�̸��Դϴ�.\n");
	while (1) {
		start = 0;
		printf("�ð��� �Է����ּ���.(�Է� ����: �ð� �� ��)\n\n");
		scanf("%d %d %d", &hour, &min, &sec);
		if (hour < 0 || min < 0 || sec < 0) // �ϳ� �̻��� ������ ��
			printf("�ð�, ��, �ʴ� 0 �̻��̿��� �մϴ�.\n");
		else
			start++;
		if (min >= 60 || sec >= 60) // ��, �ʰ� 60 �̻�
			printf("�а� �ʴ� ���� 60 �̻��� ���� �Է��� �� �����ϴ�.\n");
		else
			start++;
		if (hour >= 100) // �ð��� 100 �̻�
			printf("�ð��� 100 �̻��� ���� �Է��� �� �����ϴ�.\n");
		else
			start++;
		if (hour || min || sec)// ��� 0�� �Է����� ��
			start++;
		else
			printf("Ÿ�̸��� ���� �ð��� 0�ʺ��� Ŀ�� �մϴ�.\n");
		if (start == 4) // start ������ ��� �������Ѿ����� ����
			break;
	}

	time_count(hour, min, sec);
	printf("Ÿ�̸� ����\a\n"); // \a:�����
	system("pause"); // ��� ������Ʈ�� �ִ� �Լ���, Ű�� �Է¹��������� ����
}

void stop_watch() {
	clock_t a, b; // clock()���� ������ ����, clock()�� ���α׷��� ���� �������κ��� ����� �ð��� ms ������ ����(type:long) -> max: 2147483647ms �Ǵ� �� 24.8 ��
	char timearray[5][33] = { 0 }; // ��¿� �迭 ����
	int go, hour = 0, min = 0, sec = 0; // ���� ���� �����ϴ� ����
	timearray[1][10] = timearray[1][22] = timearray[3][10] = timearray[3][22] = 1; // �ð�, ��, �� ���� : �κ�

	system("cls");
	printf("�����ġ�� �����Ϸ��� EnterŰ�� �����ּ���.\n");

	while (1) {
		go = getch();// ����� �Է� ���ڸ� ����
		if (go == 13)
			break;
	}

	while (1) {
		a = clock(); //a�� �Է� ���� �ð� �Է�
		array_in(timearray, hour / 10, 0);// �ð�, ��, �ʸ� �� �ڸ��� �������(timearray�� �ּ� �� ����)
		array_in(timearray, hour % 10, 1);
		array_in(timearray, min / 10, 2);
		array_in(timearray, min % 10, 3);
		array_in(timearray, sec / 10, 4);
		array_in(timearray, sec % 10, 5);

		system("cls");
		printf("���Ḧ ���Ͻø� CTRL + C �� �Է��ϼ���.\n\n");
		print_time(timearray);//������ ���� ���, 

		sec++;
		if (sec >= 60)
			min++, sec -= 60;
		if (min >= 60)
			hour++, min -= 60;

		b = clock(); // b�� ��� �� �ð� �Է�

		Sleep(1000 - (b - a)); // 1��= 1000ms�� ���߱� ����, 1000���� ��±��� �ҿ�� �ð��� �� �ð���ŭ ���(�������� ����)
	}
}

void time_count(int hour, int min, int sec) {
	clock_t a, b;
	char timearray[5][33] = { 0 };
	int go;
	timearray[1][10] = timearray[1][22] = timearray[3][10] = timearray[3][22] = 1; // �ð�, ��, �� ���� : �κ�

	system("cls");
	if (hour)
		printf("%d�ð� ", hour);
	if (min)
		printf("%d�� ", min);
	if (sec)
		printf("%d�� ", sec);
	printf("Ÿ�̸��Դϴ�.\nŸ�̸Ӹ� �����Ϸ��� EnterŰ�� �����ּ���.\n");

	while (1) {
		go = getch();
		if (go == 13)
			break;
	}

	while (hour || min || sec) {
		a = clock();
		array_in(timearray, hour / 10, 0);
		array_in(timearray, hour % 10, 1);
		array_in(timearray, min / 10, 2);
		array_in(timearray, min % 10, 3);
		array_in(timearray, sec / 10, 4);
		array_in(timearray, sec % 10, 5);

		system("cls");
		printf("���Ḧ ���Ͻø� CTRL + C �� �Է��ϼ���.\n\n");
		print_time(timearray);

		sec--;
		if (sec < 0)
			min--, sec += 60;
		if (min < 0)
			hour--, min += 60;

		b = clock();

		Sleep(1000 - (b - a));
	}
	array_in(timearray, 0, 5);
	system("cls");
	printf("\n\n");
	print_time(timearray);
}

void array_in(char timearray[][33], int num, int start) {
	int startnum = (start / 2) * 2 + start * 5; //��ȣ�� ������� �迭�� ù��° �� ��ġ
	char numDigits[10][5][4] =  //�����з� ǥ������ 3���� �迭 [0][][] -> 0, [1][][] ->1 ...
	{
		{	//0�� ǥ��
		{1, 1, 1, 1},
		{1, 0, 0, 1},
		{1, 0, 0, 1},
		{1, 0, 0, 1},
		{1, 1, 1, 1}
		},
		{	//1�� ǥ��
		{0, 0, 0, 1},
		{0, 0, 0, 1},
		{0, 0, 0, 1},
		{0, 0, 0, 1},
		{0, 0, 0, 1}
		},
		{	//2�� ǥ��
		{1, 1, 1, 1},
		{0, 0, 0, 1},
		{1, 1, 1, 1},
		{1, 0, 0, 0},
		{1, 1, 1, 1}
		},
		{	//3�� ǥ��
		{1, 1, 1, 1},
		{0, 0, 0, 1},
		{0, 1, 1, 1},
		{0, 0, 0, 1},
		{1, 1, 1, 1}
		},
		{	//4�� ǥ��
		{1, 0, 0, 1},
		{1, 0, 0, 1},
		{1, 1, 1, 1},
		{0, 0, 0, 1},
		{0, 0, 0, 1}
		},
		{	//5�� ǥ��
		{1, 1, 1, 1},
		{1, 0 ,0 ,0},
		{1, 1, 1, 1},
		{0, 0, 0, 1},
		{1, 1, 1, 1}
		},
		{	//6�� ǥ��
		{1, 1, 1, 1},
		{1, 0, 0, 0},
		{1, 1, 1, 1},
		{1, 0, 0, 1},
		{1, 1, 1, 1}
		},
		{	//7�� ǥ��
		{1, 1, 1, 1},
		{1, 0, 0, 1},
		{0, 0, 0, 1},
		{0, 0, 0, 1},
		{0, 0, 0, 1}
		},
		{	//8�� ǥ��
		{1, 1, 1, 1},
		{1, 0, 0, 1},
		{1, 1, 1, 1},
		{1, 0, 0, 1},
		{1, 1, 1, 1}
		},
		{	//9�� ǥ��
		{1, 1, 1, 1},
		{1, 0, 0, 1},
		{1, 1, 1, 1},
		{0, 0, 0, 1},
		{1, 1, 1, 1}
		}
	};
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 4; j++)
			timearray[i][startnum + j] = numDigits[num][i][j]; // ��¿� �ð� �迭�� startnum�� ���� ������ ������ �Է�
}

void print_time(char timearray[][33]) {
	// Ÿ�̸ӿ��� ��ĭ�� ��(��->����), ä����ĭ�� ��(�� -> ����)
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 33; j++) {
			if (timearray[i][j]) // �迭�� ����� ���� ���� �� �Ǵ� ��ĭ(��)�� �����
				printf("��");
			else
				printf("��");
		}
		printf("\n");
	}
}