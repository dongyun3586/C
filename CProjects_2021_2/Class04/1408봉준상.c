#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_NAME 10
#define MAX_SUB 4
#define MAX_STU 16

enum choose { INPUT = 1, SEARCH, DELETE, RANK, EXIT } choice;     //main �Լ����� �޴��� �����Ҷ� �츮�� ��� enum�� ����ؼ� ���������� switch case ���� �߰��ϰ��� �ߴ�.

struct subject {     //����� ����� �ϳ��� ���� ����ü
	float kor;
	float eng;
	float math;
	float sci;
	float sum;
};

typedef struct {                    //�л��� ������ ���� ����ü�� �̸�, �⼮ ��ȣ, ���� ������ �ִ�.
	char name[MAX_NAME];
	int number;
	struct subject sub;
}student;

int inputstudent(student* p, int count);      //�л��� �߰��ϴ� �Լ�
void search(student* p, int count);  //���ǿ� ���缭 �л��� �˻��ϴ� �Լ��� �̵������ִ� �Լ�
int searchstudent(student* p);   //�л��� �˻��ϴ� �Լ�
void showstudentlist(student* p, int count);     //���ݱ��� ����� �л��� �����ִ� �Լ�
int delete(student* p, int count);  //���ǿ� ���缭 �л��� �����ϴ� �Լ��� �̵������ִ� �Լ�
void deletestudent(student* p, int num, int count);  //�л��� �����ϴ� �Լ�
void rankstudent(student* p, int count);  //�л��� ����� �����ִ� �Լ�

int main() {      //main �Լ��� ����ڰ� ������ �޴��� �ٷ�� �Լ��� switch case ���� �����
	student stu[MAX_STU] = { "", 0, {0,0,0,0,0} };
	int count = 0;
	printf("***********1408�� ���� ���� �ý��ۿ� ���Ű��� ȯ���մϴ�!***********\n\n");

	while (1) {
		printf("�޴��δ�  1: �л� �߰�, 2: �л� �˻�, 3: �л� ����, 4: ��� Ȯ��, 5: ������\n�޴� ����: ");
		scanf("%d", &choice);
		system("cls"); //������ �ִ� ���� �� �����ֱ� ���� �����
		switch (choice) {  //�� �ڵ�� �����ð��� �ߴ� �������� 13: ģ������ �ý��ۿ��� �Ϻ� �ο��ؿԴ�.
		case INPUT:
			if (inputstudent(stu, count) == 1) count++;
			break;
		case SEARCH:
			search(stu, count);
			break;
		case DELETE:
			if (delete(stu, count) == 1) count--;
			break;
		case RANK:
			rankstudent(stu, count);
			break;
		case EXIT:
			printf("\n���� ���� ���α׷��� �����մϴ�. �̿��� �ּż� �����մϴ�.\n");
			exit(0);
		default:
			printf("��Ȯ�� ���� �Է����ּ���!\n\n");
			break;
		}
	}

}

int inputstudent(student* p, int count) {
	if (count < MAX_STU) {
		printf("�߰��� �л��� ������ �Է����ּ���.\n");
		printf("�л� �̸�: ");
		scanf("%s", &(p[count].name));
		printf("���� ����: ");
		scanf("%f", &(p[count].sub.kor));
		printf("���� ����: ");
		scanf("%f", &(p[count].sub.eng));
		printf("���� ����: ");
		scanf("%f", &(p[count].sub.math));
		printf("���� ����: ");
		scanf("%f", &(p[count].sub.sci));
		p[count].sub.sum = p[count].sub.kor + p[count].sub.eng + p[count].sub.math + p[count].sub.sci;
		p[count].number = count + 1;
		printf("���������� �л��� �߰��Ǿ����ϴ�!\n\n");
		return 1;
	}
	else
		printf("�л��� �̹� �ִ�� �����߽��ϴ�. �л� ���� �� �ٽ� �õ����ּ���\n\n");
	return 0;
}

void showstudentlist(student* p, int count) {
	int i;
	int number;
	if (count > 0) {  //����� �л��� �Ѹ��̶� �־���� �л��� ������
		printf("\n��ϵ� �л� ���\n");
		printf(" ��ȣ   �̸�\n");
		printf("=============\n");
		for (i = 0; i < count; i++) {

			printf(" %2d :  %-10s\n", (p + i)->number, (p + i)->name);
		}
		printf("=============\n\n");
		return 0;
	}
	else {
		printf("\n��ϵ� �л��� �����ϴ�.\n\n");
		return 0;
	}
}

