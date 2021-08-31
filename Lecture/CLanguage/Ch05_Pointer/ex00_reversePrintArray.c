#include <stdio.h>

void main()
{
	int arr[15], n;
	int* pt = arr;

	printf("배열의 요소 거꾸로 출력하기\n");
	printf("배열에 저장할 요소의 개수(max 15)는?");
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		printf("element %d : ", i + 1);
		scanf("%d", pt);
		pt++;
	}

	pt = &arr[n - 1];

	printf("\n배열 요소 거꾸로 출력\n");
	for (int i = n; i > 0; i--)
	{
		printf("element %d : %d\n", i, *pt);
		pt--;
	}
	printf("\n\n");
}