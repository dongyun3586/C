#include<stdio.h>
#include<time.h> // clock(), clock_t, clock()은 프로그램의 실행 시작으로부터 경과된 시간을 ms 단위로 측정(type:long) -> max: 2147483647ms 또는 약 24.8 일
#include<Windows.h> // system("cls"), Sleep((int)num), system("pause")

void timer(); // 타이머
void stop_watch(); // 스톱워치
void array_in(char timearray[][33], int num, int start); // timearray에 각각의 값을 집어 넣는 함수
void time_count(int hour, int min, int sec); // 시간을 counting하는 함수
void print_time(char timearray[][33]); // 남은 시간을 출력하는 함수

int main() {
	int input;

	while (1) {
		system("cls"); //명령 프롬프트에 있는 cls로, 대화창을 초기화시킴
		printf("타이머를 실행하려면 Enter키를, 스톱워치를 실행하려면 space키를, 종료하려면 Esc키를 눌러주세요.");
		input = getch(); // getch는 사용자가 입력한 키를 아스키 코드 값으로 바로 받음(엔터 누를 필요 X)
		switch (input) {
		case 13: // Enter를 표시
			timer();
			break;
		case 32: // Space를 표시
			stop_watch();
			break;
		case 27:
			return;
		}
	}
}

void timer() {
	int hour = 0, min = 0, sec = 0, start, y = 1;

	system("cls");
	printf("타이머입니다.\n");
	while (1) {
		start = 0;
		printf("시간을 입력해주세요.(입력 형식: 시간 분 초)\n\n");
		scanf("%d %d %d", &hour, &min, &sec);
		if (hour < 0 || min < 0 || sec < 0) // 하나 이상이 음수일 때
			printf("시간, 분, 초는 0 이상이여야 합니다.\n");
		else
			start++;
		if (min >= 60 || sec >= 60) // 분, 초가 60 이상
			printf("분과 초는 각각 60 이상의 값을 입력할 수 없습니다.\n");
		else
			start++;
		if (hour >= 100) // 시간이 100 이상
			printf("시간은 100 이상의 값을 입력할 수 없습니다.\n");
		else
			start++;
		if (hour || min || sec)// 모두 0을 입력했을 때
			start++;
		else
			printf("타이머의 지정 시간은 0초보다 커야 합니다.\n");
		if (start == 4) // start 조건을 모두 만족시켜야지만 실행
			break;
	}

	time_count(hour, min, sec);
	printf("타이머 종료\a\n"); // \a:경고음
	system("pause"); // 명령 프롬프트에 있는 함수로, 키를 입력받을때까지 멈춤
}

void stop_watch() {
	clock_t a, b; // clock()값을 저장할 변수, clock()은 프로그램의 실행 시작으로부터 경과된 시간을 ms 단위로 측정(type:long) -> max: 2147483647ms 또는 약 24.8 일
	char timearray[5][33] = { 0 }; // 출력용 배열 선언
	int go, hour = 0, min = 0, sec = 0; // 진행 여부 결정하는 변수
	timearray[1][10] = timearray[1][22] = timearray[3][10] = timearray[3][22] = 1; // 시간, 분, 초 사이 : 부분

	system("cls");
	printf("스톱워치를 시작하려면 Enter키를 눌러주세요.\n");

	while (1) {
		go = getch();// 사용자 입력 문자를 받음
		if (go == 13)
			break;
	}

	while (1) {
		a = clock(); //a에 입력 시작 시각 입력
		array_in(timearray, hour / 10, 0);// 시간, 분, 초를 한 자리씩 집어넣음(timearray의 주소 값 넣음)
		array_in(timearray, hour % 10, 1);
		array_in(timearray, min / 10, 2);
		array_in(timearray, min % 10, 3);
		array_in(timearray, sec / 10, 4);
		array_in(timearray, sec % 10, 5);

		system("cls");
		printf("종료를 원하시면 CTRL + C 를 입력하세요.\n\n");
		print_time(timearray);//디지털 숫자 출력, 

		sec++;
		if (sec >= 60)
			min++, sec -= 60;
		if (min >= 60)
			hour++, min -= 60;

		b = clock(); // b에 출력 후 시간 입력

		Sleep(1000 - (b - a)); // 1초= 1000ms를 맞추기 위해, 1000에서 출력까지 소요된 시간을 뺀 시간만큼 대기(일정하지 않음)
	}
}

