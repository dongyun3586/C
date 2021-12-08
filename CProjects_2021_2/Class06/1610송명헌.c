#include <stdio.h>
#include <string.h>

void jumsuCalculator(float jumsu, float* sum);
void hakjumCalculator(char hakjum[], float* sum, int b);
int isuhakjumSum(int b, int* isusum);

int main() {
	printf("본 프로그램은 영재학교 재학생들을 위해 제작되었습니다.\n\n");

	printf("시험은 잘 보셨나요?\n");
	int ans;
	printf("1 : 참\n2 : 거짓\n");
	scanf("%d", &ans);

	if (ans == 1) {
		printf("기쁜 마음으로 성적을 입력하실 수 있겠어요.\n\n");
	}
	else if (ans == 2) {
		printf("냉철한 자기 판단을 위한 성적 산출을 도와드리겠습니다.\n\n");
	}
	else {
		printf("\n");
	}

	int re = 1;

	while (re == 1) {
		printf("-----------------------------------------------------\n\n");
		printf("어떤 성적을 확인하고 싶으신가요?\n");
		int choice;
		printf("1 : 평균\n2: 평점평균\n");
		scanf("%d", &choice);

		if (choice == 1 || choice == 2) {
			printf("\n***각 성적을 입력할 때마다 enter키를 누르세요***\n\n");

			if (choice == 1) {
				printf("점수를 모두 입력해 주세요\n");
				printf("(모든 입력이 끝나면 '999'를 입력해 주시기 바랍니다)\n");
				float jumsu = 0;
				float sumj = 0;
				int a = 0;
				float mean;

				while (jumsu != 999) {
					scanf("%f", &jumsu);
					jumsuCalculator(jumsu, &sumj);
					a++;
				}
				sumj -= 999;
				mean = sumj / (a - 1);
				printf("평균은 %f점 입니다.\n", mean);
			}

			else if (choice == 2) {
				printf("각 과목의 등급과 이수 학점을 입력해 주세요(등급 입력 후에도 enter입력)\n");
				printf("(모든 입력이 끝나면 'gg, 0'을 입력해 주시기 바랍니다)\n");
				char hakjum[3] = { 0 };
				float sumh = 0;
				int b = 0;
				int isusum = 0;
				float grade;

				while (strcmp(hakjum, "gg") != 0) {
					rewind(stdin);
					fgets(hakjum, 3, stdin);
					scanf("%d", &b);
					hakjumCalculator(hakjum, &sumh, b);
					isuhakjumSum(b, &isusum);
				}
				grade = sumh / isusum;
				printf("평점평균은 %f점 입니다.\n", grade);
			}
		}

		else {
			printf("다시 입력해주세요\n\n");
			continue;
		}

		printf("\n나머지 성적도 확인하실 건가요?\n");
		printf("1 : 참\n2 : 거짓\n");
		scanf("%d", &re);
		printf("\n");
	}

	printf("*************************\n");
	printf("이용해 주셔서 감사합니다\n\n");
	printf("힘들어도 항상 힘내세요!!!\n");
	printf("*************************\n");
}

void jumsuCalculator(float jumsu, float* sum) {
	*sum += jumsu;
}

void hakjumCalculator(char hakjum[], float* sum, int b) {
	float k = 0;
	if (strcmp(hakjum, "A+") == 0) {
		k = 4.3;
	}
	else if (strcmp(hakjum, "A0") == 0) {
		k = 4.0;
	}
	else if (strcmp(hakjum, "A-") == 0) {
		k = 3.7;
	}
	else if (strcmp(hakjum, "B+") == 0) {
		k = 3.3;
	}
	else if (strcmp(hakjum, "B0") == 0) {
		k = 3.0;
	}
	else if (strcmp(hakjum, "B-") == 0) {
		k = 2.7;
	}
	else if (strcmp(hakjum, "C+") == 0) {
		k = 2.3;
	}
	*sum += k * b;
}

int isuhakjumSum(int b, int* isusum) {
	*isusum += b;
}