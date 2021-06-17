#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include <windows.h>
void rock(); //�׸��Դϴ�
void scissors();
void paper();
int main() {
	int com; // ��ǻ�Ͱ� �� ���� �����մϴ�. 
	int user; // ����ڰ� �� ���� �����մϴ�. 
	int win = 0, tie = 0, lose = 0; // ������ ����� �����մϴ�.
	// result �迭�� ��� ��Ҹ� 0���� �ʱ�ȭ�մϴ�. 
	int cnt = 0; // ������ Ƚ���� �����մϴ�. 0���� �ʱ�ȭ�մϴ�. 
	srand(time(NULL)); // rand �Լ��� ����� �Ź� �ٸ����� �õ尪�� �����մϴ�. 
	while (1) // ����ڰ� ������ �� ���� �ݺ��մϴ�. 
	{
		com = rand() % 3 + 1; // 1~3 �� �� �ϳ��� �����մϴ�. 
		printf("**************** ���� ���� �� ���� ****************\n");
		printf("(1. ���� _ 2. ���� _ 3. �� _ 0. ����)\n\n");
		printf("�Է����ּ��� : ");
		scanf_s("%d", &user);
		if (user > 0 && user < 4) // ����ڰ� 1~3 ���� �Է����� ����Դϴ�.
		{
			cnt++; // �������� �Է��� ��� ���� Ƚ���� ������ŵ�ϴ�. 

		// ��ǻ��, ����ڰ� �� ���� ���� ����, ����, �� �� ����� ���� �����մϴ�. 
			printf("\n��ǻ�� : %s\n", (com == 1 ? "����" : com == 2 ? "����" : "��"));
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
			if (com == 1) {
				scissors();
			}
			if (com == 2) {
				rock();
			}
			if (com == 3) {
				paper();
			}
			printf("����� : %s\n\n", (user == 1 ? "����" : user == 2 ? "����" : "��"));
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
			if (user == 1) {
				scissors();
			}
			if (user == 2) {
				rock();
			}
			if (user == 3) {
				paper();
			}
			if (com == user) // ��ǻ���� ���� ������� ���� ������ ���� ����Դϴ�. 
			{
				printf("�������� ���� ��븦 ������. \n\n");
				tie++; // ���º� Ƚ���� ������ŵ�ϴ�. 
			}// ���� ����� ���Դϴ�. 
			else if (((com == 1) && (user == 3)) ||
				((com == 2) && (user == 1)) ||
				((com == 3) && (user == 2)))
			{
				printf("������ �༮ \n\n");
				lose++; // �й� Ƚ���� ������ŵ�ϴ�. 
			}
			else // �������� �̱� ����Դϴ�. 
			{
				printf("���� ���ҳ�\n\n");
				win++; // �¸� Ƚ���� ������ŵ�ϴ�. 
			}
			printf("%d�� %d�� %d�� %d��\n\n", cnt, win, tie, lose);
		}
		else // ����ڰ� �Է��� ���� 1, 2, 3�� �ƴ� ��� 
		{
			if (user == 0) // ����ڰ� �Է��� ���� 0�̸� �����մϴ�. 
			{
				printf("������ �����մϴ�.\n");
				break;
			}
			printf("���ڸ� ����� �Է����ּ���\n\n");// �� �ܿ��� ����ó�� �޼��� ��� 
		}
		system("pause"); // �Ͻ����� �ƹ�Ű�� ������ ����˴ϴ�. 
		system("cls"); // ȭ�� ������ ��� ����ϴ�. 
	}
	return 0;
}

void scissors() {
	printf("\n");
	printf("   $$$$$    $$$$$ \n");
	printf("   $$$$$    $$$$$ \n");
	printf("   $$$$$    $$$S$ \n");
	printf("   $$$$$    $$$$$ \n");
	printf("   $$$$$    $$$$$\n");
	printf("  $$$S$$$$$$$$$$$ \n");
	printf("  $$$$$$$$$$$$$$$ \n");
	printf("  $$$$$$$$$$$$$$$ \n");
	printf("  $$$$$$$$$$$$$$$ \n");
	printf("  $$$$$$$$$$$$$$$ \n");
	printf("%c[0m\n", 27); //���� ������ �ǵ���
}

void rock() {
	printf("   \n");
	printf("   \n");
	printf("   \n");
	printf("      $$$$$$$$$$  \n");
	printf("   $$$$$$$$$$$$$$ \n");
	printf("  $$$S$$$$$$$$$$$$\n");
	printf("  $$$$$$$$$$$$$$$$\n");
	printf("  $$$$$$$$$$$$$$$ \n");
	printf("  $$$$$$$$$$$$$$$ \n");
	printf("  \n");
	printf("%c[0m\n", 27); //���� ������ �ǵ���

}


void paper() {
	printf("\n");
	printf("  $$  $$  $$  $$  \n");
	printf("  $$  $$  $$  $$  \n");
	printf("  $$  $$  $$  $S  \n");
	printf("  $$  $$  $$  $$$ \n");
	printf("  $$$$$$$$$$$$$$$$\n");
	printf("  $$$S$$$$$$$$$$$$  $$\n");
	printf("  $$$$$$$$$$$$$$$$$$$\n");
	printf("  $$$$$$$$$$$$$$$$$ \n");
	printf("  $$$$$$$$$$$$$$$ \n");
	printf("    $$$$$$$$$$$$$ \n");
	printf("%c[0m\n", 27); //���� ������ �ǵ���
}
