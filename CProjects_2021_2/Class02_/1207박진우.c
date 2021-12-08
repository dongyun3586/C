#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
char* type[17] = { "�븻", "�Ҳ�", "��", "����", "Ǯ", "����", "����", "��", "��", "����", "������", "����", "����", "��Ʈ", "�巡��", "��", "��ö" };
float isCounter[17][17] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0.5,
						   0, 1, 1, 0.5, 1, 0.5, 0.5, 1, 2, 2, 1, 1, 1, 1, 1, 2, 0.5, 1, 0.5, 1, 2,
						   1, 2, 0.5, 1, 0.5, 1, 1, 1, 2, 1, 1, 1, 2, 1, 0.5, 1, 1,
						   1, 1, 2, 0.5, 0.5, 1, 1, 1, 0, 2, 1, 1, 1, 1, 0.5, 1, 1,
						   1, 0.5, 2, 1, 0.5, 1, 1, 0.5, 2, 0.5, 1, 0.5, 2, 1, 0.5, 1, 0.5,
						   1, 0.5, 0.5, 1, 2, 0.5, 1, 1, 2, 2, 1, 1, 1, 1, 2, 1, 0.5,
						   2, 1, 1, 1, 1, 2, 1, 0.5, 1, 0.5, 0.5, 0.5, 2, 0, 1, 2, 2,
						   1, 1, 1, 1, 2, 1, 1, 0.5, 0.5, 1, 1, 1, 0.5, 0.5, 1, 1, 0,
						   1, 2, 1, 2, 0.5, 1, 1, 2, 1, 0, 1, 0.5, 2, 1, 1, 1, 2,
						   1, 1, 1, 0.5, 2, 1, 2, 1, 1, 1, 1, 2, 0.5, 1, 1, 1, 0.5,
						   1, 1, 1, 1, 1, 1, 2, 2, 1, 1, 0.5, 1, 1, 1, 1, 0, 0.5,
						   1, 0.5, 1, 1, 2, 1, 0.5, 0.5,1, 0.5, 2, 1, 1, 0.5, 1, 2, 0.5,
						   1, 2, 1, 1, 1, 2, 0.5, 1, 0.5, 2, 1 ,2, 1, 1, 1, 1, 0.5,
						   0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 0.5, 0.5,
						   1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 0.5,
						   1, 1, 1, 1, 1, 1, 0.5, 1, 1, 1, 2, 1, 1, 2, 1, 0.5, 0.5,
						   1, 0.5, 0.5, 0.5, 1, 2, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 0.5 };   //�� : �����ϴ� Ÿ��, �� : ���ݹ޴�    ���尪 : ȿ���� ���(0, 0.5, 1, 2����)
