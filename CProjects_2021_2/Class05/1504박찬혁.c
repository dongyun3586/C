#include<stdio.h>

void set(char array[31][31]);
void print(char array[31][31]);
void process(int X, int Y, int count, char horse);
void move(int n, int x, int y, int count, char horse);
int check(int count1, int count2);
void end();

char arr[31][31];//������ ��
char* yuut[] = { "OOOX(��)","OOXX(��)","OXXX(��)","XXXX(��)","OOOO(��)" }; //��

int x1 = 30, y1 = 30, x2 = 30, y2 = 30;// ���� ��1,��2�� x,y ��ǥ
int counta = 0, countb = 0;//���� ��1�� ��2�� ������ ���� ����
int p;//p�� 1�� �� ��, p�� 2�� �� ��.. p�� 5�� �� �� ��
char k[2];// ������ ���� ���������� �ߴ� ���� ���� ���� ���� ����Ű�� �޴� �迭

int main() {
	printf("�������� �ų���~ ��մ�~ ��!��!��!\n�� 2���̰� ��1�� �����̸� �� ���� ���� 4���Դϴ�. enter Ű�� ���� �������ּ���.\n");
	fgets(k, 2, stdin);// ���� ȭ�鿡 �ٷ� ������ ���� �ߴ� �� �����ϱ� ����

	set(arr);//arr �ʱ�ȭ

	while (1)
	{
		process(x1, y1, counta, '1');
		process(x2, y2, countb, '2');

		if (check(counta, countb))
			break;
	}

	end();

	return 0;
}

void set(char array[31][31]) { // ���� ���� �⺻���� �������� ����� �Լ�
	for (int i = 0; i < 31; i++)//2���� �迭�� ��, ���� 31�� ���� : �������� ����,���� ���� ������ ���� 6��, �밢�� ���� ������ 7��(�ڼ��� �� ������ ���� �׸��� �������ּ���)
		for (int j = 0; j < 31; j++)
			arr[i][j] = ' '; //�迭 �ʱ�ȭ�� ����

	for (int i = 0; i < 6; i++) {
		array[0][6 * i] = 'O'; // ���� �κ�
		array[30][6 * i] = 'O'; //���� �κ� 
		array[6 * i][0] = '0';  //���� �κ�
		array[6 * i][30] = '0'; //���� �κ�
	}

	for (int i = 0; i < 7; i++) { // �밢�� 
		array[5 * i][5 * i] = 'O'; // ������
		array[5 * i][30 - 5 * i] = 'O'; // ������
	}
}

void print(char array[31][31]) { // �������� ��� �Լ�
	for (int i = 0; i < 31; i++) {
		for (int j = 0; j < 31; j++)
			printf("%c", *(array[i] + j));
		printf("\n");
	}
}

void process(int X, int Y, int count, char horse) { // �������� ��������� �巯�� �ִ� �Լ�
	srand(time(NULL));
	p = rand() % 5 + 1;
	printf("�� %c : %s\n", horse, yuut[p - 1]);// �� ���� ��ŭ ���� �̵����� �����ش�.
	move(p, X, Y, count, horse);
	print(arr);

	if (p == 4 || p == 5) {
		printf("�� �� ��~ enter Ű�� �Է��ϼ���\n");
		fgets(k, 2, stdin);
		if (horse == '1')
			process(x1, y1, counta, '1');
		else process(x2, y2, countb, '2');
	}
	else {
		printf("���� �� ����~ enter Ű�� �Է��ϼ���\n");
		fgets(k, 2, stdin);
	}
}

void move(int n, int x, int y, int count, char horse) {// ���� �̵���Ű�� �Լ�(������ �������� ��ǥ �׸��� �������ּ���)
	arr[x][y] = 'O';// �̵��ϱ� ���� ���� ��ġ�� ���������� 'O'���� �ٲپ���´�.

	if (x == y == 30) {//Ȩ // Ȩ�� ���� ���� ���� ������ ������� ���ļ� Ȩ�� ���� ���� ����ؾ� �ϱ� ����
		x = 30 - n * 6, y = 30;
	}
	else if (x == y && x != 30) {//������ //�������� �����⺸�� ���� ���� ����:�������� (15,15)���� ���������� ���̱� ���� 
		if (x + n * 5 > 30)//���� Ȩ�� ������ ���
			count++, x = 30, y = 30;
		else x += n * 5, y += n * 5;
	}
	else if (x + y == 30) {//������ //�������� ����,���κ��� ���� ���� ���� : �� ������ ���ΰ� (6,30)���� ���������� ���̱� ����
		if (x + n * 5 > 30)
			y = (n - (30 - x) / 5) * 6, x = 30;
		else x += n * 5, y -= n * 5;
	}
	else if (y == 30) {// �� ������ ����
		if (x - 6 * n < 0)
			y = 30 - (n - (x / 6)) * 6, x = 0;
		else x -= 6 * n;
	}
	else if (x == 0) {//�� ���� ����
		if (y - 6 * n < 0)
			x = (n - y / 6) * 6, y = 0;
		else y -= n * 6;
	}
	else if (y == 0) {//�� ���� ����
		if (x + n * 6 > 30)
			y = (n - (30 - x) / 6) * 6, x = 30;
		else x += 6 * n;
	}
	else if (x == 30) {//�� ���� ����
		if (y + 6 * n > 30)
			count++, y = 30;
		else y += 6 * n;
	}

	arr[x][y] = horse;//������ ���� ���� ���д�

	if (horse == '1')//�������� ���� �̵���Ű�� ���� ���� ���� ��ǥ�� ����
		x1 = x, y1 = y;
	else x2 = x, y2 = y;
}

int check(int count1, int count2) {//������ ���� ������ 4�� �� 0�� �ƴ� ���� ��ȯ�ϴ� �Լ�
	if (count1 == 4 && count2 == 4)//����
		return 3;
	else if (count1 == 4)//��1�� �̱� ���
		return 2;
	else if (count2 == 4)//��2�� �̱� ���
		return 1;
	else return 0;
}

void end() {   // �¸��� �������ִ� �Լ�
	if (check(counta, countb) == 3)// ����
		printf("����!!\n\n ������ �̿����ּż� �����մϴ�.�ȴ�~");
	else if (check(counta, countb) == 2)//��1�� �¸�
		printf("��1�� �¸��߽��ϴ�. ���ϵ����\n\n ������ �̿����ּż� �����մϴ�. �ȴ�~");
	else if (check(counta, countb) == 1)//��2�� �¸�
		printf("��2�� �¸��߽��ϴ�. ���ϵ����\n\n ������ �̿����ּż� �����մϴ�. �ȴ�~");
}