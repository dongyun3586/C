#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>		// Sleep( ) ������ �Լ�
#include <process.h>		// �����带 ����� �� �ִ� ���

struct Points {
	int a;
	int b;
	int c;
};

// Thread_A��� �̸��� ������ => A �� 1�ʸ��� ���
unsigned _stdcall Thread_A(struct Points *arg)
{
	srand(time(NULL));
	while(1)
	{
		//printf("arg = %p\n", arg);
		arg->a = rand() % 10 + 1;
		arg->b = rand() % 10 + 1;
		arg->c = rand() % 10 + 1;
		printf("������ : arg.a = %d, arg.b = %d, arg.c = %d\n", arg->a, arg->b, arg->c);
		Sleep(2000);
	}
	_endthread();	 // �����带 �����Ѵ�.
}

int main(void)
{
	struct Points p1 = { 1,2,3 };
	//printf("p1 = %p\n", &p1);
	printf("main �ʱ� ����: p1.a=%d, p1.b=%d, p1.c=%d\n", p1.a, p1.b, p1.c);

	_beginthreadex(NULL, 0, Thread_A, &p1, 0, NULL);		// Thread_A ȣ��

	while (1)
	{
		printf("main : p1.a = %d, p1.b = %d, p1.c = %d\n", p1.a, p1.b, p1.c);
		Sleep(2000);
	}
	return 0;
}