#include <stdio.h>
#include <stdlib.h>		// 파일 입출력을 실행하기 위해 추가한 헤더 파일
#include <string.h>		// 내용을 저장할 파일의 이름을 문자열의 형태로 입력받기 위한 헤더 파일
#include <windows.h>	// 표준 라이브러리 아니므로 코드 포함 X / system("cls") (클리어)를 실행해주기 위해 추가한 헤더 파일
#include <time.h>		// 알람 기능으로 남은 시간을 표시해주기 위해 추가한 헤더 파일

typedef struct THINGS_TO_DO {		// 해야 할 일을 구조체의 형태로 저장
	int hour;			// 해야 할 일의 수행 시간
	int minute;			// 해야 할 일의 수행 분
	char context[200];	// 해야 할 일의 내용
}th;

typedef struct alarm {		// 해야 할 일을 수행하기까지 남은 시간을 구조체의 형태로 저장
	int lefthour;		// 해야 할 일을 수행하기까지 남은 시각
	int leftminute;		// 해야 할 일을 수행하기까지 남은 분
	int leftsecond;		// 해야 할 일을 수행하기까지 남은 초
	char context[200];	// 해야 할 일의 내용
}ala;

th certain[100] = { 0 };		// 활성화된 플래너의 할 일들의 내용을 저장해주는 전역변수
int num = 0;					// 활성화된 플래너의 할 일들의 개수를 저장해주는 전역변수
void ReadPlanner();			// 텍스트 파일에 저장된 해야 할 일들을 읽어와 출력하는 함수
void WritePlanner();		// 텍스트 파일에 자신이 해야 할 일들을 입력해 플래너를 만드는 함수
void ActivatePlanner(char* filename, th* a);		// ReadPlanner에서 읽은 플래너에 저장된 해야 할 일들을 certain에 저장하고, 그 개수를 num에 저장하는 함수
void TimeAlarm(int num, th* a);		// GetMinute 함수로 구한 certain에 저장된 해야 할 일들을 수행하기까지 남은 시간을 매초 출력해주는 함수(7초동안)
void ArrayStruct(th* a, int num);	// certain에 저장된 해야 할 일들을 시간 순으로 재배열하는 함수
ala GetMinute(th k);		// certain에 저장된 해야 할 일들의 수행까지 남은 시간을 ala 구조체의 형태로 저장하는 함수

int main() {
	int det = 0;
	do {		// 프로그램을 반복적으로 실행하기 위해 do - while 문 사용
		system("cls");
		printf("1514 최현민의 플래너 작성 프로그램에 오신 것을 환영합니다!~~\n\n");
		printf("수행하고 싶은 작업을 선택해주세요!\n\n");
	doyouknow:
		printf("1 - 플래너 작성하기  |  2 - 플래너 활성화하기  |  3 - 오늘 일정 확인하기  |  4 - 종료 : ");		// 프로그램에서 하고 싶은 작업을 선택
		scanf("%d", &det);		// 하고 싶은 작업을 int형 변수 det에 입력된 값으로 판별
		rewind(stdin);			// ReadPlanner, WritePlanner에서 플래너를 저장하거나 읽어올 파일의 이름을 입력받기 위해 스트림을 비우는 코드(매 함수마다 사용하는 것보다 효율적)
		system("cls");			// 화면을 지움.(clear)
		switch (det) {			// switch 문을 통해 det의 값에 따라 각각 다른 함수를 실행
		case 1:
			WritePlanner();		// 플래너를 작성하는 WritePlanner 함수 실행
			break;
		case 2:
			ReadPlanner();		// 플래너에 저장된 내용을 읽어오는 ReadPlanner 함수 실행 -> 함수 끝에 ActivatePlanner 함수 실행
			break;
		case 3:
			TimeAlarm(num, certain);		// 활성화된 플래너의 해야 할 일들까지 남은 시간을 출력해주는 함수 TimeAlarm 실행
			break;
		case 4:
			goto hello;			// 4(종료)가 입력되었을 때에는 do-while 문 바깥에 있는 hello: 로 이동(break 문은 do-while문만 탈출)
		default:
			printf("1~4 사이의 자연수를 입력해주세요.\n\n");
			goto doyouknow;		// det의 값이 1~4 사이의 값이 아닐 경우에는 다시 프로그램에서 하고 싶은 작업을 선택하는 부분으로 이동
		}
	} while (1);
hello:
	printf("프로그램을 이용해주셔서 감사합니다~\n"); // 위의 do - while문에서 4를 입력해 빠져나왔을 경우 프로그램 종료
	return 0;
}

