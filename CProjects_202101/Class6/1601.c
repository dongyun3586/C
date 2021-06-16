#include<stdio.h>
/*
Gauss-Jordan elimination은 연립방정식의 계수와 상수들로 이루어진 첨가행렬의 기본행 연산을 통해
동차 연립방정식의 해를 계산하는 방법이다. 이 때 아래와 같은 과정을 따른다
1. 가장 왼쪽에 있는 원소가 0이 아니도록 첫째 행과 다른 행을 바꾼다.(열의 모든 원소가 0이라면 다음 열로 넘어간다)
2. 1에서 찾은 가장 왼쪽에 있는 원소가 1이 아니라면 행 전체를 같은 수로 나누어 1(여기서 만든 1을 leader 1이라고 한다.)로 만든다.
3. 1행에 적당한 수를 곱하고 다른 행들에 더해서 leader 1 열의 원소들이 모두 0이 되도록 한다.
4. 1행은 두고 나머지 부분행렬에 대해서 다음과 같은 단계를 반복한다.(이 때 소거는 전체 행렬에 대해서 한다.)*/
//기본행 연산을 함수로 정의한다.
void row_change(float a[][100], int n, int i, int j); //행끼리 바꾸는 연산 (행렬, 행렬의 크기, 서로 바꿀 행)
void row_divide(float a[][100], int n, int i, int j); //행 전체를 나누어 행의 가장 앞의 수를 1로 만드는 연산 (행렬,행렬의 크기, 나눌 행,1로 만들 열)
void row_elimination(float a[][100], int n, int i, int m, int j);//행에 다른 행의 실수배를 빼서 소거하는 연산 (행렬,행렬의 크기, 소거에 쓸 행, 소거에 사용할 행의 leader 1,소거시킬 행)
void printa(float a[][100], int n); //행렬을 출력한다.
int check1(float a[][100], int n); //연립 방정식이 1개의 해가 나오는지 판정한다.
int check2(float a[][100], int n); //연립 방정식이 1개의 해가 나오지 않을 때 불능인지 부정인지 판단한다.
int main() {
	float a[100][100] = { 0 }; //첨가행렬을 입력할 공간
	int n; //연립방정식의 미지수의 개수
	printf("풀이할 연립방정식의 미지수의 개수를 입력하세요 : ");
	scanf("%d", &n); //미지수의 개수 입력
	printf("풀이할 연립 방정식의 계수를 입력하세요.\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= n; j++) {
			scanf("%f", &a[i][j]);
		} // 연립방정식의 계수와 상수(첨가행렬)를 입력한다. i는 행, j는 열
	}
	int i = 0, j, k = 0; // i는 행, k는 열
	while (k < n) { //모든 열에 대해서 소거를 시행
		j = i; //j는 1번 과정에서 i행과 바꿀 행
		while (j != n) { //j가 커져서 n이 되면(모든 행과 바꿔 시행이 끝남
			if (a[i][k] != 0) { //가장 왼쪽의 성분이 0이 아니라면
				row_divide(a, n, i, k); //2번 과정
				int b = i + 1; //b는 3번 과정에서 소거할 행을 나타낸다.
				b %= n;
				while (b != i) { //자신을 제외한 모든 행을 소거할 때까지 실행
					row_elimination(a, n, i, k, b); //소거
					b++;
					b %= n;
				}
				i++; // 다음 행으로 넘어간다.
				break;
			}
			else { //가장 왼쪽의 성분이 0이면
				j++;
				row_change(a, n, i, j); //다른 행과 바꾼다.
				if (j == n) {
					row_change(a, n, i, j);
				}
			}
		}
		k++; //다음 열로 넘어간다
	}
	if (check1(a, n)) { //연립방정식의 해가 1개가 아니라면
		if (check2(a, n)) { // 연립방정식의 해가 부정이라면
			printa(a, n); //Gauss-Jordan elimination을 수행한 후의 첨가행렬 출력
			return 0;
		}
		printf("해가 없습니다.");//불능이라면 이렇게 출력
	}
	else {//해가 1쌍 나온다면
		printf("(");
		for (i = 0; i < n - 1; i++) { //괄호 안에 해 출력
			printf("%f, ", a[i][n]);
		}
		printf("%f)", a[n - 1][n]);
	}


}
void row_change(float a[][100], int n, int i, int j) { //행끼리 바꾸는 연산 (행렬, 행렬의 크기, 서로 바꿀 행)
	float b; // 값을 바꿀 때 임시로 저장할 공간
	for (int k = 0; k <= n; k++) { //k는 열 i행 k열과 j행 k열의 수를 모두 바꿔준다.
		b = a[i][k];
		a[i][k] = a[j][k];
		a[j][k] = b;
	}
}
void row_divide(float a[][100], int n, int i, int j) { //i행 j열이 1이 되도록 행 전체를 나눈다.
	float m = a[i][j]; //m은 행 전체를 나눌 수
	for (int k = 0; k <= n; k++) a[i][k] /= m; //i행의 모든 수를 m으로 나눔
}
void row_elimination(float a[][100], int n, int i, int m, int j) { //j행에 i행의 상수배를 빼서 소거한다.
	float l = a[j][m] / a[i][m]; //l은 j행 m열을 소거하기 위해 i행에 곱할 상수
	for (int k = 0; k <= n; k++) {
		a[j][k] -= l * a[i][k];
	}
}
void printa(float a[][100], int n) { //행렬을 출력
	printf("\n");
	for (int k = 0; k < n; k++) {
		for (int j = 0; j <= n; j++) {
			printf("%f ", a[k][j]);
		}
		printf("\n");
	}
}
int check1(float a[][100], int n) { //Gauss-Jordan elimination을 수행한 이후 계수 행렬 중 행 전체가 0이 되는 행이 있는지 확인
	int b;
	for (int i = 0; i < n; i++) { //각 i행들에 대해서 확인
		b = 0; //b 초기화
		for (int j = 0; j < n; j++) { //i행의 모든 성분이 0이면 b = 0, 한 성분이라도 0이 아닌 수가 있다면 b = 1
			b = b || a[i][j];
		}
		if (!b)	return 1; //b = 0이면(행의 모든 성분이 0면) 1을 반환
	}
	return 0; //모든 행 중에 모든 성분이 0인 행이 없으면 0 반환
}
int check2(float a[][100], int n) { //check1과 유사하지만 이 때 계수행렬이 아닌 첨가행렬을 조사
	int b;							//행의 모든 성분이 0인 행이 있으면(부정) b = 0 -> return 1
	for (int i = 0; i < n; i++) {
		b = 0;
		for (int j = 0; j <= n; j++) {
			b = b || a[i][j];
		}
		if (!b) return 1;
	}
	return 0;
}