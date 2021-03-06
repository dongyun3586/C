//년, 월, 일을 입력받아 지정된 형식으로 출력하는 연습을 해보자.
//입력받은 연, 월, 일을 yyyy.mm.dd 형식으로 출력한다.

#include<stdio.h>

int main_1019(void) {
	int y, m, d;
	scanf("%d.%d.%d", &y, &m, &d);
	printf("%04d.%02d.%02d", y, m, d);

	return 0;
}