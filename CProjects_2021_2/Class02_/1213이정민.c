#include <stdio.h>
#include <time.h>

int level;
int arrayGaybokchi[6];
int* cursor; //물고기를 가리키는 역할

void initialData();
void printGaybokchi();
void decreaseWater(long elapsedTime);

int main(void) {
	long startTime = 0; //게임 시작시간
	long totalElapsedTime = 0; //총 경과시간
	long prevElapsedTime = 0; //직전 경과 시간 (최근에 물을 준 시간 간격)

	int num; //몇 번 어항에 물을 줄 것인지, 사용자 입력
	initialData();

	cursor = arrayGaybokchi; //포인터변수를 이용 배열처럼 사용

	startTime = clock(); //현재시간을 ms 단위로 반환
	while (1) {
		printGaybokchi();
		//getchar(); 임시로 사용자 입력을 대기 
		printf("몇 번 어항에 물을 주시겠어요?");
		scanf_s("%d", &num);

		//입력값 확인
		if (num < 1 || num>6)
		{
			printf("\n 입력값이 잘못되었습니다. \n");
			continue;
		}
		//총 경과시간
		totalElapsedTime = (clock() - startTime) / CLOCKS_PER_SEC;
		printf("총 경과시간 : %ld 초\n", prevElapsedTime);

		//어항의 물이 증발
		decreaseWater(prevElapsedTime);

		//사용자가 입력한 어항에 물을 줌.
		// 어항의 물이 0일 경우 물을 주지 않는다. (물고기가 이미 죽음)
		if (cursor[num - 1] <= 0)
		{
			printf("%d번 물고기는 이미 죽었습니다. 물을 주지 않습니다. \n", num);
		}
		// 어항의 물이 0이 아닌 경우 물을 준다. (100을 넘지는 않는지 확인이 필요함)

		else if (cursor[num - 1] + 1 <= 100)
		{
			//물을 준다
			printf("%d번 어항에 물을 줍니다\n\n", num);
			cursor[num - 1] += 1;
		}

		//Levelup을 할 건기 확인 (20seconds 마다 한번씩 Levelup 수행)
		if (totalElapsedTime / 20 > level - 1) //처음레벨이 1이므로 1보다 작은 0.XXX 의 수는 int 에서 0으로 생각
		{
			level++;
			printf("축 레벨업! 기존 %d 레벨에서 %d레벨로 업그레이드 성공! \n\n", level - 1, level);
			//기존레벨은 새로 Levelup 된 현재레벨보다 1만큼 낮음.

			//최종레벨 : 5Level
			if (level == 5)
			{
				printf("\n\n 축하! 최고 레벨을 달성하였습니다! 게임끝!\n\n");

				exit(0); //프로그램 전체를 종료하는 작업
			}
		}

		//모든 물고기가 죽었는지 확인 

		if (checkFishAlive() == 0)
		{
			//물고기가 한마리도 남지 않고 모두 죽었음
			printf("모든 물고기가 사망했습니다. \n");
		}
		else
		{
			//한마리 또는 그이상의 물고기들이 살아있음
			printf("물고기가 아직 남아있어요!\n");
		}
		prevElapsedTime = totalElapsedTime;

		//25초에서 15초를 빼기위한 임시값을 지정 while 때문에
	}
	return 0;
}

void initialData()
{
	level = 1; //게임레벨은 1레벨에서 5레벨까지 (5가 최대)
	for (int i = 0; i < 6; i++)
	{
		arrayGaybokchi[i] = 100; //어항의 물 높이 (0부터 100까지)
	}
}

void printGaybokchi() {

	printf("%3d번 3d번 %3d번 %3d번 %3d번 %3d번 \n", 1, 2, 3, 4, 5, 6);
	for (int i = 0; i < 6; i++)
	{
		printf("%3d", arrayGaybokchi[i]);
	}
	printf("\n\n");
}

void decreaseWater(long elapsedTime) //최근경과시간
{
	for (int i = 0; i < 6; i++)
	{
		arrayGaybokchi[i] -= (level * 3 * (int)elapsedTime); //3은 난이도조절값, 10초인 경우에는 30만큼 줄임
		if (arrayGaybokchi[i] < 0)
		{
			arrayGaybokchi[i] = 0;
		}
	}
}

int checkFishAlive() {

	for (int i = 0; i < 6; i++)
	{
		if (arrayGaybokchi[i] > 0)
			return 1; //참 Ture
	}
	return 0;
}