void ReadPlanner() {
	char filename[80];		// 불러올 파일의 이름을 저장할 문자열
helloboy:
	printf("플래너의 내용을 읽으려는 파일의 이름을 입력하세요. : ");
	gets(filename);			// 파일의 이름을 gets 함수로 입력받기
	int size = strlen(filename);
	if (strcmp(&filename[size - 4], ".txt") != 0)		// 파일의 이름의 뒤에 ".txt"가 없는 경우 ".txt"를 추가해주기
		strcpy(&filename[size], ".txt");
	system("cls");		// 화면을 초기화하기
	FILE* fk = fopen(filename, "r");		// 입력받은 파일의 내용을 읽어오기
	if (fk == NULL) {			// 파일을 정상적으로 불러올 수 없는 경우 경고문 출력 & 파일의 이름 다시 입력받기
		system("cls");
		printf("파일이 제대로 열리지 않았습니다.\n");
		printf("다른 파일을 열거나 같은 이름의 텍스트 파일을 생성한 후 프로그램을 다시 실행해주세요.\n");
		goto helloboy;			// 파일의 이름 입력 전으로 이동하여 이름 다시 입력받기
	}
	char c = fgetc(fk);		// 파일에 담겨있는 문자 각각을 문자에 저장해 출력하기
	printf("\n");
	while (c != EOF) {
		printf("%c", c);	// 매 글자마다 반복 & 한 칸 이동
		c = fgetc(fk);
	}
	fclose(fk);				// 불러온 파일 닫기
	int det = 1;			// 플래너 활성화 여부를 담을 int형 변수
	printf("이 플래너를 활성화하시겠습니까?\n");
	printf("1 - 예 | 2 - 아니요 : ");		// det에 1을 입력받았을 때 활성화, 2 입력받았을 때 프로그램 시작 창으로 돌아가기
	scanf("%d", &det);
	if (det == 1)
		ActivatePlanner(filename, certain);	// det가 1인 경우 플래너 활성화(ActivatePlanner 함수 실행)
}

