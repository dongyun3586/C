#include<stdio.h>
#include<math.h>

#define rangex 100 //넓이를 계산 할 수 있는 x의 값의 범위(-rangex, rangex)
#define rangey 100 //넓이를 계산 할 수 있는 y의 값의 범위(-rangey, rangey)

//polynomial은 좌표평면 위의 한 점(x,y)를 받아서 함수 f(x,y)의 부호를 알려주는 함수이다
int polynomial(double arr[][3], double x, double y);

int main() {
	//term은 항의 개수를,  sign은 부등식의 부호를,  lattice는 부등식의 조건을 만족하는 격자점의 개수를 저장하는 변수이다
	int term, sign = 1, lattice = 0;
	//DISTANCE는 격자점 사이의 간격을 나타낸다. 이 값을 작게할수록 넓이를 구할때 정확도가 높아질 것이다
	double DISTANCE = 1;
	//surface는 부등식을 만족시키는 부분의 넓이를 저장
	double surface;

	//격자점의 간격 입력받기
	printf("부등식의 영역을 구할때 사용되는 격자점 사이의 간격은?\n간격이 작을수록 영역은 정확히 구해진다.");
	scanf("%lf", &DISTANCE);

	//부등식의 항의 개수를 입력받기
	printf("f(x,y)>0의 형태이다\n항의 개수는?");
	scanf_s("%d", &term);

	//poly는 10 by 3 행렬이다. 1열에 항의 계수들을, 2열에 항의 x의 차수들을, 3열에 항의 y의 차수들을 저장한다
	double poly[10][3] = { 0 };
	double pcoe, px, py;

	//pcoe(항의 계수), px(x의 차수), py(y의 차수)를 받아서 poly에 저장하기
	for (int i = 0; i < term; i++) {
		printf("%d 번째 항의 계수와 x, y의 차수는?", i + 1);
		scanf_s("%lf %lf %lf", &pcoe, &px, &py);
		poly[i][0] = pcoe;
		poly[i][1] = px;
		poly[i][2] = py;
	}

	//부등식의 영역이 x와 y의 범위를 넘어간 경우, 넓이가 정확히 구해지지 않으니, 끝 범위를 스캔한다.
	int rangecheck = -1;
	//x = -rangex일때 의 끝 범위 체크하기
	for (int i = -rangey; i <= rangey; i++) {
		rangecheck = polynomial(poly, -rangex, i);
		if (rangecheck == 1) {
			printf("구하려는 부등식의 영역이 계산할 수 있는 범위 밖을 포함합니다");
			return 0;
		}
	}
	//x = rangex일때 의 끝 범위 체크하기
	for (int i = -rangey; i <= rangey; i++) {
		rangecheck = polynomial(poly, rangex, i);
		if (rangecheck == 1) {
			printf("구하려는 부등식의 영역이 계산할 수 있는 범위 밖을 포함합니다");
			return 0;
		}
	}
	//y = -rangey일때 의 끝 범위 체크하기
	for (int i = -rangex; i <= rangex; i++) {
		rangecheck = polynomial(poly, i, -rangey);
		if (rangecheck == 1) {
			printf("구하려는 부등식의 영역이 계산할 수 있는 범위 밖을 포함합니다");
			return 0;
		}
	}
	//y = rangey일때 의 끝 범위 체크하기
	for (int i = -rangex; i <= rangex; i++) {
		rangecheck = polynomial(poly, i, rangey);
		if (rangecheck == 1) {
			printf("구하려는 부등식의 영역이 계산할 수 있는 범위 밖을 포함합니다");
			return 0;
		}
	}

	/*많은 범위를 계산하기에는 무리가 있으니 유효한 넓이를 간격이 1인 범위로 스캔하여
	유효한 범위를 포함하는 직사각형을 구한다 : (xminusend, xplusend)*(yminusend, yplusend) */
	int xminusend = -1, xplusend = 1, yminusend = -1, yplusend = 1;
	for (int i = -rangex; i <= rangex; i++) {
		for (int j = -rangey; j <= rangey; j++) { //-rangex <= x <= rangex, -rangey <= y <= rangey 범위 내의 모든 격자점을 스캔한다
			if (polynomial(poly, i, j) == 1) {
				//해당하는 범위가 xminusend나 yminusend보다 작으면, 그 값을 각각의 변수에 저장한다
				if (i < xminusend)
					xminusend = i;
				if (j < yminusend)
					yminusend = j;
				//해당하는 범위가 xplusend나 yplusend보다 크면, 그 값을 각각의 변수에 저장한다
				if (i > xplusend)
					xplusend = i;
				if (j > yplusend)
					yplusend = j;
			}
		}
	}

	//주어진 x와 y의 범위에서 부등식을 만족시키는 격자점의 수를 센다
	for (double x = xminusend - 1; x <= xplusend + 1; x += DISTANCE) {
		for (double y = yminusend - 1; y <= yplusend + 1; y += DISTANCE) {
			if (polynomial(poly, x, y) == 1)
				lattice++;//(x, y) 에서 부등식을 만족할때, 격자점의 개수를 센다
		}
	}
	surface = (double)lattice * pow(DISTANCE, 2);//구한 lattice를 이용하여 부등식의 넓이를 계산하기
	printf("%lf", surface);//surface를 출력

	return 0;
}



int polynomial(double arr[][3], double x, double y) {
	int sign = 1;
	double function = 0;//function은 f(x,y)의 값을 저장
	//각 항의 값을 계산해서 function에 더한다
	for (int i = 0; i < 3; i++)
		function += arr[i][0] * pow(x, arr[i][1]) * pow(y, arr[i][2]);
	if (function < 0)
		sign = -1;
	return sign;//f(x,y)의 부호를 넘긴다
}