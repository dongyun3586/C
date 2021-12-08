#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
char* type[17] = { "노말", "불꽃", "물", "전기", "풀", "얼음", "격투", "독", "땅", "비행", "에스퍼", "벌레", "바위", "고스트", "드래곤", "악", "강철" };
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
						   1, 0.5, 0.5, 0.5, 1, 2, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 0.5 };   //행 : 공격하는 타입, 열 : 공격받는    저장값 : 효과의 배수(0, 0.5, 1, 2배임)
struct skill {
	char name[100];
	int typeOfSkill;//노말, 불꽃, 물, 전기, 풀, 얼음, 격투, 독, 땅, 비행, 에스퍼, 벌레, 바위, 고스트, 드래곤, 악, 강철 순으로 0부터 자연수
	int priority; // 기술의 우선도
	int power; //위력
	int catagory; //물리(0) 또는 특수(1)
	float myself; //반동 데미지 있으면 자신이 준 데미지의 몇 배인지 저장, 없으면 0 저장
	int accuracy; //명중률 몇 퍼센트인지 저장
};
typedef struct pokemoninfo {
	char name[100];
	int level;
	int hpOriginal; int attack_special[2]; int defence_special[2]; int speed; //공격, 특공/ 방어 특방을 배열로 묶어 저장
	int hpnow;
	int pokeType;
	struct skill* skillset[4];
}포켓몬;
struct trainer {
	struct pokemoninfo* pokemon[3];
	int left; //남은 포켓몬 수
};
enum Who { 나, 레드 };
void changeHp(struct pokemoninfo* po1, struct pokemoninfo* po2, int PlayerUse, int ComUse, int* left1, int* left2); //left1은 나의 남은 포켓몬 수, left2는 레드의 남은 포켓몬 수
int comskill(); //컴퓨터가 사용할 스킬을 랜덤으로 정하기
void printskill(struct trainer tr1); //내 포켓몬의 스킬들 출력
void printpoke(struct pokemoninfo* po); //포켓몬 정보 출력
int damage(struct pokemoninfo po1, struct pokemoninfo po2, int SkillUse, enum Who wh);  //po1이 공격자 po2는 공격받음, 데미지 계산
void printCounter(int Skilltype, int Poketype); //효과가 굉장한지 어쩐지를 알려주는 함수
int WhoIsFirst(struct pokemoninfo* po1, struct pokemoninfo* po2, int PlayerUse, int ComUse);  //선공이 누구인지
int percentage(int accuracy);  //기술의 명중을 결정
int myself(struct pokemoninfo* po1, struct pokemoninfo* po2, int SkillUse, enum Who wh, int preDamage); //반동기 처리 함수
int main() {
	struct skill 볼트태클 = { "볼트태클", 3, 0, 120, 0, 1 / 3, 100 };
	struct skill 전광석화 = { "전광석화", 0, 1, 40, 0, 0, 100 };
	struct skill 아이언테일 = { "아이언테일", 16, 0, 100, 0, 0, 75 };
	struct skill 십만볼트 = { "10만볼트", 3, 0, 95, 1, 0, 100 };
	struct skill 눈보라 = { "눈보라", 5, 0, 120, 1, 0, 70 };
	struct skill 씨폭탄 = { "씨폭탄", 4, 0, 80, 0, 0, 100 };
	struct skill 깨물어부수기 = { "깨물어부수기", 15, 0, 80, 0, 0, 100 };
	struct skill 누르기 = { "누르기", 0, 0, 85, 0, 0, 100 };
	struct skill 하이드로펌프 = { "하이드로펌프", 2, 0, 120, 1, 0, 80 };
	struct skill 러스터캐논 = { "러스터캐논", 16, 0, 80, 1, 0, 100 };
	struct skill 기합구슬 = { "기합구슬", 6, 0, 120, 1, 0, 70 };
	struct skill 악의파동 = { "악의파동", 15, 0, 80, 1, 0, 100 };
	struct skill 얼음뭉치 = { "얼음뭉치", 5, 1, 40, 0, 0, 100 };
	struct skill 냉동빔 = { "냉동빔", 5, 0, 95, 1, 0, 100 };
	struct skill 미러코트 = { "미러코트", 10, -5, 0, 1, -1, 100 }; //미러코트는 반동 멤버에 -1을 저장하여 인식
	struct skill 섀도볼 = { "섀도볼", 13, 0, 80, 1, 0, 100 };
	struct skill 자연의은혜 = { "자연의은혜", 1, 0, 80, 0, 0, 100 };
	struct skill 씨폭탄1 = { "씨폭탄", 4, 0, 80, 0, 0, 100 };
	struct skill 시저크로스 = { "시저크로스", 11, 0, 80, 0, 0, 100 };
	struct skill 리프블레이드 = { "리프블레이드", 4, 0, 90, 0, 0, 100 };
	struct skill 십만볼트1 = { "10만볼트", 3, 0, 95, 1, 0, 100 };
	struct skill 방전 = { "방전", 3, 0, 80, 1, 0, 100 };
	struct skill 번개 = { "번개", 3, 0, 120, 1, 0, 70 };
	struct skill 섀도볼1 = { "섀도볼", 13, 0, 80, 1, 0, 100 };
	포켓몬 피카츄 = { "피카츄", 88, 186, {141, 132}, {93, 112}, 209, 186, 3, {&볼트태클, &아이언테일, &전광석화, &십만볼트} };
	포켓몬 잠만보 = { "잠만보", 82, 379, {210, 137}, {188, 210}, 79, 379, 0, {&눈보라, &씨폭탄, &깨물어부수기, &누르기} };
	포켓몬 거북왕 = { "거북왕", 84, 252, {170, 173}, {199, 207}, 162, 252, 2, {&하이드로펌프, &러스터캐논, &기합구슬, &악의파동} };
	포켓몬 글레이시아 = { "글레이시아", 90, 301, {140, 323}, {231, 203}, 149, 301, 5, {&얼음뭉치, &냉동빔, &미러코트, &섀도볼} };
	포켓몬 리피아 = { "리피아", 83, 269, {233, 127}, {238, 134}, 201, 269, 4, {&자연의은혜, &씨폭탄1, &시저크로스, &리프블레이드} };
	포켓몬 쥬피썬더 = { "쥬피썬더", 80, 259, {133, 205}, {125, 200}, 280, 259, 3, {&십만볼트1, &방전, &번개, &섀도볼1} };
	struct trainer Me = { {&글레이시아, &리피아, &쥬피썬더}, 3 };
	struct trainer Red = { {&피카츄, &잠만보, &거북왕}, 3 };
	int isDie_me = 0, isDie_Red = 0;
	printf("포켓몬스터 배틀\n");
	system("pause");
	printf("...... ...... ......\n...... ...... ......\n");
	printf("포켓몬 트레이너 레드가 승부를 걸어왔다!");
	printf("포켓몬 트레이너 레드는 %s(을)를 내보냈다!\n", Red.pokemon[3 - Red.left]->name);
	printf("가랏! %s!\n", Me.pokemon[3 - Me.left]->name);
	while (1) {
		int skilluse;
		printpoke(Red.pokemon[3 - Red.left]);
		printpoke(Me.pokemon[3 - Me.left]);
		printf("%s은(는) 무엇을 할까?\n", Me.pokemon[3 - Me.left]->name);
		printskill(Me);
		scanf("%d", &skilluse);
		system("cls");
		changeHp(Me.pokemon[3 - Me.left], Red.pokemon[3 - Red.left], skilluse, comskill(), &Me.left, &Red.left, &isDie_me, &isDie_Red);
		if (Me.left == 0) {
			printf("심향에게는 싸울수 있는 포켓몬이 없다!\n");
			printf("...... ...... ......\n");
			printf("심향은 눈앞이 하얘졌다!\n");
			printf("패배......");
			break;
		}
		else if (Red.left == 0) {
			printf("포켓몬 트레이너 레드와의 승부에서 이겼다!\n");
			printf("...... ...... ......!\n");
			printf("The end\n");
			break;
		}
		if (isDie_Red == 1)  //포켓몬 쓰러질 때만 내보내는 문장 출력하는 코드
			printf("포켓몬 트레이너 레드는 %s(을)를 내보냈다!\n", Red.pokemon[3 - Red.left]->name);
		if (isDie_me == 1)
			printf("가랏! %s!\n", Me.pokemon[3 - Me.left]->name);
		isDie_me = 0;
		isDie_Red = 0;
	}

	return 0;
}
void changeHp(struct pokemoninfo* po1, struct pokemoninfo* po2, int PlayerUse, int ComUse, int* left1, int* left2, int* Die_me, int* Die_red) {
	int saveDamage = 0; // 반동이 있는 기술이나 미러코트 같은 특수한 기술의 경우 내가 받거나 준 데미지를 사용할 필요가 있어 저장하는 변수 만듦
	switch (WhoIsFirst(po1, po2, PlayerUse, ComUse)) {
	case(1): printf("%s의 %s!\n", po1->name, po1->skillset[PlayerUse]->name); //나의 선공
		saveDamage = damage(*po1, *po2, PlayerUse, 나);
		po2->hpnow -= saveDamage;
		printCounter(po1->skillset[PlayerUse]->typeOfSkill, po2->pokeType);
		if (po2->hpnow <= 0) {
			po2->hpnow = 0;
			printpoke(po2); printpoke(po1);
			printf("상대 %s는 쓰러졌다!\n", po2->name);
			(*left2)--;
			*Die_red = 1;    //포켓몬이 죽었는지 저장하는 변수의 값 변화
			(*left1) += myself(po1, po2, PlayerUse, 나, saveDamage);  //반동기 처리, 반동데미지로 자신이 죽었을 때 남은 포켓몬 수 바꾸기
		}
		else {
			(*left1) += myself(po1, po2, PlayerUse, 나, saveDamage);//죽지 않아도 반동 의한 데미지 받아야 함
			printpoke(po2); printpoke(po1);
			printf("상대 %s의 %s!\n", po2->name, po2->skillset[ComUse]->name); //위 공격에서 죽지 않았을 때 상대의 기술 발동
			if (po2->skillset[ComUse]->myself != -1) {
				saveDamage = damage(*po2, *po1, ComUse, 레드);
				po1->hpnow -= saveDamage;
				printCounter(po2->skillset[ComUse]->typeOfSkill, po1->pokeType);
				if (po1->hpnow <= 0) {
					po1->hpnow = 0;
					printpoke(po2); printpoke(po1);
					printf("%s는 쓰러졌다!\n", po1->name);
					(*left1)--;
					*Die_me = 1;
					(*left2) += myself(po2, po1, ComUse, 레드, saveDamage);
				}
				(*left2) += myself(po2, po1, ComUse, 레드, saveDamage);
			}
			else if (po2->skillset[ComUse]->myself == -1) {   //미러코트와 같은 기술은 우선도 최하, 항상 후공이므로 이때만 처리
				if (po1->skillset[PlayerUse]->catagory == po2->skillset[ComUse]->catagory) {
					saveDamage *= 2;
					po1->hpnow -= saveDamage;
					if (po1->hpnow <= 0) {
						po1->hpnow = 0;
						printpoke(po2); printpoke(po1);
						printf("%s는 쓰러졌다!\n", po1->name);
						(*left1)--;
						*Die_me = 1;
					}
				}
				else
					printf("그러나 실패하고 말았다!\n");  //미러코트는 특수, 상대의 기술이 물리 기술이면 기술 사용이 실패함
			}
		}
		break;
	case(2): printf("상대 %s의 %s!\n", po2->name, po2->skillset[ComUse]->name);
		saveDamage = damage(*po2, *po1, ComUse, 레드);
		po1->hpnow -= saveDamage;
		printCounter(po2->skillset[ComUse]->typeOfSkill, po1->pokeType);
		if (po1->hpnow <= 0) {
			po1->hpnow = 0;
			printpoke(po2); printpoke(po1);
			printf("%s는 쓰러졌다!\n", po1->name);
			(*left1)--;
			*Die_me = 1;
			(*left2) += myself(po2, po1, ComUse, 레드, saveDamage);
		}
		else {
			(*left2) += myself(po2, po1, ComUse, 레드, saveDamage);
			printpoke(po2); printpoke(po1);
			printf("%s의 %s!\n", po1->name, po1->skillset[PlayerUse]->name);
			if (po1->skillset[PlayerUse]->myself != -1) {
				po2->hpnow -= damage(*po1, *po2, PlayerUse, 나);
				printCounter(po1->skillset[PlayerUse]->typeOfSkill, po2->pokeType);
				if (po2->hpnow <= 0) {
					po2->hpnow = 0;
					printpoke(po2); printpoke(po1);
					printf("상대 %s는 쓰러졌다!\n", po2->name);
					(*left2)--;
					*Die_red = 1;
					(*left1) += myself(po1, po2, PlayerUse, 나, saveDamage);
				}
				(*left1) += myself(po1, po2, PlayerUse, 나, saveDamage);
			}
			else if (po1->skillset[PlayerUse]->myself == -1) {
				if (po2->skillset[ComUse]->catagory == po1->skillset[PlayerUse]->catagory) {
					saveDamage *= 2;
					po2->hpnow -= saveDamage;
					if (po2->hpnow <= 0) {
						po2->hpnow = 0;
						printpoke(po2); printpoke(po1);
						printf("상대 %s는 쓰러졌다!\n", po2->name);
						(*left2)--;
						*Die_red = 1;
					}
				}
				else
					printf("그러나 실패하고 말았다!\n");
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
int damage(struct pokemoninfo po1, struct pokemoninfo po2, int SkillUse, enum Who wh) { //po1 ->기술 사용,  po2 -> 기술 맞음
	float isSame = 1; // 쓰는 기술과 자기 자신의 타입이 일치 -> 1.5, 아니면 1  (자속 보정)
	int percentSave = percentage(po1.skillset[SkillUse]->accuracy);
	if (percentSave == 0) {
		switch (wh) {
		case 나: printf("그러나 %s의 공격은 빗나갔다!", po1.name); break;
		case 레드: printf("그러나 상대 %s의 공격은 빗나갔다!", po1.name); break;
		}
	}
	if (po1.pokeType == po1.skillset[SkillUse]->typeOfSkill)
		isSame = 1.5;
	return percentSave * (((po1.skillset[SkillUse]->power) * (po1.attack_special[po1.skillset[SkillUse]->catagory]) * (po1.level * 2 / 5 + 2)) / (po2.defence_special[po1.skillset[SkillUse]->catagory]) / 50 * isSame * isCounter[po1.skillset[SkillUse]->typeOfSkill][po2.pokeType]);
}

void printCounter(int Skilltype, int Poketype) {
	if (isCounter[Skilltype][Poketype] == 2)
		printf("효과가 굉장했다!\n");
	else if (isCounter[Skilltype][Poketype] == 0.5)
		printf("효과가 별로인 듯하다...\n");
	else if (isCounter[Skilltype][Poketype] == 0)
		printf("효과가 없는 듯하다...\n");
}
int WhoIsFirst(struct pokemoninfo* po1, struct pokemoninfo* po2, int PlayerUse, int ComUse) {//po1->내 포켓몬 po2->레드꺼
	if (po1->skillset[PlayerUse]->priority > po2->skillset[ComUse]->priority) //po1의 선공
		return 1;
	else if (po1->skillset[PlayerUse]->priority == po2->skillset[ComUse]->priority) {
		if (po1->speed > po2->speed)  //po1의 선공
			return 1;
		else if (po1->speed < po2->speed)  //po2의 선공
			return 2;
	}
	else  //po2의 선공
		return 2;
}
int percentage(int accuracy) {  //accuracy에 확률 받아옴
	srand(time(NULL));
	int a = rand() % 100 + 1;
	if (a <= accuracy)
		return 1; // 기술 명중
	else
		return 0;
}
int myself(struct pokemoninfo* po1, struct pokemoninfo* po2, int SkillUse, enum Who wh, int preDamage) {  //preDamage 직전 공격의 데미지를 받아올 것
	int reboundDam; //반동데미지    po1: 공격자 po2 수비자
	if (po1->skillset[SkillUse]->myself > 0) {
		reboundDam = (po1->skillset[SkillUse]->myself) * preDamage;
		po1->hpnow -= reboundDam;
		if (po1->hpnow <= 0) {
			po1->hpnow = 0;
			switch (wh) {  //wh는 공격자    wh가 po1의 소유자
			case(나):printpoke(po2); printpoke(po1);
				printf("%s는 공격의 반동을 입었다!\n", po1->name);
				printf("%s는 쓰러졌다!\n", po1->name);
				break;
			case(레드):printpoke(po1); printpoke(po2);
				printf("상대 %s는 공격의 반동을 입었다!\n", po1->name);
				printf("상대%s는 쓰러졌다!\n", po1->name);
				break;
			}
			return -1;
		}
		switch (wh) {  //wh는 공격자    wh가 po1의 소유자
		case(나):printpoke(po2); printpoke(po1);
			printf("%s는 공격의 반동을 입었다!\n", po1->name);
			break;
		case(레드):printpoke(po1); printpoke(po2);
			printf("상대 %s는 공격의 반동을 입었다!\n", po1->name);
			break;
		}
		return 0;
	}
	return 0;
}