struct skill {
	char name[100];
	int typeOfSkill;//�븻, �Ҳ�, ��, ����, Ǯ, ����, ����, ��, ��, ����, ������, ����, ����, ��Ʈ, �巡��, ��, ��ö ������ 0���� �ڿ���
	int priority; // ����� �켱��
	int power; //����
	int catagory; //����(0) �Ǵ� Ư��(1)
	float myself; //�ݵ� ������ ������ �ڽ��� �� �������� �� ������ ����, ������ 0 ����
	int accuracy; //���߷� �� �ۼ�Ʈ���� ����
};
typedef struct pokemoninfo {
	char name[100];
	int level;
	int hpOriginal; int attack_special[2]; int defence_special[2]; int speed; //����, Ư��/ ��� Ư���� �迭�� ���� ����
	int hpnow;
	int pokeType;
	struct skill* skillset[4];
}���ϸ�;
struct trainer {
	struct pokemoninfo* pokemon[3];
	int left; //���� ���ϸ� ��
};
enum Who { ��, ���� };
void changeHp(struct pokemoninfo* po1, struct pokemoninfo* po2, int PlayerUse, int ComUse, int* left1, int* left2); //left1�� ���� ���� ���ϸ� ��, left2�� ������ ���� ���ϸ� ��
int comskill(); //��ǻ�Ͱ� ����� ��ų�� �������� ���ϱ�
void printskill(struct trainer tr1); //�� ���ϸ��� ��ų�� ���
void printpoke(struct pokemoninfo* po); //���ϸ� ���� ���
int damage(struct pokemoninfo po1, struct pokemoninfo po2, int SkillUse, enum Who wh);  //po1�� ������ po2�� ���ݹ���, ������ ���
void printCounter(int Skilltype, int Poketype); //ȿ���� �������� ��¾���� �˷��ִ� �Լ�
int WhoIsFirst(struct pokemoninfo* po1, struct pokemoninfo* po2, int PlayerUse, int ComUse);  //������ ��������
int percentage(int accuracy);  //����� ������ ����
int myself(struct pokemoninfo* po1, struct pokemoninfo* po2, int SkillUse, enum Who wh, int preDamage); //�ݵ��� ó�� �Լ�
int main() {
	struct skill ��Ʈ��Ŭ = { "��Ʈ��Ŭ", 3, 0, 120, 0, 1 / 3, 100 };
	struct skill ������ȭ = { "������ȭ", 0, 1, 40, 0, 0, 100 };
	struct skill ���̾����� = { "���̾�����", 16, 0, 100, 0, 0, 75 };
	struct skill �ʸ���Ʈ = { "10����Ʈ", 3, 0, 95, 1, 0, 100 };
	struct skill ������ = { "������", 5, 0, 120, 1, 0, 70 };
	struct skill ����ź = { "����ź", 4, 0, 80, 0, 0, 100 };
	struct skill ������μ��� = { "������μ���", 15, 0, 80, 0, 0, 100 };
	struct skill ������ = { "������", 0, 0, 85, 0, 0, 100 };
	struct skill ���̵������ = { "���̵������", 2, 0, 120, 1, 0, 80 };
	struct skill ������ĳ�� = { "������ĳ��", 16, 0, 80, 1, 0, 100 };
	struct skill ���ձ��� = { "���ձ���", 6, 0, 120, 1, 0, 70 };
	struct skill �����ĵ� = { "�����ĵ�", 15, 0, 80, 1, 0, 100 };
	struct skill ������ġ = { "������ġ", 5, 1, 40, 0, 0, 100 };
	struct skill �õ��� = { "�õ���", 5, 0, 95, 1, 0, 100 };
	struct skill �̷���Ʈ = { "�̷���Ʈ", 10, -5, 0, 1, -1, 100 }; //�̷���Ʈ�� �ݵ� ����� -1�� �����Ͽ� �ν�
	struct skill ������ = { "������", 13, 0, 80, 1, 0, 100 };
	struct skill �ڿ������� = { "�ڿ�������", 1, 0, 80, 0, 0, 100 };
	struct skill ����ź1 = { "����ź", 4, 0, 80, 0, 0, 100 };
	struct skill ����ũ�ν� = { "����ũ�ν�", 11, 0, 80, 0, 0, 100 };
	struct skill �������̵� = { "�������̵�", 4, 0, 90, 0, 0, 100 };
	struct skill �ʸ���Ʈ1 = { "10����Ʈ", 3, 0, 95, 1, 0, 100 };
	struct skill ���� = { "����", 3, 0, 80, 1, 0, 100 };
	struct skill ���� = { "����", 3, 0, 120, 1, 0, 70 };
	struct skill ������1 = { "������", 13, 0, 80, 1, 0, 100 };
	���ϸ� ��ī�� = { "��ī��", 88, 186, {141, 132}, {93, 112}, 209, 186, 3, {&��Ʈ��Ŭ, &���̾�����, &������ȭ, &�ʸ���Ʈ} };
	���ϸ� �Ḹ�� = { "�Ḹ��", 82, 379, {210, 137}, {188, 210}, 79, 379, 0, {&������, &����ź, &������μ���, &������} };
	���ϸ� �źϿ� = { "�źϿ�", 84, 252, {170, 173}, {199, 207}, 162, 252, 2, {&���̵������, &������ĳ��, &���ձ���, &�����ĵ�} };
	���ϸ� �۷��̽þ� = { "�۷��̽þ�", 90, 301, {140, 323}, {231, 203}, 149, 301, 5, {&������ġ, &�õ���, &�̷���Ʈ, &������} };
	���ϸ� ���Ǿ� = { "���Ǿ�", 83, 269, {233, 127}, {238, 134}, 201, 269, 4, {&�ڿ�������, &����ź1, &����ũ�ν�, &�������̵�} };
	���ϸ� ���ǽ�� = { "���ǽ��", 80, 259, {133, 205}, {125, 200}, 280, 259, 3, {&�ʸ���Ʈ1, &����, &����, &������1} };
	struct trainer Me = { {&�۷��̽þ�, &���Ǿ�, &���ǽ��}, 3 };
	struct trainer Red = { {&��ī��, &�Ḹ��, &�źϿ�}, 3 };
	int isDie_me = 0, isDie_Red = 0;
	printf("���ϸ��� ��Ʋ\n");
	system("pause");
	printf("...... ...... ......\n...... ...... ......\n");
	printf("���ϸ� Ʈ���̳� ���尡 �ºθ� �ɾ�Դ�!");
	printf("���ϸ� Ʈ���̳� ����� %s(��)�� �����´�!\n", Red.pokemon[3 - Red.left]->name);
	printf("����! %s!\n", Me.pokemon[3 - Me.left]->name);
	while (1) {
		int skilluse;
		printpoke(Red.pokemon[3 - Red.left]);
		printpoke(Me.pokemon[3 - Me.left]);
		printf("%s��(��) ������ �ұ�?\n", Me.pokemon[3 - Me.left]->name);
		printskill(Me);
		scanf("%d", &skilluse);
		system("cls");
		changeHp(Me.pokemon[3 - Me.left], Red.pokemon[3 - Red.left], skilluse, comskill(), &Me.left, &Red.left, &isDie_me, &isDie_Red);
		if (Me.left == 0) {
			printf("���⿡�Դ� �ο�� �ִ� ���ϸ��� ����!\n");
			printf("...... ...... ......\n");
			printf("������ ������ �Ͼ�����!\n");
			printf("�й�......");
			break;
		}
		else if (Red.left == 0) {
			printf("���ϸ� Ʈ���̳� ������� �ºο��� �̰��!\n");
			printf("...... ...... ......!\n");
			printf("The end\n");
			break;
		}
		if (isDie_Red == 1)  //���ϸ� ������ ���� �������� ���� ����ϴ� �ڵ�
			printf("���ϸ� Ʈ���̳� ����� %s(��)�� �����´�!\n", Red.pokemon[3 - Red.left]->name);
		if (isDie_me == 1)
			printf("����! %s!\n", Me.pokemon[3 - Me.left]->name);
		isDie_me = 0;
		isDie_Red = 0;
	}

	return 0;
}
void changeHp(struct pokemoninfo* po1, struct pokemoninfo* po2, int PlayerUse, int ComUse, int* left1, int* left2, int* Die_me, int* Die_red) {
	int saveDamage = 0; // �ݵ��� �ִ� ����̳� �̷���Ʈ ���� Ư���� ����� ��� ���� �ްų� �� �������� ����� �ʿ䰡 �־� �����ϴ� ���� ����
	switch (WhoIsFirst(po1, po2, PlayerUse, ComUse)) {
	case(1): printf("%s�� %s!\n", po1->name, po1->skillset[PlayerUse]->name); //���� ����
		saveDamage = damage(*po1, *po2, PlayerUse, ��);
		po2->hpnow -= saveDamage;
		printCounter(po1->skillset[PlayerUse]->typeOfSkill, po2->pokeType);
		if (po2->hpnow <= 0) {
			po2->hpnow = 0;
			printpoke(po2); printpoke(po1);
			printf("��� %s�� ��������!\n", po2->name);
			(*left2)--;
			*Die_red = 1;    //���ϸ��� �׾����� �����ϴ� ������ �� ��ȭ
			(*left1) += myself(po1, po2, PlayerUse, ��, saveDamage);  //�ݵ��� ó��, �ݵ��������� �ڽ��� �׾��� �� ���� ���ϸ� �� �ٲٱ�
		}
		else {
			(*left1) += myself(po1, po2, PlayerUse, ��, saveDamage);//���� �ʾƵ� �ݵ� ���� ������ �޾ƾ� ��
			printpoke(po2); printpoke(po1);
			printf("��� %s�� %s!\n", po2->name, po2->skillset[ComUse]->name); //�� ���ݿ��� ���� �ʾ��� �� ����� ��� �ߵ�
			if (po2->skillset[ComUse]->myself != -1) {
				saveDamage = damage(*po2, *po1, ComUse, ����);
				po1->hpnow -= saveDamage;
				printCounter(po2->skillset[ComUse]->typeOfSkill, po1->pokeType);
				if (po1->hpnow <= 0) {
					po1->hpnow = 0;
					printpoke(po2); printpoke(po1);
					printf("%s�� ��������!\n", po1->name);
					(*left1)--;
					*Die_me = 1;
					(*left2) += myself(po2, po1, ComUse, ����, saveDamage);
				}
				(*left2) += myself(po2, po1, ComUse, ����, saveDamage);
			}
			else if (po2->skillset[ComUse]->myself == -1) {   //�̷���Ʈ�� ���� ����� �켱�� ����, �׻� �İ��̹Ƿ� �̶��� ó��
				if (po1->skillset[PlayerUse]->catagory == po2->skillset[ComUse]->catagory) {
					saveDamage *= 2;
					po1->hpnow -= saveDamage;
					if (po1->hpnow <= 0) {
						po1->hpnow = 0;
						printpoke(po2); printpoke(po1);
						printf("%s�� ��������!\n", po1->name);
						(*left1)--;
						*Die_me = 1;
					}
				}
				else
					printf("�׷��� �����ϰ� ���Ҵ�!\n");  //�̷���Ʈ�� Ư��, ����� ����� ���� ����̸� ��� ����� ������
			}
		}
		break;
	case(2): printf("��� %s�� %s!\n", po2->name, po2->skillset[ComUse]->name);
		saveDamage = damage(*po2, *po1, ComUse, ����);
		po1->hpnow -= saveDamage;
		printCounter(po2->skillset[ComUse]->typeOfSkill, po1->pokeType);
		if (po1->hpnow <= 0) {
			po1->hpnow = 0;
			printpoke(po2); printpoke(po1);
			printf("%s�� ��������!\n", po1->name);
			(*left1)--;
			*Die_me = 1;
			(*left2) += myself(po2, po1, ComUse, ����, saveDamage);
		}
		else {
			(*left2) += myself(po2, po1, ComUse, ����, saveDamage);
			printpoke(po2); printpoke(po1);
			printf("%s�� %s!\n", po1->name, po1->skillset[PlayerUse]->name);
			if (po1->skillset[PlayerUse]->myself != -1) {
				po2->hpnow -= damage(*po1, *po2, PlayerUse, ��);
				printCounter(po1->skillset[PlayerUse]->typeOfSkill, po2->pokeType);
				if (po2->hpnow <= 0) {
					po2->hpnow = 0;
					printpoke(po2); printpoke(po1);
					printf("��� %s�� ��������!\n", po2->name);
					(*left2)--;
					*Die_red = 1;
					(*left1) += myself(po1, po2, PlayerUse, ��, saveDamage);
				}
				(*left1) += myself(po1, po2, PlayerUse, ��, saveDamage);
			}
			else if (po1->skillset[PlayerUse]->myself == -1) {
				if (po2->skillset[ComUse]->catagory == po1->skillset[PlayerUse]->catagory) {
					saveDamage *= 2;
					po2->hpnow -= saveDamage;
					if (po2->hpnow <= 0) {
						po2->hpnow = 0;
						printpoke(po2); printpoke(po1);
						printf("��� %s�� ��������!\n", po2->name);
						(*left2)--;
						*Die_red = 1;
					}
				}
				else
					printf("�׷��� �����ϰ� ���Ҵ�!\n");
			}
			break;
		}
	}
}
int comskill() {
	srand(time(NULL));
	int a = rand() % 4;
	return a;
}
void printskill(struct trainer tr1) {
	for (int i = 0; i < 4; i++)
		printf("%d: %s %s\n", i, type[tr1.pokemon[3 - tr1.left]->skillset[i]->typeOfSkill], tr1.pokemon[3 - tr1.left]->skillset[i]->name);
}
void printpoke(struct pokemoninfo* po) {
	printf("%s: %d Lv, Hp: %d/%d\n", po->name, po->level, po->hpnow, po->hpOriginal);
}
int damage(struct pokemoninfo po1, struct pokemoninfo po2, int SkillUse, enum Who wh) { //po1 ->��� ���,  po2 -> ��� ����
	float isSame = 1; // ���� ����� �ڱ� �ڽ��� Ÿ���� ��ġ -> 1.5, �ƴϸ� 1  (�ڼ� ����)
	int percentSave = percentage(po1.skillset[SkillUse]->accuracy);
	if (percentSave == 0) {
		switch (wh) {
		case ��: printf("�׷��� %s�� ������ ��������!", po1.name); break;
		case ����: printf("�׷��� ��� %s�� ������ ��������!", po1.name); break;
		}
	}
	if (po1.pokeType == po1.skillset[SkillUse]->typeOfSkill)
		isSame = 1.5;
	return percentSave * (((po1.skillset[SkillUse]->power) * (po1.attack_special[po1.skillset[SkillUse]->catagory]) * (po1.level * 2 / 5 + 2)) / (po2.defence_special[po1.skillset[SkillUse]->catagory]) / 50 * isSame * isCounter[po1.skillset[SkillUse]->typeOfSkill][po2.pokeType]);
}