void WritePlanner() {
	char filename[80];		// 불러올 파일의 이름을 저장할 문자열
mynameis:
	printf("플래너를 담으려는 파일의 이름을 입력하세요. : ");
	gets(filename);			// 파일의 이름을 gets 함수로 입력받기
	int size = strlen(filename);
	if (strcmp(&filename[size - 4], ".txt") != 0)		// 파일의 이름의 뒤에 ".txt"가 없는 경우 ".txt"를 추가해주기
		strcpy(&filename[size], ".txt");
	FILE* fk = fopen(filename, "r");	// 입력받은 파일의 내용을 읽어오기
	if (fk == NULL) {			// 파일을 정상적으로 불러올 수 없는 경우 경고문 출력 & 파일의 이름 다시 입력받기
		system("cls");
		printf("파일이 제대로 열리지 않았습니다.\n");
		printf("다른 파일을 열거나 같은 이름의 텍스트 파일을 생성한 후 프로그램을 다시 실행해주세요.\n");
		goto mynameis;			// 파일의 이름 입력 전으로 이동하여 이름 다시 입력받기
	}
	char c = fgetc(fk);		// 파일에 담겨있는 문자 각각을 문자에 저장해 출력하기
	if (c != EOF) {
		int det;			// 플래너의 내용을 덮어쓸 것인지의 여부를 저장하는 int형 변수
		printf("이미 %s에 입력된 내용이 있습니다. 덮어쓰시겠습니까?\n", filename);
		printf("1 - 예 | 2 - 아니요\n");		// det에 1을 입력받았을 때 덮어쓰기, 2 입력받았을 때 프로그램 시작 창으로 돌아가기
		scanf("%d", &det);
		fclose(fk);			// 불러온 파일 닫기
		if (det == 2)
			return;			// 2 입력받았을 때 프로그램 시작 창으로 돌아가기
	}
	system("cls");		// 화면 초기화하기
	FILE* fp = fopen(filename, "w");		// 텍스트를 입력하기 위해 파일 불러오기
	th b;				// 파일에 입력할 플래너의 내용을 구조체의 형태로 입력받기
	int count = 1;		// 몇 번째 해야 할 일인지 알려주는 용도
	printf("플래너에 기입하고 싶은 할 일의 시각과 그 내용을 입력하세요!\n");
	printf("ex) 4 0 수학 프린트 풀기\n");
	printf("플래너 작성을 끝내고 싶을 때에는 0 0 0을 입력해주세요!\n");
	do {
		printf("%d번째 일정: ", count);			// 몇 번째 해야 할 일을 입력하고 있는지 알려줌
		scanf("%d %d", &b.hour, &b.minute);		// 해야 할 일의 시 / 분을 입력받음.
		gets(b.context);				// 해야 할 일의 내용을 입력받음.
		if (b.hour >= 0 && b.hour < 24 && b.minute >= 0 && b.minute < 60) {
			fprintf(fp, "%d %d%s\n", b.hour, b.minute, b.context);		// 입력받은 내용을 텍스트 파일에 저장하기
			count++;		// 해야 할 일의 개수에 1을 추가
		}
		else
			printf("시간은 0시부터 23시, 분은 0분부터 59분까지 입력 가능합니다!\n");		// 범위에 맞지 않는 시 / 분을 입력해주었을 시 경고문 출력
	} while (b.hour != 0 || b.minute != 0 || strcmp(b.context, " 0") != 0);
	fclose(fp); // 불러온 파일 닫기
	system("cls"); // 화면 초기화하기
}

void ActivatePlanner(char* filename, th* a) {
	FILE* fp = fopen(filename, "r");		// 플래너에 있는 내용을 읽어오기 위해 파일 열기
	char c = fgetc(fp);			// 플래너에 있는 내용을 문자별로 fgetc 함수를 이용해 받기
	int i = 0, count = 0, charnum = 0;		// i는 몇 번째 해야 할 일인지를, count는 시 / 분 / 내용 중 무엇을 입력받는지를, charnum은 context에 저장되는 문자가 몇 번째인지를 알려줌.
	while (c != EOF) {
		if (count == 0) {
			if (c == ' ')			// 공백이 있으면 분 입력받아야 한다는 신호
				count++, c = fgetc(fp);
			else
				a[i].hour = a[i].hour * 10 + c - 48;		// 각 문자별로 기존의 hour값에 10을 곱해준 후 텍스트에 저장된 숫자 더해주기(-48은 아스키코드 때문)
		}
		if (count == 1) {
			if (c == ' ')			// 공백이 있으면 내용 입력받아야 한다는 신호
				count++, c = fgetc(fp);
			else
				a[i].minute = a[i].minute * 10 + c - 48;	// 각 문자별로 기존의 minute값에 10을 곱해준 후 텍스트에 저장된 숫자 더해주기(-48은 아스키코드 때문)
		}
		if (count == 2) {
			if (c == '\n' && (a[i].hour != 0 || a[i].minute != 0 || a[i].context != "0")) {		// 개행 문자가 있거나 파일에 '0 0 0'이 입력되어 있으면 내용 입력 종료
				printf("%d %d %s\n", a[i].hour, a[i].minute, a[i].context);		// 파일에 저장되어 있었던 내용 출력하기
				count = 0, charnum = 0, i++;		// count & charnum 변수 초기화 및 i, 즉 해야 할 일의 개수에 1 더해주기
				goto hello;		// 같은 과정 반복
			}
			a[i].context[charnum] = c;		// context 문자열에 파일에 저장되어 있는 내용 문자별로 저장하기
			charnum++;
		}
	hello:
		c = fgetc(fp);
	}
	ArrayStruct(a, i);		// 해야 할 일들의 구조체를 시간 순서대로 배열해주는 함수
	num = i;		// 해야 할 일들의 개수를 전역변수 num에 저장
	TimeAlarm(i, a);		// 해야 할 일들까지 남은 시간을 초별로 출력해주는 함수
}

