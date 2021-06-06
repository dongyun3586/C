#include<windows.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
	int x, y, r, g, b;

	HDC hdc;
	hdc = GetWindowDC(GetForegroundWindow());

	srand(time(NULL));
	for (int i = 0; i < 10000; i++) {
		x = rand() % 300;
		y = rand() % 300 + 150;
		r = rand() % 256;
		g = rand() % 256;
		b = rand() % 256;
		SetPixel(hdc, x, y, RGB(r, g, b));
	}
	return 0;
}