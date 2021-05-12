#include<stdio.h>
#include<Windows.h>

void drawRect(int n);
void drawEllipse(HDC hdc, int n);

int main(void) {
	HDC hdc = GetWindowDC(GetForegroundWindow());

	// ������ �簢�� �׸���
	//drawRect(hdc, 100);

	// ������ Ÿ�� �׸���
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