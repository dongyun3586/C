//1, 2, 3, 4, 5 ... 를 순서대로 계속 더해 합을 만들어가다가,
//입력된 정수와 같거나 커졌을 때, 마지막에 더한 정수를 출력한다.

#include<stdio.h>

int main_1080() {
	int n=0, input_num, sum = 0;
	scanf("%d", &input_num);

	while (sum < input_num) {
		sum += ++n;
	}
	printf("%d\n", n);

	return 0;
}