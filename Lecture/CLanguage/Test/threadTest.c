#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>		// Sleep( ) 딜레이 함수
#include <process.h>		// 쓰레드를 사용할 수 있는 기능

struct Points {
	int a;
	int b;
	int c;
};

// Thread_A라는 이름의 쓰레드 => A 를 1초마다 출력
unsigned _stdcall Thread_A(struct Points *arg)
{
	srand(time(NULL));
	while(1)
	{
		//printf("arg = %p\n", arg);
		arg->a = rand() % 10 + 1;
		arg->b = rand() % 10 + 1;
		arg->c = rand() % 10 + 1;
		printf("쓰레드 : arg.a = %d, arg.b = %d, arg.c = %d\n", arg->a, arg->b, arg->c);
		Sleep(2000);
	}
	_endthread();	 // 스레드를 종료한다.
}

int main(void)
{
	struct Points p1 = { 1,2,3 };
	//printf("p1 = %p\n", &p1);
	printf("main 초기 상태: p1.a=%d, p1.b=%d, p1.c=%d\n", p1.a, p1.b, p1.c);

	_beginthreadex(NULL, 0, Thread_A, &p1, 0, NULL);		// Thread_A 호출

	while (1)
	{
		printf("main : p1.a = %d, p1.b = %d, p1.c = %d\n", p1.a, p1.b, p1.c);
		Sleep(2000);
	}
	return 0;
}