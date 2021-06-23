#include<stdio.h>
#include<direct.h>
#include<time.h>
#include<string.h>
#include<windows.h>
#include<memory.h>
#define MOD 93269117
#define max(a,b) ((a>b)?a:b)
void call_main();
void book_menu();
void mem_menu();
void book_in();
void book_del();
void book_find();
void find_mem();
void mem_in();
void get_black();
void show_all_lend();
typedef struct ab {
	char title[51], genre[51], author[51];
	int count, state[2];
}book;
typedef struct ab2 {
	char name[51]; int age, gender, ad_year, ad_mon, ad_day;
}member;
int get_path(int code, book tmp, int mode);
int get_path2(int code, member tmp, int mode);
int check_form(char* stmp);
int get_hashing(char* d);
int return_code(char* d);
void lend();
int main()
{
	call_main();
	system("cls");
	printf("도서관 관리 프로그램을 종료합니다.\n****C 드라이브의 LibSave 폴더는 본 프로그램의 저장 폴더입니다. 삭제하실 경우 저장된 데이터가 모두 삭제되므로 주의하십시오.****");
	return 0;
}
inline void call_main()
{
	char path[] = "C:\\LibSave";
	mkdir(path);
	//C 폴더에 LibSave 폴더 제작
	while (1)
	{
		system("cls");
		int input;
		printf("------도서관 관리 프로그램------\n");
		printf("1 : 도서 관리\n2 : 회원 관리\n3 : 대출 및 반납\n4 : 종료\n원하시는 메뉴를 선택하십시오:");
		//도서관 관리 프로그램의 메인화면에서 안내
		scanf("%d", &input);
		if (input == 1)book_menu();
		else if (input == 2)mem_menu();
		else if (input == 3)lend();
		else if (input == 4)return;
		else {
			//잘못된 예외 처리
			printf("잘못된 입력입니다.\n");
			Sleep(1000);
		}
	}
}
inline void book_menu()
{

	while (1)
	{
		system("cls");
		int input;
		printf("------도서 관리------\n");
		//도서 관리창에서 안내
		printf("1 : 도서 추가\n2 : 도서 삭제\n3 : 도서 조회\n4 : 뒤로가기\n");
		printf("원하시는 메뉴를 선택하십시오:");
		scanf("%d", &input);
		if (input == 1)book_in();
		else if (input == 2)book_del();
		else if (input == 3)book_find();
		else if (input == 4)return;
		else {
			//잘못된 예외 처리
			printf("잘못된 입력입니다\n");
			Sleep(1000);
		}
	}
}

