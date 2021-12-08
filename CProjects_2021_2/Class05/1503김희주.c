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

	Param* params[100];  //���� ������ ����

	for (int i = 0; i < sizeof(params) / sizeof(Param*); i++)
		params[i] = malloc(sizeof(Param));     //����ü�� �޸� �Ҵ��ؾ���!!!!!

	start(&code, params);

	fclose(code);

	Sleep(1000);
	system("cls");
	printf("\n\n-------������ �ڵ�-------\n\n");

	code = fopen("code.txt", "r");
	while (fgets(content, sizeof(content), code) != NULL) {
		puts(content);
	}

	return 0;
}

void start(FILE** fp, Param* params[100]) {
	char content[MAX_LENGTH];

	//�������, �����Լ�
	fprintf(*fp, "#include <stdio.h>\n");
	fprintf(*fp, "#include <stdlib.h>\n");
	fprintf(*fp, "#include <time.h>\n\n");
	fprintf(*fp, "int main()\n{\n");
	tap++;
	print_tap(fp);
	fprintf(*fp, "srand(time(NULL));\n\n");  //rand�� �ű��???

	printf("�ڵ��ڵ�������\n\n");

	choose_mode(fp, params, 0);

	fprintf(*fp, "\n");
	print_tap(fp);
	fprintf(*fp, "return 0;\n");
	tap--;
	fprintf(*fp, "}");
}

//���� �̸�, Ÿ�� ����صα�!!!
//�����ؼ� ���� �ְ� �����
void declare(FILE** fp, Param* params[100]) {
	char param[MAX_CHAR];
	char type[MAX_CHAR];
	char type_arr[4][MAX_CHAR] = { "int", "float", "double", "char" };
	int ch;

	while (1) {
		printf("\n���������ϱ�\n\n");
		printf("���� Ÿ��(������ : int, �Ǽ��� : float �Ǵ� double, ���Ϲ��� : char ���)\n: ");
		scanf("%s", type);
		//���ڷ� �ٲ㼭?

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
				printf("���� �̸� : ");
				scanf("%s", param);
				//�����̸��� ���ڷ� �����ϰų� �Լ��̸��̸� �ȵ�....

				if (check_paramName(param, params)) { //��밡���� �̸����� Ȯ��
					fprintf(*fp, "%s", param);

					//����ü�� ����
					strcpy(params[Nparam]->name, param);
					strcpy(params[Nparam]->type, type);
					strcpy(params[Nparam]->print_type, print_type(type));
					Nparam++;

					printf("���� ������ �Ϸ��߽��ϴ�.\n");

					break;
				}
				else {
					Sleep(500);
					system("cls");
				}

			}
			fprintf(*fp, ";\n");

			printf("(��� �����Ϸ��� 1, ���� ������ �������� 0) : ");
			scanf("%d", &ch);
			if (!ch) break;
			Sleep(500);
			system("cls");
		}
		else {
			printf("�߸��� Ÿ���Դϴ�.\n");
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
		printf("�̹� �����ϴ� �����Դϴ�.\n\n");
		return 0;
	}

	if (isdigit(param[0])) {
		printf("�����̸��� ù���ڴ� ���ڷ� ������ �� �����ϴ�.\n\n");
		return 0;
	}

	for (int i = 0; param[i] != '\0'; i++) {
		if (!isalpha(param[i]) && !isdigit(param[i]) && param[i] != ' ') {
			printf("�����̸��� ������, ����, _�θ� ������ �� �ֽ��ϴ�.\n\n");
			return 0;
		}
	}

	for (int i = 0; i < 32; i++) {
		if (strcmp(param, impossible[i]) == 0) {
			printf("����� �� ���� �����̸��Դϴ�.\n\n");
			return 0;
		}
	}

	return 1;  //��밡���� �̸�
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

	printf("����ϱ�\n\n");
	printf("����ϰ� ���� ������ �Է��ϼ���\n������ ����Ϸ��� {�����̸�}\n:");

	fgets(content, sizeof(content), stdin);
	content[strlen(content) - 1] = '\0';  //\n ���ֱ�

	print_tap(fp);
	fprintf(*fp, "printf(\"");
	for (int i = 0; content[i] != '\0'; i++) {
		//{�����̸�}
		if (content[i] == '{') {
			a = 0;
			for (int s = i + 1; content[s] != '\0'; s++) {
				if (content[s] == ' ') continue;

				if (content[s] == '}') {
					p[a] = '\0';
					t = check_formula(p, params, print_type);
					if (t) {                             //�´� ����,�����̸����� Ȯ��
						fprintf(*fp, "%s", print_type);  //���Ĺ���?(%d, %f���) ���
						strcpy(used_params[b++], p);     //����� ��Ͽ� ����(���߿� ��� ����)
					}

					//posi = check_param(p, params);  
					//if (posi != -1) {  //��������Ʈ�� �ִ��� Ȯ��
					//	fprintf(*fp, "%s", params[posi]->print_type);  //���Ĺ���?(%d, %f���) ���
					//	used_param[b++] = posi;    //���� ���� ��Ͽ� ����
					//}

					i = s;
					break;
				}
				else {
					p[a++] = content[s];   //p�� �����̸� ����
				}
			}
		}
		else {
			fprintf(*fp, "%c", content[i]);  //���Ͽ� ���� ���
		}
	}
	fprintf(*fp, "\\n\"");

	for (int i = 0; i < b; i++) {
		fprintf(*fp, ", %s", used_params[i]);
	}

	//for (int i = 0; i < b; i++) {
	//	fprintf(*fp, ", %s", params[used_param[i]]->name);  //printf �޺κ� ���� ���
	//}
	fprintf(*fp, ");\n");

	printf("�ڵ������ �Ϸ��߽��ϴ�.");
	Sleep(500);
	//fprintf(*fp, "printf(\"%s\\n\");\n", content);
}

