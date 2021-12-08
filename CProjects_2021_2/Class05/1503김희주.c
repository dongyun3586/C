#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include <stdlib.h>

#define MAX_LENGTH 200
#define MAX_CHAR 30
#define MAX_PARAMS 10

enum Mode { FINISH, DECLARE, PRINT, SCAN, IF, SIMPLE_FOR, RAND, SHOW };

typedef struct {
	char name[MAX_CHAR];
	char type[MAX_CHAR];
	char print_type[5];
}Param;

void start(FILE** fp, Param* params[100]);
void declare(FILE** fp, Param* params[100]);
void print(FILE** fp, Param* params[100]);
void scan(FILE** fp, Param* params[100]);
void show_params(Param* params[100]);
void simple_for(FILE** fp, Param* params[100]);
void if_else(FILE** fp, Param* params[100]);
void randnum(FILE** fp, Param* params[100]);
void print_tap(FILE** fp);
char* print_type(char type[MAX_CHAR]);
int check_paramName(char param[MAX_CHAR], Param* params[100]);
int check_param(char param[MAX_CHAR], Param* params[100]);
int check_formula(char param[MAX_CHAR], Param* params[100], char print_type[5]);
int check_formula2(char param[MAX_CHAR], Param* params[100]);
int compare_type(char a[5], char b[5]);
void choose_mode(FILE** fp, Param* params[100], int a);

int Nparam = 0;
int tap = 0;


int main()
{
	char content[MAX_LENGTH];
	FILE* code;
	code = fopen("code.txt", "w");

	Param* params[100];  //변수 저장할 변수

	for (int i = 0; i < sizeof(params) / sizeof(Param*); i++)
		params[i] = malloc(sizeof(Param));     //구조체에 메모리 할당해야함!!!!!

	start(&code, params);

	fclose(code);

	Sleep(1000);
	system("cls");
	printf("\n\n-------생성된 코드-------\n\n");

	code = fopen("code.txt", "r");
	while (fgets(content, sizeof(content), code) != NULL) {
		puts(content);
	}

	return 0;
}

void start(FILE** fp, Param* params[100]) {
	char content[MAX_LENGTH];

	//헤더파일, 메인함수
	fprintf(*fp, "#include <stdio.h>\n");
	fprintf(*fp, "#include <stdlib.h>\n");
	fprintf(*fp, "#include <time.h>\n\n");
	fprintf(*fp, "int main()\n{\n");
	tap++;
	print_tap(fp);
	fprintf(*fp, "srand(time(NULL));\n\n");  //rand로 옮기기???

	printf("코드자동생성기\n\n");

	choose_mode(fp, params, 0);

	fprintf(*fp, "\n");
	print_tap(fp);
	fprintf(*fp, "return 0;\n");
	tap--;
	fprintf(*fp, "}");
}

//변수 이름, 타입 기억해두기!!!
//연속해서 쓸수 있게 만들기
void declare(FILE** fp, Param* params[100]) {
	char param[MAX_CHAR];
	char type[MAX_CHAR];
	char type_arr[4][MAX_CHAR] = { "int", "float", "double", "char" };
	int ch;

	while (1) {
		printf("\n변수선언하기\n\n");
		printf("변수 타입(정수형 : int, 실수형 : float 또는 double, 단일문자 : char 등등)\n: ");
		scanf("%s", type);
		//숫자로 바꿔서?

		int t = 0;
		for (int i = 0; i < 4; i++) {
			if (strcmp(type, type_arr[i]) == 0) {
				t = 1;
				break;
			}
		}
		if (t) {
			print_tap(fp);
			fprintf(*fp, "%s ", type);

			while (1) {
				printf("변수 이름 : ");
				scanf("%s", param);
				//변수이름이 숫자로 시작하거나 함수이름이면 안됨....

				if (check_paramName(param, params)) { //사용가능한 이름인지 확인
					fprintf(*fp, "%s", param);

					//구조체에 저장
					strcpy(params[Nparam]->name, param);
					strcpy(params[Nparam]->type, type);
					strcpy(params[Nparam]->print_type, print_type(type));
					Nparam++;

					printf("변수 선언을 완료했습니다.\n");

					break;
				}
				else {
					Sleep(500);
					system("cls");
				}

			}
			fprintf(*fp, ";\n");

			printf("(계속 선언하려면 1, 변수 선언을 끝내려면 0) : ");
			scanf("%d", &ch);
			if (!ch) break;
			Sleep(500);
			system("cls");
		}
		else {
			printf("잘못된 타입입니다.\n");
			Sleep(500);
			system("cls");
		}

	}
}


