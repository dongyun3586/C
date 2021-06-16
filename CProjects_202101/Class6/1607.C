#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>

void main() {

	int total_score = 0;

EXIT:                                     //<-- **************여기로 이동**********************************************************************************

	srand(time(NULL));
	int a8 = 0, a10 = 0, a12 = 0;
	a8 = rand() % 8 + 1;                             //8면체(1~8),10면체(1~10),12면체(1~10) 주사위를 굴려 나오는 숫자를 랜덤으로 출력한다. 
	a10 = rand() % 10 + 1;
	a12 = rand() % 12 + 1;
	int a = 0, b = 0, sum1 = 0, sum2 = 0, c = 0, score = 0;                                   //a,b 입력할 연산기호를 저장하는 변수, 
	int array_printedNumber1[100] = { 0 };                                          //중복방지용 배열
	int array_printedNumber[10] = { 0 };                                            //출력된 숫자를 저장할 배열
	printf("8면체 주사위: %d\n\n10면체 주사위:%d \n\n12면체 주사위: %d\n\n", a8, a10, a12);

	int array[] = { a8,a10,a12 };
	int array_1point[] = { 3,4,5,6,7,8,9,10,11,12,13,14,15,17,18,20,24 };              //각 숫자들의 point에 따라 배열을 선언했다. 게임이 끝난 뒤 point 합산할 것이다.
	int array_2point[] = { 17,21,36,30,40 };
	int array_3point[] = { 19,22,27,28,32,35,42,48,56,60,72 };
	int array_4point[] = { 25,42 };
	int array_5point[] = { 23,26,33,50,54,70,80 };
	int array_6point[] = { 44,63 };
	int array_8point[] = { 49,64,84,90 };


	srand(time(NULL));                                                          //이제 1층부터 4층까지 피라미드를 쌓을 건데 1층은 1~2point숫자중에서 임의의 숫자들이 출력되고,2층은 3~4,3층은 5~6,4층은 8point 숫자들이 출력된다.
	int array_point1or2[] = { 3,4,5,6,7,8,9,10,11,12,13,14,15,17,18,20,24,17,21,36,30,40 };
	int array_point3or4[] = { 19,22,27,28,32,35,42,48,56,60,72,25,42 };
	int array_point5or6[] = { 23,26,33,50,54,70,80,44,63 };
	int x, y, z, w;

	x = rand() % 22;
	printf(" %2d  ", array_point1or2[x]);
	array_printedNumber1[array_point1or2[x]] = 1;
	array_printedNumber[0] = array_point1or2[x];
	for (int i = 1; i < 4; i++) {
		while (array_printedNumber1[array_point1or2[x]])                 //8point에서 숫자 1개,5~6point에서 숫자 2개,3~4point에서 숫자 3개,1~2point에서 숫자 4개를 출력한다.
			x = rand() % 22;                                     //중복을 방지한 방법-array_printedNumber1[100] 배열을 사용해서 이미 출력된 숫자들이 그 숫자 만큼의 순서에 1을 넣어 주었다. 예를 들어 임의의 난수 6이 나오면 그 숫자를 변수 x에 저장한다.  
		array_printedNumber1[array_point1or2[x]] = 1;            //그다음 array_point1or2[x]를 출력한다.그리고 array_printedNumber[array_point1or2[x]]에 숫자 1을 넣어주고 while을 사용하여 while(array_printedNumber1[array_point1or2[x]])를 사용하고 x에 다른 숫자가 저장될 때까지 난수 생성을 반복하여 중복을 방지하였다.  
		array_printedNumber[i] = array_point1or2[x];
		printf(" %2d  ", array_point1or2[x]);                         //출력된 원소들을 printedNumber 배열에 저장한다.          
	}printf("\n ");
	y = rand() % 13;
	printf("  %2d ", array_point3or4[y]);
	array_printedNumber1[array_point3or4[y]] = 1;
	array_printedNumber[4] = array_point3or4[y];
	for (int i = 5; i <= 6; i++) {
		while (array_printedNumber1[array_point3or4[y]])
			y = rand() % 13;                                                  //3층에 출력될 3~4point                                      
		array_printedNumber1[array_point3or4[y]] = 1;
		printf("  %2d ", array_point3or4[y]);
		array_printedNumber[i] = array_point3or4[y];
	}printf("\n    ");
	//2층에 출력될 5~6point
	z = rand() % 9;
	printf(" %2d   ", array_point5or6[z]);
	array_printedNumber1[array_point5or6[z]] = 1;
	array_printedNumber[7] = array_point5or6[z];
	while (array_printedNumber1[array_point5or6[z]])z = rand() % 9;
	printf(" %2d   ", array_point5or6[z]);
	array_printedNumber[8] = array_point5or6[z];
	printf("\n     ");
	w = rand() % 3;                                                          //1층에 출력될 8point 
	printf("   %2d\n", array_8point[w]);
	array_printedNumber[9] = array_8point[w];

	printf("\n\n\n\n\n\n |%2d[  ]%2d|[  ]%2d", a8, a10, a12);
	printf("\n\n 다음 숫자를 이용해 피라미드의 숫자를 만드시오.(대괄호 안에 들어갈 연산기호를 입력하시오.)\n");
	scanf(" %c %c", &a, &b);

	if ((int)a == 43) {                      //아스키 코드로 43이더하기, 45가 빼기, 42가 곱하기,47이 나누기
		sum1 = a8 + a10;
		if ((int)b == 43)                                    //대괄호 안에 연산기호를 입력하면 그대로 연산이 된다.
			sum2 = sum1 + a12;                      //a8과 a10을 연산한 것을 sum1에 저장하고 sum1과 a12를 연산한 것을 sum2에 저장한다.
		else if ((int)b == 45)
			sum2 = sum1 - a12;
		else if ((int)b == 42)
			sum2 = sum1 * a12;
		else if ((int)b == 47)
			sum2 = sum1 / a12;
	}
	else if ((int)a == 45) {                //빼기
		sum1 = a8 - a10;
		if ((sum1) < 0)
			sum1 = sum1 * (-1);
		if ((int)b == 43)
			sum2 = sum1 + a12;
		else if ((int)b == 45)
			sum2 = sum1 - a12;
		else if ((int)b == 42)
			sum2 = sum1 * a12;
		else if ((int)b == 47)
			sum2 = sum1 / a12;
	}
	else if ((int)a == 42) {                       //곱하기 
		sum1 = a8 * a10;
		if ((int)b == 43)
			sum2 = sum1 + a12;
		else if ((int)b == 45)
			sum2 = sum1 - a12;
		else if ((int)b == 42)
			sum2 = sum1 * a12;
		else if ((int)b == 47)
			sum2 = sum1 / a12;
	}
	else if ((int)a == 47) {                               //나누기
		sum1 = a8 / a10;
		if ((int)b == 43)
			sum2 = sum1 + a12;
		else if ((int)b == 45)
			sum2 = sum1 - a12;
		else if ((int)b == 42)
			sum2 = sum1 * a12;
		else if ((int)b == 47)
			sum2 = sum1 / a12;
	}
	printf("\n%d", sum2);

	for (int j = 0; j < 10; j++) {
		if (sum2 == array_printedNumber[j]) {                             //sum2와 출력된 숫자 중 하나와 같다면 그 숫자의 point만큼 점수가 추가된다.
			for (int i = 1; i <= 17; i++) {                      //<---1point
				if (sum2 == array_1point[i - 1]) {
					score = score + 1;
				}
			}
			for (int i = 1; i <= 5; i++) {                  //<--2point
				if (sum2 == array_2point[i - 1])
					score = score + 2;
			}
			for (int i = 1; i <= 11; i++) {
				if (sum2 == array_3point[i - 1])          //<--3point
					score = score + 3;
			}
			for (int i = 1; i <= 2; i++) {
				if (sum2 == array_4point[i - 1])                //<--4point
					score = score + 4;
			}
			for (int i = 1; i <= 7; i++) {
				if (sum2 == array_5point[i - 1])             //<--5point
					score = score + 5;
			}
			for (int i = 1; i <= 2; i++) {
				if (sum2 == array_6point[i - 1])
					score = score + 6;                        //<--6point
			}
			for (int i = 1; i < 5; i++) {
				if (sum2 == array_8point[i - 1])            //<--8point
					score = score + 8;
			}

		}
	}
	Sleep(400);                                     //조금 기다렸다가 계산된 숫자에 해당하는 point가 출력되고 total point에 더해진다.                           
	printf("\n점수는: %d", score);
	total_score += score;

	Sleep(2000);
	system("cls");
	printf("현재점수 : %d\n", total_score);     //다음 화면으로 넘어가기 전에 잠시 기다린다. 
	Sleep(800);
	system("cls");
	goto EXIT;                                     //한 라운드가 끝나면 화면을 모두 지운 뒤 EXIT으로 이동한다 .
}


//끝!!