void printCounter(int Skilltype, int Poketype) {
	if (isCounter[Skilltype][Poketype] == 2)
		printf("ȿ���� �����ߴ�!\n");
	else if (isCounter[Skilltype][Poketype] == 0.5)
		printf("ȿ���� ������ ���ϴ�...\n");
	else if (isCounter[Skilltype][Poketype] == 0)
		printf("ȿ���� ���� ���ϴ�...\n");
}
int WhoIsFirst(struct pokemoninfo* po1, struct pokemoninfo* po2, int PlayerUse, int ComUse) {//po1->�� ���ϸ� po2->���岨
	if (po1->skillset[PlayerUse]->priority > po2->skillset[ComUse]->priority) //po1�� ����
		return 1;
	else if (po1->skillset[PlayerUse]->priority == po2->skillset[ComUse]->priority) {
		if (po1->speed > po2->speed)  //po1�� ����
			return 1;
		else if (po1->speed < po2->speed)  //po2�� ����
			return 2;
	}
	else  //po2�� ����
		return 2;
}
int percentage(int accuracy) {  //accuracy�� Ȯ�� �޾ƿ�
	srand(time(NULL));
	int a = rand() % 100 + 1;
	if (a <= accuracy)
		return 1; // ��� ����
	else
		return 0;
}
int myself(struct pokemoninfo* po1, struct pokemoninfo* po2, int SkillUse, enum Who wh, int preDamage) {  //preDamage ���� ������ �������� �޾ƿ� ��
	int reboundDam; //�ݵ�������    po1: ������ po2 ������
	if (po1->skillset[SkillUse]->myself > 0) {
		reboundDam = (po1->skillset[SkillUse]->myself) * preDamage;
		po1->hpnow -= reboundDam;
		if (po1->hpnow <= 0) {
			po1->hpnow = 0;
			switch (wh) {  //wh�� ������    wh�� po1�� ������
			case(��):printpoke(po2); printpoke(po1);
				printf("%s�� ������ �ݵ��� �Ծ���!\n", po1->name);
				printf("%s�� ��������!\n", po1->name);
				break;
			case(����):printpoke(po1); printpoke(po2);
				printf("��� %s�� ������ �ݵ��� �Ծ���!\n", po1->name);
				printf("���%s�� ��������!\n", po1->name);
				break;
			}
			return -1;
		}
		switch (wh) {  //wh�� ������    wh�� po1�� ������
		case(��):printpoke(po2); printpoke(po1);
			printf("%s�� ������ �ݵ��� �Ծ���!\n", po1->name);
			break;
		case(����):printpoke(po1); printpoke(po2);
			printf("��� %s�� ������ �ݵ��� �Ծ���!\n", po1->name);
			break;
		}
		return 0;
	}
	return 0;
}