void scan(FILE** fp, Param* params[100]) {
	char param[MAX_CHAR];
	int posi = 0;
	while (1) {
		printf("\n�Է¹��� ���� �̸� : ");
		scanf("%s", param);


		posi = check_param(param, params);
		if (posi != -1) {  //��������Ʈ�� �ִ��� Ȯ��
			break;
		}
		else
			printf("���� ���� �Դϴ�.\n");
	}

	print_tap(fp);
	fprintf(*fp, "printf(\"%s �Է� : \");\n", param);
	print_tap(fp);
	fprintf(*fp, "scanf(\"%s\", &%s);\n", params[posi]->print_type, param); //scanf�� ���

	printf("�ڵ������ �Ϸ��߽��ϴ�.");
	Sleep(500);
}

void simple_for(FILE** fp, Param* params[100]) {
	int start, end, plus;

	printf("\n������ �ݺ���\n\n");

	while (1) {
		printf("���� ���� : ");
		scanf("%d", &start);
		printf("�� ���� : ");
		scanf("%d", &end);
		printf("���� �Ǵ� ������ ��\n(�� : 1�� �����Ϸ��� 1, 2�� �����Ϸ��� -2 �Է�) : ");
		scanf("%d", &plus);

		if (plus == 0) {
			printf("���ѹݺ��� �Դϴ�.\n�ٽ� �Է��� �ּ���");
		}
		else if ((plus > 0 && start > end) || (plus < 0 && start < end)) {
			printf("�ݺ� ������ �߸��Ǿ����ϴ�.\n");
		}
		else {
			break;
		}
	}
	print_tap(fp);
	fprintf(*fp, "for (int i = %d; i <= %d; i += %d) {\n", start, end, plus);
	tap++;

	//i ��������Ʈ�� �߰�
	strcpy(params[Nparam]->name, "i");
	strcpy(params[Nparam]->type, "int");
	strcpy(params[Nparam]->print_type, print_type("int"));
	Nparam++;

	choose_mode(fp, params, 1);

	//for���� ����� ���ڵ� ��������Ʈ�� ���
	//�ٸ� for���� �ߺ����� �ʰ� ����

	tap--;
	print_tap(fp);
	fprintf(*fp, "}\n\n");

	printf("�ڵ������ �Ϸ��߽��ϴ�.");
	Sleep(500);
}

void if_else(FILE** fp, Param* params[100]) {
	char content[MAX_CHAR];

	rewind(stdin);
	printf("\n���ǹ�");

	while (1) {
		printf("\n\n���ǽ��� �Է��� �ּ��� : ");
		gets(content);

		if (check_formula2(content, params))
			break;
		else
			printf("�߸��� ���� �Դϴ�.");
	}

	print_tap(fp);
	fprintf(*fp, "if(%s) {\n", content);
	tap++;

	choose_mode(fp, params, 2);

	tap--;
	print_tap(fp);
	fprintf(*fp, "}\n\n");

	printf("�ڵ������ �Ϸ��߽��ϴ�.");
	Sleep(500);
}

