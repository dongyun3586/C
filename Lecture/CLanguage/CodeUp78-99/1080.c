//1, 2, 3, 4, 5 ... �� ������� ��� ���� ���� �����ٰ�,
//�Էµ� ������ ���ų� Ŀ���� ��, �������� ���� ������ ����Ѵ�.

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