#include<stdio.h>
#include<Windows.h>
#include<stdlib.h>
#include<time.h>

int main(void) {
	int i, x, y, red, green, blue;

	HDC hdc = GetWindowDC(GetForegroundWindow());

	srand(time(NULL));
	for (int i = 0; i < 10000; i++) {
		x = rand() % 300;
		y = rand() % 300 + 200;

		red = rand() % 256;
		green = rand() % 256;
		blue = rand() % 256;

		// x, y ��ġ�� ���� ��� �Լ�
		SetPixel(hdc, x, y, RGB(red, green, blue));
		//Sleep(10);
	}
	getchar();	// ���α׷� ���� ���ڿ��� �� ������ �Է� ���

	return 0;
}