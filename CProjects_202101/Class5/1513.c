#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

	//플레이어수 설정하기
	while (1) {

		int playnum, outputnum, sum = 0, input;
		//playnum=플레이어수, sum=각 턴에서 합계
		//outputnum=출력되는 수(31-100), input: 각 플레이어가 입력하는 수(0-99)

		printf("\n###숫자만 입력하시기 바랍니다.###\n");
		printf("플레이어 수를 입력하세요: ");
		scanf("%d", &playnum);


		//플레이어수가 1-4가 아닐 때 다시 입력하기
		if (playnum > 4 || playnum < 1)
		{
			printf("플레이어수는 1명에서 4명입니다.\n");
			printf("다시 입력하기\n");
		}

		//올바르게 입력되었을 때
		else
		{
			printf("플레이어수는 %d명입니다.\n", playnum);
			printf("--------------------start-----------------------\n");

			//게임 진행
			while (1) {

				//사용되는 변수 설정
				srand(time(NULL));
				outputnum = rand() % 69 + 31;
				input = rand() % 13 + 3;

				//플레이어가 1명일 때
				//컴퓨터랑 게임하는 건 안되서 혼자서 게임하는 것으로 바꿈

				if (playnum == 1) {
					printf("숫자를 입력하세요: ");
					scanf("%d", &input);
					if (input < 0 || input >99)
					{
						printf("\n******범위 밖의 숫자입니다.******\n");
						printf("----다시 입력하기----\n\n");

					}

					else
					{
						if (input <= 9)
							sum += 1;
						else
							sum += 2;

						if (sum >= outputnum) {
							printf("\n==========게임 종료==========\n\n");
							break;
						}
						else
							printf("\n----합계: %d----\n\n", sum);
					}
				}

				else {

					//플레이어가 2명 이상일 때 

					if (sum < outputnum) {

						for (int i = 1; i <= playnum; i++) {

							printf("%d--숫자를 입력하세요: ", i);
							scanf("%d", &input);

							if (input < 0 || input >99)
							{
								printf("\n******범위 밖의 숫자입니다.******\n");
								printf("----다시 입력하기----\n\n");
								printf("잘못 입력한 %d번 플레이어의 차례는 무효입니다.\n\n", i);
								//잘못 입력한 사람의 차례는 무효
							}

							else
							{
								if (input <= 9)
									sum += 1;
								else
									sum += 2;

								printf("\n----합계: %d----\n\n", sum);
							}
						}
					}
					else
					{
						printf("==========게임 종료==========\n\n");
						printf("마지막에 입력한 사람이 승자입니다.\n\n\n\n");
						break;
					}
				}
			}
		}
	}
}