#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<conio.h>

struct dtime {
	int day;
	int hr;
	int min;
	int sec;
};

int main() {

	struct tm* in, * out, * today, day1;	// 입사, 퇴사, 현재 날짜와 시간, 새학기시작날
	struct dtime tp, tl;				// time passed, time left

	time_t start, finish, passed, left;

	time_t now;
	now = time(NULL);

	int iyr, imth, iday;	// iyr = in year = 입사한 년도
	int oyr, omth, oday;
	char* weekday[] = { "일요일", "월요일", "화요일", "수요일", "목요일", "금요일", "토요일" };

	int tda;	// 새학기 시작하고 지난 날

	day1.tm_year = 2021 - 1900;
	day1.tm_mon = 3 - 1;
	day1.tm_mday = 2;
	day1.tm_hour = 1;
	day1.tm_min = 1;
	day1.tm_sec = 1;
	// mktime함수 쓰려면 시, 분, 초 값 필요

	mktime(&day1);
	// mktime 함수를 호출하면 년, 월, 일 값에 따라 구조체의 tm_wday와 tm_yday를 설정.

	today = localtime(&now);
	tda = today->tm_yday - day1.tm_yday + 1;

	printf("\n**** ! 퇴사까지 COUNTDOWN ! ****\n");
	printf("오늘은 2021학년도 시작한지 %d일째 되는 날!\n\n", tda);
	printf("[입사 시간은 19:30 , 퇴사 시간은 16:20] 예외는 생각하지 않는다~\n\n\n");

	in = localtime(&now);	//초기화

	printf("언제 입사했어? (yyyy mm dd) : ");

	scanf("%d %d %d", &iyr, &imth, &(in->tm_mday));
	in->tm_year = iyr - 1900;
	in->tm_mon = imth - 1;
	in->tm_hour = 19;
	in->tm_min = 30;
	in->tm_sec = 0;

	start = mktime(in);
	// mktime 함수는 매개변수로 받은 구조체를 time_t형으로 반환 
	// => in을 time_t형으로 바꿔 start에 저장

	printf("\n\n입사한 날짜 : %d년 %2d월 %2d일 %s\n"
		, in->tm_year + 1900, in->tm_mon + 1, in->tm_mday, weekday[in->tm_wday]);


	out = localtime(&now);

	printf("\n\n언제 퇴사해? (yyyy mm dd) : ");

	scanf("%d %d %d", &oyr, &omth, &(out->tm_mday));
	out->tm_year = oyr - 1900;
	out->tm_mon = omth - 1;
	out->tm_hour = 16;
	out->tm_min = 20;
	out->tm_sec = 0;

	finish = mktime(out);

	printf("\n\n퇴사 날짜 : %d년 %2d월 %2d일 %s\n"
		, out->tm_year + 1900, out->tm_mon + 1, out->tm_mday, weekday[out->tm_wday]);


	today = localtime(&now);

	printf("\n\n오늘 날짜 : %d년 %2d월 %2d일 %s\n\n"
		, today->tm_year + 1900, today->tm_mon + 1, today->tm_mday, weekday[today->tm_wday]);

	while (1) {

		now = time(NULL);	//now를 계속 업데이트시킴

		passed = now - start;	//입사시간부터 지금까지 흐른 초
		left = finish - now;	//지금부터 퇴사시간까지 남은 초

		tp.day = (int)passed / 86400;	//24*3600=86400
		tp.hr = (int)passed / 3600 % 24;
		tp.min = (int)passed % 3600 / 60;
		tp.sec = (int)passed % 60;

		tl.day = (int)left / 86400;
		tl.hr = (int)left / 3600 % 24;
		tl.min = (int)left % 3600 / 60;
		tl.sec = (int)left % 60;

		today = localtime(&now);	//계속 업뎃되는 현재시간

		printf("현재 시간  %02d : %02d : %02d\t\t 지금까지 버틴 시간  %d일 %02d시간 %02d분 %02d초\t 앞으로 남은 시간  %d일 %02d시간 %02d분 %02d초\r"
			, today->tm_hour, today->tm_min, today->tm_sec
			, tp.day, tp.hr, tp.min, tp.sec
			, tl.day, tl.hr, tl.min, tl.sec);
		// \r로 줄의 맨앞으로 돌아가 시간 계속 덮어쓰기

		if (kbhit() == 1)	// 키보드에 입력값이 있으면 break
			break;
	}

	return 0;
}