void ArrayStruct(th* a, int num) {
	for (int i = 0; i < num - 1; i++) {
		for (int j = i + 1; j < num; j++) {
			int imin = (a[i].hour) * 60 + a[i].minute, jmin = (a[j].hour) * 60 + a[j].minute;	// 해야 할 일들의 시각을 분의 형태로 변환
			if (imin > jmin) {		// 앞선 구조체의 시각이 뒤따라오는 구조체의 시각보다 느릴 경우 자리 바꾸어주기
				th temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}

void TimeAlarm(int num, th* a) {
	ala now[100];			// 시간이 얼마나 남았는지 정보를 담아주는 구조체
	for (int i = 0; i < 7; i++) {		// 7초동안 반복하기
		system("cls");		// 화면 초기화하기
		for (int j = 1; j < num; j++) {
			now[j] = GetMinute(a[j]);	// 각 해야 할 일까지 얼마나 많은 시간이 남았는지를 저장해주는 함수
			if (now[j].lefthour != -1)	// lefthour의 값이 -1인지 아닌지를 통해 일정 수행 시각이 지났는지 여부 판단
				printf("'%s' 일정까지 %d시 %d분 %d초 남았습니다.\n", now[j].context, now[j].lefthour, now[j].leftminute, now[j].leftsecond);	// 남은 시간 및 내용 출력
			else
				printf("'%s' 일정은 이미 끝났습니다.\n", now[j].context);		// 일정 수행 시각이 지나갔음을 알려주는 문구
		}
		Sleep(1000);// 1초동안 출력 상태 유지
	}
	system("cls");	// 화면 초기화하기
}

ala GetMinute(th k) {
	ala res = { 0 };		// 결과값으로 반환할 구조체
	time_t timer = time(NULL);
	struct tm* t = localtime(&timer);// 현재의 시각을 담고 있는 time_t 구조체
	int alarmsec = 0, nowsec = 0;
	alarmsec = 3600 * k.hour + 60 * k.minute, nowsec = (t->tm_hour) * 3600 + (t->tm_min) * 60 + t->tm_sec;	// 현재 시각과 해야 할 일의 수행 시각을 초로 변환
	int sec = alarmsec - nowsec; // alarmsec와 nowsec의 차 저장하는 int형 변수
	if (sec > 0)		// 해야 할 일의 수행 시각이 현재 시각보다 앞설 경우
		res.lefthour = sec / 3600;
	else		// 현재 시각이 해야 할 일의 수행 시각보다 앞설 경우
		res.lefthour = -1;		// lefthour에 -1을 저장하여 이를 나타내기
	res.leftminute = (sec % 3600) / 60;	// leftminute에 sec를 3600으로 나눈 나머지를 60으로 나눈 몫, 즉 분 저장
	res.leftsecond = sec % 60;		// leftsecond에 sec를 60으로 나눈 나머지, 즉 초 저장
	strcpy(res.context, k.context);	// res.context에 파일에 저장되어 있었던 할 일의 내용을 strcpy 함수로 저장
	return res;		// res 반환하기
}