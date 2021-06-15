#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int determineFertilityRateOwl(int owl, int numRabbit, int numOwl);
int determineFertilityRateOwl2(int owl, int numTree, int numOwl);
int determineFertilityRateRabbit(int rabbit, int numOwl, int numRabbit);
int determineFertilityRateRabbit2(int rabbit, int numGrass, int numRabbit);
int determineFertilityRateGrass(int grass, int numRabbit, int numGrass);
int determineFertilityRateGrass2(int grass, int numTree, int numGrass);
int determineFertilityRateTree(int tree, int numGrass, int numTree);
int determineFertilityRateTree2(int tree, int numOwl, int numTree);

int main() {
	int numOwl, numRabbit, numTree, numGrass, owl = 100, rabbit = 100, tree = 100, grass = 100, count = 0, random, count2 = 0/*전염병 발생 횟수*/, river, final/*그래프 출력 여부*/;
	//각 종의 개체 수                        각 종의 번식률         시뮬레이션 횟수  전염병 발생에 사용되는 랜덤 값       강의 유뮤 표시
	int owlArr[30] = { 0 }, rabbitArr[30] = { 0 }, grassArr[30] = { 0 }, treeArr[30] = { 0 }, print = 0;;
	srand(time(NULL));

	//프로그램 및 시뮬레션 설명
	printf("생태계 시뮬레이션 프로그램입니다\n\n<생태계 모델을 설정하십시오>\n!!각 생물종의 초기 개체수는 2 이상!!\n\n");

	//초기 상태 입력
	printf("부엉이 초기 개체수 : ");
	scanf("%d", &numOwl);
	printf("토끼 초기 개체수   : ");
	scanf("%d", &numRabbit);
	printf("풀 초기 개체수     : ");
	scanf("%d", &numGrass);
	printf("나무 초기 개체수   : ");
	scanf("%d", &numTree);
	printf("강을 배치한다면 1, 배치하지 않는다면 0를 입력하십시오 : ");
	scanf("%d", &river);

	//안내
	printf("\n입력값이 모두 입력되었습니다. 강의 유무는 일부 종의 번식률에 영향을 줍니다.\n시뮬레이션 결과를 출력합니다.\n\n");

	while (1) {
		//번식률 변화 함수 돌리기
		owl = determineFertilityRateOwl(owl, numRabbit, numOwl);
		owl = determineFertilityRateOwl2(owl, numTree, numOwl);
		rabbit = determineFertilityRateRabbit(rabbit, numOwl, numRabbit);
		rabbit = determineFertilityRateRabbit2(rabbit, numGrass, numRabbit);
		grass = determineFertilityRateGrass(grass, numRabbit, numGrass);
		grass = determineFertilityRateGrass2(grass, numTree, numGrass);
		tree = determineFertilityRateTree(tree, numGrass, numTree);
		tree = determineFertilityRateTree2(tree, numOwl, numTree);

		//강의 유무 고려하여 2차 번식률 조정
		if (river) {
			rabbit = rabbit * 11 / 10;
			grass = grass * 13 / 10;
			tree = tree * 6 / 5;
		}

		//1/100확률로 전염병 발생, 3차 번식률 조정
		random = rand() % 100;
		switch (random) {
		case 1:
			owl = owl / 2;
			count2++;
			break;
		case 2:
			rabbit = rabbit / 2;
			count2++;
			break;
		case 3:
			grass = grass / 2;
			count2++;
			break;
		case 4:
			tree = tree / 2;
			count2++;
			break;
		}

		//번식률을 대입하여 개체수 변화
		numOwl = numOwl * owl / 100;
		numRabbit = numRabbit * rabbit / 100;
		numGrass = numGrass * grass / 100;
		numTree = numTree * tree / 100;

		//결과 출력
		count++;
		printf("%d회", count);
		printf("\n부엉이 개체수 : %7d", numOwl);
		printf("\n토끼 개체수   : %7d", numRabbit);
		printf("\n풀 개체수     : %7d", numGrass);
		printf("\n나무 개체수   : %7d", numTree);

		//전염병이 발생했다면 전염병 알림 출력
		switch (random) {
		case 1:
			printf("\n#전염병 : 부엉이 번식률이 감소하였습니다");
			break;
		case 2:
			printf("\n#전염병 : 토끼 번식률이 감소하였습니다");
			break;
		case 3:
			printf("\n#전염병 : 풀 번식률이 감소하였습니다");
			break;
		case 4:
			printf("\n#전염병 : 나무 번식률이 감소하였습니다");
			break;
		}

		printf("\n\n\n");

		//각 종에 대한 회차의 번식률 저장
		owlArr[count] = owl / 10 + 1;
		rabbitArr[count] = rabbit / 10 + 1;
		grassArr[count] = grass / 10 + 1;
		treeArr[count] = tree / 10 + 1;

		//멸종종 존재 여부 확인
		if (numOwl <= 1 || numRabbit <= 1 || numGrass <= 1 || numTree <= 1)
			break;
	}

	//프로그램 종료
	printf("\n\n\n전염병은 %d회 발생\n\n%d회에 생태계 균형이 파괴됩니다\n\n", count2, count);

	//최종 결과 막대 그래프 출력
	printf("최종 결과 그래프를 출력하시겠습니까? 출력을 원한다면 1, 원하지 않는다면 0을 입력하십시오 : ");
	scanf("%d", &final);

	if (final) {
		printf("\n\n<<최종 결과>>\n\n");
		numOwl = numOwl / 10 + 1;
		numRabbit = numRabbit / 10 + 1;
		numGrass = numGrass / 10 + 1;
		numTree = numTree / 10 + 1;
		int i = numOwl + numRabbit + numGrass + numTree;

		printf("부엉이  토끼   풀   나무\n");

		for (i; i > 0; i) {
			if (numOwl > 0) {
				printf("  ■     ");
				numOwl--;
				i--;
			}
			else
				printf("         ");

			if (numRabbit > 0) {
				printf("■    ");
				numRabbit--;
				i--;
			}
			else
				printf("      ");

			if (numGrass > 0) {
				printf("■     ");
				numGrass--;
				i--;
			}
			else
				printf("       ");

			if (numTree > 0) {
				printf("■");
				numTree--;
				i--;
			}

			printf("\n");
		}

	}

	//번식률 변화 막대 그래프 출력
	printf("\n\n부엉이 번식률 변화 그래프를 출력하시겠습니까? 출력을 원한다면 1, 원하지 않는다면 0을 입력하십시오 : ");
	scanf("%d", &final);
	if (final) {
		printf("\n\n<<부엉이 번식률 변화>>\n***번식률은 350%까지만 표시됩니다\n\n");

		for (int i = 35; i > 0; i--) {       //i = owlArr[0~length], 0<i<35
			int k = i * 10;
			printf("%3d", k);
			for (int j = 1; j <= count; j++) {       //j = 0~length
				if (i <= owlArr[j]) {
					printf("■");
					owlArr[j]--;
				}
				else printf("  ");
			}
			printf("\n");
		}
		printf("  ");
		for (int i = 1; i <= count; i++) {
			printf("%d ", i);
		}

	}

	printf("\n\n토끼 번식률 변화 그래프를 출력하시겠습니까? 출력을 원한다면 1, 원하지 않는다면 0을 입력하십시오 : ");
	scanf("%d", &final);
	if (final) {
		printf("\n\n<<토끼 번식률 변화>>\n***번식률은 350%까지만 표시됩니다\n\n");

		for (int i = 35; i > 0; i--) {
			int k = i * 10;
			printf("%3d", k);
			for (int j = 1; j <= count; j++) {
				if (i <= rabbitArr[j]) {
					printf("■");
					rabbitArr[j]--;
				}
				else printf("  ");
			}
			printf("\n");
		}
		printf("  ");
		for (int i = 1; i <= count; i++) {
			printf("%d ", i);
		}
	}

	printf("\n\n풀 번식률 변화 그래프를 출력하시겠습니까? 출력을 원한다면 1, 원하지 않는다면 0을 입력하십시오 : ");
	scanf("%d", &final);
	if (final) {
		printf("\n\n<<풀 번식률 변화>>\n***번식률은 350%까지만 표시됩니다\n\n");

		for (int i = 35; i > 0; i--) {
			int k = i * 10;
			printf("%3d", k);
			for (int j = 1; j <= count; j++) {
				if (i <= grassArr[j]) {
					printf("■");
					grassArr[j]--;
				}
				else printf("  ");
			}
			printf("\n");
		}
		printf("  ");
		for (int i = 1; i <= count; i++) {
			printf("%d ", i);
		}
	}

	printf("\n\n나무 번식률 변화 그래프를 출력하시겠습니까? 출력을 원한다면 1, 원하지 않는다면 0을 입력하십시오 : ");
	scanf("%d", &final);
	if (final) {
		printf("\n\n<<나무 번식률 변화>>\n***번식률은 350%까지만 표시됩니다\n\n");

		for (int i = 35; i > 0; i--) {
			int k = i * 10;
			printf("%3d", k);
			for (int j = 1; j <= count; j++) {
				if (i <= treeArr[j]) {
					printf("■");
					treeArr[j]--;
				}
				else printf("  ");
			}
			printf("\n");
		}
		printf("  ");
		for (int i = 1; i <= count; i++) {
			printf("%d ", i);
		}
	}

	//종료 알림
	printf("\n\n\n<시뮬레이션이 종료됩니다>\n\n\n");
	return 0;
}


