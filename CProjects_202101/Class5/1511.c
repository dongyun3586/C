#include<stdio.h>
#include<math.h>
#define _CRT_SECURE_NO_WARNINGS
float g = 9.8;
void first();
void second();
void third();
void fourth();

int main()

{
	printf("1. 위치에너지 --> 운동에너지\n");
	printf("2. 운동에너지 --> 탄성에너지\n");
	printf("3, 위치에너지 --> 탄성에너지\n");  // 구하고 싶은 문제를 정하기 
	printf("4. 운동에너지 --> 위치에너지\n");
	printf("0을 입력하면 프로그램이 종료된다.\n");
	int n;
	while (1)
	{
		printf("\n문제의 번호를 고르시오 : ");
		scanf("%d", &n);
		printf("\n");
		if (n == 1)
		{
			first();
		}
		else if (n == 2)
		{
			second();
		}
		else if (n == 3)
		{
			third();
		}
		else if (n == 4)
		{
			fourth();
		}
		else if (n == 0)  // 0이 입력받아지면 프로그램이 종료됨.
		{
			printf("***실행이 종료되었습니다***\n");
			return 0;
		}
		else {
			printf("잘못된 번호를 골랐습니다.");  //0,1,2,3,4 가 아닌 다른 문제를 선택하면 다시 선택하라고 뜬다. 
		}
	}
}
void first() // 위치에너지를 운동에너지로 전환하는 함수 
{
	float h;
	float vmax;
	float f;
	printf("***물체를 위에서 자유낙하 시켰을때 최고속도를 구해보자***\n\n");
	printf("물체의 최고점은 몇 m인가?\n");
	scanf("%f", &h);
	f = 2 * g * h;
	vmax = sqrt(f);
	printf("***물체의 최고속도는 %f m/s입니다.***\n\n", vmax);

}
void second()  // 운동에너지를 탄성에너지로 전환하는 함수.
{
	float m, v;
	float k;
	float f;
	float x;
	printf("***물체가 속도 v로 용수철에 부딪혀서 용수철이 최대로 압축된 길이를 구해보자***\n\n");
	printf("물체의 무게는 몇 kg인가?\n");
	scanf("%f", &m);
	printf("처음 물체의 속도 몇 m/s 인가?\n");
	scanf("%f", &v);
	printf("용수철의 탄성계수는?\n");
	scanf("%f", &k);
	f = m * v / k;
	x = sqrt(f);
	printf("***용수철이 최대로 압축된 길이는 %f m 입니다.***\n", x);

}
void third() //위치에너지를 탄성에너지로 바꾼 함수 
{
	float h, m, k;
	float f;
	float x;
	printf("***물체가 h높이에서 자유낙하하고나서 용수철에 부딪힌후 용수철이 최대로 압축된 길이를 구해보자***\n\n");
	printf("물체의 무게는 몇 kg인가?\n");
	scanf("%f", &m);
	printf("물체의 높이 몇 m 인가?\n");
	scanf("%f", &h);
	printf("용수철의 탄성계수는?\n");
	scanf("%f", &k);
	f = 2 * m * h * g / k;

	x = sqrt(f);
	printf("***용수철이 최대로 압축된 길이는 %f m입니다.***\n", x);

}
void fourth() // 운동에너지를 위치에너지로 전환되는 함수 
{
	float v;
	float h;
	printf("***물체를 지상에서 수직방향으로 던질때 최고점의 높이를 구해보자***\n\n");
	printf("물체의 속도는 몇 m/s인가?\n");
	scanf("%f", &v);
	h = v * v / (2 * g);

	printf("***물체의 최고점의 높이는 %f m 입니다.***\n", h);

}