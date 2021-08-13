#include<stdio.h>

#define TYPE_INT 0
#define TYPE_FLOAT 1
#define TYPE_DOUBLE 2
#define TYPE_CHAR 3

void* sum(void* a, void* b, void* result, int type_num) {
	switch (type_num) {
	case TYPE_INT:
		*(int*)result = *(int*)a + *(int*)b;
		break;
	case TYPE_FLOAT:
		*(float*)result = *(float*)a + *(float*)b;
		break;
	case TYPE_DOUBLE:
		*(double*)result = *(double*)a + *(double*)b;
		break;
	default:
		printf("지원하지 않는 형식 입니다.");
	}
	return result;
}

int main() {
	int a = 3, b = 4, int_sum;
	float c = 1.1, d = 2.2, float_sum;
	double e = 3.3, f = 4.4, double_sum;
	char g = 'a', h = 'A', char_sum;

	printf("%d\n", *(int*)sum(&a, &b, &int_sum, TYPE_INT));
	printf("%f\n", *(float*)sum(&c, &d, &float_sum, TYPE_FLOAT));
	printf("%f\n", *(double*)sum(&e, &f, &double_sum, TYPE_DOUBLE));
	printf("%c\n", *(char*)sum(&g, &h, &char_sum, TYPE_CHAR));

	return 0;
}