int check_paramName(char param[MAX_CHAR], Param* params[100]) {
	char impossible[32][MAX_CHAR] = { "auto", "break", "case", "char", "const",	"continue",	"default",
		"do", "double", "else",	"enum",	"extern", "float", "for", "goto", "if", "int", "long", "register",
		"return", "short", "signed", "sizeof", "static", "struct", "switch", "typedef",	"union", "unsigend"
		"void", "volatile", "while" };
	int posi;

	posi = check_param(param, params);
	if (posi != -1) {
		printf("이미 존재하는 변수입니다.\n\n");
		return 0;
	}

	if (isdigit(param[0])) {
		printf("변수이름의 첫글자는 숫자로 시작할 수 없습니다.\n\n");
		return 0;
	}

	for (int i = 0; param[i] != '\0'; i++) {
		if (!isalpha(param[i]) && !isdigit(param[i]) && param[i] != ' ') {
			printf("변수이름은 영문자, 숫자, _로만 구성될 수 있습니다.\n\n");
			return 0;
		}
	}

	for (int i = 0; i < 32; i++) {
		if (strcmp(param, impossible[i]) == 0) {
			printf("사용할 수 없는 변수이름입니다.\n\n");
			return 0;
		}
	}

	return 1;  //사용가능한 이름
}

void print(FILE** fp, Param* params[100]) {
	char content[MAX_LENGTH];
	char print_type[5];
	char p[MAX_LENGTH];
	int used_param[MAX_PARAMS];
	char used_params[MAX_PARAMS][MAX_CHAR];
	int a, b = 0;
	int posi;
	int t;

	rewind(stdin);

	printf("출력하기\n\n");
	printf("출력하고 싶은 내용을 입력하세요\n변수를 출력하려면 {변수이름}\n:");

	fgets(content, sizeof(content), stdin);
	content[strlen(content) - 1] = '\0';  //\n 없애기

	print_tap(fp);
	fprintf(*fp, "printf(\"");
	for (int i = 0; content[i] != '\0'; i++) {
		//{변수이름}
		if (content[i] == '{') {
			a = 0;
			for (int s = i + 1; content[s] != '\0'; s++) {
				if (content[s] == ' ') continue;

				if (content[s] == '}') {
					p[a] = '\0';
					t = check_formula(p, params, print_type);
					if (t) {                             //맞는 수식,변수이름인지 확인
						fprintf(*fp, "%s", print_type);  //서식문자?(%d, %f등등) 출력
						strcpy(used_params[b++], p);     //사용한 목록에 저장(나중에 출력 위해)
					}

					//posi = check_param(p, params);  
					//if (posi != -1) {  //변수리스트에 있는지 확인
					//	fprintf(*fp, "%s", params[posi]->print_type);  //서식문자?(%d, %f등등) 출력
					//	used_param[b++] = posi;    //사용된 변수 목록에 저장
					//}

					i = s;
					break;
				}
				else {
					p[a++] = content[s];   //p에 변수이름 복사
				}
			}
		}
		else {
			fprintf(*fp, "%c", content[i]);  //파일에 내용 출력
		}
	}
	fprintf(*fp, "\\n\"");

	for (int i = 0; i < b; i++) {
		fprintf(*fp, ", %s", used_params[i]);
	}

	//for (int i = 0; i < b; i++) {
	//	fprintf(*fp, ", %s", params[used_param[i]]->name);  //printf 뒷부분 변수 출력
	//}
	fprintf(*fp, ");\n");

	printf("코드생성을 완료했습니다.");
	Sleep(500);
	//fprintf(*fp, "printf(\"%s\\n\");\n", content);
}

void scan(FILE** fp, Param* params[100]) {
	char param[MAX_CHAR];
	int posi = 0;
	while (1) {
		printf("\n입력받을 변수 이름 : ");
		scanf("%s", param);


		posi = check_param(param, params);
		if (posi != -1) {  //변수리스트에 있는지 확인
			break;
		}
		else
			printf("없는 변수 입니다.\n");
	}

	print_tap(fp);
	fprintf(*fp, "printf(\"%s 입력 : \");\n", param);
	print_tap(fp);
	fprintf(*fp, "scanf(\"%s\", &%s);\n", params[posi]->print_type, param); //scanf문 출력

	printf("코드생성을 완료했습니다.");
	Sleep(500);
}

