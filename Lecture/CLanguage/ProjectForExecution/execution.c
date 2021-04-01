#include<stdio.h>

int main() {
	time_t t;
	t = time();      // time() 함수를 통해서 현재 시간 반환
	printf("%lld\n", t);   // 출력

	// time() : 1970년 1월 1일 00시 00분(UTC) 부터 지금까지 초단위의 시간에 대한 정수값 반환
	printf("%d\n", time(NULL));  // 현재 시간 출력





	//for (int i = 0; i < 10; i++) {
	//	
	//}

	return 0;
}