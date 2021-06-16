#include<stdio.h>
#include <windows.h>
#include<math.h>

float timef(float d, float v, float c, float a, float b);

float ABS(float n) {
	if (n > 0)
		return n;
	else
		n = -n;
	return n;
}

void SetConsoleView()
{
	system("mode con:cols=100 lines=25");

}

void GotoXY(int x, int y)
{
	COORD Pos;
	Pos.X = 2 * x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

int main() {
	SetConsoleView();

	GotoXY(15, 2);
	printf("*** 1학년 2반 5번 박재원 ***");

	GotoXY(15, 3);
	printf("이 프로그램은 탄성충돌의 간단한 모델입니다.");

	GotoXY(15, 4);
	printf("시간이 생각보다 짧습니다.주의해 주세요.");

	GotoXY(15, 5);
	printf("초기 조건을 입력하여 주십시오.\n");

	float a, b;//두 물체의 질량
	float v = 0;//물체의 속도
	float c = 0;//가벼운 물체의 초기 속도
	int cnt = 0;//충돌 횟수
	float d = 0;//물체 사이의 거리

	GotoXY(15, 6);
	printf("원주율의 근사값을 얻으시려면");

	GotoXY(15, 7);
	printf("10의 짝수승의 비로 질량비를 설정하세요");

	GotoXY(15, 8);
	printf("추천 값: 100 1 5 4");

	GotoXY(15, 9);
	printf("왼쪽 무거운 물체의 질량:");

	scanf("%f", &a);
	GotoXY(15, 10);
	printf("오른쪽 가벼운 물체의 질량:");

	scanf("%f", &b);
	GotoXY(15, 11);
	printf("왼쪽 무거운 물체의 속도:");

	scanf("%f", &v);
	GotoXY(15, 12);
	printf("벽과 가벼운 물체 사이의 거리");

	scanf("%f", &d);
	if (a <= b) {
		printf("입력이 잘못되었습니다.");
	}
	else {
		while (1) {
			v = v * (float)((a - b) / (a + b)) + c * (float)((2 * b) / (a + b));//탄성충돌시 무거운 물체의 속도
			c = c * (float)((b - a) / (a + b)) + v * (float)((2 * a) / (a + b));//가벼운 물체의 속도
			if (c > 0) {
				c *= -1;
				cnt++;
			}
			cnt++;
			if (ABS(v) > ABS(c)) {
				break;
			}
		}
		GotoXY(15, 13);
		printf("충돌 횟수는 %d번 입니다", cnt);
		GotoXY(15, 14);
		printf("시간은 %f초 경과하였습니다\n\n\n\n\n", timef(d, v, c, a, b));
	}
	return 0;
}

float timef(float d, float v, float c, float a, float b) {

	float time = 0;

	float k = 0;

	while (v > 0) {

		v = v * (float)((a - b) / (a + b)) + c * (float)((2 * b) / (a + b));//충돌 속도 식

		c = c * (float)((b - a) / (a + b)) + v * (float)((2 * a) / (a + b));//충돌 속도 식

		if (c < 0) {
			k = -c;//벽에 튕기고 반대 방향으로 운동하는 것에 대한 묘사
		}

		else {
			k = c;//그렇지 않고 직진하는 경우에 대한 묘사
		}
		time += (float)d / (k + v);//시간은 거리를 속도로 나눈 것과 같다라는 사실을 잘 이용해 보자.

		d *= (float)k / (k + v);//거리가 속도에 비례하여 계속 감소하는 모델,충돌 시간 간격이 줄어듦에 따라서 거리도 증가.
	}
	while (ABS(v) < ABS(c)) {

		v = v * (float)((a - b) / (a + b)) + c * (float)((2 * b) / (a + b));//나중 속도의 공식 1

		c = c * (float)((b - a) / (a + b)) + v * (float)((2 * a) / (a + c));//나중 속도의 공식 2

		if (c < 0) {
			k = -c;
		}
		else {
			k = c;
		}
		time += (float)d / (k - v);
		d *= (float)k / (k - v);
	}
	return time;
}