void simple_for(FILE** fp, Param* params[100]) {
	int start, end, plus;

	printf("\n간단한 반복문\n\n");

	while (1) {
		printf("시작 범위 : ");
		scanf("%d", &start);
		printf("끝 범위 : ");
		scanf("%d", &end);
		printf("증가 또는 감소할 수\n(예 : 1씩 증가하려면 1, 2씩 감소하려면 -2 입력) : ");
		scanf("%d", &plus);

		if (plus == 0) {
			printf("무한반복문 입니다.\n다시 입력해 주세요");
		}
		else if ((plus > 0 && start > end) || (plus < 0 && start < end)) {
			printf("반복 범위가 잘못되었습니다.\n");
		}
		else {
			break;
		}
	}
	print_tap(fp);
	fprintf(*fp, "for (int i = %d; i <= %d; i += %d) {\n", start, end, plus);
	tap++;

	//i 변수리스트에 추가
	strcpy(params[Nparam]->name, "i");
	strcpy(params[Nparam]->type, "int");
	strcpy(params[Nparam]->print_type, print_type("int"));
	Nparam++;

	choose_mode(fp, params, 1);

	//for문에 사용한 문자도 변수리스트에 기록
	//다른 for문과 중복되지 않게 조심

	tap--;
	print_tap(fp);
	fprintf(*fp, "}\n\n");

	printf("코드생성을 완료했습니다.");
	Sleep(500);
}

void if_else(FILE** fp, Param* params[100]) {
	char content[MAX_CHAR];

	rewind(stdin);
	printf("\n조건문");

	while (1) {
		printf("\n\n조건식을 입력해 주세요 : ");
		gets(content);

		if (check_formula2(content, params))
			break;
		else
			printf("잘못된 수식 입니다.");
	}

	print_tap(fp);
	fprintf(*fp, "if(%s) {\n", content);
	tap++;

	choose_mode(fp, params, 2);

	tap--;
	print_tap(fp);
	fprintf(*fp, "}\n\n");

	printf("코드생성을 완료했습니다.");
	Sleep(500);
}

void randnum(FILE** fp, Param* params[100]) {
	char param[MAX_CHAR];
	int input, posi, start, end;
	print_tap(fp);

	while (1) {
		printf("\n난수를 저장할 변수이름 : ");
		scanf("%s", param);

		posi = check_param(param, params);
		if (posi == -1) {  //변수리스트에 있는지 확인
			printf("\n없는 변수입니다.\n");
			printf("생성하려면 1, 다시 입력하려면 0 입력 : ");
			scanf("%d", &input);
			if (input == 1) {
				//변수리스트에 추가
				strcpy(params[Nparam]->name, param);
				strcpy(params[Nparam]->type, "int");
				strcpy(params[Nparam]->print_type, print_type("int"));
				Nparam++;

				fprintf(*fp, "int %s = ", param);
				break;
			}
			else system("cls");
		}
		else {
			fprintf(*fp, "%s = ", param);
			break;
		}
	}

	printf("\n난수 범위를 입력해주세요\n");
	printf("시작 : ");
	scanf("%d", &start);
	printf("끝 : ");
	scanf("%d", &end);

	fprintf(*fp, "rand() %% %d + %d;\n", end - start + 1, start);  //rand 출력

	printf("코드생성을 완료했습니다.");
	Sleep(500);

}

void print_tap(FILE** fp) {
	for (int i = 0; i < tap; i++)
		fprintf(*fp, "\t");
}

char* print_type(char type[MAX_CHAR]) {
	if (strcmp(type, "int") == 0)
		return "%d";
	else if (strcmp(type, "float") == 0)
		return "%f";
	else if (strcmp(type, "double") == 0)
		return "%llf";
	else if (strcmp(type, "char") == 0)
		return "%c";
	else
		return NULL;
}