void time_count(int hour, int min, int sec) {
	clock_t a, b;
	char timearray[5][33] = { 0 };
	int go;
	timearray[1][10] = timearray[1][22] = timearray[3][10] = timearray[3][22] = 1; // 시간, 분, 초 사이 : 부분

	system("cls");
	if (hour)
		printf("%d시간 ", hour);
	if (min)
		printf("%d분 ", min);
	if (sec)
		printf("%d초 ", sec);
	printf("타이머입니다.\n타이머를 시작하려면 Enter키를 눌러주세요.\n");

	while (1) {
		go = getch();
		if (go == 13)
			break;
	}

	while (hour || min || sec) {
		a = clock();
		array_in(timearray, hour / 10, 0);
		array_in(timearray, hour % 10, 1);
		array_in(timearray, min / 10, 2);
		array_in(timearray, min % 10, 3);
		array_in(timearray, sec / 10, 4);
		array_in(timearray, sec % 10, 5);

		system("cls");
		printf("종료를 원하시면 CTRL + C 를 입력하세요.\n\n");
		print_time(timearray);

		sec--;
		if (sec < 0)
			min--, sec += 60;
		if (min < 0)
			hour--, min += 60;

		b = clock();

		Sleep(1000 - (b - a));
	}
	array_in(timearray, 0, 5);
	system("cls");
	printf("\n\n");
	print_time(timearray);
}

void array_in(char timearray[][33], int num, int start) {
	int startnum = (start / 2) * 2 + start * 5; //번호를 집어넣을 배열의 첫번째 열 위치
	char numDigits[10][5][4] =  //디지털로 표시해줄 3차원 배열 [0][][] -> 0, [1][][] ->1 ...
	{
		{	//0을 표시
		{1, 1, 1, 1},
		{1, 0, 0, 1},
		{1, 0, 0, 1},
		{1, 0, 0, 1},
		{1, 1, 1, 1}
		},
		{	//1을 표시
		{0, 0, 0, 1},
		{0, 0, 0, 1},
		{0, 0, 0, 1},
		{0, 0, 0, 1},
		{0, 0, 0, 1}
		},
		{	//2를 표시
		{1, 1, 1, 1},
		{0, 0, 0, 1},
		{1, 1, 1, 1},
		{1, 0, 0, 0},
		{1, 1, 1, 1}
		},
		{	//3을 표시
		{1, 1, 1, 1},
		{0, 0, 0, 1},
		{0, 1, 1, 1},
		{0, 0, 0, 1},
		{1, 1, 1, 1}
		},
		{	//4를 표시
		{1, 0, 0, 1},
		{1, 0, 0, 1},
		{1, 1, 1, 1},
		{0, 0, 0, 1},
		{0, 0, 0, 1}
		},
		{	//5을 표시
		{1, 1, 1, 1},
		{1, 0 ,0 ,0},
		{1, 1, 1, 1},
		{0, 0, 0, 1},
		{1, 1, 1, 1}
		},
		{	//6을 표시
		{1, 1, 1, 1},
		{1, 0, 0, 0},
		{1, 1, 1, 1},
		{1, 0, 0, 1},
		{1, 1, 1, 1}
		},
		{	//7을 표시
		{1, 1, 1, 1},
		{1, 0, 0, 1},
		{0, 0, 0, 1},
		{0, 0, 0, 1},
		{0, 0, 0, 1}
		},
		{	//8을 표시
		{1, 1, 1, 1},
		{1, 0, 0, 1},
		{1, 1, 1, 1},
		{1, 0, 0, 1},
		{1, 1, 1, 1}
		},
		{	//9를 표시
		{1, 1, 1, 1},
		{1, 0, 0, 1},
		{1, 1, 1, 1},
		{0, 0, 0, 1},
		{1, 1, 1, 1}
		}
	};
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 4; j++)
			timearray[i][startnum + j] = numDigits[num][i][j]; // 출력용 시간 배열의 startnum줄 부터 숫자의 값들을 입력
}

void print_time(char timearray[][33]) {
	// 타이머에서 빈칸은 　(ㄱ->한자), 채워진칸은 ■(ㅁ -> 한자)
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 33; j++) {
			if (timearray[i][j]) // 배열에 저장된 값에 따라 ■ 또는 빈칸(　)을 출력함
				printf("■");
			else
				printf("　");
		}
		printf("\n");
	}
}