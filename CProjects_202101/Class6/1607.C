#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>

void main() {

	int total_score = 0;

EXIT:                                     //<-- **************����� �̵�**********************************************************************************

	srand(time(NULL));
	int a8 = 0, a10 = 0, a12 = 0;
	a8 = rand() % 8 + 1;                             //8��ü(1~8),10��ü(1~10),12��ü(1~10) �ֻ����� ���� ������ ���ڸ� �������� ����Ѵ�. 
	a10 = rand() % 10 + 1;
	a12 = rand() % 12 + 1;
	int a = 0, b = 0, sum1 = 0, sum2 = 0, c = 0, score = 0;                                   //a,b �Է��� �����ȣ�� �����ϴ� ����, 
	int array_printedNumber1[100] = { 0 };                                          //�ߺ������� �迭
	int array_printedNumber[10] = { 0 };                                            //��µ� ���ڸ� ������ �迭
	printf("8��ü �ֻ���: %d\n\n10��ü �ֻ���:%d \n\n12��ü �ֻ���: %d\n\n", a8, a10, a12);

	int array[] = { a8,a10,a12 };
	int array_1point[] = { 3,4,5,6,7,8,9,10,11,12,13,14,15,17,18,20,24 };              //�� ���ڵ��� point�� ���� �迭�� �����ߴ�. ������ ���� �� point �ջ��� ���̴�.
	int array_2point[] = { 17,21,36,30,40 };
	int array_3point[] = { 19,22,27,28,32,35,42,48,56,60,72 };
	int array_4point[] = { 25,42 };
	int array_5point[] = { 23,26,33,50,54,70,80 };
	int array_6point[] = { 44,63 };
	int array_8point[] = { 49,64,84,90 };


	srand(time(NULL));                                                          //���� 1������ 4������ �Ƕ�̵带 ���� �ǵ� 1���� 1~2point�����߿��� ������ ���ڵ��� ��µǰ�,2���� 3~4,3���� 5~6,4���� 8point ���ڵ��� ��µȴ�.
	int array_point1or2[] = { 3,4,5,6,7,8,9,10,11,12,13,14,15,17,18,20,24,17,21,36,30,40 };
	int array_point3or4[] = { 19,22,27,28,32,35,42,48,56,60,72,25,42 };
	int array_point5or6[] = { 23,26,33,50,54,70,80,44,63 };
	int x, y, z, w;

	x = rand() % 22;
	printf(" %2d  ", array_point1or2[x]);
	array_printedNumber1[array_point1or2[x]] = 1;
	array_printedNumber[0] = array_point1or2[x];
	for (int i = 1; i < 4; i++) {
		while (array_printedNumber1[array_point1or2[x]])                 //8point���� ���� 1��,5~6point���� ���� 2��,3~4point���� ���� 3��,1~2point���� ���� 4���� ����Ѵ�.
			x = rand() % 22;                                     //�ߺ��� ������ ���-array_printedNumber1[100] �迭�� ����ؼ� �̹� ��µ� ���ڵ��� �� ���� ��ŭ�� ������ 1�� �־� �־���. ���� ��� ������ ���� 6�� ������ �� ���ڸ� ���� x�� �����Ѵ�.  
		array_printedNumber1[array_point1or2[x]] = 1;            //�״��� array_point1or2[x]�� ����Ѵ�.�׸��� array_printedNumber[array_point1or2[x]]�� ���� 1�� �־��ְ� while�� ����Ͽ� while(array_printedNumber1[array_point1or2[x]])�� ����ϰ� x�� �ٸ� ���ڰ� ����� ������ ���� ������ �ݺ��Ͽ� �ߺ��� �����Ͽ���.  
		array_printedNumber[i] = array_point1or2[x];
		printf(" %2d  ", array_point1or2[x]);                         //��µ� ���ҵ��� printedNumber �迭�� �����Ѵ�.          
	}printf("\n ");
	y = rand() % 13;
	printf("  %2d ", array_point3or4[y]);
	array_printedNumber1[array_point3or4[y]] = 1;
	array_printedNumber[4] = array_point3or4[y];
	for (int i = 5; i <= 6; i++) {
		while (array_printedNumber1[array_point3or4[y]])
			y = rand() % 13;                                                  //3���� ��µ� 3~4point                                      
		array_printedNumber1[array_point3or4[y]] = 1;
		printf("  %2d ", array_point3or4[y]);
		array_printedNumber[i] = array_point3or4[y];
	}printf("\n    ");
	//2���� ��µ� 5~6point
	z = rand() % 9;
	printf(" %2d   ", array_point5or6[z]);
	array_printedNumber1[array_point5or6[z]] = 1;
	array_printedNumber[7] = array_point5or6[z];
	while (array_printedNumber1[array_point5or6[z]])z = rand() % 9;
	printf(" %2d   ", array_point5or6[z]);
	array_printedNumber[8] = array_point5or6[z];
	printf("\n     ");
	w = rand() % 3;                                                          //1���� ��µ� 8point 
	printf("   %2d\n", array_8point[w]);
	array_printedNumber[9] = array_8point[w];

	printf("\n\n\n\n\n\n |%2d[  ]%2d|[  ]%2d", a8, a10, a12);
	printf("\n\n ���� ���ڸ� �̿��� �Ƕ�̵��� ���ڸ� ����ÿ�.(���ȣ �ȿ� �� �����ȣ�� �Է��Ͻÿ�.)\n");
	scanf(" %c %c", &a, &b);

	if ((int)a == 43) {                      //�ƽ�Ű �ڵ�� 43�̴��ϱ�, 45�� ����, 42�� ���ϱ�,47�� ������
		sum1 = a8 + a10;
		if ((int)b == 43)                                    //���ȣ �ȿ� �����ȣ�� �Է��ϸ� �״�� ������ �ȴ�.
			sum2 = sum1 + a12;                      //a8�� a10�� ������ ���� sum1�� �����ϰ� sum1�� a12�� ������ ���� sum2�� �����Ѵ�.
		else if ((int)b == 45)
			sum2 = sum1 - a12;
		else if ((int)b == 42)
			sum2 = sum1 * a12;
		else if ((int)b == 47)
			sum2 = sum1 / a12;
	}
	else if ((int)a == 45) {                //����
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
	else if ((int)a == 42) {                       //���ϱ� 
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
	else if ((int)a == 47) {                               //������
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
		if (sum2 == array_printedNumber[j]) {                             //sum2�� ��µ� ���� �� �ϳ��� ���ٸ� �� ������ point��ŭ ������ �߰��ȴ�.
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
	Sleep(400);                                     //���� ��ٷȴٰ� ���� ���ڿ� �ش��ϴ� point�� ��µǰ� total point�� ��������.                           
	printf("\n������: %d", score);
	total_score += score;

	Sleep(2000);
	system("cls");
	printf("�������� : %d\n", total_score);     //���� ȭ������ �Ѿ�� ���� ��� ��ٸ���. 
	Sleep(800);
	system("cls");
	goto EXIT;                                     //�� ���尡 ������ ȭ���� ��� ���� �� EXIT���� �̵��Ѵ� .
}


//��!!