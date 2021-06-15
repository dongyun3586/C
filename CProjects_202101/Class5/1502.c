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
	int numOwl, numRabbit, numTree, numGrass, owl = 100, rabbit = 100, tree = 100, grass = 100, count = 0, random, count2 = 0/*������ �߻� Ƚ��*/, river, final/*�׷��� ��� ����*/;
	//�� ���� ��ü ��                        �� ���� ���ķ�         �ùķ��̼� Ƚ��  ������ �߻��� ���Ǵ� ���� ��       ���� ���� ǥ��
	int owlArr[30] = { 0 }, rabbitArr[30] = { 0 }, grassArr[30] = { 0 }, treeArr[30] = { 0 }, print = 0;;
	srand(time(NULL));

	//���α׷� �� �ùķ��� ����
	printf("���°� �ùķ��̼� ���α׷��Դϴ�\n\n<���°� ���� �����Ͻʽÿ�>\n!!�� �������� �ʱ� ��ü���� 2 �̻�!!\n\n");

	//�ʱ� ���� �Է�
	printf("�ξ��� �ʱ� ��ü�� : ");
	scanf("%d", &numOwl);
	printf("�䳢 �ʱ� ��ü��   : ");
	scanf("%d", &numRabbit);
	printf("Ǯ �ʱ� ��ü��     : ");
	scanf("%d", &numGrass);
	printf("���� �ʱ� ��ü��   : ");
	scanf("%d", &numTree);
	printf("���� ��ġ�Ѵٸ� 1, ��ġ���� �ʴ´ٸ� 0�� �Է��Ͻʽÿ� : ");
	scanf("%d", &river);

	//�ȳ�
	printf("\n�Է°��� ��� �ԷµǾ����ϴ�. ���� ������ �Ϻ� ���� ���ķ��� ������ �ݴϴ�.\n�ùķ��̼� ����� ����մϴ�.\n\n");

	while (1) {
		//���ķ� ��ȭ �Լ� ������
		owl = determineFertilityRateOwl(owl, numRabbit, numOwl);
		owl = determineFertilityRateOwl2(owl, numTree, numOwl);
		rabbit = determineFertilityRateRabbit(rabbit, numOwl, numRabbit);
		rabbit = determineFertilityRateRabbit2(rabbit, numGrass, numRabbit);
		grass = determineFertilityRateGrass(grass, numRabbit, numGrass);
		grass = determineFertilityRateGrass2(grass, numTree, numGrass);
		tree = determineFertilityRateTree(tree, numGrass, numTree);
		tree = determineFertilityRateTree2(tree, numOwl, numTree);

		//���� ���� ����Ͽ� 2�� ���ķ� ����
		if (river) {
			rabbit = rabbit * 11 / 10;
			grass = grass * 13 / 10;
			tree = tree * 6 / 5;
		}

		//1/100Ȯ���� ������ �߻�, 3�� ���ķ� ����
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

		//���ķ��� �����Ͽ� ��ü�� ��ȭ
		numOwl = numOwl * owl / 100;
		numRabbit = numRabbit * rabbit / 100;
		numGrass = numGrass * grass / 100;
		numTree = numTree * tree / 100;

		//��� ���
		count++;
		printf("%dȸ", count);
		printf("\n�ξ��� ��ü�� : %7d", numOwl);
		printf("\n�䳢 ��ü��   : %7d", numRabbit);
		printf("\nǮ ��ü��     : %7d", numGrass);
		printf("\n���� ��ü��   : %7d", numTree);

		//�������� �߻��ߴٸ� ������ �˸� ���
		switch (random) {
		case 1:
			printf("\n#������ : �ξ��� ���ķ��� �����Ͽ����ϴ�");
			break;
		case 2:
			printf("\n#������ : �䳢 ���ķ��� �����Ͽ����ϴ�");
			break;
		case 3:
			printf("\n#������ : Ǯ ���ķ��� �����Ͽ����ϴ�");
			break;
		case 4:
			printf("\n#������ : ���� ���ķ��� �����Ͽ����ϴ�");
			break;
		}

		printf("\n\n\n");

		//�� ���� ���� ȸ���� ���ķ� ����
		owlArr[count] = owl / 10 + 1;
		rabbitArr[count] = rabbit / 10 + 1;
		grassArr[count] = grass / 10 + 1;
		treeArr[count] = tree / 10 + 1;

		//������ ���� ���� Ȯ��
		if (numOwl <= 1 || numRabbit <= 1 || numGrass <= 1 || numTree <= 1)
			break;
	}

	//���α׷� ����
	printf("\n\n\n�������� %dȸ �߻�\n\n%dȸ�� ���°� ������ �ı��˴ϴ�\n\n", count2, count);

	//���� ��� ���� �׷��� ���
	printf("���� ��� �׷����� ����Ͻðڽ��ϱ�? ����� ���Ѵٸ� 1, ������ �ʴ´ٸ� 0�� �Է��Ͻʽÿ� : ");
	scanf("%d", &final);

	if (final) {
		printf("\n\n<<���� ���>>\n\n");
		numOwl = numOwl / 10 + 1;
		numRabbit = numRabbit / 10 + 1;
		numGrass = numGrass / 10 + 1;
		numTree = numTree / 10 + 1;
		int i = numOwl + numRabbit + numGrass + numTree;

		printf("�ξ���  �䳢   Ǯ   ����\n");

		for (i; i > 0; i) {
			if (numOwl > 0) {
				printf("  ��     ");
				numOwl--;
				i--;
			}
			else
				printf("         ");

			if (numRabbit > 0) {
				printf("��    ");
				numRabbit--;
				i--;
			}
			else
				printf("      ");

			if (numGrass > 0) {
				printf("��     ");
				numGrass--;
				i--;
			}
			else
				printf("       ");

			if (numTree > 0) {
				printf("��");
				numTree--;
				i--;
			}

			printf("\n");
		}

	}

	//���ķ� ��ȭ ���� �׷��� ���
	printf("\n\n�ξ��� ���ķ� ��ȭ �׷����� ����Ͻðڽ��ϱ�? ����� ���Ѵٸ� 1, ������ �ʴ´ٸ� 0�� �Է��Ͻʽÿ� : ");
	scanf("%d", &final);
	if (final) {
		printf("\n\n<<�ξ��� ���ķ� ��ȭ>>\n***���ķ��� 350%������ ǥ�õ˴ϴ�\n\n");

		for (int i = 35; i > 0; i--) {       //i = owlArr[0~length], 0<i<35
			int k = i * 10;
			printf("%3d", k);
			for (int j = 1; j <= count; j++) {       //j = 0~length
				if (i <= owlArr[j]) {
					printf("��");
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

	printf("\n\n�䳢 ���ķ� ��ȭ �׷����� ����Ͻðڽ��ϱ�? ����� ���Ѵٸ� 1, ������ �ʴ´ٸ� 0�� �Է��Ͻʽÿ� : ");
	scanf("%d", &final);
	if (final) {
		printf("\n\n<<�䳢 ���ķ� ��ȭ>>\n***���ķ��� 350%������ ǥ�õ˴ϴ�\n\n");

		for (int i = 35; i > 0; i--) {
			int k = i * 10;
			printf("%3d", k);
			for (int j = 1; j <= count; j++) {
				if (i <= rabbitArr[j]) {
					printf("��");
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

	printf("\n\nǮ ���ķ� ��ȭ �׷����� ����Ͻðڽ��ϱ�? ����� ���Ѵٸ� 1, ������ �ʴ´ٸ� 0�� �Է��Ͻʽÿ� : ");
	scanf("%d", &final);
	if (final) {
		printf("\n\n<<Ǯ ���ķ� ��ȭ>>\n***���ķ��� 350%������ ǥ�õ˴ϴ�\n\n");

		for (int i = 35; i > 0; i--) {
			int k = i * 10;
			printf("%3d", k);
			for (int j = 1; j <= count; j++) {
				if (i <= grassArr[j]) {
					printf("��");
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

	printf("\n\n���� ���ķ� ��ȭ �׷����� ����Ͻðڽ��ϱ�? ����� ���Ѵٸ� 1, ������ �ʴ´ٸ� 0�� �Է��Ͻʽÿ� : ");
	scanf("%d", &final);
	if (final) {
		printf("\n\n<<���� ���ķ� ��ȭ>>\n***���ķ��� 350%������ ǥ�õ˴ϴ�\n\n");

		for (int i = 35; i > 0; i--) {
			int k = i * 10;
			printf("%3d", k);
			for (int j = 1; j <= count; j++) {
				if (i <= treeArr[j]) {
					printf("��");
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

	//���� �˸�
	printf("\n\n\n<�ùķ��̼��� ����˴ϴ�>\n\n\n");
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