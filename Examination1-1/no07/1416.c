#include<stdio.h>

/* �˶� �ð� ��� */
int main() {
	int nh, nm, ah, am;

	printf("���� �ð�: ");
	scanf("%d %d", &nh, &nm);
	printf("�˶� �ð�: ");
	scanf("%d %d", &ah, &am);

	if(nh>=ah||nm>=am)
		printf("%d�ð� %d�� ", nh-ah, nm-am);
	if (nh >= ah || nm < am)
		printf("%d�ð� %d�� ", nh - ah, am-nm);
	if (nh < ah || nm >= am)
		printf("%d�ð� %d�� ", ah - nh, nm - am);
	else
		printf("%d�ð� %d�� ", ah - nh, am - nm);

	return 0;
}