int determineFertilityRateOwl(int owl, int numRabbit, int numOwl) {
	if (numRabbit / numOwl >= 3)
		owl = 300;
	else if (numRabbit / numOwl >= 2)
		owl = 250;
	else if (numRabbit * 2 / numOwl >= 3)
		owl = 135;
	else if (numRabbit * 5 / numOwl >= 6)
		owl = 87;
	else if (numRabbit / numOwl >= 1)
		owl = 65;
	else if (numRabbit * 3 / numOwl >= 2)
		owl = 45;
	else if (numRabbit * 3 / numOwl >= 1)
		owl = 20;
	else owl = 12;

	return owl;
}

int determineFertilityRateOwl2(int owl, int numTree, int numOwl) {
	if (numTree * 20 / numOwl <= 1)
		owl = owl / 10;
	else if (numTree * 5 / numOwl <= 1)
		owl = owl * 1 / 3;
	else if (numTree * 5 / numOwl <= 2)
		owl = owl * 2 / 5;
	else if (numTree * 5 / numOwl <= 3)
		owl = owl * 5 / 7;
	else if (numTree * 5 / numOwl <= 4)
		owl = owl;
	else if (numTree / numOwl <= 1)
		owl = owl * 7 / 6;
	else if (numTree * 4 / numOwl <= 5)
		owl = owl * 6 / 5;
	else if (numTree * 2 / numOwl <= 3)
		owl = owl * 7 / 5;
	else if (numTree * 10 / numOwl <= 7)
		owl = owl * 9 / 5;
	else if (numTree / numOwl <= 2)
		owl = owl * 2;
	else if (numTree * 2 / numOwl <= 5)
		owl = owl * 5 / 2;
	return owl;
}