inline void mem_menu()
{
	while (1)
	{
		system("cls");
		int input;
		printf("------회원 관리------\n");
		//회원 관리창에서 안내
		printf("1 : 회원 추가\n2 : 회원 조회\n3 : 블랙 리스트 확인\n4 : 도서 대출 기록 조회\n5 : 뒤로가기\n");
		printf("원하시는 메뉴를 선택하십시오:");
		scanf("%d", &input);
		if (input == 1)mem_in();
		else if (input == 2)find_mem();
		else if (input == 3)get_black();
		else if (input == 4)show_all_lend();
		else if (input == 5)return;
		else {
			//잘못된 예외 처리
			printf("잘못된 입력입니다\n");
			Sleep(1000);
		}
	}
	system("pause");
}
inline void find_mem()
{
	system("cls");
	char path[100001] = "C:\\LibSave\\", tmpp[100001];
	int code = 0, i;
	printf("조회하고자 하는 회원의 관리번호를 입력하십시오.(이름으로 검색하기를 원하면 아무 문자나): ");
	//조회하고자 하는 회원의 관리번호를 입력받는다.
	scanf("%s", tmpp);
	//관리번호의 첫자리가 0일 경우가 존재하므로 %s로 입력 받음
	code = return_code(tmpp);
	//정수로 변환
	int code_2 = code;
	if (code != -1) {
		for (i = 11; i < 11 + strlen(tmpp); i++, code /= 10)path[i] = code % 10 + '0';
		path[i] = '-'; path[i + 1] = 'P'; path[i + 2] = '.'; path[i + 3] = 't'; path[i + 4] = 'x'; path[i + 5] = 't';
		//회원의 정보를 저장하고 있는 파일의 경로 지정
		if (access(path, 00) == -1) {
			//존재하지 않을시 안내
			printf("존재하지 않는 관리번호입니다.");
			Sleep(1000); return;
		}
		FILE* now = fopen(path, "r");
		member tmp; int cnt;
		//조회 정보 출력
		fscanf(now, "%s %d %d %d %d %d %d %d", tmp.name, &tmp.age, &tmp.gender, &tmp.ad_year, &tmp.ad_mon, &tmp.ad_day, &cnt);
		printf("----회원 조회 정보----\n");
		printf("이름 : %s\n", tmp.name);
		printf("나이 : %d\n", tmp.age);
		printf("성별 : %s\n", tmp.gender == 1 ? "남성" : "여성");
		printf("등록일 : %d.%d.%d\n", tmp.ad_year, tmp.ad_mon, tmp.ad_day);
		printf("연체기록 : %d\n", cnt);
		printf("관리번호 : ");
		for (int k = strlen(tmpp) - 1; k >= 0; k--)printf("%c", tmpp[k]);
		printf("\n");
		fclose(now);
		path[i] = '-'; path[i + 1] = 'P'; path[i + 2] = 'L'; path[i + 3] = '.'; path[i + 4] = 't'; path[i + 5] = 'x'; path[i + 6] = 't';
		//회원의 대출 리스트를 저장하고 있는 파일의 경로 지정
		now = fopen(path, "r");
		printf("******대출 리스트******\n");
		//EOF일 때까지 반복하며 목록 출력
		while (1) {
			char tmp[100001], book_code[10001]; int start1, start2, start3, end1, end2, end3;
			memset(tmp, sizeof(tmp), '\0');
			memset(book_code, sizeof(book_code), '\0');
			if (fscanf(now, "%s %d %d %d %d %d %d %s", tmp, &start1, &start2, &start3, &end1, &end2, &end3, book_code) == EOF)break;
			if (tmp[strlen(tmp) - 1] == '^')continue;
			//제목의 마지막 글자가 @, 즉, 반납 된 도서일 경우 pass
			tmp[strlen(tmp) - 1] = '\0';
			printf("제목 : %s | 기한(대출 날짜, 반납 기한) : %d.%d.%d~%d.%d.%d | 도서 관리 번호 : %s\n", tmp, start1, start2, start3, end1, end2, end3, book_code);
		}
		fclose(now);
		printf("\n");
	}
	else {
		member tmp;
		//숫자가 아닌 문자가 관리번호로 들어올 경우 이름을 통해 검색할수 있도록 지원
		printf("모든 입력은 한글을 지원하지 않습니다.공백은 _로 표현하여주십시오.사용가능한 특수문자는 . ? !입니다.\n");
		printf("이름: ");
		scanf("%s", tmp.name);
		if (!check_form(tmp.name)) {
			//입력 형태 검사
			Sleep(1000); return;
		}
		if (!get_path2(get_hashing(tmp.name), tmp, 2)) {
			//검색에 실패한 경우 안내
			printf("검색을 실패하였습니다. 제목과 작가를 다시 확인해주시기 바랍니다.\n");
		}
	}
	system("pause");
}
inline void mem_in()
{
	system("cls");
	member tmp;
	char ntmp[1001];
	//추가할 회원의 정보를 입력
	printf("모든 입력은 한글을 지원하지 않습니다.공백은 _로 표현하여주십시오.사용가능한 특수문자는 . ? !입니다.\n");
	printf("이름:");
	scanf("%s", tmp.name);
	if (check_form(tmp.name));
	else return;
	printf("나이:");
	scanf("%d", &tmp.age);
	printf("성별:(남성 1, 여성 2):");
	scanf("%d", &tmp.gender);
	if (tmp.gender != 1 && tmp.gender != 2) {
		printf("잘못된 입력 입니다.");
		Sleep(1000); return;
	}
	//잘못된 입력 형식 검사
	int code = get_hashing(tmp.name);
	//초기 해시값 생성
	get_path2(code, tmp, 1);
	system("pause");
}
int check_form(char* stmp)
{
	//문자열의 형태가 지정된 형식에 성립되는지 검사
	int length = strlen(stmp);
	for (int i = 0; i < length; i++) {
		if (!((stmp[i] >= 'A' && stmp[i] <= 'Z') || (stmp[i] >= 'a' && stmp[i] <= 'z') || (stmp[i] >= '0' && stmp[i] <= '9') || stmp[i] == '_' || stmp[i] == '!' || stmp[i] == '?' || stmp[i] == '.')) {
			printf("잘못된 입력 형식입니다."); Sleep(1000);
			return 0;
		}
	}
	return 1;
}
int get_hashing(char* d)
{
	//해시값 생성
	long long ans = 0;
	for (int i = 0; i < strlen(d); i++) {
		ans = (ans + (long long)d[i] * 719103 % MOD) % MOD;
		ans = (ans * 129) % MOD;
	}
	ans %= MOD;
	return (int)ans;

}
inline void book_in()
{
	system("cls");
	book tmp;
	char ntmp[1001];
	//추가할 책의 정보를 입력
	printf("모든 입력은 한글을 지원하지 않습니다.공백은 _로 표현하여주십시오.사용가능한 특수문자는 . ? !입니다.\n");
	printf("도서 제목:");
	scanf("%s", ntmp);
	if (check_form(ntmp))strcpy(tmp.title, ntmp);
	else return;
	memset(ntmp, strlen(ntmp), '\0');
	printf("장르:");
	scanf("%s", ntmp);
	if (check_form(ntmp))strcpy(tmp.genre, ntmp);
	else return;
	memset(ntmp, strlen(ntmp), '\0');
	printf("작가:");
	scanf("%s", ntmp);
	if (check_form(ntmp))strcpy(tmp.author, ntmp);
	else return;
	int numbertmp;
	printf("추가할 권수:");
	scanf("%d", &numbertmp);
	if (numbertmp < 0) {
		printf("잘못된 입력입니다."); Sleep(1000); return;
	}
	//잘못된 입력 형식 처리
	tmp.count = numbertmp;
	int code = get_hashing(tmp.title);
	//해시값 생성
	get_path(code, tmp, 1);
	system("pause");
}
inline void book_del()
{
	system("cls");
	char path[100001] = "C:\\LibSave\\", tmpp[100001];
	//삭제하려 하는 책의 관리번호 입력
	printf("삭제하고자 하는 책의 관리번호를 입력하십시오.(제목, 작가를 사용하기를 원하면 아무 문자나):");
	scanf("%s", tmpp);
	int code, i;
	code = return_code(tmpp);
	//정수로 변환
	if (code != -1) {
		for (i = 11; i < 11 + strlen(tmpp); i++, code /= 10)path[i] = code % 10 + '0';
		path[i] = '.'; path[i + 1] = 't'; path[i + 2] = 'x'; path[i + 3] = 't';
		//해당 책의 저장 경로 생성
		if (access(path, 00) == -1) {
			printf("존재하지 않는 관리번호입니다.");
			Sleep(1000); return;
		}
		FILE* now = fopen(path, "r+w");
		book tmp;
		fscanf(now, "%s %s %s %d %d %d", tmp.title, tmp.genre, tmp.author, &tmp.count, &tmp.state[0], &tmp.state[1]);
		int del_cnt;
		//제거할 권수 입력
		printf("제거하실 권수를 입력하십시오(대출 중이 아닌 도서만 제거가능합니다.):");
		scanf("%d", &del_cnt);
		rewind(now);
		//제거 후 정보 업데이트
		fprintf(now, "%s %s %s %d %d %d                                                                                                                          --end", tmp.title, tmp.genre, tmp.author, max(tmp.state[1], tmp.count - del_cnt), max(0, tmp.state[0] - del_cnt), tmp.state[1]);
		fclose(now);
	}
	else {
		//문자가 들어왔을 시, 제목과 작가를 입력받아 처리
		book tmp;
		printf("모든 입력은 한글을 지원하지 않습니다.공백은 _로 표현하여주십시오.사용가능한 특수문자는 . ? !입니다.\n");
		printf("제목: ");
		scanf("%s", tmp.title);
		if (!check_form(tmp.title)) {
			Sleep(1000); return;
		}
		printf("작가: ");
		scanf("%s", tmp.author);
		if (!check_form(tmp.author)) {
			Sleep(1000); return;
		}
		if (!get_path(get_hashing(tmp.title), tmp, 3)) {
			//실패시 안내
			printf("검색을 실패하였습니다. 제목과 작가를 다시 확인해주시기 바랍니다.\n");
		}
	}
	//안내
	printf("****도서 제거후 도서의 재고가 0권일 경우도, 기록은 삭제되지 않으며, 추후 도서 추가 시 할당되어있는 관리번호를 사용합니다.****\n");
	system("pause");
}
inline void book_find()
{
	system("cls");
	char path[100001] = "C:\\LibSave\\", tmpp[100001];
	int code = 0, i;
	//조회하려 하는 책의 관리번호 입력
	printf("조회하고자 하는 책의 관리번호를 입력하십시오.(제목, 작가로 검색하기를 원하면 아무 문자나): ");
	scanf("%s", tmpp);
	code = return_code(tmpp);
	int code_2 = code;
	if (code != -1) {
		for (i = 11; i < 11 + strlen(tmpp); i++, code /= 10)path[i] = code % 10 + '0';
		path[i] = '.'; path[i + 1] = 't'; path[i + 2] = 'x'; path[i + 3] = 't';
		//저장된 책의 정보의 경로 생성
		if (access(path, 00) == -1) {
			//검사
			printf("존재하지 않는 관리번호입니다.");
			Sleep(1000); return;
		}
		FILE* now = fopen(path, "r");
		book tmp;
		//조회 결과 출력
		fscanf(now, "%s %s %s %d %d %d", tmp.title, tmp.genre, tmp.author, &tmp.count, &tmp.state[0], &tmp.state[1]);
		printf("----책 조회 정보----\n");
		printf("제목 : %s\n", tmp.title);
		printf("장르 : %s\n", tmp.genre);
		printf("작가 : %s\n", tmp.author);
		printf("보관 권수 : %d권(대출 가능:%d권, 대출 중:%d권)\n", tmp.count, tmp.state[0], tmp.state[1]);
		printf("관리 번호 : %s\n", tmpp);
		fclose(now);
	}
	else {
		book tmp;
		//문자가 들어올 경우 제목과 작가를 입력받아 처리
		printf("모든 입력은 한글을 지원하지 않습니다.공백은 _로 표현하여주십시오.사용가능한 특수문자는 . ? !입니다.\n");
		printf("제목: ");
		scanf("%s", tmp.title);
		if (!check_form(tmp.title)) {
			Sleep(1000); return;
		}
		printf("작가: ");
		scanf("%s", tmp.author);
		if (!check_form(tmp.author)) {
			Sleep(1000); return;
		}
		if (!get_path(get_hashing(tmp.title), tmp, 2)) {
			printf("검색을 실패하였습니다. 제목과 작가를 다시 확인해주시기 바랍니다.\n");
		}
	}
	system("pause");
}
int get_path(int code, book tmp, int mode)
{
	int line = 0, mem = 19, code_2 = code;
	//기본 해시값을 바탕으로 시작 경로 생성
	char path[10001] = "C:\\LibSave\\";
	for (int i = 11; i <= 18; i++, code /= 10)path[i] = code % 10 + '0';
	if (mode < 4) { path[19] = '.'; path[20] = 't'; path[21] = 'x'; path[22] = 't'; }

	book justtmp;
	while (1)
	{
		int i;
		if ((mode == 1) && access(path, 00) != 0)break;
		//mode=1->책 추가, 즉, 사용가능한 경로가 발견되면 break;
		else if ((mode == 2 || mode == 3) && access(path, 00) != 0)return 0;
		//mode=2->책 조회, mode=3->책 삭제, 즉, 더이상 확인해야하는 정보가 존재하지 않을 시 break;
		else {
			FILE* now = fopen(path, "r+w");
			memset(justtmp.title, sizeof(justtmp.title), '\0');
			memset(justtmp.title, sizeof(justtmp.genre), '\0');
			memset(justtmp.title, sizeof(justtmp.author), '\0');
			fscanf(now, "%s %s %s %d %d %d", justtmp.title, justtmp.genre, justtmp.author, &justtmp.count, &justtmp.state[0], &justtmp.state[1]);
			//추가,삭제 혹은 조회하고 싶은 책과 현재 경로의 정보가 일치하는지 확인
			if (mode == 1 && !strcmp(justtmp.title, tmp.title) && !strcmp(justtmp.author, tmp.author) && !strcmp(justtmp.genre, tmp.genre)) {
				//권수만 변경
				justtmp.count += tmp.count; justtmp.state[0] += tmp.count;
				rewind(now);
				fprintf(now, "%s %s %s %d %d %d                                                                                                                          --end", justtmp.title, justtmp.genre, justtmp.author, justtmp.count, justtmp.state[0], justtmp.state[1]);
				fclose(now);
				return 0;
			}
			else if (mode == 2 && !strcmp(justtmp.title, tmp.title) && !strcmp(justtmp.author, tmp.author))
			{
				//조회 정보 출력
				printf("----책 조회 정보----\n");
				printf("제목 : %s\n", justtmp.title);
				printf("장르 : %s\n", justtmp.genre);
				printf("작가 : %s\n", justtmp.author);
				printf("보관 권수 : %d권(대출 가능:%d권, 대출 중:%d권)\n", justtmp.count, justtmp.state[0], justtmp.state[1]);
				printf("관리 번호 : %d\n", code_2);
				fclose(now);
				return 1;
			}
			else if (mode == 3 && !strcmp(justtmp.title, tmp.title) && !strcmp(justtmp.author, tmp.author)) {
				//제거할 권수 입력 받고 제거
				printf("제거하실 권수를 입력하십시오(대출 중이 아닌 도서만 제거가능합니다.):");
				int del_cnt;
				rewind(now);
				scanf("%d", &del_cnt);
				fprintf(now, "%s %s %s %d %d %d                                                                                                                          --end", justtmp.title, justtmp.genre, justtmp.author, max(justtmp.state[1], justtmp.count - del_cnt), max(0, justtmp.state[0] - del_cnt), justtmp.state[1]);
				fclose(now);
				return 1;
			}
			fclose(now);
		}
		line++;
		int line_2 = line;
		//다음 경로 생성
		path[mem] = path[mem + 1] = path[mem + 2] = path[mem + 3] = '\0';
		for (i = 19; line_2; i++, line_2 /= 10)path[i] = line_2 % 10 + '0';
		if (mode < 4) { path[i] = '.'; path[i + 1] = 't'; path[i + 2] = 'x'; path[i + 3] = 't'; }
		else { path[i] = '-'; path[i + 1] = 'P'; path[i + 2] = '.'; path[i + 3] = 't'; path[i + 4] = 'x'; path[i + 5] = 't'; }
		mem = i;
	}
	//관리 번호 부여
	printf("관리 번호 ");
	for (int i = mem - 1; i >= 11; i--)printf("%c", path[i]);
	printf("가 부여되었습니다.\n");
	FILE* now2 = fopen(path, "w");
	if (mode == 1)fprintf(now2, "%s %s %s %d %d 0                                                                                                                          --end", tmp.title, tmp.genre, tmp.author, tmp.count, tmp.count);
	fclose(now2);
	return 0;
}
int get_path2(int code, member tmp, int mode)
{
	int line = 0, mem = 19, code_2 = code, i;
	//시작 경로 지정
	char path[10001] = "C:\\LibSave\\", memcode[1001];
	for (i = 11; i <= 18; i++, code /= 10)path[i] = memcode[i - 11] = code % 10 + '0';
	path[19] = '-'; path[20] = 'P';
	path[21] = '.'; path[22] = 't'; path[23] = 'x'; path[24] = 't';
	int check = 0, chk = 0;
	member justtmp;
	while (1)
	{
		if (access(path, 00) != 0)break;
		//더이상 체인이 이어지지 않는 다면 break;
		else {
			int cnt, count;
			FILE* now = fopen(path, "r");
			memset(justtmp.name, sizeof(justtmp.name), '\0');
			fscanf(now, "%s %d %d %d %d %d %d", justtmp.name, &justtmp.age, &justtmp.gender, &justtmp.ad_year, &justtmp.ad_mon, &justtmp.ad_day, &count);
			//조회하고 싶은 사용자와 현재 경로의 정보가 같은지 확인
			if (mode == 2 && !strcmp(justtmp.name, tmp.name))
			{
				//관리번호로 입력받았을때와 동일
				if (!chk) {
					chk = 1; printf("%s의 이름을 가진 사용자의 총 조회 결과입니다.\n", tmp.name);
				}
				printf("---------------------------------------\n\n");
				printf("이름 : %s\n", justtmp.name);
				printf("나이 : %d\n", justtmp.age);
				printf("성별 : %s\n", justtmp.gender == 1 ? "남성" : "여성");
				printf("등록일 : %d.%d.%d\n", justtmp.ad_year, justtmp.ad_mon, justtmp.ad_day);
				printf("연체기록 : %d번\n", count);
				printf("관리번호 : ");
				for (int k = strlen(memcode) - 1; k >= 0; k--)printf("%c", memcode[k]);
				printf("\n");
				fclose(now);
				path[i + 2] = 'L'; path[i + 3] = '.'; path[i + 4] = 't'; path[i + 5] = 'x'; path[i + 6] = 't';

				now = fopen(path, "r");
				printf("******대출 리스트******\n");
				while (1) {
					char tmp[100001], bookcodep[1001]; int start1, start2, start3, end1, end2, end3, book_code;
					memset(tmp, sizeof(tmp), '\0');
					memset(bookcodep, sizeof(bookcodep), '\0');
					if (fscanf(now, "%s %d %d %d %d %d %d %s", tmp, &start1, &start2, &start3, &end1, &end2, &end3, bookcodep) == EOF)break;
					if (tmp[strlen(tmp) - 1] == '^')continue;
					tmp[strlen(tmp) - 1] = '\0';
					printf("제목 : %s | 기한(대출 날짜, 반납 기한) : %d.%d.%d~%d.%d.%d | 도서 관리 번호 : %s\n", tmp, start1, start2, start3, end1, end2, end3, bookcodep);
				}
				printf("\n");
				check = 1;
				fclose(now);
			}
			fclose(now);
		}

		line++;
		//다음 경로 생성
		int line_2 = line;
		path[mem] = path[mem + 1] = path[mem + 2] = path[mem + 3] = '\0';
		for (i = 19; line_2; i++, line_2 /= 10)path[i] = memcode[i - 11] = line_2 % 10 + '0';
		path[i] = '-'; path[i + 1] = 'P'; path[i + 2] = '.'; path[i + 3] = 't'; path[i + 4] = 'x'; path[i + 5] = 't';
		mem = i;
	}
	if (mode == 2)return check;
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	//관리 번호 부여
	printf("관리 번호 ");
	for (int i = mem - 1; i >= 11; i--)printf("%c", path[i]);
	printf("가 부여되었습니다.\n");
	FILE* now2 = fopen(path, "w");
	fprintf(now2, "%s %d %d %d %d %d 0                                                                                                                          --end", tmp.name, tmp.age, tmp.gender, tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
	fclose(now2);
	return 0;
}
int return_code(char* d)
{
	//문자열 코드를 정수로 변환
	int code = 0;
	for (int i = 0; i < strlen(d); i++) {
		if (!(d[i] >= '0' && d[i] <= '9')) {
			code = -1; break;
		}
		code *= 10; code += d[i] - '0';
	}
	return code;
}
inline void lend()
{
	system("cls");
	printf("****도서 대출 및 반납은 이름(혹은 제목과 작가)검색 기능을 제공하지 않습니다. 회원 조회 또는 도서 조회를 통해 관리번호를 조회할수 있습니다.****\n");
	printf("계속 하시겠습니까?(Y/anykey(not Y)");
	char tmp; scanf("%c%c", &tmp, &tmp);
	if (tmp != 'Y')return;
	int i;
	char mem_code[10001], book_code[10001];
	int memcode, bookcode;
	printf("대출자의 관리번호:");
	scanf("%s", mem_code);
	memcode = return_code(mem_code);
	printf("도서 관리번호:");
	scanf("%s", book_code);
	bookcode = return_code(book_code);
	printf("유형(대출=1,반납=2):");
	int bookcode_2 = bookcode, memcode_2 = memcode;
	int type;
	scanf("%d", &type);
	char path_mem[100001] = "C:\\LibSave\\", path_book[100001] = "C:\\LibSave\\", path_booklist[100001] = "C:\\LibSave\\";
	for (i = 11; i < 11 + strlen(book_code); i++, bookcode /= 10)path_book[i] = bookcode % 10 + '0';
	path_book[i] = '.'; path_book[i + 1] = 't'; path_book[i + 2] = 'x'; path_book[i + 3] = 't';
	for (i = 11; i < 11 + strlen(mem_code); i++, memcode /= 10) {
		path_mem[i] = memcode % 10 + '0';
		path_booklist[i] = memcode % 10 + '0';
	}
	path_mem[i] = '-'; path_mem[i + 1] = 'P'; path_mem[i + 2] = '.'; path_mem[i + 3] = 't'; path_mem[i + 4] = 'x'; path_mem[i + 5] = 't';
	path_booklist[i] = '-'; path_booklist[i + 1] = 'P'; path_booklist[i + 2] = 'L'; path_booklist[i + 3] = '.'; path_booklist[i + 4] = 't'; path_booklist[i + 5] = 'x'; path_booklist[i + 6] = 't';
	//대출자의 관리번호와 도서 관리번호, 유형을 입력받고 기본 경로 지정
	if (access(path_book, 00) != 0) {
		FILE* test = fopen(path_book, "r");
		fprintf(test, "this is test");
		printf("존재하지 않는 도서입니다.\n"); Sleep(1000); return;
	}
	if (access(path_mem, 00) != 0) {
		printf("존재하지 않는 회원입니다.\n"); Sleep(1000); return;
	}
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	if (type == 1) {
		FILE* books = fopen(path_book, "r+w");
		book tmp;
		fscanf(books, "%s %s %s %d %d %d", tmp.title, tmp.genre, tmp.author, &tmp.count, &tmp.state[0], &tmp.state[1]);
		if (tmp.state[0] == 0) {
			printf("현재 대출중이지 않는 해당 도서가 존재하지 않습니다.\n");
			Sleep(1000); return;
		}
		//대출 일 경우 반납 권수 추가
		rewind(books);
		fprintf(books, "%s %s %s %d %d %d                                                                                                                          --end", tmp.title, tmp.genre, tmp.author, tmp.count, tmp.state[0] - 1, tmp.state[1] + 1);
		fclose(books);
		FILE* meml = fopen(path_booklist, "a+");
		int year, mon, day;
		printf("반납 기한 설정:(YYYY MM DD):");
		scanf("%d %d %d", &year, &mon, &day);
		//  fseek(meml,-1,SEEK_END);
		fprintf(meml, "%s@ %04d %02d %02d %04d %02d %02d %s\n", tmp.title, tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, year, mon, day, book_code);
		fclose(meml);
		printf("대출 성공\n");
		//.LP 파일에 대출 기록
	}
	else {
		int chk = 0;
		FILE* books = fopen(path_book, "r+w");
		book tmp;
		fscanf(books, "%s %s %s %d %d %d", tmp.title, tmp.genre, tmp.author, &tmp.count, &tmp.state[0], &tmp.state[1]);
		if (tmp.state[1] == 0) {
			printf("현재 대출중인 해당 도서가 존재하지 않습니다.\n");
			Sleep(1000); return;
		}
		fclose(books);
		FILE* meml = fopen(path_booklist, "r+t");
		while (1)
		{
			//해당 사용자의 대출 기록중 반납하고자 하는 책을 검색
			char title[1001], code[1001]; int year, mon, day, year2, mon2, day2;
			if (fscanf(meml, "%s %d %d %d %d %d %d %s", title, &year, &mon, &day, &year2, &mon2, &day2, code) == EOF)break;
			if (title[strlen(title) - 1] == '^')continue;
			if (!strcmp(code, book_code)) {
				char tmp; int cnt;
				fseek(meml, -(strlen(book_code) + 16 + 8), SEEK_CUR);
				fprintf(meml, "^");
				chk = 1; book stmp;
				books = fopen(path_book, "r+w");
				fscanf(books, "%s %s %s %d %d %d %d %d", stmp.title, stmp.genre, stmp.author, &stmp.count, &stmp.state[0], &stmp.state[1]);
				rewind(books);
				fprintf(books, "%s %s %s %d %d %d                                                                                                                          --end", stmp.title, stmp.genre, stmp.author, stmp.count, stmp.state[0] + 1, stmp.state[1] - 1);
				fclose(books);
				FILE* memm = fopen(path_mem, "r+w");
				member tmpp;
				fscanf(memm, "%s %d %d %d %d %d %d", tmpp.name, &tmpp.age, &tmpp.gender, &tmpp.ad_year, &tmpp.ad_mon, &tmpp.ad_day, &cnt);
				//책의 대출중 권수와 대출 가능 권수를 변경하고, 대출기록에서 해당 도서 반납 처리
				if (year2 < tm.tm_year + 1900 || (year2 == tm.tm_year + 1900 && mon2 < tm.tm_mon + 1) || (year2 == tm.tm_year + 1900 && mon2 == tm.tm_mon + 1 && day2 < tm.tm_mday)) {
					//연체일 경우, 반납자의 연체 횟수 증가 및 블랙리스트 심사
					printf("연체 도서입니다.\n");
					rewind(memm);
					fprintf(memm, "%s %d %d %d %d %d %d                                                                                                                          --end", tmpp.name, tmpp.age, tmpp.gender, tmpp.ad_year, tmpp.ad_mon, tmpp.ad_day, cnt + 1);
					if (cnt == 6) {
						FILE* black = fopen("C:\\LibSave\\BlackList.txt", "a+");
						fprintf(black, "%s\n", tmpp.name);
						fclose(black);
					}
				}
				fclose(memm);
				break;
			}
		}
		fclose(meml);
		if (chk)printf("반납 성공\n");
		else printf("해당 도서의 대출 기록이 존재하지 않습니다.\n");
	}
	system("pause");
}
inline void get_black()
{
	system("cls");
	//블랙 리스트 출력
	printf("연체기록이 7번 이상인 블랙리스트를 출력합니다.\n---------------------------------------\n");
	FILE* black = fopen("C:\\LibSave\\BlackList.txt", "r");
	while (1)
	{
		char tmp1[10001];
		memset(tmp1, sizeof(tmp1), 0);
		if (fscanf(black, "%s", tmp1) == EOF)break;
		printf("%s\n", tmp1);
	}
	printf("---------------------------------------\n");
	system("pause");
	return;
}
void show_all_lend()
{
	//대출 기록 출력
	system("cls");
	char path[100001] = "C:\\LibSave\\", tmpp[1001];
	int code = 0, i;
	printf("대출기록 조회를 원하는 회원의 관리번호를 입력하십시오 : ");
	scanf("%s", tmpp);
	code = return_code(tmpp);
	for (i = 11; i < 11 + strlen(tmpp); i++, code /= 10)path[i] = code % 10 + '0';
	path[i] = '-'; path[i + 1] = 'P'; path[i + 2] = 'L'; path[i + 3] = '.'; path[i + 4] = 't'; path[i + 5] = 'x'; path[i + 6] = 't';
	if (access(path, 00) == -1) {
		printf("존재하지 않는 관리번호입니다.");
		Sleep(1000); return;
	}
	printf("-----------------------------------\n");
	FILE* now = fopen(path, "r");
	while (1)
	{
		char title[1001], code[1001]; int sy, sm, sd, fy, fm, fd;
		memset(title, sizeof(title), 0);
		memset(code, sizeof(code), 0);
		if (fscanf(now, "%s %d %d %d %d %d %d %s", title, &sy, &sm, &sd, &fy, &fm, &fd, code) == EOF)break;
		title[strlen(title) - 1] = '\0';
		printf("제목:%s | 대출 기간(대출일, 설정되었던 반납 일)%d.%d.%d~%d.%d.%d | 관리번호 : %s\n", title, sy, sm, sd, fy, fm, fd, code);
	}
	printf("-----------------------------------\n");
	system("pause");
}