void show_params(Param* params[100]) {
	char input;

	printf("----현재 변수 목록----\n\n");
	printf("이름     자료형\n");
	for (int i = 0; i < Nparam; i++) {
		printf("%s  %s  %s\n", params[i]->name, params[i]->type, params[i]->print_type);
	}

	rewind(stdin);
	printf("\n\n나가려면 아무거나 입력하세요 : ");
	scanf("%c", &input);
}

int check_param(char param[MAX_CHAR], Param* params[100]) {
	for (int i = 0; i < Nparam; i++) {
		if (strcmp(param, params[i]->name) == 0)  //param이 변수 목록에 있으면
			return i;                             //위치 반환
	}
	return -1;
}

void choose_mode(FILE** fp, Param* params[100], int a) {
	enum Mode mode;
	int input, t = 0;

	while (1) {
		system("cls");
		if (a == 0)
			printf("현재 위치 : main함수\n");
		else if (a == 1)
			printf("현재 위치 : for문\n");
		else if (a == 2)
			printf("현재 위치 : if문\n");

		printf("\n--------원하는 기능 선택--------\n\n");
		printf("1. 변수 선언\n");
		printf("2. 출력\n");
		printf("3. 입력\n");
		printf("4. 조건문(if-else)\n");
		printf("5. 간단한 반복문(for)\n");
		printf("6. 난수생성(rand)\n");
		printf("7. 현재 변수목록 보기\n");
		if (a == 0)
			printf("종료하려면 0을 입력하세요\n\n");
		else if (a == 1)
			printf("for문을 종료하려면 0을 입력하세요\n\n");
		else if (a == 2)
			printf("if문을 종료하려면 0을 입력하세요\n\n");
		printf("필요한 기능(숫자로 입력) : ");
		scanf("%d", &input);

		mode = input;

		switch (mode) {
		case FINISH:
			if (a == 0)
				printf("프로그램을 종료합니다.");
			else if (a == 1)
				printf("for문을 종료합니다.\n");
			else if (a == 2)
				printf("if문을 종료합니다.\n");
			t = 1;
			break;
		case DECLARE:
			declare(fp, params);
			break;
		case PRINT:
			print(fp, params);
			break;
		case SCAN:
			scan(fp, params);
			break;
		case IF:
			if_else(fp, params);
			break;
		case SIMPLE_FOR:
			simple_for(fp, params);
			break;
		case RAND:
			randnum(fp, params);
			break;
		case SHOW:
			show_params(params);
			break;
		default:
			printf("다시 입력해주세요.");
			break;
		}

		if (t) break;
	}
}

//사용된 변수 주소 보내기

//맞는 수식인지 확인하기
int check_formula(char param[MAX_CHAR], Param* params[100], char print_type[5]) {
	char record[MAX_CHAR];
	char ope[9] = "+-*/%!=><";
	enum Type { NOT, PARAM, NUM, OPE };
	enum Type now;
	now = NOT;
	int t, a = 0, space = 0, posi;
	strcpy(print_type, "%c");  //가장 작은 자료형으로

	//안되는 경우
	//1. 숫자 - 변수
	//2. 변수 - 숫자 / 변수 - 변수
	//3. 연산기호 - 연산기호
	//4. 변수 - 띄어쓰기 - 숫자
	//5. 변수 - 띄어쓰기 - 변수
	for (int i = 0; param[i] != '\0'; i++) {
		if (param[i] == ' ') { //공백이라면
			if (now == PARAM) {  //이전이 변수라면
				record[a] = '\0';
				posi = check_param(record, params);
				if (posi == -1) //없는 변수이면
					return 0;  //잘못된 수식
				else {
					//print_type 확인
					if (compare_type(print_type, params[posi]->print_type))
						strcpy(print_type, params[posi]->print_type);

					a = 0; //record 초기화
					space = 1;
				}
			}
			continue;
		}

		if (isalpha(param[i]) || param[i] == '_') {  //알파벳이면
			if (now == NUM) //현재상태가 숫자이면 -> 잘못된 수식
				return 0;
			if (now == NOT || now == OPE)
				now = PARAM; //현재상태 : 변수로
			else if (now == PARAM && space) //변수 연달아 등장
				return 0;

			record[a++] = param[i];
			space = 0;
		}
		else if (isdigit(param[i])) {  //숫자이면
			if (now == NOT || now == OPE) now = NUM; //현재상태 : 숫자로
			else if (now == PARAM && space)     //현재상태가 변수이고 그전이 띄어쓰기라면
				return 0;                       //변수 숫자 연달아 등장 -> 잘못된 수식
			else if (now == PARAM)  //현재상태가 변수이고 띄어쓰기가 없다면
				record[a++] = param[i]; //기록
		}
		else {
			t = 0;
			for (int j = 0; j < sizeof(ope); j++) {
				if (param[i] == ope[j]) { //연산기호인지 확인
					t = 1;
					if (now == OPE) return 0; //연산기호 연속해서 등장 -> 잘못된 수식
					else if (now == PARAM) {  //이전이 변수였다면
						if (!space) {
							record[a] = '\0';
							posi = check_param(record, params);
							if (posi == -1) //없는 변수이면
								return 0;  //잘못된 수식
							else {
								//print_type 확인
								if (compare_type(print_type, params[posi]->print_type))
									strcpy(print_type, params[posi]->print_type);

								a = 0; //record 초기화
							}
						}
					}
					space = 0;
					now = OPE;
					break;
				}
			}
			if (!t) return 0; //잘못된 기호 포함
		}

	}
	if (now == PARAM) {
		record[a] = '\0';
		posi = check_param(record, params);
		if (posi == -1) //없는 변수이면
			return 0;  //잘못된 수식
		else {
			//print_type 확인
			if (compare_type(print_type, params[posi]->print_type))
				strcpy(print_type, params[posi]->print_type);
		}
	}

	return 1;
}