int determineFertilityRateRabbit(int rabbit, int numOwl, int numRabbit) {
	if (numOwl * 10 / numRabbit <= 1)
		rabbit = 330;
	else if (numOwl * 7 / numRabbit <= 1)
		rabbit = 280;
	else if (numOwl * 5 / numRabbit <= 1)
		rabbit = 130;
	else if (numOwl * 3 / numRabbit <= 1)
		rabbit = 110;
	else if (numOwl * 3 / numRabbit <= 2)
		rabbit = 95;
	else if (numOwl * 11 / numRabbit <= 10)
		rabbit = 110;
	else if (numOwl * 5 / numRabbit <= 6)
		rabbit = 85;
	else if (numOwl * 5 / numRabbit <= 7)
		rabbit = 70;
	else if (numOwl * 5 / numRabbit <= 9)
		rabbit = 50;
	else if (numOwl * 5 / numRabbit <= 10)
		rabbit = 40;
	else rabbit = 20;
	return rabbit;
}

int determineFertilityRateRabbit2(int rabbit, int numGrass, int numRabbit) {
	if (numGrass * 5 / numRabbit <= 1)
		rabbit = rabbit * 1 / 10;
	else if (numGrass * 5 / numRabbit <= 3)
		rabbit = rabbit * 1 / 8;
	else if (numGrass * 5 / numRabbit <= 4)
		rabbit = rabbit * 3 / 5;
	else if (numGrass / numRabbit <= 1)
		rabbit = rabbit * 7 / 10;
	else if (numGrass * 5 / numRabbit <= 6)
		rabbit = rabbit * 85 / 100;
	else if (numGrass * 5 / numRabbit <= 7)
		rabbit = rabbit;
	else if (numGrass * 5 / numRabbit <= 8)
		rabbit = rabbit * 5 / 3;
	else if (numGrass * 5 / numRabbit <= 9)
		rabbit = rabbit * 2;
	else if (numGrass / numRabbit <= 2)
		rabbit = rabbit * 5 / 2;
	else rabbit = rabbit * 3;
	return rabbit;
}

