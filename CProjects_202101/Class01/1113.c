#include<stdio.h>

int Calculate1(int num1, int num2);
int Calculate2(int num);

int main() {
	int kind, num1, num2, i, num;

	printf("****** 유전형질의 종류 ******\n");
	printf("1.색맹\n2.혈우병\n3.곱슬/생머리\n4.분리/부착귓불\n5.혀말기 여부\n6.V자형/민자형 머리선\n7.쌍꺼풀 여부\n8.보조개 여부\n9.대머리 여부\n10.주근깨 여부");
	printf("\n발현 형질의 동형접합과 이형접합의 확률은 동일하게 계산하였습니다.");
	printf("\n계산되는 확률은 첫번째 발현형입니다.");
	printf("\n*****************************");

	printf("\n확인하고자 하는 형질의 종류를 입력하세요: ");
	scanf("%d", &kind);
	switch (kind) {
	case 1:
		printf("\n\n부모님의 유전형을 입력해주세요.\n 1.색맹O    2.색맹X");
		printf("\n아버지: ");
		scanf("%d", &num1);
		printf("어머니: ");
		scanf("%d", &num2);

		Calculate1(num1, num2);

		return 0;
		break;

	case 2:
		printf("\n\n부모님의 유전형을 입력해주세요.\n 1.혈우병O    2.혈우병X");
		printf("\n아버지: ");
		scanf("%d", &num1);
		printf("어머니: ");
		scanf("%d", &num2);

		Calculate1(num1, num2);

		return 0;
		break;

	case 3:
		printf("\n\n부모님의 유전형을 입력해주세요.\n 1.곱슬머리   2.생머리");
		printf("\n아버지: ");
		scanf("%d", &num1);
		printf("어머니: ");
		scanf("%d", &num2);
		num = num1 + num2;

		Calculate2(num);

		return 0;
		break;

	case 4:
		printf("\n\n부모님의 유전형을 입력해주세요.\n 1.분리귓불   2.부착귓불");
		printf("\n아버지: ");
		scanf("%d", &num1);
		printf("어머니: ");
		scanf("%d", &num2);
		num = num1 + num2;

		Calculate2(num);

		return 0;
		break;

	case 5:
		printf("\n\n부모님의 유전형을 입력해주세요.\n 1.혀말기 가능   2.혀말기 불가능");
		printf("\n아버지: ");
		scanf("%d", &num1);
		printf("어머니: ");
		scanf("%d", &num2);
		num = num1 + num2;

		Calculate2(num);

		return 0;
		break;

	case 6:
		printf("\n\n부모님의 유전형을 입력해주세요.\n 1.V자형 머리선   2.민자형 머리선");
		printf("\n아버지: ");
		scanf("%d", &num1);
		printf("어머니: ");
		scanf("%d", &num2);
		num = num1 + num2;

		Calculate2(num);

		return 0;
		break;

	case 7:
		printf("\n\n부모님의 유전형을 입력해주세요.\n 1.쌍꺼풀 있음   2.쌍꺼풀 없음");
		printf("\n아버지: ");
		scanf("%d", &num1);
		printf("어머니: ");
		scanf("%d", &num2);
		num = num1 + num2;

		Calculate2(num);

		return 0;
		break;

	case 8:
		printf("\n\n부모님의 유전형을 입력해주세요.\n 1.보조개 있음   2.보조개 없음");
		printf("\n아버지: ");
		scanf("%d", &num1);
		printf("어머니: ");
		scanf("%d", &num2);
		num = num1 + num2;

		Calculate2(num);

		return 0;
		break;

	case 9:
		printf("\n\n부모님의 유전형을 입력해주세요.\n 1.대머리   2.대머리 아님");
		printf("\n아버지: ");
		scanf("%d", &num1);
		printf("어머니: ");
		scanf("%d", &num2);
		num = num1 + num2;

		Calculate2(num);

		return 0;
		break;

	case 10:
		printf("\n\n부모님의 유전형을 입력해주세요.\n 1.주근깨 있음   2.주근깨 없음");
		printf("\n아버지: ");
		scanf("%d", &num1);
		printf("어머니: ");
		scanf("%d", &num2);
		num = num1 + num2;

		Calculate2(num);

		return 0;
		break;

	}
	return 0;
}

int Calculate1(int num1, int num2) {
	int a, b, c;
	if (num1 == 1) {
		if (num2 == 1) {
			printf("[발현확률] 남아: 100%%    여아: 100%%");
		}
		else
			printf("[발현확률] 남아: 25%%   여아: 25%% (보인자일 확률: 75%%)");
	}
	else {
		if (num2 == 1) {
			printf("[발현확률] 남아: 50%%   여아: 0%% (보인자일 확률: 100%%)");
		}
		else
			printf("[발현확률] 남아: 25%%   여아: 0%% (보인자일 확률: 25%%)");
	}
	return num1, num2;
}

int Calculate2(int num) {
	if (num == 2)
		printf("[발현확률] 0%%");
	if (num == 3)
		printf("[발현확률] 75%%");
	if (num == 4)
		printf("[발현확률] 91.7%%");
	return num;
}