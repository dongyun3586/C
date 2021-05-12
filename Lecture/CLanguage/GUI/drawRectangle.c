#include<stdio.h>
#include<Windows.h>

void drawRect(int n);
void drawEllipse(HDC hdc, int n);

int main(void) {
	HDC hdc = GetWindowDC(GetForegroundWindow());

	// 무작위 사각형 그리기
	//drawRect(hdc, 100);

	// 무작위 타원 그리기
	drawEllipse(hdc, 100);
	
	return 0;
}

void drawRect(HDC hdc, int n)
{
	for (int i = 0; i < n; i++) {
		int x = rand() % 500 + 200;
		int y = rand() % 300 + 200;
		int w = rand() % 100;
		int h = rand() % 100;
		Rectangle(hdc, x, y, x + w, y + h);
		Sleep(100);
	}
}

void drawEllipse(HDC hdc, int n)
{
	for (int i = 0; i < n; i++) {
		int x = rand() % 500 + 200;
		int y = rand() % 300 + 200;
		int w = rand() % 100;
		int h = rand() % 100;
		Ellipse(hdc, x, y, x + w, y + h);
		Sleep(100);
	}
}