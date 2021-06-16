#include <stdio.h>
#include <math.h>
#include <time.h>

int main() {
	int ggh = 1;

	while (ggh == 1) {
		int Q;
		printf("무엇이 궁금하신가요?\n");
		printf("<1> : 계산기\n<2> : 오차율 구하기\n<3>: 어떤 선택을 해야 할까요?\n");
		scanf("%d", &Q);

		//<1> : 계산기
		if (Q == 1) {
			int n;
			int count = 0;

			//계산 선택
			do {
				if (count == 1)
					printf("\n무슨 말씀을 하시는지 모르겠어요\n\n다시 입력해주세요\n");
				printf("하고 싶은 계산을 선택해주세요\n");
				printf("1 : 사칙연산\n2 : 거듭제곱\n");
				scanf("%d", &n);
				if (n != 1 && n != 2)
					count = 1;
			} while (n != 1 && n != 2);//잘못 입력했을 경우 다시 질문 받기

			//1 : 사칙연산
			if (n == 1) {
				float a, b;
				char operator=0;

				printf("하고 싶은 연산을 입력하세요\n");
				scanf(" %c", &operator);

				//더하기
				if (operator == '+') {
					printf("더하고 싶은 수를 입력하세요 ");
					scanf("%f %f", &a, &b);
					printf("\n%f", a + b);
				}

				//빼기
				if (operator == '-') {
					printf("빼고 싶은 수를 입력하세요 ");
					scanf("%f %f", &a, &b);
					printf("\n%f", a - b);
				}

				//곱하기
				if (operator == '*') {
					printf("곱하고 싶은 수를 입력하세요 ");
					scanf("%f %f", &a, &b);
					printf("\n%f", a * b);
				}

				//나누기
				if (operator == '/') {
					printf("나누고 싶은 수를 입력하세요 ");
					scanf("%f %f", &a, &b);
					printf("\n%f", a / b);
				}
			}

			//2 : 거듭제곱
			if (n == 2) {
				double a, b;
				printf("몇의 몇제곱? ");
				scanf("%lf %lf", &a, &b);
				printf("\n%lf", pow(a, b));
			}
		}

		//<2> : 오차율 구하기
		else if (Q == 2) {
			float meaval, trueval, pererror;
			printf("실험값 : ");
			scanf("%f", &meaval);
			printf("이론값 : ");
			scanf("%f", &trueval);
			pererror = ((trueval - meaval) / trueval) * 100;
			if (pererror < 0)
				pererror = -pererror;
			printf("\n%f %%", pererror);
		}

		//<3> : 어떤 선택을 해야 할까요?
		else if (Q == 3) {
			char a[50], b[50], c;
			printf("선택장애가 온 당신!\n");
			printf("선택지에는 무엇이 있나요?(두 가지 선택지를 입력해주세요)\n");
			printf("1 : ");
			scanf("%s", a);
			printf("2 : ");
			scanf("%s", b);
			srand(time(NULL));
			c = rand() % 2 + 1;
			if (c == 1)
				printf("\n%d : %s", c, a);
			if (c == 2)
				printf("\n%d : %s", c, b);
		}

		//잘못 입력했을 경우
		else {
			printf("\n무슨 말씀을 하시는지 모르겠어요\n\n다시 입력해주세요\n");
			continue;//(while(ggh==1))로 돌아가 다시 질문 받기
		}

		//질문 더 받을지 결정하기
		int k = 1;
		while (k == 1) {
			int any;
			printf("\n\n다른 궁금한 점은 없나요?\n");
			printf("1 : 있어요\n2 : 없어요\n");
			scanf("%d", &any);

			if (any == 1) {
				printf("\n----------------------\n\n");//새 질문과 전 질문 사이 구분선
				k = 0;//while (k==1) 빠져나가고 while(ggh==1) 부터 다시 실행
			}

			else if (any == 2) {
				printf("\n감사합니다\n");
				k = 0;//while (k==1) 빠져나가기
				ggh = 0;//while(ggh==1) 빠져나가기

			}

			//잘못 입력했을 경우
			else {
				printf("\n무슨 말씀을 하시는지 모르겠어요\n\n다시 입력해주세요");
				continue;//(while (k==1))의 처음 위치로 돌아가 다시 질문 받기
			}
		}
	}
	return 0;
}