void search(student* p, int count) {
	if (count > 0) {  //����� �л��� �Ѹ� �̻��϶� �˻��Լ��� ����
		showstudentlist(p, count);
		searchstudent(p);
	}
	else return 0;
}

int searchstudent(student* p) {
	int stunum;

	while (1) {
		printf("�˻��ϰ� ���� �л��� ��ȣ�� �Է����ּ���: ");
		scanf("%d", &stunum);
		stunum--;  //�迭�̱� ������ �츮�� ���� ��ȣ�� 1�����̹Ƿ� -1�� ����(stunum�� ��� ����ϱ� ������ �׳� p[stunum-1]...��� ���� �ͺ��� �׳� 1�ٿ�����
		if (p[stunum].number < MAX_STU && p[stunum].number>0) {    //ó���� 0���� �ʱ�ȭ �߱� ������ 0�� �ִ� �л��� ���̿� �ִ� ��ȣ������ ���
			printf("\n     �̸�           ����    ����   ����   ����\n");
			printf("===============================================\n");
			printf("    %-14s %5.2f, %5.2f, %5.2f, %5.2f\n", p[stunum].name, p[stunum].sub.kor, p[stunum].sub.eng, p[stunum].sub.math, p[stunum].sub.sci);
			printf("===============================================\n\n");
			return 0;
		}
		else {
			printf("�л��� ��ȣ�� ��Ȯ�� �Է����ּ���!\n\n");
		}
	}
}

int delete(student* p, int count) {
	int stunum;
	if (count > 0) {  //�л��� �Ѹ��̶� �־���� ���� ����
		showstudentlist(p, count);  //�л��� ��θ� ������
		while (1) {
			printf("������ �л��� ��ȣ�� �Է����ּ���: ");
			scanf("%d", &stunum);
			if (p[stunum - 1].number < 17 && p[stunum - 1].number>0) {
				deletestudent(p, stunum, count);
				printf("�л��� ���������� ���ŵǾ����ϴ�\n\n");
				return 1;
			}
			else printf("�л��� ��ȣ�� ��Ȯ�� �Է����ּ���!\n\n");
		}
	}
	else {
		printf("\n��ϵ� �л��� �����ϴ�.\n\n");
		return 0;



	}
}

void deletestudent(student* p, int num, int count) {
	for (int i = num - 1; i < count; i++) {   //�����Ϸ��� �л����� ��ĭ�� �Ű��ִ� �ڵ�
		p[i] = p[i + 1];
	}
	for (int i = num - 1; i < count - 1; i++) {  //���� �ڵ�� �⼮��ȣ ���� �������� 1,2,3���� 2�� �����ϸ� 1,3�� �ǹǷ� ������ �������� ��ȣ�� 1�� ����
		p[i].number--;
	}
}

void rankstudent(student* p, int count) {  //����� ����ϱ� ���ؼ��� �л����� ��ġ�� �迭 ������ �ٲ���Ѵ�. �׷��� ���� ����ü�迭���� �ٲٸ� �ȵǱ� ������ ���ο� rank�迭�� ����� �־Ҵ�.
	int choice;
	if (count > 0) {
		student rank[MAX_STU] = { "", 0, {0,0,0,0,0} };
		student temp[MAX_STU];
		for (int i = 0; i < count; i++) {
			rank[i] = p[i];   //rank �迭�� ���� ����ü �迭�ȿ� �ִ� ���� ������� �־��ش�
		}
		for (int i = 1; i < count; i++) {
			for (int j = 0; j < count - i; j++) {   //�޻���� �ջ������ ������ ���� �� rank�迭�� ������ �ٲ��ش�.
				if (rank[j + 1].sub.sum > rank[j].sub.sum) {
					temp[j] = rank[j];
					rank[j] = rank[j + 1];
					rank[j + 1] = temp[j];
				}
			}
		}
		printf("***********���� ���� ���***********\n\n");  //������ ���� ��� ���� �� ���񺰷� ����� ������ ������ �Ȱ��� �ڵ忡�� sum-->(kor, math...��)���� �� �ٲٱ� ������ �Ȱ��� �ڵ尡 �ʹ� ���� �ݺ��Ǿ� ���� ��� �ϳ��� �ߴ�.
		printf(" ���   ��ȣ   �̸�    ���\n");
		printf("=============================\n");
		for (int i = 0; i < count; i++) {
			printf("  %d��   %2d :  %-4s   %.2f\n", i + 1, rank[i].number, rank[i].name, rank[i].sub.sum / MAX_SUB);
		}
		printf("=============================\n\n");
		return 0;
	}
	else {
		printf("\n��ϵ� �л��� �����ϴ�.\n\n");
		return 0;
	}
}