void randnum(FILE** fp, Param* params[100]) {
	char param[MAX_CHAR];
	int input, posi, start, end;
	print_tap(fp);

	while (1) {
		printf("\n������ ������ �����̸� : ");
		scanf("%s", param);

		posi = check_param(param, params);
		if (posi == -1) {  //��������Ʈ�� �ִ��� Ȯ��
			printf("\n���� �����Դϴ�.\n");
			printf("�����Ϸ��� 1, �ٽ� �Է��Ϸ��� 0 �Է� : ");
			scanf("%d", &input);
			if (input == 1) {
				//��������Ʈ�� �߰�
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

	printf("\n���� ������ �Է����ּ���\n");
	printf("���� : ");
	scanf("%d", &start);
	printf("�� : ");
	scanf("%d", &end);

	fprintf(*fp, "rand() %% %d + %d;\n", end - start + 1, start);  //rand ���

	printf("�ڵ������ �Ϸ��߽��ϴ�.");
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

	printf("----���� ���� ���----\n\n");
	printf("�̸�     �ڷ���\n");
	for (int i = 0; i < Nparam; i++) {
		printf("%s  %s  %s\n", params[i]->name, params[i]->type, params[i]->print_type);
	}

	rewind(stdin);
	printf("\n\n�������� �ƹ��ų� �Է��ϼ��� : ");
	scanf("%c", &input);
}

int check_param(char param[MAX_CHAR], Param* params[100]) {
	for (int i = 0; i < Nparam; i++) {
		if (strcmp(param, params[i]->name) == 0)  //param�� ���� ��Ͽ� ������
			return i;                             //��ġ ��ȯ
	}
	return -1;
}

void choose_mode(FILE** fp, Param* params[100], int a) {
	enum Mode mode;
	int input, t = 0;

	while (1) {
		system("cls");
		if (a == 0)
			printf("���� ��ġ : main�Լ�\n");
		else if (a == 1)
			printf("���� ��ġ : for��\n");
		else if (a == 2)
			printf("���� ��ġ : if��\n");

		printf("\n--------���ϴ� ��� ����--------\n\n");
		printf("1. ���� ����\n");
		printf("2. ���\n");
		printf("3. �Է�\n");
		printf("4. ���ǹ�(if-else)\n");
		printf("5. ������ �ݺ���(for)\n");
		printf("6. ��������(rand)\n");
		printf("7. ���� ������� ����\n");
		if (a == 0)
			printf("�����Ϸ��� 0�� �Է��ϼ���\n\n");
		else if (a == 1)
			printf("for���� �����Ϸ��� 0�� �Է��ϼ���\n\n");
		else if (a == 2)
			printf("if���� �����Ϸ��� 0�� �Է��ϼ���\n\n");
		printf("�ʿ��� ���(���ڷ� �Է�) : ");
		scanf("%d", &input);

		mode = input;

		switch (mode) {
		case FINISH:
			if (a == 0)
				printf("���α׷��� �����մϴ�.");
			else if (a == 1)
				printf("for���� �����մϴ�.\n");
			else if (a == 2)
				printf("if���� �����մϴ�.\n");
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
			printf("�ٽ� �Է����ּ���.");
			break;
		}

		if (t) break;
	}
}

//���� ���� �ּ� ������

//�´� �������� Ȯ���ϱ�
int check_formula(char param[MAX_CHAR], Param* params[100], char print_type[5]) {
	char record[MAX_CHAR];
	char ope[9] = "+-*/%!=><";
	enum Type { NOT, PARAM, NUM, OPE };
	enum Type now;
	now = NOT;
	int t, a = 0, space = 0, posi;
	strcpy(print_type, "%c");  //���� ���� �ڷ�������

	//�ȵǴ� ���
	//1. ���� - ����
	//2. ���� - ���� / ���� - ����
	//3. �����ȣ - �����ȣ
	//4. ���� - ���� - ����
	//5. ���� - ���� - ����
	for (int i = 0; param[i] != '\0'; i++) {
		if (param[i] == ' ') { //�����̶��
			if (now == PARAM) {  //������ �������
				record[a] = '\0';
				posi = check_param(record, params);
				if (posi == -1) //���� �����̸�
					return 0;  //�߸��� ����
				else {
					//print_type Ȯ��
					if (compare_type(print_type, params[posi]->print_type))
						strcpy(print_type, params[posi]->print_type);

					a = 0; //record �ʱ�ȭ
					space = 1;
				}
			}
			continue;
		}

		if (isalpha(param[i]) || param[i] == '_') {  //���ĺ��̸�
			if (now == NUM) //������°� �����̸� -> �߸��� ����
				return 0;
			if (now == NOT || now == OPE)
				now = PARAM; //������� : ������
			else if (now == PARAM && space) //���� ���޾� ����
				return 0;

			record[a++] = param[i];
			space = 0;
		}
		else if (isdigit(param[i])) {  //�����̸�
			if (now == NOT || now == OPE) now = NUM; //������� : ���ڷ�
			else if (now == PARAM && space)     //������°� �����̰� ������ ������
				return 0;                       //���� ���� ���޾� ���� -> �߸��� ����
			else if (now == PARAM)  //������°� �����̰� ���Ⱑ ���ٸ�
				record[a++] = param[i]; //���
		}
		else {
			t = 0;
			for (int j = 0; j < sizeof(ope); j++) {
				if (param[i] == ope[j]) { //�����ȣ���� Ȯ��
					t = 1;
					if (now == OPE) return 0; //�����ȣ �����ؼ� ���� -> �߸��� ����
					else if (now == PARAM) {  //������ �������ٸ�
						if (!space) {
							record[a] = '\0';
							posi = check_param(record, params);
							if (posi == -1) //���� �����̸�
								return 0;  //�߸��� ����
							else {
								//print_type Ȯ��
								if (compare_type(print_type, params[posi]->print_type))
									strcpy(print_type, params[posi]->print_type);

								a = 0; //record �ʱ�ȭ
							}
						}
					}
					space = 0;
					now = OPE;
					break;
				}
			}
			if (!t) return 0; //�߸��� ��ȣ ����
		}

	}
	if (now == PARAM) {
		record[a] = '\0';
		posi = check_param(record, params);
		if (posi == -1) //���� �����̸�
			return 0;  //�߸��� ����
		else {
			//print_type Ȯ��
			if (compare_type(print_type, params[posi]->print_type))
				strcpy(print_type, params[posi]->print_type);
		}
	}

	return 1;
}

int compare_type(char a[5], char b[5]) {
	char list[4][5] = { "%c", "%d", "%f", "%llf" };  //���ڰ� Ŭ���� ���� �ڷ���
	int a_com, b_com;

	for (int i = 0; i < 4; i++) {
		if (strcmp(a, list[i]) == 0) {
			a_com = i;
		}
		if (strcmp(b, list[i]) == 0) {
			b_com = i;
		}
	}

	if (a_com < b_com) return 1;  //print_type ��ü�ؾ���
	else return 0;  //�״�� �ص� ��
}

int check_formula2(char param[MAX_CHAR], Param* params[100]) {
	char record[MAX_CHAR];
	char ope[11] = "+-*/%=><!&|";
	enum Type { NOT, PARAM, NUM, OPE };
	enum Type now;
	now = NOT;
	int t, a = 0, space = 0, posi;

	for (int i = 0; param[i] != '\0'; i++) {
		if (param[i] == ' ') { //�����̶��
			if (now == PARAM) {  //������ �������
				record[a] = '\0';
				posi = check_param(record, params);
				if (posi == -1) //���� �����̸�
					return 0;  //�߸��� ����
				else {
					a = 0; //record �ʱ�ȭ
					space = 1;
				}
			}
			continue;
		}

		if (isalpha(param[i]) || param[i] == '_') {  //���ĺ��̸�
			if (now == NUM) //������°� �����̸� -> �߸��� ����
				return 0;
			if (now == NOT || now == OPE)
				now = PARAM; //������� : ������
			else if (now == PARAM && space) //���� ���޾� ����
				return 0;

			record[a++] = param[i];
			space = 0;
		}
		else if (isdigit(param[i])) {  //�����̸�
			if (now == NOT || now == OPE) now = NUM; //������� : ���ڷ�
			else if (now == PARAM && space)     //������°� �����̰� ������ ������
				return 0;                       //���� ���� ���޾� ���� -> �߸��� ����
			else if (now == PARAM)  //������°� �����̰� ���Ⱑ ���ٸ�
				record[a++] = param[i]; //���
		}
		else {
			t = 0;
			for (int j = 0; j < sizeof(ope); j++) {
				if (param[i] == ope[j]) { //�����ȣ���� Ȯ��
					t = 1;
					if (now == PARAM) {  //������ �������ٸ�
						if (!space) {
							record[a] = '\0';
							posi = check_param(record, params);
							if (posi == -1) //���� �����̸�
								return 0;  //�߸��� ����
							else {
								a = 0; //record �ʱ�ȭ
							}
						}
					}
					space = 0;
					now = OPE;
					break;
				}
			}
			if (!t) return 0; //�߸��� ��ȣ ����
		}

	}
	if (now == PARAM) {
		record[a] = '\0';
		posi = check_param(record, params);
		if (posi == -1) //���� �����̸�
			return 0;  //�߸��� ����
	}

	return 1;
}