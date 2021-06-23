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
	printf("������ ���� ���α׷��� �����մϴ�.\n****C ����̺��� LibSave ������ �� ���α׷��� ���� �����Դϴ�. �����Ͻ� ��� ����� �����Ͱ� ��� �����ǹǷ� �����Ͻʽÿ�.****");
	return 0;
}
inline void call_main()
{
	char path[] = "C:\\LibSave";
	mkdir(path);
	//C ������ LibSave ���� ����
	while (1)
	{
		system("cls");
		int input;
		printf("------������ ���� ���α׷�------\n");
		printf("1 : ���� ����\n2 : ȸ�� ����\n3 : ���� �� �ݳ�\n4 : ����\n���Ͻô� �޴��� �����Ͻʽÿ�:");
		//������ ���� ���α׷��� ����ȭ�鿡�� �ȳ�
		scanf("%d", &input);
		if (input == 1)book_menu();
		else if (input == 2)mem_menu();
		else if (input == 3)lend();
		else if (input == 4)return;
		else {
			//�߸��� ���� ó��
			printf("�߸��� �Է��Դϴ�.\n");
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
		printf("------���� ����------\n");
		//���� ����â���� �ȳ�
		printf("1 : ���� �߰�\n2 : ���� ����\n3 : ���� ��ȸ\n4 : �ڷΰ���\n");
		printf("���Ͻô� �޴��� �����Ͻʽÿ�:");
		scanf("%d", &input);
		if (input == 1)book_in();
		else if (input == 2)book_del();
		else if (input == 3)book_find();
		else if (input == 4)return;
		else {
			//�߸��� ���� ó��
			printf("�߸��� �Է��Դϴ�\n");
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
		printf("------ȸ�� ����------\n");
		//ȸ�� ����â���� �ȳ�
		printf("1 : ȸ�� �߰�\n2 : ȸ�� ��ȸ\n3 : �� ����Ʈ Ȯ��\n4 : ���� ���� ��� ��ȸ\n5 : �ڷΰ���\n");
		printf("���Ͻô� �޴��� �����Ͻʽÿ�:");
		scanf("%d", &input);
		if (input == 1)mem_in();
		else if (input == 2)find_mem();
		else if (input == 3)get_black();
		else if (input == 4)show_all_lend();
		else if (input == 5)return;
		else {
			//�߸��� ���� ó��
			printf("�߸��� �Է��Դϴ�\n");
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
	printf("��ȸ�ϰ��� �ϴ� ȸ���� ������ȣ�� �Է��Ͻʽÿ�.(�̸����� �˻��ϱ⸦ ���ϸ� �ƹ� ���ڳ�): ");
	//��ȸ�ϰ��� �ϴ� ȸ���� ������ȣ�� �Է¹޴´�.
	scanf("%s", tmpp);
	//������ȣ�� ù�ڸ��� 0�� ��찡 �����ϹǷ� %s�� �Է� ����
	code = return_code(tmpp);
	//������ ��ȯ
	int code_2 = code;
	if (code != -1) {
		for (i = 11; i < 11 + strlen(tmpp); i++, code /= 10)path[i] = code % 10 + '0';
		path[i] = '-'; path[i + 1] = 'P'; path[i + 2] = '.'; path[i + 3] = 't'; path[i + 4] = 'x'; path[i + 5] = 't';
		//ȸ���� ������ �����ϰ� �ִ� ������ ��� ����
		if (access(path, 00) == -1) {
			//�������� ������ �ȳ�
			printf("�������� �ʴ� ������ȣ�Դϴ�.");
			Sleep(1000); return;
		}
		FILE* now = fopen(path, "r");
		member tmp; int cnt;
		//��ȸ ���� ���
		fscanf(now, "%s %d %d %d %d %d %d %d", tmp.name, &tmp.age, &tmp.gender, &tmp.ad_year, &tmp.ad_mon, &tmp.ad_day, &cnt);
		printf("----ȸ�� ��ȸ ����----\n");
		printf("�̸� : %s\n", tmp.name);
		printf("���� : %d\n", tmp.age);
		printf("���� : %s\n", tmp.gender == 1 ? "����" : "����");
		printf("����� : %d.%d.%d\n", tmp.ad_year, tmp.ad_mon, tmp.ad_day);
		printf("��ü��� : %d\n", cnt);
		printf("������ȣ : ");
		for (int k = strlen(tmpp) - 1; k >= 0; k--)printf("%c", tmpp[k]);
		printf("\n");
		fclose(now);
		path[i] = '-'; path[i + 1] = 'P'; path[i + 2] = 'L'; path[i + 3] = '.'; path[i + 4] = 't'; path[i + 5] = 'x'; path[i + 6] = 't';
		//ȸ���� ���� ����Ʈ�� �����ϰ� �ִ� ������ ��� ����
		now = fopen(path, "r");
		printf("******���� ����Ʈ******\n");
		//EOF�� ������ �ݺ��ϸ� ��� ���
		while (1) {
			char tmp[100001], book_code[10001]; int start1, start2, start3, end1, end2, end3;
			memset(tmp, sizeof(tmp), '\0');
			memset(book_code, sizeof(book_code), '\0');
			if (fscanf(now, "%s %d %d %d %d %d %d %s", tmp, &start1, &start2, &start3, &end1, &end2, &end3, book_code) == EOF)break;
			if (tmp[strlen(tmp) - 1] == '^')continue;
			//������ ������ ���ڰ� @, ��, �ݳ� �� ������ ��� pass
			tmp[strlen(tmp) - 1] = '\0';
			printf("���� : %s | ����(���� ��¥, �ݳ� ����) : %d.%d.%d~%d.%d.%d | ���� ���� ��ȣ : %s\n", tmp, start1, start2, start3, end1, end2, end3, book_code);
		}
		fclose(now);
		printf("\n");
	}
	else {
		member tmp;
		//���ڰ� �ƴ� ���ڰ� ������ȣ�� ���� ��� �̸��� ���� �˻��Ҽ� �ֵ��� ����
		printf("��� �Է��� �ѱ��� �������� �ʽ��ϴ�.������ _�� ǥ���Ͽ��ֽʽÿ�.��밡���� Ư�����ڴ� . ? !�Դϴ�.\n");
		printf("�̸�: ");
		scanf("%s", tmp.name);
		if (!check_form(tmp.name)) {
			//�Է� ���� �˻�
			Sleep(1000); return;
		}
		if (!get_path2(get_hashing(tmp.name), tmp, 2)) {
			//�˻��� ������ ��� �ȳ�
			printf("�˻��� �����Ͽ����ϴ�. ����� �۰��� �ٽ� Ȯ�����ֽñ� �ٶ��ϴ�.\n");
		}
	}
	system("pause");
}
inline void mem_in()
{
	system("cls");
	member tmp;
	char ntmp[1001];
	//�߰��� ȸ���� ������ �Է�
	printf("��� �Է��� �ѱ��� �������� �ʽ��ϴ�.������ _�� ǥ���Ͽ��ֽʽÿ�.��밡���� Ư�����ڴ� . ? !�Դϴ�.\n");
	printf("�̸�:");
	scanf("%s", tmp.name);
	if (check_form(tmp.name));
	else return;
	printf("����:");
	scanf("%d", &tmp.age);
	printf("����:(���� 1, ���� 2):");
	scanf("%d", &tmp.gender);
	if (tmp.gender != 1 && tmp.gender != 2) {
		printf("�߸��� �Է� �Դϴ�.");
		Sleep(1000); return;
	}
	//�߸��� �Է� ���� �˻�
	int code = get_hashing(tmp.name);
	//�ʱ� �ؽð� ����
	get_path2(code, tmp, 1);
	system("pause");
}
int check_form(char* stmp)
{
	//���ڿ��� ���°� ������ ���Ŀ� �����Ǵ��� �˻�
	int length = strlen(stmp);
	for (int i = 0; i < length; i++) {
		if (!((stmp[i] >= 'A' && stmp[i] <= 'Z') || (stmp[i] >= 'a' && stmp[i] <= 'z') || (stmp[i] >= '0' && stmp[i] <= '9') || stmp[i] == '_' || stmp[i] == '!' || stmp[i] == '?' || stmp[i] == '.')) {
			printf("�߸��� �Է� �����Դϴ�."); Sleep(1000);
			return 0;
		}
	}
	return 1;
}
int get_hashing(char* d)
{
	//�ؽð� ����
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
	//�߰��� å�� ������ �Է�
	printf("��� �Է��� �ѱ��� �������� �ʽ��ϴ�.������ _�� ǥ���Ͽ��ֽʽÿ�.��밡���� Ư�����ڴ� . ? !�Դϴ�.\n");
	printf("���� ����:");
	scanf("%s", ntmp);
	if (check_form(ntmp))strcpy(tmp.title, ntmp);
	else return;
	memset(ntmp, strlen(ntmp), '\0');
	printf("�帣:");
	scanf("%s", ntmp);
	if (check_form(ntmp))strcpy(tmp.genre, ntmp);
	else return;
	memset(ntmp, strlen(ntmp), '\0');
	printf("�۰�:");
	scanf("%s", ntmp);
	if (check_form(ntmp))strcpy(tmp.author, ntmp);
	else return;
	int numbertmp;
	printf("�߰��� �Ǽ�:");
	scanf("%d", &numbertmp);
	if (numbertmp < 0) {
		printf("�߸��� �Է��Դϴ�."); Sleep(1000); return;
	}
	//�߸��� �Է� ���� ó��
	tmp.count = numbertmp;
	int code = get_hashing(tmp.title);
	//�ؽð� ����
	get_path(code, tmp, 1);
	system("pause");
}
inline void book_del()
{
	system("cls");
	char path[100001] = "C:\\LibSave\\", tmpp[100001];
	//�����Ϸ� �ϴ� å�� ������ȣ �Է�
	printf("�����ϰ��� �ϴ� å�� ������ȣ�� �Է��Ͻʽÿ�.(����, �۰��� ����ϱ⸦ ���ϸ� �ƹ� ���ڳ�):");
	scanf("%s", tmpp);
	int code, i;
	code = return_code(tmpp);
	//������ ��ȯ
	if (code != -1) {
		for (i = 11; i < 11 + strlen(tmpp); i++, code /= 10)path[i] = code % 10 + '0';
		path[i] = '.'; path[i + 1] = 't'; path[i + 2] = 'x'; path[i + 3] = 't';
		//�ش� å�� ���� ��� ����
		if (access(path, 00) == -1) {
			printf("�������� �ʴ� ������ȣ�Դϴ�.");
			Sleep(1000); return;
		}
		FILE* now = fopen(path, "r+w");
		book tmp;
		fscanf(now, "%s %s %s %d %d %d", tmp.title, tmp.genre, tmp.author, &tmp.count, &tmp.state[0], &tmp.state[1]);
		int del_cnt;
		//������ �Ǽ� �Է�
		printf("�����Ͻ� �Ǽ��� �Է��Ͻʽÿ�(���� ���� �ƴ� ������ ���Ű����մϴ�.):");
		scanf("%d", &del_cnt);
		rewind(now);
		//���� �� ���� ������Ʈ
		fprintf(now, "%s %s %s %d %d %d                                                                                                                          --end", tmp.title, tmp.genre, tmp.author, max(tmp.state[1], tmp.count - del_cnt), max(0, tmp.state[0] - del_cnt), tmp.state[1]);
		fclose(now);
	}
	else {
		//���ڰ� ������ ��, ����� �۰��� �Է¹޾� ó��
		book tmp;
		printf("��� �Է��� �ѱ��� �������� �ʽ��ϴ�.������ _�� ǥ���Ͽ��ֽʽÿ�.��밡���� Ư�����ڴ� . ? !�Դϴ�.\n");
		printf("����: ");
		scanf("%s", tmp.title);
		if (!check_form(tmp.title)) {
			Sleep(1000); return;
		}
		printf("�۰�: ");
		scanf("%s", tmp.author);
		if (!check_form(tmp.author)) {
			Sleep(1000); return;
		}
		if (!get_path(get_hashing(tmp.title), tmp, 3)) {
			//���н� �ȳ�
			printf("�˻��� �����Ͽ����ϴ�. ����� �۰��� �ٽ� Ȯ�����ֽñ� �ٶ��ϴ�.\n");
		}
	}
	//�ȳ�
	printf("****���� ������ ������ ��� 0���� ��쵵, ����� �������� ������, ���� ���� �߰� �� �Ҵ�Ǿ��ִ� ������ȣ�� ����մϴ�.****\n");
	system("pause");
}
inline void book_find()
{
	system("cls");
	char path[100001] = "C:\\LibSave\\", tmpp[100001];
	int code = 0, i;
	//��ȸ�Ϸ� �ϴ� å�� ������ȣ �Է�
	printf("��ȸ�ϰ��� �ϴ� å�� ������ȣ�� �Է��Ͻʽÿ�.(����, �۰��� �˻��ϱ⸦ ���ϸ� �ƹ� ���ڳ�): ");
	scanf("%s", tmpp);
	code = return_code(tmpp);
	int code_2 = code;
	if (code != -1) {
		for (i = 11; i < 11 + strlen(tmpp); i++, code /= 10)path[i] = code % 10 + '0';
		path[i] = '.'; path[i + 1] = 't'; path[i + 2] = 'x'; path[i + 3] = 't';
		//����� å�� ������ ��� ����
		if (access(path, 00) == -1) {
			//�˻�
			printf("�������� �ʴ� ������ȣ�Դϴ�.");
			Sleep(1000); return;
		}
		FILE* now = fopen(path, "r");
		book tmp;
		//��ȸ ��� ���
		fscanf(now, "%s %s %s %d %d %d", tmp.title, tmp.genre, tmp.author, &tmp.count, &tmp.state[0], &tmp.state[1]);
		printf("----å ��ȸ ����----\n");
		printf("���� : %s\n", tmp.title);
		printf("�帣 : %s\n", tmp.genre);
		printf("�۰� : %s\n", tmp.author);
		printf("���� �Ǽ� : %d��(���� ����:%d��, ���� ��:%d��)\n", tmp.count, tmp.state[0], tmp.state[1]);
		printf("���� ��ȣ : %s\n", tmpp);
		fclose(now);
	}
	else {
		book tmp;
		//���ڰ� ���� ��� ����� �۰��� �Է¹޾� ó��
		printf("��� �Է��� �ѱ��� �������� �ʽ��ϴ�.������ _�� ǥ���Ͽ��ֽʽÿ�.��밡���� Ư�����ڴ� . ? !�Դϴ�.\n");
		printf("����: ");
		scanf("%s", tmp.title);
		if (!check_form(tmp.title)) {
			Sleep(1000); return;
		}
		printf("�۰�: ");
		scanf("%s", tmp.author);
		if (!check_form(tmp.author)) {
			Sleep(1000); return;
		}
		if (!get_path(get_hashing(tmp.title), tmp, 2)) {
			printf("�˻��� �����Ͽ����ϴ�. ����� �۰��� �ٽ� Ȯ�����ֽñ� �ٶ��ϴ�.\n");
		}
	}
	system("pause");
}
int get_path(int code, book tmp, int mode)
{
	int line = 0, mem = 19, code_2 = code;
	//�⺻ �ؽð��� �������� ���� ��� ����
	char path[10001] = "C:\\LibSave\\";
	for (int i = 11; i <= 18; i++, code /= 10)path[i] = code % 10 + '0';
	if (mode < 4) { path[19] = '.'; path[20] = 't'; path[21] = 'x'; path[22] = 't'; }

	book justtmp;
	while (1)
	{
		int i;
		if ((mode == 1) && access(path, 00) != 0)break;
		//mode=1->å �߰�, ��, ��밡���� ��ΰ� �߰ߵǸ� break;
		else if ((mode == 2 || mode == 3) && access(path, 00) != 0)return 0;
		//mode=2->å ��ȸ, mode=3->å ����, ��, ���̻� Ȯ���ؾ��ϴ� ������ �������� ���� �� break;
		else {
			FILE* now = fopen(path, "r+w");
			memset(justtmp.title, sizeof(justtmp.title), '\0');
			memset(justtmp.title, sizeof(justtmp.genre), '\0');
			memset(justtmp.title, sizeof(justtmp.author), '\0');
			fscanf(now, "%s %s %s %d %d %d", justtmp.title, justtmp.genre, justtmp.author, &justtmp.count, &justtmp.state[0], &justtmp.state[1]);
			//�߰�,���� Ȥ�� ��ȸ�ϰ� ���� å�� ���� ����� ������ ��ġ�ϴ��� Ȯ��
			if (mode == 1 && !strcmp(justtmp.title, tmp.title) && !strcmp(justtmp.author, tmp.author) && !strcmp(justtmp.genre, tmp.genre)) {
				//�Ǽ��� ����
				justtmp.count += tmp.count; justtmp.state[0] += tmp.count;
				rewind(now);
				fprintf(now, "%s %s %s %d %d %d                                                                                                                          --end", justtmp.title, justtmp.genre, justtmp.author, justtmp.count, justtmp.state[0], justtmp.state[1]);
				fclose(now);
				return 0;
			}
			else if (mode == 2 && !strcmp(justtmp.title, tmp.title) && !strcmp(justtmp.author, tmp.author))
			{
				//��ȸ ���� ���
				printf("----å ��ȸ ����----\n");
				printf("���� : %s\n", justtmp.title);
				printf("�帣 : %s\n", justtmp.genre);
				printf("�۰� : %s\n", justtmp.author);
				printf("���� �Ǽ� : %d��(���� ����:%d��, ���� ��:%d��)\n", justtmp.count, justtmp.state[0], justtmp.state[1]);
				printf("���� ��ȣ : %d\n", code_2);
				fclose(now);
				return 1;
			}
			else if (mode == 3 && !strcmp(justtmp.title, tmp.title) && !strcmp(justtmp.author, tmp.author)) {
				//������ �Ǽ� �Է� �ް� ����
				printf("�����Ͻ� �Ǽ��� �Է��Ͻʽÿ�(���� ���� �ƴ� ������ ���Ű����մϴ�.):");
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
		//���� ��� ����
		path[mem] = path[mem + 1] = path[mem + 2] = path[mem + 3] = '\0';
		for (i = 19; line_2; i++, line_2 /= 10)path[i] = line_2 % 10 + '0';
		if (mode < 4) { path[i] = '.'; path[i + 1] = 't'; path[i + 2] = 'x'; path[i + 3] = 't'; }
		else { path[i] = '-'; path[i + 1] = 'P'; path[i + 2] = '.'; path[i + 3] = 't'; path[i + 4] = 'x'; path[i + 5] = 't'; }
		mem = i;
	}
	//���� ��ȣ �ο�
	printf("���� ��ȣ ");
	for (int i = mem - 1; i >= 11; i--)printf("%c", path[i]);
	printf("�� �ο��Ǿ����ϴ�.\n");
	FILE* now2 = fopen(path, "w");
	if (mode == 1)fprintf(now2, "%s %s %s %d %d 0                                                                                                                          --end", tmp.title, tmp.genre, tmp.author, tmp.count, tmp.count);
	fclose(now2);
	return 0;
}
int get_path2(int code, member tmp, int mode)
{
	int line = 0, mem = 19, code_2 = code, i;
	//���� ��� ����
	char path[10001] = "C:\\LibSave\\", memcode[1001];
	for (i = 11; i <= 18; i++, code /= 10)path[i] = memcode[i - 11] = code % 10 + '0';
	path[19] = '-'; path[20] = 'P';
	path[21] = '.'; path[22] = 't'; path[23] = 'x'; path[24] = 't';
	int check = 0, chk = 0;
	member justtmp;
	while (1)
	{
		if (access(path, 00) != 0)break;
		//���̻� ü���� �̾����� �ʴ� �ٸ� break;
		else {
			int cnt, count;
			FILE* now = fopen(path, "r");
			memset(justtmp.name, sizeof(justtmp.name), '\0');
			fscanf(now, "%s %d %d %d %d %d %d", justtmp.name, &justtmp.age, &justtmp.gender, &justtmp.ad_year, &justtmp.ad_mon, &justtmp.ad_day, &count);
			//��ȸ�ϰ� ���� ����ڿ� ���� ����� ������ ������ Ȯ��
			if (mode == 2 && !strcmp(justtmp.name, tmp.name))
			{
				//������ȣ�� �Է¹޾������� ����
				if (!chk) {
					chk = 1; printf("%s�� �̸��� ���� ������� �� ��ȸ ����Դϴ�.\n", tmp.name);
				}
				printf("---------------------------------------\n\n");
				printf("�̸� : %s\n", justtmp.name);
				printf("���� : %d\n", justtmp.age);
				printf("���� : %s\n", justtmp.gender == 1 ? "����" : "����");
				printf("����� : %d.%d.%d\n", justtmp.ad_year, justtmp.ad_mon, justtmp.ad_day);
				printf("��ü��� : %d��\n", count);
				printf("������ȣ : ");
				for (int k = strlen(memcode) - 1; k >= 0; k--)printf("%c", memcode[k]);
				printf("\n");
				fclose(now);
				path[i + 2] = 'L'; path[i + 3] = '.'; path[i + 4] = 't'; path[i + 5] = 'x'; path[i + 6] = 't';

				now = fopen(path, "r");
				printf("******���� ����Ʈ******\n");
				while (1) {
					char tmp[100001], bookcodep[1001]; int start1, start2, start3, end1, end2, end3, book_code;
					memset(tmp, sizeof(tmp), '\0');
					memset(bookcodep, sizeof(bookcodep), '\0');
					if (fscanf(now, "%s %d %d %d %d %d %d %s", tmp, &start1, &start2, &start3, &end1, &end2, &end3, bookcodep) == EOF)break;
					if (tmp[strlen(tmp) - 1] == '^')continue;
					tmp[strlen(tmp) - 1] = '\0';
					printf("���� : %s | ����(���� ��¥, �ݳ� ����) : %d.%d.%d~%d.%d.%d | ���� ���� ��ȣ : %s\n", tmp, start1, start2, start3, end1, end2, end3, bookcodep);
				}
				printf("\n");
				check = 1;
				fclose(now);
			}
			fclose(now);
		}

		line++;
		//���� ��� ����
		int line_2 = line;
		path[mem] = path[mem + 1] = path[mem + 2] = path[mem + 3] = '\0';
		for (i = 19; line_2; i++, line_2 /= 10)path[i] = memcode[i - 11] = line_2 % 10 + '0';
		path[i] = '-'; path[i + 1] = 'P'; path[i + 2] = '.'; path[i + 3] = 't'; path[i + 4] = 'x'; path[i + 5] = 't';
		mem = i;
	}
	if (mode == 2)return check;
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	//���� ��ȣ �ο�
	printf("���� ��ȣ ");
	for (int i = mem - 1; i >= 11; i--)printf("%c", path[i]);
	printf("�� �ο��Ǿ����ϴ�.\n");
	FILE* now2 = fopen(path, "w");
	fprintf(now2, "%s %d %d %d %d %d 0                                                                                                                          --end", tmp.name, tmp.age, tmp.gender, tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
	fclose(now2);
	return 0;
}
int return_code(char* d)
{
	//���ڿ� �ڵ带 ������ ��ȯ
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
	printf("****���� ���� �� �ݳ��� �̸�(Ȥ�� ����� �۰�)�˻� ����� �������� �ʽ��ϴ�. ȸ�� ��ȸ �Ǵ� ���� ��ȸ�� ���� ������ȣ�� ��ȸ�Ҽ� �ֽ��ϴ�.****\n");
	printf("��� �Ͻðڽ��ϱ�?(Y/anykey(not Y)");
	char tmp; scanf("%c%c", &tmp, &tmp);
	if (tmp != 'Y')return;
	int i;
	char mem_code[10001], book_code[10001];
	int memcode, bookcode;
	printf("�������� ������ȣ:");
	scanf("%s", mem_code);
	memcode = return_code(mem_code);
	printf("���� ������ȣ:");
	scanf("%s", book_code);
	bookcode = return_code(book_code);
	printf("����(����=1,�ݳ�=2):");
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
	//�������� ������ȣ�� ���� ������ȣ, ������ �Է¹ް� �⺻ ��� ����
	if (access(path_book, 00) != 0) {
		FILE* test = fopen(path_book, "r");
		fprintf(test, "this is test");
		printf("�������� �ʴ� �����Դϴ�.\n"); Sleep(1000); return;
	}
	if (access(path_mem, 00) != 0) {
		printf("�������� �ʴ� ȸ���Դϴ�.\n"); Sleep(1000); return;
	}
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	if (type == 1) {
		FILE* books = fopen(path_book, "r+w");
		book tmp;
		fscanf(books, "%s %s %s %d %d %d", tmp.title, tmp.genre, tmp.author, &tmp.count, &tmp.state[0], &tmp.state[1]);
		if (tmp.state[0] == 0) {
			printf("���� ���������� �ʴ� �ش� ������ �������� �ʽ��ϴ�.\n");
			Sleep(1000); return;
		}
		//���� �� ��� �ݳ� �Ǽ� �߰�
		rewind(books);
		fprintf(books, "%s %s %s %d %d %d                                                                                                                          --end", tmp.title, tmp.genre, tmp.author, tmp.count, tmp.state[0] - 1, tmp.state[1] + 1);
		fclose(books);
		FILE* meml = fopen(path_booklist, "a+");
		int year, mon, day;
		printf("�ݳ� ���� ����:(YYYY MM DD):");
		scanf("%d %d %d", &year, &mon, &day);
		//  fseek(meml,-1,SEEK_END);
		fprintf(meml, "%s@ %04d %02d %02d %04d %02d %02d %s\n", tmp.title, tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, year, mon, day, book_code);
		fclose(meml);
		printf("���� ����\n");
		//.LP ���Ͽ� ���� ���
	}
	else {
		int chk = 0;
		FILE* books = fopen(path_book, "r+w");
		book tmp;
		fscanf(books, "%s %s %s %d %d %d", tmp.title, tmp.genre, tmp.author, &tmp.count, &tmp.state[0], &tmp.state[1]);
		if (tmp.state[1] == 0) {
			printf("���� �������� �ش� ������ �������� �ʽ��ϴ�.\n");
			Sleep(1000); return;
		}
		fclose(books);
		FILE* meml = fopen(path_booklist, "r+t");
		while (1)
		{
			//�ش� ������� ���� ����� �ݳ��ϰ��� �ϴ� å�� �˻�
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
				//å�� ������ �Ǽ��� ���� ���� �Ǽ��� �����ϰ�, �����Ͽ��� �ش� ���� �ݳ� ó��
				if (year2 < tm.tm_year + 1900 || (year2 == tm.tm_year + 1900 && mon2 < tm.tm_mon + 1) || (year2 == tm.tm_year + 1900 && mon2 == tm.tm_mon + 1 && day2 < tm.tm_mday)) {
					//��ü�� ���, �ݳ����� ��ü Ƚ�� ���� �� ������Ʈ �ɻ�
					printf("��ü �����Դϴ�.\n");
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
		if (chk)printf("�ݳ� ����\n");
		else printf("�ش� ������ ���� ����� �������� �ʽ��ϴ�.\n");
	}
	system("pause");
}
inline void get_black()
{
	system("cls");
	//�� ����Ʈ ���
	printf("��ü����� 7�� �̻��� ������Ʈ�� ����մϴ�.\n---------------------------------------\n");
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
	//���� ��� ���
	system("cls");
	char path[100001] = "C:\\LibSave\\", tmpp[1001];
	int code = 0, i;
	printf("������ ��ȸ�� ���ϴ� ȸ���� ������ȣ�� �Է��Ͻʽÿ� : ");
	scanf("%s", tmpp);
	code = return_code(tmpp);
	for (i = 11; i < 11 + strlen(tmpp); i++, code /= 10)path[i] = code % 10 + '0';
	path[i] = '-'; path[i + 1] = 'P'; path[i + 2] = 'L'; path[i + 3] = '.'; path[i + 4] = 't'; path[i + 5] = 'x'; path[i + 6] = 't';
	if (access(path, 00) == -1) {
		printf("�������� �ʴ� ������ȣ�Դϴ�.");
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
		printf("����:%s | ���� �Ⱓ(������, �����Ǿ��� �ݳ� ��)%d.%d.%d~%d.%d.%d | ������ȣ : %s\n", title, sy, sm, sd, fy, fm, fd, code);
	}
	printf("-----------------------------------\n");
	system("pause");
}
