#include <stdio.h>
int main()
{
	int a, b, t;

	printf("���� �� ���� �Է��Ͻÿ�: ");
	scanf("%d %d", &a, &b);

	printf("a=%2d, b=%2d\n", a, b);
	// �� ������ �� ��ȯ�Ͽ� ����
	t = a;
	a = b;
	b = t;

#pragma region case 2
	/*a = a + b;
	b = a - b;
	a = a - b;*/
#pragma endregion

	printf("a=%2d, b=%2d\n", a, b);
}