#include<stdio.h>

int main() {
	time_t t;
	t = time();      // time() �Լ��� ���ؼ� ���� �ð� ��ȯ
	printf("%lld\n", t);   // ���

	// time() : 1970�� 1�� 1�� 00�� 00��(UTC) ���� ���ݱ��� �ʴ����� �ð��� ���� ������ ��ȯ
	printf("%d\n", time(NULL));  // ���� �ð� ���





	//for (int i = 0; i < 10; i++) {
	//	
	//}

	return 0;
}