int determineFertilityRateGrass(int grass, int numRabbit, int numGrass) {
	if (numRabbit * 2 / numGrass >= 5)
		grass = 10;
	else if (numRabbit / numGrass >= 2)
		grass = 25;
	else if (numRabbit * 2 / numGrass >= 3)
		grass = 35;
	else if (numRabbit / numGrass >= 1)
		grass = 50;
	else if (numRabbit * 5 / numGrass >= 4)
		grass = 90;
	else if (numRabbit * 8 / numGrass >= 3)
		grass = 145;
	else if (numRabbit * 10 / numGrass >= 1)
		grass = 180;
	else if (numRabbit * 20 / numGrass >= 1)
		grass = 220;
	else grass = 250;
	return grass;
}

int determineFertilityRateGrass2(int grass, int numTree, int numGrass) {
	if (numTree * 30 / numGrass <= 1)
		grass = grass * 1 / 2;
	else if (numTree * 2 / numGrass >= 5)
		grass = grass * 3 / 5;
	else if (numTree * 2 / numGrass >= 4)
		grass = grass * 7 / 10;
	else if (numTree * 2 / numGrass >= 3)
		grass = grass * 4 / 5;
	else if (numTree * 5 / numGrass >= 7)
		grass = grass * 9 / 10;
	else if (numTree / numGrass >= 1)
		grass = grass * 19 / 20;
	else if (numTree * 5 / numGrass >= 4)
		grass = grass * 21 / 20;
	else if (numTree * 5 / numGrass >= 3)
		grass = grass * 22 / 20;
	else if (numTree * 5 / numGrass >= 2)
		grass = grass * 23 / 20;
	else if (numTree * 3 / numGrass >= 1)
		grass = grass * 5 / 4;
	else grass = grass * 3 / 2;
	return grass;
}

int determineFertilityRateTree(int tree, int numGrass, int numTree) {
	if (numGrass / numTree >= 5)
		tree = 70;
	else if (numGrass * 2 / numTree >= 5)
		tree = 75;
	else if (numGrass * 2 / numTree >= 3)
		tree = 95;
	else if (numGrass * 5 / numTree >= 7)
		tree = 105;
	else if (numGrass / numTree >= 1)
		tree = 120;
	else if (numGrass * 5 / numTree >= 4)
		tree = 135;
	else if (numGrass * 5 / numTree >= 3)
		tree = 165;
	else if (numGrass * 5 / numTree >= 2)
		tree = 175;
	else if (numGrass * 20 / numTree >= 1)
		tree = 400;
	else tree = 185;
	return tree;
}

int determineFertilityRateTree2(int tree, int numOwl, int numTree) {
	if (numOwl * 3 / numTree <= 1)
		tree = tree * 2 / 3;
	else if (numOwl * 2 / numTree <= 1)
		tree = tree * 2;
	else if (numOwl * 5 / numTree <= 3)
		tree = tree * 7 / 5;
	else if (numOwl * 5 / numTree <= 4)
		tree = tree * 4 / 5;
	else if (numOwl / numTree <= 1)
		tree = tree * 1 / 3;
	else if (numOwl * 5 / numTree <= 7)
		tree = tree * 3 / 14;
	else if (numOwl * 5 / numTree <= 9)
		tree = tree * 1 / 20;
	return tree;
}