int compare_type(char a[5], char b[5]) {
	char list[4][5] = { "%c", "%d", "%f", "%llf" };  //숫자가 클수록 상위 자료형
	int a_com, b_com;

	for (int i = 0; i < 4; i++) {
		if (strcmp(a, list[i]) == 0) {
			a_com = i;
		}
		if (strcmp(b, list[i]) == 0) {
			b_com = i;
		}
	}

	if (a_com < b_com) return 1;  //print_type 교체해야함
	else return 0;  //그대로 해도 됨
}

int check_formula2(char param[MAX_CHAR], Param* params[100]) {
	char record[MAX_CHAR];
	char ope[11] = "+-*/%=><!&|";
	enum Type { NOT, PARAM, NUM, OPE };
	enum Type now;
	now = NOT;
	int t, a = 0, space = 0, posi;

	for (int i = 0; param[i] != '\0'; i++) {
		if (param[i] == ' ') { //공백이라면
			if (now == PARAM) {  //이전이 변수라면
				record[a] = '\0';
				posi = check_param(record, params);
				if (posi == -1) //없는 변수이면
					return 0;  //잘못된 수식
				else {
					a = 0; //record 초기화
					space = 1;
				}
			}
			continue;
		}

		if (isalpha(param[i]) || param[i] == '_') {  //알파벳이면
			if (now == NUM) //현재상태가 숫자이면 -> 잘못된 수식
				return 0;
			if (now == NOT || now == OPE)
				now = PARAM; //현재상태 : 변수로
			else if (now == PARAM && space) //변수 연달아 등장
				return 0;

			record[a++] = param[i];
			space = 0;
		}
		else if (isdigit(param[i])) {  //숫자이면
			if (now == NOT || now == OPE) now = NUM; //현재상태 : 숫자로
			else if (now == PARAM && space)     //현재상태가 변수이고 그전이 띄어쓰기라면
				return 0;                       //변수 숫자 연달아 등장 -> 잘못된 수식
			else if (now == PARAM)  //현재상태가 변수이고 띄어쓰기가 없다면
				record[a++] = param[i]; //기록
		}
		else {
			t = 0;
			for (int j = 0; j < sizeof(ope); j++) {
				if (param[i] == ope[j]) { //연산기호인지 확인
					t = 1;
					if (now == PARAM) {  //이전이 변수였다면
						if (!space) {
							record[a] = '\0';
							posi = check_param(record, params);
							if (posi == -1) //없는 변수이면
								return 0;  //잘못된 수식
							else {
								a = 0; //record 초기화
							}
						}
					}
					space = 0;
					now = OPE;
					break;
				}
			}
			if (!t) return 0; //잘못된 기호 포함
		}

	}
	if (now == PARAM) {
		record[a] = '\0';
		posi = check_param(record, params);
		if (posi == -1) //없는 변수이면
			return 0;  //잘못된 수식
	}

	return 1;
}