#include <stdio.h>

void main()
{
	int arr[15], n;
	int* pt = arr;

	printf("�迭�� ��� �Ųٷ� ����ϱ�\n");
	printf("�迭�� ������ ����� ����(max 15)��?");
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		printf("element %d : ", i + 1);
		scanf("%d", pt);
		pt++;
	}

	pt = &arr[n - 1];

	printf("\n�迭 ��� �Ųٷ� ���\n");
	for (int i = n; i > 0; i--)
	{
		printf("element %d : %d\n", i, *pt);
		pt--;
	}
	printf("\n\n");
}